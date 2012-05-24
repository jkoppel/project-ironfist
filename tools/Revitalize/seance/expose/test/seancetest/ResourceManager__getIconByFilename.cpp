Icon *__thiscall ResourceManager::getIconByFilename(ResourceManager *this, const char *filename)
{
  unsigned int hash; // eax@1

  hash = ResourceManager::setResource(this, filename, 1);
  return ResourceManager::getIconByFileID(this, hash);
}
