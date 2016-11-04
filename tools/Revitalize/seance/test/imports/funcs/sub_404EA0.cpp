{
  signed int v0; // [sp+Ch] [bp-18h]@2
  int v1; // [sp+10h] [bp-14h]@2
  int v2; // [sp+1Ch] [bp-8h]@2
  int v3; // [sp+20h] [bp-4h]@2

  if ( dword_4ED2CC )
  {
    while ( 1 )
    {
      v3 = 256;
      v0 = (*(int (__cdecl **)(int, int *, int *, signed int, _DWORD, int *))(*(_DWORD *)dword_4ED2CC + 84))(
             dword_4ED2CC,
             &v1,
             &v2,
             1,
             buf,
             &v3);
      if ( v0 == -2005466946 )
        break;
      if ( v0 )
        sub_4057C0(v0, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED5AC + 23);
      if ( v1 && (!v2 || v2 == dword_4ED2D0) )
        sub_404F60(v3, v1);
    }
  }
}
