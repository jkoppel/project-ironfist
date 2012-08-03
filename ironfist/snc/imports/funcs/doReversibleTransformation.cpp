{
  int i; // [sp+Ch] [bp-4h]@3

  if ( veryVerbose )
  {
    sprintf(gText, L" ");
    LogStr(gText);
  }
  sortIt();
  origPtr = -1;
  for ( i = 0; last >= i; ++i )
  {
    if ( !*((_DWORD *)zptr + i) )
    {
      origPtr = i;
      break;
    }
  }
  if ( origPtr == -1 )
    panic();
}