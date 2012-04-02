void __thiscall ResourceManager::readFromCurrentFile(ResourceManager *this, void *buf, unsigned int nbytes)
{
  int v3; // ST28_4@2
  int *v4; // eax@2
  ResourceManager *thisa; // [sp+Ch] [bp-10h]@1
  int v6; // [sp+18h] [bp-4h]@1

  thisa = this;
  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 816);
  yieldToGlobalUpdater();
  v6 = _read(thisa->fileDescriptors[thisa->curHandleIdx], buf, nbytes);
  if ( v6 != nbytes )
  {
    v3 = *_errno();
    v4 = _errno();
    sprintf(
      globBuf,
      "File error - bytes read %d, bytes requested %d, errno %d, last file '%s'",
      v6,
      nbytes,
      *v4,
      thisa->resourceToLoad);
    debugLog(globBuf);
  }
  yieldToGlobalUpdater();
}
