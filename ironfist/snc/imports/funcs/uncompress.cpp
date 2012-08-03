{
  int v1; // ST24_4@3
  int v2; // ST28_4@3

  strcpy(inName, this);
  strcpy(outName, this);
  if ( endsInBz(inName) )
    *((_BYTE *)&bigR + strlen(outName) + 1) = 0;
  v1 = fopen(inName, (int)"rb");
  v2 = fopen(outName, (int)"wb");
  *_errno() = 0;
  outputHandleJustInCase = v2;
  uncompressStream((void *)v1, v2);
  outputHandleJustInCase = 0;
  if ( remove(inName) )
    ioError();
}