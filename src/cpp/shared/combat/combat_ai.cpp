#include "combat/combat.h"

float heuristicModifierForDuration[] = {
   0.0,
   0.5,
   0.65,
   0.78,
   0.85,
   0.95,
   1.03,
   1.08,
   1.12,
   1.15,
   1.18
};

float durationBenefit[] = {
   0.0,
   0.33,
   0.55,
   0.72,
   0.85,
   0.95,
   1.03,
   1.08,
   1.12,
   1.15,
   1.18
};

void combatManager::DetermineEffectOfSpell(int spell, int *value, int *target) {
  *value = 0;
  AI_SPELL_TYPES aiSpellType;
  int targetSide = 0;

  switch(spell) {
    case SPELL_MASS_SLOW:
    case SPELL_MASS_CURSE:
      aiSpellType = AI_MASS_DEBUFF_SPELL;
      targetSide = 1 - this->currentActionSide;
      break;
    case SPELL_SLOW:
    case SPELL_CURSE:
      aiSpellType = AI_TARGET_DAMAGE_OR_DEBUFF_SPELL;
      targetSide = 1 - this->currentActionSide;
    default:
      this->DetermineEffectOfSpell_orig(spell, value, target);
      return;
  }

  int targetHex = 0;
  int hex = 1;

  if(aiSpellType == AI_TARGET_BUFF_SPELL
    || aiSpellType == AI_TARGET_DAMAGE_OR_DEBUFF_SPELL
    || aiSpellType == AI_MASS_DEBUFF_SPELL
    || aiSpellType == AI_MASS_BUFF_SPELL
    || aiSpellType == AI_DISPEL_SPELL)
    targetHex = this->FirstArmy(1, targetSide, &hex);
    
  bool targSpentTurn = 1;
  float durBenefit = 1.0;
  while(true) {
    if(!targetHex) {
      bool incapacitated = false;
      bool underMyControl = false;
      army *potTarg = nullptr;

      if(this->combatGrid[hex].stackIdx < 0 || this->combatGrid[hex].unitOwner < 0) {
        potTarg = 0;
      } else {
        potTarg = &this->creatures[this->combatGrid[hex].unitOwner][this->combatGrid[hex].stackIdx];
        giCurrSpellGroup = this->combatGrid[hex].unitOwner;
        targSpentTurn = (potTarg->creature.creature_flags & MAYBE_NOT_LOST_TURN) != 0;
        int duration = this->heroSpellpowers[this->currentActionSide];
        if(this->heroes[this->currentActionSide]->HasArtifact(ARTIFACT_ENCHANTED_HOURGLASS))
          duration += 2;
        if(this->heroes[this->currentActionSide]->HasArtifact(ARTIFACT_WIZARDS_HAT))
          duration += 10;
        int durationBenefitIdx = duration - targSpentTurn;
        if(duration - targSpentTurn >= 10)
          durationBenefitIdx = 10;
        durBenefit = durationBenefit[durationBenefitIdx];
        if(potTarg->effectStrengths[EFFECT_HYPNOTIZE] || potTarg->effectStrengths[EFFECT_BERSERKER])
          underMyControl = true;
        if(potTarg->effectStrengths[EFFECT_BLIND] || potTarg->effectStrengths[EFFECT_PARALYZE] || potTarg->effectStrengths[EFFECT_PETRIFY])
          incapacitated = true;
      }

      int effectValue = 0;
      switch(spell) {
        case SPELL_SLOW:
        case SPELL_MASS_SLOW:
          if(!incapacitated) {
            if(!underMyControl) {
              if(!potTarg->effectStrengths[EFFECT_SLOW]) {
                effectValue = -this->RawEffectSpellInfluence(potTarg, EFFECT_SLOW) * durBenefit;
                if(potTarg->effectStrengths[EFFECT_HASTE]) {
                  int durModifierIdx = targSpentTurn + potTarg->effectStrengths[EFFECT_HASTE];
                  if(durModifierIdx >= 10)
                    durModifierIdx = 10;

                  effectValue += this->RawEffectSpellInfluence(potTarg, EFFECT_HASTE) * heuristicModifierForDuration[durModifierIdx];
                }
              }
            }
          }
          break;
        case SPELL_CURSE:
        case SPELL_MASS_CURSE:
          if(!incapacitated) {
            if(!underMyControl) {
              if(!potTarg->effectStrengths[EFFECT_CURSE]) {
                effectValue = -this->RawEffectSpellInfluence(potTarg, EFFECT_CURSE) * durBenefit;
                if(potTarg->effectStrengths[EFFECT_BLESS]) {
                  int durModifierIdx = targSpentTurn + potTarg->effectStrengths[EFFECT_BLESS];
                  if(durModifierIdx >= 10)
                    durModifierIdx = 10;
                  effectValue += this->RawEffectSpellInfluence(potTarg, EFFECT_BLESS) * heuristicModifierForDuration[durModifierIdx];
                }
              }
            }
          }
          break;
        default:
          *value = 0;
          break;
      }

      int finalEffectValue = 0;
      switch(aiSpellType) {
        case AI_MASS_BUFF_SPELL:
        case AI_MASS_DEBUFF_SPELL:
          finalEffectValue += effectValue;
          break;
        case AI_BATTLEFIELD_AFFECTING_SPELL:
        case AI_BALL_SPALL:
        case AI_TARGET_BUFF_SPELL:
        case AI_TARGET_DAMAGE_OR_DEBUFF_SPELL:
        case AI_RESURRECT_SPELL:
        case AI_DISPEL_SPELL:
          finalEffectValue = effectValue;
          break;
        default:
          break;
      }

      if(aiSpellType == AI_MASS_BUFF_SPELL || aiSpellType == AI_MASS_DEBUFF_SPELL || *value < finalEffectValue) {
        *value = finalEffectValue;
        *target = hex;
      }

      switch(aiSpellType) {
        case AI_BATTLEFIELD_AFFECTING_SPELL:
          targetHex = 1;
          break;
        case AI_MASS_BUFF_SPELL:
        case AI_MASS_DEBUFF_SPELL:
        case AI_TARGET_BUFF_SPELL:
        case AI_TARGET_DAMAGE_OR_DEBUFF_SPELL:
        case AI_DISPEL_SPELL:
          targetHex = this->FirstArmy(hex + 1, targetSide, &hex);
          break;
        case AI_RESURRECT_SPELL:
          targetHex = this->FirstResurrectable(hex + 1, &hex, spell);
          break;
        case AI_BALL_SPALL:
          this->NextPos(&hex);
          if(hex > 43)
            targetHex = 1;
          break;
      }
      continue;
    }
    break;
  }
}

