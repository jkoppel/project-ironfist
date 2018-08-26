#include "base.h"
#include "gui/msg.h"

#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/gui.h"
#include "resource/resources.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "town/town.h"

#include <sstream>
#include <string>


namespace {
  void initTownObjNames() {
    gTownObjNames[0] = "mage";
    gTownObjNames[1] = "thie";
    gTownObjNames[2] = "tvrn";
    gTownObjNames[3] = "dock";
    gTownObjNames[4] = "well";
    gTownObjNames[5] = "tent";
    gTownObjNames[6] = "cstl";
    gTownObjNames[7] = "stat";
    gTownObjNames[8] = "ltur";
    gTownObjNames[9] = "rtur";
    gTownObjNames[10] = "mark";
    gTownObjNames[11] = "wel2";
    gTownObjNames[12] = "moat";
    gTownObjNames[13] = "spec";
    gTownObjNames[14] = "boat";
    gTownObjNames[15] = "capt";
    gTownObjNames[16] = "ext0";
    gTownObjNames[17] = "ext1";
    gTownObjNames[18] = "ext2";
    gTownObjNames[19] = "dw_0";
    gTownObjNames[20] = "dw_1";
    gTownObjNames[21] = "dw_2";
    gTownObjNames[22] = "dw_3";
    gTownObjNames[23] = "dw_4";
    gTownObjNames[24] = "dw_5";
    gTownObjNames[25] = "up_1";
    gTownObjNames[26] = "up_2";
    gTownObjNames[27] = "up_3";
    gTownObjNames[28] = "up_4";
    gTownObjNames[29] = "up_5";
    gTownObjNames[30] = "up5b";
    gTownObjNames[31] = "ext3";
  }
}

unsigned long gTownEligibleBuildMask[NUM_FACTIONS] = {
  0x3FF8BF9F,
  0x1BF8BF9F,
  0xFF8BF9F,
  0x69F8BF9F,
  0x35F8BF9F,
  0x1FF8BF9B,
  0x0,
  0x0,
  0x0,
  0x0,
  0x0,
  0x0,
  0x01F8BF9F  // TODO: decide whether Cyborg creatures have any upgrades
};

extern char *gTownObjNames[32] = {
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4,
  (char*)0x4, (char*)0x4, (char*)0x4, (char*)0x4
};

// Defines the creature types in dwellings 1-6, followed by upgrades 1-5b
// (which are really the tier 2 upgrade through tier 6 second upgrade).
// TODO: do Cyborg creatures have upgrades?
unsigned char gDwellingType[NUM_FACTIONS * NUM_DWELLINGS] = {
  
   CREATURE_PEASANT, CREATURE_ARCHER, CREATURE_PIKEMAN, CREATURE_SWORDSMAN, CREATURE_CAVALRY, CREATURE_PALADIN,
       CREATURE_RANGER, CREATURE_VETERAN_PIKEMAN, CREATURE_MASTER_SWORDSMAN, CREATURE_CHAMPION, CREATURE_CRUSADER, CREATURE_INVALID,
   CREATURE_GOBLIN, CREATURE_ORC, CREATURE_WOLF, CREATURE_OGRE, CREATURE_TROLL, CREATURE_CYCLOPS,
       CREATURE_ORC_CHIEF, CREATURE_INVALID, CREATURE_OGRE_LORD, CREATURE_WAR_TROLL, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_SPRITE, CREATURE_DWARF, CREATURE_ELF, CREATURE_DRUID, CREATURE_UNICORN, CREATURE_PHOENIX,
       CREATURE_BATTLE_DWARF, CREATURE_GRAND_ELF, CREATURE_GREATER_DRUID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_CENTAUR, CREATURE_GARGOYLE, CREATURE_GRIFFIN, CREATURE_MINOTAUR, CREATURE_HYDRA, CREATURE_GREEN_DRAGON,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_MINOTAUR_KING, CREATURE_INVALID, CREATURE_RED_DRAGON, CREATURE_BLACK_DRAGON,
   CREATURE_HALFLING, CREATURE_BOAR, CREATURE_IRON_GOLEM, CREATURE_ROC, CREATURE_MAGE, CREATURE_GIANT,
       CREATURE_INVALID, CREATURE_STEEL_GOLEM, CREATURE_INVALID, CREATURE_ARCHMAGE, CREATURE_TITAN, CREATURE_INVALID,
   CREATURE_SKELETON, CREATURE_ZOMBIE, CREATURE_MUMMY, CREATURE_VAMPIRE, CREATURE_LICH, CREATURE_BONE_DRAGON,
       CREATURE_MUTANT_ZOMBIE, CREATURE_ROYAL_MUMMY, CREATURE_VAMPIRE_LORD, CREATURE_POWER_LICH, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID,
   CREATURE_CYBER_KOBOLD_SPEARMAN, CREATURE_CYBER_PLASMA_BERSERKER, CREATURE_CYBER_PLASMA_LANCER, CREATURE_CYBER_INDIGO_PANTHER, CREATURE_CYBER_SHADOW_ASSASSIN, CREATURE_CYBER_BEHEMOTH,
       CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID, CREATURE_INVALID
};

