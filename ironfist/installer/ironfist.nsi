outfile "ironfist-install.exe"
Name "Project Ironfist"

installDir "$PROGRAMFILES\GOG.com\Heroes of Might and Magic 2 GOLD"

Page directory
Page instfiles

section

	setOutPath $SYSDIR

        SetOverwrite off
	File msvcr100.dll
	File msvcr100d.dll
	File msvcp100.dll
	File msvcp100d.dll
	File WING32.DLL
	
	SetOverwrite on

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
	
	setOutPath $INSTDIR\MAPS
	
	File SorrowEn.MX2

	CreateDirectory "$INSTDIR\SCRIPTS"
	
	setOutPath $INSTDIR\SCRIPTS
	
	File SorrowEn.MX2.lua


	setOutPath $INSTDIR
	writeUninstaller "$INSTDIR\uninstall-ironfist.exe"

	CreateDirectory "$SMPROGRAMS\Project Ironfist"
	createShortCut "$SMPROGRAMS\Project Ironfist\Ironfist.lnk" "$INSTDIR\ironfist.exe"
	createShortCut "$SMPROGRAMS\Project Ironfist\Map Editor.lnk" "$INSTDIR\editor.exe"
	createShortCut "$SMPROGRAMS\Project Ironfist\Uninstall.lnk" "$INSTDIR\uninstall-ironfist.exe"

sectionEnd

section "uninstall"

	delete "$INSTDIR\ironfist.exe"
	delete "$INSTDIR\xerces-c_3_1.dll"
	delete "$INSTDIR\editor.exe"

	delete "$INSTDIR\DATA\ironfist.agg"
	delete "$INSTDIR\DATA\creatures_xml.xsd"
	delete "$INSTDIR\DATA\creatures.xml"

	delete "$INSTDIR\GAMES\map_xml.xsd"

	RMDIR "$INSTDIR\SCRIPTS"

	delete "$SMPROGRAMS\Project Ironfist\Ironfist.lnk"
	delete "$SMPROGRAMS\Project Ironfist\Map Editor.lnk"
	delete "$SMPROGRAMS\Project Ironfist\Uninstall.lnk"
	RMDIR "$SMPROGRAMS\Project Ironfist"

        #Because Vista moves shortcuts to the "All Users" folder
        SetShellVarContext all
	delete "$SMPROGRAMS\Project Ironfist\Ironfist.lnk"
	delete "$SMPROGRAMS\Project Ironfist\Map Editor.lnk"
	delete "$SMPROGRAMS\Project Ironfist\Uninstall.lnk"
	RMDIR "$SMPROGRAMS\Project Ironfist"

sectionEnd