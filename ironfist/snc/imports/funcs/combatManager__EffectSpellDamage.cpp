{
  __int16 v4; // fps@73
  unsigned __int8 v5; // c0@73
  unsigned __int8 v6; // c3@73
  int unitOwner; // eax@110
  int v8; // ecx@111
  __int64 v9; // qax@112
  __int64 v10; // qax@112
  signed __int64 v11; // qax@125
  combatManager *thisa; // [sp+50h] [bp-54h]@1
  int v14; // [sp+54h] [bp-50h]@114
  CREATURES creatIdx; // [sp+58h] [bp-4Ch]@74
  int remDam; // [sp+5Ch] [bp-48h]@107
  int stacksKilled[2]; // [sp+60h] [bp-44h]@22
  float chance; // [sp+68h] [bp-3Ch]@73
  int v19; // [sp+6Ch] [bp-38h]@18
  int damage; // [sp+70h] [bp-34h]@74
  army *stack; // [sp+74h] [bp-30h]@19
  int damMult; // [sp+78h] [bp-2Ch]@2
  int i; // [sp+7Ch] [bp-28h]@20
  int neighborIdx; // [sp+80h] [bp-24h]@18
  int kills; // [sp+84h] [bp-20h]@18
  int dam; // [sp+88h] [bp-1Ch]@18
  bool done; // [sp+8Ch] [bp-18h]@18
  int fightValueKilled[2]; // [sp+90h] [bp-14h]@22
  int curHex; // [sp+98h] [bp-Ch]@18
  int v30[2]; // [sp+9Ch] [bp-8h]@22

  thisa = this;
  switch ( spell )
  {
    case SPELL_ARMAGEDDON:
      damMult = 50;
      break;
    case SPELL_HOLY_WORD:
      damMult = 10;
      break;
    case SPELL_HOLY_SHOUT:
      damMult = 20;
      break;
    case SPELL_DEATH_RIPPLE:
      damMult = 5;
      break;
    case SPELL_DEATH_WAVE:
      damMult = 10;
      break;
    case SPELL_ELEMENTAL_STORM:
      damMult = 25;
      break;
    case SPELL_FIREBALL:
      damMult = 10;
      break;
    case SPELL_FIREBLAST:
      damMult = 10;
      break;
    case SPELL_METEOR_SHOWER:
      damMult = 25;
      break;
    case SPELL_LIGHTNING_BOLT:
      damMult = 25;
      break;
    case SPELL_MAGIC_ARROW:
      damMult = 10;
      break;
    case SPELL_CHAIN_LIGHTNING:
      damMult = 40;
      break;
    case SPELL_COLD_RAY:
      damMult = 20;
      break;
    case SPELL_COLD_RING:
      damMult = 10;
      break;
    default:
      damMult = 0;
      break;
  }
  dam = damMult * this->heroSpellpowers[this->currentActionSide];
  curHex = 0;
  neighborIdx = 0;
  done = 0;
  kills = 0;
  v19 = 0;
  if ( this->combatGrid[hexIdx].stackIdx >= 0 )
    stack = &this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx];
  for ( i = 0; i < 2; ++i )
  {
    stacksKilled[i] = 0;
    fightValueKilled[i] = 0;
    v30[i] = 0;
  }
  combatManager::ClearEffects();
  while ( !done )
  {
    switch ( spell )
    {
      case SPELL_HOLY_WORD:
      case SPELL_HOLY_SHOUT:
      case SPELL_ARMAGEDDON:
      case SPELL_ELEMENTAL_STORM:
      case SPELL_DEATH_RIPPLE:
      case SPELL_DEATH_WAVE:
        combatManager::NextPos(&curHex);
        done = curHex >= 116;
        break;
      case SPELL_COLD_RING:
        if ( !neighborIdx )
          neighborIdx = 1;
        goto LABEL_29;
      case SPELL_FIREBALL:
      case SPELL_FIREBLAST:
      case SPELL_METEOR_SHOWER:
LABEL_29:
        if ( (neighborIdx < 7 || spell == SPELL_FIREBLAST) && neighborIdx < 19 )
        {
          if ( !neighborIdx )
            curHex = hexIdx;
          if ( neighborIdx > 0 && neighborIdx <= 6 )
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, neighborIdx - 1);
          if ( neighborIdx > 6 && neighborIdx <= 12 )
          {
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, neighborIdx - 7);
            curHex = GetAdjacentCellIndexNoArmy(curHex, neighborIdx - 7);
          }
          if ( neighborIdx == 13 )
            curHex = hexIdx - 26;
          if ( neighborIdx == 14 )
            curHex = hexIdx + 26;
          if ( neighborIdx == 15 )
          {
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, 1);
            curHex = GetAdjacentCellIndexNoArmy(curHex, 0);
          }
          if ( neighborIdx == 16 )
          {
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, 1);
            curHex = GetAdjacentCellIndexNoArmy(curHex, 2);
          }
          if ( neighborIdx == 17 )
          {
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, 4);
            curHex = GetAdjacentCellIndexNoArmy(curHex, 5);
          }
          if ( neighborIdx == 18 )
          {
            curHex = GetAdjacentCellIndexNoArmy(hexIdx, 4);
            curHex = GetAdjacentCellIndexNoArmy(curHex, 3);
          }
          ++neighborIdx;
        }
        else
        {
          done = 1;
        }
        break;
      case SPELL_LIGHTNING_BOLT:
      case SPELL_MAGIC_ARROW:
      case SPELL_COLD_RAY:
      case SPELL_DISRUPTING_RAY:
        if ( curHex == hexIdx )
          done = 1;
        else
          curHex = hexIdx;
        break;
      case SPELL_CHAIN_LIGHTNING:
        if ( curHex )
        {
          dam >>= 1;
          curHex = combatManager::GetNextChainLightningTarget(
                     thisa,
                     &thisa->creatures[thisa->combatGrid[curHex].unitOwner][thisa->combatGrid[curHex].stackIdx],
                     0);
        }
        else
        {
          curHex = hexIdx;
        }
        ++neighborIdx;
        if ( neighborIdx > 4 || curHex == -1 )
          done = 1;
        break;
      case SPELL_TELEPORT:
      case SPELL_CURE:
      case SPELL_MASS_CURE:
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_HASTE:
      case SPELL_MASS_HASTE:
      case SPELL_SLOW:
      case SPELL_MASS_SLOW:
      case SPELL_BLIND:
      case SPELL_BLESS:
      case SPELL_MASS_BLESS:
      case SPELL_STONESKIN:
      case SPELL_STEELSKIN:
      case SPELL_CURSE:
      case SPELL_MASS_CURSE:
      case SPELL_ANTI_MAGIC:
      case SPELL_DISPEL_MAGIC:
      case SPELL_MASS_DISPEL:
      case SPELL_BERZERKER:
      case SPELL_PARALYZE:
      case SPELL_HYPNOTIZE:
        break;
    }
    if ( !done )
    {
      if ( curHex >= 0 )
      {
        if ( curHex < 116 )
        {
          if ( thisa->combatGrid[curHex].stackIdx >= 0 )
          {
            if ( thisa->combatGrid[curHex].unitOwner >= 0 )
            {
              stack = &thisa->creatures[thisa->combatGrid[curHex].unitOwner][thisa->combatGrid[curHex].stackIdx];
              if ( !gArmyEffected[thisa->combatGrid[curHex].unitOwner][thisa->combatGrid[curHex].stackIdx] )
              {
                gArmyEffected[thisa->combatGrid[curHex].unitOwner][thisa->combatGrid[curHex].stackIdx] = 1;
                UNDEF(v4);
                chance = army::SpellCastWorkChance(stack, spell);
                if ( !(v5 | v6) )
                {
                  damage = (signed __int64)((double)dam * chance);
                  creatIdx = stack->creatureIdx;
                  switch ( spell )
                  {
                    case SPELL_ARMAGEDDON:
                      if ( creatIdx == CREATURE_IRON_GOLEM || creatIdx == CREATURE_STEEL_GOLEM )
                        damage = (signed __int64)((double)damage * 0.5);
                      break;
                    case SPELL_FIREBALL:
                    case SPELL_FIREBLAST:
                      if ( creatIdx == CREATURE_IRON_GOLEM || creatIdx == CREATURE_STEEL_GOLEM )
                        damage = (signed __int64)((double)damage * 0.5);
                      if ( creatIdx == CREATURE_WATER_ELEMENTAL )
                        damage *= 2;
                      break;
                    case SPELL_METEOR_SHOWER:
                      if ( creatIdx == CREATURE_IRON_GOLEM || creatIdx == CREATURE_STEEL_GOLEM )
                        damage = (signed __int64)((double)damage * 0.5);
                      if ( creatIdx == CREATURE_EARTH_ELEMENTAL )
                        damage *= 2;
                      break;
                    case SPELL_LIGHTNING_BOLT:
                    case SPELL_CHAIN_LIGHTNING:
                    case SPELL_ELEMENTAL_STORM:
                      if ( creatIdx == CREATURE_IRON_GOLEM || creatIdx == CREATURE_STEEL_GOLEM )
                        damage = (signed __int64)((double)damage * 0.5);
                      if ( creatIdx == CREATURE_AIR_ELEMENTAL )
                        damage *= 2;
                      break;
                    case SPELL_COLD_RAY:
                    case SPELL_COLD_RING:
                      if ( creatIdx == CREATURE_IRON_GOLEM || creatIdx == CREATURE_STEEL_GOLEM )
                        damage = (signed __int64)((double)damage * 0.5);
                      if ( creatIdx == CREATURE_FIRE_ELEMENTAL )
                        damage *= 2;
                      break;
                    default:
                      break;
                  }
                  combatManager::ModifyDamageForArtifacts(
                    &damage,
                    spell,
                    thisa->heroes[thisa->currentActionSide],
                    thisa->heroes[stack->owningSide]);
                  if ( HIBYTE(stack->creature.creature_flags) & ATTR_MIRROR_IMAGE && damage )
                    damage = 999999;
                  kills = damage / stack->creature.hp;
                  remDam = damage % stack->creature.hp;
                  if ( remDam + stack->damage >= stack->creature.hp )
                  {
                    ++kills;
                    remDam -= stack->creature.hp - stack->damage;
                  }
                  if ( stack->quantity <= kills )
                  {
                    kills = stack->quantity;
                    remDam = 0;
                    unitOwner = thisa->combatGrid[curHex].unitOwner;
                    ++stacksKilled[unitOwner];
                  }
                  fightValueKilled[thisa->combatGrid[curHex].unitOwner] = (signed __int64)(((double)remDam * 0.75
                                                                                          + (double)(kills * stack->creature.hp))
                                                                                         * (double)gMonsterDatabase[stack->creatureIdx].fight_value
                                                                                         / (double)stack->creature.hp
                                                                                         + (double)fightValueKilled[thisa->combatGrid[curHex].unitOwner]);
                  v8 = thisa->combatGrid[curHex].unitOwner;
                  v30[v8] += kills
                           * stack->creature.hp
                           * gMonsterDatabase[stack->creatureIdx].fight_value
                           / stack->creature.hp;
                  if ( HIBYTE(stack->creature.creature_flags) & 1 )
                  {
                    v9 = v30[thisa->combatGrid[curHex].unitOwner];
                    v30[thisa->combatGrid[curHex].unitOwner] = ((signed int)v9 - HIDWORD(v9)) >> 1;
                    v10 = fightValueKilled[thisa->combatGrid[curHex].unitOwner];
                    fightValueKilled[thisa->combatGrid[curHex].unitOwner] = ((signed int)v10 - HIDWORD(v10)) >> 1;
                  }
                  if ( spell == 34 )
                  {
                    v14 = stack->creature.defense - 3;
                    if ( v14 < 1 )
                      v14 = 1;
                    v19 = (signed __int64)((double)((stack->quantity - kills)
                                                  * ((signed int)stack->creature.defense - v14)
                                                  * gMonsterDatabase[stack->creatureIdx].fight_value)
                                         * 0.05
                                         + (double)v19);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( thisa->numCreatures[0] > stacksKilled[0] && thisa->numCreatures[1] > stacksKilled[1] )
  {
    *val = v19 + fightValueKilled[1 - thisa->currentActionSide] - fightValueKilled[thisa->currentActionSide];
  }
  else if ( v30[thisa->currentActionSide] > 0 )
  {
    *val = v19 + v30[1 - thisa->currentActionSide] - v30[thisa->currentActionSide];
  }
  else
  {
    *val = v19 + 100000000 - *(_WORD *)&gsSpellInfo[spell].appearingChance;
  }
  LODWORD(v11) = thisa;
  if ( !thisa->currentActionSide )
  {
    LODWORD(v11) = thisa;
    if ( thisa->isCastleBattle )
    {
      v11 = (signed __int64)((double)*val * 1.25);
      *val = v11;
    }
  }
  return v11;
}