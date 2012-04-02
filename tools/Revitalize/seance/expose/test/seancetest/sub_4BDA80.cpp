int __thiscall sub_4BDA80(int this)
{
  int v1; // ST0C_4@1
  int result; // eax@1

  v1 = this;
  *(_DWORD *)(this + 82) = -1;
  *(_DWORD *)(v1 + 78) = *(_DWORD *)(v1 + 82);
  *(_DWORD *)(v1 + 86) = *(_DWORD *)(v1 + 78);
  *(_DWORD *)(v1 + 74) = *(_DWORD *)(v1 + 86);
  result = *(_DWORD *)(this + 74);
  *(_DWORD *)(this + 70) = result;
  return result;
}
