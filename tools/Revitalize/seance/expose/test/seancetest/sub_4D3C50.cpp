int __fastcall sub_4D3C50(int a1, unsigned __int8 a2)
{
  int result; // eax@1

  result = a2 | *((_DWORD *)dword_51FDC0 + a1) & 0xFFFFFF00;
  *((_DWORD *)dword_51FDC0 + a1) = result;
  return result;
}
