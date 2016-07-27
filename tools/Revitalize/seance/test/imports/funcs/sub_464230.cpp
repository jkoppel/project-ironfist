{
  char result; // al@2

  if ( getTickCount() >= dword_52630C + 250 )
  {
    dword_52630C = getTickCount();
    if ( dword_526308 >= (signed int)strlen(byte_525268) )
    {
      sub_4644D0(L"\r", 1);
      result = 1;
    }
    else
    {
      sub_4644D0(&byte_525268[dword_526308++], 1);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
