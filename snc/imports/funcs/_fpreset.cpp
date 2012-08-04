{
  int v0; // [sp+8h] [bp+4h]@0

  if ( v0 )
  {
    if ( *(_UNKNOWN **)(v0 + 12) != &unk_5226B4 )
    {
      free(*(_DWORD *)(v0 + 12));
      free(*(_DWORD *)(v0 + 16));
      free(*(_DWORD *)(v0 + 20));
      free(*(_DWORD *)(v0 + 24));
      free(*(_DWORD *)(v0 + 28));
      free(*(_DWORD *)(v0 + 32));
      free(*(_DWORD *)(v0 + 36));
    }
  }
}