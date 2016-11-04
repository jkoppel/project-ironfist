{
  int result; // eax@15
  int v1; // [sp+Ch] [bp-4h]@1

  v1 = soundDisabled;
  if ( dword_50CAF0 == 1 )
  {
    someSortOfPaletteSwap(dword_524234->contents, 1);
    MouseManager::enableCursor(mouseManager);
    soundDisabled = 1;
    if ( dword_52340C )
      display_message_window(
        "Unable to access CD-ROM Drive.  Without a CD-ROM drive and a Heroes 2 Expansion CD-ROM you will only be able to play as the guest in a multi-player game.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
    dword_4F1CBC = 1;
  }
  else
  {
    if ( dword_50CAF0 == 2 )
    {
      someSortOfPaletteSwap(dword_524234->contents, 1);
      MouseManager::enableCursor(mouseManager);
      soundDisabled = 1;
      if ( dword_52340C )
        display_message_window(
          "The Heroes 2 Expansion CD-ROM is not in the drive.  Without a Heroes 2 Expansion CD-ROM you will only be able to play as the guest in a multi-player game.  If you have the CD, then exit the program, put the CD in, and try again.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      dword_4F1CBC = 1;
    }
  }
  if ( dword_50CAF0 == 3 )
  {
    sub_42F610("Startup Error", "Unable to change to the Heroes II directory.  Please run the installation program.");
    exit(0);
  }
  if ( dword_50CAF0 == 4 )
  {
    sub_42F610("Startup Error", "Unable to find the Heroes II data files.  Please run the installation program.");
    exit(0);
  }
  result = v1;
  soundDisabled = v1;
  return result;
}
