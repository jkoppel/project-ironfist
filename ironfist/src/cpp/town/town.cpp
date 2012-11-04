#include "base.h"
#include "map.h"

#include "adventure/adv.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "spell/spells.h"

void game::SetupTowns() {

  for(int castleIdx = 0; castleIdx < MAX_TOWNS; castleIdx++) {
    if(this->castles[castleIdx].exists) {
      town* castle = &this->castles[castleIdx];
	  int extraIdx = this->castles[castleIdx].extraIdx;
      townMapExtra* twnExtra = (townMapExtra *)ppMapExtra[extraIdx];

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
            castle->buildingsBuiltFlags &= ~((1 << BUILDING_DWELLING_6) || (BUILDING_UPGRADE_5B));
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

      castle->mayNotBeUpgradedToCastle = twnExtra->mayNotBeUpgraded;
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

	for (int i = 0; i < 5; i++) {
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