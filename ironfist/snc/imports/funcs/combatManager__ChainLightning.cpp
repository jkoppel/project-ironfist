{
  int v3; // ebx@0
  double v4; // st6@0
  int v5; // ST50_4@19
  army *stack; // [sp+2Ch] [bp-44h]@3
  signed int v8; // [sp+38h] [bp-38h]@1
  signed int baseDam; // [sp+3Ch] [bp-34h]@6
  int tick; // [sp+40h] [bp-30h]@1
  unsigned int i; // [sp+44h] [bp-2Ch]@1
  int divergeFreq; // [sp+48h] [bp-28h]@11
  int v13; // [sp+4Ch] [bp-24h]@11
  int a15; // [sp+50h] [bp-20h]@16
  int v15; // [sp+58h] [bp-18h]@18
  signed int endX; // [sp+5Ch] [bp-14h]@11
  signed int startY; // [sp+60h] [bp-10h]@1
  signed int startX; // [sp+64h] [bp-Ch]@1
  signed int endY; // [sp+68h] [bp-8h]@11
  int v20; // [sp+6Ch] [bp-4h]@11

  v8 = 40 * power;
  tick = KBTickCount();
  startX = castX;
  startY = castY;
  combatManager::ClearEffects();
  mouseManager::HideColorPointer(gpMouseManager);
  for ( i = 0; (signed int)i < 4; ++i )
  {
    stack = &this->creatures[this->combatGrid[targetHex].unitOwner][this->combatGrid[targetHex].stackIdx];
    if ( (signed int)i <= 2 && this->combatGrid[targetHex].unitOwner == this->currentActionSide )
      gpCombatManager->field_339D[this->currentActionSide] = 1;
    baseDam = v8;
    if ( stack->creatureIdx == CREATURE_AIR_ELEMENTAL )
      baseDam = 2 * v8;
    if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
      baseDam = (signed __int64)((double)baseDam * 0.5);
    army::Damage(stack, baseDam, SPELL_NONE);
    v8 >>= 1;
    gArmyEffected[stack->owningSide][stack->stackIdx] = 1;
    endX = army::MidX(stack);
    endY = army::MidY(stack);
    v20 = abs(endX - startX);
    v13 = abs(endY - startY);
    divergeFreq = (signed int)(signed __int64)sqrt((double)(v20 * v20 + v13 * v13)) / 10;
    if ( divergeFreq > 30 )
      divergeFreq = 30;
    if ( divergeFreq < 8 )
      divergeFreq = 8;
    a15 = divergeFreq <= 20 ? 2 : 3;
    combatManager::DoBolt(
      this,
      v3,
      v4,
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
    DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 100.0));
    v15 = combatManager::GetNextChainLightningTarget(this, stack, 1);
    if ( v15 == -1 )
      break;
    targetHex = v15;
    combatManager::DrawFrame(this, 1, 0, 0, 0, 0, 1, 1);
    DelayTil(&tick);
    v5 = KBTickCount();
    v4 = gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 100.0;
    tick = (signed __int64)((double)v5 + v4);
  }
  combatManager::ShowMassSpell(
    this,
    (char (*)[2][20])gArmyEffected,
    (unsigned __int8)gsSpellInfo[3].creatureEffectAnimationIdx,
    1);
  combatManager::DrawFrame(this, 1, 0, 0, 0, 75, 1, 1);
  mouseManager::ShowColorPointer(gpMouseManager);
}