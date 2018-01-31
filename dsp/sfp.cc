// generated from file './/sfp.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace sfp {

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

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
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
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec5[2];
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
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
	double 	fConst68;
	double 	fConst69;
	double 	fVec0[2];
	double 	fConst70;
	double 	fRec9[2];
	double 	fRec8[6];
	double 	fConst71;
	double 	fConst72;
	double 	fConst73;
	double 	fConst74;
	double 	fConst75;
	double 	fConst76;
	double 	fConst77;
	double 	fConst78;
	double 	fConst79;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec10[2];
	double 	fVec1[2];
	double 	fConst80;
	double 	fRec7[2];
	double 	fRec6[5];
	double 	fConst81;
	double 	fConst82;
	double 	fConst83;
	double 	fConst84;
	double 	fConst85;
	double 	fConst86;
	double 	fConst87;
	double 	fConst88;
	double 	fConst89;
	double 	fConst90;
	double 	fConst91;
	double 	fConst92;
	double 	fConst93;
	double 	fConst94;
	double 	fConst95;
	double 	fVec2[2];
	double 	fRec4[2];
	double 	fRec3[4];
	double 	fConst96;
	double 	fConst97;
	double 	fConst98;
	double 	fConst99;
	double 	fConst100;
	double 	fConst101;
	double 	fConst102;
	double 	fConst103;
	double 	fConst104;
	double 	fConst105;
	double 	fConst106;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fVec3[2];
	double 	fRec2[2];
	double 	fRec1[5];
	double 	fConst107;
	double 	fConst108;
	double 	fConst109;
	double 	fConst110;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static double symclip(double x);
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
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<6; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<5; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<4; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
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
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = double(iConst0);
	fConst2 = (4.62843186694136e-16 * fConst1);
	fConst3 = (1.93302728487208e-10 + (fConst1 * (4.95931014548854e-11 + fConst2)));
	fConst4 = (3.7623572423036e-32 * fConst1);
	fConst5 = (2.61915652513995e-14 + fConst4);
	fConst6 = ((fConst1 * ((fConst1 * (0 - fConst5)) - 1.91661440591131e-10)) - 6.34637642560352e-12);
	fConst7 = (6.34637642560352e-12 + (fConst1 * (1.91661440591131e-10 + (fConst1 * fConst5))));
	fConst8 = ((fConst1 * (4.95931014548854e-11 - fConst2)) - 1.93302728487208e-10);
	fConst9 = (6.34637642560352e-12 + (fConst1 * ((fConst1 * (2.61915652513995e-14 - fConst4)) - 1.91661440591131e-10)));
	fConst10 = ((fConst1 * (1.91661440591131e-10 + (fConst1 * (fConst4 - 2.61915652513995e-14)))) - 6.34637642560352e-12);
	fConst11 = (1.50494289692144e-31 * fConst1);
	fConst12 = faustpower<2>(fConst1);
	fConst13 = (1.2692752851207e-11 + (fConst12 * (fConst11 - 5.23831305027991e-14)));
	fConst14 = ((fConst12 * (5.23831305027991e-14 - fConst11)) - 1.2692752851207e-11);
	fConst15 = (9.25686373388272e-16 * fConst12);
	fConst16 = (fConst15 - 3.86605456974416e-10);
	fConst17 = (2.25741434538216e-31 * fConst12);
	fConst18 = (3.83322881182262e-10 - fConst17);
	fConst19 = (fConst17 - 3.83322881182262e-10);
	fConst20 = (3.86605456974416e-10 - fConst15);
	fConst21 = (5.23831305027991e-14 + fConst11);
	fConst22 = ((fConst12 * fConst21) - 1.2692752851207e-11);
	fConst23 = (1.2692752851207e-11 + (fConst12 * (0 - fConst21)));
	fConst24 = (470.33999466970965 / double(iConst0));
	fConst25 = (1 - fConst24);
	fConst26 = (4.38520579615081e-15 * fConst1);
	fConst27 = (4.37121789887425e-08 + (fConst1 * ((fConst1 * (2.22485269464101e-10 - fConst26)) - 5.05253340546452e-08)));
	fConst28 = (1.31556173884524e-14 * fConst1);
	fConst29 = (1.31136536966227e-07 + (fConst1 * ((fConst1 * (fConst28 - 2.22485269464101e-10)) - 5.05253340546452e-08)));
	fConst30 = (1.31136536966227e-07 + (fConst1 * (5.05253340546452e-08 + (fConst1 * (0 - (2.22485269464101e-10 + fConst28))))));
	fConst31 = (4.37121789887425e-08 + (fConst1 * (5.05253340546452e-08 + (fConst1 * (2.22485269464101e-10 + fConst26)))));
	fConst32 = (1.0 / fConst31);
	fConst33 = (1.84708529522986e-19 * fConst1);
	fConst34 = (9.13123542662614e-16 + (fConst1 * (2.31469014072784e-15 + (fConst1 * (1.36914113807875e-15 + (fConst1 * (1.83475075894458e-16 + fConst33)))))));
	fConst35 = (1.01060172159129e-20 * fConst1);
	fConst36 = (2.03513460543809e-17 + (fConst1 * (8.06858604331616e-17 + (fConst1 * (8.0634909264833e-17 + (fConst1 * (2.87093333481566e-18 + fConst35)))))));
	fConst37 = (2.05622157103542e-20 * fConst1);
	fConst38 = ((fConst1 * ((fConst1 * ((fConst1 * (0 - (1.80052581626697e-17 + fConst37))) - 8.9116016172994e-17)) - 8.06858552953373e-17)) - 2.03513434786736e-17);
	fConst39 = (1.62091769212376e-18 * fConst1);
	fConst40 = ((fConst1 * (5.25997200776013e-17 - fConst39)) - 2.10421942979062e-16);
	fConst41 = (9.09577352129774e-21 * fConst1);
	fConst42 = (5.54006149590308e-19 + (fConst1 * (fConst41 - 2.72598623324966e-19)));
	fConst43 = (3.07685811911133e-18 * fConst1);
	fConst44 = (4.08800058161684e-16 + (fConst1 * (fConst43 - 1.00183267050103e-16)));
	fConst45 = (9.13123542662614e-16 + (fConst1 * ((fConst1 * (1.36914113807875e-15 + (fConst1 * (fConst33 - 1.83475075894458e-16)))) - 2.31469014072784e-15)));
	fConst46 = (2.03513460543809e-17 + (fConst1 * ((fConst1 * (8.0634909264833e-17 + (fConst1 * (fConst35 - 2.87093333481566e-18)))) - 8.06858604331616e-17)));
	fConst47 = ((fConst1 * (8.06858552953373e-17 + (fConst1 * ((fConst1 * (1.80052581626697e-17 - fConst37)) - 8.9116016172994e-17)))) - 2.03513434786736e-17);
	fConst48 = (7.38834118091945e-19 * fConst1);
	fConst49 = (3.65249417065045e-15 + (fConst1 * ((fConst12 * (3.66950151788917e-16 - fConst48)) - 4.62938028145568e-15)));
	fConst50 = (4.04240688636518e-20 * fConst1);
	fConst51 = (8.14053842175235e-17 + (fConst1 * ((fConst12 * (5.74186666963131e-18 - fConst50)) - 1.61371720866323e-16)));
	fConst52 = (8.22488628414166e-20 * fConst1);
	fConst53 = ((fConst1 * (1.61371710590675e-16 + (fConst12 * (fConst52 - 3.60105163253394e-17)))) - 8.14053739146943e-17);
	fConst54 = (5.47874125597568e-15 + (fConst12 * ((1.10825117713792e-18 * fConst12) - 2.7382822761575e-15)));
	fConst55 = (1.22108076326285e-16 + (fConst12 * ((6.06361032954776e-20 * fConst12) - 1.61269818529666e-16)));
	fConst56 = ((fConst12 * (1.78232032345988e-16 - (1.23373294262125e-19 * fConst12))) - 1.22108060872041e-16);
	fConst57 = (3.65249417065045e-15 + (fConst1 * (4.62938028145568e-15 + (fConst12 * (0 - (3.66950151788917e-16 + fConst48))))));
	fConst58 = (8.14053842175235e-17 + (fConst1 * (1.61371720866323e-16 + (fConst12 * (0 - (5.74186666963131e-18 + fConst50))))));
	fConst59 = ((fConst1 * ((fConst12 * (3.60105163253394e-17 + fConst52)) - 1.61371710590675e-16)) - 8.14053739146943e-17);
	fConst60 = (3.54359308063424e-24 * fConst1);
	fConst61 = (1.94643920812984e-18 + (fConst1 * ((fConst1 * (2.77200698725965e-17 + (fConst1 * ((fConst1 * (1.80920540450679e-20 - fConst60)) - 9.38774091555291e-18)))) - 2.0298803841787e-17)));
	fConst62 = (1.77179654031712e-23 * fConst1);
	fConst63 = (9.73219604064918e-18 + (fConst1 * ((fConst1 * (2.77200698725965e-17 + (fConst1 * (9.38774091555291e-18 + (fConst1 * (fConst62 - 5.42761621352036e-20)))))) - 6.08964115253609e-17)));
	fConst64 = (3.54359308063424e-23 * fConst1);
	fConst65 = (1.94643920812984e-17 + (fConst1 * ((fConst1 * ((fConst1 * (1.87754818311058e-17 + (fConst1 * (3.61841080901358e-20 - fConst64)))) - 5.54401397451929e-17)) - 4.0597607683574e-17)));
	fConst66 = (1.94643920812984e-17 + (fConst1 * (4.0597607683574e-17 + (fConst1 * ((fConst1 * ((fConst1 * (3.61841080901358e-20 + fConst64)) - 1.87754818311058e-17)) - 5.54401397451929e-17)))));
	fConst67 = (9.73219604064918e-18 + (fConst1 * (6.08964115253609e-17 + (fConst1 * (2.77200698725965e-17 + (fConst1 * ((fConst1 * (0 - (5.42761621352036e-20 + fConst62))) - 9.38774091555291e-18)))))));
	fConst68 = (1.94643920812984e-18 + (fConst1 * (2.0298803841787e-17 + (fConst1 * (2.77200698725965e-17 + (fConst1 * (9.38774091555291e-18 + (fConst1 * (1.80920540450679e-20 + fConst60)))))))));
	fConst69 = (1.0 / fConst68);
	fConst70 = (1.0 / (1 + fConst24));
	fConst71 = (2.54522299651678e-19 * fConst1);
	fConst72 = ((fConst1 * (4.27785660896858e-17 - fConst71)) - 1.64186678306723e-17);
	fConst73 = (7.63566898955033e-19 * fConst1);
	fConst74 = ((fConst1 * (fConst73 - 4.27785660896858e-17)) - 1.64186678306723e-17);
	fConst75 = (5.09044599303355e-19 * fConst1);
	fConst76 = (3.28373356613446e-17 + (fConst1 * (0 - (8.55571321793716e-17 + fConst75))));
	fConst77 = (3.28373356613446e-17 + (fConst1 * (8.55571321793716e-17 - fConst75)));
	fConst78 = ((fConst1 * (4.27785660896858e-17 + fConst73)) - 1.64186678306723e-17);
	fConst79 = ((fConst1 * (0 - (4.27785660896858e-17 + fConst71))) - 1.64186678306723e-17);
	fConst80 = (fConst12 / fConst68);
	fConst81 = (3.6383094085191e-20 * fConst1);
	fConst82 = (5.45197246649933e-19 - fConst81);
	fConst83 = (1.23074324764453e-17 * fConst1);
	fConst84 = (2.00366534100206e-16 - fConst83);
	fConst85 = (6.48367076849506e-18 * fConst1);
	fConst86 = (fConst85 - 1.05199440155203e-16);
	fConst87 = (4.20843885958123e-16 - (9.72550615274259e-18 * fConst12));
	fConst88 = ((5.45746411277865e-20 * fConst12) - 1.10801229918062e-18);
	fConst89 = ((1.8461148714668e-17 * fConst12) - 8.17600116323368e-16);
	fConst90 = (1.05199440155203e-16 + fConst85);
	fConst91 = (0 - (5.45197246649933e-19 + fConst81));
	fConst92 = (0 - (2.00366534100206e-16 + fConst83));
	fConst93 = ((fConst1 * (0 - (5.25997200776013e-17 + fConst39))) - 2.10421942979062e-16);
	fConst94 = (5.54006149590308e-19 + (fConst1 * (2.72598623324966e-19 + fConst41)));
	fConst95 = (4.08800058161684e-16 + (fConst1 * (1.00183267050103e-16 + fConst43)));
	fConst96 = ((fConst1 * (3.18924057901876e-12 - fConst26)) - 4.98318840471683e-08);
	fConst97 = ((fConst1 * (fConst28 - 3.18924057901876e-12)) - 4.98318840471683e-08);
	fConst98 = (4.98318840471683e-08 + (fConst1 * (0 - (3.18924057901876e-12 + fConst28))));
	fConst99 = (4.98318840471683e-08 + (fConst1 * (3.18924057901876e-12 + fConst26)));
	fConst100 = (fConst1 / fConst31);
	fConst101 = (7.69334350201899e-16 * fConst1);
	fConst102 = ((fConst1 * (3.90262334011509e-11 - fConst101)) - 8.74243579774876e-09);
	fConst103 = (2.3080030506057e-15 * fConst1);
	fConst104 = ((fConst1 * (fConst103 - 3.90262334011509e-11)) - 8.74243579774876e-09);
	fConst105 = (8.74243579774876e-09 + (fConst1 * (0 - (3.90262334011509e-11 + fConst103))));
	fConst106 = (8.74243579774876e-09 + (fConst1 * (3.90262334011509e-11 + fConst101)));
	fConst107 = (4.62843186693736e-16 * fConst1);
	fConst108 = (0 - (4.69622192759233e-10 + fConst107));
	fConst109 = (9.25686373387472e-16 * fConst1);
	fConst110 = (fConst107 - 4.69622192759233e-10);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

