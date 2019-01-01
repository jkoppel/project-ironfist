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
#include "town/buildings.h"
#include "town/town.h"

#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

unsigned long gTownEligibleBuildMask[MAX_FACTIONS] = {
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

// Leave these undefined initially to make the compiler put them in the
// same data segment. This ensures the old game code will be able to index
// into gDwellingType by referencing gTownObjNames.
char *gTownObjNames[32] = { 0 };
unsigned char gDwellingType[MAX_FACTIONS][NUM_DWELLINGS] = { 0 };

// Declare these in the cpp file to force the use of the helper functions in
// order to get these building names.
extern char *gWellExtraNames[MAX_FACTIONS] = { 0 };
extern char *gSpecialBuildingNames[MAX_FACTIONS] = { 0 };
extern char *xNecromancerShrine;
extern char *gNeutralBuildingNames[];
extern char *gDwellingNames[][NUM_DWELLINGS];
extern char *gBuildingInfoSpecial[MAX_FACTIONS] = { 0 };

extern char *gTownPrefixNames[MAX_FACTIONS] = {
  "twnk", "twnb", "twns", "twnw", "twnz", "twnn",
  "", "", "", "", "", "",
  "twnc"
};

std::vector<std::string> objectNames = {
  "mage",
  "thie",
  "tvrn",
  "dock",
  "well",
  "tent",
  "cstl",
  "stat",
  "ltur",
  "rtur",
  "mark",
  "wel2",
  "moat",
  "spec",
  "boat",
  "capt",
  "ext0",
  "ext1",
  "ext2",
  "dw_0",
  "dw_1",
  "dw_2",
  "dw_3",
  "dw_4",
  "dw_5",
  "up_1",
  "up_2",
  "up_3",
  "up_4",
  "up_5",
  "up5b",
  "ext3"
};

void InitTownObjNames() {
  for (auto i = 0u; i < objectNames.size(); ++i) {
    gTownObjNames[i] = &objectNames[i][0];
  }
}

// Defines the creature types in dwellings 1-6, followed by upgrades 1-5b
// (which are really the tier 2 upgrade through tier 6 second upgrade).
void InitDwellingTypes() {
  for (int i = 0; i < MAX_FACTIONS; ++i) {
    for (int j = 0; j < NUM_DWELLINGS; ++j) {
      gDwellingType[i][j] = CREATURE_INVALID;
    }
  }

  gDwellingType[FACTION_KNIGHT][DWELLING_1] = CREATURE_PEASANT;
  gDwellingType[FACTION_KNIGHT][DWELLING_2] = CREATURE_ARCHER;
  gDwellingType[FACTION_KNIGHT][DWELLING_3] = CREATURE_PIKEMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_4] = CREATURE_SWORDSMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_5] = CREATURE_CAVALRY;
  gDwellingType[FACTION_KNIGHT][DWELLING_6] = CREATURE_PALADIN;
  gDwellingType[FACTION_KNIGHT][DWELLING_2_UPGRADE] = CREATURE_RANGER;
  gDwellingType[FACTION_KNIGHT][DWELLING_3_UPGRADE] = CREATURE_VETERAN_PIKEMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_4_UPGRADE] = CREATURE_MASTER_SWORDSMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_5_UPGRADE] = CREATURE_CHAMPION;
  gDwellingType[FACTION_KNIGHT][DWELLING_6_UPGRADE] = CREATURE_CRUSADER;

  gDwellingType[FACTION_BARBARIAN][DWELLING_1] = CREATURE_GOBLIN;
  gDwellingType[FACTION_BARBARIAN][DWELLING_2] = CREATURE_ORC;
  gDwellingType[FACTION_BARBARIAN][DWELLING_3] = CREATURE_WOLF;
  gDwellingType[FACTION_BARBARIAN][DWELLING_4] = CREATURE_OGRE;
  gDwellingType[FACTION_BARBARIAN][DWELLING_5] = CREATURE_TROLL;
  gDwellingType[FACTION_BARBARIAN][DWELLING_6] = CREATURE_CYCLOPS;
  gDwellingType[FACTION_BARBARIAN][DWELLING_2_UPGRADE] = CREATURE_ORC_CHIEF;
  gDwellingType[FACTION_BARBARIAN][DWELLING_4_UPGRADE] = CREATURE_OGRE_LORD;
  gDwellingType[FACTION_BARBARIAN][DWELLING_5_UPGRADE] = CREATURE_WAR_TROLL;

  gDwellingType[FACTION_SORCERESS][DWELLING_1] = CREATURE_SPRITE;
  gDwellingType[FACTION_SORCERESS][DWELLING_2] = CREATURE_DWARF;
  gDwellingType[FACTION_SORCERESS][DWELLING_3] = CREATURE_ELF;
  gDwellingType[FACTION_SORCERESS][DWELLING_4] = CREATURE_DRUID;
  gDwellingType[FACTION_SORCERESS][DWELLING_5] = CREATURE_UNICORN;
  gDwellingType[FACTION_SORCERESS][DWELLING_6] = CREATURE_PHOENIX;
  gDwellingType[FACTION_SORCERESS][DWELLING_2_UPGRADE] = CREATURE_BATTLE_DWARF;
  gDwellingType[FACTION_SORCERESS][DWELLING_3_UPGRADE] = CREATURE_GRAND_ELF;
  gDwellingType[FACTION_SORCERESS][DWELLING_4_UPGRADE] = CREATURE_GREATER_DRUID;

  gDwellingType[FACTION_WARLOCK][DWELLING_1] = CREATURE_CENTAUR;
  gDwellingType[FACTION_WARLOCK][DWELLING_2] = CREATURE_GARGOYLE;
  gDwellingType[FACTION_WARLOCK][DWELLING_3] = CREATURE_GRIFFIN;
  gDwellingType[FACTION_WARLOCK][DWELLING_4] = CREATURE_MINOTAUR;
  gDwellingType[FACTION_WARLOCK][DWELLING_5] = CREATURE_HYDRA;
  gDwellingType[FACTION_WARLOCK][DWELLING_6] = CREATURE_GREEN_DRAGON;
  gDwellingType[FACTION_WARLOCK][DWELLING_4_UPGRADE] = CREATURE_MINOTAUR_KING;
  gDwellingType[FACTION_WARLOCK][DWELLING_6_UPGRADE] = CREATURE_RED_DRAGON;
  gDwellingType[FACTION_WARLOCK][DWELLING_6_UPGRADE2] = CREATURE_BLACK_DRAGON;

  gDwellingType[FACTION_WIZARD][DWELLING_1] = CREATURE_HALFLING;
  gDwellingType[FACTION_WIZARD][DWELLING_2] = CREATURE_BOAR;
  gDwellingType[FACTION_WIZARD][DWELLING_3] = CREATURE_IRON_GOLEM;
  gDwellingType[FACTION_WIZARD][DWELLING_4] = CREATURE_ROC;
  gDwellingType[FACTION_WIZARD][DWELLING_5] = CREATURE_MAGE;
  gDwellingType[FACTION_WIZARD][DWELLING_6] = CREATURE_GIANT;
  gDwellingType[FACTION_WIZARD][DWELLING_3_UPGRADE] = CREATURE_STEEL_GOLEM;
  gDwellingType[FACTION_WIZARD][DWELLING_5_UPGRADE] = CREATURE_ARCHMAGE;
  gDwellingType[FACTION_WIZARD][DWELLING_6_UPGRADE] = CREATURE_TITAN;

  gDwellingType[FACTION_NECROMANCER][DWELLING_1] = CREATURE_SKELETON;
  gDwellingType[FACTION_NECROMANCER][DWELLING_2] = CREATURE_ZOMBIE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_3] = CREATURE_MUMMY;
  gDwellingType[FACTION_NECROMANCER][DWELLING_4] = CREATURE_VAMPIRE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_5] = CREATURE_LICH;
  gDwellingType[FACTION_NECROMANCER][DWELLING_6] = CREATURE_BONE_DRAGON;
  gDwellingType[FACTION_NECROMANCER][DWELLING_2_UPGRADE] = CREATURE_MUTANT_ZOMBIE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_3_UPGRADE] = CREATURE_ROYAL_MUMMY;
  gDwellingType[FACTION_NECROMANCER][DWELLING_4_UPGRADE] = CREATURE_VAMPIRE_LORD;
  gDwellingType[FACTION_NECROMANCER][DWELLING_5_UPGRADE] = CREATURE_POWER_LICH;

  gDwellingType[FACTION_CYBORG][DWELLING_1] = CREATURE_CYBER_KOBOLD_SPEARMAN;
  gDwellingType[FACTION_CYBORG][DWELLING_2] = CREATURE_CYBER_PLASMA_BERSERKER;
  gDwellingType[FACTION_CYBORG][DWELLING_3] = CREATURE_CYBER_PLASMA_LANCER;
  gDwellingType[FACTION_CYBORG][DWELLING_4] = CREATURE_CYBER_INDIGO_PANTHER;
  gDwellingType[FACTION_CYBORG][DWELLING_5] = CREATURE_CYBER_SHADOW_ASSASSIN;
  gDwellingType[FACTION_CYBORG][DWELLING_6] = CREATURE_CYBER_BEHEMOTH;
  // TODO: do Cyborg creatures have upgrades?
}

