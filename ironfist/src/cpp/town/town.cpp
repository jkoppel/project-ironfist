#include "base.h"
#include "msg.h"

#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/gui.h"
#include "resource/resources.h"
#include "scripting/hook.h"
#include "spell/spells.h"
#include "town/town.h"

int BuildingBuilt(town* twn, int building) {
	return (twn->buildingsBuiltFlags & (1 << building)) ? 1 : 0;
}

void game::SetupTowns() {

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
				if((1 << i) & castle->buildingsBuiltFlags) {
					if(i == BUILDING_UPGRADE_5B)
						castle->buildingsBuiltFlags &= ~((1 << BUILDING_DWELLING_6) | (BUILDING_UPGRADE_5B));
					else
						castle->buildingsBuiltFlags &= ~(1 << (i - (BUILDING_UPGRADE_1 - BUILDING_DWELLING_2)));
				}
			}

			for(int i = 0; i <= NUM_DWELLINGS; i++) {
				if((1 << (i+BUILDING_DWELLING_1) & castle->buildingsBuiltFlags))
					castle->numCreaturesInDwelling[i] = gMonsterDatabase[gDwellingType[castle->factionID][i]].growth;
			}

			if(castle->buildingsBuiltFlags & (1 << BUILDING_MAGE_GUILD)) {
				for(int i = 0; i < castle->mageGuildLevel; i++ ) {
					castle->numSpellsOfLevel[i] = gSpellLimits[i];
					if(castle->factionID == FACTION_WIZARD && (castle->buildingsBuiltFlags & (1 << BUILDING_SPECIAL)))
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
	ScriptSignal(SCRIPT_EVT_TOWN_LOADED, this->castle->name);
	return res;
}

void town::SetNumSpellsOfLevel(int l, int n) {
	this->numSpellsOfLevel[l] = n;
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
			int hasLibrary = this->castle->factionID == FACTION_WIZARD && BuildingBuilt(this->castle, BUILDING_SPECIAL);

			if(j < this->castle->numSpellsOfLevel[i]) {
				GUIAddFlag(mageGuildWindow, SPELL_SCROLLS+4*i+j, ICON_GUI_VISIBLE);
				GUISetImgIdx(mageGuildWindow, SPELL_SCROLLS+4*i+j, 0);
				GUISetImgIdx(mageGuildWindow,
							 SPELL_ICONS+4*i+j,
							  gsSpellInfo[this->castle->mageGuildSpells[i][j]].spriteIdx);
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
  if(faction == FACTION_NECROMANCER && building == BUILDING_TAVERN) {
    return xNecromancerShrine;
  } else {
    if(building == BUILDING_SPECIAL_GROWTH) {
      return gWellExtraNames[faction];
    } else if(building == BUILDING_SPECIAL) {
      return gSpecialBuildingNames[faction];
    } else if(building >= BUILDING_DWELLING_1) {
      return gDwellingNames[faction][building-BUILDING_DWELLING_1];
    } else {
      return gNeutralBuildingNames[building];
    }
  }
}

int recruitUnit::Open(int x) {
  char ctype[4];
  itoa(creatureType, ctype, 10);
  ScriptSignal(SCRIPT_EVT_RECRUIT, ctype);
  return Open_orig(x);
}
