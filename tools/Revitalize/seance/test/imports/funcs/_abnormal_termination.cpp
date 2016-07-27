{
  signed int result; // eax@1

  result = 0;
  if ( *(signed int (__cdecl **)(int, int, int, int))(this + 4) == _unwind_handler )
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(*(_DWORD *)(this + 12) + 12) )
      result = 1;
  }
  return result;
}
