#include "hero_edit.h"

#include "artifacts.h"
#include "editor.h"
#include "combat/creatures.h"
#include "gui/gui.h"
#include "town/town_globals.h"

extern HeroExtra gEditedHeroExtra;

#define NUM_HERO_PORTRAITS 73

namespace {
  const int ARTIFACT_DROPDOWN_1 = 308;
  const int CREATURE_DROPDOWN_1 = 220;

  bool shouldFillInArtifacts = true;
  bool shouldFillInCreatures = true;

  std::string Capitalize(const char *name) {
    if (!name) {
      return {};
    }

    std::string properName(name);
    if (!properName.empty()) {
      properName[0] -= 32;  // this is how the game code does it
    }
    return properName;
  }
}

extern "C" int gbModifyingJailedHero;

void __stdcall FillInHeroEdit(HeroExtra *extra) {
  if (shouldFillInArtifacts) {
    for (int i = MAX_EXPANSION_ARTIFACT + 1; i < NUM_SUPPORTED_ARTIFACTS; ++i) {
      if (!IsArtifactValid(i)) {
        continue;
      }
      for (int j = 0; j < 3; ++j) {
        GUIDroplistAdd(gpCellEditDialog, j + ARTIFACT_DROPDOWN_1, GetArtifactName(i));
      }
    }
    shouldFillInArtifacts = false;
  }

  if (shouldFillInCreatures) {
    for (int i = MAX_BASE_CREATURE + 1; i < GetNumCreatures(); ++i) {
      std::string name = Capitalize(GetCreatureName(i));
      if (name.empty()) {
        continue;
      }
      for (int j = 0; j < 5; ++j) {
        GUIDroplistAdd(gpCellEditDialog, j + CREATURE_DROPDOWN_1, name);
      }
    }
    shouldFillInCreatures = false;
  }


  if(gbModifyingJailedHero) {
    for(int i = 0; i < FACTIONS_ACTUAL_NAMES.size(); i++)
      GUIDroplistClear(gpCellEditDialog, 803);
    for(int i = 0; i < FACTIONS_ACTUAL_NAMES.size(); i++) {
      sprintf(gText, FACTIONS_ACTUAL_NAMES[i].c_str());
      GUIDroplistAdd(gpCellEditDialog, 803, gText);
    }
  }

  if(extra->hasArmy)
    GUIAddFlag(gpCellEditDialog, 206, 4);
  else
    GUIRemoveFlag(gpCellEditDialog, 206, 4);

  if(extra->hasArmy)
    GUIRemoveFlag(gpCellEditDialog, 204, 4);
  else
    GUIAddFlag(gpCellEditDialog, 204, 4);

  for(int i = 210; i <= 239; ++i) {
    if(extra->hasArmy)
      GUIAddFlag(gpCellEditDialog, i, 4);
    else
      GUIRemoveFlag(gpCellEditDialog, i, 4);
  }

  if(gbModifyingJailedHero) {
    GUIAddFlag(gpCellEditDialog, 803, 4);
  } else {
    if(extra->relatedToJailCondition)
      GUIAddFlag(gpCellEditDialog, 803, 4);
    else
      GUIRemoveFlag(gpCellEditDialog, 803, 4);
  }

  if(gbModifyingJailedHero) {
    GUIRemoveFlag(gpCellEditDialog, 802, 4);
    GUIRemoveFlag(gpCellEditDialog, 801, 4);
  } else {
    if(extra->relatedToJailCondition)
      GUIAddFlag(gpCellEditDialog, 802, 4);
    else
      GUIRemoveFlag(gpCellEditDialog, 802, 4);
  }

  for(int i = 0; i < CREATURES_IN_ARMY; ++i) {
    sprintf(gText, "%d", extra->army.quantities[i]);
    GUISetText(gpCellEditDialog, 230 + i, gText);
    GUISetDropdownSelection(gpCellEditDialog, 220 + i, extra->army.creatureTypes[i] + 1);
  }

  for(int i = 0; i < 3; ++i) {
    char artifact = extra->artifacts[i] + 1;
    if(extra->artifacts[i] >= 82)
      artifact -= 5;
    GUISetDropdownSelection(gpCellEditDialog, 308 + i, artifact);
  }

  if(gbModifyingJailedHero) {
    int dropdownIndex;
    auto it = std::find(FACTIONS_ACTUAL.begin(), FACTIONS_ACTUAL.end(), extra->factionID);
    if(it == FACTIONS_ACTUAL.end()) {
      extra->factionID = 0;
      dropdownIndex = extra->factionID;
    } else
      dropdownIndex = std::distance(FACTIONS_ACTUAL.begin(), it);
    GUISetDropdownSelection(gpCellEditDialog, 803, dropdownIndex);
  } else {
    GUISetDropdownSelection(gpCellEditDialog, 803, extra->factionID);
  }

  sprintf(gText, "%d", extra->experience);
  GUISetText(gpCellEditDialog, 401, gText);

  if(extra->hasSecondarySkills)
    GUIAddFlag(gpCellEditDialog, 506, 4);
  else
    GUIRemoveFlag(gpCellEditDialog, 506, 4);

  if(extra->hasSecondarySkills)
    GUIRemoveFlag(gpCellEditDialog, 504, 4);
  else
    GUIAddFlag(gpCellEditDialog, 504, 4);

  for(int i = 510; i <= 529; ++i) {
    if(extra->hasSecondarySkills)
      GUIAddFlag(gpCellEditDialog, i, 4);
    else
      GUIRemoveFlag(gpCellEditDialog, i, 4);
  }

  for(int i = 0; i < MAX_SECONDARY_SKILLS; ++i) {
    int index;
    if(extra->secondarySkills[i] == -1)
      index = 0;
    else
      index = extra->secondarySkills[i] + 14 * (extra->secondarySkillLevel[i] - 1) + 1;
    GUISetDropdownSelection(gpCellEditDialog, 520 + i, index);
  }

  if(extra->hasName)
    GUIAddFlag(gpCellEditDialog, 606, 4);
  else
    GUIRemoveFlag(gpCellEditDialog, 606, 4);

  if(extra->hasName)
    GUIRemoveFlag(gpCellEditDialog, 604, 4);
  else
    GUIAddFlag(gpCellEditDialog, 604, 4);

  if(extra->hasName)
    GUIAddFlag(gpCellEditDialog, 607, 4);
  else
    GUIRemoveFlag(gpCellEditDialog, 607, 4);

  sprintf(gText, "%s", &extra->name);
  GUISetText(gpCellEditDialog, 607, gText);

  int imgIdx;
  if(extra->customPortrait)
    imgIdx = extra->heroID + 1;
  else
    imgIdx = 0;
  GUISetImgIdx(gpCellEditDialog, 702, imgIdx);

  for (int i = 0; i < 5; ++i) {
    // skip one for "~empty~"
    int creatureIndex = extra->army.creatureTypes[i] + 1;
    if (creatureIndex > MAX_BASE_CREATURE + 1) {
      // The slots for random creatures between the base game and Ironfist
      // creatures are not included in the creature dropdown.
      creatureIndex -= MIN_IRONFIST_CREATURE - MAX_BASE_CREATURE - 1;
    }
    GUISetDropdownSelection(gpCellEditDialog, CREATURE_DROPDOWN_1 + i, creatureIndex);
  }
}

