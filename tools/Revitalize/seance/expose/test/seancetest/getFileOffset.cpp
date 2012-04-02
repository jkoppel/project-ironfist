signed int __cdecl getFileOffset(int a1)
{
  return _lseek(a1, 0, SEEK_CUR);
}
