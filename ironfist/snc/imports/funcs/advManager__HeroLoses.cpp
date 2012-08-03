{
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  if ( a2 )
  {
    advManager::CompleteDraw((advManager *)this, *(_DWORD *)(this + 470), *(_DWORD *)(this + 474), 0, 1);
    advManager::UpdateScreen((advManager *)v2, 0, 0);
    hero::Deallocate((hero *)a2, 1);
    advManager::FizzleCenter((void *)v2, 0);
    advManager::UpdateRadar(v2, 1, 0);
    advManager::UpdateHeroLocators((advManager *)v2, 1, 1);
  }
}