{
  int durationBenefitIdx; // eax@27
  int v5; // ST94_4@53
  double v6; // st7@54
  int v7; // ecx@54
  int v8; // ST88_4@61
  double v9; // st7@62
  int v10; // ecx@62
  int v11; // ST7C_4@69
  double v12; // st7@70
  int v13; // ecx@70
  int v14; // ST70_4@77
  double v15; // st7@78
  int v16; // ecx@78
  int v17; // ST64_4@85
  double v18; // st7@86
  int v19; // ecx@86
  int v20; // eax@93
  double v21; // st7@94
  int v22; // ecx@94
  int v23; // ST4C_4@102
  int v24; // ST48_4@106
  int v25; // ST3C_4@116
  int v26; // ST30_4@126
  int v27; // ST2C_4@129
  int v28; // ST24_4@139
  int v29; // ST20_4@143
  int v30; // ST1C_4@147
  combatManager *thisa; // [sp+9Ch] [bp-44h]@1
  signed int v32; // [sp+A0h] [bp-40h]@151
  int v33; // [sp+A4h] [bp-3Ch]@102
  int duration; // [sp+A8h] [bp-38h]@23
  int val; // [sp+ACh] [bp-34h]@21
  int incapacitated; // [sp+B0h] [bp-30h]@21
  int targetSide; // [sp+B4h] [bp-2Ch]@1
  float durBenefit; // [sp+B8h] [bp-28h]@1
  int v39; // [sp+BCh] [bp-24h]@1
  int underMyControl; // [sp+C0h] [bp-20h]@21
  army *potTarg; // [sp+C4h] [bp-1Ch]@1
  AI_SPELL_TYPES aiSpellType; // [sp+C8h] [bp-18h]@2
  int i; // [sp+D0h] [bp-10h]@151
  int targetHex; // [sp+D4h] [bp-Ch]@1
  bool targSpentTurn; // [sp+D8h] [bp-8h]@1
  int hex; // [sp+DCh] [bp-4h]@1

  thisa = this;
  targetHex = 0;
  targetSide = 0;
  hex = 1;
  durBenefit = 1.0;
  targSpentTurn = 1;
  v39 = 0;
  potTarg = 0;
  *value = 0;
  switch ( spell )
  {
    case SPELL_MASS_CURE:
    case SPELL_HOLY_WORD:
    case SPELL_HOLY_SHOUT:
    case SPELL_MASS_DISPEL:
    case SPELL_ARMAGEDDON:
    case SPELL_ELEMENTAL_STORM:
    case SPELL_DEATH_RIPPLE:
    case SPELL_DEATH_WAVE:
    case SPELL_SUMMON_EARTH_ELEMENTAL:
    case SPELL_SUMMON_AIR_ELEMENTAL:
    case SPELL_SUMMON_FIRE_ELEMENTAL:
    case SPELL_SUMMON_WATER_ELEMENTAL:
    case SPELL_EARTHQUAKE:
      aiSpellType = AI_BATTLEFIELD_AFFECTING_SPELL;
      goto LABEL_12;
    case SPELL_FIREBALL:
    case SPELL_FIREBLAST:
    case SPELL_METEOR_SHOWER:
    case SPELL_COLD_RING:
      aiSpellType = AI_BALL_SPALL;
      goto LABEL_12;
    case SPELL_MASS_HASTE:
    case SPELL_MASS_BLESS:
    case SPELL_MASS_SHIELD:
      aiSpellType = AI_MASS_BUFF_SPELL;
      targetSide = this->currentActionSide;
      goto LABEL_12;
    case SPELL_MASS_SLOW:
    case SPELL_MASS_CURSE:
      aiSpellType = AI_MASS_DEBUFF_SPELL;
      targetSide = 1 - this->currentActionSide;
      goto LABEL_12;
    case SPELL_DISPEL_MAGIC:
      aiSpellType = AI_DISPEL_SPELL;
      targetSide = 2;
      goto LABEL_12;
    case SPELL_TELEPORT:
    case SPELL_CURE:
    case SPELL_HASTE:
    case SPELL_BLESS:
    case SPELL_STONESKIN:
    case SPELL_STEELSKIN:
    case SPELL_ANTI_MAGIC:
    case SPELL_DRAGON_SLAYER:
    case SPELL_BLOOD_LUST:
    case SPELL_MIRROR_IMAGE:
    case SPELL_SHIELD:
      aiSpellType = AI_TARGET_BUFF_SPELL;
      targetSide = this->currentActionSide;
      goto LABEL_12;
    case SPELL_RESURRECT:
    case SPELL_RESURRECT_TRUE:
    case SPELL_ANIMATE_DEAD:
      aiSpellType = AI_RESURRECT_SPELL;
      targetSide = this->currentActionSide;
      goto LABEL_12;
    case SPELL_LIGHTNING_BOLT:
    case SPELL_CHAIN_LIGHTNING:
    case SPELL_SLOW:
    case SPELL_BLIND:
    case SPELL_CURSE:
    case SPELL_MAGIC_ARROW:
    case SPELL_BERZERKER:
    case SPELL_PARALYZE:
    case SPELL_HYPNOTIZE:
    case SPELL_COLD_RAY:
    case SPELL_DISRUPTING_RAY:
      aiSpellType = AI_TARGET_DAMAGE_OR_DEBUFF_SPELL;
      targetSide = 1 - this->currentActionSide;
LABEL_12:
      if ( aiSpellType == AI_RESURRECT_SPELL )
        targetHex = combatManager::FirstResurrectable(this, 1, &hex, spell);
      if ( aiSpellType == AI_TARGET_BUFF_SPELL
        || aiSpellType == AI_TARGET_DAMAGE_OR_DEBUFF_SPELL
        || aiSpellType == AI_MASS_DEBUFF_SPELL
        || aiSpellType == AI_MASS_BUFF_SPELL
        || aiSpellType == AI_DISPEL_SPELL )
        targetHex = combatManager::FirstArmy(thisa, 1, targetSide, &hex);
      while ( 2 )
      {
        if ( !targetHex )
        {
          incapacitated = 0;
          underMyControl = 0;
          val = 0;
          if ( thisa->combatGrid[hex].stackIdx < 0 || thisa->combatGrid[hex].unitOwner < 0 )
          {
            potTarg = 0;
          }
          else
          {
            potTarg = &thisa->creatures[thisa->combatGrid[hex].unitOwner][thisa->combatGrid[hex].stackIdx];
            giCurrSpellGroup = thisa->combatGrid[hex].unitOwner;
            targSpentTurn = (potTarg->creature.creature_flags & MAYBE_NOT_LOST_TURN) != 0;
            duration = thisa->heroSpellpowers[thisa->currentActionSide];
            if ( hero::HasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_ENCHANTED_HOURGLASS) )
              duration += 2;
            if ( hero::HasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_WIZARDS_HAT) )
              duration += 10;
            durationBenefitIdx = duration - targSpentTurn;
            if ( duration - targSpentTurn >= 10 )
              durationBenefitIdx = 10;
            durBenefit = durationBenefit[durationBenefitIdx];
            if ( potTarg->effectStrengths[7] || potTarg->effectStrengths[5] )
              underMyControl = 1;
            if ( potTarg->effectStrengths[2] || potTarg->effectStrengths[6] || potTarg->effectStrengths[11] )
              incapacitated = 1;
          }
          switch ( spell )
          {
            case SPELL_CURE:
              combatManager::EffectSpellCure(thisa, &val, thisa->currentActionSide, hex, 1);
              goto LABEL_171;
            case SPELL_MASS_CURE:
              combatManager::EffectSpellCure(thisa, &val, thisa->currentActionSide, -1, 1);
              goto LABEL_171;
            case SPELL_DISPEL_MAGIC:
              combatManager::EffectSpellCure(thisa, &val, potTarg->owningSide, potTarg->stackIdx, 0);
              goto LABEL_171;
            case SPELL_MASS_DISPEL:
              combatManager::EffectSpellCure(thisa, &val, 2, -1, 0);
              goto LABEL_171;
            case SPELL_RESURRECT:
            case SPELL_RESURRECT_TRUE:
            case SPELL_ANIMATE_DEAD:
              if ( !underMyControl )
                combatManager::EffectSpellResurrect(thisa, &val, hex, spell);
              goto LABEL_171;
            case SPELL_MIRROR_IMAGE:
            case SPELL_SUMMON_EARTH_ELEMENTAL:
            case SPELL_SUMMON_AIR_ELEMENTAL:
            case SPELL_SUMMON_FIRE_ELEMENTAL:
            case SPELL_SUMMON_WATER_ELEMENTAL:
              val = combatManager::EffectSpellCreateCreature(thisa, hex, spell);
              goto LABEL_171;
            case SPELL_FIREBALL:
            case SPELL_FIREBLAST:
            case SPELL_LIGHTNING_BOLT:
            case SPELL_CHAIN_LIGHTNING:
            case SPELL_HOLY_WORD:
            case SPELL_HOLY_SHOUT:
            case SPELL_MAGIC_ARROW:
            case SPELL_ARMAGEDDON:
            case SPELL_ELEMENTAL_STORM:
            case SPELL_METEOR_SHOWER:
            case SPELL_COLD_RAY:
            case SPELL_COLD_RING:
            case SPELL_DISRUPTING_RAY:
            case SPELL_DEATH_RIPPLE:
            case SPELL_DEATH_WAVE:
              if ( !underMyControl )
              {
                combatManager::EffectSpellDamage(thisa, &val, spell, hex);
                if ( incapacitated )
                  val = (signed __int64)((double)val * 0.5);
              }
              goto LABEL_171;
            case SPELL_HASTE:
            case SPELL_MASS_HASTE:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[0] )
                  {
                    v5 = combatManager::RawEffectSpellInfluence(thisa, potTarg, 0);
                    val = (signed __int64)((double)v5 * durBenefit);
                    if ( potTarg->effectStrengths[1] )
                    {
                      v6 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_SLOW);
                      v7 = targSpentTurn + potTarg->effectStrengths[1];
                      if ( v7 >= 10 )
                        v7 = 10;
                      val = (signed __int64)((double)val - v6 * heuristicModifierForDuration[v7]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_BERZERKER:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[5] )
                  {
                    v8 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BERSERKER);
                    val = (signed __int64)((double)v8 * durBenefit);
                    if ( potTarg->effectStrengths[7] )
                    {
                      v9 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_HYPNOTIZE);
                      v10 = targSpentTurn + potTarg->effectStrengths[7];
                      if ( v10 >= 10 )
                        v10 = 10;
                      val = (signed __int64)((double)val - v9 * heuristicModifierForDuration[v10]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_HYPNOTIZE:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[7] )
                  {
                    v11 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_HYPNOTIZE);
                    val = (signed __int64)((double)v11 * durBenefit);
                    if ( potTarg->effectStrengths[5] )
                    {
                      v12 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BERSERKER);
                      v13 = targSpentTurn + potTarg->effectStrengths[5];
                      if ( v13 >= 10 )
                        v13 = 10;
                      val = (signed __int64)((double)val - v12 * heuristicModifierForDuration[v13]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_SLOW:
            case SPELL_MASS_SLOW:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[1] )
                  {
                    v14 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_SLOW);
                    val = (signed __int64)((double)v14 * durBenefit);
                    if ( potTarg->effectStrengths[0] )
                    {
                      v15 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, 0);
                      v16 = targSpentTurn + potTarg->effectStrengths[0];
                      if ( v16 >= 10 )
                        v16 = 10;
                      val = (signed __int64)((double)val - v15 * heuristicModifierForDuration[v16]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_BLESS:
            case SPELL_MASS_BLESS:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[3] )
                  {
                    v17 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BLESS);
                    val = (signed __int64)((double)v17 * durBenefit);
                    if ( potTarg->effectStrengths[4] )
                    {
                      v18 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_CURSE);
                      v19 = targSpentTurn + potTarg->effectStrengths[4];
                      if ( v19 >= 10 )
                        v19 = 10;
                      val = (signed __int64)((double)val - v18 * heuristicModifierForDuration[v19]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_CURSE:
            case SPELL_MASS_CURSE:
              if ( !incapacitated )
              {
                if ( !underMyControl )
                {
                  if ( !potTarg->effectStrengths[4] )
                  {
                    v20 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_CURSE);
                    val = (signed __int64)((double)-v20 * durBenefit);
                    if ( potTarg->effectStrengths[3] )
                    {
                      v21 = (double)combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BLESS);
                      v22 = targSpentTurn + potTarg->effectStrengths[3];
                      if ( v22 >= 10 )
                        v22 = 10;
                      val = (signed __int64)((double)val - v21 * heuristicModifierForDuration[v22]);
                    }
                  }
                }
              }
              goto LABEL_171;
            case SPELL_ANTI_MAGIC:
              if ( !potTarg->effectStrengths[12] )
              {
                if ( spell != 22 || thisa->heroes[1 - thisa->currentActionSide] )
                {
                  v23 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_ANTI_MAGIC);
                  val = (signed __int64)((double)v23 * durBenefit);
                  combatManager::EffectSpellCure(thisa, &v33, potTarg->owningSide, potTarg->stackIdx, 0);
                  val += v33;
                }
                else
                {
                  val = 0;
                }
              }
              goto LABEL_171;
            case SPELL_STONESKIN:
              if ( !underMyControl && !potTarg->effectStrengths[13] && !potTarg->effectStrengths[14] )
              {
                v24 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_STONESKIN);
                val = (signed __int64)((double)v24 * durBenefit);
                if ( thisa->castles[1] && !potTarg->owningSide && potTarg->creature.creature_flags & SHOOTER )
                  val = (signed __int64)((double)val * 1.5);
                if ( incapacitated )
                  val = (signed __int64)((double)val * 0.5);
              }
              goto LABEL_171;
            case SPELL_STEELSKIN:
              if ( !underMyControl && !potTarg->effectStrengths[13] && !potTarg->effectStrengths[14] )
              {
                v25 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_STEELSKIN);
                val = (signed __int64)((double)v25 * durBenefit);
                if ( thisa->castles[1] && !potTarg->owningSide && potTarg->creature.creature_flags & 4 )
                  val = (signed __int64)((double)val * 1.5);
                if ( incapacitated )
                  val = (signed __int64)((double)val * 0.5);
              }
              goto LABEL_171;
            case SPELL_BLOOD_LUST:
              if ( !incapacitated && !underMyControl && !potTarg->effectStrengths[9] )
              {
                v26 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BLOOD_LUST);
                val = (signed __int64)((double)v26 * durBenefit);
              }
              goto LABEL_171;
            case SPELL_SHIELD:
            case SPELL_MASS_SHIELD:
              if ( !underMyControl && !potTarg->effectStrengths[10] )
              {
                v27 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_SHIELD);
                val = (signed __int64)((double)v27 * durBenefit);
                if ( thisa->castles[1] && !potTarg->owningSide && potTarg->creature.creature_flags & 4 )
                  val *= 2;
                if ( incapacitated )
                  val = (signed __int64)((double)val * 0.5);
              }
              goto LABEL_171;
            case SPELL_BLIND:
              if ( !incapacitated && !underMyControl && !potTarg->effectStrengths[2] )
              {
                v28 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_BLIND);
                val = (signed __int64)((double)v28 * durBenefit);
              }
              goto LABEL_171;
            case SPELL_PARALYZE:
              if ( !incapacitated && !underMyControl && !potTarg->effectStrengths[6] )
              {
                v29 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_PARALYZE);
                val = (signed __int64)((double)v29 * durBenefit);
              }
              goto LABEL_171;
            case SPELL_DRAGON_SLAYER:
              if ( !incapacitated && !underMyControl && !potTarg->effectStrengths[8] )
              {
                v30 = combatManager::RawEffectSpellInfluence(thisa, potTarg, EFFECT_DRAGON_SLAYER);
                val = (signed __int64)((double)v30 * durBenefit);
              }
              goto LABEL_171;
            case SPELL_TELEPORT:
              val = 0;
              goto LABEL_171;
            case SPELL_EARTHQUAKE:
              if ( thisa->currentActionSide || !thisa->isCastleBattle )
              {
                val = 0;
              }
              else
              {
                v32 = 0;
                for ( i = 0; i < 4; ++i )
                {
                  if ( thisa->wallStatus[i] == 2 || thisa->wallStatus[i] == 6 )
                    ++v32;
                }
                if ( v32 )
                {
                  if ( v32 >= 4 )
                    val = 0;
                  else
                    val = 100 * (4 - v32);
                }
                else
                {
                  val = 29999;
                }
              }
