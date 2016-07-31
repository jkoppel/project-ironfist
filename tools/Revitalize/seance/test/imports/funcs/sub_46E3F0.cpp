{
  void *result; // eax@3
  char v2; // [sp+Ch] [bp-10h]@1
  signed int v3; // [sp+10h] [bp-Ch]@4
  signed int i; // [sp+14h] [bp-8h]@4
  signed int v5; // [sp+18h] [bp-4h]@4

  v2 = relinquish;
  if ( dword_4F7494 && !byte_512594 )
  {
    v3 = 999999999;
    v5 = -1;
    for ( i = 0; i < 128; ++i )
    {
      if ( dword_527438[i] )
      {
        if ( dword_526EE0[i] < v3 )
        {
          v3 = dword_526EE0[i];
          v5 = i;
        }
      }
    }
    if ( v5 < 0 )
    {
      result = 0;
    }
    else
    {
      memcpy(&byte_5276F8, (const void *)dword_527438[v5], 0x100u);
      if ( v2 )
      {
        KBFree((void *)dword_527438[v5], (int)"F:\\h2xsrc\\Source\\REMOTE.CPP", word_512728 + 25);
        dword_527438[v5] = 0;
      }
      result = &byte_5276F8;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
