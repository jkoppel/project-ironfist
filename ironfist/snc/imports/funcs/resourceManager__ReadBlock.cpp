{
  int err1; // ST28_4@2
  int *err2; // eax@2
  signed int nread; // [sp+18h] [bp-4h]@1

  ProcessAssert(this->fileDescriptors[this->curHandleIdx] != 0xFFFFFFFF, "F:\\h2xsrc\\Base\\RESMGR.CPP", 816);
  PollSound();
  nread = _read(this->fileDescriptors[this->curHandleIdx], buf, ntoread);
  if ( nread != ntoread )
  {
    err1 = *_errno();
    err2 = _errno();
    sprintf(
      gText,
      "File error - bytes read %d, bytes requested %d, errno %d, last file '%s'",
      nread,
      ntoread,
      *err2,
      this->resourceToLoad);
    LogStr(gText);
  }
  PollSound();
}