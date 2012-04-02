void __cdecl sub_4D38B0()
{
  int v0; // [sp+10h] [bp-4h]@1

  v0 = 100000 * dword_537934;
  sub_4D3810();
  dword_51FDC0 = KBAlloc(4 * v0 + 65, "F:\\h2xsrc\\Base\\Bzip.cpp", 1141);
  dword_51FDC4 = KBAlloc(4 * v0 + 1, "F:\\h2xsrc\\Base\\Bzip.cpp", 1142);
  dword_51FDC8 = KBAlloc(0x40005u, "F:\\h2xsrc\\Base\\Bzip.cpp", 1143);
  if ( !dword_51FDC0 || !dword_51FDC4 || !dword_51FDC8 )
    sub_4D60C0(8 * v0 + 262212, v0);
}
