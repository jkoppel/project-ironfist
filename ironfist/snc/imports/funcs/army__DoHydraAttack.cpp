{
  int v2; // eax@4
  army *thisa; // [sp+Ch] [bp-FCh]@1
  char *v4; // [sp+10h] [bp-F8h]@28
  char *v5; // [sp+14h] [bp-F4h]@24
  signed int neighborIdx; // [sp+18h] [bp-F0h]@4
  int a1; // [sp+1Ch] [bp-ECh]@7
  int a1a; // [sp+1Ch] [bp-ECh]@16
  int v9; // [sp+20h] [bp-E8h]@17
  __int16 v10; // [sp+24h] [bp-E4h]@2
  int v11; // [sp+28h] [bp-E0h]@1
  int damageDone; // [sp+2Ch] [bp-DCh]@20
  int v13; // [sp+30h] [bp-D8h]@1
  army *targ; // [sp+34h] [bp-D4h]@19
  int v15; // [sp+38h] [bp-D0h]@17
  int creaturesKilled; // [sp+3Ch] [bp-CCh]@20
  char message; // [sp+40h] [bp-C8h]@31

  thisa = this;
  v13 = 0;
  v11 = 0;
  combatManager::ResetHitByCreature(gpCombatManager);
  if ( thisa->effectStrengths[5] )
    v10 = army::GetAttackMask(thisa, thisa->occupiedHex, 2, -1);
  else
    v10 = army::GetAttackMask(thisa, thisa->occupiedHex, 1, -1);
  army::CheckLuck(thisa);
  combatManager::ResetLimitCreature(gpCombatManager);
  v2 = 80 * thisa->owningSide + 4 * thisa->stackIdx;
  ++*(signed int *)((char *)gpCombatManager->stuffHappenedToCreature[0] + v2);
  for ( neighborIdx = 0; neighborIdx < 8; ++neighborIdx )
  {
    if ( !(v10 & (1 << neighborIdx)) )
    {
      a1 = thisa->occupiedHex;
      if ( thisa->creature.creature_flags & TWO_HEXER
        && (!thisa->facingRight && neighborIdx > 2 || thisa->facingRight == 1 && (neighborIdx < 3 || neighborIdx > 5)) )
      {
        if ( thisa->facingRight )
          a1 = thisa->occupiedHex + 1;
        else
          a1 = thisa->occupiedHex - 1;
      }
      a1a = army::GetAdjacentCellIndex(thisa, a1, neighborIdx);
      if ( ValidHex(a1a) )
      {
        v9 = gpCombatManager->combatGrid[a1a].unitOwner;
        v15 = gpCombatManager->combatGrid[a1a].stackIdx;
        if ( v9 >= 0 )
        {
          if ( v15 >= 0 )
          {
            ++gpCombatManager->stuffHappenedToCreature[v9][v15];
            targ = &gpCombatManager->creatures[v9][v15];
            if ( !gpCombatManager->creatures[v9][v15].hitByHydraAttack )
            {
              targ->hitByHydraAttack = 1;
              army::DamageEnemy(thisa, targ, &damageDone, &creaturesKilled, 0, 0);
              v11 += damageDone;
              v13 += creaturesKilled;
              ++gpCombatManager->stuffHappenedToCreature[v9][v15];
            }
          }
        }
      }
    }
  }
  combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
  thisa->mightBeIsAttacking = 1;
  thisa->mightBeAttackAnimIdx = 20;
  soundManager::MemorySample(gpSoundManager, thisa->combatSounds[1]);
  if ( v13 <= 0 )
  {
    if ( thisa->quantity <= 1 )
      v4 = gArmyNames[thisa->creatureIdx];
    else
      v4 = gArmyNamesPlural[thisa->creatureIdx];
    sprintf(gText, "%s %s %d %s.", v4, &aDo_2[("does" - "do") & ((thisa->quantity > 1) - 1)], v11, "damage");
  }
  else
  {
    if ( thisa->quantity <= 1 )
      v5 = gArmyNames[thisa->creatureIdx];
    else
      v5 = gArmyNamesPlural[thisa->creatureIdx];
    sprintf(
      gText,
      "%s %s %d %s.\n%d %s %s.",
      v5,
      &aDo_1[("does" - "do") & ((thisa->quantity > 1) - 1)],
      v11,
      "damage",
      v13,
      &aCreatures[("creature" - "creatures") & ((v13 > 1) - 1)],
      &aPerish_1[("perishes" - "perish") & ((v13 > 1) - 1)]);
  }
  gText[0] -= 32;
  strcpy(&message, gText);
  army::PowEffect(thisa, -1, 0, -1, -1);
  combatManager::CombatMessage(gpCombatManager, &message, 1, 1, 0);
  gpCombatManager->stuffHappenedToCreature[thisa->owningSide][thisa->stackIdx] = 1;
}