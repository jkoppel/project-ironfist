{
  soundManager *thisa; // [sp+Ch] [bp-40h]@1
  struct tagAUXCAPSA pac; // [sp+10h] [bp-3Ch]@11
  unsigned __int32 tracknum; // [sp+40h] [bp-Ch]@6
  int numDevs; // [sp+44h] [bp-8h]@9
  UINT uDeviceID; // [sp+48h] [bp-4h]@9

  thisa = this;
  if ( !gbNoSound )
  {
    this->field_6A6 = 1;
    this->field_69E = 0;
    if ( !gbNoCDRom )
    {
      if ( !byte_5248D6 )
      {
        if ( !gbDontTryRedbook )
        {
          aStatusCdPositi = AIL_redbook_open(0);
          if ( aStatusCdPositi )
          {
            thisa->field_69E = 1;
            thisa->someTick = KBTickCount() + 5000;
            numRedbookTrackSlots = AIL_redbook_tracks(aStatusCdPositi) + 2;
            ptr = BaseAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 26);
            dword_4ED0B4 = BaseAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 27);
            dword_4ED0B8 = BaseAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 28);
            for ( tracknum = 0; (signed int)tracknum < numRedbookTrackSlots; ++tracknum )
            {
              AIL_redbook_track_info(
                aStatusCdPositi,
                tracknum,
                (unsigned __int32 *)ptr + tracknum,
                (unsigned __int32 *)dword_4ED0B4 + tracknum);
              *((_DWORD *)dword_4ED0B8 + tracknum) = 0;
            }
            numDevs = auxGetNumDevs();
            thisa->outputDeviceID = -1;
            for ( uDeviceID = 0; numDevs > (signed int)uDeviceID; ++uDeviceID )
            {
              memset(&pac, 0, 0x30u);
              auxGetDevCapsA(uDeviceID, &pac, 0x30u);
              if ( pac.wTechnology == AUXCAPS_CDAUDIO )
              {
                thisa->outputDeviceID = uDeviceID;
                break;
              }
            }
            if ( thisa->outputDeviceID != -1 )
              auxGetVolume(thisa->outputDeviceID, &pdwVolume);
          }
        }
      }
    }
  }
}