LABEL_171:
              switch ( aiSpellType )
              {
                case AI_MASS_BUFF_SPELL:
                case AI_MASS_DEBUFF_SPELL:
                  v39 += val;
                  break;
                case AI_BATTLEFIELD_AFFECTING_SPELL:
                case AI_BALL_SPALL:
                case AI_TARGET_BUFF_SPELL:
                case AI_TARGET_DAMAGE_OR_DEBUFF_SPELL:
                case AI_RESURRECT_SPELL:
                case AI_DISPEL_SPELL:
                  v39 = val;
                  break;
                default:
                  break;
              }
              if ( aiSpellType == AI_MASS_BUFF_SPELL || aiSpellType == AI_MASS_DEBUFF_SPELL || *value < v39 )
              {
                *value = v39;
                *target = hex;
              }
              switch ( aiSpellType )
              {
                case AI_BATTLEFIELD_AFFECTING_SPELL:
                  targetHex = 1;
                  break;
                case AI_MASS_BUFF_SPELL:
                case AI_MASS_DEBUFF_SPELL:
                case AI_TARGET_BUFF_SPELL:
                case AI_TARGET_DAMAGE_OR_DEBUFF_SPELL:
                case AI_DISPEL_SPELL:
                  targetHex = combatManager::FirstArmy(thisa, hex + 1, targetSide, &hex);
                  break;
                case AI_RESURRECT_SPELL:
                  targetHex = combatManager::FirstResurrectable(thisa, hex + 1, &hex, spell);
                  break;
                case AI_BALL_SPALL:
                  combatManager::NextPos(&hex);
                  if ( hex > 43 )
                    targetHex = 1;
                  break;
                default:
                  continue;
              }
              continue;
            default:
              *value = 0;
              break;
          }
        }
        break;
      }
      break;
    default:
      *value = 0;
      break;
  }
}