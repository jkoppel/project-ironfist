{
  void *v2; // [sp+Ch] [bp-8h]@1

  v2 = this;
  if ( bsInUse )
    panic();
  bsInUse = 1;
  unk_537938 = v2;
  *((_DWORD *)&unk_537938 + 1) = 0;
  *((_DWORD *)&unk_537938 + 2) = 0;
  *((_BYTE *)&unk_537938 + 12) = 119;
  return &unk_537938;
}