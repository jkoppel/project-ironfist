{
  int v1; // ST3C_4@1
  int v2; // ST2C_4@1
  armyGroup *v3; // ST28_4@1
  hero *v4; // ST20_4@1
  int v5; // eax@1

  v1 = this;
  v2 = *(_DWORD *)(this + 82);
  v3 = (armyGroup *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101);
  v4 = *(hero **)(this + 4 * *(_DWORD *)(this + 70) + 62);
  v5 = armyGroup::GetNumArmies((armyGroup *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101));
  return game::ViewArmy(
           gpGame,
           119,
           20,
           (CREATURES)*(_BYTE *)(*(_DWORD *)(v1 + 4 * *(_DWORD *)(v1 + 70) + 62) + *(_DWORD *)(v1 + 82) + 101),
           *(_WORD *)(*(_DWORD *)(v1 + 4 * *(_DWORD *)(v1 + 70) + 62) + 2 * *(_DWORD *)(v1 + 82) + 106),
           0,
           v5 == 1,
           1u,
           0,
           v4,
           0,
           v3,
           v2);
}