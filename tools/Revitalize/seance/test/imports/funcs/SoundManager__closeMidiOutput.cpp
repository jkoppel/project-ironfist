{
  SoundManager *thisa; // esi@1
  int v2; // eax@2
  struct _SEQUENCE *v3; // eax@10
  int v4; // eax@15
  AbstractResource *v5; // eax@15
  HSEQUENCE *v6; // edi@19
  AbstractResource **v7; // esi@23

  thisa = this;
  if ( !soundDisabled )
  {
    v2 = this->usingRedbookRelated;
    if ( v2 )
    {
      if ( !soundDisabled && v2 && curSequenceIndex != -1 )
      {
        if ( !soundDisabled )
        {
          if ( *(_DWORD *)&musicVolume )
          {
            if ( v2 )
            {
              if ( curSequenceIndex != -1 )
              {
                v3 = *(&hsequences + curSequenceIndex);
                if ( v3 )
                {
                  if ( AIL_sequence_status(v3) == 4 )
                  {
                    if ( *(&hsequences + curSequenceIndex) )
                    {
                      AIL_stop_sequence(*(&hsequences + curSequenceIndex));
                      if ( dword_4F74A8 || !*((_BYTE *)&byte_523020 + curSequenceIndex) )
                      {
                        AIL_release_sequence_handle(*(&hsequences + curSequenceIndex));
                        v4 = curSequenceIndex;
                        *(HSEQUENCE *)((char *)&hsequences + v4 * 4) = 0;
                        v5 = (AbstractResource *)sequences[v4];
                        if ( v5 )
                          ResourceManager::reduceReferenceCountToResource(resourceManager, v5);
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
      v6 = &hsequences;
      debugLog("MS1");
      do
      {
        if ( *v6 )
          AIL_release_sequence_handle(*v6);
        *v6 = 0;
        ++v6;
      }
      while ( (unsigned int)v6 < (unsigned int)fileOffsetStack );
      debugLog("MS2");
      AIL_midiOutClose(drvr);
      drvr = 0;
      thisa->usingRedbookRelated = 0;
      v7 = (AbstractResource **)sequences;
      do
      {
        if ( *v7 )
          ResourceManager::reduceReferenceCountToResource(resourceManager, *v7);
        *v7 = 0;
        ++v7;
      }
      while ( (unsigned int)v7 < (unsigned int)&hsequences );
      debugLog("MS4");
    }
  }
}
