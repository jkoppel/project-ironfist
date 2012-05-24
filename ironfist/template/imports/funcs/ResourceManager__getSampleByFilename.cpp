{
  unsigned int hash; // ST28_4@1
  Sample *sample; // eax@2 MAPDST

  hash = ResourceManager::setResource(this, filename, 1);
  sample = (Sample *)ResourceManager::findLoadedFile(this, hash);
  if ( sample )
  {
    ++sample->referenceCount;
  }
  else
  {
    sample = (Sample *)operator new(sizeof(Sample));
    if ( sample )
      sample = Sample_constructor(sample, filename, 0, 127, 1);
    else
      sample = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)sample);
  }
  return sample;
}
