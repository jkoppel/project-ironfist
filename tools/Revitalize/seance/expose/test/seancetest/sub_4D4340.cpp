int __cdecl sub_4D4340()
{
  int result; // eax@3
  signed int i; // [sp+Ch] [bp-4h]@1

  for ( i = 0; i < 16; ++i )
  {
    result = *((_DWORD *)dword_51FDC0 + i);
    *((_DWORD *)dword_51FDC0 + i + dword_5347A0) = result;
  }
  return result;
}
