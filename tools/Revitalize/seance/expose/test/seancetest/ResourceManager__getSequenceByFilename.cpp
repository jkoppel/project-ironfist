Sequence *__thiscall ResourceManager::getSequenceByFilename(ResourceManager *this, const char *filename)
{
  unsigned int hash; // ST20_4@1
  Sequence *sequence; // eax@2 MAPDST

  hash = ResourceManager::setResource(this, filename, 1);
  sequence = (Sequence *)ResourceManager::findLoadedFile(this, hash);
  if ( sequence )
  {
    ++sequence->referenceCount;
  }
  else
  {
    sequence = (Sequence *)operator new(sizeof(Sequence));
    if ( sequence )
      sequence = Sequence_constructor(sequence, filename);
    else
      sequence = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)sequence);
  }
  return sequence;
}
