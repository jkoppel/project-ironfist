{
  soundManager *thisa; // esi@1
  int v2; // eax@2
  struct _SEQUENCE *v3; // eax@10
  int v4; // eax@15
  resource *v5; // eax@15
  HSEQUENCE *v6; // edi@19
  resource **v7; // esi@23

  thisa = this;
  if ( !gbNoSound )
  {
    v2 = this->usingRedbookRelated;
    if ( v2 )
    {
      if ( !gbNoSound && v2 && CurrentMidiFile != -1 )
      {
        if ( !gbNoSound )
        {
          if ( *(_DWORD *)&Data )
          {
            if ( v2 )
            {
              if ( CurrentMidiFile != -1 )
              {
                v3 = *(&hSequence + CurrentMidiFile);
                if ( v3 )
                {
                  if ( AIL_sequence_status(v3) == 4 )
                  {
                    if ( *(&hSequence + CurrentMidiFile) )
                    {
                      AIL_stop_sequence(*(&hSequence + CurrentMidiFile));
                      if ( gbLowMemory || !*((_BYTE *)&bSaveMusicPosition + CurrentMidiFile) )
                      {
                        AIL_release_sequence_handle(*(&hSequence + CurrentMidiFile));
                        v4 = CurrentMidiFile;
                        *(HSEQUENCE *)((char *)&hSequence + v4 * 4) = 0;
                        v5 = (resource *)pMIDIWrap[v4];
                        if ( v5 )
                          resourceManager::Dispose(gpResourceManager, v5);
                        pMIDIWrap[CurrentMidiFile] = 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        CurrentMidiFile = -1;
        thisa->currentTrack = -1;
      }
      v6 = &hSequence;
      LogStr("MS1");
      do
      {
        if ( *v6 )
          AIL_release_sequence_handle(*v6);
        *v6 = 0;
        ++v6;
      }
      while ( (unsigned int)v6 < (unsigned int)lastPositionZ );
      LogStr("MS2");
      AIL_midiOutClose(hMDI);
      hMDI = 0;
      thisa->usingRedbookRelated = 0;
      v7 = (resource **)pMIDIWrap;
      do
      {
        if ( *v7 )
          resourceManager::Dispose(gpResourceManager, *v7);
        *v7 = 0;
        ++v7;
      }
      while ( (unsigned int)v7 < (unsigned int)&hSequence );
      LogStr("MS4");
    }
  }
}