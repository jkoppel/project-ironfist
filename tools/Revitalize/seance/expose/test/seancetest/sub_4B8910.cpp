signed int __stdcall sub_4B8910(int a1)
{
  signed int result; // eax@2

  if ( curPlayer->_4[1] & (1 << (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7)) )
    result = 0;
  else
    result = 2500;
  return result;
}
