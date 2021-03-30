#include<stdio.h>

#include "base.h"

#include "artifacts.h"
#include "skills.h"
#include "adventure/adv_globals.h"
#include "adventure/hero_globals.h"
#include "adventure/map.h"
#include "editor.h"
#include "gui/dialog.h"
#include "overlay.h"
#include "overlay_xml.h"
#include "town/town.h"


extern "C" int giOverlaySelectMaybeNumUnseen;
extern "C" int giOverlaySelectNRows;

overlay gOverlayDatabase[MAX_OVERLAYS] = { 0 };
int gNumOverlays = 0;
std::map<int, std::string> overlayNames;

void LoadOverlays() {
  OverlayXML xml;
  std::string filename = "DATA//overlays.xml";
  tinyxml2::XMLError err = xml.Read(filename.c_str());

  if(err) {
    std::string error_message = "Could not load " + filename + "\n" + std::string(xml.GetError());
    DisplayError(error_message, "overlays.xml");
  }
}

void LoadOverlayNames() {
  for(int i = 0; i < gNumOverlays; i++) {
    overlay *ovr = &gOverlayDatabase[i];
    int loc = ovr->locationType;
    int idx = ovr->idx;
    const int FIRST_BARRIER_IDX = 799;
    const int FIRST_TENT_IDX = 807;
    const int FIRST_EXP_DWELLING_IDX = 792;
    char* advMapName = adventureMapLocations[loc];    

    if(loc == LOCATION_BARRIER)
      sprintf(gText, advMapName, barrierColors[idx - FIRST_BARRIER_IDX]);
    else if(loc == LOCATION_TRAVELLER_TENT)
      sprintf(gText, advMapName, barrierColors[idx - FIRST_TENT_IDX]);
    else if(loc == LOCATION_EXPANSION_DWELLING)
      sprintf(gText, advMapName, expDwellingNames[idx - FIRST_EXP_DWELLING_IDX]);
    else if(idx == 790)
      sprintf(gText, "Alchemist's Tower");
    else if(idx == 791)
      sprintf(gText, "Arena");
    else if(idx == 797)
      sprintf(gText, "Hut of the Magi");
    else if(idx == 798)
      sprintf(gText, "Eye of the Magi");
    else if(idx == 815)
      sprintf(gText, "Stables");
    else if(idx == 817)
      sprintf(gText, "Mermaid");
    else if(idx == 818)
      sprintf(gText, "Sirens");
    else if(loc == LOCATION_ROCK && ovr->tileset == TILESET_OBJECT_EXPANSION_2)
      sprintf(gText, "Reefs");
    else
      sprintf(gText, advMapName);

    overlayNames[idx] = gText;
  }
}

int overlayManager::PopulateAvailOverlays(int ovrType) {
  this->nAvailOverlays = 0;
  for(int i = 0; i < gNumOverlays; ++i) {
    overlay *ovr = &gOverlayDatabase[i];
    if(ovr->category == gOverlayTypeCategories[ovrType]) {
      if(ovr->terrainObjCategoryMask & gObjTypeTerrains[ovrType])
        memcpy(&this->availOverlays[this->nAvailOverlays++], ovr, sizeof(this->availOverlays[this->nAvailOverlays++]));
    }
  }
  // bubble sort availOverlays in increasing order
  for(int i = 0; ; ++i) {
    if(this->nAvailOverlays > i) {
      int v7 = 0;
      for(int j = this->nAvailOverlays - 1; j > 0; --j) {
        if(this->availOverlays[j - 1].ordinal > this->availOverlays[j].ordinal) {
          overlay tmp;
          memcpy(&tmp, &this->availOverlays[j], 128u);
          tmp.fullGridIconIndices[46] = this->availOverlays[j].fullGridIconIndices[46];
          tmp.fullGridIconIndices[47] = this->availOverlays[j].fullGridIconIndices[47];
          memcpy(&this->availOverlays[j], &this->availOverlays[j - 1], sizeof(this->availOverlays[j]));
          memcpy(&this->availOverlays[j - 1], &tmp, 128u);
          this->availOverlays[j - 1].fullGridIconIndices[46] = tmp.fullGridIconIndices[46];
          this->availOverlays[j - 1].fullGridIconIndices[47] = tmp.fullGridIconIndices[47];
          v7 = 1;
        }
      }
      if(v7)
        continue;
    }
    break;
  }
  return this->nAvailOverlays != 0;
}

