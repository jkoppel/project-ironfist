#include "base.h"
#include "gui/msg.h"

#include "adventure/adv.h"
#include "adventure/map.h"
#include "adventure/terrain.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "gui/gui.h"
#include "gui/recruit_unit.h"
#include "resource/resourceManager.h"
#include "resource/resources.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "town/buildings.h"
#include "town/town.h"
#include "town/town_globals.h"

#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

extern char *xNecromancerShrine;
extern char *gNeutralBuildingNames[];
extern char *gDwellingNames[][NUM_DWELLINGS];

// numAnimationFrames + rectangle data for hovering over buildings in town screen
SBuildingInfo sBuildingsInfo[MAX_FACTIONS][BUILDING_MAX] = {
{
    { '\0', 397, 46, 84, 138 },
    { '\x05', 0, 130, 53, 63 },
    { '\x05', 345, 114, 83, 62 },
    { '\x05', 531, 214, 113, 42 },
    { '\0', 188, 214, 39, 42 },
    { '\0', 69, 108, 67, 55 },
    { '\x05', 0, 49, 286, 116 },
    { '\0', 478, 193, 46, 63 },
    { '\x05', 7, 33, 0, 0 },
    { '\x05', 134, 37, 0, 0 },
    { '\0', 219, 138, 120, 30 },
    { '\0', 286, 102, 88, 22 },
    { '\0', 0, 146, 311, 30 },
    { '\0', 0, 78, 251, 22 },
    { '\t', 531, 211, 113, 45 },
    { '\0', 293, 107, 59, 35 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\x05', 192, 163, 69, 52 },
    { '\0', 135, 149, 73, 32 },
    { '\x05', 240, 166, 91, 66 },
    { '\0', 323, 174, 102, 69 },
    { '\a', 48, 176, 104, 80 },
    { '\0', 445, 50, 195, 157 },
    { '\0', 135, 149, 73, 32 },
    { '\x05', 240, 166, 91, 66 },
    { '\0', 323, 174, 102, 69 },
    { '\a', 48, 176, 104, 80 },
    { '\0', 445, 50, 195, 157 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  },
  {
    { '\b', 346, 22, 54, 120 },
    { '\0', 466, 94, 87, 47 },
    { '\0', 0, 161, 136, 85 },
    { '\x05', 505, 199, 138, 56 },
    { '\0', 268, 189, 50, 66 },
    { '\0', 44, 109, 87, 52 },
    { '\x06', 0, 0, 214, 175 },
    { '\0', 463, 154, 38, 81 },
    { '\0', 10, 58, 0, 0 },
    { '\0', 118, 45, 0, 0 },
    { '\0', 217, 166, 67, 43 },
    { '\0', 240, 106, 73, 34 },
    { '\x05', 115, 138, 182, 42 },
    { '\0', 210, 80, 197, 61 },
    { '\t', 505, 199, 138, 56 },
    { '\x05', 206, 99, 46, 42 },
    { '\x05', 0, 0, 0, 0 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 290, 138, 58, 45 },
    { '\0', 145, 195, 76, 52 },
    { '\0', 557, 48, 83, 83 },
    { '\x05', 496, 136, 138, 64 },
    { '\x05', 318, 174, 131, 54 },
    { '\x05', 407, 0, 113, 106 },
    { '\0', 145, 195, 76, 52 },
    { '\0', 0, 0, 0, 0 },
    { '\x05', 496, 136, 138, 64 },
    { '\x05', 318, 174, 131, 54 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  },
  {
    { '\0', 279, 0, 63, 168 },
    { '\x05', 423, 167, 87, 50 },
    { '\x05', 490, 141, 148, 91 },
    { '\x05', 0, 208, 178, 48 },
    { '\0', 335, 205, 45, 29 },
    { '\0', 104, 130, 59, 42 },
    { '\x05', 0, 0, 201, 179 },
    { '\0', 152, 163, 28, 65 },
    { '\0', 98, 99, 0, 0 },
    { '\0', 151, 98, 0, 0 },
    { '\0', 404, 122, 69, 45 },
    { '\x05', 131, 185, 71, 53 },
    { '\0', 0, 171, 272, 23 },
    { '\0', 152, 0, 236, 84 },
    { '\t', 0, 208, 178, 48 },
    { '\x05', 223, 122, 37, 52 },
    { '\x05', 0, 0, 0, 0 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\x05', 472, 59, 111, 92 },
    { '\x05', 338, 146, 93, 61 },
    { '\0', 51, 164, 106, 40 },
    { '\0', 198, 178, 143, 71 },
    { '\0', 263, 226, 296, 30 },
    { '\0', 179, 0, 84, 119 },
    { '\x05', 338, 146, 93, 61 },
    { '\0', 51, 164, 106, 40 },
    { '\0', 198, 178, 143, 71 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  },
  {
    { '\0', 586, 18, 54, 150 },
    { '\0', 520, 103, 64, 54 },
    { '\0', 476, 96, 82, 55 },
    { '\x05', 517, 200, 123, 56 },
    { '\0', 342, 205, 67, 51 },
    { '\0', 298, 135, 72, 31 },
    { '\x05', 241, 18, 181, 150 },
    { '\0', 478, 161, 37, 63 },
    { '\0', 311, 84, 0, 0 },
    { '\0', 359, 83, 0, 0 },
    { '\0', 386, 171, 71, 40 },
    { '\x06', 60, 32, 63, 186 },
    { '\x05', 211, 166, 301, 21 },
    { '\0', 0, 160, 59, 96 },
    { '\t', 517, 200, 123, 56 },
    { '\x05', 418, 83, 53, 84 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\x06', 0, 64, 48, 50 },
    { '\0', 237, 168, 78, 87 },
    { '\0', 492, 50, 53, 39 },
    { '\0', 139, 163, 190, 83 },
    { '\0', 82, 92, 178, 68 },
    { '\0', 92, 0, 64, 257 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 139, 163, 190, 83 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 92, 0, 64, 257 },
    { '\0', 92, 0, 64, 257 },
    { '\0', 0, 0, 0, 0 }
  },
  {
    { '\0', 570, 0, 70, 126 },
    { '\x05', 505, 50, 51, 49 },
    { '\x06', 0, 149, 118, 76 },
    { '\x05', 0, 206, 206, 50 },
    { '\0', 249, 139, 28, 33 },
    { '\0', 58, 60, 49, 42 },
    { '\x05', 0, 0, 200, 99 },
    { '\0', 464, 45, 24, 72 },
    { '\0', 30, 17, 0, 0 },
    { '\0', 128, 17, 0, 0 },
    { '\0', 255, 163, 108, 53 },
    { '\0', 237, 208, 137, 49 },
    { '\0', 0, 90, 223, 14 },
    { '\0', 297, 95, 109, 78 },
    { '\t', 0, 206, 206, 50 },
    { '\0', 210, 52, 28, 35 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\x05', 467, 181, 38, 30 },
    { '\0', 231, 68, 192, 36 },
    { '\x05', 152, 130, 96, 60 },
    { '\0', 593, 184, 51, 31 },
    { '\0', 411, 0, 49, 167 },
    { '\0', 160, 0, 178, 67 },
    { '\0', 0, 0, 0, 0 },
    { '\x05', 152, 130, 96, 60 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 411, 0, 49, 167 },
    { '\0', 160, 0, 178, 67 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  },
  {
    { '\x05', 557, 17, 85, 191 },
    { '\0', 275, 124, 62, 77 },
    { '\0', 455, 39, 51, 103 },
    { '\x05', 500, 220, 141, 36 },
    { '\0', 215, 213, 29, 41 },
    { '\0', 333, 115, 47, 70 },
    { '\x05', 289, 10, 134, 164 },
    { '\0', 365, 154, 41, 93 },
    { '\0', 330, 47, 0, 0 },
    { '\0', 360, 46, 0, 0 },
    { '\0', 412, 193, 98, 61 },
    { '\x06', 263, 181, 90, 65 },
    { '\0', 258, 171, 193, 19 },
    { '\0', 0, 0, 640, 63 },
    { '\t', 500, 220, 141, 36 },
    { '\0', 441, 77, 22, 99 },
    { '\x05', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 396, 177, 71, 35 },
    { '\0', 110, 174, 141, 45 },
    { '\x05', 0, 28, 241, 142 },
    { '\0', 20, 107, 124, 129 },
    { '\0', 221, 127, 66, 84 },
    { '\x06', 464, 72, 105, 124 },
    { '\0', 110, 174, 141, 45 },
    { '\x05', 0, 28, 241, 142 },
    { '\0', 0, 107, 144, 129 },
    { '\0', 223, 45, 65, 166 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  },
  { {0} },
  { {0} },
  { {0} },
  { {0} },
  { {0} },
  { {0} },
  {
    { 0, 175, 20, 30, 105 },
    { 0, 5, 65, 85, 65 },
    { 0, 560, 130, 83, 52 },
    { 5, 60, 190, 106, 60 },
    { 0, 316, 145, 32, 42 },
    { 0, 304, 106, 51, 40 },
    { 6, 216, 3, 236, 130 },
    { 0, 380, 172, 40, 80 },
    { 0, 7, 33, 0, 0 }, // ltur
    { 0, 134, 37, 0, 0 }, // rtur
    { 0, 517, 102, 80, 50 },
    { 0, 147, 120, 63, 40 },
    { 8, 207, 107, 254, 30 },
    { 7, 200, 7, 105, 58 },
    { 5, 0, 191, 120, 65 },
    { 0, 220, 110, 59, 45 },
    { 4, 0, 0, 0, 0 },
    { 4, 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 },
    { 5, 230, 165, 90, 60 },
    { 0, 427, 90, 90, 60 },
    { 0, 365, 126, 90, 72 },
    { 5, 495, 184, 147, 75 },
    { 5, 75, 45, 100, 50 },
    { 4, 547, 10, 48, 84 },
    { '\0', 135, 149, 73, 32 },
    { '\x05', 240, 166, 91, 66 },
    { '\0', 323, 174, 102, 69 },
    { '\a', 48, 176, 104, 80 },
    { '\0', 445, 50, 195, 157 },
    { '\0', 0, 0, 0, 0 },
    { '\0', 0, 0, 0, 0 }
  }
};

float marketEfficiency[11] = {
  0,
  0.1,
  0.15,
  0.2,
  0.25,
  0.3,
  0.35,
  0.4,
  0.45,
  0.5,
  0.5
};

unsigned long gHierarchyMask[MAX_FACTIONS][NUM_DWELLINGS] = {
  {0x00000000, 0x00080000, 0x00080010, 0x00080004, 0x00700000, 0x00700000, 0x00700000, 0x00700000, 0x00700000, 0x00800000, 0x01000000, 0x0FFFFFFFF },
  {0x00000000, 0x00080000, 0x00080000, 0x00080000, 0x00700000, 0x00800000, 0x00700000, 0x0FFFFFFFF, 0x00700000, 0x00800000, 0x0FFFFFFFF, 0x0FFFFFFFF},
  {0x00000000, 0x00080004, 0x00080000, 0x00200001, 0x00400000, 0x00800000, 0x00100010, 0x00400000, 0x00400000, 0x0FFFFFFFF, 0x0FFFFFFFF, 0x0FFFFFFFF},
  {0x00000000, 0x00080000, 0x00080000, 0x00100000, 0x00200000, 0x00C00000, 0x0FFFFFFFF, 0x0FFFFFFFF, 0x00400000, 0x0FFFFFFFF, 0x01000000, 0x20000000},
  {0x00000000, 0x00080000, 0x00080000, 0x00100000, 0x00200001, 0x00C00000, 0x0FFFFFFFF, 0x00200010, 0x0FFFFFFFF, 0x00802000, 0x01000000, 0x0FFFFFFFF},
  {0x00000000, 0x00080000, 0x00080000, 0x00200002, 0x00100001, 0x00800000, 0x00100000, 0x00200000, 0x00400000, 0x00800000, 0x0FFFFFFFF, 0x0FFFFFFFF},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0x00000000, 0x00080000, 0x00080010, 0x00080004, 0x00700000, 0x00700000, 0x00700000, 0x00700000, 0x00700000, 0x00800000, 0x01000000, 0x0FFFFFFFF}
};

void InitializeTownConstants() {
  InitTownObjNames();
  InitDwellingTypes();
  InitDwellingCosts();
  InitBuildingNames();
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

bool town::IsDisallowed(int building) const {
  if (building < 0 || building >= BUILDING_MAX) {
    return false;
  }

  return gpGame->disallowedBuildings[this->idx][building];
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
  } else if(faction == FACTION_CYBORG && building == BUILDING_WELL) {
    return "Energy Pump";
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

townObject::townObject(int faction, int buildingCode, char *filename) {
  this->animationIdx = 0;
  this->guiElement = nullptr;
  this->built = 1;
  SBuildingInfo *bInfo = &sBuildingsInfo[faction][buildingCode];
  this->animationLength = bInfo->animationLength;
  int x = bInfo->x;
  int y = bInfo->y;
  int width = bInfo->width;
  int height = bInfo->height;
  this->buildingCode = buildingCode;
  
  std::string fullFilename;
  fullFilename += filename;
  fullFilename += ".icn";
  this->icon = gpResourceManager->GetIcon(&fullFilename[0u]);
  if(buildingCode != -1) {
    this->guiElement = new border(x, y, width, height, buildingCode, 1, 0, 0);
    if(!this->guiElement)
      MemError();
  }
}

int townManager::Main(tag_message &evt) {
  bool rightClick;
  if((*((unsigned char*)&(evt.inputTypeBitmask) + 1)) & 2)
    rightClick = 1;
  else
    rightClick = 0;

  if(giDebugBuildingToBuild != -1) {
    int buildingToBuild = giDebugBuildingToBuild;
    giDebugBuildingToBuild = -1;
    unsigned long eligibleBuildMask = gTownEligibleBuildMask[this->castle->factionID];
    if(buildingToBuild == 100) {
      for(int buildingCode = 0; buildingCode < BUILDING_MAX; ++buildingCode) {
        if((1 << buildingCode) & eligibleBuildMask || buildingCode == BUILDING_CASTLE)
          this->BuildObj(buildingCode);
      }
    } else {
      if((1 << buildingToBuild) & eligibleBuildMask || buildingToBuild == BUILDING_CASTLE)
        this->BuildObj(buildingToBuild);
    }
  }

  if(KBTickCount() > glTimers) {
    const int TOWN_DRAW_DURATION = 150;
    this->DrawTown(1, 1);
    glTimers = KBTickCount() + TOWN_DRAW_DURATION;
  }

  bool exitFlag = false;
  switch(evt.eventCode) {
    case INPUT_GUI_MESSAGE_CODE: {
      int keycode = evt.xCoordOrKeycode;
      int guiItemIdx = evt.yCoordOrFieldID;
      if(keycode == 13) {        
        if(guiItemIdx >= 903) {
          if(guiItemIdx <= 904) {
            int numCastles = gpCurPlayer->numCastles;
            if(this->castle->ownerIdx == giCurPlayer && numCastles > 1) {
              this->castle = &gpGame->castles[gpCurPlayer->castlesOwned[(getCastleOwnedIdx(gpCurPlayer, this->castle->idx)
                + numCastles + ((unsigned int)(guiItemIdx - 903) < 1 ? -1 : 1)) % numCastles]];
              this->ChangeTown();
            }
          } else {
            if(guiItemIdx == BUTTON_EXIT && !rightClick)
              exitFlag = true;
          }
        }
        break;
      }
      if(keycode == 12 || keycode == 14) {
        if(guiItemIdx == BUTTON_EXIT) {
          if(!rightClick)
            this->SetCommandAndText(evt);
          break;
        }

        if(guiItemIdx >= BUILDING_DWELLING_1 && guiItemIdx <= BUILDING_UPGRADE_5B) {
          if(rightClick) {
            QuickViewRecruit(this->castle, guiItemIdx - 19);
          } else {
            this->DrawTown(1, 1);
            recruitUnit *unit = new recruitUnit(this->castle, guiItemIdx - 19, 1);
            if(!unit)
              MemError();
            gpExec->DoDialog((baseManager *)unit);
            delete unit;
          }
          break;
        }

        if(guiItemIdx >= BUILDING_MAGE_GUILD && guiItemIdx <= BUILDING_EXT_3) {
          if(rightClick) {
            char *buildInfo = GetBuildingInfo(this->castle->factionID, evt.yCoordOrFieldID, 1);
            NormalDialog(buildInfo, 4, -1, -1, -1, evt.yCoordOrFieldID, -1, 0, -1, 0);
          } else {
            switch(guiItemIdx) {
              case BUILDING_CASTLE: {                
                this->curScreen = new heroWindow(0, 0, "caslwind.bin");
                if(!this->curScreen)
                  MemError();
                this->SetupCastle(this->curScreen, 0);
                this->field_15A = 1;
                this->isRecruitingHero = 0;
                gpWindowManager->DoDialog(this->curScreen, CastleHandler, 0);
                this->field_15A = 0;
                delete this->curScreen;
                if(this->isRecruitingHero) {
                  this->RedrawTownScreen();
                  gpWindowManager->SaveFizzleSource(0, 256, 552, 204);
                  if(this->visitingArmyDisplay)
                    delete this->visitingArmyDisplay;
                  sprintf(gText, "port%04d.icn", this->heroBeingRecruited->heroID);
                  this->visitingArmyDisplay = new strip(0, 355, 3, gpResourceManager->MakeId(gText, 1), 0, &this->heroBeingRecruited->army, 122, 0, -1);
                  if(!this->visitingArmyDisplay)
                    MemError();
                  SAMPLE2 res = LoadPlaySample("buildtwn.82M");
                  this->townScreen->DrawWindow(0);
                  this->garrisonDisplay->DrawIcons(0);
                  this->visitingArmyDisplay->DrawIcons(0);
                  gpWindowManager->FizzleForward(0, 256, 552, 204, -1, 0, 0);
                  WaitEndSample(res, -1);
                  this->isRecruitingHero = 0;
                  gpWindowManager->ReleaseFizzleSource();
                } else {
                  if(this->buildingToBuild == BUILDING_CAPTAIN && this->castle->visitingHeroIdx == -1) {
                    if(this->visitingArmyDisplay)
                      delete this->visitingArmyDisplay;
                    this->visitingArmyDisplay = 0;
                    sprintf(gText, "port%04d.icn", this->castle->factionID + 90);
                    this->visitingArmyDisplay = new strip(0, 355, 3, gpResourceManager->MakeId(gText, 1), 0, 0, -1, 0, gpCurPlayer->color);
                    if(!this->visitingArmyDisplay)
                      MemError();
                  }
                  this->RedrawTownScreen();
                  if(this->buildingToBuild != -1)
                    this->BuildObj(this->buildingToBuild);
                }
                break;
              }
              case BUILDING_MAGE_GUILD: {
                int visitingHeroIdx = this->castle->visitingHeroIdx;
                if(visitingHeroIdx == -1 || gpGame->heroes[visitingHeroIdx].HasArtifact(ARTIFACT_MAGIC_BOOK)) {
                  this->curScreen = new heroWindow(0, 0, "magewind.bin");
                  if(!this->curScreen)
                    MemError();
                  SetWinText(this->curScreen, 17);
                  this->SetupMage(this->curScreen);
                  gpWindowManager->DoDialog(this->curScreen, MageGuildHandler, 0);
                  delete this->curScreen;
                } else {
                  if(gpGame->heroes[visitingHeroIdx].NumArtifacts() == 14) {
                    NormalDialog("You must purchase a spell book to use the mage guild, but you currently have no room for a spell book.  Try giving one of your artifacts to another hero.",
                      1, -1, -1, -1, 0, -1, 0, -1, 0);
                  } else {
                    if(gpCurPlayer->resources[RESOURCE_GOLD] >= 500) {
                      NormalDialog("To cast spells, you must first buy a spell book for 500 gold.  Do you wish to buy one?",
                        2, -1, -1, 7, 81, -1, 0, -1, 0);
                      if(gpWindowManager->buttonPressedCode == BUTTON_YES) {
                        GiveArtifact(&gpGame->heroes[visitingHeroIdx], ARTIFACT_MAGIC_BOOK, 1, -1);
                        gpCurPlayer->resources[RESOURCE_GOLD] -= 500;
                        this->bankbox->Update(1);
                        this->townScreen->DrawWindow();
                        this->castle->GiveSpells(0);
                      }
                    } else {
                      NormalDialog("To cast spells, you must first buy a spell book for 500 gold.  Unfortunately, you seem to be a little short of cash at the moment.",
                        1, -1, -1, 7, 81, -1, 0, -1, 0);
                    }
                  }
                }
                this->castle->GiveSpells(0);
                this->RedrawTownScreen();
                break;
              }
              case BUILDING_WELL: {
                this->curScreen = new heroWindow(0, 0, "wellwind.bin");
                if(!this->curScreen)
                  MemError();
                this->SetupWell(this->curScreen);
                gpWindowManager->DoDialog(this->curScreen, TrueFalseDialogHandler, 0);
                delete this->curScreen;
                this->RedrawTownScreen();
                break;
              }
              case BUILDING_THIEVES_GUILD: {
                this->curScreen = new heroWindow(0, 0, "thiefwin.bin");
                if(!this->curScreen)
                  MemError();
                SetWinText(this->curScreen, 14);
                this->SetupThievesGuild(this->curScreen, -1);
                gpWindowManager->DoDialog(this->curScreen, TrueFalseDialogHandler, 0);
                delete this->curScreen;
                this->RedrawTownScreen();
                break;
              }
              case BUILDING_TAVERN: {
                if(this->castle->factionID == FACTION_NECROMANCER) {
                  char *buildInfo = GetBuildingInfo(this->castle->factionID, evt.yCoordOrFieldID, 1);
                  NormalDialog(buildInfo, 1, -1, -1, this->castle->factionID + 19, evt.yCoordOrFieldID, -1, 0, -1, 0);
                } else {
                  this->DoTavern();
                }
                break;
              }
              case BUILDING_TENT:
                if(this->castle->mayNotBeUpgradedToCastle) {
                  NormalDialog("This town may not be upgraded to a castle.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
                } else {
                  if(this->BuyBuild(BUILDING_CASTLE, CanBuy(this->castle, BUILDING_CASTLE) < 1, rightClick))
                    this->BuildObj(BUILDING_CASTLE);
                }
                break;
              case BUILDING_DOCK: {
                gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_ADD_FLAGS, BUTTON_EXIT, 16392);
                if(gpGame->GetBoatsBuilt() >= MAX_BOATS
                  || gpAdvManager->GetCell(this->castle->buildDockRelated, this->castle->boatCell)->objType) {
                  NormalDialog("Cannot build another boat.", 1, 208, 40, -1, 0, -1, 0, -1, 0);
                } else {
                  this->curScreen = new heroWindow(177, 20, "shipwind.bin");
                  if(!this->curScreen)
                    MemError();
                  SetWinText(this->curScreen, 12);
                  if(gpGame->players[giCurPlayer].resources[RESOURCE_GOLD] < 1000 || gpGame->players[giCurPlayer].resources[RESOURCE_WOOD] < 10) {
                    GUIAddFlag(this->curScreen, BUTTON_OK, 4096);
                    GUIRemoveFlag(this->curScreen, BUTTON_OK, 2);
                  }
                  gpWindowManager->DoDialog(this->curScreen, TrueFalseDialogHandler, 0);
                  delete this->curScreen;
                  if(gpWindowManager->buttonPressedCode == BUTTON_OK) {
                    if(gpGame->CreateBoat(this->castle->buildDockRelated, this->castle->boatCell, 0) == -1) {
                      LogStr("Can't create boat!");
                    } else {
                      this->BuildObj(BUILDING_BOAT);
                      gpGame->players[giCurPlayer].resources[RESOURCE_GOLD] -= 1000;
                      gpGame->players[giCurPlayer].resources[RESOURCE_WOOD] -= 10;
                      this->bankbox->Update(1);
                    }
                  }
                }
                gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_REMOVE_FLAGS, BUTTON_EXIT, 16392);
                break;
                }
              case BUILDING_MARKET: {
                int numMarkets = 0;
                for(int buildingCode = 0; gpCurPlayer->numCastles > buildingCode; ++buildingCode) {
                  unsigned int builtFlags = gpGame->castles[gpCurPlayer->castlesOwned[buildingCode]].buildingsBuiltFlags;
                  if(builtFlags & (1 << BUILDING_MARKET))
                    ++numMarkets;
                }
                if(numMarkets > 10)
                  numMarkets = 10;
                DoTradingPost(1, marketEfficiency[numMarkets]);
                this->RedrawTownScreen();
                break;
              }
              case BUILDING_CAPTAIN:
              case BUILDING_STATUE:
              case BUILDING_LEFT_TURRET:
              case BUILDING_RIGHT_TURRET:
              case BUILDING_SPECIAL_GROWTH:
              case BUILDING_MOAT:
              case BUILDING_SPECIAL: {
                char *buildInfo = GetBuildingInfo(this->castle->factionID, evt.yCoordOrFieldID, 1);
                    NormalDialog(buildInfo, 1, -1, -1, -1, evt.yCoordOrFieldID, -1, 0, -1, 0);
                break;
              }
              default:
                break;
            }
          }
        }
        
        if(rightClick) {
          bool showInfo = false;
          // Right clicking on garrison creatures
          if(evt.yCoordOrFieldID >= 117 && evt.yCoordOrFieldID <= 121) {
            this->currentDisplay = this->garrisonDisplay;
            this->currentCreature = evt.yCoordOrFieldID - 117;
            showInfo = true;
          }
          // Right clicking on visiting hero creatures
          if(evt.yCoordOrFieldID >= 123 && evt.yCoordOrFieldID <= 127) {
            this->currentDisplay = this->visitingArmyDisplay;
            this->currentCreature = evt.yCoordOrFieldID - 123;
            showInfo = true;
          }
          
          if(showInfo) {
            int creature = this->currentCreature;
            armyGroup* currentArmy = this->currentDisplay->army;
            int type = currentArmy->creatureTypes[creature];
            if(type == -1)
              break;
            hero* hro = nullptr;
            if(this->currentDisplay == this->visitingArmyDisplay)
              hro = &gpGame->heroes[this->castle->visitingHeroIdx];
            int quantity = currentArmy->quantities[creature];
            gpGame->ViewArmy(119, 20, type, quantity, this->castle, 1, 1u, 1, hro, 0, currentArmy, creature);
            this->bankbox->Update(1);
          }
        } else {
          this->DoCommand(this->field_14A);
          this->SetCommandAndText(evt);
        }
      }
      break;
    }      
    case INPUT_KEYDOWN_EVENT_CODE: {
      int keyCode = evt.xCoordOrKeycode;
      if(keyCode == 1) {
        exitFlag = true;
      } else {
        // left shift / right shift
        if(keyCode == 42 || keyCode == 54)
          this->ShiftQualChange();
      }
      break;
    }
    case INPUT_KEYUP_EVENT_CODE: {
      int keycode = evt.xCoordOrKeycode;
      // left shift / right shift
      if(keycode == 42 || keycode == 54)
        this->ShiftQualChange();
      break;
    }
    case INPUT_MOUSEMOVE_EVENT_CODE: {
      // Show message on hover
      gpWindowManager->ConvertToHover(evt);
      if(evt.yCoordOrFieldID != this->field_142 || evt.inputTypeBitmask != this->field_146) {
        this->field_142 = evt.yCoordOrFieldID;
        this->field_146 = evt.inputTypeBitmask;
        if(this->factionID == FACTION_CYBORG && evt.yCoordOrFieldID == BUILDING_WELL) {
          this->field_14A = -1;
          strcpy(this->infoMessage, "Energy Pump");
          this->ShowText(this->infoMessage);
        } else {
          this->SetCommandAndText(evt);
        }
      }
      return 1;
    }
  }
  
  if(exitFlag == 1) {
    evt.eventCode = (INPUT_EVENT_CODE)16384;
    evt.xCoordOrKeycode = 1;
    return 2;
  }
  else
    return 1;  
}

// Set built flags for extra buildings and boat depending on faction and dock creation possibility
void townManager::SetupExtraStuff() {
  // remove ext0,ext1,ext2,ext3 and boat building flags
  this->castle->buildingsBuiltFlags &= 0x7FF8BFFFu;

  if(this->castle->factionID == FACTION_WIZARD)
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_0);
  if(this->castle->factionID == FACTION_SORCERESS) {
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_0);
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_1);
  }
  if(this->castle->factionID == FACTION_KNIGHT) {
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_1);
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_2);
  }
  if(this->castle->factionID == FACTION_BARBARIAN) {
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_1);
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_2);
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_3);
  }
  if(this->castle->factionID == FACTION_WARLOCK
    || this->castle->factionID == FACTION_KNIGHT
    || this->castle->factionID == FACTION_BARBARIAN
    || this->castle->factionID == FACTION_NECROMANCER
    || this->castle->factionID == FACTION_CYBORG) {
    if(this->castle->CanBuildDock())
      this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_0);
  }
  if(this->castle->factionID == FACTION_CYBORG) {
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_EXT_1);
  }
  if(this->castle->buildingsBuiltFlags & (1 << BUILDING_DOCK) && gpAdvManager->GetCell(this->castle->buildDockRelated, this->castle->boatCell)->objType)
    this->castle->buildingsBuiltFlags |= (1 << BUILDING_BOAT);
  else
    this->castle->buildingsBuiltFlags &= 0xFFFFBFFFu; // remove boat flag
}

