void __userpurge CombatManager::doStraightRayGraphics(CombatManager *this<ecx>, char a2<bl>, int hexIdx, Spell spell)
{
  CombatManager *thisa; // [sp+34h] [bp-5Ch]@1
  H2RECT rect; // [sp+38h] [bp-58h]@6
  int v6; // [sp+48h] [bp-48h]@2
  int v7; // [sp+4Ch] [bp-44h]@4
  Icon *icn; // [sp+50h] [bp-40h]@2
  CreatureStack *stack; // [sp+54h] [bp-3Ch]@4
  int v10; // [sp+58h] [bp-38h]@4
  int v11; // [sp+5Ch] [bp-34h]@4
  int t; // [sp+60h] [bp-30h]@4
  int v13; // [sp+64h] [bp-2Ch]@4
  int i; // [sp+68h] [bp-28h]@4
  float v15; // [sp+6Ch] [bp-24h]@4
  float v16; // [sp+70h] [bp-20h]@4
  int yCent; // [sp+74h] [bp-1Ch]@4
  int imageIdx; // [sp+78h] [bp-18h]@6
  int xCent; // [sp+7Ch] [bp-14h]@4
  float v20; // [sp+80h] [bp-10h]@4
  int v21; // [sp+84h] [bp-Ch]@4
  float v22; // [sp+88h] [bp-8h]@4
  int yDiff; // [sp+8Ch] [bp-4h]@4

  thisa = this;
  if ( spell == SPELL_COLD_RAY )
  {
    icn = ResourceManager::getIconByFilename(resourceManager, "coldray.icn");
    v6 = 18;
  }
  else
  {
    icn = ResourceManager::getIconByFilename(resourceManager, "disrray.icn");
    v6 = 24;
  }
  stack = &thisa->creatures[thisa->combatGrid[hexIdx].unitOwner][thisa->combatGrid[hexIdx].stackIdx];
  xCent = CreatureStack::getCenterX(stack);
  yCent = CreatureStack::getCenterY(stack);
  v21 = couldBeWandX;
  v10 = couldBeWandY;
  v11 = xCent - couldBeWandX;
  yDiff = yCent - couldBeWandY;
  v7 = (signed __int64)sqrt((double)(yDiff * yDiff + (xCent - couldBeWandX) * (xCent - couldBeWandX)));
  v13 = v7 / v6;
  v16 = (double)v21;
  v15 = (double)v10;
  v22 = (double)v11 / (double)(v7 / v6);
  v20 = (double)yDiff / (double)(v7 / v6);
  t = 0;
  for ( i = 0; i < v13; ++i )
  {
    CombatManager::resetStuffHapenedToCreature(thisa);
    dword_4F7480 = 1;
    dword_4F7484 = 1;
    v16 = v16 + v22;
    v15 = v15 + v20;
    imageIdx = (10 * i - 1) / v13;
    Icon::drawToScreenAndSetRectBounds(
      icn,
      (signed __int64)v16,
      (signed __int64)v15,
      (10 * i - 1) / v13,
      &rect,
      v22 < 0.0,
      0,
      0,
      0);
    if ( combatScreenRedrawRectLeft < 0 )
      combatScreenRedrawRectLeft = 0;
    if ( combatScreenRedrawRectTop < 0 )
      combatScreenRedrawRectTop = 0;
    if ( combatScreenRedrawRectRight > 639 )
      combatScreenRedrawRectRight = 639;
    if ( combatScreenRedrawRectBot > 442 )
      combatScreenRedrawRectBot = 442;
    sleepUntilPointer(&t);
    t = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 10.0);
    HeroWindowManager::redrawRectangle(
      HeroWindowManager::instance,
      combatScreenRedrawRectLeft,
      combatScreenRedrawRectTop,
      combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
      combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
  }
  dword_4F7480 = 0;
  dword_4F7484 = 0;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 0, 1, 0);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)icn);
}
