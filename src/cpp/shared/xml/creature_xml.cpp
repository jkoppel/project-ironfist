#include "xml/creature_xml.h"

#include "combat/creatures.h"

using namespace UtilsXML;

void ReadCreatureData(tinyxml2::XMLNode* root) {
  giNumCreatures = 0;

  for(tinyxml2::XMLNode* creature = root->FirstChild(); creature; creature = creature->NextSibling()) {
    tinyxml2::XMLElement *crElem = creature->ToElement();
    int id = crElem->IntAttribute("id");

    QueryTextAttribute(crElem, "icn", &cMonFilename[id]);
    QueryTextAttribute(crElem, "frm", &cArmyFrameFileNames[id]);
    QueryTextAttribute(crElem, "name-singular", &gArmyNames[id]);
    QueryTextAttribute(crElem, "name-plural", &gArmyNamesPlural[id]);
    QueryTextAttribute(crElem, "projectile", &cArmyProjectileFileNames[id]);

    int minDamage, maxDamage, randMin, randMax, creature_flags;
    minDamage = maxDamage = randMin = randMax = creature_flags = 0;
    
    for (int i = 0; i < NUM_SECONDARY_RESOURCES ; i++) {
	    gMonSecondaryResourceCost[id][i] = 0;
    }

    for(tinyxml2::XMLNode* property = crElem->FirstChild(); property; property = property->NextSibling()) {
      tinyxml2::XMLElement *propElem = property->ToElement();
      std::string name = propElem->Name();
      if(name == "damage") {
        minDamage = propElem->IntAttribute("minimum");
        maxDamage = propElem->IntAttribute("maximum");
      } else if(name == "random-spawn") {
        gMonRandBound[id][0] = propElem->IntAttribute("minimum");
        gMonRandBound[id][1] = propElem->IntAttribute("maximum");
      } else if(name == "creature-attribute") {
        bool attr_found = false;
        char *attrName = QueryTextAttribute(propElem, "name");
        for(int k = 0; k < ELEMENTS_IN(creatureAttributeNameTable); k++) {
          if(!strcmp(creatureAttributeNameTable[k].name, attrName)) {
            creature_flags |= creatureAttributeNameTable[k].flag;
            attr_found = true;
            break;
          }
        }

        if(!attr_found) {
          //Ironfist-only attribute; using general attribute engine
          GrantCreatureAttribute(id, QueryTextAttribute(propElem, "name"));
        }
      } else if(name == "secondary-cost") {
          bool customed_secondary_cost = false;
          for(int k = 0; k < NUM_SECONDARY_RESOURCES; k++) {
            if(SecondaryResourceNameTable[k].name == std::string(QueryTextAttribute(propElem, "resource"))) {
              if(!customed_secondary_cost) {
                gMonSecondaryResourceCost[id][SecondaryResourceNameTable[k].resource_id] = propElem->IntAttribute("cost");
                customed_secondary_cost = true;
              } else {
                std::string error_message = "Error loading creatures.xml.\nToo many secondary resource costs for creature "
                  + std::string(gArmyNames[id]) + "!";
                EarlyShutdown("Startup Error", (char *)error_message.c_str());
              }
            }
          }
        }
    }

    if(id > giNumCreatures)
      giNumCreatures = id;
		
    tag_monsterInfo info;
    info.cost = (short)crElem->IntAttribute("cost");
    info.fight_value = crElem->IntAttribute("fight-value");
    info.fight_value_aux = (char)crElem->IntAttribute("fight-value-aux");
    info.growth = (char)crElem->IntAttribute("growth");
    info.hp = (short)crElem->IntAttribute("hp");
    info.faction = (char)crElem->IntAttribute("faction");
    info.speed = (char)crElem->IntAttribute("speed");
    info.attack = (char)crElem->IntAttribute("attack");
    info.defense = (char)crElem->IntAttribute("defense");
    info.min_damage = minDamage;
    info.max_damage = maxDamage;
    info.shots = (char)crElem->IntAttribute("shots");
    strcpy(info.short_name, QueryTextAttribute(crElem, "short-name"));
    info.creature_flags = creature_flags;
    gMonsterDatabase[id] = info;
  }
  giNumCreatures++;
}

tinyxml2::XMLError CreatureXML::Read(const char* fileName) {
  tinyxml2::XMLError eResult = tempDoc->LoadFile(fileName);
  if(!eResult) {
    tinyxml2::XMLNode *pRoot = tempDoc->FirstChild();
    ReadCreatureData(pRoot);
  }
  return eResult;
}