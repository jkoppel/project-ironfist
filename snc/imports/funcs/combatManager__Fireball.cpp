{
  combatManager *thisa; // [sp+14h] [bp-54h]@1
  signed int v4; // [sp+18h] [bp-50h]@3
  army *stack; // [sp+20h] [bp-48h]@14
  signed int dam; // [sp+24h] [bp-44h]@37
  int y; // [sp+28h] [bp-40h]@2
  int neighborIdx; // [sp+2Ch] [bp-3Ch]@8
  signed int neighborIdxa; // [sp+2Ch] [bp-3Ch]@14
  signed int neighborIdxb; // [sp+2Ch] [bp-3Ch]@19
  signed int neighborIdxc; // [sp+2Ch] [bp-3Ch]@30
  __int16 affectedHexes[19]; // [sp+30h] [bp-38h]@16
  int damage; // [sp+58h] [bp-10h]@30
  int x; // [sp+5Ch] [bp-Ch]@2
  icon *res; // [sp+60h] [bp-8h]@4
  int anyoneDamaged; // [sp+64h] [bp-4h]@30

  thisa = this;
  if ( ValidHex(hexIdx) )
  {
    x = thisa->combatGrid[hexIdx].centerX;
    y = thisa->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    if ( !gbNoShowCombat )
    {
      v4 = 12;
      if ( spell )
      {
        if ( spell == SPELL_FIREBLAST )
        {
          res = resourceManager::GetIcon(gpResourceManager, "firebal2.icn");
        }
        else
        {
          res = resourceManager::GetIcon(gpResourceManager, "coldring.icn");
          v4 = 7;
        }
      }
      else
      {
        res = resourceManager::GetIcon(gpResourceManager, "fireball.icn");
      }
      for ( neighborIdx = 0; v4 > neighborIdx; ++neighborIdx )
      {
        glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 75.0);
        IconToBitmap(res, gpWindowManager->screenBuffer, x, y, neighborIdx, 1, 0, 0, 0x280u, 443, 0);
        if ( spell == SPELL_COLD_RING )
          FlipIconToBitmap(res, gpWindowManager->screenBuffer, x, y, neighborIdx, 1, 0, 0, 640, 443, 0);
        combatManager::UpdateCombatArea(thisa);
        combatManager::DrawFrame(thisa, 0, 0, 0, 0, 75, 1, 1);
        DelayTil(&glTimers);
      }
      resourceManager::Dispose(gpResourceManager, (resource *)res);
    }
    combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
    stack = &thisa->creatures[thisa->currentActionSide][thisa->someSortOfStackIdx];
    for ( neighborIdxa = 0; neighborIdxa < 19; ++neighborIdxa )
      affectedHexes[neighborIdxa] = -1;
    if ( spell != SPELL_COLD_RING )
      affectedHexes[0] = hexIdx;
    for ( neighborIdxb = 0; neighborIdxb < 6; ++neighborIdxb )
    {
      affectedHexes[neighborIdxb + 1] = GetAdjacentCellIndexNoArmy(hexIdx, neighborIdxb);
      if ( spell == SPELL_FIREBLAST )
        affectedHexes[neighborIdxb + 7] = army::GetAdjacentCellIndex(
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
      affectedHexes[15] = GetAdjacentCellIndexNoArmy(affectedHexes[2], 0);
      affectedHexes[16] = GetAdjacentCellIndexNoArmy(affectedHexes[2], 2);
      affectedHexes[17] = GetAdjacentCellIndexNoArmy(affectedHexes[5], 5);
      affectedHexes[18] = GetAdjacentCellIndexNoArmy(affectedHexes[5], 3);
    }
    damage = 10 * thisa->heroSpellpowers[thisa->currentActionSide];
    combatManager::ClearEffects();
    anyoneDamaged = 0;
    for ( neighborIdxc = 0; neighborIdxc < 19; ++neighborIdxc )
    {
      if ( affectedHexes[neighborIdxc] != -1 )
      {
        if ( thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner != -1 )
        {
          stack = &thisa->creatures[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx];
          if ( army::SpellCastWorks(stack, spell) )
          {
            if ( !gArmyEffected[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx] )
            {
              gArmyEffected[thisa->combatGrid[affectedHexes[neighborIdxc]].unitOwner][thisa->combatGrid[affectedHexes[neighborIdxc]].stackIdx] = 1;
              if ( !stack->damageTakenDuringSomeTimePeriod )
              {
                dam = damage;
                if ( spell == SPELL_COLD_RING && stack->creatureIdx == CREATURE_FIRE_ELEMENTAL )
                  dam = 2 * damage;
                if ( (spell == SPELL_FIREBALL || spell == 1) && stack->creatureIdx == CREATURE_WATER_ELEMENTAL )
                  dam *= 2;
                if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
                  dam = (signed __int64)((double)dam * 0.5);
                army::Damage(stack, dam, spell);
                anyoneDamaged = 1;
              }
            }
          }
        }
      }
    }
    if ( anyoneDamaged )
    {
      combatManager::ModifyDamageForArtifacts(
        &damage,
        spell,
        thisa->heroes[thisa->currentActionSide],
        thisa->heroes[1 - thisa->currentActionSide]);
      if ( spell == SPELL_COLD_RING )
        sprintf(gText, "The cold ring does %d damage.", damage);
      else
        sprintf(gText, "The fireball does %d damage.", damage);
      combatManager::CombatMessage(thisa, gText, 1, 1, 0);
      army::PowEffect(stack, -1, 1, -1, -1);
    }
  }
}