void townManager::SetupCastle(heroWindow *window, int a3) {
  enum BUILDING_STATUS_IMAGES {
    IMAGE_CHECKMARK = 11,
    IMAGE_CROSS = 12,
    IMAGE_NOT_ENOUGH_RESOURCES = 13
  };

  enum GUI_FIELDS {
    GUI_BUILD_SCREEN_BUILDING_TEXTBAR = 400,
    GUI_BUILD_SCREEN_BUILDING_TEXT = 600,
    GUI_BUILD_SCREEN_BUILDING_IMAGE = 700,
    GUI_BUILD_SCREEN_BUILDING_STATUS_ICON = 800
  };

  casWin = window;

  for(int i = 0; i < NUM_BUILDING_SLOTS; ++i) {
    castleSlotsUse[i] = castleSlotsBase[i];
    town *twn = this->castle;
    unsigned int builtFlags = twn->buildingsBuiltFlags;
    int bld = castleSlotsBase[i];
    int bldUpgr = bld + 5;
    int faction = twn->factionID;
    if(bld >= BUILDING_DWELLING_2 && bld <= BUILDING_DWELLING_6 && gTownEligibleBuildMask[faction] & (1 << (bldUpgr))) {
      if(twn->BuildingBuilt(bld) || twn->BuildingBuilt(bldUpgr) || bld == BUILDING_DWELLING_6 && faction == FACTION_WARLOCK && twn->BuildingBuilt(BUILDING_UPGRADE_5B)) {
        if(bld == BUILDING_DWELLING_6 && faction == FACTION_WARLOCK && (twn->BuildingBuilt(BUILDING_UPGRADE_5) || twn->BuildingBuilt(BUILDING_UPGRADE_5B)))
          castleSlotsUse[i] = BUILDING_UPGRADE_5B;
        else
          castleSlotsUse[i] = bldUpgr;
      }
    }
  }

  this->canBuildFlags = this->canBuyFlags = 0;
  for(int i = 0; i < NUM_BUILDING_SLOTS; ++i) {
    if(CanBuy(this->castle, castleSlotsUse[i]))
      this->canBuyFlags |= 1 << castleSlotsUse[i];
    if(CanBuild(this->castle, castleSlotsUse[i]))
      this->canBuildFlags |= 1 << castleSlotsUse[i];
  }
  
  sprintf(gText, "cstl%s.icn", cHeroTypeShortName[this->castle->factionID]);
  for(int i = 0; i < NUM_BUILDING_SLOTS; ++i) {
    GUISetIcon(casWin, i + GUI_BUILD_SCREEN_BUILDING_IMAGE, gText);
    GUISetImgIdx(casWin, i + GUI_BUILD_SCREEN_BUILDING_IMAGE, castleSlotsUse[i]);
  }

  for(int i = 0; i < NUM_BUILDING_SLOTS; ++i) {
    if(castleSlotsUse[i] == BUILDING_MAGE_GUILD) {
      int mageGuildLevel = this->castle->mageGuildLevel + 1;
      if(mageGuildLevel >= 5)
        mageGuildLevel = 5;
      GUISetText(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXT, "Mage Guild, Level " + std::to_string(mageGuildLevel));
    } else {
      GUISetText(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXT, GetBuildingName(this->castle->factionID, castleSlotsUse[i]));
    }
  }

  int imgIdx;
  for(int i = 0; i < NUM_BUILDING_SLOTS; ++i) {
    imgIdx = -1;
    bool disallowed = false;
    if(this->castle->IsDisallowed(castleSlotsUse[i])) {
      disallowed = true;
      imgIdx = IMAGE_CROSS;
    } else if((1 << castleSlotsUse[i]) & this->castle->buildingsBuiltFlags
      && (castleSlotsUse[i] || this->castle->mageGuildLevel == 5)) {
      imgIdx = IMAGE_CHECKMARK;
    } else {
      if((1 << castleSlotsUse[i]) & this->canBuildFlags) {
        if(!((1 << castleSlotsUse[i]) & this->canBuyFlags))
          imgIdx = IMAGE_NOT_ENOUGH_RESOURCES;
      } else {
        imgIdx = IMAGE_CROSS;
      }
    }
    if(imgIdx == -1)
      GUIRemoveFlag(casWin, i + GUI_BUILD_SCREEN_BUILDING_STATUS_ICON, 4);
    else {
      GUIAddFlag(casWin, i + GUI_BUILD_SCREEN_BUILDING_STATUS_ICON, 4);
      GUISetImgIdx(casWin, i + GUI_BUILD_SCREEN_BUILDING_STATUS_ICON, imgIdx);
    }
    if(imgIdx == IMAGE_CHECKMARK)
      GUIRemoveFlag(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXTBAR, 4);
    else {
      GUIAddFlag(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXTBAR, 4);
      if(disallowed) {
        GUISetImgIdx(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXTBAR, 3);
      } else if(imgIdx == -1) {
        GUISetImgIdx(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXTBAR, 1);
      } else
        GUISetImgIdx(casWin, i + GUI_BUILD_SCREEN_BUILDING_TEXTBAR, 2);
    }
  }

  int hasCaptain = this->castle->buildingsBuiltFlags & (1 << BUILDING_CAPTAIN);
  if(hasCaptain) {
    GUIRemoveFlag(casWin, 1101, 6);
    GUISetImgIdx(casWin, 1100, 1);
    GUIAddFlag(casWin, 1106, 4);
    GUISetImgIdx(casWin, 1106, gpCurPlayer->color);
  } else {  
    GUIAddFlag(casWin, 1101, 6);
    GUISetImgIdx(casWin, 1100, 0);
    GUIRemoveFlag(casWin, 1106, 4);
  }

  sprintf(gText, "CSTLCAP%c.ICN", cHeroTypeInitial[this->castle->factionID]);
  GUISetIcon(casWin, 1100, gText);

  imgIdx = -1;

  if(hasCaptain) {
    char a2[100];
    sprintf(gText, "");
    for(int i = 0; i < 4; ++i) {
      sprintf(a2, "%s\n", gStatNames[i]);
      strcat(gText, a2);
    }
    GUISetText(casWin, 1104, gText);

    sprintf(gText, "");
    for(int i = 0; i < 4; ++i) {
      sprintf(a2, "%d\n", captainStats[this->castle->factionID][i]);
      strcat(gText, a2);
    }
    GUISetText(casWin, 1105, gText);

    if(this->castle->field_38) {
      GUIRemoveFlag(casWin, 213, 4);
      GUIAddFlag(casWin, 215, 4);
    } else {
      GUIAddFlag(casWin, 213, 4);
      GUIRemoveFlag(casWin, 215, 4);
    }
  } else {
    if(CanBuild(this->castle, BUILDING_CAPTAIN)) {
      if(!CanBuy(this->castle, BUILDING_CAPTAIN))
        imgIdx = IMAGE_NOT_ENOUGH_RESOURCES;
    } else {
      imgIdx = IMAGE_CROSS;
    }
    if(CanBuild(this->castle, BUILDING_CAPTAIN))
      this->canBuildFlags |= 1 << BUILDING_CAPTAIN;
    if(CanBuy(this->castle, BUILDING_CAPTAIN))
      this->canBuyFlags |= 1 << BUILDING_CAPTAIN;
  }

  if(imgIdx == -1) {
    GUIRemoveFlag(casWin, 1102, 4);
  } else {
	  GUISetImgIdx(casWin, 1102, imgIdx);
	  GUIAddFlag(casWin, 1102, 4);
  }

  if(gpCurPlayer->resources[RESOURCE_GOLD] >= gHeroGoldCost) {
    if(gpCurPlayer->numHeroes != 8 && this->castle->visitingHeroIdx == -1) {
      if(this->isRecruitingHero)
        imgIdx = IMAGE_CHECKMARK;
      else
        imgIdx = -1;
    } else {
      imgIdx = IMAGE_CROSS;
    }
  } else {
    imgIdx = IMAGE_NOT_ENOUGH_RESOURCES;
  }

  for(int i = 0; i < 2; ++i) {
    int field = i + 902;
    if(imgIdx == -1) {
      GUIRemoveFlag(casWin, field, 4);
    } else {
      GUIAddFlag(casWin, field, 4);
      GUISetImgIdx(casWin, field, imgIdx);
    }
    sprintf(gText, "port%04d.icn", gpGame->heroes[gpCurPlayer->heroesForPurchase[i]].heroID);
    field = i + 900;
    GUISetIcon(casWin, field, gText);
  }

  // Drawing castle and terrain underneath
  if(!a3) {
    // find terrain id under castle
    int index = (unsigned char)this->castle->y * gpGame->map.width + (unsigned char)this->castle->x;
    int terrain = giGroundToTerrain[gpGame->map.tiles[index].groundIndex];
    // find correct frame offset
    int frameOffset = 2 * (5 * terrain - 5);

    int currentFrame = 0;
    for(int j = 5; j <= 6; ++j) {
      for(int k = 4; k <= 8; ++k) {
        int x = 32 * (k - 4) + 458;
        int y = 32 * (j - 2);
        int frame = currentFrame + frameOffset;
          widget *guiObj = (widget *)new iconWidget(x, y, 32, 32, "objntwba.icn", frame, 0, -1, 16, 1);
        if(!guiObj)
          MemError();
        casWin->AddWidget(guiObj, -1);
        ++currentFrame;
      }
    }

    currentFrame = 0;
    frameOffset = 32 * this->castle->factionID;
    if(this->castle->factionID == FACTION_CYBORG)
      frameOffset = 32 * 6;
    for(int j = 2; j <= 5; ++j) {
      for(int k = 4; k <= 8; ++k) {
        if(j != 2 || k == 6) {
          int x = 32 * (k - 4) + 458;
          int y = 32 * (j - 2);
          int frame = currentFrame + frameOffset;
            widget *guiObj = (widget *)new iconWidget(x, y, 32, 32, "objntown.icn", frame, 0, -1, 16, 1);
          if(!guiObj)
            MemError();
          casWin->AddWidget(guiObj, -1);
          ++currentFrame;
        }
      }
    }

    if(!xIsExpansionMap && this->castle->factionID == FACTION_NECROMANCER) {
      widget *guiObj = (widget *)new iconWidget(149, 157, 137, 72, "caslxtra.icn", 0, 0, -1, 16, 1);
      if(!guiObj)
        MemError();
      casWin->AddWidget(guiObj, -1);
    }
  }
}

