{
  int result; // eax@15
  int v1; // [sp+Ch] [bp-4h]@1

  v1 = gbNoSound;
  if ( iCDRomErr == 1 )
  {
    SetPalette(gPalette->contents, 1);
    mouseManager::ShowColorPointer(gpMouseManager);
    gbNoSound = 1;
    if ( giTCPHostStatus )
      NormalDialog(
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
    gbNoCDRom = 1;
  }
  else if ( iCDRomErr == 2 )
  {
    SetPalette(gPalette->contents, 1);
    mouseManager::ShowColorPointer(gpMouseManager);
    gbNoSound = 1;
    if ( giTCPHostStatus )
      NormalDialog(
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
    gbNoCDRom = 1;
  }
  if ( iCDRomErr == 3 )
  {
    EarlyShutdown("Startup Error", "Unable to change to the Heroes II directory.  Please run the installation program.");
    exit(0);
  }
  if ( iCDRomErr == 4 )
  {
    EarlyShutdown("Startup Error", "Unable to find the Heroes II data files.  Please run the installation program.");
    exit(0);
  }
  result = v1;
  gbNoSound = v1;
  return result;
}