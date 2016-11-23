#include<stdlib.h>

#include "artifacts.h"
#include "base.h"
#include "spell/spells.h"

#include "adventure/adv.h"
#include "game/game.h"

#include<io.h>
#include<stddef.h>

char cHeroTypeInitial[13] ={'k', 'b', 's', 'w', 'z', 'n',
	                        '\0','\0','\0','\0','\0','\0',
                            'c'};

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

int hero::GetLevel() {
	return this->oldLevel;
}

void hero::TakeArtifact(int art) {
	for(int i = 0; i < 14; i++) {
		if(this->artifacts[i] == art) {
			this->artifacts[i] = -1;
			GiveTakeArtifactStat(this, this->artifacts[i], 1);
			break;
		}
	}
}

int hero::CalcMobility() {
	int points;
	signed int playerIdxi;
	int MAX_CREATURE_TERM_MOVEMENT_POINTS = 1500;
	int PLAYER_FIRST = 0;
	int PLAYER_LAST = 5;

	float gfSSLogisticsMod[] = { 1.0,  1.1,  1.2,  1.3 };

	mapCell* cell = gpAdvManager->GetCell(this->x, this->y);
	if ((cell->objType & 0x7F) != LOCATION_TOWN) {
		return this->CalcMobility_orig();
	}

	points = MAX_CREATURE_TERM_MOVEMENT_POINTS;
	points = (signed __int64)((double)points * gfSSLogisticsMod[GetSSLevel(SECONDARY_SKILL_LOGISTICS)]);
	if (this->HasArtifact(ARTIFACT_NOMAD_BOOTS_OF_MOBILITY)) {
		points += 600;
	}
	if (this->HasArtifact(ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY)) {
		points += 300;
	}
	if (this->flags & HERO_AT_SEA) {
		points += 400;
	}
	if (this->HasArtifact(ARTIFACT_TRUE_COMPASS_OF_MOBILITY)) {
		points += 500;
	}
	if (this->ownerIdx >= PLAYER_FIRST) {
		if (this->ownerIdx <= PLAYER_LAST) {
			if (!gbHumanPlayer[ownerIdx]) {
				if (gpGame->difficulty >= 2) {
					points += 75;
					if (gpGame->players[ownerIdx].personality == 2) {
						points += 50;
					}
				}
			}
		}
	}
	return points;
}

hero* GetCurrentHero() {
  return &gpGame->heroes[gpCurPlayer->curHeroIdx];
}