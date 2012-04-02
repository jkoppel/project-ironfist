__int16 __stdcall sub_426CB0(int a1)
{
  __int16 result; // ax@1

  result = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F;
  if ( (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F) == 4 )
  {
    result = 8 * (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F) | *(_WORD *)(a1 + 4) & 7;
    *(_WORD *)(a1 + 4) = result;
  }
  return result;
}
