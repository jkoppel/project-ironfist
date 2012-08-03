{
  int v2; // [sp+0h] [bp-14h]@0
  int thisb; // [sp+Ch] [bp-8h]@1
  int track; // [sp+10h] [bp-4h]@6

  thisb = this;
  if ( !gbNoSound && *(_DWORD *)(this + 66) && *(_DWORD *)&Data && *(_DWORD *)(this + 1694) )
  {
    if ( *(_DWORD *)&useCDMusic )
    {
      track = *(_BYTE *)(this + 1404);
      soundManager::CDStop((soundManager *)this);
      *(_BYTE *)(thisb + 1404) = -1;
    }
    else
    {
      track = *(_BYTE *)(this + 1404);
      soundManager::MIDIStop(this);
    }
    memset((void *)(thisb + 1428), 0, 0xF0u);
    *(_DWORD *)&useCDMusic = a2;
    if ( track >= 0 )
      soundManager::PlayAmbientMusic((soundManager *)thisb, track, 0, -1, v2);
  }
}