{
  BOOL result; // eax@2

  if ( a1 )
  {
    free(*(_DWORD *)(a1 + 4));
    free(*(_DWORD *)(a1 + 8));
    free(*(_DWORD *)(a1 + 12));
    free(*(_DWORD *)(a1 + 16));
    free(*(_DWORD *)(a1 + 20));
    free(*(_DWORD *)(a1 + 24));
    free(*(_DWORD *)a1);
    free(*(_DWORD *)(a1 + 32));
    free(*(_DWORD *)(a1 + 36));
    free(*(_DWORD *)(a1 + 40));
    free(*(_DWORD *)(a1 + 44));
    free(*(_DWORD *)(a1 + 48));
    free(*(_DWORD *)(a1 + 52));
    free(*(_DWORD *)(a1 + 28));
    free(*(_DWORD *)(a1 + 56));
    free(*(_DWORD *)(a1 + 60));
    free(*(_DWORD *)(a1 + 64));
    free(*(_DWORD *)(a1 + 68));
    free(*(_DWORD *)(a1 + 72));
    free(*(_DWORD *)(a1 + 76));
    free(*(_DWORD *)(a1 + 80));
    free(*(_DWORD *)(a1 + 84));
    free(*(_DWORD *)(a1 + 88));
    free(*(_DWORD *)(a1 + 92));
    free(*(_DWORD *)(a1 + 96));
    free(*(_DWORD *)(a1 + 100));
    free(*(_DWORD *)(a1 + 104));
    free(*(_DWORD *)(a1 + 108));
    free(*(_DWORD *)(a1 + 112));
    free(*(_DWORD *)(a1 + 116));
    free(*(_DWORD *)(a1 + 120));
    free(*(_DWORD *)(a1 + 124));
    free(*(_DWORD *)(a1 + 128));
    free(*(_DWORD *)(a1 + 132));
    free(*(_DWORD *)(a1 + 136));
    free(*(_DWORD *)(a1 + 140));
    free(*(_DWORD *)(a1 + 144));
    free(*(_DWORD *)(a1 + 148));
    free(*(_DWORD *)(a1 + 152));
    free(*(_DWORD *)(a1 + 156));
    free(*(_DWORD *)(a1 + 160));
    free(*(_DWORD *)(a1 + 164));
    result = free(*(_DWORD *)(a1 + 168));
  }
  return result;
}
