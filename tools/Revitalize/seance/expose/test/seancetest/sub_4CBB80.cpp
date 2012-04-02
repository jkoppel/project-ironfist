bool __thiscall sub_4CBB80(SoundManager *this)
{
  struct _SEQUENCE *v1; // eax@5
  bool result; // eax@6

  if ( !soundDisabled
    && *(_DWORD *)&musicVolume
    && this->usingRedbookRelated
    && curSequenceIndex != -1
    && (v1 = *(&hsequences + curSequenceIndex)) != 0 )
    result = AIL_sequence_status(v1) == 4;
  else
    result = 0;
  return result;
}
