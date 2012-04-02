void __thiscall ResourceManager::readNexDOSFilename(ResourceManager *this, void *buf)
{
  ResourceManager::readFromCurrentFile(this, buf, 13u);
}
