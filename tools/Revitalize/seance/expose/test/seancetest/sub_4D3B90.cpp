int __fastcall sub_4D3B90(int a1, unsigned __int8 a2)
{
  int v2; // eax@1
  int result; // eax@1

  v2 = *((_DWORD *)dword_51FDC0 + a1);
  result = (a2 << 24) | v2 & 0xFFFFFF;
  *((_DWORD *)dword_51FDC0 + a1) = result;
  return result;
}
