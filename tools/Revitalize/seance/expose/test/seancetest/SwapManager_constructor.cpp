int __thiscall SwapManager_constructor(int this, int a2, int a3)
{
  int v3; // ST0C_4@1

  v3 = this;
  AbstractManager_constructor((AbstractManager *)this);
  *(_DWORD *)v3 = &SwapManager_vtable;
  *(_DWORD *)(v3 + 62) = a2;
  *(_DWORD *)(v3 + 66) = a3;
  return v3;
}
