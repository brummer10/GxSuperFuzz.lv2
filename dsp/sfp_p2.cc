// generated from file './/sfp_p2.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace sfp_p2 {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fVec0[2];
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fRec4[2];
	double 	fRec3[4];
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fVec1[2];
	double 	fRec2[2];
	double 	fRec1[5];
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
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
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<4; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<5; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = min(1.92e+05, max(1.0, (double)fSamplingFreq));
	fConst1 = double(fConst0);
	fConst2 = (3.7623572423036e-32 * fConst1);
	fConst3 = (2.61915652513995e-14 + fConst2);
	fConst4 = ((fConst1 * ((fConst1 * (0 - fConst3)) - 1.91661440591131e-10)) - 6.34637642560352e-12);
	fConst5 = (6.34637642560352e-12 + (fConst1 * (1.91661440591131e-10 + (fConst1 * fConst3))));
	fConst6 = (4.62843186694136e-16 * fConst1);
	fConst7 = (1.93302728487208e-10 + (fConst1 * (4.95931014548854e-11 + fConst6)));
	fConst8 = (6.34637642560352e-12 + (fConst1 * ((fConst1 * (2.61915652513995e-14 - fConst2)) - 1.91661440591131e-10)));
	fConst9 = ((fConst1 * (1.91661440591131e-10 + (fConst1 * (fConst2 - 2.61915652513995e-14)))) - 6.34637642560352e-12);
	fConst10 = ((fConst1 * (4.95931014548854e-11 - fConst6)) - 1.93302728487208e-10);
	fConst11 = (1.50494289692144e-31 * fConst1);
	fConst12 = faustpower<2>(fConst1);
	fConst13 = (1.2692752851207e-11 + (fConst12 * (fConst11 - 5.23831305027991e-14)));
	fConst14 = ((fConst12 * (5.23831305027991e-14 - fConst11)) - 1.2692752851207e-11);
	fConst15 = (9.25686373388272e-16 * fConst12);
	fConst16 = (fConst15 - 3.86605456974416e-10);
	fConst17 = (2.25741434538216e-31 * fConst12);
	fConst18 = (3.83322881182262e-10 - fConst17);
	fConst19 = (fConst17 - 3.83322881182262e-10);
	fConst20 = (5.23831305027991e-14 + fConst11);
	fConst21 = ((fConst12 * fConst20) - 1.2692752851207e-11);
	fConst22 = (1.2692752851207e-11 + (fConst12 * (0 - fConst20)));
	fConst23 = (3.86605456974416e-10 - fConst15);
	fConst24 = (4.38520579615081e-15 * fConst1);
	fConst25 = (4.37121789887425e-08 + (fConst1 * ((fConst1 * (2.22485269464101e-10 - fConst24)) - 5.05253340546452e-08)));
	fConst26 = (1.31556173884524e-14 * fConst1);
	fConst27 = (1.31136536966227e-07 + (fConst1 * ((fConst1 * (fConst26 - 2.22485269464101e-10)) - 5.05253340546452e-08)));
	fConst28 = (1.31136536966227e-07 + (fConst1 * (5.05253340546452e-08 + (fConst1 * (0 - (2.22485269464101e-10 + fConst26))))));
	fConst29 = (4.37121789887425e-08 + (fConst1 * (5.05253340546452e-08 + (fConst1 * (2.22485269464101e-10 + fConst24)))));
	fConst30 = (1.0 / fConst29);
	fConst31 = (470.33999466970965 / fConst0);
	fConst32 = (1 - fConst31);
	fConst33 = (1.0 / (1 + fConst31));
	fConst34 = ((fConst1 * (3.18924057901876e-12 - fConst24)) - 4.98318840471683e-08);
	fConst35 = ((fConst1 * (fConst26 - 3.18924057901876e-12)) - 4.98318840471683e-08);
	fConst36 = (4.98318840471683e-08 + (fConst1 * (0 - (3.18924057901876e-12 + fConst26))));
	fConst37 = (4.98318840471683e-08 + (fConst1 * (3.18924057901876e-12 + fConst24)));
	fConst38 = (fConst1 / fConst29);
	fConst39 = (7.69334350201899e-16 * fConst1);
	fConst40 = ((fConst1 * (3.90262334011509e-11 - fConst39)) - 8.74243579774876e-09);
	fConst41 = (2.3080030506057e-15 * fConst1);
	fConst42 = ((fConst1 * (fConst41 - 3.90262334011509e-11)) - 8.74243579774876e-09);
	fConst43 = (8.74243579774876e-09 + (fConst1 * (0 - (3.90262334011509e-11 + fConst41))));
	fConst44 = (8.74243579774876e-09 + (fConst1 * (3.90262334011509e-11 + fConst39)));
	fConst45 = (4.62843186693736e-16 * fConst1);
	fConst46 = (0 - (4.69622192759233e-10 + fConst45));
	fConst47 = (9.25686373387472e-16 * fConst1);
	fConst48 = (fConst45 - 4.69622192759233e-10);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	int 	iSlow1 = int(double(fslider1));
	for (int i=0; i<count; i++) {
		fRec0[0] = (fSlow0 + (0.993 * fRec0[1]));
		double fTemp0 = (6.34637642560352e-12 + (fConst1 * (fConst7 + (fRec0[0] * (fConst5 + (fConst4 * fRec0[0]))))));
		double fTemp1 = (double)input0[i];
		fVec0[0] = fTemp1;
		fRec4[0] = (fConst33 * ((fVec0[0] + (fConst32 * fRec4[1])) - fVec0[1]));
		fRec3[0] = (fRec4[0] - (fConst30 * (((fConst28 * fRec3[1]) + (fConst27 * fRec3[2])) + (fConst25 * fRec3[3]))));
		double fTemp2 = ((iSlow1)?(fConst38 * ((((fConst44 * fRec3[0]) + (fConst43 * fRec3[1])) + (fConst42 * fRec3[2])) + (fConst40 * fRec3[3]))):(fConst38 * ((((fConst37 * fRec3[0]) + (fConst36 * fRec3[1])) + (fConst35 * fRec3[2])) + (fConst34 * fRec3[3]))));
		fVec1[0] = fTemp2;
		fRec2[0] = (fConst33 * (((fConst32 * fRec2[1]) + fVec1[0]) - fVec1[1]));
		fRec1[0] = (fRec2[0] - ((((fRec1[1] * (2.53855057024141e-11 + (fConst1 * (fConst23 + (fRec0[0] * (fConst22 + (fConst21 * fRec0[0]))))))) + ((fRec1[2] * (3.80782585536211e-11 + (fConst12 * ((fRec0[0] * (fConst19 + (fConst18 * fRec0[0]))) - 9.91862029097707e-11)))) + (fRec1[3] * (2.53855057024141e-11 + (fConst1 * (fConst16 + (fRec0[0] * (fConst14 + (fConst13 * fRec0[0]))))))))) + (fRec1[4] * (6.34637642560352e-12 + (fConst1 * (fConst10 + (fRec0[0] * (fConst9 + (fConst8 * fRec0[0])))))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst12 * (((fConst1 * (fRec1[1] * (0 - (9.25686373387472e-16 * fRec0[0])))) + (fRec0[0] * ((((fConst48 * fRec1[0]) + (9.39244385518467e-10 * fRec1[2])) + (fConst47 * fRec1[3])) + (fConst46 * fRec1[4])))) / fTemp0));
		// post processing
		for (int i=4; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec2[1] = fRec2[0];
		fVec1[1] = fVec1[0];
		for (int i=3; i>0; i--) fRec3[i] = fRec3[i-1];
		fRec4[1] = fRec4[0];
		fVec0[1] = fVec0[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case BALANCE: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	// static const value_pair fslider1_values[] = {{"ON"},{"OFF"},{0}};
	case TONE: 
		fslider1_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
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
   BALANCE, 
   TONE, 
} PortIndex;
*/

} // end namespace sfp_p2
