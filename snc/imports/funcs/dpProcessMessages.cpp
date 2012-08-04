{
  signed int v0; // [sp+Ch] [bp-18h]@2
  int v1; // [sp+10h] [bp-14h]@2
  int v2; // [sp+1Ch] [bp-8h]@2
  int v3; // [sp+20h] [bp-4h]@2

  if ( lpIDC )
  {
    while ( 1 )
    {
      v3 = 256;
      v0 = (*(int (__cdecl **)(int, int *, int *, signed int, _DWORD, int *))(*(_DWORD *)lpIDC + 84))(
             lpIDC,
             &v1,
             &v2,
             1,
             rcvBufIn,
             &v3);
      if ( v0 == -2005466946 )
        break;
      if ( v0 )
        DPSD(v0, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED5AC + 23);
      if ( v1 && (!v2 || v2 == dcoID) )
        dpEvaluateMessage(v3, v1);
    }
  }
}