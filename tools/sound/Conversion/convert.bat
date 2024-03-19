@echo off
setlocal enabledelayedexpansion

:drag_drop
if [%1]==[] goto :end

REM Capture the dropped file path
set "input_file=%~f1"
set "output_directory=converted"

REM Create an output directory if it doesn't exist
if not exist "%output_directory%" mkdir "%output_directory%"

REM Get the file name without extension
for %%I in ("%input_file%") do (
    set "output_file=%output_directory%\%%~nI.64"
)

REM Perform the conversion using ffmpeg (assuming ffmpeg is available)
ffmpeg -i "%input_file%" -f u16le -c:a pcm_u16le -ar 44100 -ac 2 "%output_file%"

if not errorlevel 1 (
    echo Conversion complete for: %input_file%
) else (
    echo Error converting: %input_file%
)

shift
goto :drag_drop

:end
echo Batch conversion complete.
pause