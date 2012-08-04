{
  int v4; // [sp+Ch] [bp-8h]@4
  void *thisa; // [sp+10h] [bp-4h]@1

  thisa = this;
  if ( *(_DWORD *)a2 == 4 )
    (*(void (__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
  CheckDoMain(1, a3);
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
    else if ( v4 == 60 )
    {
      PopNetBox(0, (void *)0xFFFFFFFF);
    }
  }
  advManager::UpdBottomView((advManager *)thisa, 0, 1, 1);
  return 0;
}