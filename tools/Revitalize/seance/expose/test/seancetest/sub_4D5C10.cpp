signed int __fastcall sub_4D5C10(void *a1, int a2)
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
  v6 = (int)sub_4D2670(a1);
  v2 = (unsigned __int8)sub_4D2880((void *)v6);
  v8 = (unsigned __int8)sub_4D2880((void *)v6);
  v7 = (unsigned __int8)sub_4D2880((void *)v6);
  v5 = (unsigned __int8)sub_4D2880((void *)v6);
  if ( v2 == 66 && v8 == 90 && v7 == 48 && v5 >= 49 && v5 <= 57 )
  {
    sub_4D3A20(v5 - 48);
    sub_4D25F0();
    sub_4D3080();
    sub_4D2B30((void *)v6);
    if ( dword_537920 )
    {
      sprintf(globBuf, "  ");
      debugLog(globBuf);
    }
    v11 = 0;
    do
    {
      ++v11;
      if ( dword_537920 )
      {
        sprintf(globBuf, "[%d: ac+mtf ", v11);
        debugLog(globBuf);
      }
      v9 = sub_4D3F60(v6);
      if ( dword_537920 )
        debugLog("rt ");
      sub_4D5110();
      sub_4D52B0(0);
      if ( dword_537920 )
        debugLog("rld");
      sub_4D57D0((FILE *)v4, v9);
      if ( dword_537920 )
        debugLog("] ");
    }
    while ( !v9 );
    if ( dword_537920 )
      debugLog(L" ");
    v10 = sub_4D3260(v6);
    v12 = sub_4D2610();
    if ( dword_537920 )
    {
      sprintf(globBuf, "CRCs: stored = 0x%x, computed = 0x%x\n  ", v10, v12);
      debugLog(globBuf);
    }
    if ( v12 != v10 )
      sub_4D5EC0(v10, v12);
    unknown_libname_24();
    sub_4D2920((void *)v6);
    if ( *(_BYTE *)(v4 + 12) & 0x20 )
      sub_4D5F60();
    if ( fclose((FILE *)v4) == -1 )
      sub_4D5F60();
    sub_4D3980();
    result = 1;
  }
  else
  {
    sub_4D2920((void *)v6);
    if ( fclose((FILE *)v4) == -1 )
      sub_4D5F60();
    sub_4D3980();
    result = 0;
  }
  return result;
}
