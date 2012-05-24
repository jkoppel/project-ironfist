void __thiscall CreatureStack::doHydraAttack(CreatureStack *this, int a2)
{
  int v2; // eax@4
  CreatureStack *thisa; // [sp+Ch] [bp-FCh]@1
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
  CreatureStack *targ; // [sp+34h] [bp-D4h]@19
  int v15; // [sp+38h] [bp-D0h]@17
  int creaturesKilled; // [sp+3Ch] [bp-CCh]@20
  char message; // [sp+40h] [bp-C8h]@31

  thisa = this;
  v13 = 0;
  v11 = 0;
  CombatManager::clearHitByHydraAttack(combatManager);
  if ( thisa->effectStrengths[5] )
    v10 = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 2, -1);
  else
    v10 = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 1, -1);
  CreatureStack::rollAndHandleLuck(thisa);
  CombatManager::resetStuffHapenedToCreature(combatManager);
  v2 = 80 * thisa->owningSide + 4 * thisa->stackIdx;
  ++*(signed int *)((char *)combatManager->stuffHappenedToCreature[0] + v2);
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
      a1a = CreatureStack::getHexNeighbor(thisa, a1, neighborIdx);
      if ( checkHexGridIdxBounds(a1a) )
      {
        v9 = combatManager->combatGrid[a1a].unitOwner;
        v15 = combatManager->combatGrid[a1a].stackIdx;
        if ( v9 >= 0 )
        {
          if ( v15 >= 0 )
          {
            ++combatManager->stuffHappenedToCreature[v9][v15];
            targ = &combatManager->creatures[v9][v15];
            if ( !combatManager->creatures[v9][v15].hitByHydraAttack )
            {
              targ->hitByHydraAttack = 1;
              CreatureStack::dealDamage(thisa, targ, &damageDone, &creaturesKilled, 0, 0);
              v11 += damageDone;
              v13 += creaturesKilled;
              ++combatManager->stuffHappenedToCreature[v9][v15];
            }
          }
        }
      }
    }
  }
  CombatManager::drawBattlefield(combatManager, 0, 1, 0, 1, 75, 1, 1);
  thisa->mightBeIsAttacking = 1;
  thisa->mightBeAttackAnimIdx = 20;
  SoundManager::playSample(soundManager, thisa->combatSounds[1]);
  if ( v13 <= 0 )
  {
    if ( thisa->quantity <= 1 )
      v4 = creatureSingularNames[thisa->creatureIdx];
    else
      v4 = creaturePluralNames[thisa->creatureIdx];
    sprintf(globBuf, "%s %s %d %s.", v4, &aDo_2[("does" - "do") & ((thisa->quantity > 1) - 1)], v11, "damage");
  }
  else
  {
    if ( thisa->quantity <= 1 )
      v5 = creatureSingularNames[thisa->creatureIdx];
    else
      v5 = creaturePluralNames[thisa->creatureIdx];
    sprintf(
      globBuf,
      "%s %s %d %s.\n%d %s %s.",
      v5,
      &aDo_1[("does" - "do") & ((thisa->quantity > 1) - 1)],
      v11,
      "damage",
      v13,
      &aCreatures[("creature" - "creatures") & ((v13 > 1) - 1)],
      &aPerish_1[("perishes" - "perish") & ((v13 > 1) - 1)]);
  }
  globBuf[0] -= 32;
  strcpy((int)&message);
  CreatureStack::doAttackAndDamageTakenAnimations(thisa, -1, 0, -1, -1);
  CombatManager::displayCombatMessage(combatManager, &message, 1, 1, 0);
  combatManager->stuffHappenedToCreature[thisa->owningSide][thisa->stackIdx] = 1;
}
