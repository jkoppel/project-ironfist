{
  unsigned int hash; // ST20_4@1
  MIDIWrap *sequence; // eax@2 MAPDST

  hash = resourceManager::MakeId(this, filename, 1);
  sequence = (MIDIWrap *)resourceManager::Query(this, hash);
  if ( sequence )
  {
    ++sequence->referenceCount;
  }
  else
  {
    sequence = (MIDIWrap *)operator new(sizeof(MIDIWrap));
    if ( sequence )
      sequence = MIDIWrap::MIDIWrap(sequence, filename);
    else
      sequence = NULL;
    resourceManager::AddResource(this, (resource *)sequence);
  }
  return sequence;
}