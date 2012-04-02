{
  ResourceManager *thisa; // ST18_4@1
  int v2; // ST1C_4@2
  int buf; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  assertTrue(this->fileDescriptors[this->curHandleIdx] != 0xFFFFFFFF, "F:\\h2xsrc\\Base\\RESMGR.CPP", 760);
  buf = 0;
  v5 = _read(thisa->fileDescriptors[thisa->curHandleIdx], &buf, 4u);
  if ( !v5 )
    v2 = *_errno();
  return buf;
}
