!system '"..\assets\pack.bat"'

outfile "ironfist-install.exe"
Name "Project Ironfist"

DirText "Please select a folder that contains a copy of Heroes of Might and Magic II.$\r$\n\
		This folder may (or may not) look like: $\"C:\GOG Games\HoMM 2 Gold$\" or$\r$\n\
		$\"C:\GOG Games\Heroes of Might and Magic 2 GOLD$\" or$\r$\n\
		$\"C:\GOG Games\Heroes of Might and Magic 2 (Win)$\"."

InstallDir "C:\"

Page directory
Page instfiles

Section

	IfFileExists "$INSTDIR\HEROES2W.EXE" game_found win_not_found
	win_not_found:
		IfFileExists "$INSTDIR\HEROES2.EXE" game_found game_not_found
	game_not_found:
		MessageBox MB_OK "Installation Failed: Game not found in selected folder.$\r$\n$\n\
			Please try again and select a folder that contains a copy of Heroes of Might and Magic II."
		Quit
	game_found:

	SetOutPath $SYSDIR

    SetOverwrite off
	File WING32.DLL
	
	SetOverwrite on

	SetOutPath $INSTDIR

	File ..\build\bin\ironfist.exe
	File bass.dll
	File MSS32.DLL
	File SMACKW32.DLL
	File xerces-c_3_1.dll
	File ..\build\bin\editor.exe

	SetOutPath $INSTDIR\DATA
	
	File ..\build\ironfist.agg
	File ..\src\xsd\creatures_xml.xsd
	File ..\data\creatures.xml

	SetOutPath $INSTDIR\GAMES

	File ..\src\xsd\map_xml.xsd
	
	SetOutPath $INSTDIR\MAPS
	
	File ..\maps\Behemoth.MX2
	File ..\maps\SorrowEn.MX2
	File ..\maps\LastStand.MX2

	CreateDirectory "$INSTDIR\SCRIPTS"
	
	SetOutPath $INSTDIR\SCRIPTS
	
	File ..\maps\Behemoth.MX2.lua
	File ..\maps\SorrowEn.MX2.lua
	File ..\maps\LastStand.MX2.lua

	CreateDirectory "$INSTDIR\SCRIPTS\MODULES"
	
	SetOutPath $INSTDIR\SCRIPTS\MODULES
	
	File ..\maps\modules\niftysnippets_1.lua
	File ..\maps\modules\AdvMessageBox.lua
	File ..\maps\modules\binding.lua
	
	SetOutPath $INSTDIR
	WriteUninstaller "$INSTDIR\uninstall-ironfist.exe"

	CreateDirectory "$SMPROGRAMS\Project Ironfist"
	CreateShortCut "$SMPROGRAMS\Project Ironfist\Ironfist.lnk" "$INSTDIR\ironfist.exe"
	CreateShortCut "$SMPROGRAMS\Project Ironfist\Map Editor.lnk" "$INSTDIR\editor.exe"
	CreateShortCut "$SMPROGRAMS\Project Ironfist\Uninstall.lnk" "$INSTDIR\uninstall-ironfist.exe"

SectionEnd

Section "uninstall"

	Delete "$INSTDIR\ironfist.exe"
	Delete "$INSTDIR\editor.exe"

	Delete "$INSTDIR\DATA\ironfist.agg"
	Delete "$INSTDIR\DATA\creatures_xml.xsd"
	Delete "$INSTDIR\DATA\creatures.xml"

	Delete "$INSTDIR\GAMES\map_xml.xsd"

	RMDIR "$INSTDIR\SCRIPTS"

	Delete "$SMPROGRAMS\Project Ironfist\Ironfist.lnk"
	Delete "$SMPROGRAMS\Project Ironfist\Map Editor.lnk"
	Delete "$SMPROGRAMS\Project Ironfist\Uninstall.lnk"
	RMDIR "$SMPROGRAMS\Project Ironfist"

        #Because Vista moves shortcuts to the "All Users" folder
        SetShellVarContext all
	Delete "$SMPROGRAMS\Project Ironfist\Ironfist.lnk"
	Delete "$SMPROGRAMS\Project Ironfist\Map Editor.lnk"
	Delete "$SMPROGRAMS\Project Ironfist\Uninstall.lnk"
	RMDIR "$SMPROGRAMS\Project Ironfist"

SectionEnd