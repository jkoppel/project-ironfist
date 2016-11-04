{
  int v4; // [sp+Ch] [bp-8h]@4
  void *v5; // [sp+10h] [bp-4h]@1

  v5 = this;
  if ( *(_DWORD *)a2 == 4 )
    (*(void (__thiscall **)(MouseManager *))(LODWORD(mouseManager->vtable) + 8))(mouseManager);
  sub_4AA7B0(1, a3);
  if ( *(_DWORD *)a2 == 1 )
  {
    v4 = *(_DWORD *)(a2 + 4);
    if ( v4 == 16 )
    {
      if ( *(_BYTE *)(a2 + 12) & 0xC )
      {
        *(_DWORD *)a2 = 16384;
        *(_DWORD *)(a2 + 4) = 1;
        return 2;
      }
    }
    else
    {
      if ( v4 == 60 )
        sub_435F20(0, (void *)0xFFFFFFFF);
    }
  }
  sub_44D440(v5, 0, 1, 1);
  return 0;
}
