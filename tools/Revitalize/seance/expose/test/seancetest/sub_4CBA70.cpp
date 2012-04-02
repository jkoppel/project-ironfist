signed int __thiscall sub_4CBA70(int this)
{
  signed int result; // eax@1
  int v2; // esi@1
  struct _SEQUENCE *v3; // eax@8
  int v4; // eax@13
  AbstractResource *v5; // eax@13

  result = soundDisabled;
  v2 = this;
  if ( !soundDisabled )
  {
    result = *(_DWORD *)(this + 1698);
    if ( result )
    {
      if ( curSequenceIndex != -1 )
      {
        if ( !soundDisabled )
        {
          if ( *(_DWORD *)&musicVolume )
          {
            if ( result )
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
        result = -1;
        curSequenceIndex = -1;
        *(_BYTE *)(v2 + 1404) = -1;
      }
    }
  }
  return result;
}
