outfile "ironfist-install.exe"
Name "Project Ironfist"

installDir "C:\Program Files\GOG.com\Heroes of Might and Magic 2 GOLD"

section

messageBox MB_OK "Installing Ironfist"

setOutPath $INSTDIR

File ironfist.exe
File MSS32.DLL
File SMACKW32.DLL
File xerces-c_3_1.dll
File editor.exe

setOutPath $INSTDIR\DATA

File ironfist.agg
File creatures_xml.xsd
File creatures.xml

setOutPath $INSTDIR\GAMES

File map_xml.xsd

sectionEnd