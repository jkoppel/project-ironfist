{
  unsigned int hash; // ST28_4@1
  sample *sample; // eax@2 MAPDST

  hash = resourceManager::MakeId(this, filename, 1);
  sample = (sample *)resourceManager::Query(this, hash);
  if ( sample )
  {
    ++sample->referenceCount;
  }
  else
  {
    sample = (sample *)operator new(sizeof(sample));
    if ( sample )
      sample = sample::sample(sample, filename, 0, 127, 1);
    else
      sample = NULL;
    resourceManager::AddResource(this, (resource *)sample);
  }
  return sample;
}