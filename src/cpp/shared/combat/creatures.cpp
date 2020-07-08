#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include "array.h"

#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/dialog.h"

#include "xml/creature_xml.h"


#include<iostream>
#include<sstream>

using namespace std;

/*
* Still missing: 
*
* 1) Filenames for projectile icons are still hardcoded in army::LoadResources
* 2) Creature types in high scores (GetMonType)
* 3) Debug menu free creatures
*/

#define RAND_DEFAULT 3

std::vector<CREATURES> CREATURES_RANDOMIZABLE;

tag_monsterInfo gMonsterDatabase[MAX_CREATURES];

const char* CREATURE_DATA = ".\\DATA\\creatures.xml";

int giNumCreatures;
char *cMonFilename[MAX_CREATURES];
char *cArmyFrameFileNames[MAX_CREATURES];
char *gArmyNames[MAX_CREATURES];
char *gArmyNamesPlural[MAX_CREATURES];
int gMonRandBound[MAX_CREATURES][2];
int gMonSecondaryResourceCost[MAX_CREATURES][NUM_SECONDARY_RESOURCES];
char *cArmyProjectileFileNames[MAX_CREATURES];

attributeNameTableEntry creatureAttributeNameTable[5] = {
	{"two-hex", TWO_HEXER},
	{"flies", FLYER},
	{"shoots", SHOOTER},
	{"two-hex-attack", TWO_HEX_ATTACKER},
	{"undead", UNDEAD}
};

SecondaryResourceNameTableEntry SecondaryResourceNameTable[] = {
	{"wood", RESOURCE_WOOD},
	{"mercury", RESOURCE_MERCURY},
	{"ore", RESOURCE_ORE},
	{"sulfur", RESOURCE_SULFUR},
	{"crystal", RESOURCE_CRYSTAL},
	{"gems", RESOURCE_GEMS}
};

std::vector<std::string> ironfistAttributeNames = { STRIKE_AND_RETURN, PLASMA_BLAST, TELEPORTER, ASTRAL_DODGE, SHADOW_MARK, JUMPER, CHARGER};
std::vector<std::vector<int>> ironfistAttributeTable;

void ResetCreatureAttributes() {
  ironfistAttributeTable.clear();
  for(int j = 0; j < (int)ironfistAttributeNames.size(); j++) {
    std::vector<int> tmp;
    for(int i = 0; i < MAX_CREATURES; i++) {
      tmp.push_back(0);
    }    
    ironfistAttributeTable.push_back(tmp);
  }
}

void GrantCreatureAttribute(int id, std::string name) {
	for(int i = 0; i < (int)ironfistAttributeNames.size(); i++) {
		if(ironfistAttributeNames[i] == name) {
			ironfistAttributeTable[i][id] = 1;
			return;
		}
	}

	EarlyShutdown(&name[0], "Attempted to grant attribute that does not exist. Check creatures.xml .");
}

int CreatureHasAttribute(int id, const std::string &name) {
  if(id == -1)
    return 0;
  for(int i = 0; i < (int)ironfistAttributeNames.size(); i++) {
    if(ironfistAttributeNames[i] == name) {
      return ironfistAttributeTable[i][id];
    }
  }
  return 0;
}

char* GetCreatureName(int id) {
	return gArmyNames[id];
}

char* GetCreaturePluralName(int id) {
	return gArmyNamesPlural[id];
}

char *__fastcall GetMonsterName(int id) {
  return GetCreatureName(id);
}

int GetNumCreatures() {
	return giNumCreatures;
}

void LoadCreatures() {
	ResetCreatureAttributes();

  CreatureXML xmlDoc;
  tinyxml2::XMLError err = xmlDoc.Read(CREATURE_DATA);
  if(err) {
    H2MessageBox("Could not load XML. " + std::string(xmlDoc.GetError()));
    exit(1);
  }

  for(int i = 0; i <= MAX_BASE_CREATURE; i++)
    CREATURES_RANDOMIZABLE.push_back((CREATURES)i);
  for(int i = MIN_IRONFIST_CREATURE; i <= MAX_IRONFIST_CREATURE; i++)
    CREATURES_RANDOMIZABLE.push_back((CREATURES)i);
}

void UnloadCreatures() {
	for(int i = 0; i < MAX_CREATURES; i++) {
		if(cMonFilename[i] != NULL) free(cMonFilename[i]);
		if(cArmyFrameFileNames[i] != NULL) free(cArmyFrameFileNames[i]);
		if(gArmyNames[i] != NULL) free(gArmyNames[i]);
		if(gArmyNamesPlural[i] != NULL) free(gArmyNamesPlural[i]);
	}
}

void __fastcall GetMonsterCost(int mon, int *const costs) {
	for (int i = 0; i < NUM_SECONDARY_RESOURCES; i++) {
		costs[i] = gMonSecondaryResourceCost[mon][i];
	}
        
	costs[RESOURCE_GOLD] = gMonsterDatabase[mon].cost;
}
