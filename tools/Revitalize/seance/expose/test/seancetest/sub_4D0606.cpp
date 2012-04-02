signed int __cdecl sub_4D0606(void *a1, unsigned int castleIdx)
{
  signed int result; // eax@1

  result = 1 << (castleIdx & 7);
  *(_DWORD *)((char *)a1 + (castleIdx >> 3)) |= result;
  return result;
}
