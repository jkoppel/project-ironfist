{
  font *result; // eax@2
  font *newFontMem; // [sp+10h] [bp-Ch]@3
  font *loadedFont; // [sp+14h] [bp-8h]@1
  font *newFont; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = resourceManager::MakeId(this, filename, 1);
  loadedFont = (font *)resourceManager::Query(this, hash);
  if ( loadedFont )
  {
    ++loadedFont->referenceCount;
    result = loadedFont;
  }
  else
  {
    newFontMem = (font *)operator new(sizeof(font));
    if ( newFontMem )
      newFont = font::font(newFontMem, hash);
    else
      newFont = 0;
    resourceManager::AddResource(this, (resource *)newFont);
    result = newFont;
  }
  return result;
}