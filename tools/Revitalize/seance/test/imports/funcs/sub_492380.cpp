{
  char result; // al@1

  result = (1 << (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7)) | curPlayer->_4[1];
  curPlayer->_4[1] = result;
  return result;
}
