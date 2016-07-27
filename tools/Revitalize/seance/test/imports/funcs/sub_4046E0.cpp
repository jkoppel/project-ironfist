{
  signed int result; // eax@2

  if ( a4 & 1 )
  {
    result = 0;
  }
  else
  {
    debugLog("Sessions:");
    logUpTo7Ints(a1 + 36, *(_DWORD *)(a1 + 20), -999, -999, -999, -999, -999, -999);
    dword_522BA0[dword_522B94++] = *(_DWORD *)(a1 + 20);
    result = 1;
  }
  return result;
}
