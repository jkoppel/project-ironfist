void __thiscall ResourceManager::readNexDOSFilename(ResourceManager *this, char *buf)
{
  ResourceManager::readFromCurrentFile(this, buf, MAX_FILENAME_LENGTH);
}
