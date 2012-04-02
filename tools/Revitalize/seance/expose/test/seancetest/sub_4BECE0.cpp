int __thiscall sub_4BECE0(int this)
{
  int v1; // ST3C_4@1
  int v2; // ST2C_4@1
  ArmyInfo *v3; // ST28_4@1
  Hero *v4; // ST20_4@1
  int v5; // eax@1

  v1 = this;
  v2 = *(_DWORD *)(this + 82);
  v3 = (ArmyInfo *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101);
  v4 = *(Hero **)(this + 4 * *(_DWORD *)(this + 70) + 62);
  v5 = ArmyInfo::getNumStacks((ArmyInfo *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101));
  return GameInfo::showStackInfo(
           gameObject,
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
