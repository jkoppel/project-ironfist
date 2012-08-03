{
  signed int result; // eax@1
  int v2; // esi@1
  struct _SEQUENCE *v3; // eax@8
  int v4; // eax@13
  resource *v5; // eax@13

  result = gbNoSound;
  v2 = this;
  if ( !gbNoSound )
  {
    result = *(_DWORD *)(this + 1698);
    if ( result )
    {
      if ( CurrentMidiFile != -1 )
      {
        if ( !gbNoSound )
        {
          if ( *(_DWORD *)&Data )
          {
            if ( result )
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
        result = -1;
        CurrentMidiFile = -1;
        *(_BYTE *)(v2 + 1404) = -1;
      }
    }
  }
  return result;
}