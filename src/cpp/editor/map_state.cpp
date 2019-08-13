#include "adventure/hero_globals.h"
#include "adventure/map.h"
#include "editor.h"

#include "base.h"

extern unsigned __int16 gpRumorIndices[];
extern unsigned __int16 gpEventDataIndices[];
extern int __fastcall HasExtraObjectData(int);

void __fastcall DeleteExtraObjectData(unsigned int idx) {
	FREE(gpEditManager->mapExtra[idx]);

    if (gpEditManager->nMapExtra > idx + 1) {
        memmove(
            &gpEditManager->mapExtra[idx],
            &gpEditManager->mapExtra[idx + 1],
            sizeof(void*) * (gpEditManager->nMapExtra - (idx + 1)));

        memmove(
            &gpEditManager->lenMapExtra[idx],
            &gpEditManager->lenMapExtra[idx + 1],
            sizeof(__int16) * (gpEditManager->nMapExtra - (idx + 1)));
    }

    gpEditManager->nMapExtra--;

    for (int i = 0; i < gpMapHeader.numRumors; i++) {
        if (gpRumorIndices[i] >= idx) {
            gpRumorIndices[i]--;
        }
    }

    for (int i = 0; i < gpMapHeader.numEvents; i++) {
        if (gpEventDataIndices[i] >= idx) {
            gpEventDataIndices[i]--;
        }
    }

    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            mapCell *cell = &gpMap.tiles[j * gpMap.width + i];
            if (HasExtraObjectData(cell->objType) && cell->extraInfo >= idx) {
                cell->extraInfo--;
            }
        }
    }
}

void __fastcall CalculatePlayerNumbers() {
  int maxHumans = 0;
  int numPlayers = 0;
  int minHumans = 0;
  for(int i = 0; i < 6; ++i) {
    if(gpMapHeader.hasPlayer[i]) {
      if(!gpMapHeader.playerMayBeHuman[i] && !gpMapHeader.playerMayBeComp[i])
        gpMapHeader.playerMayBeComp[i] = 1;
      if(gpMapHeader.playerMayBeHuman[i])
        ++maxHumans;
      if(gpMapHeader.playerMayBeHuman[i] || gpMapHeader.playerMayBeComp[i])
        ++numPlayers;
      if(gpMapHeader.playerMayBeHuman[i]) {
        if(!gpMapHeader.playerMayBeComp[i])
          ++minHumans;
      }
    } else {
      gpMapHeader.playerMayBeHuman[i] = 0;
      gpMapHeader.playerMayBeComp[i] = 0;
    }
  }

  if(!maxHumans) {
    for(int i = 0; i < 6; ++i) {
      if(gpMapHeader.hasPlayer[i]) {
        gpMapHeader.playerMayBeHuman[i] = 1;
        maxHumans = 1;
        minHumans = 1;
        break;
      }
    }
  }

  gpMapHeader.numPlayers = numPlayers;
  gpMapHeader.minHumans = minHumans;
  gpMapHeader.maxHumans = maxHumans;

  for(int i = 0; i < 6; ++i)
    gpMapHeader.playerFactions[i] = -1;

  char playerHasFaction[6][MAX_FACTIONS];
  memset(playerHasFaction, 0, 6 * MAX_FACTIONS);
  for(int x = 0; x < MAP_WIDTH; ++x) {
    for(int y = 0; y < MAP_HEIGHT; ++y) {
      mapCell *cell = &gpMap.tiles[y * (unsigned int)gpMap.width  + x];
      if(cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_HERO)) {
        int player = GetHeroOverlayColor(cell->objectIndex);
        int faction = GetHeroOverlayFaction(cell->objectIndex);
        playerHasFaction[player][faction] = true;
      }
      if(cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_CASTLE) || cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_TOWN) || cell->objType == (TILE_HAS_EVENT | LOCATION_TOWN)) {
        TownExtra *cstl = (TownExtra *)gpEditManager->mapExtra[cell->extraInfo];
        if(cstl->color != -1) {
          int player = cstl->color;
          int faction = cstl->faction;
          playerHasFaction[player][faction] = true;
        }
      }
    }
  }

  int lastFaction = 0;
  int numFactions = 0;
  for(int i = 0; i < 6; ++i) {
    if(gpMapHeader.hasPlayer[i]) {
      if(playerHasFaction[i][FACTION_MULTIPLE]) {
        gpMapHeader.playerFactions[i] = FACTION_RANDOM;
      } else {
        numFactions = 0;
        for(int faction = 0; faction < MAX_FACTIONS; ++faction) {
          if(playerHasFaction[i][faction]) {
            ++numFactions;
            lastFaction = faction;
          }
        }
        if(numFactions == 1)
          gpMapHeader.playerFactions[i] = lastFaction;
        else
          gpMapHeader.playerFactions[i] = FACTION_MULTIPLE;
      }
    }
  }
}

void __fastcall ResetPlayerAvailability() {
  memset(gpMapHeader.hasPlayer, 0, 6u);
  for(int i = 0; i < MAP_WIDTH; ++i) {
    for(int j = 0; j < MAP_HEIGHT; ++j) {
      mapCell *cell = &gpMap.tiles[j * (unsigned int)gpMap.width + i];
      if(cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_HERO))
        gpMapHeader.hasPlayer[GetHeroOverlayColor(cell->objectIndex)] = 1;
      if(cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_CASTLE) || cell->objType == (TILE_HAS_EVENT | LOCATION_RANDOM_TOWN) || cell->objType == (TILE_HAS_EVENT | LOCATION_TOWN)) {
        TownExtra *twn = (TownExtra *)gpEditManager->mapExtra[cell->extraInfo];
        if(twn->color != -1)
          gpMapHeader.hasPlayer[twn->color] = 1;
      }
    }
  }
  CalculatePlayerNumbers();
}