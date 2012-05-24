{
  unsigned int hash;
  Sample *sample;

  hash = this->setResource(filename, 1);
  sample = (Sample *)this->findLoadedFile(hash);
  if ( sample )
  {
    ++sample->referenceCount;
  }
  else
  {
    sample = new Sample;
    if ( sample )
      sample = Sample_constructor(sample, filename, 0, 127, 1);
    else
      sample = NULL;
    this->prependFileLinkedListNode((AbstractResource *)sample);
  }
  return sample;
}
