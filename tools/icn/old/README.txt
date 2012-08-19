   ****************************  Overview *******************************

Converts a directory full of images to a Heroes II sprite archive (ICN) file.

It is less efficient than the one used by the original developers. Converting an ICN to PNGs and converting back using this tool will typically result in a substantial blowup.

All images placed into the sprite archive should have the same dimensions. In particular, the walk animations of creatures should show them moving forwards.

It will give an error if the directory contains any non-image files. Mac users should beware of the hidden ".DS_STORE" file created in every directory.


   ****************************   Usage   *******************************

To compile:

    $javac ICNWriter.java

To use:

   $java ICNWriter directory [palette=KB.PAL] [background=00000000]

with

directory: The directory containing the images to be placed into the sprite archive. Images will be placed in the order given by the file system, usually alphabetical order.

palette: The palette file to use. This defaults to KB.PAL, the standard Heroes II palette. Any colors not in the palette will be mapped to the closest (least-squares) color in the palette.

background: The ARGB color to be treated as the background color, and rendered as transparent. It defaults to 00000000, perfectly transparent black. (Perfectly opaque black would be FF000000 .)