int __fastcall CanBuild(town *twn, int building) {    
  if(BitTest((const LONG*)gpGame->builtToday, twn->idx)) {
    return 0;
  }

  if(twn->IsDisallowed(building))
    return 0;

  unsigned int builtFlags = twn->buildingsBuiltFlags;
  if(!(builtFlags & (1 << BUILDING_CASTLE)) && building != BUILDING_CASTLE)
    return 0;

  if(twn->factionID == FACTION_NECROMANCER && building == BUILDING_TAVERN && !xIsExpansionMap)
    return 0;

  if(building == BUILDING_DOCK) {
    if(twn->CanBuildDock())
      return 1;
    return 0;
  }

  if(building == BUILDING_MAGE_GUILD && twn->mageGuildLevel >= 5)
    return 0;

  if(building == BUILDING_TENT || building == BUILDING_BOAT || building == BUILDING_EXT_0 || building == BUILDING_EXT_1 || building == BUILDING_EXT_2 || building == BUILDING_EXT_3)
    return 0;

  if(building >= BUILDING_DWELLING_1 && building <= BUILDING_UPGRADE_5B) {
    if(building == BUILDING_DWELLING_2 && builtFlags & (1 << BUILDING_UPGRADE_1)
      || building == BUILDING_DWELLING_3 && builtFlags & (1 << BUILDING_UPGRADE_2)
      || building == BUILDING_DWELLING_4 && builtFlags & (1 << BUILDING_UPGRADE_3)
      || building == BUILDING_DWELLING_5 && builtFlags & (1 << BUILDING_UPGRADE_4)
      || building == BUILDING_DWELLING_6 && (builtFlags & (1 << BUILDING_UPGRADE_5) || builtFlags & (1 << BUILDING_UPGRADE_5B))
      || building == BUILDING_UPGRADE_5 && builtFlags & (1 << BUILDING_UPGRADE_5B)) {
      return 0;
    }

    if(builtFlags & (1 << BUILDING_UPGRADE_1))
      builtFlags |= (1 << BUILDING_DWELLING_2);
    if(builtFlags & (1 << BUILDING_UPGRADE_2))
      builtFlags |= (1 << BUILDING_DWELLING_3);
    if(builtFlags & (1 << BUILDING_UPGRADE_3))
      builtFlags |= (1 << BUILDING_DWELLING_4);
    if(builtFlags & (1 << BUILDING_UPGRADE_4))
      builtFlags |= (1 << BUILDING_DWELLING_5);
    if(builtFlags & (1 << BUILDING_UPGRADE_5))
      builtFlags |= (1 << BUILDING_DWELLING_6);
    if(builtFlags & (1 << BUILDING_UPGRADE_5B))
      builtFlags |= (1 << BUILDING_UPGRADE_5);
    int mask = gHierarchyMask[twn->factionID][building - 19];
    if((builtFlags & mask) == mask)
      return twn->factionID != FACTION_NECROMANCER || building != BUILDING_UPGRADE_4 || twn->mageGuildLevel > 1;
    return 0;
  }
  return 1;
}

