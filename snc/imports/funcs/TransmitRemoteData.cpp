{
  int result; // eax@3
  int a2a; // [sp+Ch] [bp-118h]@1
  signed int v9; // [sp+14h] [bp-110h]@4
  _BYTE a1a[5]; // [sp+18h] [bp-10Ch]@4
  char v11; // [sp+1Dh] [bp-107h]@5
  char v12; // [sp+1Eh] [bp-106h]@9
  __int16 v13; // [sp+1Fh] [bp-105h]@9
  char v14; // [sp+21h] [bp-103h]@10
  int i; // [sp+11Ch] [bp-8h]@17
  int v16; // [sp+120h] [bp-4h]@4

  a2a = a2;
  if ( gbRemoteOn && !gbInNetSetup )
  {
    v16 = 0;
    v9 = 0;
    ++iIDCtr;
    a1a[0] = giThisNetPos;
    *(_DWORD *)&a1a[1] = iIDCtr;
    if ( a7 == -1 )
    {
      if ( a5 )
        v11 = 2;
      else
        v11 = 3;
    }
    else
    {
      v11 = a7;
    }
    v13 = a3;
    v12 = a4;
    if ( (signed int)a3 > 0 )
      memcpy(&v14, a1, a3);
    while ( !v16 && v9 <= 25 )
    {
      v16 = SendRemoteData((int)a1a, a2a, a3 + 9);
      if ( !a5 && v16 )
        return 1;
      if ( v16 )
      {
        for ( i = 0; i < 50; ++i )
        {
          ForcePollSound();
          if ( iIDCtr == dword_512578 )
            return 1;
          v16 = 0;
          DelayMilli(20);
        }
      }
      else
      {
        DelayMilli(1000);
      }
      if ( a6 && v9 == 25 && !v16 )
      {
        NormalDialog("Error sending data.  Keep trying??", 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          v9 = -1;
      }
      ++v9;
    }
    result = v16;
  }
  else
  {
    result = 1;
  }
  return result;
}