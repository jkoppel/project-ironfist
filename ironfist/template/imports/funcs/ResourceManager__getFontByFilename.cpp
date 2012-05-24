{
  Font *result; // eax@2
  Font *newFontMem; // [sp+10h] [bp-Ch]@3
  Font *loadedFont; // [sp+14h] [bp-8h]@1
  Font *newFont; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = ResourceManager::setResource(this, filename, 1);
  loadedFont = (Font *)ResourceManager::findLoadedFile(this, hash);
  if ( loadedFont )
  {
    ++loadedFont->referenceCount;
    result = loadedFont;
  }
  else
  {
    newFontMem = (Font *)operator new(sizeof(Font));
    if ( newFontMem )
      newFont = Font_constructor(newFontMem, hash);
    else
      newFont = 0;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)newFont);
    result = newFont;
  }
  return result;
}
