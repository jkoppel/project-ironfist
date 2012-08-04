{
  int v4; // [sp+Ch] [bp-84h]@1
  int v5; // [sp+10h] [bp-80h]@1
  int v6; // [sp+14h] [bp-7Ch]@4
  signed int errorCode; // [sp+18h] [bp-78h]@4
  int v8; // [sp+24h] [bp-6Ch]@1
  int v9; // [sp+28h] [bp-68h]@2
  int v10; // [sp+2Ch] [bp-64h]@3
  int v11; // [sp+30h] [bp-60h]@3
  unsigned __int8 *v12; // [sp+48h] [bp-48h]@10
  int v13; // [sp+8Ch] [bp-4h]@2

  v4 = a2;
  v5 = a1;
  memset(&v8, 0, 0x6Cu);
  v8 = 108;
  if ( a3 )
  {
    v9 = 1;
    v13 = 512;
  }
  else
  {
    v9 = 7;
    v13 = 2112;
    v10 = v4;
    v11 = v5;
  }
  errorCode = ((int (__cdecl *)(LPDIRECTDRAW *, int *, int *, _DWORD))(*lpDD)[6].lpVtbl)(lpDD, &v8, &v6, 0);
  if ( errorCode )
    DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519998 + 28);
  if ( !a3 )
  {
    errorCode = (*(int (__cdecl **)(int, _DWORD, int *, signed int, _DWORD))(*(_DWORD *)v6 + 100))(v6, 0, &v8, 1, 0);
    if ( errorCode )
      DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519998 + 36);
    if ( gpWindowManager->screenBuffer )
    {
      gpWindowManager->screenBuffer->contents = v12;
      lpInitWin = (bitmap *)v12;
    }
    else
    {
      lpInitWin = (bitmap *)v12;
    }
  }
  return v6;
}