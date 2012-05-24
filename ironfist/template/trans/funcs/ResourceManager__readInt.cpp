{
  int err;
  int buf;
  int success;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 760);
  buf = 0;
  success = _read(this->fileDescriptors[this->curHandleIdx], &buf, sizeof(int));
  if ( !success )
    err = *_errno();
  return buf;
}
