# The Blow Me Amplifier

What's makes the sound of commercial guitar amplifiers is their defaults. By defaults, I mean the financial
dictated choices made to be concurential on the market. They includes economies on both circuit topology
and parts quality or rating.

The Blow Me Amplifier is designed from the scratch with a priority: Not to compromize the sound.

The topology of the preamp is very classical. The amp use a single ended class A OTL driver stage build around
an EL84, which deliver enough power in order to drive the 6L6 class AB2 push-pull output stage
(yes, it is in the datasheet, for maximum dynamic output, each G1 of a 6L6 stage
must get 1.5 W in class AB2 or B).

You can also note that the tubes are driven at high voltage and impedance into the preamp. That is to get as little
distortion as possible with the clear sounds. Into the amp, the tubes are pushed at their maximum, especially
the 6L6. This is why it is called the Blow Me Amplifier.

- You have been warned if You want to reproduce it with real hardware.

The capacitors are of relatively high values, that in order to get a good bandwitch in the basses,
that with so little phase shift as possible.

All that makes the Blow Me Amplifier suited not only for guitar, but also for any other use.

## Included plugins
- BlowMePreamplifier.sch: Blow Me Preamplifier schematics. Build with

	./build-plug.py  -i BlowMePreamplifier.sch --buildlv2 -n BlowMePreAmpHard

  will result into a mono LV2 plugin named GxBlowMePreampHard.

  Is is a huge volume difference with the On-Off switch, so it is best used as a mute switch.
  In guitarix, You can use the banks instead of the On-Off switch.
  But it have a so cool sound when GX head is set as explained here:

- BlowMeAmp-orig.sch: Blow Me Amplifier schematics.

 	./build-plug.py  -i BlowMeAmp-orig.sch --buildlv2 -n BlowMeHeadHard

  will build a mono LV2 plugin named GxBlowMeAmpHead.

  To use these 2 LV2 plugins in guitarix, in order to get the best sound out of them,
  start with:
  - let the Blow Me knobs at their middle (0.5);
  - into the GX head, set the general volume and the Drive at their minimum,
    then set the general gain at zero (in the middle) and the pre-gain in order to get
    about the same volume when the Blow Me Head is on or off.

  To build a complete amplifier, run:

	./build-plug.py  -i BlowMePreamplifier.sch BlowMeAmp-orig.sch --buildlv2 -n BlowMeAmpHard

  We can see the default volume is way too loud into other LV2 hosts like jalv.

- BlowMeAmp2.sch: Blow Me Amplifier schematics with a=17 for the log scale of the Volume.

 	./build-plug.py  -i BlowMeAmp2.sch --buildlv2 -n BlowMeHeadSoft

   This make it suitable to use with full General volume and Drive at -9 dB in GX head or with other LV2 host.

- BlowMePreamp2.sch: Blow Me Preamplisfier schematics with a=17 for the log scale of the Volume.

	./build-plug.py  -i BlowMePreamp2.sch --buildlv2 -n BlowMePreAmpSoft

  and for a complete amplifier:

	./build-plug.py  -i BlowMePreamp2.sch BlowMeAmp2.sch --buildlv2 -n BlowMeAmpSoft

  or:

	./build-plug.py  -i BlowMePreamp2.sch BlowMeAmp-orig.sch --buildlv2 -n BlowMeAmp

To get the faust code, replace --buildlv2 by --buildfaust. dkbuilder can generate stereo
plugins too. Look at the output of './build-plug.py -h'.

At full volume, these plugins will all have the same gain. That because the only difference between
Hard and Soft versions is the curve of their potentiometers, which change the scale of the knobs
and their volume at the middle point.

Enjoy,
Dominique
