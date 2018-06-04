#include<stdio.h>

#include "base.h"

#include "artifacts.h"

#include "adventure/map.h"
#include "editor.h"
#include "overlay/overlay.h"
#include "overlay/overlays_xml.hxx"
#include "town/town.h"


#define MAX_OVERLAYS 320000

// Actual count must still be NUM_OVERLAYS, for this count is referenced multiple places in the assembly.
overlay gOverlayDatabase[MAX_OVERLAYS] = { 0 };
int giOverlayCount;

/*
 * XSD has minOccurs/maxOccurs, but not a true optional type. These should be considered 0/1 optional
 */
long long BitmaskStringToLong(const overlay_t::tiles_sequence &bitmaskStringSeq) {
  if (bitmaskStringSeq.size() == 0) {
    return 0;
  }
  else {
    const overlay_t::tiles_type& tiles = bitmaskStringSeq[0];

    long long mask = 0;

    int idx = 0;
    for (char c : tiles) {
      if (c == '0' || c == '1') {
        mask |= ((c - '0') << idx);
        idx++;
      }
    }

    return mask;
  }
}

void LoadOverlays() {
  try {
    auto allOverlays = overlays_("./DATA/overlays.xml");
    const auto &overlayList = allOverlays->overlay();

    if (overlayList.size() != NUM_OVERLAYS) {
      EarlyShutdown("Error loading overlays",
        "Mismatch between expected and actual number of overlays. "
        "Adding new map overlays still requires changing the code.");
    }

    int i = 0;
    for (const auto &ovr : overlayList) {
      overlay* curOverlay = &gOverlayDatabase[i];

      curOverlay->idx = ovr.idx();
      curOverlay->idx2 = ovr.idx2();
      curOverlay->ordinal = ovr.ordinal();
      curOverlay->tileset = ovr.tileset();
      curOverlay->category = ovr.category();
      curOverlay->animationLength = ovr.animationLength();
      curOverlay->intersectsTileMask = BitmaskStringToLong(ovr.tiles());
      curOverlay->animatedLateOverlay = BitmaskStringToLong(ovr.animatedTiles());

      i++;
    }
  } catch (const xml_schema::exception& e) {
    std::string errorMsg = "Error loading overlays.xml: ";
    errorMsg += e.what();
    errorMsg += "  Try reinstalling Ironfist.";
    EarlyShutdown("Startup Error", const_cast<char*>(errorMsg.c_str()));
  }
}

int NumTownsOfColor(int color) {
    int n = 0;

    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            mapCell *cell = &gpMap.tiles[i * gpMap.width + j];
            if(!(cell->objType & TILE_HAS_EVENT)) {
                continue;
            }

            unsigned char typ = cell->objType & (~TILE_HAS_EVENT);
            if(typ == LOCATION_TOWN || typ == LOCATION_RANDOM_CASTLE || typ == LOCATION_RANDOM_TOWN) {
                TownExtra *mapExtra = (TownExtra*)gpEditManager->mapExtra[cell->extraInfo];
                if(mapExtra->color == color) {
                    n++;
                }
            }
        }
    }

    return n;
}

int CountHeroes(int color) {
    int n = 0;

    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            mapCell *cell = &gpMap.tiles[i * gpMap.width + j];
            unsigned char typ = cell->objType & (~TILE_HAS_EVENT);
            if((typ == LOCATION_HERO || typ == LOCATION_RANDOM_HERO) && cell->objectIndex / 7 == color) {
                n++;
            }
        }
    }

    if(!gpMapHeader.noStartingHeroInCastle && NumTownsOfColor(color) > 0) {
        n++;
    }

    return n;
}

void __cdecl FillInOverlayTiles()
{
  int previousTileset = -1;
  int nextOverlayIconIdxStart[NUM_TILESETS];
  for(int i = 0; i < NUM_TILESETS; i++) {
      nextOverlayIconIdxStart[i] = 0;
  }

  int v7 = 0;
  for(int k = 0; k < NUM_OVERLAYS; k++ ) {
    int v9 = 0;
    overlay* ovr = &gOverlayDatabase[k];
    int tset = gOverlayDatabase[k].tileset;
    previousTileset = ovr->tileset;
    if ( ovr->field_4E == 1111 )
      nextOverlayIconIdxStart[tset] = v7;
    if ( !ovr->field_4E )
      nextOverlayIconIdxStart[tset] = 0;
    int nextIconIdx = nextOverlayIconIdxStart[tset];
    v7 = nextOverlayIconIdxStart[tset];
    int cellPos = 0;
    for (int i = 0; i < 6; i++) {
      for(int j = 0; j < 8; j++) {
        if(OverlayMaskBitSet(&ovr->intersectsTileMask, j, i)) {
          if ( 8 - j > v9 )
            v9 = 8 - j;
          if ( ovr->field_4E >= 0 )
            ovr->fullGridIconIndices[cellPos] = nextIconIdx;
          if (OverlayMaskBitSet(&ovr->animatedLateOverlay, j, i)) {
            nextIconIdx += ovr->animationLength + 1;
            nextOverlayIconIdxStart[tset] += ovr->animationLength + 1;
          }
          else
          {
            ++nextIconIdx;
            ++nextOverlayIconIdxStart[tset];
          }
        }
        else if ( ovr->field_4E >= 0 )
        {
          ovr->fullGridIconIndices[cellPos] = -1;
        }
        ++cellPos;
      }
    }
    ovr->field_4D = v9;
  }
}

