{
  int err1;
  int *err2;
  signed int nread;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 816);
  yieldToGlobalUpdater();
  nread = _read(this->fileDescriptors[this->curHandleIdx], buf, ntoread);
  if ( nread != ntoread )
  {
    err1 = *_errno();
    err2 = _errno();
    sprintf(
      globBuf,
      "File error - bytes read %d, bytes requested %d, errno %d, last file '%s'",
      nread,
      ntoread,
      *err2,
      this->resourceToLoad);
    debugLog(globBuf);
  }
  yieldToGlobalUpdater();
}