void town::SetFaction(FACTION faction) {
  // Shift of town graphics in relation to current graphics
  // Setting offset in such a way that makes the town have frames from the first faction town/castle
  int oldFactionID = this->factionID;
  int imgOffset = -oldFactionID;
  if(this->factionID == FACTION_CYBORG)
    imgOffset = -6;
  
  // Meanwhile applying some town changes
  this->field_55 = 10;
  this->factionID = faction;

  // Destroying buildings that don't exist in new faction
  for(int bldIdx = BUILDING_MAX - 1; bldIdx >= 0; bldIdx--) {
    unsigned long eligibleBuildMask = gTownEligibleBuildMask[faction];
    int bldMask = (1 << bldIdx);

    // Skip if building is a castle, not built or can be built
    if(bldIdx == BUILDING_CASTLE || !(bldMask & this->buildingsBuiltFlags) || (bldMask & eligibleBuildMask))
      continue;

    // Remove building that can't be built
    this->buildingsBuiltFlags &= ~(bldMask);

    // Downgrade buildings if upgraded ones don't exist in new faction
    int dwellingIdx = bldIdx - 19;
    int numCreatures = this->numCreaturesInDwelling[dwellingIdx];
    if(bldIdx == BUILDING_UPGRADE_5B) {
      this->numCreaturesInDwelling[dwellingIdx] = 0;
      int downgradedBldIdx = BUILDING_UPGRADE_5;
      int downgradedBldMask = (1 << downgradedBldIdx);
      dwellingIdx = downgradedBldIdx - 19;

      if(!(downgradedBldMask & eligibleBuildMask)) {
        this->numCreaturesInDwelling[dwellingIdx] = 0;
        downgradedBldIdx = BUILDING_DWELLING_6;
        dwellingIdx = downgradedBldIdx - 19;
        downgradedBldMask = (1 << downgradedBldIdx);
      }
      this->buildingsBuiltFlags |= downgradedBldMask;
      this->numCreaturesInDwelling[dwellingIdx] = numCreatures;
    } else if(bldIdx >= BUILDING_UPGRADE_1 && bldIdx <= BUILDING_UPGRADE_5) {
      this->numCreaturesInDwelling[dwellingIdx] = 0;      
      int downgradedBldIdx = bldIdx - 5;
      int downgradedBldMask = (1 << downgradedBldIdx);
      dwellingIdx = downgradedBldIdx - 19;

      if(downgradedBldMask & eligibleBuildMask) {
        this->buildingsBuiltFlags |= downgradedBldMask;
        this->numCreaturesInDwelling[dwellingIdx] = numCreatures;
      }
    }    
  }
  
  // Now we set the offset of graphics for requested faction
  if(faction == FACTION_CYBORG)
    imgOffset += 6;
  else
    imgOffset += faction;

  int xFrom, xTo, yFrom, yTo;
  xFrom = this->x - 5;
  xTo   = this->x + 2;
  yFrom = this->y - 3;
  yTo   = this->y + 1;
  gpGame->ConvertObject(xFrom, yFrom, xTo, yTo, TILESET_OBJ_TOWN, 0, 255, TILESET_OBJ_TOWN, 32 * imgOffset, TILESET_OBJ_TOWN, TILESET_OBJ_TOWN);
  gpGame->ConvertObject(xFrom, yFrom, xTo, yTo, TILESET_TOWN_SHADOW, 0, 255, TILESET_TOWN_SHADOW, 32 * imgOffset, TILESET_OBJ_TOWN, TILESET_OBJ_TOWN);
}

