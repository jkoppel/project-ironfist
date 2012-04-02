{
  Tileset *result; // eax@2
  ResourceManager *thisa; // [sp+Ch] [bp-10h]@1
  Tileset *thisb; // [sp+10h] [bp-Ch]@3
  int fileID; // [sp+14h] [bp-8h]@1
  AbstractResource *a2; // [sp+18h] [bp-4h]@1
  AbstractResource *a2a; // [sp+18h] [bp-4h]@4

  thisa = this;
  fileID = ResourceManager::setResource(this, filename, 1);
  a2 = ResourceManager::findLoadedFile(thisa, fileID);
  if ( a2 )
  {
    ++a2->referenceCount;
    result = (Tileset *)a2;
  }
  else
  {
    thisb = (Tileset *)operator new(0x1Au);
    if ( thisb )
      a2a = (AbstractResource *)Tileset_constructor(thisb, fileID);
    else
      a2a = 0;
    ResourceManager::prependFileLinkedListNode(thisa, a2a);
    result = (Tileset *)a2a;
  }
  return result;
}
