{
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  if ( a2 )
  {
    sub_447C20((AdvManager *)this, *(_DWORD *)(this + 470), *(_DWORD *)(this + 474), 0, 1);
    sub_447A00((void *)v2, 0, 0);
    Hero::delete((Hero *)a2, 1);
    sub_48F7F0((void *)v2, 0);
    sub_44AA80(v2, 1, 0);
    AdvManager::heroSelectionGUIStuff((AdvManager *)v2, 1, 1);
  }
}
