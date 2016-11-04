{
  signed int result; // eax@2

  if ( curPlayer->_4[1] & (1 << (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7)) )
    result = 1;
  else
    result = 0;
  return result;
}
