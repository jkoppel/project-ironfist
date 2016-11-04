{
  int result; // eax@1
  int i; // [sp+10h] [bp-4h]@2

  result = *(_DWORD *)(this + 54);
  if ( (1 << a2) & *(_DWORD *)(result + 24) )
  {
    for ( i = 0; ; ++i )
    {
      result = this;
      if ( *(_DWORD *)(this + 190) <= i )
        break;
      if ( *(_DWORD *)(*(_DWORD *)(this + 4 * i + 62) + 12) == a2 )
        *(_DWORD *)(*(_DWORD *)(this + 4 * i + 62) + 8) ^= 1u;
    }
  }
  return result;
}
