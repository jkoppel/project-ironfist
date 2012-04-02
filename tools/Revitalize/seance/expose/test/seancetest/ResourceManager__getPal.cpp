Palette *__thiscall ResourceManager::getPal(ResourceManager *thisa, const char *file)
{
  Palette *result; // eax@2
  Palette *v4; // [sp+10h] [bp-Ch]@3
  int fileID; // [sp+14h] [bp-8h]@1
  AbstractResource *a2; // [sp+18h] [bp-4h]@1
  AbstractResource *a2a; // [sp+18h] [bp-4h]@4

  fileID = ResourceManager::setResource(thisa, file, 1);
  a2 = ResourceManager::findLoadedFile(thisa, fileID);
  if ( a2 )
  {
    ++a2->referenceCount;
    result = (Palette *)a2;
  }
  else
  {
    v4 = (Palette *)operator new(sizeof(Palette));
    if ( v4 )
      a2a = (AbstractResource *)Palette_constructorFromFile(v4, fileID);
    else
      a2a = 0;
    ResourceManager::prependFileLinkedListNode(thisa, a2a);
    result = (Palette *)a2a;
  }
  return result;
}
