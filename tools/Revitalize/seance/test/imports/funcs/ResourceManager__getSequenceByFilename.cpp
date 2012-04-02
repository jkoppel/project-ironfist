{
  int v2; // ST20_4@1
  Sequence *result; // eax@2
  ResourceManager *this; // [sp+Ch] [bp-10h]@1
  Sequence *v5; // [sp+10h] [bp-Ch]@3
  AbstractResource *a2; // [sp+14h] [bp-8h]@1
  AbstractResource *a2a; // [sp+14h] [bp-8h]@4

  this = ecx0;
  v2 = ResourceManager::setResource(ecx0, filename, 1);
  a2 = ResourceManager::findLoadedFile(this, v2);
  if ( a2 )
  {
    ++a2->referenceCount;
    result = (Sequence *)a2;
  }
  else
  {
    v5 = (Sequence *)operator new(0x14u);
    if ( v5 )
      a2a = (AbstractResource *)Sequence_constructor(v5, filename);
    else
      a2a = 0;
    ResourceManager::prependFileLinkedListNode(this, a2a);
    result = (Sequence *)a2a;
  }
  return result;
}
