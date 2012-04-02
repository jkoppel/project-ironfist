void __fastcall sub_4D5960(int a1, void *a2)
{
  int v2; // ST60_4@4
  int v3; // [sp+48h] [bp-18h]@1
  int v4; // [sp+50h] [bp-10h]@1
  signed int v5; // [sp+54h] [bp-Ch]@1
  signed int v6; // [sp+5Ch] [bp-4h]@5

  v3 = a1;
  v5 = 1;
  dword_5347A8 = 0;
  dword_534BDC = 0;
  v4 = (int)sub_4D26E0(a2);
  sub_4D28D0(v4, 0x42u);
  sub_4D28D0(v4, 0x5Au);
  sub_4D28D0(v4, 0x30u);
  sub_4D28D0(v4, dword_537934 + 48);
  sub_4D25F0();
  sub_4D3080();
  sub_4D2AA0();
  do
  {
    if ( dword_537920 )
    {
      sprintf(globBuf, "\nBEGIN block %d\n", v5);
      debugLog(globBuf);
    }
    ++v5;
    v2 = sub_4D55E0((void *)v3);
    sub_4D52B0((void *)1);
    sub_4D5060();
    sub_4D3DA0((void *)v4, v2);
  }
  while ( !v2 );
  v6 = sub_4D2610();
  sub_4D3150((void *)v4, v6);
  if ( dword_537920 )
  {
    sprintf(globBuf, "\nCRC = 0x%x\n", v6);
    debugLog(globBuf);
  }
  sub_4D2AE0((void *)v4);
  sub_4D2920((void *)v4);
  if ( *(_BYTE *)(v3 + 12) & 0x20 )
    sub_4D5F60();
  if ( fclose((FILE *)v3) == -1 )
    sub_4D5F60();
  if ( dword_537920 )
  {
    sprintf(globBuf, L" ");
    debugLog(globBuf);
    sub_4D33B0();
    sprintf(globBuf, L" ");
    debugLog(globBuf);
  }
  if ( !dword_5347A8 )
    dword_5347A8 = 1;
  if ( !dword_534BDC )
    dword_534BDC = 1;
  if ( dword_5357FC )
  {
    sprintf(
      globBuf,
      "%6.3f:1, %6.3f bits/byte, %5.2f%% saved, %d in, %d out.\n",
      (double)dword_5347A8 / (double)dword_534BDC,
      (double)dword_534BDC * 8.0 / (double)dword_5347A8,
      (1.0 - (double)dword_534BDC / (double)dword_5347A8) * 100.0,
      dword_5347A8,
      dword_534BDC);
    debugLog(globBuf);
  }
  if ( dword_537920 )
  {
    sprintf(globBuf, L"\n");
    debugLog(globBuf);
  }
}
