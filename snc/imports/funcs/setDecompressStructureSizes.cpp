{
  int v1; // [sp+Ch] [bp-Ch]@1

  v1 = a1;
  if ( a1 != blockSize100k )
  {
    blockSize100k = a1;
    FreeDecompressStructures();
    if ( v1 )
    {
      block = BaseAlloc(100000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1185);
      ll = BaseAlloc(100000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1186);
      zptr = BaseAlloc(400000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1187);
      if ( !block || !ll || !zptr )
        uncompressOutOfMemory(600000 * v1, 100000 * v1);
    }
  }
}