#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include "array.h"

#include "tied/base.h"
#include "tied/combat/creatures.h"
#include "tied/game/game.h"

#include "lib/xml/tinyxml2.h"


using namespace tinyxml2;

/*
* Still missing: 
*
* 1) Filenames for projectile icons are still hardcoded in army::LoadResources
* 2) Creature types in high scores (GetMonType)
* 3) Debug menu free creatures (moot point; all menubars are broken,
*                                  and debug mode is not normally accessible)
*/

#define MAX_CREATURES 256
#define RAND_DEFAULT 3

tag_monsterInfo gMonsterDatabase[MAX_CREATURES];

const char* CREATURE_DATA = ".\\DATA\\creatures.xml";

char *cMonFilename[MAX_CREATURES];
char *cArmyFrameFileNames[MAX_CREATURES];
char *gArmyNames[MAX_CREATURES];
char *gArmyNamesPlural[MAX_CREATURES];
int gMonRandBound[MAX_CREATURES][2];

#define ERROR_XML_WRAP(x, e) {if((x) != XML_NO_ERROR) {errorDesc = (e); goto error;}}
#define ERROR_ON_NULL(x, e)     {if((x) == NULL) {errorDesc = (e); goto error;}}

struct attributeNameTableEntry{char* name; int flag;};

attributeNameTableEntry creatureAttributeNameTable[] = {
	{"two-hex", TWO_HEXER},
	{"flies", FLYER},
	{"shoots", SHOOTER},
	{"two-hex-attack", TWO_HEX_ATTACKER},
	{"undead", UNDEAD}
};

void LoadCreatures() {
	char* errorDesc = "";

	tinyxml2::XMLDocument doc;
	ERROR_XML_WRAP(doc.LoadFile(CREATURE_DATA), "Failed to load file");

	for(XMLElement* creat = doc.FirstChildElement()->FirstChildElement();
		creat != NULL;
		creat = creat->NextSiblingElement()) {

			if(strcmp(creat->Name(), "creature") == 0) {
				int id = 0;
				const char* tmp;
				ERROR_XML_WRAP(creat->QueryIntAttribute("id", &id), "Reading id");
				ERROR_ON_NULL(tmp = creat->Attribute("icn"), "Reading icn");
				cMonFilename[id] = strdup(tmp);
				ERROR_ON_NULL(tmp = creat->Attribute("frm"), "Reading frm");
				cArmyFrameFileNames[id] = strdup(tmp);
				//printf("%s\n", cArmyFrameFileNames[id]);
				ERROR_ON_NULL(tmp = creat->Attribute("name-singular"), "Reading name-singular");
				gArmyNames[id] = strdup(tmp);
				ERROR_ON_NULL(tmp = creat->Attribute("name-plural"), "Reading name-plural");
				gArmyNamesPlural[id] = strdup(tmp);


				int cost, fight_value, fight_value_aux, growth, hp, faction, speed,
					attack, defense, shots;
				char* short_name;

				ERROR_XML_WRAP(creat->QueryIntAttribute("cost", &cost), "Reading cost");
				ERROR_XML_WRAP(creat->QueryIntAttribute("fight-value", &fight_value), "Reading fight-value");
				ERROR_XML_WRAP(creat->QueryIntAttribute("fight-value-aux", &fight_value_aux), "Reading fight-value-aux");
				ERROR_XML_WRAP(creat->QueryIntAttribute("growth", &growth), "Reading growth");
				ERROR_XML_WRAP(creat->QueryIntAttribute("hp", &hp), "Reading hp");
				ERROR_XML_WRAP(creat->QueryIntAttribute("faction", &faction), "Reading faction");
				ERROR_XML_WRAP(creat->QueryIntAttribute("speed", &speed), "Reading speed");
				ERROR_XML_WRAP(creat->QueryIntAttribute("attack", &attack), "Reading attack");
				ERROR_XML_WRAP(creat->QueryIntAttribute("defense", &defense), "Reading defense");
				ERROR_XML_WRAP(creat->QueryIntAttribute("shots", &shots), "Reading shots");
				ERROR_XML_WRAP(creat->QueryIntAttribute("fight-value", &fight_value), "Reading fight-value");

				ERROR_ON_NULL(tmp = creat->Attribute("short-name"), "Reading short-name");
				short_name = strdup(tmp);


				int min_damage = 0, max_damage = 0;
				int creature_flags = 0;

				for(XMLElement* subelt = creat->FirstChildElement();
					subelt != NULL;
					subelt = subelt->NextSiblingElement()) {

						if(strcmp(subelt->Name(), "range") == 0) {
							if(strcmp(subelt->Attribute("name"), "damage") == 0) {
								ERROR_XML_WRAP(subelt->QueryIntAttribute("min", &min_damage), "Reading min damage");
								ERROR_XML_WRAP(subelt->QueryIntAttribute("max", &max_damage), "Reading max damage");
							} else if(strcmp(subelt->Attribute("name"), "random-spawn") == 0) {
								ERROR_XML_WRAP(subelt->QueryIntAttribute("min", &gMonRandBound[id][0]),
													"Reading min rand bound");
								ERROR_XML_WRAP(subelt->QueryIntAttribute("max", &gMonRandBound[id][1]),
													"Reading max rand bound");
							} else {
								goto error;
							}
						} else if(strcmp(subelt->Name(), "creature-flag") == 0) {
							int found = 0;
							for(int i = 0; i < SIZEOF_ARRAY(creatureAttributeNameTable); i++) {
								if(strcmp(creatureAttributeNameTable[i].name,
									subelt->Attribute("name")) == 0) {
										creature_flags |= creatureAttributeNameTable[i].flag;
										found = 1;
								}
							}
							if(!found) goto error;
						} else {
							goto error;
						}
				}

				gMonsterDatabase[id] = tag_monsterInfo(cost, fight_value, fight_value_aux, growth, hp, faction,
														speed, attack, defense, min_damage, max_damage, shots,
														short_name, creature_flags, 0);
				free(short_name);
														
			} else {
				goto error;
			}
	}
	return;

error:
	char *format = "Error when reading creaure file: %s";
	int len = strlen(format)+strlen(errorDesc);
	char *buf = (char*)malloc(sizeof(char*)*len);
	_snprintf(buf, len, format, errorDesc);
	MessageBox(NULL, buf, NULL, MB_OK|MB_ICONERROR);
	free(buf);
	exit(1);
}

