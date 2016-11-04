{
  __int16 result; // ax@5
  void *v3; // [sp+Ch] [bp-10h]@1
  unsigned __int16 v4; // [sp+10h] [bp-Ch]@1
  size_t v5; // [sp+14h] [bp-8h]@3
  int a1a; // [sp+18h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  EnterCriticalSection(&CriticalSection);
  a1a = sub_4BC830((int)&unk_527838);
  LeaveCriticalSection(&CriticalSection);
  if ( a1a )
  {
    if ( *(_WORD *)(a1a + 8) < (signed __int16)v4 )
      v5 = *(_WORD *)(a1a + 8);
    else
      v5 = v4;
    memcpy(v3, (const void *)(a1a + 11), v5);
    KBFree((void *)a1a, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512F7C + 11);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
