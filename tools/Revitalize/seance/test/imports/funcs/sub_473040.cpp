{
  signed __int16 result; // ax@3
  void *v4; // eax@6
  int v5; // ST20_4@6
  __int16 v6; // [sp+Ch] [bp-Ch]@1
  char v7; // [sp+10h] [bp-8h]@1

  v6 = a2;
  v7 = a1;
  if ( (unsigned __int8)byte_512EBC != a1 || a2 )
  {
    if ( byte_512EC4[a1] & 1 )
    {
      v4 = KBAlloc(a2 + 11, "F:\\h2xsrc\\Source\\netwin.cpp", word_512F9C + 15);
      v5 = (int)v4;
      *((_WORD *)v4 + 4) = v6;
      *((_BYTE *)v4 + 10) = v7;
      memcpy((char *)v4 + 11, a3, v6);
      EnterCriticalSection(&stru_52FAD8);
      sub_4BC7B0((int)&unk_527848, v5);
      LeaveCriticalSection(&stru_52FAD8);
      SetEvent(dword_527810);
      result = 0;
    }
    else
    {
      result = 8;
    }
  }
  else
  {
    sub_4738A0();
    result = 0;
  }
  return result;
}