void UnloadCreatures() {
	for(int i = 0; i < MAX_CREATURES; i++) {
		if(cMonFilename[i] != NULL) free(cMonFilename[i]);
		if(cArmyFrameFileNames[i] != NULL) free(cArmyFrameFileNames[i]);
		if(gArmyNames[i] != NULL) free(gArmyNames[i]);
		if(gArmyNamesPlural[i] != NULL) free(gArmyNamesPlural[i]);
	}
}

/*
 * The original script used to move the creature tables into XML.
 * Preserved as an example.
 */
/*
void main() {
	FILE* f = fopen("creatures.xml", "w");
	XMLPrinter printer(f);

	printer.OpenElement("creatures");

	for(int i = 0; i < 73; i++) {
		printer.OpenElement("creature");

		printer.PushAttribute("id", i);
		printer.PushAttribute("name-singular", gArmyNames[i]);
		printer.PushAttribute("name-plural", gArmyNamesPlural[i]);
		printer.PushAttribute("icn", cMonFilename[i]);
		printer.PushAttribute("frm", cArmyFrameFileNames[i]);

		tag_monsterInfo* m = &gMonsterDatabase[i];

		printer.PushAttribute("cost", m->cost);
		printer.PushAttribute("fight-value", m->fight_value);
		printer.PushAttribute("fight-value-aux", m->fight_value_aux);
		printer.PushAttribute("growth", m->growth);
		printer.PushAttribute("hp", m->hp);
		printer.PushAttribute("faction", m->faction);
		printer.PushAttribute("speed", m->speed);
		printer.PushAttribute("attack", m->attack);
		printer.PushAttribute("defense", m->defense);
		printer.PushAttribute("shots", m->shots);
		printer.PushAttribute("short-name", m->short_name);


		printer.OpenElement("range");
		printer.PushAttribute("name", "damage");
		printer.PushAttribute("min", m->min_damage);
		printer.PushAttribute("max", m->max_damage);
		printer.CloseElement();

		char* names[] = {"two-hex", "flies", "shoots", "two-hex-attack", "dead", "","","","","","undead"};
		for(int i = 0; i < 11; i++) {
			if(m->creature_flags & (1<<i)) {
				printer.OpenElement("creature-flag");
				printer.PushAttribute("name", names[i]);
				printer.CloseElement();
			}
		}

		printer.OpenElement("range");
		printer.PushAttribute("name", "random-spawn");
		printer.PushAttribute("min", gMonRandBound[i][0]);
		printer.PushAttribute("max", gMonRandBound[i][1]);
		printer.CloseElement();

		printer.CloseElement();
	}
	printer.CloseElement();
	fclose(f);	
}*/