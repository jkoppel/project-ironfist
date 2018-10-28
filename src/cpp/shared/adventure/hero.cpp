#include<stdlib.h>

#include "artifacts.h"
#include "base.h"
#include "skills.h"
#include "spell/spells.h"

#include "adventure/adv.h"
#include "game/game.h"

#include<io.h>
#include<stddef.h>

char cHeroTypeInitial[MAX_FACTIONS] = {'k', 'b', 's', 'w', 'z', 'n',
                                       '\0','\0','\0','\0','\0','\0',
                                       'c'};

extern char* cHeroTypeShortName[MAX_FACTIONS] = {
  "kngt", "barb", "sorc", "wrlk", "wzrd", "necr",
  "", "", "", "", "", "",
  "cbrg"
};

signed __int8 gHeroSkillBonus[MAX_FACTIONS][2][4] = {
  {{35, 45, 10, 10}, {25, 25, 25, 25}},
  {{55, 35,  5,  5}, {25, 25, 25, 25}},
  {{10, 10, 30, 50}, {20, 20, 30, 30}},
  {{10, 10, 50, 30}, {20, 20, 30, 30}},
  {{10, 10, 40, 40}, {20, 20, 30, 30}},
  {{15, 15, 35, 35}, {25, 25, 25, 25}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{ 0,  0,  0,  0}, { 0,  0,  0,  0}},
  {{15, 15, 35, 35}, {25, 25, 25, 25}},  // TODO: decide on Cyborg skill chances, copied Necromancer for now
};

signed __int8 captainStats[MAX_FACTIONS][4] = {
  {1, 1, 1, 1},
  {1, 1, 1, 1},
  {0, 0, 2, 2},
  {0, 0, 2, 2},
  {0, 0, 2, 2},
  {0, 0, 2, 2},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 1, 1, 1}  // TODO: is Cyborg a might or magic hero?
};