void game::SetupTowns() {
	initTownObjNames();

	for(int castleIdx = 0; castleIdx < MAX_TOWNS; castleIdx++) {
		if(this->castles[castleIdx].exists) {
			town* castle = &this->castles[castleIdx];
			int extraIdx = this->castles[castleIdx].extraIdx;
			TownExtra* twnExtra = (TownExtra *)ppMapExtra[extraIdx];

			int playerPos;

			if(twnExtra->color == -1)
				playerPos = -1;
			else
				playerPos = gcColorToPlayerPos[twnExtra->color];

			this->ClaimTown(castleIdx, playerPos, 0);
			castle->playerPos = playerPos;

			if(twnExtra->customGarrison) {
				for(int i = 0; i < 5; i++) {
					castle->garrison.quantities[i] = twnExtra->garrison.quantities[i];
					if(castle->garrison.quantities[i] <= 0)
						castle->garrison.creatureTypes[i] = -1;
					else
						castle->garrison.creatureTypes[i] = twnExtra->garrison.creatureTypes[i];
				}

			} else {

				for(int i = 0; i < 5; i++) {
					castle->garrison.quantities[i] = 0;
					castle->garrison.creatureTypes[i] = -1;
				}
				this->GiveTroopsToNeutralTown(castleIdx);
				this->GiveTroopsToNeutralTown(castleIdx);
				this->GiveTroopsToNeutralTown(castleIdx);
				this->GiveTroopsToNeutralTown(castleIdx);
			}

			if(twnExtra->customBuildings ) {
				castle->buildingsBuiltFlags &= (1 << BUILDING_TENT) | (1 << BUILDING_CASTLE);
				castle->buildingsBuiltFlags |= twnExtra->buildingsBuilt & gTownEligibleBuildMask[castle->factionID];
				castle->mageGuildLevel = twnExtra->mageGuildLevel;
			} else {
				castle->buildingsBuiltFlags |= 1 << BUILDING_DWELLING_1;
				castle->mageGuildLevel = 0;

				//If you think this is complicated, then you should see the original code
				if((gbHumanPlayer[castle->ownerIdx] && Random(0, 9) < 3) ||
					(!gbHumanPlayer[castle->ownerIdx] && Random(0, 99) < 51)) {

						castle->buildingsBuiltFlags |= 1 << BUILDING_DWELLING_2;
				}
			}

			for(int i = BUILDING_UPGRADE_1; i <= BUILDING_UPGRADE_5B; i++ ) {
				if(castle->BuildingBuilt(i)) {
					if(i == BUILDING_UPGRADE_5B)
						castle->buildingsBuiltFlags &= ~((1 << BUILDING_DWELLING_6) | (BUILDING_UPGRADE_5B));
					else
						castle->buildingsBuiltFlags &= ~(1 << (i - (BUILDING_UPGRADE_1 - BUILDING_DWELLING_2)));
				}
			}

			for(int i = 0; i < NUM_DWELLINGS; i++) {
				if(castle->DwellingBuilt(i))
					castle->numCreaturesInDwelling[i] = gMonsterDatabase[gDwellingType[castle->factionID * NUM_DWELLINGS + i]].growth;
			}

			if(castle->BuildingBuilt(BUILDING_MAGE_GUILD)) {
				for(int i = 0; i < castle->mageGuildLevel; i++ ) {
					castle->numSpellsOfLevel[i] = gSpellLimits[i];
					if(castle->factionID == FACTION_WIZARD && (castle->BuildingBuilt(BUILDING_SPECIAL)))
						castle->numSpellsOfLevel[i]++;
				}
			}
			if(twnExtra->hasCaptain)
				castle->buildingsBuiltFlags |= 1 << BUILDING_CAPTAIN;

			castle->mayNotBeUpgradedToCastle = twnExtra->disallowCastle;
			strcpy(castle->name, twnExtra->name);

			castle->SelectSpells();

			FREE(ppMapExtra[extraIdx]);
			ppMapExtra[extraIdx] = NULL;
		}
	}
}

