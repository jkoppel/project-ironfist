signed int __cdecl sub_4D05D8(int a1, unsigned int a2)
{
  signed int result; // eax@2

  if ( *(_DWORD *)((a2 >> 3) + a1) & (1 << (a2 & 7)) )
    result = 1;
  else
    result = 0;
  return result;
}
