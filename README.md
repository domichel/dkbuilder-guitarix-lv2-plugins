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
Install the dependencies: lv2, cairo, libX11 (+xorg-proto on gentoo).
Navigate the tree and go into a <plugin>/buildlv2 folder and run:

	make
 	make install

When run as user, 'make install' will install the plugin in $HOME/.lv2, which is fine.
You may have to add that PATH into LV2_PATH with

	export LV2_PATH="${HOME}/.lv2:${LV2_PATH}"

into your .bashrc file or similar.

When run as root, it will install into /usr/lib/lv2, which is infortunate beacause that path is
system dependent. Many modern ystem use /usr/lib64/lv2. Which imply you may have to change
that path into the Makefile file before the install run.

Or even better because it will let You redesign the plugins and other goodies,
You may use the faust code with XUiDesigner.

Enjoy,
Dominique
