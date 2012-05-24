{
  CreatureStack *stack; // [sp+2Ch] [bp-44h]@3
  signed int v5; // [sp+38h] [bp-38h]@1
  signed int baseDam; // [sp+3Ch] [bp-34h]@6
  int tick; // [sp+40h] [bp-30h]@1
  unsigned int i; // [sp+44h] [bp-2Ch]@1
  int divergeFreq; // [sp+48h] [bp-28h]@11
  int v10; // [sp+4Ch] [bp-24h]@11
  int a15; // [sp+50h] [bp-20h]@16
  int v12; // [sp+58h] [bp-18h]@18
  signed int endX; // [sp+5Ch] [bp-14h]@11
  signed int startY; // [sp+60h] [bp-10h]@1
  signed int startX; // [sp+64h] [bp-Ch]@1
  signed int endY; // [sp+68h] [bp-8h]@11
  int v17; // [sp+6Ch] [bp-4h]@11

  v5 = 40 * power;
  tick = getTickCount();
  startX = couldBeWandX;
  startY = couldBeWandY;
  zero_out_stack_affected_list();
  MouseManager::disableCursor(mouseManager);
  for ( i = 0; (signed int)i < 4; ++i )
  {
    stack = &this->creatures[this->combatGrid[targetHex].unitOwner][this->combatGrid[targetHex].stackIdx];
    if ( (signed int)i <= 2 && this->combatGrid[targetHex].unitOwner == this->currentActionSide )
      combatManager->field_339D[this->currentActionSide] = 1;
    baseDam = v5;
    if ( stack->creatureIdx == CREATURE_AIR_ELEMENTAL )
      baseDam = 2 * v5;
    if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
      baseDam = (signed __int64)((double)baseDam * 0.5);
    CreatureStack::takeDamage(stack, baseDam, SPELL_NONE);
    v5 >>= 1;
    stack_affected_by_aoe[stack->owningSide][stack->stackIdx] = 1;
    endX = CreatureStack::getCenterX(stack);
    endY = CreatureStack::getCenterY(stack);
    v17 = abs(endX - startX);
    v10 = abs(endY - startY);
    divergeFreq = (signed int)(signed __int64)sqrt((double)(v17 * v17 + v10 * v10)) / 10;
    if ( divergeFreq > 30 )
      divergeFreq = 30;
    if ( divergeFreq < 8 )
      divergeFreq = 8;
    a15 = divergeFreq <= 20 ? 2 : 3;
    CombatManager::drawBolt(
      this,
      0,
      startX,
      startY,
      endX,
      endY,
      0,
      80,
      9,
      2,
      0x12Du,
      10,
      80,
      divergeFreq,
      a15,
      0,
      0,
      i < 1);
    startX = endX;
    startY = endY;
    sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 100.0));
    v12 = CombatManager::findClosestCreature(this, stack, 1);
    if ( v12 == -1 )
      break;
    targetHex = v12;
    CombatManager::drawBattlefield(this, 1, 0, 0, 0, 0, 1, 1);
    sleepUntilPointer(&tick);
    tick = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 100.0);
  }
  CombatManager::animateMultitargetSpellEffect(
    this,
    (char (*)[2][20])stack_affected_by_aoe,
    (unsigned __int8)spell_table[3].creatureEffectAnimationIdx,
    1);
  CombatManager::drawBattlefield(this, 1, 0, 0, 0, 75, 1, 1);
  MouseManager::enableCursor(mouseManager);
}
