{
  int id; // ST28_4@1
  Sample *result; // eax@2
  ResourceManager *thisa; // [sp+Ch] [bp-10h]@1
  Sample *this; // [sp+10h] [bp-Ch]@3
  AbstractResource *a2; // [sp+14h] [bp-8h]@1
  AbstractResource *fileNodea; // [sp+14h] [bp-8h]@4

  thisa = ecx0;
  id = ResourceManager::setResource(ecx0, filename, 1);
  a2 = ResourceManager::findLoadedFile(thisa, id);
  if ( a2 )
  {
    ++a2->referenceCount;
    result = (Sample *)a2;
  }
  else
  {
    this = (Sample *)operator new(0x30u);
    if ( this )
      fileNodea = (AbstractResource *)Sample_constructor(this, filename, 0, 127, 1);
    else
      fileNodea = 0;
    ResourceManager::prependFileLinkedListNode(thisa, fileNodea);
    result = (Sample *)fileNodea;
  }
  return result;
}
