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

signed int combatManager::GetNextArmy(int a2) {
  int stackIdx;

  while (1) {
    int v9 = 0;
    int side = this->otherCurrentSideThing;
    this->field_F2AB = 14;
    for (int i = 0; i < 15; ++i) {
      for (int j = 0; j < 2; ++j) {
        side = 1 - side;
        for (stackIdx = 0; ; ++stackIdx) {
          if (this->numCreatures[side] > stackIdx) {
            int v10 = 0;
            if (this->creatures[side][stackIdx].creature.creature_flags & (MAYBE_NOT_LOST_TURN | DEAD)
              || this->creatures[side][stackIdx].effectStrengths[6]
              || this->creatures[side][stackIdx].effectStrengths[11]
              || this->creatures[side][stackIdx].effectStrengths[2]
              || this->creatures[side][stackIdx].creature.speed != this->field_F2AB
              && !(this->creatures[side][stackIdx].creature.creature_flags & HAS_GOOD_MORALE))
              v10 = 1;
            if (!v10 && !i && !(this->creatures[side][stackIdx].creature.creature_flags & HAS_GOOD_MORALE))
              v10 = 1;
            if (HIBYTE(this->creatures[side][stackIdx].creature.creature_flags) & DEAD) {
              v10 = 1;
              v9 = 1;
            }
            if (!v10 && a2 && this->CheckApplyBadMorale(side, stackIdx))
              v10 = 1;
            if (v10)
              continue;
          }
          break;
        }
        if (this->numCreatures[side] != stackIdx) {
          this->otherCurrentSideThing = side;
          this->someSortOfStackIdx = stackIdx;
          if (this->creatures[side][stackIdx].effectStrengths[7])
            this->currentActionSide = 1 - side;
          else
            this->currentActionSide = side;
          this->GetControl();
          return 1;
        }
      }
      if (i) {
        --this->field_F2AB;
        if (!this->field_F2AB)
          this->field_F2AB = 15;
      }
    }
    if (!v9)
      break;
    a2 = 0;
    for (int k = 0; k < 2; ++k) {
      for (int stackIdxa = 0; this->numCreatures[k] > stackIdxa; ++stackIdxa)
        this->creatures[k][stackIdxa].creature.creature_flags &= 0xFFFFEFFFu;
    }
  }
  this->CheckCastleAttack();
  this->currentActionSide = 1 - this->currentActionSide;
  this->CheckCastleAttack();
  this->currentActionSide = 1 - this->currentActionSide;
  return 0;
}

