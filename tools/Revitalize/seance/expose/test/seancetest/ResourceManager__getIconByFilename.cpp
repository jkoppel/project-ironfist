Icon *__thiscall ResourceManager::getIconByFilename(ResourceManager *this, const char *filename)
{
  ResourceManager *v2; // ST14_4@1
  int v3; // eax@1

  v2 = this;
  v3 = ResourceManager::setResource(this, filename, 1);
  return ResourceManager::getIconByFileID(v2, v3);
}
