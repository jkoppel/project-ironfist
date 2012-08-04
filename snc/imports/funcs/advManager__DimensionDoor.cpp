{
  int v1; // [sp+Ch] [bp-24h]@1
  heroWindow *thisa; // [sp+18h] [bp-18h]@1
  int row; // [sp+1Ch] [bp-14h]@7
  mapCell *v4; // [sp+20h] [bp-10h]@7
  int col; // [sp+24h] [bp-Ch]@7
  char *a2; // [sp+28h] [bp-8h]@6
  heroWindow *window; // [sp+2Ch] [bp-4h]@2

  v1 = (int)this;
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    window = heroWindow::heroWindow(thisa, 0, 0, "dimdoor.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  heroWindowManager::DoDialog(gpWindowManager, window, (int (__fastcall *)(tag_message *))DimensionDoorHandler, 0);
  operator delete(window);
  a2 = (char *)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  if ( gpWindowManager->buttonPressedCode == 1 )
  {
    col = *(_DWORD *)(v1 + 470) + *(_DWORD *)(v1 + 486);
    row = *(_DWORD *)(v1 + 474) + *(_DWORD *)(v1 + 490);
    v4 = advManager::GetCell(
           (advManager *)v1,
           *(_DWORD *)(v1 + 470) + *(_DWORD *)(v1 + 486),
           *(_DWORD *)(v1 + 474) + *(_DWORD *)(v1 + 490));
    if ( (!(a2[227] & 0x80) || !giGroundToTerrain[v4->tileType]) && (a2[227] & 0x80 || giGroundToTerrain[v4->tileType]) )
    {
      soundManager::SwitchAmbientMusic(gpSoundManager, 1);
      advManager::TeleportTo((advManager *)v1, (hero *)a2, col, row, 0, 0);
      soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[*(_DWORD *)(v1 + 166)]);
    }
    else
    {
      NormalDialog("Dimension Door failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      advManager::UpdateRadar(v1, 1, 0);
    }
    hero::UseSpell(&gpGame->heroes[gpCurPlayer->curHeroIdx], 56);
  }
  else
  {
    advManager::UpdateRadar(v1, 1, 0);
  }
}