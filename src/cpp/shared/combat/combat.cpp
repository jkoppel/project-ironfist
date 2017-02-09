#include "base.h"
#include "adventure/adv.h"
#include "combat/combat.h"
#include "game/game.h"
#include "resource/resourceManager.h"
#include "artifacts.h"
#include "skills.h"
#include "sound/sound.h"
#include "spell/spells.h"

#include "gui/dialog.h"

#include "scripting/callback.h"
#include <string>

extern int castX;
extern int castY;
extern SCmbtHero sCmbtHero[13];

int squaresAroundCaster[2][3] = {
  {14,27,40},
  {11,24,37}
};

void combatManager::InitNonVisualVars() {
  combatManager::InitNonVisualVars_orig();
        
  ScriptCallback("OnBattleStart");

  for(int i = 0; i < 2; i++) {
    HandlePandoraBox(i);
  }
}

/*
* What happens when a hero wins a battle using Pandora's Box, but loses their
* main army? They walk around with stacks of 0 creatures, of course! 
* 0-creature stacks are still useful in combat though, since all attacks do at least 1 damage.
*
* On a related note, in the original game, what happens when a hero wins a battle
* using temporarily-resurrected creatures, but has no army left at the end? They
* walk around with no creatures, and instantly lose their next battle.
*
* Winning a battle with nothing but summoned elementals remaining works, however.
*
* TL, DR: There is a bug when winning a battle with nothing but temporary creatures left,
* but it's also present in the original game.
*/
void combatManager::HandlePandoraBox(int side) {
  if(this->heroes[side] && this->heroes[side]->HasArtifact(ARTIFACT_PANDORA_BOX)) {

    //The HoMM II code appears to lack a definition of creature tier. This deserves investigation.
    //We temporarily hardcode the tier-1 creatures
    int creatChoices[] = {
      CREATURE_PEASANT, CREATURE_SPRITE,CREATURE_HALFLING, CREATURE_GOBLIN,
      CREATURE_SKELETON, CREATURE_CENTAUR, CREATURE_ROGUE, CREATURE_BLOODSUCKER
    };
    int creat = creatChoices[SRandom(0, ELEMENTS_IN(creatChoices)-1)];

    int hex = -1;
    int poss = ELEMENTS_IN(squaresAroundCaster[side]);
    int tryFirst = SRandom(0, poss-1);
    for(int i = 0; i < poss; i++) {
      int square = squaresAroundCaster[side][(i+tryFirst)%poss];
      if(gMonsterDatabase[creat].creature_flags & TWO_HEXER) {
        int dir = side == 0 ? 1 : -1;
        if(this->combatGrid[square+dir].unitOwner != -1)
          continue;
      }
      if(this->combatGrid[square].unitOwner == -1)
        hex = square;
    }

    if(hex==-1)
      return;

    int amt = gpGame->GetRandomNumTroops(creat);
    AddArmy(side, creat, amt, hex, 0x8000, 0);

    hexcell* cell = &this->combatGrid[hex];
    this->creatures[cell->unitOwner][cell->stackIdx].temporaryQty = amt;
  }
}

// We don't actually change anything in sElevationOverlay, but the disasm was causing some problems

#pragma pack(push, 1)
struct SElevationOverlay {
  __int16 terrains;
  char coveredHexes[15];
};
#pragma pack(pop)

