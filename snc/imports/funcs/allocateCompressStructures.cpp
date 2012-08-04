{
  int v0; // [sp+10h] [bp-4h]@1

  v0 = 100000 * blockSize100k;
  FreeCompressStructures();
  words = BaseAlloc(4 * v0 + 65, "F:\\h2xsrc\\Base\\Bzip.cpp", 1141);
  zptr = BaseAlloc(4 * v0 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1142);
  ftab = BaseAlloc(0x40005u, "F:\\h2xsrc\\Base\\Bzip.cpp", 1143);
  if ( !words || !zptr || !ftab )
    compressOutOfMemory(8 * v0 + 262212, v0);
}