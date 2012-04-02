void __thiscall SoundManager::initializeRedbook(SoundManager *this)
{
  SoundManager *thisa; // [sp+Ch] [bp-40h]@1
  struct tagAUXCAPSA pac; // [sp+10h] [bp-3Ch]@11
  unsigned __int32 tracknum; // [sp+40h] [bp-Ch]@6
  int numDevs; // [sp+44h] [bp-8h]@9
  UINT uDeviceID; // [sp+48h] [bp-4h]@9

  thisa = this;
  if ( !soundDisabled )
  {
    this->field_6A6 = 1;
    this->field_69E = 0;
    if ( !dword_4F1CBC )
    {
      if ( !byte_5248D6 )
      {
        if ( !dword_4F1C90 )
        {
          redbook = AIL_redbook_open(0);
          if ( redbook )
          {
            thisa->field_69E = 1;
            thisa->someTick = getTickCount() + 5000;
            numRedbookTrackSlots = AIL_redbook_tracks(redbook) + 2;
            ptr = KBAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 26);
            dword_4ED0B4 = KBAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 27);
            dword_4ED0B8 = KBAlloc(4 * numRedbookTrackSlots + 1, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED168 + 28);
            for ( tracknum = 0; (signed int)tracknum < numRedbookTrackSlots; ++tracknum )
            {
              AIL_redbook_track_info(
                redbook,
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
