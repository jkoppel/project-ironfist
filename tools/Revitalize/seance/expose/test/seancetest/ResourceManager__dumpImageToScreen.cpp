void __thiscall ResourceManager::dumpImageToScreen(ResourceManager *this, const char *filename, Bitmap *screenBuf, int isICN)
{
  Icon *v4; // ST20_4@2
  int v5; // eax@3

  if ( isICN )
  {
    v4 = ResourceManager::getIconByFilename(this, filename);
    Icon::drawToScreen(v4, 0, 0, 0, 0);
    ResourceManager::reduceReferenceCountToResource(this, (AbstractResource *)v4);
  }
  else
  {
    v5 = ResourceManager::setResource(this, filename, 1);
    ResourceManager::pointToFile(this, v5);
    ResourceManager::readShort(this);
    ResourceManager::readShort(this);
    ResourceManager::readShort(this);
    ResourceManager::readFromCurrentFile(this, screenBuf->contents, screenBuf->width * screenBuf->height);
  }
}
