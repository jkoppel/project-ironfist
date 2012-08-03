{
  signed int result; // eax@13
  void *v2; // [sp+10h] [bp-8h]@1
  signed int v3; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  PollSound();
  if ( *(_DWORD *)v2 == 512
    && *((_DWORD *)v2 + 1) == 13
    && (*((_DWORD *)v2 + 2) > 0 && *((_DWORD *)v2 + 2) <= 1000 || *((_DWORD *)v2 + 2) == 30721) )
    v3 = 1;
  if ( v3 || giMenuCommand != -1 )
  {
    gpWindowManager->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    if ( giMenuCommand != -1 )
      gpWindowManager->buttonPressedCode = 30721;
    result = 2;
  }
  else
  {
    CheckShingleUpdate();
    result = 1;
  }
  return result;
}