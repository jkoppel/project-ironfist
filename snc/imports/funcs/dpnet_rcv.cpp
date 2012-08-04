{
  __int16 result; // ax@2
  int v2; // ST20_4@3

  dpProcessMessages();
  if ( iDPRcvBufferTail == iDPRcvBufferHead )
  {
    result = 0;
  }
  else
  {
    v2 = *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferTail);
    memcpy(a1, *((const void **)ppDPRcvBuffer + iDPRcvBufferTail), *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferTail));
    BaseFree(*((void **)ppDPRcvBuffer + iDPRcvBufferTail), (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED588 + 9);
    iDPRcvBufferTail = (iDPRcvBufferTail + 1) % 200;
    result = v2;
  }
  return result;
}