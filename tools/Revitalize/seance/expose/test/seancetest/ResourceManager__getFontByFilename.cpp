Font *__thiscall ResourceManager::getFontByFilename(ResourceManager *ecx0, const char *filename)
{
  Font *result; // eax@2
  ResourceManager *this; // [sp+Ch] [bp-10h]@1
  Font *ecx0a; // [sp+10h] [bp-Ch]@3
  AbstractResource *a2; // [sp+14h] [bp-8h]@1
  AbstractResource *fileNodea; // [sp+14h] [bp-8h]@4
  int fileID; // [sp+18h] [bp-4h]@1

  this = ecx0;
  fileID = ResourceManager::setResource(ecx0, filename, 1);
  a2 = ResourceManager::findLoadedFile(this, fileID);
  if ( a2 )
  {
    ++a2->referenceCount;
    result = (Font *)a2;
  }
  else
  {
    ecx0a = (Font *)operator new(0x20u);
    if ( ecx0a )
      fileNodea = (AbstractResource *)Font_constructor(ecx0a, fileID);
    else
      fileNodea = 0;
    ResourceManager::prependFileLinkedListNode(this, fileNodea);
    result = (Font *)fileNodea;
  }
  return result;
}
