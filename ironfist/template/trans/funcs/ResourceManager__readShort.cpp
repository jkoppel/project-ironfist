{
  int err;
  __int16 buf;
  int success;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 732);
  buf = 0;
  success = _read(this->fileDescriptors[this->curHandleIdx], &buf, sizeof(short));
  if ( !success )
    err = *_errno();
  return buf;
}
