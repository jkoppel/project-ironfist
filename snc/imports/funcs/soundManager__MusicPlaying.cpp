{
  bool result; // eax@2

  if ( gbNoSound )
  {
    result = 0;
  }
  else if ( *(_DWORD *)&useCDMusic )
  {
    if ( this->field_69E )
      result = soundManager::CDIsPlaying(this);
    else
      result = 0;
  }
  else if ( this->usingRedbookRelated )
  {
    result = soundManager::MIDIIsPlaying(this);
  }
  else
  {
    result = 0;
  }
  return result;
}