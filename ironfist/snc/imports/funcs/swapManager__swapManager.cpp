{
  int v1; // ST0C_4@1
  int v3; // [sp+18h] [bp+8h]@0
  int v4; // [sp+1Ch] [bp+Ch]@0

  v1 = (int)this;
  baseManager::baseManager((baseManager *)this);
  *(_DWORD *)v1 = &swapManager::_vftable_;
  *(_DWORD *)(v1 + 62) = v3;
  *(_DWORD *)(v1 + 66) = v4;
  return v1;
}