signed int __stdcall sub_4B6A60(int a1, int a2)
{
  signed int result; // eax@3

  if ( *(_BYTE *)(a2 + a1 + 116) || *(_DWORD *)(a1 + 144) >= 8 )
    result = 0;
  else
    result = sub_4B6840(a1, a2, 1);
  return result;
}
