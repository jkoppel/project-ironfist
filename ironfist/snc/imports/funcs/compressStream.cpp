{
  int v2; // ST60_4@4
  int v3; // [sp+48h] [bp-18h]@1
  int v4; // [sp+50h] [bp-10h]@1
  signed int v5; // [sp+54h] [bp-Ch]@1
  signed int v6; // [sp+5Ch] [bp-4h]@5

  v3 = a1;
  v5 = 1;
  bytesIn = 0;
  bytesOut = 0;
  v4 = (int)bsOpenWriteStream(a2);
  bsPutUChar(v4, 0x42u);
  bsPutUChar(v4, 0x5Au);
  bsPutUChar(v4, 0x30u);
  bsPutUChar(v4, blockSize100k + 48);
  initialiseCRC();
  initBogusModel();
  arithCodeStartEncoding();
  do
  {
    if ( veryVerbose )
    {
      sprintf(gText, "\nBEGIN block %d\n", v5);
      LogStr(gText);
    }
    ++v5;
    v2 = loadAndRLEsource((void *)v3);
    spotBlock((void *)1);
    doReversibleTransformation();
    moveToFrontCodeAndSend((void *)v4, v2);
  }
  while ( !v2 );
  v6 = getFinalCRC();
  putUInt32((void *)v4, v6);
  if ( veryVerbose )
  {
    sprintf(gText, "\nCRC = 0x%x\n", v6);
    LogStr(gText);
  }
  arithCodeDoneEncoding((void *)v4);
  bsClose((void *)v4);
  if ( *(_BYTE *)(v3 + 12) & 0x20 )
    ioError();
  if ( fclose(v3) == -1 )
    ioError();
  if ( veryVerbose )
  {
    sprintf(gText, L" ");
    LogStr(gText);
    dumpAllModelStats();
    sprintf(gText, L" ");
    LogStr(gText);
  }
  if ( !bytesIn )
    bytesIn = 1;
  if ( !bytesOut )
    bytesOut = 1;
  if ( dword_5357FC )
  {
    sprintf(
      gText,
      "%6.3f:1, %6.3f bits/byte, %5.2f%% saved, %d in, %d out.\n",
      (double)bytesIn / (double)bytesOut,
      (double)bytesOut * 8.0 / (double)bytesIn,
      (1.0 - (double)bytesOut / (double)bytesIn) * 100.0,
      bytesIn,
      bytesOut);
    LogStr(gText);
  }
  if ( veryVerbose )
  {
    sprintf(gText, L"\n");
    LogStr(gText);
  }
}