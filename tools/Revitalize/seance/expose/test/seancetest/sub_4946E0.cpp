int __thiscall sub_4946E0(void *this, __int64 a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  void *thisa; // [sp+10h] [bp-24h]@1
  int v13; // [sp+14h] [bp-20h]@1
  InputEvent v14; // [sp+18h] [bp-1Ch]@1

  thisa = this;
  combatGraphicsOff = 1;
  v13 = dword_524C14;
  dword_524C14 = 0;
  MouseManager::setSpriteIdx(mouseManager, 0);
  mouseManager->field_7E = 1;
  v14.eventCode = 0;
  sub_450880((AdvManager *)thisa);
  sub_474730(combatManager, a2, a3, a4, a5, a6, a7, a2, SHIDWORD(a2), a10);
  CombatManager::initializeArmyAndHeroData(combatManager);
  combatManager->notHandlingInputEvent = 1;
  while ( !combatManager->field_F357 )
    combatManager->vtable->handleInput((AbstractManager *)combatManager, &v14);
  combatGraphicsOff = 0;
  if ( a3 )
    Hero::checkForLevelUp((Hero *)a3);
  if ( a6 )
    Hero::checkForLevelUp((Hero *)a6);
  if ( a11 )
  {
    switch ( combatManager->winningSide + 1 )
    {
      case 1:
        if ( !isRetreating )
          sub_48F450(a6, a3);
        sub_48F630((int)thisa, a6);
        break;
      case 2:
        if ( !isRetreating )
          sub_48F450(a3, a6);
        sub_48F630((int)thisa, a3);
        break;
      case 0:
        sub_48F630((int)thisa, a3);
        sub_48F630((int)thisa, a6);
        break;
      case 4:
        break;
    }
  }
  dword_524C14 = v13;
  if ( dword_524810[curPlayerIdx] )
  {
    sub_485C90(1);
  }
  else
  {
    sub_429420();
    sub_423DE0();
    sub_485C90(0);
  }
  sub_450820((int)thisa, 0);
  if ( a11 )
    isRetreating = 0;
  dword_4F7474 = 0;
  mouseManager->field_7E = 0;
  return combatManager->winningSide;
}