double always_inline Dsp::symclip(double x) {
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
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
#define fslider3 (*fslider3_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	int 	iSlow3 = int(double(fslider3));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = (6.34637642560352e-12 + (fConst1 * ((fRec0[0] * (fConst7 + (fConst6 * fRec0[0]))) + fConst3)));
		fRec5[0] = ((0.993 * fRec5[1]) + fSlow1);
		double fTemp1 = ((fRec5[0] * ((fConst38 * fRec5[0]) + fConst36)) + fConst34);
		double fTemp2 = (double)input0[i];
		fVec0[0] = fTemp2;
		fRec9[0] = (fConst70 * ((fVec0[0] - fVec0[1]) + (fConst25 * fRec9[1])));
		fRec8[0] = (fRec9[0] - (fConst69 * (((((fConst67 * fRec8[1]) + (fConst66 * fRec8[2])) + (fConst65 * fRec8[3])) + (fConst63 * fRec8[4])) + (fConst61 * fRec8[5]))));
		fRec10[0] = ((0.993 * fRec10[1]) + fSlow2);
		double fTemp3 = (fRec10[0] * ((((((fConst79 * fRec8[0]) + (fConst78 * fRec8[1])) + (fConst77 * fRec8[2])) + (fConst76 * fRec8[3])) + (fConst74 * fRec8[4])) + (fConst72 * fRec8[5])));
		fVec1[0] = fTemp3;
		fRec7[0] = (fConst70 * ((fConst25 * fRec7[1]) + (fConst80 * (fVec1[0] - fVec1[1]))));
		fRec6[0] = (fRec7[0] - (((((fRec6[1] * ((fRec5[0] * ((fConst59 * fRec5[0]) + fConst58)) + fConst57)) + (fRec6[2] * ((fRec5[0] * ((fConst56 * fRec5[0]) + fConst55)) + fConst54))) + (fRec6[3] * ((fRec5[0] * ((fConst53 * fRec5[0]) + fConst51)) + fConst49))) + (fRec6[4] * ((fRec5[0] * ((fConst47 * fRec5[0]) + fConst46)) + fConst45))) / fTemp1));
		double fTemp4 = ((1.0 + (6 * max((double)0, (fRec5[0] - 0.35)))) * symclip((fConst12 * ((((((fRec6[0] * ((fRec5[0] * (fConst95 + (fConst94 * fRec5[0]))) + fConst93)) + (fConst1 * (fRec6[1] * ((fRec5[0] * (fConst92 + (fConst91 * fRec5[0]))) + fConst90)))) + (fRec6[2] * ((fRec5[0] * (fConst89 + (fConst88 * fRec5[0]))) + fConst87))) + (fConst1 * (fRec6[3] * (fConst86 + (fRec5[0] * (fConst84 + (fConst82 * fRec5[0]))))))) + (fRec6[4] * ((fRec5[0] * (fConst44 + (fConst42 * fRec5[0]))) + fConst40))) / fTemp1))));
		fVec2[0] = fTemp4;
		fRec4[0] = (fConst70 * ((fVec2[0] - fVec2[1]) + (fConst25 * fRec4[1])));
		fRec3[0] = (fRec4[0] - (fConst32 * (((fConst30 * fRec3[1]) + (fConst29 * fRec3[2])) + (fConst27 * fRec3[3]))));
		double fTemp5 = ((iSlow3)?(fConst100 * ((((fConst106 * fRec3[0]) + (fConst105 * fRec3[1])) + (fConst104 * fRec3[2])) + (fConst102 * fRec3[3]))):(fConst100 * ((((fConst99 * fRec3[0]) + (fConst98 * fRec3[1])) + (fConst97 * fRec3[2])) + (fConst96 * fRec3[3]))));
		fVec3[0] = fTemp5;
		fRec2[0] = (fConst70 * ((fVec3[0] - fVec3[1]) + (fConst25 * fRec2[1])));
		fRec1[0] = (fRec2[0] - (((((fRec1[1] * (2.53855057024141e-11 + (fConst1 * ((fRec0[0] * (fConst23 + (fConst22 * fRec0[0]))) + fConst20)))) + (fRec1[2] * (3.80782585536211e-11 + (fConst12 * ((fRec0[0] * (fConst19 + (fConst18 * fRec0[0]))) - 9.91862029097707e-11))))) + (fRec1[3] * (2.53855057024141e-11 + (fConst1 * (fConst16 + (fRec0[0] * (fConst14 + (fConst13 * fRec0[0])))))))) + (fRec1[4] * (6.34637642560352e-12 + (fConst1 * ((fRec0[0] * (fConst10 + (fConst9 * fRec0[0]))) + fConst8))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst12 * ((((((fConst110 * (fRec0[0] * fRec1[0])) + (fConst1 * (fRec1[1] * (0 - (9.25686373387472e-16 * fRec0[0]))))) + (9.39244385518467e-10 * (fRec0[0] * fRec1[2]))) + (fConst109 * (fRec0[0] * fRec1[3]))) + (fConst108 * (fRec0[0] * fRec1[4]))) / fTemp0));
		// post processing
		for (int i=4; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec2[1] = fRec2[0];
		fVec3[1] = fVec3[0];
		for (int i=3; i>0; i--) fRec3[i] = fRec3[i-1];
		fRec4[1] = fRec4[0];
		fVec2[1] = fVec2[0];
		for (int i=4; i>0; i--) fRec6[i] = fRec6[i-1];
		fRec7[1] = fRec7[0];
		fVec1[1] = fVec1[0];
		fRec10[1] = fRec10[0];
		for (int i=5; i>0; i--) fRec8[i] = fRec8[i-1];
		fRec9[1] = fRec9[0];
		fVec0[1] = fVec0[0];
		fRec5[1] = fRec5[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
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
	case EXPANDER: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	// static const value_pair fslider3_values[] = {{"ON"},{"OFF"},{0}};
	case TONE: 
		fslider3_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case TRIM: 
		fslider1_ = (float*)data; // , 0.25, 0.0, 0.49, 0.01 
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
   EXPANDER, 
   TONE, 
   TRIM, 
} PortIndex;
*/

} // end namespace sfp