extern int giCurOverlayIdx;
extern unsigned char unknownTerrainTileAttribute[];

extern void __fastcall UnknownPlaceOverlayHelper(overlay*, int left, int top);
extern int __fastcall SetMineResourceIcon(overlay*, int x, int y, int);

template <typename T> void AddMapExtra(mapCell *tile, T mapExtra) {
    tile->extraInfo = gpEditManager->nMapExtra;
    gpEditManager->mapExtra[gpEditManager->nMapExtra] = mapExtra;
    gpEditManager->lenMapExtra[gpEditManager->nMapExtra++] = sizeof(T);
}

HeroExtra *MakeHeroMapExtra(int faction) {
    HeroExtra *heroMapExtra = new HeroExtra;

    for (int k = 0; k < ELEMENTS_IN(heroMapExtra->army.creatureTypes); k++) {
        heroMapExtra->army.creatureTypes[k] = -1;
    }

    for (int k = 0; k < ELEMENTS_IN(heroMapExtra->artifacts); k++) {
        heroMapExtra->artifacts[k] = -1;
    }

    for (int k = 0; k < ELEMENTS_IN(heroMapExtra->secondarySkills); k++) {
        heroMapExtra->secondarySkills[k] = -1;
    }

    if (faction == FACTION_KNIGHT) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_LEADERSHIP;
        heroMapExtra->secondarySkillLevel[0] = 1;
        heroMapExtra->secondarySkills[1] = SECONDARY_SKILL_BALLISTICS;
        heroMapExtra->secondarySkillLevel[1] = 1;
    }

    if (faction == FACTION_SORCERESS) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_NAVIGATION;
        heroMapExtra->secondarySkillLevel[0] = 2;
        heroMapExtra->secondarySkills[1] = SECONDARY_SKILL_WISDOM;
        heroMapExtra->secondarySkillLevel[1] = 1;
    }

    if (faction == FACTION_BARBARIAN) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_PATHFINDING;
        heroMapExtra->secondarySkillLevel[0] = 2;
    }

    if (faction == FACTION_WARLOCK) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_SCOUTING;
        heroMapExtra->secondarySkillLevel[0] = 2;
        heroMapExtra->secondarySkills[1] = SECONDARY_SKILL_WISDOM;
        heroMapExtra->secondarySkillLevel[1] = 1;
    }

    if (faction == FACTION_WIZARD) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_WISDOM;
        heroMapExtra->secondarySkillLevel[0] = 2;
    }

    if (faction == FACTION_NECROMANCER) {
        heroMapExtra->secondarySkills[0] = SECONDARY_SKILL_NECROMANCY;
        heroMapExtra->secondarySkillLevel[0] = 1;
        heroMapExtra->secondarySkills[1] = SECONDARY_SKILL_WISDOM;
        heroMapExtra->secondarySkillLevel[1] = 1;
    }

    return heroMapExtra;
}

TownExtra* MakeTownExtra(int color, int idx) {
    TownExtra* townMapExtra = new TownExtra;

    gpMapHeader.nextTownName = (gpMapHeader.nextTownName + 1) % MAX_CASTLES;
    strcpy(townMapExtra->name, gpTownNames[gpMapHeader.nextTownName]);
    if (color == 6) {
        townMapExtra->color = -1;
    } else {
        townMapExtra->color = color;
    }

    if (idx < 939 || idx > 954) {
        townMapExtra->faction = (idx - 835) % 12 / 2;
        townMapExtra->isCastle = 1
            - ((((unsigned __int64)(idx - 835) >> 32) ^ abs(LOBYTE(idx) - 67) & 1)
            - ((unsigned __int64)(idx - 835) >> 32));
    } else {
        townMapExtra->faction = FACTION_MULTIPLE;
        townMapExtra->isCastle = 1
            - ((((unsigned __int64)(idx - 939) >> 32) ^ ((((unsigned __int64)(idx - 939) >> 32) ^ (unsigned __int8)(LOBYTE(idx) + 85)) - ((unsigned __int64)(idx - 939) >> 32)) & 1)
            - ((unsigned __int64)(idx - 939) >> 32));
    }

    return townMapExtra;
}



int __fastcall PlaceOverlay(overlay *ovr, int left, int top, int userDemanded) {
  if ((ovr->locationType == LOCATION_HERO || ovr->locationType == LOCATION_RANDOM_HERO)
    && CountHeroes(ovr->fullGridIconIndices[47] / 7) >= 8) {

    sprintf(gText, "Max heroes on map (%d) for color has been reached", 8);
    ShowErrorMessage(gText);
    return 0;
  } else {
    return PlaceOverlay_orig(ovr, left, top, userDemanded);
  }
}