void overlayManager::SetupOverlayWindow(int draw) {
  const int NUM_ROWS = 9;
  const int NUM_COLS = 9;
  const int NUM_OVERLAYS_ON_SCREEN = NUM_ROWS * NUM_COLS;

  char selBoxColorIdx[NUM_ROWS][NUM_COLS];
  memset(selBoxColorIdx, 1, sizeof(selBoxColorIdx));

  for(int i = 0; i + giOverlaySelectMaybeNumUnseen < this->nAvailOverlays && i < NUM_OVERLAYS_ON_SCREEN; ++i) {
    int overlayIdx = i + giOverlaySelectMaybeNumUnseen;
    overlay *ovr = &this->availOverlays[overlayIdx];
    int col = i % NUM_COLS;
    int row = i / NUM_ROWS;
    char locationType = ovr->locationType;
    if(locationType == LOCATION_TOWN || locationType == LOCATION_RANDOM_TOWN || locationType == LOCATION_RANDOM_CASTLE) {
      if(ovr->townColorOrMineColor == 6)
        selBoxColorIdx[col][row] = 1;
      else
        selBoxColorIdx[col][row] = ovr->townColorOrMineColor + 2;
    }
    if(ovr->locationType == LOCATION_RANDOM_HERO)
      selBoxColorIdx[col][row] = ovr->townColorOrMineColor + 2;
  }

  if(giOverlaySelectNRows <= 9)
    this->slider->offsetY = 215;
  else
    this->slider->offsetY = (signed __int64)(393.0 / ((double)(giOverlaySelectNRows - 8) - 1.0)
                                           * (double)(giOverlaySelectMaybeNumUnseen / 9) + 19.0);
  
  this->selectionWindow->DrawWindow(0); 
  
  for(int col = 0; col < NUM_COLS; ++col) {
    for(int row = 0; row < NUM_ROWS; ++row)
     this->overlaySelectBoxes->DrawToBuffer(69 * col, 53 * row, selBoxColorIdx[col][row], 0);
  }
 
  int originalZoom = gpEditManager->zoomLevel;
  int category = this->availOverlays[0].category;
  if(category == OVERLAY_CATEGORY_CREATURE || category == OVERLAY_CATEGORY_ARTIFACT || category == OVERLAY_CATEGORY_TREASURE)
    gpEditManager->zoomLevel = 0;
  for(int i = 0; i + giOverlaySelectMaybeNumUnseen < this->nAvailOverlays && i < NUM_OVERLAYS_ON_SCREEN; ++i) {
    overlay *ovr = &this->availOverlays[i + giOverlaySelectMaybeNumUnseen];
    int col = 69 * (i % NUM_COLS) + 2;
    int row = 53 * (i / NUM_ROWS) + 2;
    int cellOffX = 4;
    int cellOffY = 3;
    if(gpEditManager->zoomLevel == 0) {
      cellOffX = 2;
      cellOffY = 1;
    }
    this->DrawAffectedTileGrid(69 * (i % NUM_ROWS) + 2, row, cellOffX, cellOffY, &this->availOverlays[i] + giOverlaySelectMaybeNumUnseen, 0);
    this->DrawOverlay(ovr, col, row, 0, cellOffX, cellOffY, 0, -1, -1);
  }
  gpEditManager->zoomLevel = originalZoom;
  if(draw)
    gpWindowManager->UpdateScreen();
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
  for(int k = 0; k < gNumOverlays; k++ ) {
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
            nextIconIdx += ovr->field_10 + 1;
            nextOverlayIconIdxStart[tset] += ovr->field_10 + 1;
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

template <typename T> void AddMapExtra(mapCell *tile, T *mapExtra) {
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
        int offset = 835;
        townMapExtra->faction = (idx - offset) % (NUM_ORIG_FACTIONS * 2) / 2;        
        townMapExtra->isCastle = 1
        - ((((unsigned __int64)(idx - offset) >> 32) ^ abs(LOBYTE(idx) - 67) & 1)
        - ((unsigned __int64)(idx - offset) >> 32));

        if(idx >= 971 && idx <= 985) { // ironfist towns go here
            townMapExtra->faction = FACTION_CYBORG;
            townMapExtra->isCastle = true;
            if(idx >= 979)
              townMapExtra->isCastle = false;
        }
    } else {
        townMapExtra->faction = FACTION_MULTIPLE;
        townMapExtra->isCastle = 1
            - ((((unsigned __int64)(idx - 939) >> 32) ^ ((((unsigned __int64)(idx - 939) >> 32) ^ (unsigned __int8)(LOBYTE(idx) + 85)) - ((unsigned __int64)(idx - 939) >> 32)) & 1)
            - ((unsigned __int64)(idx - 939) >> 32));
    }

    return townMapExtra;
}

int __fastcall PlaceOverlay(overlay *ovr, int left, int top, int userDemanded) {
  if (userDemanded) {
      ++giCurOverlayIdx;
  }
    
  if((ovr->locationType == LOCATION_HERO  || ovr->locationType == LOCATION_RANDOM_HERO)
        && CountHeroes(ovr->fullGridIconIndices[47] /7) >= 8) {
            
      sprintf(gText, "Max heroes on map (%d) for color has been reached", 8);
      ShowErrorMessage(gText);
      return 0;
  }


  if (!ValidOverlayPlacement(ovr, left, top, 1)) {
    LogStr("Invalid Placement");
    ShowErrorMessage("Invalid Placement");
    return 0;
  }
  
  UnknownPlaceOverlayHelper(ovr, left, top);

  if (ovr->category == OVERLAY_CATEGORY_TOWN && CountTowns() >= MAX_TOWNS) {
    sprintf(gText, "Max towns on map (%d) has been reached.", MAX_TOWNS);
    ShowErrorMessage(gText);
    return 0;
  }

  if (ovr->locationType == LOCATION_EVENT && CountPlacedEvents() >= MAX_PLACED_EVENTS) {
    sprintf(gText, "Max map events (%d) has been reached.", MAX_PLACED_EVENTS);
    ShowErrorMessage(gText);
    return 0;
  }

  if ((ovr->locationType & 0x7F) == LOCATION_ULTIMATE_ARTIFACT) {
      for (int j = 0; j < MAP_WIDTH; j++) {
          for (int i = 0; i < MAP_WIDTH; i++) {
              if ((gpMap.tiles[gpMap.width * i + j].objType & 0x7F) == LOCATION_ULTIMATE_ARTIFACT) {
                  sprintf(gText, "The ultimate artifact has already been placed.");
                  ShowErrorMessage(gText);
                  return 0;
              }
          }
      }
      
      int right = left + 7;
      int bottom = top + 5;

      if (right < 9 || right >= MAP_WIDTH - 9 || bottom < 9 || bottom >= MAP_HEIGHT - 9) {
          sprintf(gText, "The ultimate artifact must be placed at least 9 squares in from map edge.");
          ShowErrorMessage(gText);
          return 0;
      }
  }
  
  if (CountMines() >= MAX_MINES && 
      (ovr->locationType == LOCATION_ABANDONED_MINE
        || ovr->locationType == LOCATION_MINE
        || ovr->locationType == LOCATION_SAWMILL
        || ovr->locationType == LOCATION_ALCHEMIST_LAB
        || ovr->locationType == 50
        || ovr->locationType == LOCATION_DRAGON_CITY
        || ovr->locationType == LOCATION_LIGHTHOUSE)) {

     sprintf(gText, "Max mines, sawmills and alchemists on map (%d) has been reached.", MAX_MINES);
     ShowErrorMessage(gText);
     return 0;
  }


  if (ovr->category == OVERLAY_CATEGORY_TOWN) {
      int shadowOverlay;

      if (ovr->idx >= 835 && ovr->idx <= 918) {
          shadowOverlay = (ovr->idx - 835) % 12 + 919;
      } else {
        if(ovr->idx >= 971 && ovr->idx <= 977) {
          shadowOverlay = 978;
        } else if(ovr->idx >= 979 && ovr->idx <= 985) {
            shadowOverlay = 986;
        } else 
            // No, I don't know what this means
            shadowOverlay = (((unsigned __int64)(ovr->idx - 939) >> 32) ^ (((unsigned __int8)((unsigned __int64)(ovr->idx - 939) >> 32) ^ (unsigned __int8)(LOBYTE(ovr->idx) + 85))
                                                                  - (unsigned __int8)((unsigned __int64)(ovr->idx - 939) >> 32)) & 1)
                    - ((unsigned __int64)(ovr->idx - 939) >> 32)
                    + 941;
      }

      PlaceOverlay(&gOverlayDatabase[shadowOverlay], left, top, 0);


      int townEntryX = left + 5;
      int townEntryY = top + 5;
      
      int terrainOverlay = 930 + gTileTerrainTypes[gpMap.tiles[townEntryY * gpMap.width + townEntryX].groundIndex];
      PlaceOverlay(&gOverlayDatabase[terrainOverlay], left, top, 0);
  }

  for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 8; j++) {

          if (left + j < 0 || left + j >= MAP_WIDTH) {
              continue;
          }

          if (top + i < 0 || top + i >= MAP_HEIGHT) {
              continue;
          }

          int ovrTileIdx = 8 * i + j;
          mapCell *tile = &gpMap.tiles[(top + i) * gpMap.width + (left + j)];

          if (ovr->fullGridIconIndices[ovrTileIdx] == -1) {
              continue;
          }

          if (OverlayMaskBitSet(&ovr->coveredNonObstructedMask, j, i)) {
              if (tile->overlayIndex == -1) {

                  tile->ovrLink = giCurOverlayIdx;
                  tile->overlayIndex = ovr->fullGridIconIndices[ovrTileIdx];
                  tile->overlayTileset = ovr->tileset;

                  if (i < 4
                        && OverlayMaskBitSet(&ovr->intersectsTileMask, j, i + 1)
                        && (ovr->locationType != LOCATION_ROAD || !OverlayMaskBitSet(&ovr->interactionPointMask, j, i + 1))
                        && !OverlayMaskBitSet(&ovr->shadowsMask, j, i + 1)) {
                      
                      tile->hasLateOverlay = 1;
                  } else {
                      tile->hasLateOverlay = 0;
                  }

                  if (OverlayMaskBitSet(&ovr->animatedLateOverlay, j, i)) {
                      tile->hasOverlay = 1;
                  } else {
                      tile->hasOverlay = 0;
                  }
              } else {
                  mapCellExtra *extra = gpMap.GetNewCellExtraOverlay(left + j, top + i);
                  extra->ovrLink = giCurOverlayIdx;
                  extra->overlayIndex = ovr->fullGridIconIndices[ovrTileIdx];
                  extra->tileset = ovr->tileset;
                  
                  if (i < 4
                        && OverlayMaskBitSet(&ovr->intersectsTileMask, j, i + 1)
                        && (ovr->locationType != LOCATION_ROAD || !OverlayMaskBitSet(&ovr->interactionPointMask, j, i + 1))
                        && !OverlayMaskBitSet(&ovr->shadowsMask, j, i + 1)) {
                      
                      extra->hasLateOverlay = 1;
                  } else {
                      extra->hasLateOverlay = 0;
                  }

                  if (OverlayMaskBitSet(&ovr->animatedLateOverlay, j, i)) {
                      extra->animatedLateOverlay = 1;
                  } else {
                      extra->animatedLateOverlay = 0;
                  }
              }
          } else {
              if (tile->objectIndex != -1
                  && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)
                  && ovr->locationType != LOCATION_MINE) {

                gpMap.MoveInfoToCellExtra(left + j, top + i);
              }

              if (tile->objectIndex == -1) {
                  if (unknownTerrainTileAttribute[tile->groundIndex] & 0x80) {
                      tile->groundIndex = SelectTerrainTile(gTileTerrainTypes[tile->groundIndex],
                          unknownTerrainTileAttribute[tile->groundIndex] - 128, 0, 0, 0, 0, 1.0);
                  }

                  tile->objLink = giCurOverlayIdx;
                  tile->objectIndex = ovr->fullGridIconIndices[ovrTileIdx];
                  tile->objTileset = ovr->tileset;
                  if (OverlayMaskBitSet(&ovr->shadowsMask, j, i)) {
                    tile->objType = 0;
                    tile->isShadow = 1;
                  } else {
                    tile->objType = ovr->locationType;
                    tile->isShadow = 0;
                  }

                  if (i >= 5
                      || ovr->field_4B
                      || OverlayMaskBitSet(&ovr->shadowsMask, j, i)
                      || !OverlayMaskBitSet(&ovr->intersectsTileMask, j, i + 1)
                      || OverlayMaskBitSet(&ovr->shadowsMask, j, i + 1)) {

                      tile->field_4_3 = 0;
                  } else {
                      tile->field_4_3 = 1;
                  }

                  if (ovr->field_4B) {
                      tile->field_4_1 = 1;
                  } else {
                      tile->field_4_1 = 0;
                  }

                  tile->hasObject = OverlayMaskBitSet(&ovr->animatedLateOverlay, j, i);
              } else {
                  mapCellExtra *extra = gpMap.GetNewCellExtraObject(left + j, top + i);
                  extra->objLink = giCurOverlayIdx;
                  extra->objectIndex = ovr->fullGridIconIndices[ovrTileIdx];
                  extra->objTileset = ovr->tileset;
                  extra->field_4_2 = OverlayMaskBitSet(&ovr->shadowsMask, j, i);

                  if (i >= 5
                      || ovr->field_4B
                      || OverlayMaskBitSet(&ovr->shadowsMask, j, i)
                      || !OverlayMaskBitSet(&ovr->intersectsTileMask, j, i + 1)
                      || OverlayMaskBitSet(&ovr->shadowsMask, j, i + 1)) {
                      extra->field_4_3 = 0;
                  } else {
                      extra->field_4_3 = 1;
                  }

                  if (ovr->field_4B) {
                      extra->field_4_1 = 1;
                  } else {
                      extra->field_4_1 = 0;
                  }

                  extra->animatedObject = OverlayMaskBitSet(&ovr->animatedLateOverlay, j, i);
              }
          }

          
          if (OverlayMaskBitSet(&ovr->interactionPointMask, j, i) && ovr->locationType == LOCATION_MINE) {
              tile->objType = LOCATION_MINE;
          }
          
          if (OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              tile->objType |= TILE_HAS_EVENT;
          }

          
          if ( (tile->objType == (TILE_HAS_EVENT|LOCATION_TOWN)
                  || tile->objType == (TILE_HAS_EVENT|LOCATION_RANDOM_TOWN)
                  || tile->objType == (TILE_HAS_EVENT|LOCATION_RANDOM_CASTLE))
              && OverlayMaskBitSet(&ovr->interactionPointMask, j, i) ) {

                  int color = ovr->townColorOrMineColor;
                  int idx = ovr->idx;

                  AddMapExtra(tile, MakeTownExtra(color, idx));
          }

          if ((tile->objType == (TILE_HAS_EVENT|LOCATION_SIGN) || tile->objType == (TILE_HAS_EVENT|LOCATION_BOTTLE))
                  && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
                      
              AddMapExtra(tile, new SignExtra);
          }

          if (tile->objType == (TILE_HAS_EVENT|LOCATION_EVENT) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              AddMapExtra(tile, new EventExtra);
          }
          
          if (tile->objType == (TILE_HAS_EVENT|LOCATION_SPHINX) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              AddMapExtra(tile, new SphinxExtra);
          }
          
          if ((tile->objType == (TILE_HAS_EVENT|LOCATION_RANDOM_HERO) || tile->objType == (TILE_HAS_EVENT|LOCATION_JAIL))
                            && OverlayMaskBitSet(&ovr->interactionPointMask, j, i) ) {
            int faction;
            if (tile->objType == LOCATION_JAIL) {
                faction = 0;
            }
            else {
                faction = GetHeroOverlayFaction(tile->objectIndex);
            }

            AddMapExtra(tile, MakeHeroMapExtra(faction));
          }
          
          if (tile->objType == (TILE_HAS_EVENT|LOCATION_ARTIFACT) && (tile->objectIndex & 0xFE) == 2*ARTIFACT_SPELL_SCROLL) {
              tile->extraInfo = 0;
          }
                          
          if (tile->objType == (TILE_HAS_EVENT|LOCATION_ALCHEMIST_TOWER) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              switch (ovr->idx) {
              case 0x316:
                  tile->extraInfo = 0;
                  break;
              case 0x317:
                  tile->extraInfo = 1;
                  break;
              case 0x31D:
                  tile->extraInfo = 2;
                  break;
              case 0x31E:
                  tile->extraInfo = 3;
                  break;
              case 0x32F:
                  tile->extraInfo = 4;
                  break;
              case 0x331:
                  tile->extraInfo = 5;
                  break;
              case 0x332:
                  tile->extraInfo = 6;
                  break;
              default:
                  break;
              }
          }

          if (tile->objType == (TILE_HAS_EVENT|LOCATION_EXPANSION_DWELLING) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              switch (ovr->idx) {
              case 792:
                  tile->extraInfo = 0;
                  break;
              case 793:
                  tile->extraInfo = 1;
                  break;
              case 794:
                  tile->extraInfo = 1;
                  break;
              case 795:
                  tile->extraInfo = 3;
                  break;
              case 796:
                  tile->extraInfo = 4;
                  break;
              default:
                  break;
              }
          }
          if (tile->objType == (TILE_HAS_EVENT|LOCATION_BARRIER) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              tile->extraInfo = ovr->idx - 799;
          }

          if (tile->objType == (TILE_HAS_EVENT|LOCATION_TRAVELLER_TENT) && OverlayMaskBitSet(&ovr->interactionPointMask, j, i)) {
              tile->extraInfo = ovr->idx - 807;
          }

          if (OverlayMaskBitSet(&ovr->resourceField, j, i)) {
              SetMineResourceIcon(&gOverlayDatabase[ovr->townColorOrMineColor + 128], left + j, top + i, 0);
          }
          
      }
  }
  
  if (ovr->category == OVERLAY_CATEGORY_TOWN) {
      // Flags 

      PlaceOverlay(&gOverlayDatabase[2 * ovr->townColorOrMineColor + 134], left - 3, top - 1, 0);
      PlaceOverlay(&gOverlayDatabase[2 * ovr->townColorOrMineColor + 135], left - 1, top - 1, 0);
  }

  return 1;
}

