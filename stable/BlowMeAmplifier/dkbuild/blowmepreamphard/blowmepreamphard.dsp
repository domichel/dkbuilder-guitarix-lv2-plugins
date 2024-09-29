

/*******************************************************************************
**************************** File generated by *********************************
********************************************************************************
 ./build-plug.py -i BlowMePreamplifier.sch --buildfaust -n BlowMePreAmpHard
*******************************************************************************/

// generated automatically
// DO NOT MODIFY!
declare id "blowmepreamphard";
declare name "BlowMePreAmpHard";
declare category "Extern";
declare shortname "BlowMePreAmpHard";
declare description "BlowMePreAmpHard";

import("stdfaust.lib");


/*******************************************************************************
  * blowmepreamplifier generated by dkbuiler from BlowMePreamplifier.sch
*******************************************************************************/

p1 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;


    Input = vslider("Input[name:Input][style:knob]", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);

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
