/*
 * Copyright (C) 2014 Guitarix project MOD project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cassert>
#include <unistd.h>

///////////////////////// MACRO SUPPORT ////////////////////////////////

#define __rt_func __attribute__((section(".rt.text")))
#define __rt_data __attribute__((section(".rt.data")))

///////////////////////// FAUST SUPPORT ////////////////////////////////

#define FAUSTFLOAT float
#ifndef N_
#define N_(String) (String)
#endif
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

#define always_inline inline __attribute__((always_inline))

template <int32_t N> inline float faustpower(float x)
{
  return powf(x, N);
}
template <int32_t N> inline double faustpower(double x)
{
  return pow(x, N);
}
template <int32_t N> inline int32_t faustpower(int32_t x)
{
  return faustpower<N/2>(x) * faustpower<N-N/2>(x);
}
template <>      inline int32_t faustpower<0>(int32_t x)
{
  return 1;
}
template <>      inline int32_t faustpower<1>(int32_t x)
{
  return x;
}

////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_sfp.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "resampler.cc"   // define struct PluginLV2
#include "resampler-table.cc"   // define struct PluginLV2
#include "zita-resampler/resampler.h"
#include "sfp_p1.cc"    // dsp class generated by faust -> dsp2cc
#include "sfp_clip.cc"    // dsp class generated by faust -> dsp2cc
#include "sfp_p2.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace sfp {

class SimpleResampler {
 private:
    Resampler r_up, r_down;
    int m_fact;
 public:
    SimpleResampler(): r_up(), r_down(), m_fact() {}
    void setup(int sampleRate, unsigned int fact);
    void up(int count, float *input, float *output);
    void down(int count, float *input, float *output);
};

void SimpleResampler::setup(int sampleRate, unsigned int fact)
{
	m_fact = fact;
	const int qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
	// upsampler
	r_up.setup(sampleRate, sampleRate*fact, 1, qual);
	// k == inpsize() == 2 * qual
	// pre-fill with k-1 zeros
	r_up.inp_count = r_up.inpsize() - 1;
	r_up.out_count = 1;
	r_up.inp_data = r_up.out_data = 0;
	r_up.process();
	// downsampler
	r_down.setup(sampleRate*fact, sampleRate, 1, qual);
	// k == inpsize() == 2 * qual * fact
	// pre-fill with k-1 zeros
	r_down.inp_count = r_down.inpsize() - 1;
	r_down.out_count = 1;
	r_down.inp_data = r_down.out_data = 0;
	r_down.process();
}

void SimpleResampler::up(int count, float *input, float *output)
{
	r_up.inp_count = count;
	r_up.inp_data = input;
	r_up.out_count = count * m_fact;
	r_up.out_data = output;
	r_up.process();
	assert(r_up.inp_count == 0);
	assert(r_up.out_count == 0);
}

void SimpleResampler::down(int count, float *input, float *output)
{
	r_down.inp_count = count * m_fact;
	r_down.inp_data = input;
	r_down.out_count = count+1; // +1 == trick to drain input
	r_down.out_data = output;
	r_down.process();
	assert(r_down.inp_count == 0);
	assert(r_down.out_count == 1);
}

class Gx_sfp_
{
private:
  // pointer to buffer
  float*      output;
  float*      input;
  // pointer to dsp class
  PluginLV2*  sfp_p1;
  PluginLV2*  sfp_clip;
  PluginLV2*  sfp_p2;
  uint32_t fSamplingFreq;
  SimpleResampler smp;
  unsigned int fact;
  // private functions
  inline void run_dsp_(uint32_t n_samples);
  inline void connect_(uint32_t port,void* data);
  inline void init_dsp_(uint32_t rate);
  inline void connect_all__ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();

public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  Gx_sfp_();
  ~Gx_sfp_();
};

// constructor
Gx_sfp_::Gx_sfp_() :
  output(NULL),
  input(NULL),
  sfp_p1(sfp_p1::plugin()),
  sfp_clip(sfp_clip::plugin()),
  sfp_p2(sfp_p2::plugin()) {};

// destructor
Gx_sfp_::~Gx_sfp_()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (sfp_p1->activate_plugin !=0)
    sfp_p1->activate_plugin(false, sfp_p1);
  // delete DSP class
  sfp_p1->delete_instance(sfp_p1);
  if (sfp_clip->activate_plugin !=0)
    sfp_clip->activate_plugin(false, sfp_clip);
  // delete DSP class
  sfp_clip->delete_instance(sfp_clip);
  if (sfp_p2->activate_plugin !=0)
    sfp_p2->activate_plugin(false, sfp_p2);
  // delete DSP class
  sfp_p2->delete_instance(sfp_p2);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Gx_sfp_::init_dsp_(uint32_t rate)
{
  fSamplingFreq = rate;
  // samplerate check
  fact = fSamplingFreq/48000;
  if (fact>1) {
    smp.setup(fSamplingFreq, fact);
    fSamplingFreq = 48000;
  }
  sfp_p1->set_samplerate(fSamplingFreq, sfp_p1); // init the DSP class
  sfp_clip->set_samplerate(fSamplingFreq, sfp_clip); // init the DSP class
  sfp_p2->set_samplerate(fSamplingFreq, sfp_p2); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_sfp_::connect_(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_sfp_::activate_f()
{
  // allocate the internal DSP mem
  if (sfp_p1->activate_plugin !=0)
    sfp_p1->activate_plugin(true, sfp_p1);
  if (sfp_clip->activate_plugin !=0)
    sfp_clip->activate_plugin(true, sfp_clip);
  if (sfp_p2->activate_plugin !=0)
    sfp_p2->activate_plugin(true, sfp_p2);
}

void Gx_sfp_::clean_up()
{
  // delete the internal DSP mem
  if (sfp_p1->activate_plugin !=0)
    sfp_p1->activate_plugin(false, sfp_p1);
  if (sfp_clip->activate_plugin !=0)
    sfp_clip->activate_plugin(false, sfp_clip);
  if (sfp_p2->activate_plugin !=0)
    sfp_p2->activate_plugin(false, sfp_p2);
}

void Gx_sfp_::deactivate_f()
{
  // delete the internal DSP mem
  if (sfp_p1->activate_plugin !=0)
    sfp_p1->activate_plugin(false, sfp_p1);
  if (sfp_clip->activate_plugin !=0)
    sfp_clip->activate_plugin(false, sfp_clip);
  if (sfp_p2->activate_plugin !=0)
    sfp_p2->activate_plugin(false, sfp_p2);
}

void Gx_sfp_::run_dsp_(uint32_t n_samples)
{
  uint32_t ReCount = n_samples;
  if (fact>1) {
    ReCount = n_samples/fact ;
  }
  FAUSTFLOAT buf[ReCount];
  if (fact>1) {
     smp.down(ReCount, input, buf);
  } else {
    memcpy(buf, input, n_samples*sizeof(float));
  }
  sfp_p1->mono_audio(static_cast<int>(ReCount), buf, buf, sfp_p1);
  sfp_clip->mono_audio(static_cast<int>(ReCount), buf, buf, sfp_clip);
  sfp_p2->mono_audio(static_cast<int>(ReCount), buf, buf, sfp_p2);
  if (fact>1) {
    smp.up(ReCount, buf, output);
  } else {
    memcpy(output, buf, n_samples*sizeof(float));
  }
}

void Gx_sfp_::connect_all__ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_(port,data); 
  // connect the Ports used by the DSP class
  sfp_p1->connect_ports(port,  data, sfp_p1);
  sfp_clip->connect_ports(port,  data, sfp_clip);
  sfp_p2->connect_ports(port,  data, sfp_p2);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Gx_sfp_::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_sfp_ *self = new Gx_sfp_();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_sfp_::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<Gx_sfp_*>(instance)->connect_all__ports(port, data);
}

void Gx_sfp_::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_sfp_*>(instance)->activate_f();
}

void Gx_sfp_::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_sfp_*>(instance)->run_dsp_(n_samples);
}

void Gx_sfp_::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_sfp_*>(instance)->deactivate_f();
}

void Gx_sfp_::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_sfp_* self = static_cast<Gx_sfp_*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gx_sfp_::descriptor =
{
  GXPLUGIN_URI "#_sfp_",
  Gx_sfp_::instantiate,
  Gx_sfp_::connect_port,
  Gx_sfp_::activate,
  Gx_sfp_::run,
  Gx_sfp_::deactivate,
  Gx_sfp_::cleanup,
  NULL
};


} // end namespace sfp

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &sfp::Gx_sfp_::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
