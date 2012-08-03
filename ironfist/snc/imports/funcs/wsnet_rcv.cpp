{
  __int16 result; // ax@2
  int v2; // ST20_4@3

  wsProcessMessages();
  if ( iDPRcvBufferTail == iDPRcvBufferHead )
  {
    result = 0;
  }
  else
  {
    v2 = *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferTail);
    memcpy(a1, *((const void **)ppDPRcvBuffer + iDPRcvBufferTail), *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferTail));
    BaseFree(*((void **)ppDPRcvBuffer + iDPRcvBufferTail), (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511CBC + 9);
    iDPRcvBufferTail = (iDPRcvBufferTail + 1) % 200;
    result = v2;
  }
  return result;
}