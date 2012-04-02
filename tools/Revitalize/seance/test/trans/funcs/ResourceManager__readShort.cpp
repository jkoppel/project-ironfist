{
  ResourceManager *v1; // ST18_4@1
  int v2; // ST1C_4@2
  __int16 buf; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  v1 = this;
  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 732);
  buf = 0;
  v5 = _read(v1->fileDescriptors[v1->curHandleIdx], &buf, 2u);
  if ( !v5 )
    v2 = *_errno();
  return buf;
}
