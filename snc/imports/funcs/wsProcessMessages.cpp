{
  int result; // eax@2
  int fromlen; // [sp+Ch] [bp-18h]@1
  struct sockaddr from; // [sp+10h] [bp-14h]@2
  int len; // [sp+20h] [bp-4h]@2

  fromlen = 16;
  while ( 1 )
  {
    len = 256;
    result = thunk_recvfrom(sd_dg, rcvBufIn, 256, 0, &from, &fromlen);
    iRc = result;
    if ( result == -1 )
    {
      result = thunk_WSAGetLastError();
      iRc = result;
      if ( result == 10035 )
        break;
    }
    if ( !iRc )
      break;
    if ( *(_DWORD *)&from.sa_data[2] != *((_DWORD *)&giNetPosToDCOPos + giThisNetPos) )
      wsEvaluateMessage(iRc, *(int *)&from.sa_data[2]);
  }
  return result;
}