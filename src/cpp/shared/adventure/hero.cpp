#include <map>
#include<stdlib.h>

#include "artifacts.h"
#include "base.h"
#include "gui/dialog.h"
#include "scripting/callback.h"
#include "scripting/deepbinding.h"
#include "skills.h"
#include "sound/sound.h"
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

signed __int8 gHeroSkillBonus[MAX_FACTIONS][2][NUM_PRIMARY_SKILLS] = {
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
  {0, 0, 2, 2}
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

unsigned char iGetSSByAlignment[NUM_SECONDARY_SKILLS][MAX_FACTIONS] = {
  {3,4,2,2,2,3,0,0,0,0,0,0,3},
  {2,3,3,1,1,1,0,0,0,0,0,0,2},
  {3,3,2,2,2,2,0,0,0,0,0,0,3},
  {2,4,1,4,2,1,0,0,0,0,0,0,2},
  {3,2,2,2,2,2,0,0,0,0,0,0,3},
  {2,3,4,2,2,2,0,0,0,0,0,0,2},
  {5,3,1,1,2,0,0,0,0,0,0,0,5},
  {2,1,4,5,5,4,0,0,0,0,0,0,2},
  {1,1,3,3,4,3,0,0,0,0,0,0,1},
  {1,2,3,1,2,1,0,0,0,0,0,0,1},
  {4,3,3,3,3,3,0,0,0,0,0,0,4},
  {1,1,2,3,3,3,0,0,0,0,0,0,1},
  {0,0,0,1,0,10,0,0,0,0,0,0,0},
  {3,2,2,2,2,2,0,0,0,0,0,0,3}
};

std::map<int, Spell> cyborgLvlUpSpells = {
  {3, SPELL_ARMAGEDDON},
  {5, SPELL_BERZERKER}
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

void hero::Write(int fd, signed char expansion) {
	_write(fd, this, offsetof(hero, spellsLearned));
	_write(fd, this->spellsLearned, ORIG_SPELLS);
	if(expansion) {
		_write(fd, &this->FIELD_AFTER_SPELLS_LEARNED, sizeof(hero)-offsetof(hero, FIELD_AFTER_SPELLS_LEARNED));
	} else {
		_write(fd, &this->FIELD_AFTER_SPELLS_LEARNED,
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
      auto res = ScriptCallbackResult<int>("OnCalcMobility", deepbind<hero*>(this), points);
      if(res.has_value())
        points = max(1, res.value());
      return points;
    }
  }

  points = this->CalcMobility_orig(); //Default CalcMobility output
  auto res = ScriptCallbackResult<int>("OnCalcMobility", deepbind<hero*>(this), points);
  if(res.has_value())
    points = max(1, res.value());
  return points;
}

hero* GetCurrentHero() {
  return &gpGame->heroes[gpCurPlayer->curHeroIdx];
}

extern int gSSValues[NUM_SECONDARY_SKILLS][3];

void hero::CheckLevel() {
	int newLevel = this->GetLevel(this->experience);
	if(this->oldLevel == newLevel)
		return;

	SAMPLE2 res;
	res.file = NULL_SAMPLE2.file;
	res.sample = NULL_SAMPLE2.sample;
	int pSkillGained[NUM_PRIMARY_SKILLS];

	for(int i = this->oldLevel + 1; i <= newLevel; ++i) {
		sprintf(gText, "%s has gained a level.\n", this->name);		
		
		int pSkillChance[NUM_PRIMARY_SKILLS];
		for(int j = 0; j < NUM_PRIMARY_SKILLS; j++)
		{
			pSkillGained[j] = 0;
			if(i > 9)
				pSkillChance[j] = gHeroSkillBonus[this->factionID][1][j];
			else
				pSkillChance[j] = gHeroSkillBonus[this->factionID][0][j];
		}

		SRand(30 * i + this->randomSeed);
		int randNum = SRandom(1, 100);
		if(pSkillChance[PRIMARY_SKILL_ATTACK] <= randNum) {
			int chanceDiff = randNum - pSkillChance[PRIMARY_SKILL_ATTACK];
			if(pSkillChance[PRIMARY_SKILL_DEFENSE] <= chanceDiff) {
				if(pSkillChance[PRIMARY_SKILL_SPELLPOWER] <= chanceDiff - pSkillChance[PRIMARY_SKILL_DEFENSE])
					pSkillGained[PRIMARY_SKILL_KNOWLEDGE]++;
				else
					pSkillGained[PRIMARY_SKILL_SPELLPOWER]++;
			} else {
				pSkillGained[PRIMARY_SKILL_DEFENSE]++;
			}
		} else {
			pSkillGained[PRIMARY_SKILL_ATTACK]++;
		}

		for(int j = 0; j < NUM_PRIMARY_SKILLS; ++j) {
			if(pSkillGained[j] > 0) {
				this->primarySkills[j] += pSkillGained[j];
				sprintf(gText, "%s\n%s +%d", gText, gStatNames[j], pSkillGained[j]);
			}
		}

		int secSkillOptions[2];
		for(int j = 0; j < 2; ++j) {
			secSkillOptions[j] = -1;
			if(j
				|| this->factionID == FACTION_BARBARIAN
				|| this->factionID == FACTION_KNIGHT
				|| this->secondarySkillLevel[SECONDARY_SKILL_WISDOM] >= 3
				|| i - this->wisdomLastOffered < 3) {
				int v3 = 0;
				int v6 = Random(0, 200);
				int sSkill = 0;
				while(v3 < 5000) {
					++v3;
					int level = this->secondarySkillLevel[sSkill];
					if((!j || secSkillOptions[0] != sSkill)
						&& (level && level < 3
							|| !level && this->numSecSkillsKnown < 8)) {
						v6 -= iGetSSByAlignment[sSkill][this->factionID];
						if(v6 <= 0) {
							secSkillOptions[j] = sSkill;
							break;
						}
					}
					sSkill = (sSkill + 1) % NUM_SECONDARY_SKILLS;
				}
			} else {
				secSkillOptions[j] = SECONDARY_SKILL_WISDOM;
			}
		}

		if(secSkillOptions[0] == SECONDARY_SKILL_WISDOM || secSkillOptions[1] == SECONDARY_SKILL_WISDOM)
			this->wisdomLastOffered = i;

		if(gbInNewGameSetup || this->ownerIdx < 0 || !gbThisNetHumanPlayer[this->ownerIdx]) {
			if(secSkillOptions[0] != -1) {
				if(secSkillOptions[1] == -1) {
					this->GiveSS(secSkillOptions[0], 1);
				} else {
					if(gSSValues[secSkillOptions[1]][0] >= gSSValues[secSkillOptions[0]][0])
						this->GiveSS(secSkillOptions[1], 1);
					else
						this->GiveSS(secSkillOptions[0], 1);
				}
			}
		} else {
			res = LoadPlaySample("nwherolv.82m");
			if(secSkillOptions[0] == -1) {
				NormalDialog(gText, DIALOG_OKAY, -1, -1, -1, 0, -1, 0, -1, 0);
			} else {
				if(secSkillOptions[1] == -1) {
					int imgArg;
					if(this->factionID == FACTION_CYBORG && secSkillOptions[1] == SECONDARY_SKILL_WISDOM) {
						sprintf(gText,
							"%s\n\nYou have learned %s Cybernetics.",
							gText,
							secondarySkillLevels[this->secondarySkillLevel[secSkillOptions[0]] + 1]);
						imgArg = 3 * 15 + this->secondarySkillLevel[secSkillOptions[0]];
					} else {
						sprintf(gText,
							"%s\n\nYou have learned %s %s.",
							gText,
							secondarySkillLevels[this->secondarySkillLevel[secSkillOptions[0]] + 1],
							gSecondarySkills[secSkillOptions[0]]);
						imgArg = 3 * secSkillOptions[0] + this->secondarySkillLevel[secSkillOptions[0]];
					}
					NormalDialog(
						gText,
						DIALOG_OKAY,
						-1,
						-1,
						17,
						3 * secSkillOptions[0] + this->secondarySkillLevel[secSkillOptions[0]],
						-1,
						0,
						-1,
						0);
					this->GiveSS(secSkillOptions[0], 1);
				} else {
					std::string sSkillNames[2];
					int imgIdxs[2];
					for(int i = 0; i < 2; i++) {
						if(this->factionID == FACTION_CYBORG && secSkillOptions[i] == SECONDARY_SKILL_WISDOM) {
							sSkillNames[i] = "Cybernetics";
							imgIdxs[i] = 3 * 15 + this->secondarySkillLevel[secSkillOptions[i]];
						} else {
							sSkillNames[i] = gSecondarySkills[secSkillOptions[i]];
							imgIdxs[i] = 3 * secSkillOptions[i] + this->secondarySkillLevel[secSkillOptions[i]];
						}
					}					
					sprintf(
						gText,
						"%s\n\nYou may learn either %s %s or %s %s.",
						gText,
						secondarySkillLevels[this->secondarySkillLevel[secSkillOptions[0]] + 1],
						sSkillNames[0].c_str(),
						secondarySkillLevels[this->secondarySkillLevel[secSkillOptions[1]] + 1],
						sSkillNames[1].c_str());
					NormalDialog(
						gText,
						DIALOG_LEARN_CHOICE,
						-1,
						-1,
						17,
						imgIdxs[0],
						17,
						imgIdxs[1],
						-1,
						0);
					if(gpWindowManager->buttonPressedCode == BUTTON_LEARN_LEFT)
						this->GiveSS(secSkillOptions[0], 1);
					else
						this->GiveSS(secSkillOptions[1], 1);
				}
			}
		}
	}
	

	if(this->factionID == FACTION_CYBORG && this->ownerIdx != -1) {
		int levelsGained = newLevel - this->oldLevel;
		if(levelsGained > 0) {
			for(int i = 0; i < levelsGained; i++) {
				int lvlToCheck = this->oldLevel + i + 1;
				if(cyborgLvlUpSpells.find(lvlToCheck) != cyborgLvlUpSpells.end()) {
					int spell = cyborgLvlUpSpells[lvlToCheck];
					this->AddSpell(spell);
					if(gbHumanPlayer[this->ownerIdx])
						gpAdvManager->EventWindow(-1, 1, "You've learned a new spell!", 8, spell, -1, 0, -1);
				}
			}
		}		
	}

	this->oldLevel = newLevel;
	WaitEndSample(res, res.sample);
}

char *cyberneticsDesc[3] = {
	"{Basic Cybernetics}\n\nBasic Pathfinding reduces the movement penalty for rough terrain by 25 percent.",
	"{Advanced Cybernetics}\n\nAdvanced Pathfinding reduces the movement penalty for rough terrain by 50 percent.",
	"{Expert Cybernetics}\n\nExpert Pathfinding eliminates the movement penalty for rough terrain."
};

void hero::DoSSLevelDialog(int skill, int rightClick) {
	if(this->factionID == FACTION_CYBORG && skill == SECONDARY_SKILL_WISDOM) {
		int level = this->secondarySkillLevel[skill];
		if(level > 0) {
			sprintf(gText, "%s", cyberneticsDesc[level - 1]);
			NormalDialog(
				gText,
				rightClick < 1 ? DIALOG_OKAY : DIALOG_RIGHT_CLICK,
				-1,
				-1,
				17,
				45 + level - 1, // Cybernetics frame
				-1,
				0,
				-1,
				0);
			return;
		}
	}
	return this->DoSSLevelDialog_orig(skill, rightClick);
}