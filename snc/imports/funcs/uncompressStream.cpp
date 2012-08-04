{
  int v2; // ST30_4@1
  signed int result; // eax@8
  int v4; // [sp+Ch] [bp-30h]@1
  signed int v5; // [sp+14h] [bp-28h]@1
  int v6; // [sp+18h] [bp-24h]@1
  int v7; // [sp+24h] [bp-18h]@1
  int v8; // [sp+28h] [bp-14h]@1
  int v9; // [sp+2Ch] [bp-10h]@14
  int v10; // [sp+30h] [bp-Ch]@23
  int v11; // [sp+34h] [bp-8h]@11
  int v12; // [sp+38h] [bp-4h]@23

  v4 = a2;
  v6 = (int)bsOpenReadStream(a1);
  v2 = (unsigned __int8)bsGetUChar((void *)v6);
  v8 = (unsigned __int8)bsGetUChar((void *)v6);
  v7 = (unsigned __int8)bsGetUChar((void *)v6);
  v5 = (unsigned __int8)bsGetUChar((void *)v6);
  if ( v2 == 66 && v8 == 90 && v7 == 48 && v5 >= 49 && v5 <= 57 )
  {
    setDecompressStructureSizes(v5 - 48);
    initialiseCRC();
    initBogusModel();
    arithCodeStartDecoding((void *)v6);
    if ( veryVerbose )
    {
      sprintf(gText, "  ");
      LogStr(gText);
    }
    v11 = 0;
    do
    {
      ++v11;
      if ( veryVerbose )
      {
        sprintf(gText, "[%d: ac+mtf ", v11);
        LogStr(gText);
      }
      v9 = getAndMoveToFrontDecode(v6);
      if ( veryVerbose )
        LogStr("rt ");
      undoReversibleTransformation();
      spotBlock(0);
      if ( veryVerbose )
        LogStr("rld");
      unRLEandDump((FILE *)v4, v9);
      if ( veryVerbose )
        LogStr("] ");
    }
    while ( !v9 );
    if ( veryVerbose )
      LogStr(L" ");
    v10 = getUInt32(v6);
    v12 = getFinalCRC();
    if ( veryVerbose )
    {
      sprintf(gText, "CRCs: stored = 0x%x, computed = 0x%x\n  ", v10, v12);
      LogStr(gText);
    }
    if ( v12 != v10 )
      crcError(v10, v12);
    arithCodeDoneDecoding();
    bsClose((void *)v6);
    if ( *(_BYTE *)(v4 + 12) & 0x20 )
      ioError();
    if ( fclose(v4) == -1 )
      ioError();
    FreeDecompressStructures();
    result = 1;
  }
  else
  {
    bsClose((void *)v6);
    if ( fclose(v4) == -1 )
      ioError();
    FreeDecompressStructures();
    result = 0;
  }
  return result;
}