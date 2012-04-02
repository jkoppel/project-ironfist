int __fastcall sub_4D3B40(int a1, unsigned __int16 a2)
{
  int result; // eax@1

  result = a2 | *((_DWORD *)dword_51FDC0 + a1) & 0xFFFF0000;
  *((_DWORD *)dword_51FDC0 + a1) = result;
  return result;
}
