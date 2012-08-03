{
  signed int result; // eax@1

  result = this;
  if ( *(_DWORD *)(this + 4) != -1 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 4) + this + 20) = 1;
    sprintf(gText, "%s_%d", xShortCampaignNames[*(_DWORD *)this], *(_DWORD *)(this + 4) + 1);
    result = game::SaveGame(gpGame, gText, 1, 0);
  }
  return result;
}