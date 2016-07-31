{
  signed int result; // eax@3
  int v7; // [sp+18h] [bp-10h]@5
  char v8; // [sp+1Ch] [bp-Ch]@5
  void *v9; // [sp+20h] [bp-8h]@4
  int v10; // [sp+24h] [bp-4h]@4

  if ( dword_4F7494 && !byte_512594 )
  {
    v9 = 0;
    v10 = sub_46E1D0(a1, a2, a3, a4, 1, 1, -1);
    if ( v10 )
    {
      v7 = getTickCount();
      v8 = 0;
      while ( !v8 )
      {
        if ( getTickCount() > v7 + 90000 )
        {
          display_message_window("Error sending data.  Keep trying??", 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          {
            v10 = 0;
            goto LABEL_17;
          }
          v7 = getTickCount();
        }
        sub_42EF00();
        v9 = sub_46E3F0(1);
        if ( v9 && *((_BYTE *)v9 + 5) == 2 )
        {
          if ( *((_BYTE *)v9 + 6) == a5 )
            v8 = 1;
        }
      }
      *(_DWORD *)a6 = v9;
    }
LABEL_17:
    result = v10;
  }
  else
  {
    result = 1;
  }
  return result;
}
