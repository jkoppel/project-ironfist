This script replaces internally animated colors from HOMM2 bmp image to similarly looking static colors
Place .scm file into GIMPfolder\share\gimp\2.0\scripts
Steps:
1. open bmp with GIMP
2. Script-fu -> Ironfist -> Ironfist decycle colors
3 (ONCE). Export as -> *.bmp. During export select "Do not save color profile info"
4. You can now use "Overwrite %currentfile%.bmp" instead of 3. until you close gimp