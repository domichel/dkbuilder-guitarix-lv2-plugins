# dkbuilder guitarix-LV2 plugins

## Place for audio guitarix and LV2 plugins made with dkbuilder

dkbuilder is a toolkit that takes gschem electronic schematics as input and output source code in different formats:
LV2 (native linux audio plugins), guitarix or faust. 
The dkbuilder is part of guitarix source code, see https://linuxmusicians.com/search.php?keywords=dkbuilder for reference on how to install and use it, and https://github.com/brummer10/guitarix for its code.

The LV2 plugins can be used with any LV2 capable host (guitarix, jalv, ardour, ...), the faust code will be best used with XUiDesigner:
https://github.com/brummer10/XUiDesigner

## The plugins are organised into 2 main directories:

- main: for plugins that works as wanted
  1 folder per related plugins, each with 2 directories, buildlv2 and dkbuild.

- wip: for plugins that don't works as expected
  1 folder per related plugins, each with 2 directories, buildlv2 and dkbuild.

## The generated plugins
The guitarix plugins will not work because dkbuilder use python2.7 and guitarix use python 3.
Which imply the buildlv2 folders contain the LV2 plugins and the dkbuild folders contain
only the faust dsp code.

## Build and install the plugins
Navigate the tree and go into a <plugin>/buildlv2 folder and run:
	make
	make install

Enjoy,
Dominique