int __fastcall EditHeroHandler(tag_message& evt) {
  const int NEXT_HERO_PORTRAIT_BUTTON = 704;
  const int JAIL_FACTION_DROPLIST_ITEM = 803;
  if (evt.eventCode == INPUT_GUI_MESSAGE_CODE) {
    if (evt.yCoordOrFieldID == NEXT_HERO_PORTRAIT_BUTTON) {
      if (gEditedHeroExtra.customPortrait) {
        if (gEditedHeroExtra.heroID < NUM_HERO_PORTRAITS - 1)
          ++gEditedHeroExtra.heroID;
      } else {
        gEditedHeroExtra.customPortrait = true;
        gEditedHeroExtra.heroID = 0;
      }

      FillInHeroEdit(&gEditedHeroExtra);
      gpCellEditDialog->DrawWindow();

      return 1;
    } else if (evt.yCoordOrFieldID >= CREATURE_DROPDOWN_1 && evt.yCoordOrFieldID < CREATURE_DROPDOWN_1 + 5) {
      // Subtract 1 to account for "~empty~" in index 0.
      int creatureSelection = GUIGetDropdownSelection(gpCellEditDialog, evt.yCoordOrFieldID) - 1;
      const int armyIndex = evt.yCoordOrFieldID - CREATURE_DROPDOWN_1;
      // The slots for random creatures between the base game and Ironfist
      // creatures are not included in the creature dropdown.
      if (creatureSelection > MAX_BASE_CREATURE) {
        creatureSelection += MIN_IRONFIST_CREATURE - MAX_BASE_CREATURE - 1;
      }
      gEditedHeroExtra.army.creatureTypes[armyIndex] = creatureSelection;

      FillInHeroEdit(&gEditedHeroExtra);
      gpCellEditDialog->DrawWindow();
      return 1;
    } else if(evt.yCoordOrFieldID == JAIL_FACTION_DROPLIST_ITEM && gbModifyingJailedHero) {
      int selectedItem = GUIGetDropdownSelection(gpCellEditDialog, JAIL_FACTION_DROPLIST_ITEM);
      gEditedHeroExtra.factionID = FACTIONS_ACTUAL[selectedItem];

      FillInHeroEdit(&gEditedHeroExtra);
      gpCellEditDialog->DrawWindow();
      return 1;
    }
    else {
      return EditHeroHandler_orig(evt);
    }
  } else {
    return EditHeroHandler_orig(evt);
  }
}

void EditHero_RequestUserDefinedElements() {
  shouldFillInArtifacts = true;
  shouldFillInCreatures = true;
}