// generated from file '../dkbuild/blowmeheadhard//blowmeheadhard.dsp' by dsp2cc:
// Code generated with Faust 2.14.4 (https://faust.grame.fr)


namespace blowmeheadhard {

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
	double fConst9;
	double fConst10;
	double fRec1[4];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;

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
	id = "blowmeheadhard";
	name = N_("BlowMeHeadHard");
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
	for (int l1 = 0; (l1 < 4); l1 = (l1 + 1)) fRec1[l1] = 0.0;
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
	fConst6 = (1.0 / fConst2);
	fConst7 = (2.7124742681003501e-14 * fConst0);
	fConst8 = (((((-3.1894748319300098e-14 - fConst7) * fConst0) + 6.4032700265985e-15) * fConst0) + 3.2421008383648201e-15);
	fConst9 = (((((fConst7 + -3.1894748319300098e-14) * fConst0) + -6.4032700265985e-15) * fConst0) + 3.2421008383648201e-15);
	fConst10 = (((((3.1894748319300098e-14 - fConst1) * fConst0) + -6.4032700265985e-15) * fConst0) + 1.08070027945494e-15);
	fConst11 = (1.5511429801869199e-13 * fConst0);
	fConst12 = (fConst11 + 5.3414014469246803e-15);
	fConst13 = (5.3414014469246803e-15 - fConst11);
	fConst14 = (fConst4 + -5.3414014469246803e-15);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
	double fSlow0 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider0))) + -1.0));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (fSlow0 + (0.99299999999999999 * fRec0[1]));
		fRec1[0] = (double(input0[i]) - (fConst6 * (((fConst8 * fRec1[1]) + (fConst9 * fRec1[2])) + (fConst10 * fRec1[3]))));
		output0[i] = FAUSTFLOAT((fConst3 * (fRec0[0] * ((((fConst5 * fRec1[0]) + (fConst12 * fRec1[1])) + (fConst13 * fRec1[2])) + (fConst14 * fRec1[3])))));
		fRec0[1] = fRec0[0];
		for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
			fRec1[j0] = fRec1[(j0 - 1)];
		}
	}
#undef fVslider0
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
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
   MASTER, 
} PortIndex;
*/

} // end namespace blowmeheadhard
