#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include "array.h"

#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"

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

#define MAX_CREATURES 256
#define RAND_DEFAULT 3

tag_monsterInfo gMonsterDatabase[MAX_CREATURES];

const char* CREATURE_DATA = ".\\DATA\\creatures.xml";

int giNumCreatures;
char *cMonFilename[MAX_CREATURES];
char *cArmyFrameFileNames[MAX_CREATURES];
char *gArmyNames[MAX_CREATURES];
char *gArmyNamesPlural[MAX_CREATURES];
int gMonRandBound[MAX_CREATURES][2];

struct attributeNameTableEntry{char* name; int flag;};

attributeNameTableEntry creatureAttributeNameTable[] = {
	{"two-hex", TWO_HEXER},
	{"flies", FLYER},
	{"shoots", SHOOTER},
	{"two-hex-attack", TWO_HEX_ATTACKER},
	{"undead", UNDEAD}
};

char* ironfistAttributeNames[] = {STRIKE_AND_RETURN};
int ironfistAttributeTable[ELEMENTS_IN(ironfistAttributeNames)][MAX_CREATURES];

void ResetCreatureAttributes() {
	memset(ironfistAttributeTable, 0, sizeof(ironfistAttributeTable));
}

void GrantCreatureAttribute(int id, const char* name) {
	for(int i = 0; i < ELEMENTS_IN(ironfistAttributeNames); i++) {
		if(0 == strcmp(ironfistAttributeNames[i], name)) {
			ironfistAttributeTable[i][id] = 1;
			return;
		}
	}

	EarlyShutdown((char*)name, "Attempted to grant attribute that does not exist. Check creatures.xml .");
}

int CreatureHasAttribute(int id, const char* name) {
	for(int i = 0; i < ELEMENTS_IN(ironfistAttributeNames); i++) {
		if(0 == strcmp(ironfistAttributeNames[i], name)) {
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
				gMonRandBound[id][0] = c.random_spawn().begin()->minimum();
				gMonRandBound[id][1] = c.random_spawn().begin()->maximum();

				giNumCreatures++;

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
							GrantCreatureAttribute(id, j->name().c_str());
						}
				}
				int creature_secondary_cost_id;
				if (c.secondary_cost_id() == "wood") {
					creature_secondary_cost_id = 0;
				}
				else if (c.secondary_cost_id() == "mercury") {
					creature_secondary_cost_id = 1;
				}
				else if (c.secondary_cost_id() == "ore") {
					creature_secondary_cost_id = 2;
				}
				else if (c.secondary_cost_id() == "sulfur") {
					creature_secondary_cost_id == 3;
				}
				else if (c.secondary_cost_id() == "crystal") {
					creature_secondary_cost_id == 4;
				}
				else if (c.secondary_cost_id() == "gems") {
					creature_secondary_cost_id == 5;
				}
				else {
					creature_secondary_cost_id == 6;
				}
				
				gMonsterDatabase[id] = tag_monsterInfo(
					c.cost(),
					creature_secondary_cost_id,
					c.secondary_cost(),
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
	} catch(const xml_schema::exception& e) {
		EarlyShutdown("Startup Error", "Error loading creatures.xml. Try reinstalling Ironfist.");
	}
}

void UnloadCreatures() {
	for(int i = 0; i < MAX_CREATURES; i++) {
		if(cMonFilename[i] != NULL) free(cMonFilename[i]);
		if(cArmyFrameFileNames[i] != NULL) free(cArmyFrameFileNames[i]);
		if(gArmyNames[i] != NULL) free(gArmyNames[i]);
		if(gArmyNamesPlural[i] != NULL) free(gArmyNamesPlural[i]);
	}
}

void __fastcall GetMonsterCost(int mon, int *const costs)
{
	if (gMonsterDatabase[mon].secondary_cost_id < 6) {
		int i;
		for (i = 0; i < 6; ++i)
			costs[i] = 0;
		costs[6] = gMonsterDatabase[mon].cost;
		costs[gMonsterDatabase[mon].secondary_cost_id] = gMonsterDatabase[mon].secondary_cost;
	}
	else {
		GetMonsterCost_orig(mon, costs);
	}
	return;
}