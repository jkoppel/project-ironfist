{
  char heroAttack; // al@32
  combatManager *thisa; // [sp+10h] [bp-D4h]@1
  char *createName; // [sp+18h] [bp-CCh]@46
  signed int targetPriority; // [sp+24h] [bp-C0h]@9
  Point16 v6[6][3]; // [sp+2Ch] [bp-B8h]@31
  int targetStrength; // [sp+74h] [bp-70h]@9
  int yFrom; // [sp+78h] [bp-6Ch]@31
  int xFrom; // [sp+8Ch] [bp-58h]@31
  signed int dam; // [sp+90h] [bp-54h]@39
  int creaturesPerished; // [sp+94h] [bp-50h]@44
  int i; // [sp+98h] [bp-4Ch]@9
  int stackPriority; // [sp+9Ch] [bp-48h]@19
  int targetIdx; // [sp+A0h] [bp-44h]@9
  army *targStack; // [sp+A4h] [bp-40h]@14
  sample_resource res; // [sp+A8h] [bp-3Ch]@31
  int attack; // [sp+B0h] [bp-34h]@31
  int yTarg; // [sp+B4h] [bp-30h]@31
  int xTarg; // [sp+B8h] [bp-2Ch]@31
  float a7[9]; // [sp+BCh] [bp-28h]@31
  int numberOfArchers; // [sp+E0h] [bp-4h]@31

  thisa = this;
  if ( this->isCastleBattle
    && (towerIdx || !this->ballistaDestroyed)
    && (towerIdx != 1 || this->turretStatus[0] == 1)
    && (towerIdx != 2 || this->turretStatus[3] == 1) )
  {
    LogStr("KA1");
    targetPriority = -1;
    targetStrength = 0;
    targetIdx = -1;
    for ( i = 0; i < 20; ++i )
    {
      if ( thisa->creatures[0][i].creatureIdx >= 0 && thisa->creatures[0][i].quantity > 0 )
      {
        targStack = (army *)((char *)thisa->creatures + 1154 * i);
        if ( thisa->creatures[0][i].effectStrengths[2]
          || targStack->effectStrengths[6]
          || targStack->effectStrengths[11]
          || targStack->effectStrengths[5]
          || targStack->effectStrengths[7] )
        {
          stackPriority = 0;
        }
        else if ( targStack->creature.creature_flags & SHOOTER )
        {
          stackPriority = 3;
        }
        else if ( targStack->creature.creature_flags & FLYER )
        {
          stackPriority = 2;
        }
        else
        {
          stackPriority = 1;
        }
        if ( targetPriority < stackPriority
          || targetPriority == stackPriority
          && targStack->quantity * gMonsterDatabase[targStack->creatureIdx].fight_value > targetStrength )
        {
          targetStrength = targStack->quantity * gMonsterDatabase[targStack->creatureIdx].fight_value;
          targetPriority = stackPriority;
          targetIdx = i;
        }
      }
    }
    if ( targetIdx != -1 )
    {
      targStack = (army *)((char *)gpCombatManager->creatures + 1154 * targetIdx);
      sprintf(gText, "keepshot.82M");
      res = LoadPlaySample(gText);
      *(_QWORD *)&v6[0][0].x = 16890336860242506i64;
      v6[0][2] = (Point16)20578732;
      *(_QWORD *)&v6[1][0].x = 16890336860242506i64;
      v6[1][2] = (Point16)20578732;
      *(_QWORD *)&v6[2][0].x = 16890336860242506i64;
      v6[2][2] = (Point16)20578732;
      *(_QWORD *)&v6[3][0].x = 16890336860242506i64;
      v6[3][2] = (Point16)20578732;
      *(_QWORD *)&v6[4][0].x = 16890336860242506i64;
      v6[4][2] = (Point16)20578732;
      *(_QWORD *)&v6[5][0].x = 16890336860242506i64;
      v6[5][2] = (Point16)20578732;
      xFrom = *(_DWORD *)&v6[thisa->castles[1]->factionID][towerIdx] & 0xFFFF;
      yFrom = v6[thisa->castles[1]->factionID][towerIdx].y;
      xTarg = army::MidX(targStack);
      yTarg = army::MidY(targStack);
      LODWORD(a7[0]) = 0x42B40000u;
      LODWORD(a7[1]) = 0x42890000u;
      LODWORD(a7[2]) = 0x42340000u;
      LODWORD(a7[3]) = 0x41A66666u;
      LODWORD(a7[4]) = 0;
      LODWORD(a7[5]) = 0xC1A66666u;
      LODWORD(a7[6]) = 0xC2340000u;
      LODWORD(a7[7]) = 0xC2890000u;
      LODWORD(a7[8]) = 0xC2B40000u;
      combatManager::ShootMissile(xFrom, yFrom, xTarg, yTarg, a7, thisa->combatScreenIcons[7]);
      town::CalcNumLevelArchers(thisa->castles[1], &numberOfArchers, &attack);
      attack += 2;
      if ( thisa->heroes[1] )
      {
        heroAttack = hero::Stats(thisa->heroes[1], PRIMARY_SKILL_ATTACK);
        attack += heroAttack;
      }
      attack -= targStack->creature.defense;
      if ( attack > 20 )
        attack = 20;
      if ( attack < -20 )
        attack = -20;
      if ( towerIdx )
        numberOfArchers /= 2;
      dam = 0;
      for ( i = 0; numberOfArchers > i; ++i )
        dam += SRandom(2, 3);
      dam = (signed __int64)((double)dam * gfBattleStat[attack + 20]);
      if ( dam <= 0 )
        dam = 1;
      creaturesPerished = army::Damage(targStack, dam, SPELL_NONE);
      if ( creaturesPerished <= 0 )
      {
        sprintf(
          gText,
          "%s %d %s.",
          &aGarrisonDoes_0[("Tower does" - "Garrison does") & ((towerIdx == 0) - 1)],
          dam,
          "damage");
      }
      else
      {
        if ( creaturesPerished <= 1 )
          createName = gArmyNames[targStack->creatureIdx];
        else
          createName = gArmyNamesPlural[targStack->creatureIdx];
        sprintf(
          gText,
          "%s %d %s.\n%d %s %s.",
          &aGarrisonDoes[("Tower does" - "Garrison does") & ((towerIdx == 0) - 1)],
          dam,
          "damage",
          creaturesPerished,
          createName,
          &aPerish[("perishes" - "perish") & ((creaturesPerished > 1) - 1)]);
      }
      combatManager::CombatMessage(gpCombatManager, gText, 1, 1, 0);
      army::CancelSpellType(targStack, CREATURE_TOOK_DAMAGE_CODE);
      army::PowEffect(targStack, -1, 1, -1, -1);
      WaitEndSample(-1, res);
      LogStr("KA2");
    }
  }
}