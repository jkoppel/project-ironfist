{
  int result; // eax@2
  int v2; // [sp+0h] [bp-314h]@0
  int xa; // [sp+Ch] [bp-308h]@1
  int v4; // [sp+10h] [bp-304h]@3
  char v5; // [sp+14h] [bp-300h]@3

  xa = x;
  xLastChoice = -1;
  if ( gbNoCDRom )
  {
    result = 0;
  }
  else
  {
    gbInSmackMgr = 1;
    gbPlayedThrough = 0;
    dword_50FED8 = 1;
    memcpy(&v5, gpBufferPalette->contents, 0x300u);
    v4 = gpWindowManager->field_56;
    gpWindowManager->field_56 = 0;
    if ( xa != 67 )
    {
      gpSoundManager->aiMusicOff = 1;
      soundManager::PlayAmbientMusic(gpSoundManager, -1, 0, -1, v2);
    }
    if ( *(_DWORD *)&slowVideo == 3 )
    {
      *(_DWORD *)&slowVideo = 0;
      WritePrefs();
      bSmackNum = 37;
      bTesting = 1;
      SmackManagerMain();
      bTesting = 0;
      if ( (unsigned int)(dword_524EE4 + dword_524ED0) >= 0x7D0 || (unsigned int)dword_524EE8 >= 0x514 || gbLowMemory )
      {
        *(_DWORD *)&slowVideo = 1;
        WritePrefs();
      }
      PrintSummaryInfo((int *)smksum);
    }
    bSmackNum = xa;
    SmackManagerMain();
    memcpy(gpBufferPalette->contents, &v5, 0x300u);
    gpWindowManager->field_56 = v4;
    gbInSmackMgr = 0;
    dword_50FED8 = 0;
    result = gbPlayedThrough;
  }
  return result;
}