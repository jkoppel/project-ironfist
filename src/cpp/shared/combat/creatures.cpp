#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include "array.h"

#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/dialog.h"

#include "combat/creatures_xml.hxx"


#include<iostream>
#include<sstream>

using namespace std;

//using namespace tinyxml2;

/*
* Still missing: 
*
* 1) Filenames for projectile icons are still hardcoded in army::LoadResources
* 2) Creature types in high scores (GetMonType)
* 3) Debug menu free creatures
*/

#define RAND_DEFAULT 3

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

struct attributeNameTableEntry{char* name; int flag;};

attributeNameTableEntry creatureAttributeNameTable[] = {
	{"two-hex", TWO_HEXER},
	{"flies", FLYER},
	{"shoots", SHOOTER},
	{"two-hex-attack", TWO_HEX_ATTACKER},
	{"undead", UNDEAD}
};

struct SecondaryResourceNameTableEntry { string name; int resource_id; };
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

int GetNumCreatures() {
	return giNumCreatures;
}

void LoadCreatures() {

	ResetCreatureAttributes();

	try {
		auto_ptr<creatures_t> creats = creatures(string(CREATURE_DATA));

		giNumCreatures = 0;

		for(creatures_t::creature_const_iterator i(creats->creature().begin());
			i != creats->creature().end();
			i++) {
				creature_t c = *i;
				c.damage().begin()->minimum();

				int id = c.id();

				cMonFilename[id] = strdup(c.icn().c_str());
				cArmyFrameFileNames[id] = strdup(c.frm().c_str());
				gArmyNames[id] = strdup(c.name_singular().c_str());
				gArmyNamesPlural[id] = strdup(c.name_plural().c_str());
				cArmyProjectileFileNames[id] = strdup(c.projectile().c_str());
				gMonRandBound[id][0] = c.random_spawn().begin()->minimum();
				gMonRandBound[id][1] = c.random_spawn().begin()->maximum();

                if (id > giNumCreatures)
                    giNumCreatures = id;

				int creature_flags = 0;
				for(creature_t::creature_attribute_const_iterator j = c.creature_attribute().begin();
					j != c.creature_attribute().end();
					j++) {
						bool attr_found = false; 
						for(int k = 0; k < ELEMENTS_IN(creatureAttributeNameTable); k++) {
							if(strcmp(creatureAttributeNameTable[k].name,
								 j->name().c_str())
								== 0){
									creature_flags |= creatureAttributeNameTable[k].flag;
									attr_found = true;
									break;
							}
						}

						if(!attr_found) {
							//Ironfist-only attribute; using general attribute engine
							GrantCreatureAttribute(id, j->name());
						}
				}

				for (int i = 0; i < NUM_SECONDARY_RESOURCES ; i++) {
					gMonSecondaryResourceCost[id][i] = 0;
				}

				bool customed_secondary_cost = false;

				for (creature_t::secondary_cost_iterator i = c.secondary_cost().begin();
				     i != c.secondary_cost().end();
					 ++i) {
					    for (int k = 0; k < NUM_SECONDARY_RESOURCES; k++) {
						   if (SecondaryResourceNameTable[k].name == i->resource()) {
							   if (!customed_secondary_cost) {
								   gMonSecondaryResourceCost[id][SecondaryResourceNameTable[k].resource_id] = i->cost();
								   customed_secondary_cost = true;
							   }
							   else {
								   string error_message = "Error loading creatures.xml.\nToo many secondary resource costs for creature "
									                      + c.name_singular() + "!";
								   EarlyShutdown("Startup Error", (char *)error_message.c_str());
							   }
							       
						   }
					    }
				}
				
				gMonsterDatabase[id] = tag_monsterInfo(
					c.cost(),
					c.fight_value(),
					c.fight_value_aux(),
					c.growth(),
					c.hp(),
					c.faction(),
					c.speed(),
					c.attack(),
					c.defense(),
					c.damage().begin()->minimum(),
					c.damage().begin()->maximum(),
					c.shots(),
					c.short_name().c_str(),
					creature_flags,
					0);
				
		}
	} catch(const xml_schema::exception&) {
		EarlyShutdown("Startup Error", "Error loading creatures.xml. Try reinstalling Ironfist.");
	}
    giNumCreatures++;
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
