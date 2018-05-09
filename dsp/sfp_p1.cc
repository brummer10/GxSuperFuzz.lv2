// generated from file './/sfp_p1.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace sfp_p1 {

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
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fVec0[2];
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fRec4[2];
	double 	fRec3[6];
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec5[2];
	double 	fVec1[2];
	double 	fConst52;
	double 	fRec2[2];
	double 	fRec1[5];
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;

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
	for (int i=0; i<6; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
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
	fConst2 = (2.05622157103542e-20 * fConst1);
	fConst3 = ((fConst1 * ((fConst1 * ((fConst1 * (0 - (1.80052581626697e-17 + fConst2))) - 8.9116016172994e-17)) - 8.06858552953373e-17)) - 2.03513434786736e-17);
	fConst4 = (1.01060172159129e-20 * fConst1);
	fConst5 = (2.03513460543809e-17 + (fConst1 * (8.06858604331616e-17 + (fConst1 * (8.0634909264833e-17 + (fConst1 * (2.87093333481566e-18 + fConst4)))))));
	fConst6 = (1.84708529522986e-19 * fConst1);
	fConst7 = (9.13123542662614e-16 + (fConst1 * (2.31469014072784e-15 + (fConst1 * (1.36914113807875e-15 + (fConst1 * (1.83475075894458e-16 + fConst6)))))));
	fConst8 = (9.09577352129774e-21 * fConst1);
	fConst9 = (5.54006149590308e-19 + (fConst1 * (fConst8 - 2.72598623324966e-19)));
	fConst10 = (3.07685811911133e-18 * fConst1);
	fConst11 = (4.08800058161684e-16 + (fConst1 * (fConst10 - 1.00183267050103e-16)));
	fConst12 = (1.62091769212376e-18 * fConst1);
	fConst13 = ((fConst1 * (5.25997200776013e-17 - fConst12)) - 2.10421942979062e-16);
	fConst14 = ((fConst1 * (8.06858552953373e-17 + (fConst1 * ((fConst1 * (1.80052581626697e-17 - fConst2)) - 8.9116016172994e-17)))) - 2.03513434786736e-17);
	fConst15 = (2.03513460543809e-17 + (fConst1 * ((fConst1 * (8.0634909264833e-17 + (fConst1 * (fConst4 - 2.87093333481566e-18)))) - 8.06858604331616e-17)));
	fConst16 = (9.13123542662614e-16 + (fConst1 * ((fConst1 * (1.36914113807875e-15 + (fConst1 * (fConst6 - 1.83475075894458e-16)))) - 2.31469014072784e-15)));
	fConst17 = (8.22488628414166e-20 * fConst1);
	fConst18 = faustpower<2>(fConst1);
	fConst19 = ((fConst1 * (1.61371710590675e-16 + (fConst18 * (fConst17 - 3.60105163253394e-17)))) - 8.14053739146943e-17);
	fConst20 = (4.04240688636518e-20 * fConst1);
	fConst21 = (8.14053842175235e-17 + (fConst1 * ((fConst18 * (5.74186666963131e-18 - fConst20)) - 1.61371720866323e-16)));
	fConst22 = (7.38834118091945e-19 * fConst1);
	fConst23 = (3.65249417065045e-15 + (fConst1 * ((fConst18 * (3.66950151788917e-16 - fConst22)) - 4.62938028145568e-15)));
	fConst24 = ((fConst18 * (1.78232032345988e-16 - (1.23373294262125e-19 * fConst18))) - 1.22108060872041e-16);
	fConst25 = (1.22108076326285e-16 + (fConst18 * ((6.06361032954776e-20 * fConst18) - 1.61269818529666e-16)));
	fConst26 = (5.47874125597568e-15 + (fConst18 * ((1.10825117713792e-18 * fConst18) - 2.7382822761575e-15)));
	fConst27 = ((fConst1 * ((fConst18 * (3.60105163253394e-17 + fConst17)) - 1.61371710590675e-16)) - 8.14053739146943e-17);
	fConst28 = (8.14053842175235e-17 + (fConst1 * (1.61371720866323e-16 + (fConst18 * (0 - (5.74186666963131e-18 + fConst20))))));
	fConst29 = (3.65249417065045e-15 + (fConst1 * (4.62938028145568e-15 + (fConst18 * (0 - (3.66950151788917e-16 + fConst22))))));
	fConst30 = (3.54359308063424e-24 * fConst1);
	fConst31 = (1.94643920812984e-18 + (fConst1 * ((fConst1 * (2.77200698725965e-17 + (fConst1 * ((fConst1 * (1.80920540450679e-20 - fConst30)) - 9.38774091555291e-18)))) - 2.0298803841787e-17)));
	fConst32 = (1.77179654031712e-23 * fConst1);
	fConst33 = (9.73219604064918e-18 + (fConst1 * ((fConst1 * (2.77200698725965e-17 + (fConst1 * (9.38774091555291e-18 + (fConst1 * (fConst32 - 5.42761621352036e-20)))))) - 6.08964115253609e-17)));
	fConst34 = (3.54359308063424e-23 * fConst1);
	fConst35 = (1.94643920812984e-17 + (fConst1 * ((fConst1 * ((fConst1 * (1.87754818311058e-17 + (fConst1 * (3.61841080901358e-20 - fConst34)))) - 5.54401397451929e-17)) - 4.0597607683574e-17)));
	fConst36 = (1.94643920812984e-17 + (fConst1 * (4.0597607683574e-17 + (fConst1 * ((fConst1 * ((fConst1 * (3.61841080901358e-20 + fConst34)) - 1.87754818311058e-17)) - 5.54401397451929e-17)))));
	fConst37 = (9.73219604064918e-18 + (fConst1 * (6.08964115253609e-17 + (fConst1 * (2.77200698725965e-17 + (fConst1 * ((fConst1 * (0 - (5.42761621352036e-20 + fConst32))) - 9.38774091555291e-18)))))));
	fConst38 = (1.94643920812984e-18 + (fConst1 * (2.0298803841787e-17 + (fConst1 * (2.77200698725965e-17 + (fConst1 * (9.38774091555291e-18 + (fConst1 * (1.80920540450679e-20 + fConst30)))))))));
	fConst39 = (1.0 / fConst38);
	fConst40 = (470.33999466970965 / fConst0);
	fConst41 = (1 - fConst40);
	fConst42 = (1.0 / (1 + fConst40));
	fConst43 = (2.54522299651678e-19 * fConst1);
	fConst44 = ((fConst1 * (4.27785660896858e-17 - fConst43)) - 1.64186678306723e-17);
	fConst45 = (7.63566898955033e-19 * fConst1);
	fConst46 = ((fConst1 * (fConst45 - 4.27785660896858e-17)) - 1.64186678306723e-17);
	fConst47 = (5.09044599303355e-19 * fConst1);
	fConst48 = (3.28373356613446e-17 + (fConst1 * (0 - (8.55571321793716e-17 + fConst47))));
	fConst49 = (3.28373356613446e-17 + (fConst1 * (8.55571321793716e-17 - fConst47)));
	fConst50 = ((fConst1 * (4.27785660896858e-17 + fConst45)) - 1.64186678306723e-17);
	fConst51 = ((fConst1 * (0 - (4.27785660896858e-17 + fConst43))) - 1.64186678306723e-17);
	fConst52 = (fConst18 / fConst38);
	fConst53 = ((5.45746411277865e-20 * fConst18) - 1.10801229918062e-18);
	fConst54 = ((1.8461148714668e-17 * fConst18) - 8.17600116323368e-16);
	fConst55 = (4.20843885958123e-16 - (9.72550615274259e-18 * fConst18));
	fConst56 = (5.54006149590308e-19 + (fConst1 * (2.72598623324966e-19 + fConst8)));
	fConst57 = (4.08800058161684e-16 + (fConst1 * (1.00183267050103e-16 + fConst10)));
	fConst58 = ((fConst1 * (0 - (5.25997200776013e-17 + fConst12))) - 2.10421942979062e-16);
	fConst59 = (1.23074324764453e-17 * fConst1);
	fConst60 = (2.00366534100206e-16 + fConst59);
	fConst61 = (3.6383094085191e-20 * fConst1);
	fConst62 = (0 - (5.45197246649933e-19 + fConst61));
	fConst63 = (6.48367076849506e-18 * fConst1);
	fConst64 = (1.05199440155203e-16 + fConst63);
	fConst65 = (5.45197246649933e-19 - fConst61);
	fConst66 = (2.00366534100206e-16 - fConst59);
	fConst67 = (fConst63 - 1.05199440155203e-16);
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
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	for (int i=0; i<count; i++) {
		fRec0[0] = (fSlow0 + (0.993 * fRec0[1]));
		double fTemp0 = (fConst7 + (fRec0[0] * (fConst5 + (fConst3 * fRec0[0]))));
		double fTemp1 = (double)input0[i];
		fVec0[0] = fTemp1;
		fRec4[0] = (fConst42 * ((fVec0[0] + (fConst41 * fRec4[1])) - fVec0[1]));
		fRec3[0] = (fRec4[0] - (fConst39 * (((((fConst37 * fRec3[1]) + (fConst36 * fRec3[2])) + (fConst35 * fRec3[3])) + (fConst33 * fRec3[4])) + (fConst31 * fRec3[5]))));
		fRec5[0] = (fSlow1 + (0.993 * fRec5[1]));
		double fTemp2 = (fRec5[0] * ((((((fConst51 * fRec3[0]) + (fConst50 * fRec3[1])) + (fConst49 * fRec3[2])) + (fConst48 * fRec3[3])) + (fConst46 * fRec3[4])) + (fConst44 * fRec3[5])));
		fVec1[0] = fTemp2;
		fRec2[0] = (fConst42 * ((fConst41 * fRec2[1]) + (fConst52 * (fVec1[0] - fVec1[1]))));
		fRec1[0] = (fRec2[0] - (((((fRec1[1] * (fConst29 + (fRec0[0] * (fConst28 + (fConst27 * fRec0[0]))))) + (fRec1[2] * (fConst26 + (fRec0[0] * (fConst25 + (fConst24 * fRec0[0])))))) + (fRec1[3] * (fConst23 + (fRec0[0] * (fConst21 + (fConst19 * fRec0[0])))))) + (fRec1[4] * (fConst16 + (fRec0[0] * (fConst15 + (fConst14 * fRec0[0])))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst18 * ((((fConst1 * ((fRec1[3] * (fConst67 + (fRec0[0] * (fConst66 + (fConst65 * fRec0[0]))))) + (fRec1[1] * (fConst64 + (fRec0[0] * ((fConst62 * fRec0[0]) - fConst60)))))) + ((fRec1[0] * (fConst58 + (fRec0[0] * (fConst57 + (fConst56 * fRec0[0]))))) + (fRec1[2] * (fConst55 + (fRec0[0] * (fConst54 + (fConst53 * fRec0[0]))))))) + (fRec1[4] * (fConst13 + (fRec0[0] * (fConst11 + (fConst9 * fRec0[0])))))) / fTemp0));
		// post processing
		for (int i=4; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec2[1] = fRec2[0];
		fVec1[1] = fVec1[0];
		fRec5[1] = fRec5[0];
		for (int i=5; i>0; i--) fRec3[i] = fRec3[i-1];
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
	case EXPANDER: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
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
   EXPANDER, 
   TRIM, 
} PortIndex;
*/

} // end namespace sfp_p1