void InitBuildingNames() {
  for (int f = 0; f < MAX_FACTIONS; ++f) {
    gWellExtraNames[f] = GetFirstLevelGrowerName(f);
    gSpecialBuildingNames[f] = GetSpecialBuildingName(f);
    gBuildingInfoSpecial[f] = GetSpecialBuildingDesc(f);
  }
}

void game::SetupTowns() {
	InitTownObjNames();
	InitDwellingTypes();
	InitDwellingCosts();
	InitBuildingNames();

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
					castle->numCreaturesInDwelling[i] = gMonsterDatabase[GetDwellingType(castle->factionID, i)].growth;
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
			strncpy(castle->name, twnExtra->name, sizeof(castle->name));

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
						// nonMagicFactionAppearanceChance[6] is either 0 or 10 for every faction.
						// It's 10 for most spells/factions.
						// Holy Word/Shout is 0 for Necromancer, 10 for everyone else.
						// Death Ripple/Wave is 10 for Necromancer, 0 for everyone else.
						// In all other cases, the chance is the same for every faction.
						// To support any number of new factions, we can just use the Knight's
						// spell appearance chances for everyone except Necromancer.
						int factionAppearanceChance = gsSpellInfo[spell].nonMagicFactionAppearanceChance;
						if (factionID == FACTION_NECROMANCER) {
							if (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT) {
								factionAppearanceChance = 0;
							} else if (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE) {
								factionAppearanceChance = 10;
							}
						}
						if(factionAppearanceChance >= Random(0, 10)) {
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
  ScriptCallback("OnTownOpen", deepbind<town*>(this->castle));
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

  return (buildingsBuiltFlags & (1 << building)) != 0;
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
					sprintf_s(gText, gTextSize, "%s\n[%d]", gSpellNames[this->castle->mageGuildSpells[i][j]], c);
				} else {
					int c = GetManaCost(this->castle->mageGuildSpells[i][j]);
					sprintf_s(gText, gTextSize, "%s  [%d]", gSpellNames[this->castle->mageGuildSpells[i][j]], c);
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
	sprintf_s(gText, gTextSize, "magegld%c.icn", cHeroTypeInitial[this->castle->factionID]);
	GUISetIcon(mageGuildWindow, BUILDING_ICON, gText);
}

void townManager::SetupWell(heroWindow *window) {
  SetupWell_orig(window);
  if (!IsWellDisabled()) {
    return;
  }

  for (int tier = 0; tier < 6; ++tier) {
    const int dwellingIdx = castle->DwellingIndex(tier);
    const tag_monsterInfo &mon = gMonsterDatabase[GetDwellingType(castle->factionID, dwellingIdx)];

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
      return GetFirstLevelGrowerName(faction);
    } else if (building == BUILDING_SPECIAL) {
      return GetSpecialBuildingName(faction);
    } else if (building >= BUILDING_DWELLING_1) {
      return GetDwellingName(faction, building - BUILDING_DWELLING_1);
    } else if (IsWellDisabled() && faction == FACTION_NECROMANCER && building == BUILDING_WELL) {
      static std::string poisonedWellName = "Poisoned Well";
      return &poisonedWellName[0];
    } else {
      return gNeutralBuildingNames[building];
    }
  }
}

