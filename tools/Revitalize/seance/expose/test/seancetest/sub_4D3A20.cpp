void __fastcall sub_4D3A20(int a1)
{
  int v1; // [sp+Ch] [bp-Ch]@1

  v1 = a1;
  if ( a1 != dword_537934 )
  {
    dword_537934 = a1;
    sub_4D3980();
    if ( v1 )
    {
      dword_51FDCC = KBAlloc(100000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1185);
      dword_51FDD0 = KBAlloc(100000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1186);
      dword_51FDC4 = KBAlloc(400000 * v1 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1187);
      if ( !dword_51FDCC || !dword_51FDD0 || !dword_51FDC4 )
        sub_4D6070(600000 * v1, 100000 * v1);
    }
  }
}