void town::SelectSpells() {
	char spellPresent[NUM_SPELLS];
	memset(spellPresent, 0, NUM_SPELLS);

	int numSpellsOfLevel[5];

	for(int j = 0; j < 5; j++) {
		numSpellsOfLevel[j] = 0;
		for(int k = 0; k < 4; k++)
			this->mageGuildSpells[j][k] = -1;
	}

	if( this->factionID == FACTION_NECROMANCER && this->ownerIdx != -1 && !gbHumanPlayer[this->ownerIdx]) {
		int death_spell = Random(0, 100) >= 50 ? SPELL_DEATH_WAVE : SPELL_DEATH_RIPPLE;
		int l = gsSpellInfo[death_spell].level - 1;
		this->mageGuildSpells[l][numSpellsOfLevel[l]++] = death_spell;
	}

	int r = Random(0, 100);
	int dispeller;
	if (r < 25)
		dispeller = SPELL_DISPEL_MAGIC;
	else if (r < 50)
		dispeller = SPELL_MASS_DISPEL;
	else if (r < 75)
		dispeller = SPELL_ANTI_MAGIC;
	else
		dispeller = SPELL_CURE;

	int l = gsSpellInfo[dispeller].level - 1;
	this->mageGuildSpells[l][numSpellsOfLevel[l]++] = dispeller;

	r = Random(0, 100);
	int damage_spell;
	if(r < 20)
		damage_spell = SPELL_MAGIC_ARROW;
	else if (r < 40)
		damage_spell = SPELL_LIGHTNING_BOLT;
	else if (r < 60)
		damage_spell = SPELL_FIREBALL;
	else if (r >= 80)
		damage_spell = SPELL_COLD_RING;
	else
		damage_spell = SPELL_COLD_RAY;

	l = gsSpellInfo[damage_spell].level - 1;
	this->mageGuildSpells[l][numSpellsOfLevel[l]++] = damage_spell;

	for(int i = 0; i < 5; i++) {
		int hasAdventureSpellAtLevel = 0;
		for (int j = 0; j < 4; j++)
		{
			if(this->mageGuildSpells[i][j] == -1) {
				int tries = 0;
				int spell;

				while(true) {
					for(spell = Random(0, NUM_SPELLS-1); gsSpellInfo[spell].level - 1 != i; spell = Random(0, NUM_SPELLS-1))
						;

					int weight = 0;

					if(this->ownerIdx == -1 || gbHumanPlayer[this->ownerIdx])
						weight = 1500;
					else
						weight = gsSpellInfo[spell].appearingChance
						* ((gsSpellInfo[spell].attributes & ATTR_COMMON_SPELL) ? 4 : 1)
						+ 50;

					if (spell == SPELL_DIMENSION_DOOR)
						weight = 1500;

					if(hasAdventureSpellAtLevel != 1 || !(gsSpellInfo[spell].attributes & ATTR_ADVENTURE_SPELL)) {
						if(*(&gsSpellInfo[spell].nonMagicFactionAppearanceChance + this->factionID) >= Random(0, 10)) {
							++tries;
							if(tries <= 500) {
								if(!spellPresent[spell] && Random(1, 1500) <= weight)
									break;
							}
						}
					}
				}
				if (gsSpellInfo[spell].attributes & ATTR_ADVENTURE_SPELL)
					hasAdventureSpellAtLevel = 1;
				this->mageGuildSpells[i][j] = spell;
				spellPresent[spell] = 1;
			}
			else
			{
				spellPresent[this->mageGuildSpells[i][j]] = 1;
			}
		}
	}
}

