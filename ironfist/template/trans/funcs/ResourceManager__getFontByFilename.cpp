{
  Font *result;
  Font *newFontMem;
  Font *loadedFont;
  Font *newFont;
  unsigned int hash;

  hash = this->setResource(filename, 1);
  loadedFont = (Font *)this->findLoadedFile(hash);
  if ( loadedFont )
  {
    ++loadedFont->referenceCount;
    result = loadedFont;
  }
  else
  {
    newFontMem = new Font;
    if ( newFontMem )
      newFont = Font_constructor(newFontMem, hash);
    else
      newFont = 0;
    this->prependFileLinkedListNode((AbstractResource *)newFont);
    result = newFont;
  }
  return result;
}
