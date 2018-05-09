// generated from file './/sfp_clip.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace sfp_clip {

template <int tab_size>
struct table1d_imp { // 1-dimensional clipping table
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
};

static table1d_imp<100> clip __rt_data = {
	0.0,0.394515179396,101.97,100, {
	0.0,0.00603015075129,0.0180904522522,0.0301507537469,0.0422110552265,0.0542713566722,
	0.0663316580417,0.0783919592408,0.0904522600592,0.102512560027,0.114572858094,
	0.126633151913,0.13869343624,0.15075369936,0.162813915089,0.174874024928,
	0.18693389817,0.198993242803,0.21105140661,0.223106933614,0.235156577432,
	0.247193118816,0.259200598174,0.271144190587,0.282950034925,0.294470641721,
	0.305445189377,0.315505844416,0.324302375812,0.331685149347,0.337749693783,
	0.34272268487,0.34684305184,0.350309449589,0.353272707062,0.355843964801,
	0.35810490171,0.360116111787,0.361923194669,0.363561013504,0.365056646443,
	0.366431442802,0.367702471426,0.368883554945,0.369986019104,0.371019243547,
	0.371991072367,0.372908124189,0.373776029317,0.374599613231,0.375383040109,
	0.37612992624,0.376843430486,0.377526327079,0.378181064683,0.37880981468,
	0.379414510938,0.379996882771,0.380558482439,0.381100708226,0.381624823916,
	0.382131975308,0.3826232043,0.38309946095,0.383561613855,0.384010459105,
	0.384446728066,0.38487109414,0.385284178678,0.385686556167,0.386078758778,
	0.386461280398,0.386834580178,0.387199085695,0.387555195759,0.387903282914,
	0.388243695683,0.38857676057,0.38890278387,0.389222053284,0.389534839388,
	0.389841396959,0.390141966168,0.390436773672,0.390726033604,0.39100994847,
	0.391288709974,0.391562499764,0.391831490126,0.392095844606,0.392355718592,
	0.392611259843,0.39286260898,0.393109899932,0.393353260356,0.393592812019,
	0.393828671151,0.394060948779,0.394289751025,0.394515179396
	}
};

#define MAX_UPSAMPLE 8

class SimpleResampler
{
private:
  Resampler r_up, r_down;
  int32_t m_fact;
  int32_t ratio_a;
  int32_t ratio_b;
  static uint32_t gcd (int32_t a, int32_t b);
public:
  SimpleResampler(): r_up(), r_down(), m_fact() {}
  void setup(int32_t sampleRate, uint32_t fact);
  int32_t up(int32_t count, float *input, float *output);
  void down(int32_t count, float *input, float *output);
  int32_t get_max_out_size(int32_t i_size)
  {
    return (i_size * ratio_b) / ratio_a + 1;
  }
};

uint32_t SimpleResampler::gcd (int32_t a, int32_t b)
{
  if (a == 0) return b;
  if (b == 0) return a;
  while (1)
    {
      if (a > b)
        {
          a = a % b;
          if (a == 0) return b;
          if (a == 1) return 1;
        }
      else
        {
          b = b % a;
          if (b == 0) return a;
          if (b == 1) return 1;
        }
    }
  return 1;
}

void SimpleResampler::setup(int32_t sampleRate, uint32_t factum)
{
  int32_t fact = static_cast<int32_t>(factum);
  int32_t d = gcd(sampleRate, sampleRate*fact);
  ratio_a = sampleRate / d;
  ratio_b = (sampleRate*fact) / d;

  assert(fact <= MAX_UPSAMPLE);
  m_fact = fact;
  const int32_t qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
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
  // std::cout<<"SimpleResampler::setup "<<sampleRate<<" "<<fact<<std::endl;
}

int32_t SimpleResampler::up(int32_t count, float *input, float *output)
{
  r_up.inp_count = count;
  r_up.inp_data = input;
  int m = get_max_out_size(count);
  r_up.out_count = m;
  r_up.out_data = output;
  r_up.process();
  assert(r_up.inp_count == 0);
  assert(r_up.out_count <= 1);
  r_down.inp_count = m - r_up.out_count;
  return r_down.inp_count;
}

void SimpleResampler::down(int32_t count, float *input, float *output)
{
  r_down.inp_count = count * m_fact;
  r_down.inp_data = input;
  r_down.out_count = count+1; // +1 == trick to drain input
  r_down.out_data = output;
  r_down.process();
  assert(r_down.inp_count == 0);
  assert(r_down.out_count == 1);
}

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	SimpleResampler res;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static double tranyclip(double x);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "sfp";
	name = N_("SuperFuzz");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
    res.setup(samplingFreq,4);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

double always_inline Dsp::tranyclip(double x) {
    double f = fabs(x);
    f = (f - clip.low) * clip.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = clip.data[0];
    } else if (i >= clip.size-1) {
        f = clip.data[clip.size-1];
    } else {
	f -= i;
	f = clip.data[i]*(1-f) + clip.data[i+1]*f;
    }
    return copysign(f, -x);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
    int rescount = res.get_max_out_size(count);
    float buf[rescount];
    res.up(count,input0,buf);
	for (int i=0; i<rescount; i++) {
        double fTemp0 = buf[i];
		fRec0[0] = (fSlow0 + (0.993 * fRec0[1]));
		buf[i] = (FAUSTFLOAT)(tranyclip((double)fTemp0) * (1.0 + (6 * max((double)0, (fRec0[0] - 0.35)))));
		// post processing
		fRec0[1] = fRec0[0];
	}
    res.down(count,buf,output0);
#undef fslider0
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case TRIM: 
		fslider0_ = (float*)data; // , 0.25, 0.0, 0.49, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   TRIM, 
} PortIndex;
*/

} // end namespace sfp_clip
