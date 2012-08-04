{
  HDIGDRIVER result; // eax@2
  char *v5; // eax@12
  __int16 bitsPerSamplea; // [sp+Ch] [bp-E0h]@1
  DWORD samplesPerSecb; // [sp+10h] [bp-DCh]@1
  struct tagWAVEOUTCAPSA pwoc; // [sp+20h] [bp-CCh]@3
  HDIGDRIVER drvr; // [sp+54h] [bp-98h]@2
  struct _OSVERSIONINFOA samplesPerSeca; // [sp+58h] [bp-94h]@5

  bitsPerSamplea = bitsPerSample;
  samplesPerSecb = samplesPerSec;
  if ( waveOutGetNumDevs() )
  {
    if ( waveOutGetDevCapsA(0, &pwoc, 0x34u) )
    {
      MessageBoxA(hwndApp, "Sound initialization error!  No wave devices found.", "Startup Error", 0);
      drvr = 0;
      result = 0;
    }
    else
    {
      memset(&samplesPerSeca, 0, 0x94u);
      samplesPerSeca.dwOSVersionInfoSize = 148;
      if ( GetVersionExA(&samplesPerSeca) && samplesPerSeca.dwPlatformId == VER_PLATFORM_WIN32_NT )
        gbUseWaveout = 1;
      if ( gbUseWaveout )
        AIL_set_preference(0xFu, 1);
      Format.wFormatTag = 1;
      Format.nChannels = nChannels;
      Format.nSamplesPerSec = samplesPerSecb;
      Format.nAvgBytesPerSec = samplesPerSecb * nChannels * ((unsigned int)(unsigned __int16)bitsPerSamplea >> 3);
      Format.nBlockAlign = nChannels * ((unsigned __int16)bitsPerSamplea >> 3);
      word_522B2E = bitsPerSamplea;
      if ( AIL_waveOutOpen(&drvr, 0, 0, &Format) )
      {
        if ( a4 )
        {
          v5 = AIL_last_error();
          MessageBoxA(hwndApp, v5, "Sound initialization error!", 0);
        }
        drvr = 0;
        result = 0;
      }
      else
      {
        result = drvr;
      }
    }
  }
  else
  {
    drvr = 0;
    result = 0;
  }
  return result;
}