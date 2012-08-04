{
  if ( a1 < (unsigned int)_iob || a1 > (unsigned int)&unk_521A98 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 32));
  else
    _unlock(((signed int)(a1 - (_DWORD)_iob) >> 5) + 28);
}