int combatManager::RawEffectSpellInfluence(army *stack, int eff) {
  double chance = stack->SpellCastWorkChance(giSpellInfluenceToSpell[eff]);
  if(chance < 0.0001) {
    return 0;
  }

  int preResult;
  int fightValue = stack->quantity * stack->creature.fight_value;
  int owningSide = stack->owningSide;
  int otherSide = 1 - owningSide;
  switch(eff) {
    case EFFECT_SLOW:
    case EFFECT_HASTE:
    {
      int speedWithEffect;
      if(eff == EFFECT_SLOW)
        speedWithEffect = (stack->creature.speed + 1) >> 1;
      else
        speedWithEffect = stack->creature.speed + 2;

      if(eff == EFFECT_HASTE && stack->creature.creature_flags & FLYER)
        return 0;

      if(this->isCastleBattle && owningSide == 1)
        return 0;

      if(stack->creature.creature_flags & SHOOTER)
        return 0;
      
      if(stack->GetAttackMask(stack->occupiedHex, 1, -1) == 255) {
        int hexXCoord = stack->occupiedHex % 13;
        int distFromOptimalColumn;
        if(this->currentActionSide)
          distFromOptimalColumn = 10 - hexXCoord;
        else
          distFromOptimalColumn = hexXCoord - 2;
        if(distFromOptimalColumn < 0)
          distFromOptimalColumn = 0;

        
        int adjustedDistFromOtherSide = distFromOptimalColumn + 2;
        if(this->isCastleBattle)
          adjustedDistFromOtherSide += 3;
        double currentTurnsToOtherSide;
        if(stack->creature.creature_flags & FLYER)
          currentTurnsToOtherSide = 1.0;
        else
          currentTurnsToOtherSide = adjustedDistFromOtherSide / stack->creature.speed;

        double turnsToOtherSideAfterCast = adjustedDistFromOtherSide / speedWithEffect;
        if(turnsToOtherSideAfterCast > 7.0)
          turnsToOtherSideAfterCast = 7.0;
        if(currentTurnsToOtherSide > 7.0)
          currentTurnsToOtherSide = 7.0;
        preResult = (currentTurnsToOtherSide - turnsToOtherSideAfterCast) / 10.0 * fightValue;
      } else
        return 0;
      break;
    }
    case EFFECT_BLESS:
    case EFFECT_CURSE: {
      double avgDamage = (stack->creature.min_damage + stack->creature.max_damage) * 0.5;
      preResult = (stack->creature.max_damage - avgDamage) / avgDamage * fightValue * 0.45;
      if(eff == EFFECT_CURSE)
        preResult = -preResult;
      break;
    }
    case EFFECT_DRAGON_SLAYER: {
      bool hasAdjacentDragons = false;
      int numDragons = 0;
      
      for(int i = 0; this->numCreatures[otherSide] > i; ++i) {
        army* cr = &this->creatures[owningSide][i];
        int creatureIdx = cr->creatureIdx;
        if(creatureIdx == CREATURE_GREEN_DRAGON
          || creatureIdx == CREATURE_RED_DRAGON
          || creatureIdx == CREATURE_BLACK_DRAGON
          || creatureIdx == CREATURE_BONE_DRAGON) {
          numDragons++;
          if(stack->OtherArmyAdjacent(cr->owningSide, cr->stackIdx))
            hasAdjacentDragons = true;
        }
      }
      double dragonsVal;
      if(hasAdjacentDragons)
        dragonsVal = 1.0;
      else
        dragonsVal = numDragons / this->numCreatures[otherSide];
      preResult = 0.28 * dragonsVal;
      break;
    }
    case EFFECT_SHIELD: {
      int numShooters = 0;
      for(int j = 0; this->numCreatures[otherSide] > j; ++j) {
        if(this->creatures[owningSide][j].creature.creature_flags & SHOOTER)
          numShooters++;
      }
      double shooterVal = numShooters / this->numCreatures[otherSide];
      if(!owningSide && this->isCastleBattle) {
          shooterVal += 0.3;
          if(shooterVal > 1.0)
            shooterVal = 1.0;
      }
      preResult = 0.45 * shooterVal;
      break;
    }
    default:
      return this->RawEffectSpellInfluence_orig(stack, eff);
  }

  if(stack->effectStrengths[EFFECT_BERSERKER] || stack->effectStrengths[EFFECT_HYPNOTIZE]) {
    if(eff != EFFECT_ANTI_MAGIC)
      return 0;
  }
  return preResult * chance;
}