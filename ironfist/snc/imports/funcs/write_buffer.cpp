{
  signed int result; // eax@2

  if ( a2 + dword_52636C + 16 <= 2048 )
  {
    com_snd(0, a2, a1, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}