{
  int result; // eax@2
  int fromlen; // [sp+Ch] [bp-18h]@1
  struct sockaddr from; // [sp+10h] [bp-14h]@2
  int len; // [sp+20h] [bp-4h]@2

  fromlen = 16;
  while ( 1 )
  {
    len = 256;
    result = recvfrom(connectionSocket, buf, 256, 0, &from, &fromlen);
    dword_524F40 = result;
    if ( result == -1 )
    {
      result = WSAGetLastError();
      dword_524F40 = result;
      if ( result == 10035 )
        break;
    }
    if ( !dword_524F40 )
      break;
    if ( *(_DWORD *)&from.sa_data[2] != *((_DWORD *)&dword_522B78 + dword_523F14) )
      sub_45F9C0(dword_524F40, *(int *)&from.sa_data[2]);
  }
  return result;
}
