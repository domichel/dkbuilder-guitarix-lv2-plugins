# Some notes on dkbuilder from the linuxmusician forum thread
The I pronums are the brummer10 Herman talks. These notes are by no mean exhaustive of the content of the forum thread
on LinuxMusicians.

- In the BajaTubeDriver example, a table is used for the active part of the circuit.
- The LV2 plugins compiled and installed as an user will go into ~/.lv2.

## Build optimization
You could also go to /guitarix-git/trunk/tools/build-faust and reduce the optimization level
Currently it use -O3, but -O2 will be good as well.

## Multiples non linear tables (per plugin)
I've just pushed a update to the dkbuilder, which allow now to build multiple nonlinear tables (per plugin) and gives some control
over the generator options, true, otherwise, the automated conditions will be used.
Just found it nice for the case were multiple parts in a circuit creates nonlinear responses, found it helps a lot for dynamic responses.

## rename package
See the discussion on the linux musicians dkbuilder thread.

## Error handling
I've implemented basic error handling now, so that we get a hint if something fail.

## Models
See circ.py

## Variable resistor
• logarithmic controller: ,a=3
• lower value = lower order
For the VoxWah I found orders between 2 - 6 suitable, depends on were you like to have the sweep point.
See model.py and mk_netlist.px:
   val = 2 * value
   v = 1 / val
   R1coeff = a / (2 - a)
   R2coeff = (1 - a) / (1 + a)
• inverted: ,inv=1
in the value field. Together with the logarithmic scale, this gives you a width range of how the controller react on movements.

## Diodes, transtors and tubes models
Talking about Diodes, I've modified the Model a bit by adding a value field for the Emission coefficient. (The old definition dict still works as well) This makes it easier to use the values given on Data sheets, when you would simulate a special Diode model. Also I've added a couple of Diode models to circ.py, which allow now to use them by just enter the name of the model in the value field, instead fill in all the values.
I've done the same for transistors.
The same is true for tubes.
You could check which models been supported on top of the file circ.py
New models could as well easily be added there.
So for newly created schematics, it will be much easier to use different versions of those Components.

The tube's been based on the Koran model, yes. Diodes and transistors using nodal DK method based on the Master Thesis of Jaromír Mačák.
The Thesis is here: https://www.vutbr.cz/www_base/zav_prace_soubor_verejne.php?file_id=60090

here is a other Thesis related to the DK method:
https://www.researchgate.net/profile/Piero_Rivera_Benois/publication/263013830_Simulation_Framework_for_Analog_Audio_Circuits_based_on_Nodal_DK_Method/links/00b4953996520b377a000000/Simulation-Framework-for-Analog-Audio-Circuits-based-on-Nodal-DK-Method.pdf

Modeling and Simulation of the Power Amplifier of the RHIC (not related to the dkbuilder):
https://www.bnl.gov/isd/documents/79916.pdf

## table option
The --table n option is used to indicate the part of the circuit which introduce the non linear response.
If a linear circuit is build (like a EQ or a tonestack, or even a wah), no table is needed, so no --table n option needs to be given.
If more then one part introduce non-linearity, multiple tables could be build by using --table 1 2 3 . . .

Otherwise, you could build any circuit as linear plugin, usually that is what I'm doing first.
In later runs, I start to experimenting with the tables.
They are produced by sending a numpy array (0-1.4 in 200 steps) to the circuit and measure the response.

It  is better to split circuits into pieces, so for example the BigMuffPi and the SuperFuzz could be splitted into 3 parts,
input buffer, clipper, and output buffer, then tables could be created for the clipper. 

