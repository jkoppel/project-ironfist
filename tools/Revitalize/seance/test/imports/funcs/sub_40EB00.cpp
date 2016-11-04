{
  char result; // al@4
  signed int v1; // [sp+10h] [bp-54h]@6

  if ( byte_4EE1AC )
  {
    if ( byte_4EE1AC == 1 )
    {
      if ( sub_473600(6) & 1 )
        v1 = 0;
      else
        v1 = 1;
      if ( !v1 )
      {
        sub_473130(5, 6);
        return 1;
      }
      if ( getTickCount() > dword_4EE1B0 + 500 )
      {
        dword_4EE1B0 = getTickCount();
        sub_473040(0, 0, 0);
      }
    }
    result = 0;
  }
  else
  {
    if ( !sub_473130(3, 6) )
      ++byte_4EE1AC;
    result = 0;
  }
  return result;
}
