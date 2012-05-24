{
  unsigned int hash;
  Sequence *sequence;

  hash = this->setResource(filename, 1);
  sequence = (Sequence *)this->findLoadedFile(hash);
  if ( sequence )
  {
    ++sequence->referenceCount;
  }
  else
  {
    sequence = new Sequence;
    if ( sequence )
      sequence = Sequence_constructor(sequence, filename);
    else
      sequence = NULL;
    this->prependFileLinkedListNode((AbstractResource *)sequence);
  }
  return sequence;
}
