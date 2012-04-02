int __thiscall sub_4BD9B0(int this)
{
  int v1; // ST0C_4@1

  v1 = this;
  AbstractManager_constructor((AbstractManager *)this);
  *(_DWORD *)v1 = &SwapManager_vtable;
  *(_DWORD *)(v1 + 54) = 0;
  *(_DWORD *)(v1 + 58) = 0;
  *(_DWORD *)(v1 + 70) = -1;
  *(_DWORD *)(v1 + 74) = -1;
  *(_DWORD *)(v1 + 86) = -1;
  *(_DWORD *)(v1 + 78) = -1;
  *(_DWORD *)(v1 + 82) = -1;
  *(_DWORD *)(v1 + 62) = 0;
  *(_DWORD *)(v1 + 66) = 0;
  return v1;
}