## Faust source code
For a VCA, I (me, not Hermann, the answers are Hermann's) can transform it into a preamp and control its gain with a potentiometer.
That way, it would have only 1 input and 1 output.
It must also be possible to make some kind of detection of the audio signal and use it to control the gain.
That way we could have some kind of log or antilog amplifier. 

- A variable resistor could easily replaced by a audio input in faust source, using abs, reduce and min(max)
to get a usable control via audio input. 
So, sometimes it is required to do some hand work on the faust sources to reach a special goal.
The dkbuilder could create some filters, which you may stick together later by your own.
This way you could as well process circuit parts in parallel, implement a selector (switch) and more. 

VCA: https://pastebin.com/3ZcvUpAX
- the In/Output miss the refdes field, you schould paste the ones from the Startset.sch.
R4 should be P4 (P = variable resistor, 3 connection) and miss some values (value=500k,var=Trim,a=3),
but even then, nothing comes out of the simulation. 

Better version: https://pastebin.com/ny0xXfeV
Happy version: https://pastebin.com/4kZN6r93
Fixed gain version: https://pastebin.com/72CKxpFh
EL84VCA: https://pastebin.com/uGvZ0TYu

## Transformer model
The parameters for the transformer model look like this: w1=1000,w2=1000,w3=64,R=358
OK, w1, w2 and w3 are the number of turns of the windings, but what is the R please?

R is the magnetic reluctance.
Description of the modelling is here: https://www.vutbr.cz/www_base/zav_prace_soubor_verejne.php?file_id=60090
part 3.1.1 

Here you'll find some nice schematics for speaker simulations:
http://www.hexeguitar.com/diy/techinfo/cabsims
Real-Time Audio Transformer Emulation for Virtual Tube Amplifiers:
https://www.researchgate.net/publication/220057543_Real-Time_Audio_Transformer_Emulation_for_Virtual_Tube_Amplifiers

## Volume in jack
That depend on your taste. I, for example, love it loud. Using a amplifier to amplify the incoming signal.
My setting is that I can't hear my guitar, when connected via jack to output, without amplification.
But, indeed, in the digital domain you wont clip in the DAC, so often the Volume needs to be reduced after saturation in the simulation.
I tent to add a active volume control after the transformer before the cabinet simulation, so I could saturate the tubes,
and if it gets to loud, reduce the volume, and, if I prefer a clean tone (sometimes) I could reduce the incoming signal
and recover the volume afterwards, so the I get the level I need.

## Blow Me Amplifier and more on tables
I /me)made 2 simulations. The first one is a simple 2 stages preamp, the BlowMePreamplifier:
https://pastebin.com/Mrj7uWPX
and the BlowMeAmp:
https://pastebin.com/hSYgmW0b

./build-plug.py -i BlowMeAmplifier.sch --table 1 --sig_max 20 --build -n BlowMeAmplifier_t1_20V

it make a table starting at 0V and ending at 20V. If I run the same command with "--sig_max -20", the table start at -20V and stop at 0V.
This show the amp is not symmetrical in its response to saturation, which is due to the driver stage.
It would be nice to be able to make tables using 2 parameters, a sig_max and a sig_min.

pyplot does always plot from low to high, hence the table start at -20.
The logic I've implemented for interpolate the table was only good for positive signals.
I guess that is a big part of the difference you've seen. (He's right on that, because a single ended class A OTL driver
is very symetrical in nature.)
I've now pushed a new version to git, introduce two new options,
-g N or --table_neg N = build negative nonlinear response table from the N\'t circuit
and
-S or --scip_div = skip the divider for the negative nonlinear response table

the divider is used to translate the table into the digital domain (0 <-> 1) , default is, that the divider calculated for the positive sig,
get used for the negative sig as well, you could skip that and a new divider will be calculated for the negative table.

--table_neg N were N is the number of the schematic you'll generate a negative table for. You could generate multiple as before with --table 1 2 3 . .
but, when a negative table is generated, a positive will be generated (and used) as well.

## Stereo
I've added now a option ( -2 or --stereo) to generate a stereo plug version of the circuit.
Still the circuit itself could only be mono, but running two instances in parallel.
Works for LV2 as for gx plugins.

## BaJaTubeDriver
I've released now the example I use here in the first post, the BaJaTubeDriver.
This one use the newly introduced async table generator.
Additional it use a frequency splitter to emulate the difference in the frequency response of the tubes.
As before it is extreme lightweight in CPU usage. Using it in combo with the UltraCab, and enjoy the sweet smooth extra harmonics.
source code is here:
https://github.com/brummer10/GxBaJaTubeDriver.lv2
regards hermann
For the picture, search the forum thread.

## Faust
Work is going on, latest state is, allow to build plain faust code (no foreign function needed) from non-linear circuits.
This will allow to use the generated faust code in the online compiler to generate a binary of your choice,
or, use it with mephisto.lv2, to use it directly within your LV2 host of choice.