SElevationOverlay sElevationOverlay[25] =
{
  {
    0,
    {
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255
    }
  },
  { 2, { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    2,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 2, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  { 2, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 2, { 29, 30, 31, 32, 33, 34, 35, 81, 69, 70, 71, 72, 73, 74, 87 } },
  { 2, { 29, 17, 18, 19, 20, 21, 81, 95, 96, 97, 98, 99, 255, 255, 255 } },
  { 4, { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    4,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 4, { 42, 55, 56, 57, 58, 59, 47, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 18, 30, 43, 84, 85, 73, 60, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 21, 34, 48, 70, 83, 97, 98, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    64,
    { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    64,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 64, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  { 64, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 64, { 29, 30, 31, 32, 33, 34, 35, 81, 69, 70, 71, 72, 73, 74, 87 } },
  { 64, { 29, 17, 18, 19, 20, 21, 81, 95, 96, 97, 98, 99, 255, 255, 255 } },
  {
    128,
    { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 128, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  {
    128,
    { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 43, 30, 18, 84, 85, 73, 60, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 21, 34, 48, 70, 83, 97, 98, 255, 255, 255, 255, 255, 255, 255, 255 }
  }
};

void combatManager::LowerDoor() {
  SAMPLE2 res = LoadPlaySample("drawbrg.82m");
  giMinExtentX = 304;
  giMinExtentY = 218;
  giMaxExtentX = 384;
  giMaxExtentY = 294;
  for (int i = 2; i >= 0; --i) {
    this->drawBridgePosition = i;
    this->DrawFrame(1, 0, 1, 0, 75, 1, 1);
  }
  WaitEndSample(res, res.sample);
}

void combatManager::ArcShot(icon *icn, int fromX, int fromY, int targX, int targY)
{
  bool firingLeft = false;
  if (fromX > targX)
    firingLeft = true;
  float boulderX = fromX;
  float boulderY = fromY;
  float amplitude = 0.01282;
  float v33 = (double)((targX + fromX) / 2.);
  float stepX = (v33 - (double)fromX) / 12.5;
  float v32 = (double)targY - (double)(targX - fromX) * 0.3 - (double)targY * 0.35;
  if(firingLeft)
      v32 = (double)targY - (double)(fromX - targX) * 0.3 - (double)targY * 0.35;
  float stepY = (v32 - (double)fromY) * amplitude;
  int oldX = -1;
  int oldY = -1;
  int imageIdx = 0; // changes the sprite when its angle changes

  // temporarily save the screen so we can clear it from the projectile sprite later
  bitmap *savedscreen = new bitmap(0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
  gpWindowManager->screenBuffer->CopyTo(savedscreen, 0, 0, 0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);

  const int NUM_CYCLES = 24; // equals to the number of frames for the whole arc path
  for (int i = 0; i <= NUM_CYCLES; i++) {
    if (i == (NUM_CYCLES / 2)) // reached the peak height
      stepY = (v32 - (double)targY) * amplitude;
    if (i % 3 == 0) // every 3rd cycle
      if(imageIdx < (icn->numSprites - 1))
        imageIdx++; // changes the sprite of projectile

    savedscreen->CopyTo(gpWindowManager->screenBuffer, 0, 0, 0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT); // clear the screen from the previous projectile sprite
    icn->CombatClipDrawToBuffer((int)boulderX, (int)boulderY, imageIdx, NULL, firingLeft, 0, 0, 0);
    gpWindowManager->UpdateScreenRegion(0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
    
    oldX = (int)boulderX;
    oldY = (int)boulderY;
    boulderX += stepX;
    boulderY += (double)((NUM_CYCLES / 2) - i) * stepY;
    
    glTimers = (signed __int64)((double)KBTickCount() + (double)40 * gfCombatSpeedMod[giCombatSpeed]);
    DelayTil(&glTimers);
  }
  delete savedscreen;
  this->DrawFrame(1, 0, 0, 0, 1, 1, 1); // clear screen from the projectile
}

void combatManager::CastSpell(int proto_spell, int hexIdx, int isCreatureAbility, int a5) {
  hero* enemyHero = this->heroes[1 - this->currentActionSide];
  hero *currentHero = this->heroes[this->currentActionSide];

  if (!isCreatureAbility) {
    if (this->eagleEyeSpellLearned[1 - this->currentActionSide] == SPELL_NONE) {
      if (enemyHero) {
        if (!enemyHero->HasSpell(proto_spell)) {
          int eagleEyeLevel = enemyHero->secondarySkillLevel[SECONDARY_SKILL_EAGLE_EYE];
          if (eagleEyeLevel + 1 >= gsSpellInfo[proto_spell].level) {
            if (eagleEyeLevel >= SRandom(0, 9))
              this->eagleEyeSpellLearned[1 - this->currentActionSide] = proto_spell;
          }
        }
      }
    }
  }
  if (this->field_F2B7) {
    this->ResetLimitCreature();
    if (ValidHex(this->field_F2BB) && this->combatGrid[this->field_F2BB].unitOwner >= 0) {
      int v8 = 80 * this->combatGrid[this->field_F2BB].unitOwner + 4 * this->combatGrid[this->field_F2BB].stackIdx;
      ++*(signed int *)((char *)this->limitCreature[0] + v8);
    }
    this->field_F2B7 = 0;
    this->field_F2BB = -1;
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
  }
  
  if (!isCreatureAbility && currentHero)
    currentHero->UseSpell(proto_spell);

  army *stack = 0;
  int owner;
  int spellpower;
  int stackidx;

  if (proto_spell != SPELL_FIREBALL
    && proto_spell != SPELL_FIREBLAST
    && proto_spell != SPELL_COLD_RING
    && proto_spell != SPELL_METEOR_SHOWER
    && proto_spell != SPELL_SUMMON_EARTH_ELEMENTAL
    && proto_spell != SPELL_SUMMON_AIR_ELEMENTAL
    && proto_spell != SPELL_SUMMON_WATER_ELEMENTAL
    && proto_spell != SPELL_SUMMON_FIRE_ELEMENTAL
    && proto_spell != SPELL_MASS_BLESS
    && proto_spell != SPELL_MASS_HASTE
    && proto_spell != SPELL_EARTHQUAKE
    && proto_spell != SPELL_MASS_CURSE
    && proto_spell != SPELL_MASS_CURE
    && proto_spell != SPELL_HOLY_WORD
    && proto_spell != SPELL_HOLY_SHOUT
    && proto_spell != SPELL_DEATH_RIPPLE
    && proto_spell != SPELL_DEATH_WAVE
    && proto_spell != SPELL_MASS_SHIELD
    && proto_spell != SPELL_ARMAGEDDON
    && proto_spell != SPELL_ELEMENTAL_STORM
    && proto_spell != SPELL_MASS_DISPEL) {
    int targetedUnitOwner = this->combatGrid[hexIdx].unitOwner;
    int targetedUnitStackIdx = this->combatGrid[hexIdx].stackIdx;
    if (ValidHex(hexIdx) && targetedUnitOwner >= 0) {
      stack = &this->creatures[targetedUnitOwner][targetedUnitStackIdx];
      owner = targetedUnitOwner;
      stackidx = targetedUnitStackIdx;
    } else {
      stack = NULL;
    }
  } else {
    stack = NULL;
  }
  if (!isCreatureAbility)
    *(&this->field_353F + this->currentActionSide) = 1;
  if (isCreatureAbility) {
    spellpower = 3;
  } else {
    spellpower = this->heroSpellpowers[this->currentActionSide];
    int isDurationedSpell = gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL;
    if(isDurationedSpell) {
      if (currentHero->HasArtifact(ARTIFACT_ENCHANTED_HOURGLASS))
        spellpower += 2;
      if (currentHero->HasArtifact(ARTIFACT_WIZARDS_HAT))
        spellpower += 10;
    }
  }

  SCmbtHero combatHero = sCmbtHero[this->heroType[this->currentActionSide]];
  if (!isCreatureAbility) {
    int centX = -1;
    int centY = -1;
    if (stack) {
      centX = stack->MidX();
      centY = stack->MidY();
    } else if (proto_spell == SPELL_FIREBALL
            || proto_spell == SPELL_FIREBLAST
            || proto_spell == SPELL_COLD_RING
            || proto_spell == SPELL_METEOR_SHOWER) {
      centX = this->combatGrid[hexIdx].centerX;
      centY = this->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    }

    if (centX == -1) {
      this->heroAnimationType[this->currentActionSide] = 3;
    } else {
      if (this->currentActionSide) {
        castX = 610 - combatHero.castXOff;
        castY = combatHero.castYOff + 148;
      } else {
        castX = combatHero.castXOff + 30;
        castY = combatHero.castYOff + 183;
      }
      if ((centX - castX) * (this->currentActionSide < 1u ? 1 : -1) >= centY - castY) {
        this->heroAnimationType[this->currentActionSide] = 5;
      } else {
        this->heroAnimationType[this->currentActionSide] = 7;
        if (this->currentActionSide) {
          castX = 610 - combatHero.castLowXOff;
          castY = combatHero.castLowYOff + 148;
        } else {
          castX = combatHero.castLowXOff + 30;
          castY = combatHero.castLowYOff + 183;
        }
      }
    }
    for (this->heroAnimationFrameCount[this->currentActionSide] = 0;
      combatHero.animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    --this->heroAnimationFrameCount[this->currentActionSide];
  }

  int spell = proto_spell;
  if (proto_spell == SPELL_MEDUSA_PETRIFY)
    spell = SPELL_PARALYZE;
  if (proto_spell == SPELL_ARCHMAGI_DISPEL)
    spell = SPELL_DISPEL_MAGIC;

  SAMPLE2 res = NULL_SAMPLE2;
  if (strlen(gsSpellInfo[spell].soundName))
    sprintf(gText, "%s.82M", &gsSpellInfo[spell].soundName);
  if (isCreatureAbility || !stack || stack->SpellCastWorks(proto_spell)) {
    res = LoadPlaySample(gText);
    switch (proto_spell) {
    case SPELL_TELEPORT:
    {
      army *thisb = stack;
      int hexIdxa = a5;
      this->RippleCreature(stack->owningSide, stack->stackIdx, 1);
      this->combatGrid[stack->occupiedHex].unitOwner = -1;
      this->combatGrid[thisb->occupiedHex].stackIdx = -1;
      if (this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft) {
        if (this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft == 1) {
          this->combatGrid[thisb->occupiedHex - 1].unitOwner = -1;
          this->combatGrid[thisb->occupiedHex - 1].stackIdx = -1;
        }
      } else {
        this->combatGrid[thisb->occupiedHex + 1].unitOwner = -1;
        this->combatGrid[thisb->occupiedHex + 1].stackIdx = -1;
      }
      if (!gbNoShowCombat)
        WaitEndSample(res, res.sample);
      if (!gbNoShowCombat) {
        sprintf(gText, "telptin.82m");
        res = (SAMPLE2)LoadPlaySample(gText);
      }
      if (thisb->creature.creature_flags & TWO_HEXER) {
        int knownHex = a5;
        if (thisb->facingRight == 1) {
          if ((knownHex = thisb->GetAdjacentCellIndex(knownHex, 1), knownHex == -1)
            || this->combatGrid[knownHex].unitOwner != -1
            && (this->combatGrid[knownHex].unitOwner != owner || this->combatGrid[knownHex].stackIdx != stackidx)
            || this->combatGrid[knownHex].isBlocked)
            hexIdxa = a5 - 1;
        }
        if (!thisb->facingRight) {
          if ((knownHex = thisb->GetAdjacentCellIndex(knownHex, 4), knownHex == -1)
            || this->combatGrid[knownHex].unitOwner != -1
            && (this->combatGrid[knownHex].unitOwner != owner || this->combatGrid[knownHex].stackIdx != stackidx)
            || this->combatGrid[knownHex].isBlocked)
            ++hexIdxa;
        }
        thisb->occupiedHex = hexIdxa;
        int tmpFacingRight = thisb->facingRight;
        if (tmpFacingRight) {
          if (tmpFacingRight == 1) {
            this->combatGrid[thisb->occupiedHex].unitOwner = owner;
            this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
            this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = 0;
            this->combatGrid[thisb->occupiedHex + 1].unitOwner = owner;
            this->combatGrid[thisb->occupiedHex + 1].stackIdx = stackidx;
            this->combatGrid[thisb->occupiedHex + 1].occupiersOtherHexIsToLeft = 1;
          }
        } else {
          this->combatGrid[thisb->occupiedHex].unitOwner = owner;
          this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
          this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = 1;
          this->combatGrid[thisb->occupiedHex - 1].unitOwner = owner;
          this->combatGrid[thisb->occupiedHex - 1].stackIdx = stackidx;
          this->combatGrid[thisb->occupiedHex - 1].occupiersOtherHexIsToLeft = 0;
        }
        this->RippleCreature(thisb->owningSide, thisb->stackIdx, 2);
      } else {
        thisb->occupiedHex = a5;
        this->combatGrid[thisb->occupiedHex].unitOwner = owner;
        this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
        this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = -1;
        this->RippleCreature(thisb->owningSide, thisb->stackIdx, 2);
      }
      break;
    }
    case SPELL_DISRUPTING_RAY: {
      int oldDefense = stack->creature.defense;
      stack->creature.defense -= 3;
      if (stack->creature.defense < 1)
        stack->creature.defense = 1;
      sprintf(gText, "The disrupting ray reduces defense by %d.", oldDefense - stack->creature.defense);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      this->RippleCreature(stack->owningSide, stack->stackIdx, 0);
      break;
    }
    case SPELL_COLD_RAY: {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 175.0));
      long damage = 20 * spellpower;
      if (stack->creatureIdx == CREATURE_FIRE_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM)
        damage /= 2;
      this->ModifyDamageForArtifacts(&damage, SPELL_COLD_RAY, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The cold ray does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      stack->SpellEffect(gsSpellInfo[SPELL_COLD_RAY].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_CHAIN_LIGHTNING:
      this->ChainLightning(hexIdx, spellpower);
      break;
    case SPELL_MAGIC_ARROW: {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      long damage = 10 * spellpower;
      this->ModifyDamageForArtifacts(&damage, SPELL_MAGIC_ARROW, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The magic arrow does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      float angles[9] = {90.000000,45.000038,26.565073,18.262905,0.000000,-18.262905,-26.565073,-45.000038,-90.000000};
      icon *arrowIcon = gpResourceManager->GetIcon("keep.icn");
      this->ShootMissile(castX, castY, stack->MidX(), stack->MidY(), angles, arrowIcon);
      gpResourceManager->Dispose(arrowIcon);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_LIGHTNING_BOLT: {
      long damage = 25 * spellpower;
      if (stack->creatureIdx == CREATURE_AIR_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM) {
        damage /= 2;
      }
      this->ModifyDamageForArtifacts(&damage, SPELL_LIGHTNING_BOLT, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The lightning bolt does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBolt(1, castX, castY, stack->MidX(), stack->MidY(), 150, 100, 9, 2, 301, -40, 40, 30, 1, 0, 0, 1);
      stack->SpellEffect(gsSpellInfo[SPELL_LIGHTNING_BOLT].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_MASS_CURE:
    case SPELL_MASS_HASTE:
    case SPELL_MASS_SLOW:
    case SPELL_MASS_BLESS:
    case SPELL_MASS_CURSE:
    case SPELL_HOLY_WORD:
    case SPELL_HOLY_SHOUT:
    case SPELL_MASS_DISPEL:
    case SPELL_DEATH_RIPPLE:
    case SPELL_DEATH_WAVE:
    case SPELL_MASS_SHIELD:
      this->CastMassSpell(proto_spell, spellpower);
      break;
    case SPELL_MIRROR_IMAGE:
      this->MirrorImage(hexIdx);
      break;
    case SPELL_SUMMON_EARTH_ELEMENTAL:
      this->SummonElemental(CREATURE_EARTH_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_AIR_ELEMENTAL:
      this->SummonElemental(CREATURE_AIR_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_FIRE_ELEMENTAL:
      this->SummonElemental(CREATURE_FIRE_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_WATER_ELEMENTAL:
      this->SummonElemental(CREATURE_WATER_ELEMENTAL, spellpower);
      break;
    case SPELL_RESURRECT:
    case SPELL_RESURRECT_TRUE:
    case SPELL_ANIMATE_DEAD:
      this->Resurrect(proto_spell, hexIdx, spellpower);
      break;
    case SPELL_CURE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SpellEffect(gsSpellInfo[SPELL_CURE].creatureEffectAnimationIdx, 0, 0);
      stack->Cure(spellpower);
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
      break;
    case SPELL_SLOW:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SLOW, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_SLOW].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HASTE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_HASTE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_HASTE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_SHIELD:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SHIELD, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_SHIELD].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_DRAGON_SLAYER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_DRAGON_SLAYER, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_DRAGON_SLAYER].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLESS:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLESS, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BLESS].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STONESKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STONESKIN, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_STONESKIN].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STEELSKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STEELSKIN, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_STEELSKIN].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_CURSE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_CURSE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_CURSE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BERZERKER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BERSERKER, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BERZERKER].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HYPNOTIZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_HYPNOTIZE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_HYPNOTIZE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_PARALYZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_PARALYZE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_PARALYZE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_ARCHMAGI_DISPEL:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect(gsSpellInfo[SPELL_DISPEL_MAGIC].creatureEffectAnimationIdx, 0, 1);
      break;
    case SPELL_DISPEL_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect(gsSpellInfo[SPELL_DISPEL_MAGIC].creatureEffectAnimationIdx, 0, 0);
      for (int i = 0; i < 19; i++)
        stack->CancelIndividualSpell(i);
      break;
    case SPELL_BLIND:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLIND, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BLIND].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLOOD_LUST:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->BloodLustEffect(stack, CREATURE_RED);
      stack->SetSpellInfluence(EFFECT_BLOOD_LUST, 3);
      break;
    case SPELL_ANTI_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_ANTI_MAGIC, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_ANTI_MAGIC].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_MEDUSA_PETRIFY:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->TurnToStone(stack);
      break;
    case SPELL_COLD_RING:
      this->Fireball(hexIdx, SPELL_COLD_RING);
      break;
    case SPELL_FIREBALL:
      this->Fireball(hexIdx, SPELL_FIREBALL);
      break;
    case SPELL_FIREBLAST:
      this->Fireball(hexIdx, SPELL_FIREBLAST);
      break;
    case SPELL_METEOR_SHOWER:
      this->MeteorShower(hexIdx);
      break;
    case SPELL_ELEMENTAL_STORM:
      this->ElementalStorm();
      break;
    case SPELL_ARMAGEDDON:
      this->Armageddon();
      break;
    case SPELL_EARTHQUAKE:
      this->Earthquake();
      break;
    case SPELL_SHADOW_MARK:
        this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
        stack->SetSpellInfluence(EFFECT_SHADOW_MARK, 1);
        stack->SpellEffect(gsSpellInfo[SPELL_SHADOW_MARK].creatureEffectAnimationIdx, 0, 0);
      break;
    default:
      this->DefaultSpell(hexIdx);
      break;
    }
  } else {
    this->ShowSpellCastFailure(stack, proto_spell);
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; this->numCreatures[i] > j; ++j) {
      void *v14 = (char *)this + 24234 * i + 1154 * j;
      char *v15 = (char *)v14 + 13647;
      *(DWORD *)((char *)v14 + 13865) = 0;
      *(DWORD *)(v15 + 222) = *(DWORD *)(v15 + 218);
      *(DWORD *)(v15 + 214) = *(DWORD *)(v15 + 222);
      *(DWORD *)(v15 + 6) = 1;
      *v15 = 0;
      *(DWORD *)(v15 + 154) = -1;
    }
  }
  if (!isCreatureAbility) {
    ++this->heroAnimationType[this->currentActionSide];
    for (this->heroAnimationFrameCount[this->currentActionSide] = 0;
      combatHero.animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    this->heroAnimationType[this->currentActionSide] = 0;
    this->heroAnimationFrameCount[this->currentActionSide] = 0;
    this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
  WaitEndSample(res, res.sample);
  this->CheckChangeSelector();
}

void combatManager::ShowSpellMessage(int isCreatureAbility, int spell, army *stack) {
  char *creatureName;

  if (stack) {
    if (stack->quantity <= 1)
      creatureName = GetCreatureName(stack->creatureIdx);
    else
      creatureName = GetCreaturePluralName(stack->creatureIdx);
  }
  if (isCreatureAbility) {
    switch (spell) {
    case SPELL_PARALYZE:
      sprintf(gText, "The %s are paralyzed by the Cyclopes!", creatureName);
      break;
    case SPELL_BLIND:
      sprintf(gText, "The Unicorns' attack blinds the %s!", creatureName);
      break;
    case SPELL_MEDUSA_PETRIFY:
      sprintf(gText, "The Medusas' gaze turns the %s to stone!", creatureName);
      break;
    case SPELL_CURSE:
      sprintf(gText, "The Mummies' curse falls upon the %s!", creatureName);
      break;
    case SPELL_ARCHMAGI_DISPEL:
      sprintf(gText, "The Archmagi dispel all good spells\non the %s!", creatureName);
      break;
    case SPELL_SHADOW_MARK:
      sprintf(gText, "The Shadow Assassins mark the %s!", creatureName);
      break;
    }
  } else if (stack) {
    if (this->heroes[this->currentActionSide]->isCaptain)
      sprintf(gText, "The captain casts '%s' on the %s.", gSpellNames[spell], creatureName);
    else
      sprintf(gText,"%s casts '%s' on the %s.", this->heroes[this->currentActionSide]->name, gSpellNames[spell], creatureName);
  } else if (this->heroes[this->currentActionSide]->isCaptain) {
    sprintf(gText, "The captain casts '%s'.", gSpellNames[spell]);
  } else {
    sprintf(gText, "%s casts '%s'.", this->heroes[this->currentActionSide]->name, gSpellNames[spell]);
  }
  this->CombatMessage(gText, 1, 1, 0);
}

extern int bInTeleportGetDest;
void combatManager::SpellMessage(int spell, int hex) {
  army *targ; // [sp+18h] [bp-4h]@7

  if (!gbNoShowCombat) {

    switch (spell) {
      case SPELL_FIREBALL:
      case SPELL_FIREBLAST:
      case SPELL_METEOR_SHOWER:
      case SPELL_COLD_RING:
        sprintf(gText, "Cast %s", gSpellNames[spell]);
        break;
      case SPELL_TELEPORT: {
        if (bInTeleportGetDest) {
          sprintf(gText, "Teleport Here");
          break;
        }
        targ = &this->creatures[this->combatGrid[hex].unitOwner][this->combatGrid[hex].stackIdx];

        char *creatureName;
        if (targ->quantity == 1)
          creatureName = GetCreatureName(targ->creatureIdx);
        else
          creatureName = GetCreaturePluralName(targ->creatureIdx);
        sprintf(gText, "Cast %s on %s", gSpellNames[spell], creatureName);
        break;
      }
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD: {
        int resStack = this->FindResurrectArmyIndex(this->currentActionSide, spell, hex);
        targ = &this->creatures[this->currentActionSide][resStack];

        char *creatureName; 
        if (targ->quantity == 1)
          creatureName = GetCreatureName(targ->creatureIdx);
        else
          creatureName = GetCreaturePluralName(targ->creatureIdx);
        sprintf(gText, "Cast %s on %s", gSpellNames[spell], creatureName);
        break;
      }
      default: {
        targ = &this->creatures[this->combatGrid[hex].unitOwner][this->combatGrid[hex].stackIdx];
        char *creatureName; 
        if (targ->quantity == 1)
          creatureName = GetCreatureName(targ->creatureIdx);
        else
          creatureName = GetCreaturePluralName(targ->creatureIdx);
        sprintf(gText, "Cast %s on %s", gSpellNames[spell], creatureName);
        break;
      }
    }
    this->CombatMessage(gText, 1, 0, 0);
  }
}

extern int giNextActionGridIndex;

int combatManager::ValidSpellTarget(int spell, int hexIdx) {
  if (ValidHex(hexIdx)) {
    army *stack = nullptr;
    if (spell != SPELL_FIREBALL
      && spell != SPELL_FIREBLAST
      && spell != SPELL_METEOR_SHOWER
      && spell != SPELL_COLD_RING
      && spell != SPELL_RESURRECT
      && spell != SPELL_RESURRECT_TRUE
      && spell != SPELL_ANIMATE_DEAD
      && this->combatGrid[hexIdx].unitOwner != -1
      && ((stack = &this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx],
        this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx].effectStrengths[EFFECT_ANTI_MAGIC])
        || this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx].creatureIdx == CREATURE_GREEN_DRAGON)) {
      return 0;
    } else if (stack && stack->SpellCastWorkChance(spell) <= 0.0) {
      return 0;
    } else {
      switch (spell) {
      case SPELL_HOLY_WORD:
      case SPELL_HOLY_SHOUT:
      case SPELL_DISPEL_MAGIC:
      case SPELL_MASS_DISPEL:
      case SPELL_ARMAGEDDON:
      case SPELL_ELEMENTAL_STORM:
      case SPELL_DEATH_RIPPLE:
      case SPELL_DEATH_WAVE:
        if (this->combatGrid[hexIdx].unitOwner != -1)
          return 1;
        return 0;
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD:
        return this->FindResurrectArmyIndex(this->currentActionSide, spell, hexIdx) != -1;
      case SPELL_CURE:
      case SPELL_MASS_CURE:
      case SPELL_HASTE:
      case SPELL_MASS_HASTE:
      case SPELL_BLESS:
      case SPELL_MASS_BLESS:
      case SPELL_STONESKIN:
      case SPELL_STEELSKIN:
      case SPELL_ANTI_MAGIC:
      case SPELL_DRAGON_SLAYER:
      case SPELL_BLOOD_LUST:
      case SPELL_SHIELD:
      case SPELL_MASS_SHIELD:
        if (this->combatGrid[hexIdx].unitOwner == this->currentActionSide)
          return 1;
        return 0;
      case SPELL_MIRROR_IMAGE:
        if (this->combatGrid[hexIdx].unitOwner == this->currentActionSide) {
          if (this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx].mirrorIdx == -1
            && this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx].mirroredIdx == -1)
            return 1;
          return 0;
        } else {
          return 0;
        }
      case SPELL_LIGHTNING_BOLT:
      case SPELL_CHAIN_LIGHTNING:
      case SPELL_SLOW:
      case SPELL_MASS_SLOW:
      case SPELL_BLIND:
      case SPELL_CURSE:
      case SPELL_MASS_CURSE:
      case SPELL_MAGIC_ARROW:
      case SPELL_BERZERKER:
      case SPELL_PARALYZE:
      case SPELL_HYPNOTIZE:
      case SPELL_COLD_RAY:
      case SPELL_DISRUPTING_RAY:
      case SPELL_SHADOW_MARK:
        if (this->combatGrid[hexIdx].unitOwner == 1 - this->currentActionSide)
          return 1;
        return 0;
      case SPELL_TELEPORT:
        if (bInTeleportGetDest) {
          army* currentArmy = &this->creatures[gpCombatManager->combatGrid[giNextActionGridIndex].unitOwner][gpCombatManager->combatGrid[giNextActionGridIndex].stackIdx];
          if (hexIdx != giNextActionGridIndex && currentArmy->CanFit(hexIdx, 0, 0))
            return 1;
          return 0;
        } else {
          if (this->combatGrid[hexIdx].unitOwner == this->currentActionSide)
            return 1;
          return 0;
        }
        break;
      case SPELL_FIREBALL:
      case SPELL_FIREBLAST:
      case SPELL_METEOR_SHOWER:
      case SPELL_COLD_RING:
        if (hexIdx != -1 && hexIdx % 13 && hexIdx % 13 != 12)
          return 1;
        return 0;
      default:
        return 1;
      }
    }
  } else {
    return 0;
  }
}
