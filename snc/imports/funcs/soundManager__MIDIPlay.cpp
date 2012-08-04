{
  soundManager *thisa; // esi@1
  signed int seqIdx; // ebx@4
  int v4; // eax@8
  struct _SEQUENCE *v5; // eax@14
  int v6; // eax@19
  resource *v7; // eax@19
  int v8; // eax@25
  struct _SEQUENCE *v9; // eax@31
  int v10; // eax@36
  resource *v11; // eax@36
  struct _SEQUENCE *v12; // eax@41
  MIDIWrap *seq; // eax@43
  struct _SEQUENCE *v14; // edx@43
  signed int v15; // eax@46
  signed int v16; // ecx@46
  signed int v17; // eax@48
  signed int v18; // ecx@48
  signed __int32 volume; // eax@51
  char buf[1]; // [sp+Ch] [bp-10h]@40

  thisa = this;
  if ( gbNoSound || !this->usingRedbookRelated || !*(_DWORD *)&Data )
    return;
  LogStr("MP1a");
  seqIdx = track;
  if ( !bGotMidi[track] )
    seqIdx = -1;
  if ( seqIdx == -1 )
  {
    if ( !gbNoSound )
    {
      v4 = thisa->usingRedbookRelated;
      if ( v4 )
      {
        if ( CurrentMidiFile != -1 )
        {
          if ( !gbNoSound )
          {
            if ( *(_DWORD *)&Data )
            {
              if ( v4 )
              {
                if ( CurrentMidiFile != -1 )
                {
                  v5 = *(&hSequence + CurrentMidiFile);
                  if ( v5 )
                  {
                    if ( AIL_sequence_status(v5) == 4 )
                    {
                      if ( *(&hSequence + CurrentMidiFile) )
                      {
                        AIL_stop_sequence(*(&hSequence + CurrentMidiFile));
                        if ( gbLowMemory || !*((_BYTE *)&bSaveMusicPosition + CurrentMidiFile) )
                        {
                          AIL_release_sequence_handle(*(&hSequence + CurrentMidiFile));
                          v6 = CurrentMidiFile;
                          *(HSEQUENCE *)((char *)&hSequence + v6 * 4) = 0;
                          v7 = (resource *)pMIDIWrap[v6];
                          if ( v7 )
                            resourceManager::Dispose(gpResourceManager, v7);
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
      }
    }
    return;
  }
  if ( CurrentMidiFile == seqIdx )
    return;
  if ( !gbNoSound )
  {
    v8 = thisa->usingRedbookRelated;
    if ( v8 )
    {
      if ( CurrentMidiFile != -1 )
      {
        if ( !gbNoSound )
        {
          if ( *(_DWORD *)&Data )
          {
            if ( v8 )
            {
              if ( CurrentMidiFile != -1 )
              {
                v9 = *(&hSequence + CurrentMidiFile);
                if ( v9 )
                {
                  if ( AIL_sequence_status(v9) == 4 )
                  {
                    if ( *(&hSequence + CurrentMidiFile) )
                    {
                      AIL_stop_sequence(*(&hSequence + CurrentMidiFile));
                      if ( gbLowMemory || !*((_BYTE *)&bSaveMusicPosition + CurrentMidiFile) )
                      {
                        AIL_release_sequence_handle(*(&hSequence + CurrentMidiFile));
                        v10 = CurrentMidiFile;
                        *(HSEQUENCE *)((char *)&hSequence + v10 * 4) = 0;
                        v11 = (resource *)pMIDIWrap[v10];
                        if ( v11 )
                          resourceManager::Dispose(gpResourceManager, v11);
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
    }
  }
  sprintf(buf, "MIDI%04d.XMI", seqIdx);
  if ( *(&hSequence + seqIdx) )
  {
    AIL_resume_sequence(*(&hSequence + seqIdx));
LABEL_56:
    CurrentMidiFile = seqIdx;
    thisa->currentTrack = seqIdx;
    return;
  }
  v12 = AIL_allocate_sequence_handle(hMDI);
  *(&hSequence + seqIdx) = v12;
  if ( !v12 )
    soundManager::MIDIShutdown(thisa);
  seq = resourceManager::GetMIDIWrap(gpResourceManager, buf);
  v14 = *(&hSequence + seqIdx);
  pMIDIWrap[seqIdx] = seq;
  if ( AIL_init_sequence(v14, seq->contents, 0) )
  {
    if ( !gbNoSound && thisa->usingRedbookRelated )
    {
      v15 = 127;
      v16 = thisa->volRelated;
      if ( v16 > 0 )
      {
        if ( v16 > 10 )
        {
          v17 = 127 * (v16 - 10);
          v18 = 6;
        }
        else
        {
          v17 = 127 * (11 - v16);
          v18 = 11;
        }
        v15 = v17 / v18;
      }
      volume = soundManager::ConvertVolume(v15, 101);
      AIL_set_XMIDI_master_volume(hMDI, volume);
    }
    AIL_start_sequence(*(&hSequence + seqIdx));
    if ( bMusicIsLooping[seqIdx] )
      AIL_set_sequence_loop_count(*(&hSequence + seqIdx), 0);
    else
      AIL_set_sequence_loop_count(*(&hSequence + seqIdx), 1);
    goto LABEL_56;
  }
}