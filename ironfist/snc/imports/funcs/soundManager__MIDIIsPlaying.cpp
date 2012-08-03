{
  struct _SEQUENCE *v1; // eax@5
  bool result; // eax@6

  if ( !gbNoSound
    && *(_DWORD *)&Data
    && this->usingRedbookRelated
    && CurrentMidiFile != -1
    && (v1 = *(&hSequence + CurrentMidiFile)) != 0 )
    result = AIL_sequence_status(v1) == 4;
  else
    result = 0;
  return result;
}