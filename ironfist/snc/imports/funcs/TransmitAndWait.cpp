{
  signed int result; // eax@3
  int v7; // edx@11
  int v8; // [sp+18h] [bp-10h]@5
  char v9; // [sp+1Ch] [bp-Ch]@5
  void *v10; // [sp+20h] [bp-8h]@4
  int v11; // [sp+24h] [bp-4h]@4

  if ( gbRemoteOn && !gbInNetSetup )
  {
    v10 = 0;
    v11 = TransmitRemoteData(a1, a2, a3, a4, 1, 1, -1);
    if ( v11 )
    {
      v8 = KBTickCount();
      v9 = 0;
      while ( !v9 )
      {
        if ( KBTickCount() > v8 + 90000 )
        {
          NormalDialog("Error sending data.  Keep trying??", 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( gpWindowManager->buttonPressedCode != 30725 )
          {
            v11 = 0;
            goto LABEL_17;
          }
          v8 = KBTickCount();
        }
        ForcePollSound();
        v10 = GetRemoteData(1, v7);
        if ( v10 && *((_BYTE *)v10 + 5) == 2 )
        {
          if ( *((_BYTE *)v10 + 6) == a5 )
            v9 = 1;
        }
      }
      *(_DWORD *)a6 = v10;
    }
LABEL_17:
    result = v11;
  }
  else
  {
    result = 1;
  }
  return result;
}