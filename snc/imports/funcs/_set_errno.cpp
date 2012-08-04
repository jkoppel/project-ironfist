{
  errno_t result; // eax@1

  result = Value;
  if ( Value == 1 )
  {
    result = (errno_t)_errno();
    *(_DWORD *)result = 33;
  }
  else if ( Value >= 2 )
  {
    if ( Value <= 3 )
    {
      result = (errno_t)_errno();
      *(_DWORD *)result = 34;
    }
  }
  return result;
}