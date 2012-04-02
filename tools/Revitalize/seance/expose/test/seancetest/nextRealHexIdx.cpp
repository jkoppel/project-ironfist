void __stdcall nextRealHexIdx(int *hexIdx)
{
  if ( (*hexIdx + 2) % 13 )
    ++*hexIdx;
  else
    *hexIdx += 3;
}
