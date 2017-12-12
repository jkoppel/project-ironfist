@echo off 
pushd %~dp0
for /d %%i in (agg/*.cadres) do call "../tools/dist/icn/H2IcnPack_nodialog.exe" agg/%%i
for /r %%i in (agg/*.bin.ini) do call "../tools/dist/frm/H2FRMPack_nodialog.exe" "%~dp0agg\%%~ni.ini"
if not exist "ironfist" mkdir ironfist
move /y agg\*.icn ironfist
move /y agg\*FRM.bin ironfist
copy /y agg\*.bin ironfist
copy /y agg\*.bmp ironfist
copy /y agg\*.82M ironfist
..\tools\dist\agg\H2AggPack_nodialog.exe ..\build\ironfist.agg ironfist
RD /S /Q ironfist
popd