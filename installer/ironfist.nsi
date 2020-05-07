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
	File MSS32.DLL
	File SMACKW32.DLL
	File xerces-c_3_1.dll
	FILE bass.dll
	File ..\build\bin\editor.exe

	SetOutPath $INSTDIR\DATA
	
	File ..\build\ironfist.agg
	File ..\src\xsd\creatures_xml.xsd
	File ..\data\creatures.xml
	File ..\src\xsd\artifacts_xml.xsd
	File ..\data\artifacts.xml

	SetOutPath $INSTDIR\MAPS
	
	File ..\maps\SorrowEn.MX2
	File ..\maps\LastStan.MX2
	File ..\maps\Behemoth.MX2
	File ..\maps\CAMP5_01.HXC
	File ..\maps\CAMP5_02.HXC
	File ..\maps\CAMP5_03.HXC
	File ..\maps\CAMP5_04.HXC
	File ..\maps\CAMP5_05.HXC
	File ..\maps\CAMP5_06.HXC

	CreateDirectory "$INSTDIR\SCRIPTS"
	
	SetOutPath $INSTDIR\SCRIPTS
	
	File ..\maps\SorrowEn.MX2.lua
	File ..\maps\LastStan.MX2.lua
	File ..\maps\Behemoth.MX2.lua
	File ..\maps\CAMP5_01.HXC.lua
	File ..\maps\CAMP5_02.HXC.lua

	CreateDirectory "$INSTDIR\SCRIPTS\MODULES"
	
	SetOutPath $INSTDIR\SCRIPTS\MODULES
	
	File ..\maps\modules\niftysnippets_1.lua
	File ..\maps\modules\AdvMessageBox.lua
	File ..\maps\modules\binding.lua
	
	CreateDirectory "$INSTDIR\SCRIPTS\GENERIC"
	
	SetOutPath $INSTDIR\SCRIPTS\GENERIC
	
	File ..\maps\generic\artifacts.lua
	
	SetOutPath $INSTDIR\CAMPAIGNS
	
	File ..\cmp\cyborg.cmp
	
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
	Delete "$INSTDIR\DATA\artifacts_xml.xsd"
	Delete "$INSTDIR\DATA\artifacts.xml"

	Delete "$INSTDIR\MAPS\SorrowEn.MX2"
	Delete "$INSTDIR\MAPS\LastStan.MX2"
	Delete "$INSTDIR\MAPS\Behemoth.MX2"
	Delete "$INSTDIR\MAPS\CAMP5_01.HXC"
	Delete "$INSTDIR\MAPS\CAMP5_02.HXC"
	Delete "$INSTDIR\MAPS\CAMP5_03.HXC"
	Delete "$INSTDIR\MAPS\CAMP5_04.HXC"
	Delete "$INSTDIR\MAPS\CAMP5_05.HXC"
	Delete "$INSTDIR\MAPS\CAMP5_06.HXC"
	
	Delete "$INSTDIR\SCRIPTS\GENERIC\artifacts.lua"
	Delete "$INSTDIR\SCRIPTS\SorrowEn.MX2.lua"
	Delete "$INSTDIR\SCRIPTS\LastStan.MX2.lua"
	Delete "$INSTDIR\SCRIPTS\Behemoth.MX2.lua"
	Delete "$INSTDIR\SCRIPTS\CAMP5_01.HXC.lua"
	Delete "$INSTDIR\SCRIPTS\CAMP5_02.HXC.lua"
	
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
	
	Delete "$INSTDIR\uninstall-ironfist.exe"

SectionEnd
