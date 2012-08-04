{
  return !a2 && !*(_DWORD *)this && *(_DWORD *)(this + 4) == 3 && !gpGame->players[a2].numHeroes;
}