int townManager::Open(int idx) {
  int res = this->Open_orig(idx);
  ScriptCallback("OnTownOpen", this->castle->name);
  gpSoundManager->SwitchAmbientMusic(townTheme[this->castle->factionID]);
  return res;
}

void town::SetNumSpellsOfLevel(int l, int n) {
	this->numSpellsOfLevel[l] = n;
}

bool town::BuildingBuilt(int building) const {
  if (building < 0 || building >= BUILDING_MAX) {
    return false;
  }

  return (buildingsBuiltFlags & (1 << building));
}

bool town::DwellingBuilt(int index) const
{
  if (index < 0 || index >= NUM_DWELLINGS) {
    return false;
  }

  return BuildingBuilt(index + BUILDING_DWELLING_1);
}

int town::DwellingIndex(int tier) const {
  if (tier < 0 || tier > 5) {
    return -1;
  }

  int dwellingIdx = tier;
  if (tier > 0 && BuildingBuilt(tier + BUILDING_UPGRADE_1 - 1)) {
    dwellingIdx += 5;
  }
  if (tier == 5 && BuildingBuilt(BUILDING_UPGRADE_5B)) {  // Warlock Black Tower
    dwellingIdx = 11;
  }
  return dwellingIdx;
}

void townManager::SetupMage(heroWindow *mageGuildWindow) {
	const int SPELL_SCROLLS = 10;
	const int SPELL_ICONS = 40;
	const int SPELL_SCROLL_LABELS = 70;
	const int BUILDING_ICON = 100;
	const int BOTTOM_BAR = 110;
	tag_message evt;
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	if( this->castle->visitingHeroIdx == -1) {
		GUISetText(mageGuildWindow, BOTTOM_BAR, "The above spells are available here."); 
	}

	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++) {
			int hasLibrary = this->castle->factionID == FACTION_WIZARD && this->castle->BuildingBuilt(BUILDING_SPECIAL);

			if(j < this->castle->numSpellsOfLevel[i]) {
				GUIAddFlag(mageGuildWindow, SPELL_SCROLLS+4*i+j, ICON_GUI_VISIBLE);
				GUISetImgIdx(mageGuildWindow, SPELL_SCROLLS+4*i+j, 0);
				GUISetImgIdx(mageGuildWindow,
							 SPELL_ICONS+4*i+j,
							  gsSpellInfo[this->castle->mageGuildSpells[i][j]].magicBookIconIdx);
				if(smallFont->LineLength(gSpellNames[this->castle->mageGuildSpells[i][j]], 74) == 1 ) {
					int c = GetManaCost(this->castle->mageGuildSpells[i][j]);
					sprintf(gText, "%s\n[%d]", gSpellNames[this->castle->mageGuildSpells[i][j]], c);
				} else {
					int c = GetManaCost(this->castle->mageGuildSpells[i][j]);
					sprintf(gText, "%s  [%d]", gSpellNames[this->castle->mageGuildSpells[i][j]], c);
				}
				GUISetText(mageGuildWindow, SPELL_SCROLL_LABELS+4*i+j, gText);
			} else if(j < gSpellLimits[i] + hasLibrary) {
				GUIAddFlag(mageGuildWindow, SPELL_SCROLLS+4*i+j, ICON_GUI_VISIBLE);
				GUISetImgIdx(mageGuildWindow, SPELL_SCROLLS+4*i+j, 1);
				GUIRemoveFlag(mageGuildWindow, SPELL_ICONS+4*i+j, ICON_GUI_VISIBLE);
				GUIRemoveFlag(mageGuildWindow, SPELL_SCROLL_LABELS+4*i+j, ICON_GUI_VISIBLE);
			} else {
				GUIRemoveFlag(mageGuildWindow, SPELL_SCROLLS+4*i+j, ICON_GUI_VISIBLE);
				GUIRemoveFlag(mageGuildWindow, SPELL_ICONS+4*i+j, ICON_GUI_VISIBLE);
				GUIRemoveFlag(mageGuildWindow, SPELL_SCROLL_LABELS+4*i+j, ICON_GUI_VISIBLE);
			}
		}
	}
	GUISetImgIdx(mageGuildWindow, BUILDING_ICON, this->castle->mageGuildLevel-1);
	sprintf(gText, "magegld%c.icn", cHeroTypeInitial[this->castle->factionID]);
	GUISetIcon(mageGuildWindow, BUILDING_ICON, gText);
}

