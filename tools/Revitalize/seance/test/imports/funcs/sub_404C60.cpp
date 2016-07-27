{
  char v4; // ST28_1@1
  int v5; // [sp+10h] [bp-Ch]@1
  signed int v6; // [sp+14h] [bp-8h]@3
  void *a1a; // [sp+18h] [bp-4h]@1

  v4 = a2;
  v5 = a1;
  a1a = KBAlloc(a3 + 1, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED524 + 2);
  *(_BYTE *)a1a = v4;
  if ( a3 )
    memcpy((char *)a1a + 1, a4, a3);
  v6 = (*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_4ED2CC + 92))(
         dword_4ED2CC,
         dword_4ED2D0,
         v5,
         0,
         a1a,
         a3 + 1);
  if ( v6 && v6 != -2005466986 && v6 != -2147024809 )
    sub_4057C0(v6, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED524 + 14);
  KBFree(a1a, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED524 + 16);
}
