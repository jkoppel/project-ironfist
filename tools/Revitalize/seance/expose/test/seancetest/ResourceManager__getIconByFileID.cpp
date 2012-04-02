Icon *__thiscall ResourceManager::getIconByFileID(ResourceManager *ecx0, int fileID)
{
  Icon *result; // eax@2
  ResourceManager *this; // [sp+Ch] [bp-Ch]@1
  Icon *v4; // [sp+10h] [bp-8h]@3
  Icon *fileNode; // [sp+14h] [bp-4h]@1
  AbstractResource *fileNodea; // [sp+14h] [bp-4h]@4

  this = ecx0;
  fileNode = (Icon *)ResourceManager::findLoadedFile(ecx0, fileID);
  if ( fileNode )
  {
    ++fileNode->referenceCount;
    result = fileNode;
  }
  else
  {
    v4 = (Icon *)operator new(0x16u);
    if ( v4 )
      fileNodea = (AbstractResource *)Icon_constructor(v4, fileID);
    else
      fileNodea = 0;
    ResourceManager::prependFileLinkedListNode(this, fileNodea);
    result = (Icon *)fileNodea;
  }
  return result;
}