void townManager::SetupWell(heroWindow *window) {
  SetupWell_orig(window);
  if (!IsWellDisabled()) {
    return;
  }

  for (int tier = 0; tier < 6; ++tier) {
    const int dwellingIdx = castle->DwellingIndex(tier);
    const tag_monsterInfo &mon = gMonsterDatabase[gDwellingType[castle->factionID * NUM_DWELLINGS + dwellingIdx]];

    std::ostringstream desc;
    desc << "Attack: " << int(mon.attack)
      << "\nDefense: " << int(mon.defense)
      << "\nDmg: " << int(mon.min_damage) << '-' << int(mon.max_damage)
      << "\nHP: " << mon.hp
      << "\n\nSpeed:\n" << speedText[mon.speed];

    if (castle->DwellingBuilt(dwellingIdx)) {
      // Original code added +2 for the Well here.
      int growth = mon.growth;
      if (tier == 0 && castle->BuildingBuilt(BUILDING_SPECIAL_GROWTH)) {
        growth += 8;
      }
      desc << "\n\nGrowth\n + " << growth << " / week";
    }

    // Overwrite the text the original code sent for each creature's
    // description field in the Well window.
    GUISetText(window, 25 + tier, desc.str());
  }
}


int townManager::RecruitHero(int id, int x) {
	 /*
	  * The original RecruitHero will give heroes their movement points back.
	  * We want heroes to not regain their movement points if rehired the same turn.
	  *
	  * Thus, we restore the previous value of remainingMobility after the hero is rehired.
	  *
	  * Can lead to weirdness if some situations, like if a hero is defeated and rehired by an opponent
	  * within a single turn.
	  * 
	  */
	 hero* h = &gpGame->heroes[gpCurPlayer->heroesForPurchase[id]];
	 int oldMobility = h->remainingMobility;
	 int toRet = RecruitHero_orig(id, x);
	 h->remainingMobility = oldMobility;
	 return toRet;
}

char *__fastcall GetBuildingName(int faction, int building) {
  if (faction == FACTION_NECROMANCER && building == BUILDING_TAVERN) {
    return xNecromancerShrine;
  } else {
    if (building == BUILDING_SPECIAL_GROWTH) {
      return gWellExtraNames[faction];
    } else if (building == BUILDING_SPECIAL) {
      return gSpecialBuildingNames[faction];
    } else if (building >= BUILDING_DWELLING_1) {
      return gDwellingNames[faction][building - BUILDING_DWELLING_1];
    } else if (IsWellDisabled() && faction == FACTION_NECROMANCER && building == BUILDING_WELL) {
      static std::string poisonedWellName = "Poisoned Well";
      return &poisonedWellName[0];
    } else {
      return gNeutralBuildingNames[building];
    }
  }
}

char * __fastcall GetBuildingInfo(int faction, int building, int withTitle) {
  if (IsWellDisabled() && building == BUILDING_WELL) {
    static std::string buf;
    std::string wellInfo = "The Well provides refreshing drinking water.";
    if (faction == FACTION_NECROMANCER) {
      wellInfo = "The Well has been tainted by the presence of dark magic. Good thing undead don't get thirsty.";
    }

    if (withTitle) {
      buf = "{";
      buf += GetBuildingName(faction, building);
      buf += "}\n\n" + wellInfo;
    } else {
      buf = wellInfo;
    }
    return &buf[0];
  } else {
    return GetBuildingInfo_orig(faction, building, withTitle);
  }
}

int recruitUnit::Open(int x) {
  ScriptCallback("OnUnitRecruit", this->creatureType);
  return this->Open_orig(x);
}
