void __thiscall CombatManager::castElementalAOE(CombatManager *this, int hexIdx, Spell spell)
{
  CombatManager *thisa; // [sp+14h] [bp-54h]@1
  signed int v4; // [sp+18h] [bp-50h]@3
  CreatureStack *stack; // [sp+20h] [bp-48h]@14
  signed int dam; // [sp+24h] [bp-44h]@37
  int y; // [sp+28h] [bp-40h]@2
  int neighborIdx; // [sp+2Ch] [bp-3Ch]@8
  signed int neighborIdxa; // [sp+2Ch] [bp-3Ch]@14
  signed int neighborIdxb; // [sp+2Ch] [bp-3Ch]@19
  signed int neighborIdxc; // [sp+2Ch] [bp-3Ch]@30
  __int16 affectedHexes[19]; // [sp+30h] [bp-38h]@16
  int damage; // [sp+58h] [bp-10h]@30
  int x; // [sp+5Ch] [bp-Ch]@2
  Icon *res; // [sp+60h] [bp-8h]@4
  int anyoneDamaged; // [sp+64h] [bp-4h]@30

  thisa = this;
  if ( checkHexGridIdxBounds(hexIdx) )
  {
    x = thisa->combatGrid[hexIdx].centerX;
    y = thisa->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    if ( !combatGraphicsOff )
    {
      v4 = 12;
      if ( spell )
      {
        if ( spell == SPELL_FIREBLAST )
        {
          res = ResourceManager::getIconByFilename(resourceManager, "firebal2.icn");
        }
        else
        {
          res = ResourceManager::getIconByFilename(resourceManager, "coldring.icn");
          v4 = 7;
        }
      }
      else
      {
        res = ResourceManager::getIconByFilename(resourceManager, "fireball.icn");
      }
      for ( neighborIdx = 0; v4 > neighborIdx; ++neighborIdx )
      {
        animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                  + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 75.0);
        rasterize(res, HeroWindowManager::instance->screenBuffer, x, y, neighborIdx, 1, 0, 0, 0x280u, 443, 0);
        if ( spell == SPELL_COLD_RING )
          rasterizeMirrored(res, HeroWindowManager::instance->screenBuffer, x, y, neighborIdx, 1, 0, 0, 640, 443, 0);
        sub_4C3D60(thisa);
        CombatManager::drawBattlefield(thisa, 0, 0, 0, 0, 75, 1, 1);
        sleepUntilPointer(&animationFrameSwitchTime);
      }
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
    }
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
    stack = &thisa->creatures[thisa->currentActionSide][thisa->someSortOfStackIdx];
    for ( neighborIdxa = 0; neighborIdxa < 19; ++neighborIdxa )
      affectedHexes[neighborIdxa] = -1;
    if ( spell != SPELL_COLD_RING )
      affectedHexes[0] = hexIdx;
    for ( neighborIdxb = 0; neighborIdxb < 6; ++neighborIdxb )
    {
      affectedHexes[neighborIdxb + 1] = getHexNeighbor(hexIdx, neighborIdxb);
      if ( spell == SPELL_FIREBLAST )
        affectedHexes[neighborIdxb + 7] = CreatureStack::getHexNeighbor(
                                            stack,
                                            affectedHexes[neighborIdxb + 1],
                                            neighborIdxb);
    }
    if ( spell == SPELL_FIREBLAST )
    {
      affectedHexes[13] = hexIdx - 26;
      if ( (signed __int16)(hexIdx - 26) < 0 )
        affectedHexes[13] = -1;
      affectedHexes[14] = hexIdx + 26;
      if ( (signed __int16)(hexIdx + 26) >= 117 )
        affectedHexes[14] = -1;
      affectedHexes[15] = getHexNeighbor(affectedHexes[2], 0);
      affectedHexes[16] = getHexNeighbor(affectedHexes[2], 2);
      affectedHexes[17] = getHexNeighbor(affectedHexes[5], 5);
      affectedHexes[18] = getHexNeighbor(affectedHexes[5], 3);
    }
    damage = 10 * thisa->heroSpellpowers[thisa->currentActionSide];
    zero_out_stack_affected_list();
    anyoneDamaged = 0;
    for ( neighborIdxc = 0; neighborIdxc < 19; ++neighborIdxc )
    {
      if ( affectedHexes[neighborIdxc] != -1 )
      {
        if ( thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner != -1 )
        {
          stack = &thisa->creatures[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx];
          if ( CreatureStack::rollSpellSucceeds(stack, spell) )
          {
            if ( !stack_affected_by_aoe[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx] )
            {
              stack_affected_by_aoe[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx] = 1;
              if ( !stack->damageTakenDuringSomeTimePeriod )
              {
                dam = damage;
                if ( spell == SPELL_COLD_RING && stack->creatureIdx == CREATURE_FIRE_ELEMENTAL )
                  dam = 2 * damage;
                if ( (!spell || spell == 1) && stack->creatureIdx == CREATURE_WATER_ELEMENTAL )
                  dam *= 2;
                if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
                  dam = (signed __int64)((double)dam * 0.5);
                CreatureStack::takeDamage(stack, dam, spell);
                anyoneDamaged = 1;
              }
            }
          }
        }
      }
    }
    if ( anyoneDamaged )
    {
      modifySpellDamageForArtifacts(
        &damage,
        spell,
        thisa->heroes[thisa->currentActionSide],
        thisa->heroes[1 - thisa->currentActionSide]);
      if ( spell == SPELL_COLD_RING )
        sprintf(globBuf, "The cold ring does %d damage.", damage);
      else
        sprintf(globBuf, "The fireball does %d damage.", damage);
      CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
      CreatureStack::doAttackAndDamageTakenAnimations(stack, -1, 1, -1, -1);
    }
  }
}
