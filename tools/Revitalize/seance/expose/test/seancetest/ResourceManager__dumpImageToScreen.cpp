void __thiscall ResourceManager::dumpImageToScreen(ResourceManager *this, const char *filename, Bitmap *screenBuf, int isICN)
{
  Icon *icn; // ST20_4@2
  unsigned int bmpHash; // eax@3

  if ( isICN )
  {
    icn = ResourceManager::getIconByFilename(this, filename);
    Icon::drawToScreen(icn, 0, 0, 0, 0);
    ResourceManager::reduceReferenceCountToResource(this, (AbstractResource *)icn);
  }
  else
  {
    bmpHash = ResourceManager::setResource(this, filename, 1);
    ResourceManager::pointToFile(this, bmpHash);
    ResourceManager::readShort(this);
    ResourceManager::readShort(this);
    ResourceManager::readShort(this);
    ResourceManager::readFromCurrentFile(this, screenBuf->contents, screenBuf->width * screenBuf->height);
  }
}
