{
  int this; // [sp+Ch] [bp-4h]@1

  this = ecx0;
  if ( !gbNoSound
    && *(_DWORD *)(ecx0 + 1694)
    && *(_DWORD *)&Data
    && CDPlaying
    && (signed int)*(_BYTE *)(ecx0 + 1404) >= 0
    && bMusicIsLooping[*(_BYTE *)(ecx0 + 1404)]
    && KBTickCount() >= *(_DWORD *)(ecx0 + 1710) + 3000 )
  {
    *(_DWORD *)(this + 1710) = KBTickCount();
    if ( !soundManager::CDIsPlaying((soundManager *)this) )
      soundManager::CDPlay((soundManager *)this, *(_DWORD *)(this + 1684), 0, -1, 1);
  }
}