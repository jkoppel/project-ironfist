{
  signed int result; // eax@3

  if ( *(_BYTE *)(a2 + a1 + 116) || *(_DWORD *)(a1 + 144) >= 8 )
    result = 0;
  else
    result = philAI::ComputeValueOfSS(a1, a2, 1);
  return result;
}