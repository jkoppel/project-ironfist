{
  int v1; // ST20_4@1
  int v2; // ST24_4@1

  strcpy(inName, this);
  strcpy(outName, this);
  *(_DWORD *)&outName[strlen(outName)] = dword_520628;
  v1 = fopen(inName, (int)"rb");
  v2 = fopen(outName, (int)"wb");
  *_errno() = 0;
  outputHandleJustInCase = v2;
  compressStream(v1, (void *)v2);
  outputHandleJustInCase = 0;
  return remove(inName);
}