int townManager::BuyBuild(int building, int notEnoughResources, int isRightClick) {
  const int faction = gpTownManager->castle->factionID;
  int specialCosts[NUM_RESOURCES], dwellingCosts[NUM_DWELLINGS][NUM_RESOURCES];
  BuildingCostToIntArray(gSpecialBuildingCosts[faction], specialCosts);
  for(int i = 0; i < NUM_DWELLINGS; i++)
    BuildingCostToIntArray(gDwellingCosts[faction][i], dwellingCosts[i]);

  int mageGuildLevel = gpTownManager->castle->mageGuildLevel + 1;
  if(mageGuildLevel >= 5)
    mageGuildLevel = 5;

  short costValue[NUM_RESOURCES];
  char costType[NUM_RESOURCES];
  int costAmount = 0;

  for(int i = 0; i < NUM_RESOURCES; ++i)
    costValue[i] = costType[i] = -1;

  int dwellingIndex = -1;
  if(building >= BUILDING_DWELLING_1 && building <= BUILDING_UPGRADE_5B)
    dwellingIndex = building - BUILDING_DWELLING_1;

  for(int i = 0; i < NUM_RESOURCES; ++i) {
    if(building == BUILDING_TAVERN && faction == FACTION_NECROMANCER) {
      if(xShrineBuildingCost[i] > 0) {
        costType[costAmount] = i;
        costValue[costAmount++] = xShrineBuildingCost[i];
      }
    } else if(building == BUILDING_MAGE_GUILD) {
        if(gMageBuildingCosts[mageGuildLevel][i] > 0) {
          costType[costAmount] = i;
          costValue[costAmount++] = gMageBuildingCosts[mageGuildLevel][i];
        }
    } else if(building == BUILDING_SPECIAL) {
      if(specialCosts[i] > 0) {
        costType[costAmount] = i;
        costValue[costAmount++] = specialCosts[i];
      }
    } else if(building > BUILDING_CAPTAIN) {
      if(dwellingCosts[dwellingIndex][i] > 0) {
        costType[costAmount] = i;
        costValue[costAmount++] = dwellingCosts[dwellingIndex][i];
      }
    } else {
      if(gNeutralBuildingCosts[building][i] > 0) {
        costType[costAmount] = i;
        costValue[costAmount++] = gNeutralBuildingCosts[building][i];
      }
    }
  }
  
  int resourcesToSpend = 0;
  for(int i = 0; i < NUM_RESOURCES; ++i) {
    if(costType[i] != -1)
      ++resourcesToSpend;
  }

  int numResFirstRow = 0;
  int numResSecondRow = 0;
  if(resourcesToSpend > 4) {
    switch(resourcesToSpend) {
      case 5:
        numResFirstRow = 2;
        numResSecondRow = 3;
        break;
      case 6:
        numResFirstRow = 3;
        numResSecondRow = 3;
        break;
      case 7:
        numResFirstRow = 3;
        numResSecondRow = 4;
        break;
    }
  } else {
    numResFirstRow = resourcesToSpend;
  }

  char *content = (char *)BaseAlloc(400, __FILE__, __LINE__);
  sprintf(content, GetBuildingInfo(faction, building, 0));

  if(this->castle->IsDisallowed(building))
    strcat(content, "\n\nCan't be built in this town.");
  else if(dwellingIndex >= 0) {
    int numRequiredBuildings = 0;
    for(int i = 0; i < BUILDING_MAX; ++i) {
      if((1 << i) & gHierarchyMask[faction][dwellingIndex]) {
        if(!numRequiredBuildings)
          strcat(content, "\n\nRequires:");
        ++numRequiredBuildings;
        strcat(content, "\n");
        strcat(content, GetBuildingName(faction, i));
      }
    }
    if(faction == FACTION_NECROMANCER && building == BUILDING_UPGRADE_4 && this->castle->mageGuildLevel <= 2)
      strcat(content, "\nLevel 2 Mage Guild");
  }
  strcat(content, "\n ");

  int lineLength = bigFont->LineLength(content, 240);
  int yOffset = 151;
  int guiHeight = 16 * lineLength + 151;
  if(resourcesToSpend > 4)
    guiHeight += 88;
  else
    guiHeight += 44;

  if(!isRightClick)
    guiHeight += 39;

  int buildGuiType = (guiHeight - 69) / 45;
  if(buildGuiType < 3)
    buildGuiType = 3;
  if(buildGuiType > 6)
    buildGuiType = 6;
  sprintf(gText, "buybuil%d.bin", buildGuiType);

  heroWindow *window = new heroWindow(158, 16, gText);
  if(!window)
    MemError();

  sprintf(gText, "cstl%s.icn", cHeroTypeShortName[faction]);

  GUISetIcon(window, 2, gText);
  GUISetImgIdx(window, 2, building);

  if(building == BUILDING_MAGE_GUILD)
    sprintf(gText, "Mage Guild, Level %d", mageGuildLevel);
  else
    strcpy(gText, GetBuildingName(faction, building));

  GUISetText(window, 3, gText);

  widget *guiObj = new textWidget(43, yOffset + 24, 240, 16 * lineLength, content, "bigfont.fnt", 1, -1, 8, 1);
  if(!guiObj)
    MemError();

  window->AddWidget(guiObj, -1);

  const int RESOURCE_MAX_PER_LINE = 4;
  if(!this->castle->IsDisallowed(building)) {
    int resourceTypes[RESOURCE_MAX_PER_LINE];
    int currentRes = 0;
    icon *res = gpResourceManager->GetIcon("resource.icn");
    for(int row = 0; row < 2; ++row) {
      int y = yOffset + 16 * lineLength + 44 * row + 12;
      int numRes;
      if(row)
        numRes = numResSecondRow;
      else
        numRes = numResFirstRow;

      if(numRes <= 0)
        break;

      costAmount = currentRes;

      for(int i = 0; i < RESOURCE_MAX_PER_LINE; ++i) {
        if(i >= numRes) {
          resourceTypes[i] = -1;
        } else {
          while(costType[costAmount] == -1)
            ++costAmount;
          resourceTypes[i] = costType[costAmount++];
        }
      }

      int iconsWidth = 0;
      for(int i = 0; i < numRes; ++i)
        iconsWidth += GetIconEntry(res, resourceTypes[i])->width;

      int marginX = (256 - iconsWidth) / (numRes + 1);
      int x = (256 - iconsWidth) / (numRes + 1) + 32;

      for(int i = 0; i < numRes; ++i) {
        int width = GetIconEntry(res, resourceTypes[i])->width;
        char *text = (char*)BaseAlloc(10, __FILE__, __LINE__);
        sprintf(text, "%d", costValue[currentRes]);

        widget *resText = new textWidget(x, y + 35, width, 12, text, "smalfont.fnt", 1, -1, 8, 1);
        if(!resText)
          MemError();

        short imgIdx = costType[currentRes];

        widget *resourceIcn = new iconWidget(x - GetIconEntry(res, resourceTypes[i])->offsetX, y, width, 12, "resource.icn", imgIdx, 0, -1, 16, 1);
        if(!resourceIcn)
          MemError();

        window->AddWidget(resText, -1);
        currentRes++;
        window->AddWidget(resourceIcn, -1);
        x += width + marginX;
      }
    }
    gpResourceManager->Dispose((resource *)res);
  }

  if(!isRightClick)
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_ADD_FLAGS, BUTTON_EXIT, 16392);
  
  this->buildingToBuild = -1;
  if(isRightClick) {
    GUIRemoveFlag(window, BUTTON_OK, 6);
    GUIRemoveFlag(window, BUTTON_CANCEL, 6);
    GUIRemoveFlag(window, 0, 6);
    gpWindowManager->AddWindow(window, -1, 1);
    QuickViewWait();
    gpWindowManager->RemoveWindow(window);
  } else {
    if(notEnoughResources) {
      GUIRemoveFlag(window, BUTTON_OK, 2);
      GUIAddFlag(window, BUTTON_OK, 4096);
    }
    gpWindowManager->DoDialog(window, TrueFalseDialogHandler, 0);
    if(gpWindowManager->buttonPressedCode == BUTTON_OK) {
      this->buildingToBuild = building;
      for(int i = 0; i < resourcesToSpend; ++i)
        gpCurPlayer->resources[costType[i]] -= costValue[i];
    }
  }

  if(!isRightClick)
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_REMOVE_FLAGS, BUTTON_EXIT, 16392);

  delete window;

  if(isRightClick)
    return 0;

  return gpWindowManager->buttonPressedCode == BUTTON_OK;
}