void combatManager::CastSpell(int proto_spell, int hexIdx, int isCreatureAbility, int a5) {
  int v5; // ebx@0
  double v6; // st6@0
  double v7; // st7@0
  int v8; // eax@12
  icon *v9; // ST84_4@135
  int v10; // ST38_4@135
  int v11; // eax@135
  int v12; // ST10_4@144
  int v13; // eax@144
  void *v14; // eax@186
  char *v15; // ST80_4@186
  int v16; // [sp+14h] [bp-ACh]@111
  combatManager *thisa; // [sp+1Ch] [bp-A4h]@1
  char *v18; // [sp+20h] [bp-A0h]@142
  char *v19; // [sp+24h] [bp-9Ch]@133
  char *v20; // [sp+28h] [bp-98h]@128
  float a7[9]; // [sp+44h] [bp-7Ch]@135
  int knownHex; // [sp+68h] [bp-58h]@97
  army *thisb; // [sp+6Ch] [bp-54h]@88
  int oldDefense; // [sp+70h] [bp-50h]@119
  int centX; // [sp+74h] [bp-4Ch]@54
  int centY; // [sp+78h] [bp-48h]@54
  army *stack; // [sp+7Ch] [bp-44h]@17
  int j; // [sp+84h] [bp-3Ch]@184
  int effect; // [sp+8Ch] [bp-34h]@165
  long damage; // [sp+90h] [bp-30h]@122
  int owner; // [sp+94h] [bp-2Ch]@41
  char buf[8]; // [sp+98h] [bp-28h]@82
  int spellpower; // [sp+A8h] [bp-18h]@46
  SAMPLE2 res; // [sp+ACh] [bp-14h]@9
  int spell; // [sp+B4h] [bp-Ch]@77
  int stackidx; // [sp+B8h] [bp-8h]@41
  int i; // [sp+BCh] [bp-4h]@182
  int hexIdxa; // [sp+CCh] [bp+Ch]@88

  if (!isCreatureAbility) {
    if (this->eagleEyeSpellLearned[1 - this->currentActionSide] == SPELL_NONE) {
      if (this->heroes[1 - this->currentActionSide]) {
        if (!this->heroes[1 - this->currentActionSide]->HasSpell(proto_spell)) {
          if (this->heroes[1 - this->currentActionSide]->secondarySkillLevel[11]) {
            if (this->heroes[1 - this->currentActionSide]->secondarySkillLevel[11] + 1 >= gsSpellInfo[proto_spell].level) {
              v5 = this->heroes[1 - this->currentActionSide]->secondarySkillLevel[11];
              if (v5 >= SRandom(0, 9))
                this->eagleEyeSpellLearned[1 - this->currentActionSide] = proto_spell;
            }
          }
        }
      }
    }
  }
  res = NULL_SAMPLE2;
  if (this->field_F2B7) {
    this->ResetLimitCreature();
    if (ValidHex(this->field_F2BB) && this->combatGrid[this->field_F2BB].unitOwner >= 0) {
      v8 = 80 * this->combatGrid[this->field_F2BB].unitOwner + 4 * this->combatGrid[this->field_F2BB].stackIdx;
      ++*(signed int *)((char *)this->limitCreature[0] + v8);
    }
    this->field_F2B7 = 0;
    this->field_F2BB = -1;
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
  }
  if (!isCreatureAbility && this->heroes[this->currentActionSide])
    this->heroes[this->currentActionSide]->UseSpell(proto_spell);
  stack = 0;
  if (proto_spell
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
    if (ValidHex(hexIdx) && this->combatGrid[hexIdx].unitOwner >= 0) {
      stack = &this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx];
      owner = this->combatGrid[hexIdx].unitOwner;
      stackidx = this->combatGrid[hexIdx].stackIdx;
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
    if (this->heroes[this->currentActionSide]->HasArtifact(ARTIFACT_ENCHANTED_HOURGLASS)
      && gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL)
      spellpower += 2;
    if (this->heroes[this->currentActionSide]->HasArtifact(ARTIFACT_WIZARDS_HAT)
      && gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL)
      spellpower += 10;
  }
  if (!isCreatureAbility) {
    centX = -1;
    centY = -1;
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
        castX = 610 - sCmbtHero[this->heroType[this->currentActionSide]].castXOff;
        castY = sCmbtHero[this->heroType[this->currentActionSide]].castYOff + 148;
      } else {
        castX = sCmbtHero[this->heroType[this->currentActionSide]].castXOff + 30;
        castY = sCmbtHero[this->heroType[this->currentActionSide]].castYOff + 183;
      }
      if ((centX - castX) * (this->currentActionSide < 1u ? 1 : -1) >= centY - castY) {
        this->heroAnimationType[this->currentActionSide] = 5;
      } else {
        this->heroAnimationType[this->currentActionSide] = 7;
        if (this->currentActionSide) {
          castX = 610 - sCmbtHero[this->heroType[this->currentActionSide]].castLowXOff;
          castY = sCmbtHero[this->heroType[this->currentActionSide]].castLowYOff + 148;
        } else {
          castX = sCmbtHero[this->heroType[this->currentActionSide]].castLowXOff + 30;
          castY = sCmbtHero[this->heroType[this->currentActionSide]].castLowYOff + 183;
        }
      }
    }
    for (this->heroAnimationFrameCount[this->currentActionSide] = 0;
      sCmbtHero[this->heroType[this->currentActionSide]].animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    --this->heroAnimationFrameCount[this->currentActionSide];
  }
  spell = proto_spell;
  if (proto_spell == SPELL_MEDUSA_PETRIFY)
    spell = SPELL_PARALYZE;
  if (proto_spell == SPELL_ARCHMAGI_DISPEL)
    spell = SPELL_DISPEL_MAGIC;
  //if (strlen(gsSpellInfo[spell].soundName))
  //  sprintf(buf, "%s.82M", &gsSpellInfo[spell]);
  if (isCreatureAbility || !stack || stack->SpellCastWorks(proto_spell)) {
    //res = (SAMPLE2)LoadPlaySample(buf);
    switch (proto_spell) {
    case SPELL_TELEPORT:
      thisb = stack;
      hexIdxa = a5;
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
        knownHex = a5;
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
        v16 = thisb->facingRight;
        if (v16) {
          if (v16 == 1) {
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
    case SPELL_DISRUPTING_RAY:
      oldDefense = stack->creature.defense;
      stack->creature.defense -= 3;
      if (stack->creature.defense < 1)
        stack->creature.defense = 1;
      sprintf(gText, "The disrupting ray reduces defense by %d.", oldDefense - stack->creature.defense);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      this->RippleCreature(stack->owningSide, stack->stackIdx, 0);
      break;
    case SPELL_COLD_RAY:
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 175.0));
      damage = 20 * spellpower;
      if (stack->creatureIdx == CREATURE_FIRE_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM)
        damage = (signed __int64)((double)damage * 0.5);
      combatManager::ModifyDamageForArtifacts(
        &damage,
        SPELL_COLD_RAY,
        this->heroes[this->currentActionSide],
        this->heroes[1 - this->currentActionSide]);
      if (stack->quantity <= 1)
        v20 = GetCreatureName(stack->creatureIdx);
      else
        v20 = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The cold ray does %d\n damage to the %s.", damage, v20);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[32].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    case SPELL_CHAIN_LIGHTNING:
      this->ChainLightning(hexIdx, spellpower);
      break;
    case SPELL_MAGIC_ARROW:
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      damage = 10 * spellpower;
      combatManager::ModifyDamageForArtifacts(
        &damage,
        SPELL_MAGIC_ARROW,
        this->heroes[this->currentActionSide],
        this->heroes[1 - this->currentActionSide]);
      if (stack->quantity <= 1)
        v19 = GetCreatureName(stack->creatureIdx);
      else
        v19 = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The magic arrow does %d\n damage to the %s.", damage, v19);
      this->CombatMessage(gText, 1, 1, 0);
      v9 = gpResourceManager->GetIcon("keep.icn");
      a7[0] = 1116274688;
      a7[1] = 1110704128;
      a7[2] = 1101424230;
      a7[3] = 0;
      a7[4] = -1046059418;
      a7[5] = -1036779520;
      a7[6] = -1031208960;
      a7[7] = -1028390912;
      v10 = stack->MidY();
      v11 = stack->MidX();
      combatManager::ShootMissile(castX, castY, v11, v10, a7, v9);
      gpResourceManager->Dispose((resource *)v9);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    case SPELL_LIGHTNING_BOLT:
      damage = 25 * spellpower;
      if (stack->creatureIdx == CREATURE_AIR_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM) {
        v7 = (double)damage * 0.5;
        damage = (signed __int64)v7;
      }
      combatManager::ModifyDamageForArtifacts(
        &damage,
        SPELL_LIGHTNING_BOLT,
        this->heroes[this->currentActionSide],
        this->heroes[1 - this->currentActionSide]);
      if (stack->quantity <= 1)
        v18 = GetCreatureName(stack->creatureIdx);
      else
        v18 = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The lightning bolt does %d\n damage to the %s.", damage, v18);
      this->CombatMessage(gText, 1, 1, 0);
      v12 = stack->MidY();
      v13 = stack->MidX();
      this->DoBolt(
        1,
        castX,
        castY,
        v13,
        v12,
        150,
        100,
        9,
        2,
        301,
        -40,
        40,
        30,
        1,
        0,
        0,
        1);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[2].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
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
      stack->SpellEffect((unsigned __int8)gsSpellInfo[5].creatureEffectAnimationIdx, 0, 0);
      stack->Cure(spellpower);
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
      break;
    case SPELL_SLOW:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SLOW, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[11].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HASTE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(0, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[9].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_SHIELD:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SHIELD, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[41].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_DRAGON_SLAYER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_DRAGON_SLAYER, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[37].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLESS:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLESS, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[14].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STONESKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STONESKIN, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[16].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STEELSKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STEELSKIN, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[17].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_CURSE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_CURSE, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[18].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BERZERKER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BERSERKER, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[26].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HYPNOTIZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_HYPNOTIZE, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[31].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_PARALYZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_PARALYZE, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[30].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_ARCHMAGI_DISPEL:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect((unsigned __int8)gsSpellInfo[23].creatureEffectAnimationIdx, 0, 1);
      break;
    case SPELL_DISPEL_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect((unsigned __int8)gsSpellInfo[23].creatureEffectAnimationIdx, 0, 0);
      for (effect = 0; (signed int)effect < 15; ++effect)
        stack->CancelIndividualSpell(effect);
      break;
    case SPELL_BLIND:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLIND, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[13].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLOOD_LUST:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->BloodLustEffect(stack, CREATURE_RED);
      stack->SetSpellInfluence(EFFECT_BLOOD_LUST, 3);
      break;
    case SPELL_ANTI_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_ANTI_MAGIC, spellpower);
      stack->SpellEffect((unsigned __int8)gsSpellInfo[22].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_MEDUSA_PETRIFY:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->TurnToStone(stack);
      break;
    case SPELL_COLD_RING:
      this->Fireball(hexIdx, SPELL_COLD_RING);
      break;
    case SPELL_FIREBALL:
      this->Fireball(hexIdx, 0);
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
      stack->SetSpellInfluence(EFFECT_SHADOW_MARK, 1);
      stack->SpellEffect(gsSpellInfo[SPELL_SHADOW_MARK].creatureEffectAnimationIdx, 0, 0);
      // add graphics
      break;
    default:
      this->DefaultSpell(hexIdx);
      break;
    }
  } else {
    this->ShowSpellCastFailure(stack, proto_spell);
  }
  for (i = 0; i < 2; ++i) {
    for (j = 0; this->numCreatures[i] > j; ++j) {
      v14 = (char *)this + 24234 * i + 1154 * j;
      v15 = (char *)v14 + 13647;
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
      sCmbtHero[this->heroType[this->currentActionSide]].animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    this->heroAnimationType[this->currentActionSide] = 0;
    this->heroAnimationFrameCount[this->currentActionSide] = 0;
    this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
  //WaitEndSample(res, res.sample);
  this->CheckChangeSelector();
}