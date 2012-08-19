#include<stdlib.h>

#include "tied/artifacts.h"
#include "tied/base.h"
#include "tied/spells.h"

#include "tied/adventure/adv.h"

hero::hero() {
	this->idx = 0;
	this->ownerIdx = 0;
	this->x = 0;
	this->y = 0;
	this->factionID = 0;
	this->heroID = 0;
	this->name[0] = '\0';
	heroWin = 0;
	giHeroScreenSrcIndex = -1;
	//this->spellsLearned = (char*)calloc(NUM_SPELLS, sizeof(char));
}

hero::~hero() {
	//free(this->spellsLearned);
}

/*
 *
 * Adding new spells not working, since the list of 
 * spells heroes know is stored in map and savegame files
 *
 * Spells also still missing:
 * 
 * 1) Eagle eye
 * 2) Free spells given in some campaign maps
 * 3) Spell AI
 */

void hero::AddSpell(int spell, int knowledge) {
	this->spellsLearned[spell] = 1;
}

int hero::HasSpell(int spell) {
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
	}
	else {
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
      if (gsSpellInfo[i].attributes & ATTR_COMBAT_SPELL)
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
