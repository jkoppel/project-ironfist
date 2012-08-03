{
  signed int result; // eax@2

  if ( a4 & 1 )
  {
    result = 0;
  }
  else
  {
    LogStr("Sessions:");
    LogInt(a1 + 36, *(_DWORD *)(a1 + 20), -999, -999, -999, -999, -999, -999);
    lSessions[iMaxSession++] = *(_DWORD *)(a1 + 20);
    result = 1;
  }
  return result;
}