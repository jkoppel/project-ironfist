void __cdecl _lock_file(unsigned int a1)
{
  if ( a1 < (unsigned int)&off_521838 || a1 > (unsigned int)&unk_521A98 )
    EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 32));
  else
    _lock(((signed int)(a1 - (_DWORD)&off_521838) >> 5) + 28);
}
