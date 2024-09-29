

/*******************************************************************************
**************************** File generated by *********************************
********************************************************************************
 ./build-plug.py -i BlowMePreamp2.sch --buildfaust -n BlowMePreAmpSoft
*******************************************************************************/

// generated automatically
// DO NOT MODIFY!
declare id "blowmepreampsoft";
declare name "BlowMePreAmpSoft";
declare category "Extern";
declare shortname "BlowMePreAmpSoft";
declare description "BlowMePreAmpSoft";

import("stdfaust.lib");


/*******************************************************************************
  * blowmepreamp2 generated by dkbuiler from BlowMePreamp2.sch
*******************************************************************************/

p1 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;


    Input = vslider("Input[name:Input][style:knob]", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(17) : si.smooth(s);

    b0 = Input*fs*(fs*(4.16500005452348e-11*fs + 3.28211194209889e-11) + 6.46594157229885e-12);

    b1 = Input*fs*(fs*(-1.24950001635705e-10*fs - 3.28211194209889e-11) + 6.46594157229885e-12);

    b2 = Input*fs*(fs*(1.24950001635705e-10*fs - 3.28211194209889e-11) - 6.46594157229885e-12);

    b3 = Input*fs*(fs*(-4.16500005452348e-11*fs + 3.28211194209889e-11) - 6.46594157229885e-12);

    a0 = fs*(fs*(9.0417676423871e-15*fs + 2.29305539448686e-14) + 1.86840094799343e-14) + 4.93552052718456e-15;

    a1 = fs*(fs*(-2.71253029271613e-14*fs - 2.29305539448686e-14) + 1.86840094799343e-14) + 1.48065615815537e-14;

    a2 = fs*(fs*(2.71253029271613e-14*fs - 2.29305539448686e-14) - 1.86840094799343e-14) + 1.48065615815537e-14;

    a3 = fs*(fs*(-9.0417676423871e-15*fs + 2.29305539448686e-14) - 1.86840094799343e-14) + 4.93552052718456e-15;
};

process =  p1 ;