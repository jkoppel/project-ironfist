{
  void *result; // eax@3
  char v3; // [sp+Ch] [bp-10h]@1
  signed int v4; // [sp+10h] [bp-Ch]@4
  signed int i; // [sp+14h] [bp-8h]@4
  signed int v6; // [sp+18h] [bp-4h]@4

  v3 = relinquish;
  if ( gbRemoteOn && !gbInNetSetup )
  {
    v4 = 999999999;
    v6 = -1;
    for ( i = 0; i < 128; ++i )
    {
      if ( rcvBuf[i] )
      {
        if ( iInOrder[i] < v4 )
        {
          v4 = iInOrder[i];
          v6 = i;
        }
      }
    }
    if ( v6 < 0 )
    {
      result = 0;
    }
    else
    {
      memcpy(&rcvBufOut, (const void *)rcvBuf[v6], 0x100u);
      if ( v3 )
      {
        BaseFree((void *)rcvBuf[v6], (int)"F:\\h2xsrc\\Source\\REMOTE.CPP", word_512728 + 25);
        rcvBuf[v6] = 0;
      }
      result = &rcvBufOut;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}