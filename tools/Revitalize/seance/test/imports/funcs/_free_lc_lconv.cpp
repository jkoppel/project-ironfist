{
  BOOL result; // eax@2

  if ( a1 )
  {
    result = *(_DWORD *)(a1 + 12);
    if ( (_UNKNOWN *)result != &unk_5226B4 )
    {
      free(*(_DWORD *)(a1 + 12));
      free(*(_DWORD *)(a1 + 16));
      free(*(_DWORD *)(a1 + 20));
      free(*(_DWORD *)(a1 + 24));
      free(*(_DWORD *)(a1 + 28));
      free(*(_DWORD *)(a1 + 32));
      result = free(*(_DWORD *)(a1 + 36));
    }
  }
  return result;
}
