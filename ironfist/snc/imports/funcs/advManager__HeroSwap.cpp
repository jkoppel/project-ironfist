{
  void *v3; // [sp+Ch] [bp-14h]@1
  tag_message *v4; // [sp+18h] [bp-8h]@1
  baseManager *a2a; // [sp+1Ch] [bp-4h]@2

  v3 = this;
  v4 = (tag_message *)operator new(90);
  if ( v4 )
    a2a = (baseManager *)swapManager::swapManager(v4);
  else
    a2a = 0;
  if ( !a2a )
    MemError();
  executive::DoDialog(gpExec, a2a);
  operator delete(a2a);
  advManager::RedrawAdvScreen(v3, 1, 0);
}