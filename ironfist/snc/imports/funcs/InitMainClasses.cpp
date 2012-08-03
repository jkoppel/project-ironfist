{
  mouseManager *v0; // eax@8
  palette *result; // eax@49
  hero *j; // [sp+Ch] [bp-4Ch]@26
  signed int v3; // [sp+10h] [bp-48h]@26
  town *i; // [sp+14h] [bp-44h]@23
  signed int v5; // [sp+18h] [bp-40h]@23
  armyGroup *v6; // [sp+20h] [bp-38h]@46
  void *v7; // [sp+24h] [bp-34h]@43
  searchArray *v8; // [sp+28h] [bp-30h]@40
  townManager *v9; // [sp+2Ch] [bp-2Ch]@37
  combatManager *ecx0; // [sp+30h] [bp-28h]@34
  advManager *v11; // [sp+34h] [bp-24h]@31
  LPVOID v12; // [sp+38h] [bp-20h]@22
  baseManager *v13; // [sp+3Ch] [bp-1Ch]@19
  soundManager *v14; // [sp+40h] [bp-18h]@16
  resourceManager *this; // [sp+44h] [bp-14h]@13
  heroWindowManager *v2; // [sp+48h] [bp-10h]@10
  mouseManager *v17; // [sp+4Ch] [bp-Ch]@7
  int v18; // [sp+50h] [bp-8h]@4
  executive *v19; // [sp+54h] [bp-4h]@1

  v19 = (executive *)operator new(16);
  if ( v19 )
    gpExec = executive::executive(v19);
  else
    gpExec = 0;
  v18 = (int)operator new(2154);
  if ( v18 )
    gpInputManager = inputManager::inputManager(v18);
  else
    gpInputManager = 0;
  v17 = (mouseManager *)operator new(138);
  if ( v17 )
  {
    mouseManager::mouseManager(v17);
    gpMouseManager = v0;
  }
  else
  {
    gpMouseManager = 0;
  }
  v2 = (heroWindowManager *)operator new(98);
  if ( v2 )
    gpWindowManager = heroWindowManager::heroWindowManager(v2);
  else
    gpWindowManager = 0;
  this = (resourceManager *)operator new(162);
  if ( this )
    gpResourceManager = resourceManager::resourceManager(this);
  else
    gpResourceManager = 0;
  v14 = (soundManager *)operator new(1714);
  if ( v14 )
    gpSoundManager = soundManager::soundManager(v14);
  else
    gpSoundManager = 0;
  v13 = (baseManager *)operator new(99);
  if ( v13 )
    gpHighScoreManager = highScoreManager::highScoreManager(v13);
  else
    gpHighScoreManager = 0;
  v12 = operator new(26127);
  if ( v12 )
  {
    fullMap::fullMap((fullMap *)((char *)v12 + 2878));
    v5 = 72;
    for ( i = (town *)((char *)v12 + 2899); ; ++i )
    {
      --v5;
      if ( v5 < 0 )
        break;
      town::town(i);
    }
    v3 = 54;
    for ( j = (hero *)((char *)v12 + 10180); ; ++j )
    {
      --v3;
      if ( v3 < 0 )
        break;
      hero::hero(j);
    }
    gpGame = (game *)v12;
  }
  else
  {
    gpGame = 0;
  }
  v11 = (advManager *)operator new(894);
  if ( v11 )
    gpAdvManager = advManager::advManager(v11);
  else
    gpAdvManager = 0;
  ecx0 = (combatManager *)operator new(63607);
  if ( ecx0 )
    gpCombatManager = combatManager::combatManager(ecx0);
  else
    gpCombatManager = 0;
  v9 = (townManager *)operator new(0x17Au);
  if ( v9 )
    gpTownManager = townManager::townManager(v9);
  else
    gpTownManager = 0;
  v8 = (searchArray *)operator new(0x2518u);
  if ( v8 )
    gpSearchArray = searchArray::searchArray(v8);
  else
    gpSearchArray = 0;
  v7 = operator new(1);
  if ( v7 )
    gpPhilAI = (int)philAI::philAI(v7);
  else
    gpPhilAI = 0;
  v6 = (armyGroup *)operator new(15);
  if ( v6 )
    gpMonGroup = armyGroup::armyGroup(v6);
  else
    gpMonGroup = 0;
  result = (palette *)operator new(20);
  if ( result )
  {
    result = palette::palette(result);
    gpBufferPalette = result;
  }
  else
  {
    gpBufferPalette = 0;
  }
  return result;
}