extern int dword_485D00[];
extern int dword_485D04[];

signed int __stdcall sub_42AAF9(int *x, int *y, int a3, int doMountains, char tileset) {
  if(*x < 0 || *x > MAP_WIDTH - 1 || *y < 0 && *y > MAP_HEIGHT - 1)
    return 0;

  ProcessAssert((unsigned)tileset >= 1, __FILE__, __LINE__);
  int offset = 0;
  switch(a3) {
    case 0: case 4:
      offset = 1;
      break;
    case 1: case 5:
      offset = 3;
      break;
    case 2: case 6:
      offset = 2;
      break;
    case 3: case 7:
      offset = 0;
      break;
  }
    
  overlay *ovr = nullptr;
  for(int i = 0; i < gNumOverlays; ++i) {
    if(!ovr && gOverlayDatabase[i].tileset == tileset) {
      if(((gOverlayDatabase[i].intersectsTileMask & 0xFFFFFFFF00000000) >> 32) == 0xE0F07)
        ovr = &gOverlayDatabase[i + offset];
    }
  }

  if(!sub_4291A2(ovr, *x, *y, 1))
    return 0;

  sub_429170(ovr, *x, *y);
  *x += dword_485D00[2 * a3];
  *y += dword_485D04[2 * a3];
  return 1;
}

int overlayManager::SelectOverlayMain(tag_message &evt) {
  bool rightClick;

  if((*((unsigned char*)&(evt.inputTypeBitmask) + 1)) & 2)
    rightClick = 1;
  else
    rightClick = 0;

  if(evt.eventCode == INPUT_GUI_MESSAGE_CODE && rightClick) {
    std::string str;
    int availOverlayIdx = evt.altXCoord / 69 + giOverlaySelectMaybeNumUnseen + 9 * (evt.altYCoord / 53);
    if(availOverlayIdx < this->nAvailOverlays) {
      overlay *ovr = &this->availOverlays[availOverlayIdx];
      sprintf(gText, overlayNames[ovr->idx].c_str());
      NormalDialog(gText, 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return this->SelectOverlayMain_orig(evt);
}