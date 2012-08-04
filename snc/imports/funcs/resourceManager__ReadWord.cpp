{
  int err; // ST1C_4@2
  __int16 buf; // [sp+18h] [bp-8h]@1
  int success; // [sp+1Ch] [bp-4h]@1

  ProcessAssert(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 732);
  buf = 0;
  success = _read(this->fileDescriptors[this->curHandleIdx], &buf, 2u);
  if ( !success )
    err = *_errno();
  return buf;
}