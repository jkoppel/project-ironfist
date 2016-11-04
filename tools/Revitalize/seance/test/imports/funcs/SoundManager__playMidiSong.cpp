{
  SoundManager *thisa; // esi@1
  signed int seqIdx; // ebx@4
  int v4; // eax@8
  struct _SEQUENCE *v5; // eax@14
  int v6; // eax@19
  AbstractResource *v7; // eax@19
  int v8; // eax@25
  struct _SEQUENCE *v9; // eax@31
  int v10; // eax@36
  AbstractResource *v11; // eax@36
  struct _SEQUENCE *v12; // eax@41
  Sequence *seq; // eax@43
  struct _SEQUENCE *v14; // edx@43
  signed int v15; // eax@46
  signed int v16; // ecx@46
  signed int v17; // eax@48
  signed int v18; // ecx@48
  signed __int32 volume; // eax@51
  char buf[1]; // [sp+Ch] [bp-10h]@40

  thisa = this;
  if ( soundDisabled || !this->usingRedbookRelated || !*(_DWORD *)&musicVolume )
    return;
  debugLog("MP1a");
  seqIdx = track;
  if ( !byte_51F150[track] )
    seqIdx = -1;
  if ( seqIdx == -1 )
  {
    if ( !soundDisabled )
    {
      v4 = thisa->usingRedbookRelated;
      if ( v4 )
      {
        if ( curSequenceIndex != -1 )
        {
          if ( !soundDisabled )
          {
            if ( *(_DWORD *)&musicVolume )
            {
              if ( v4 )
              {
                if ( curSequenceIndex != -1 )
                {
                  v5 = *(&hsequences + curSequenceIndex);
                  if ( v5 )
                  {
                    if ( AIL_sequence_status(v5) == 4 )
                    {
                      if ( *(&hsequences + curSequenceIndex) )
                      {
                        AIL_stop_sequence(*(&hsequences + curSequenceIndex));
                        if ( dword_4F74A8 || !*((_BYTE *)&byte_523020 + curSequenceIndex) )
                        {
                          AIL_release_sequence_handle(*(&hsequences + curSequenceIndex));
                          v6 = curSequenceIndex;
                          *(HSEQUENCE *)((char *)&hsequences + v6 * 4) = 0;
                          v7 = (AbstractResource *)sequences[v6];
                          if ( v7 )
                            ResourceManager::reduceReferenceCountToResource(resourceManager, v7);
                          sequences[curSequenceIndex] = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          curSequenceIndex = -1;
          thisa->currentTrack = -1;
        }
      }
    }
    return;
  }
  if ( curSequenceIndex == seqIdx )
    return;
  if ( !soundDisabled )
  {
    v8 = thisa->usingRedbookRelated;
    if ( v8 )
    {
      if ( curSequenceIndex != -1 )
      {
        if ( !soundDisabled )
        {
          if ( *(_DWORD *)&musicVolume )
          {
            if ( v8 )
            {
              if ( curSequenceIndex != -1 )
              {
                v9 = *(&hsequences + curSequenceIndex);
                if ( v9 )
                {
                  if ( AIL_sequence_status(v9) == 4 )
                  {
                    if ( *(&hsequences + curSequenceIndex) )
                    {
                      AIL_stop_sequence(*(&hsequences + curSequenceIndex));
                      if ( dword_4F74A8 || !*((_BYTE *)&byte_523020 + curSequenceIndex) )
                      {
                        AIL_release_sequence_handle(*(&hsequences + curSequenceIndex));
                        v10 = curSequenceIndex;
                        *(HSEQUENCE *)((char *)&hsequences + v10 * 4) = 0;
                        v11 = (AbstractResource *)sequences[v10];
                        if ( v11 )
                          ResourceManager::reduceReferenceCountToResource(resourceManager, v11);
                        sequences[curSequenceIndex] = 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        curSequenceIndex = -1;
        thisa->currentTrack = -1;
      }
    }
  }
  sprintf(buf, "MIDI%04d.XMI", seqIdx);
  if ( *(&hsequences + seqIdx) )
  {
    AIL_resume_sequence(*(&hsequences + seqIdx));
LABEL_56:
    curSequenceIndex = seqIdx;
    thisa->currentTrack = seqIdx;
    return;
  }
  v12 = AIL_allocate_sequence_handle(drvr);
  *(&hsequences + seqIdx) = v12;
  if ( !v12 )
    SoundManager::closeMidiOutput(thisa);
  seq = ResourceManager::getSequenceByFilename(resourceManager, buf);
  v14 = *(&hsequences + seqIdx);
  sequences[seqIdx] = seq;
  if ( AIL_init_sequence(v14, seq->contents, 0) )
  {
    if ( !soundDisabled && thisa->usingRedbookRelated )
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
      volume = computeAILVolume(v15, 101);
      AIL_set_XMIDI_master_volume(drvr, volume);
    }
    AIL_start_sequence(*(&hsequences + seqIdx));
    if ( byte_524060[seqIdx] )
      AIL_set_sequence_loop_count(*(&hsequences + seqIdx), 0);
    else
      AIL_set_sequence_loop_count(*(&hsequences + seqIdx), 1);
    goto LABEL_56;
  }
}
