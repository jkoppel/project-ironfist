signed int __cdecl remove(LPCSTR lpFileName)
{
  char v1; // zf@1
  unsigned __int32 v2; // eax@1
  signed int result; // eax@4

  v1 = DeleteFileA(lpFileName) == 0;
  v2 = 0;
  if ( v1 )
    v2 = GetLastError();
  if ( v2 )
  {
    _dosmaperr(v2);
    result = -1;
  }
  else
  {
    result = 0;
  }
  return result;
}