extern startingPrimarySkills gStartingHeroStats[MAX_FACTIONS] = {
  {2, 2, 1, 1, 0},
  {3, 1, 1, 1, 0},
  {0, 0, 2, 3, 0},
  {0, 0, 3, 2, 0},
  {0, 1, 2, 2, 0},
  {1, 0, 2, 2, 0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {1, 0, 2, 2, 0}  // TODO: Cyborg hero starting stats, copied Necromancer for now
};

hero::hero() {
	this->spellsLearned = NULL;
	this->Clear();
}

void hero::Clear() {
	this->idx = 0;
	this->ownerIdx = 0;
	this->x = 0;
	this->y = 0;
	this->factionID = 0;
	this->heroID = 0;
	this->name[0] = '\0';
	heroWin = 0;
	giHeroScreenSrcIndex = -1;
	this->ResetSpellsLearned();
}

void hero::ResetSpellsLearned() {	
	if(this->spellsLearned != NULL)
		free(this->spellsLearned);

	this->spellsLearned = (char*)calloc(NUM_SPELLS, sizeof(char));
}

hero::~hero() {
	free(this->spellsLearned);
}

void hero::Read(int fd, signed char expansion) {
	this->Clear();
	_read(fd, this, offsetof(hero, spellsLearned));
	_read(fd, this->spellsLearned, ORIG_SPELLS);
	if(expansion) {
		_read(fd, &this->FIELD_AFTER_SPELLS_LEARNED, sizeof(hero)-offsetof(hero, FIELD_AFTER_SPELLS_LEARNED));
	} else {
		_read(fd, &this->FIELD_AFTER_SPELLS_LEARNED,
			offsetof(hero, LAST_SW_HERO_FIELD)-offsetof(hero, FIELD_AFTER_SPELLS_LEARNED));
	}
}

/*
 *
 * Spells also still missing:
 * 
 * 1) Eagle eye
 * 2) Free spells given in some campaign maps
 * 3) Spell AI
 */

void hero::AddSpell(int spell) {
	this->AddSpell(spell, 0);
}

void hero::AddSpell(int spell, int knowledge) {
	//The game zeroes out captains at the start of battle.
	//This is a workaround.
	if(this->spellsLearned == NULL)
		this->ResetSpellsLearned();

	this->spellsLearned[spell] = 1;
}

int hero::HasSpell(int spell) {
	//The game zeroes out captains at the start of battle
	//This is workaround part 2
	if(this->spellsLearned == NULL)
		return 0;

	if(HasArtifact(ARTIFACT_MAGIC_BOOK)) {
		if(this->spellsLearned[spell]) {
			return 1;
		} else {
			for(int i = 0; i < MAX_ARTIFACTS; i++) {
				if(this->artifacts[i] == ARTIFACT_SPELL_SCROLL && this->scrollSpell[i] == spell)
					return 1;
			}
			return HasArtifact(ARTIFACT_BATTLE_GARB_OF_ANDURAN) && spell == SPELL_TOWN_PORTAL;
		}
	} else {
		return 0;
	}
}

int hero::GetNthSpell(int type, int n) {
	int nSeen = 0;
	for(int i = 0; i < NUM_SPELLS; i++) {
		if(HasSpell(i)) {
			if(type == ATTR_COMBAT_SPELL
				|| !type && gsSpellInfo[i].attributes & ATTR_COMBAT_SPELL
				|| type == SPELL_CATEGORY_ADVENTURE && !(gsSpellInfo[i].attributes & ATTR_COMBAT_SPELL)) {
				++nSeen;
			}
			if (n == nSeen)
				return i;
		}
	}
	return SPELL_NONE;
}

int hero::GetNumSpells(int type) {
  int numCombat = 0;
  int numAdventure = 0;
  for(int i = 0; i < NUM_SPELLS; i++) {
    if(HasSpell(i)) {
      if(gsSpellInfo[i].attributes & ATTR_COMBAT_SPELL)
        numCombat++;
      else
        numAdventure++;
    }
  }
	
  switch(type) {
  case SPELL_CATEGORY_COMBAT:
	  return numCombat;
  case SPELL_CATEGORY_ADVENTURE:
	  return numAdventure;
  case SPELL_CATEGORY_ALL:
	  return numCombat+numAdventure;
  default:
	  return 0;
  }
}

void hero::SetPrimarySkill(int skill, int amt) {
  this->primarySkills[skill] = amt;
}

void hero::ClearSS() {
  for (int i = 0; i < MAX_TOTAL_SECONDARY_SKILLS; ++i) {
    this->secondarySkillLevel[i] = 0;
    this->skillIndex[i] = 0;
  }
  this->numSecSkillsKnown = 0;
}

int hero::GetLevel() {
	return this->oldLevel;
}

void hero::TakeArtifact(int art) {
  for (int i = 0; i < 14; i++) {
    if (this->artifacts[i] == art) {
      GiveTakeArtifactStat(this, this->artifacts[i], 1);
      this->artifacts[i] = -1;
      break;
    }
  }
}

int hero::CountEmptyArtifactSlots() {
  int amount = 0; //The counted amount of empty artifacts that the player has
  for (int i = 0; i < 14; i++) {
    if (this->artifacts[i] == -1) {
      amount++;
    }
  }
  return amount;
}

int hero::CountEmptyCreatureSlots() {	
	int amount = 0;
	for (int i = 0; i < CREATURES_IN_ARMY; i++) {
		if (this->army.creatureTypes[i] == -1) {
			amount++;
		}
	}
	return amount;
}

int hero::CalcMobility() {
  int points;
  int MOVEMENT_POINTS_TERM_CREATURE_MAX = 1500;
  int PLAYER_FIRST = 0;
  int PLAYER_LAST = 5;
  float gfSSLogisticsMod[] = { 1.0f,  1.1f,  1.2f,  1.3f };
  
  mapCell* cell = gpAdvManager->GetCell(this->x, this->y);
  if (cell != nullptr) {  //This is here because CalcMobility() is called on the first successive start of a New Game in the current running instance of the program
    if (cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT)) {  //Non-creature adjusted CalcMobility() output
      points = MOVEMENT_POINTS_TERM_CREATURE_MAX;
      points = (signed __int64)((double)points * gfSSLogisticsMod[GetSSLevel(SECONDARY_SKILL_LOGISTICS)]);
      if (this->flags & HERO_AT_SEA) {
        points += 400;
      }
      if (this->HasArtifact(ARTIFACT_NOMAD_BOOTS_OF_MOBILITY)) {
        points += 600;
      }
      if (this->HasArtifact(ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY)) {
        points += 300;
      }
      if (this->HasArtifact(ARTIFACT_TRUE_COMPASS_OF_MOBILITY)) {
        points += 500;
      }
      if (this->ownerIdx >= PLAYER_FIRST
          && this->ownerIdx <= PLAYER_LAST) {
        if (!gbHumanPlayer[ownerIdx]) {
          if (gpGame->difficulty >= DIFFICULTY_HARD) {
            points += 75;
            if (gpGame->players[ownerIdx].personality == PERSONALITY_EXPLORER) {
              points += 50;
            }
          }
        }
      }
      return points;
    }
  }

  return this->CalcMobility_orig(); //Default CalcMobility output
}

hero* GetCurrentHero() {
  return &gpGame->heroes[gpCurPlayer->curHeroIdx];
}