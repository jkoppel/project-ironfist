{
  MouseManager *v0; // eax@8
  Palette *result; // eax@49
  Hero *j; // [sp+Ch] [bp-4Ch]@26
  signed int v3; // [sp+10h] [bp-48h]@26
  Castle *i; // [sp+14h] [bp-44h]@23
  signed int v5; // [sp+18h] [bp-40h]@23
  ArmyInfo *v6; // [sp+20h] [bp-38h]@46
  void *v7; // [sp+24h] [bp-34h]@43
  Pathfinder *v8; // [sp+28h] [bp-30h]@40
  TownManager *v9; // [sp+2Ch] [bp-2Ch]@37
  CombatManager *ecx0; // [sp+30h] [bp-28h]@34
  AdvManager *v11; // [sp+34h] [bp-24h]@31
  void *v12; // [sp+38h] [bp-20h]@22
  AbstractManager *v13; // [sp+3Ch] [bp-1Ch]@19
  SoundManager *v14; // [sp+40h] [bp-18h]@16
  ResourceManager *this; // [sp+44h] [bp-14h]@13
  HeroWindowManager *v2; // [sp+48h] [bp-10h]@10
  MouseManager *v17; // [sp+4Ch] [bp-Ch]@7
  int v18; // [sp+50h] [bp-8h]@4
  ManagerManager *v19; // [sp+54h] [bp-4h]@1

  v19 = (ManagerManager *)operator new(0x10u);
  if ( v19 )
    managerManager = ManagerManager_constructor(v19);
  else
    managerManager = 0;
  v18 = (int)operator new(0x86Au);
  if ( v18 )
    inputManager = InputManager_constructor(v18);
  else
    inputManager = 0;
  v17 = (MouseManager *)operator new(0x8Au);
  if ( v17 )
  {
    MouseManager::constructor(v17);
    mouseManager = v0;
  }
  else
  {
    mouseManager = 0;
  }
  v2 = (HeroWindowManager *)operator new(0x62u);
  if ( v2 )
    HeroWindowManager::instance = HeroWindowManager_constructor(v2);
  else
    HeroWindowManager::instance = 0;
  this = (ResourceManager *)operator new(0xA2u);
  if ( this )
    resourceManager = ResourceManager_constructor(this);
  else
    resourceManager = 0;
  v14 = (SoundManager *)operator new(0x6B2u);
  if ( v14 )
    soundManager = SoundManager_constructor(v14);
  else
    soundManager = 0;
  v13 = (AbstractManager *)operator new(0x63u);
  if ( v13 )
    highScoreManager = HighScoreManager_constructor(v13);
  else
    highScoreManager = 0;
  v12 = operator new(0x660Fu);
  if ( v12 )
  {
    MapTiles_constructor((MapTiles *)((char *)v12 + 2878));
    v5 = 72;
    for ( i = (Castle *)((char *)v12 + 2899); ; ++i )
    {
      --v5;
      if ( v5 < 0 )
        break;
      Castle_constructor(i);
    }
    v3 = 54;
    for ( j = (Hero *)((char *)v12 + 10180); ; ++j )
    {
      --v3;
      if ( v3 < 0 )
        break;
      Hero_constructor(j);
    }
    gameObject = (GameInfo *)v12;
  }
  else
  {
    gameObject = 0;
  }
  v11 = (AdvManager *)operator new(894u);
  if ( v11 )
    advManager = AdvManager_constructor(v11);
  else
    advManager = 0;
  ecx0 = (CombatManager *)operator new(0xF877u);
  if ( ecx0 )
    combatManager = CombatManager_constructor(ecx0);
  else
    combatManager = 0;
  v9 = (TownManager *)operator new(0x17Au);
  if ( v9 )
    townManager = TownManager_constructor(v9);
  else
    townManager = 0;
  v8 = (Pathfinder *)operator new(0x2518u);
  if ( v8 )
    pathfinder = Pathfinder_constructor(v8);
  else
    pathfinder = 0;
  v7 = operator new(1u);
  if ( v7 )
    unknownGlobalObject4 = (int)sub_4AA940(v7);
  else
    unknownGlobalObject4 = 0;
  v6 = (ArmyInfo *)operator new(0xFu);
  if ( v6 )
    dword_5247BC = ArmyInfo_constructor(v6);
  else
    dword_5247BC = 0;
  result = (Palette *)operator new(0x14u);
  if ( result )
  {
    result = Palette_constructor(result);
    palette = result;
  }
  else
  {
    palette = 0;
  }
  return result;
}
