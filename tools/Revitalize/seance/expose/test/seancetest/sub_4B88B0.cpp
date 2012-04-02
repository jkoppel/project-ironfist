signed int __stdcall sub_4B88B0(int a1)
{
  signed int result; // eax@2

  if ( curPlayer->_4[1] & (1 << (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7)) )
    result = 5000;
  else
    result = 0;
  return result;
}