char * __fastcall GetBuildingInfo(int faction, int building, int withTitle) {
  std::string desc;
  const std::string buildingName = GetBuildingName(faction, building);

  if (IsWellDisabled() && building == BUILDING_WELL) {
    desc = "The Well provides refreshing drinking water.";
    if (faction == FACTION_NECROMANCER) {
      desc = "The Well has been tainted by the presence of dark magic. Good thing undead don't get thirsty.";
    }
  } else if (building == BUILDING_SPECIAL_GROWTH) {
    const int tier1 = GetDwellingType(faction, DWELLING_1);
    desc = "The ";
    desc += buildingName;
    desc += " increases production of ";
    desc += GetCreaturePluralName(tier1);
    desc += " by 8 per week.";
  } else if (building >= BUILDING_DWELLING_1) {
    const int creatureId = GetDwellingType(faction, building - BUILDING_DWELLING_1);
    desc = "The ";
    desc += buildingName;
    desc += " produces ";
    desc += GetCreaturePluralName(creatureId);
    desc += '.';
  } else {
    return GetBuildingInfo_orig(faction, building, withTitle);
  }

  static std::string buf;
  if (withTitle) {
    buf = "{";
    buf += buildingName;
    buf += "}\n\n" + desc;
  } else {
    buf = desc;
  }
  return &buf[0];
}

int GetDwellingType(int faction, int dwellingIndex) {
  if (faction < 0 || faction >= MAX_FACTIONS ||
      dwellingIndex < 0 || dwellingIndex >= NUM_DWELLINGS) {
    return CREATURE_INVALID;
  }

  return gDwellingType[faction][dwellingIndex];
}

char * GetDwellingName(int faction, int dwellingIndex) {
  if (faction >= FACTION_KNIGHT && faction <= FACTION_NECROMANCER) {
    return gDwellingNames[faction][dwellingIndex];
  }

  return GetIronfistDwellingName(faction, dwellingIndex);
}

int recruitUnit::Open(int x) {
  ScriptCallback("OnUnitRecruit", this->creatureType);
  return this->Open_orig(x);
}
