// generated from file '../dkbuild/blowmeamp//blowmeamp.dsp' by dsp2cc:
// Code generated with Faust 2.14.4 (https://faust.grame.fr)


namespace blowmeamp {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec0[2];
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec2[2];
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fRec3[4];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fRec1[4];
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;

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
	id = "blowmeamp";
	name = N_("BlowMeAmp");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec2[l1] = 0.0;
	for (int l2 = 0; (l2 < 4); l2 = (l2 + 1)) fRec3[l2] = 0.0;
	for (int l3 = 0; (l3 < 4); l3 = (l3 + 1)) fRec1[l3] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (9.0415808936678399e-15 * fConst0);
	fConst2 = (((((fConst1 + 3.1894748319300098e-14) * fConst0) + 6.4032700265985e-15) * fConst0) + 1.08070027945494e-15);
	fConst3 = (mydsp_faustpower2_f(fConst0) / fConst2);
	fConst4 = (5.1704766006230502e-14 * fConst0);
	fConst5 = (-5.3414014469246803e-15 - fConst4);
	fConst6 = (9.0417676423871e-15 * fConst0);
	fConst7 = (((((fConst6 + 2.2930553944868601e-14) * fConst0) + 1.86840094799343e-14) * fConst0) + 4.9355205271845602e-15);
	fConst8 = (fConst0 / fConst7);
	fConst9 = (4.1650000545234801e-11 * fConst0);
	fConst10 = (((fConst9 + 3.2821119420988903e-11) * fConst0) + 6.4659415722988501e-12);
	fConst11 = (1.0 / fConst7);
	fConst12 = (2.7125302927161299e-14 * fConst0);
	fConst13 = (((((-2.2930553944868601e-14 - fConst12) * fConst0) + 1.86840094799343e-14) * fConst0) + 1.4806561581553699e-14);
	fConst14 = (((((fConst12 + -2.2930553944868601e-14) * fConst0) + -1.86840094799343e-14) * fConst0) + 1.4806561581553699e-14);
	fConst15 = (((((2.2930553944868601e-14 - fConst6) * fConst0) + -1.86840094799343e-14) * fConst0) + 4.9355205271845602e-15);
	fConst16 = (1.2495000163570501e-10 * fConst0);
	fConst17 = (((-3.2821119420988903e-11 - fConst16) * fConst0) + 6.4659415722988501e-12);
	fConst18 = (((fConst16 + -3.2821119420988903e-11) * fConst0) + -6.4659415722988501e-12);
	fConst19 = (((3.2821119420988903e-11 - fConst9) * fConst0) + -6.4659415722988501e-12);
	fConst20 = (1.0 / fConst2);
	fConst21 = (2.7124742681003501e-14 * fConst0);
	fConst22 = (((((-3.1894748319300098e-14 - fConst21) * fConst0) + 6.4032700265985e-15) * fConst0) + 3.2421008383648201e-15);
	fConst23 = (((((fConst21 + -3.1894748319300098e-14) * fConst0) + -6.4032700265985e-15) * fConst0) + 3.2421008383648201e-15);
	fConst24 = (((((3.1894748319300098e-14 - fConst1) * fConst0) + -6.4032700265985e-15) * fConst0) + 1.08070027945494e-15);
	fConst25 = (1.5511429801869199e-13 * fConst0);
	fConst26 = (fConst25 + 5.3414014469246803e-15);
	fConst27 = (5.3414014469246803e-15 - fConst25);
	fConst28 = (fConst4 + -5.3414014469246803e-15);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
	double fSlow0 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider0))) + -1.0));
	double fSlow1 = (2.8979565231232145e-10 * (std::exp((17.0 * double(fVslider1))) + -1.0));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (fSlow0 + (0.99299999999999999 * fRec0[1]));
		fRec2[0] = (fSlow1 + (0.99299999999999999 * fRec2[1]));
		fRec3[0] = (double(input0[i]) - (fConst11 * (((fConst13 * fRec3[1]) + (fConst14 * fRec3[2])) + (fConst15 * fRec3[3]))));
		fRec1[0] = ((fConst8 * (fRec2[0] * ((((fConst10 * fRec3[0]) + (fConst17 * fRec3[1])) + (fConst18 * fRec3[2])) + (fConst19 * fRec3[3])))) - (fConst20 * (((fConst22 * fRec1[1]) + (fConst23 * fRec1[2])) + (fConst24 * fRec1[3]))));
		output0[i] = FAUSTFLOAT((fConst3 * (fRec0[0] * ((((fConst5 * fRec1[0]) + (fConst26 * fRec1[1])) + (fConst27 * fRec1[2])) + (fConst28 * fRec1[3])))));
		fRec0[1] = fRec0[0];
		fRec2[1] = fRec2[0];
		for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
			fRec3[j0] = fRec3[(j0 - 1)];
		}
		for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
			fRec1[j1] = fRec1[(j1 - 1)];
		}
	}
#undef fVslider0
#undef fVslider1
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case INPUT: 
		fVslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MASTER: 
		fVslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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
   INPUT, 
   MASTER, 
} PortIndex;
*/

} // end namespace blowmeamp
