#include "hero_edit.h"

#include "artifacts.h"
#include "editor.h"
#include "gui/gui.h"

extern HeroExtra gEditedHeroExtra;

#define NUM_HERO_PORTRAITS 72

namespace {
  bool shouldFillInArtifacts = true;
}

void __stdcall FillInHeroEdit(HeroExtra *extra) {
  const int ARTIFACT_SLOT_1 = 308;

  if (shouldFillInArtifacts) {
    for (int i = MAX_EXPANSION_ARTIFACT + 1; i < NUM_SUPPORTED_ARTIFACTS; ++i) {
      if (!gArtifactNames[i]) {
        continue;
      }
      for (int j = 0; j < 3; ++j) {
        GUIDroplistAdd(gpCellEditDialog, j + ARTIFACT_SLOT_1, gArtifactNames[i]);
      }
    }
    shouldFillInArtifacts = false;
  }

  FillInHeroEdit_orig(extra);
}

int __fastcall EditHeroHandler(tag_message& evt) {
  const int NEXT_HERO_PORTRAIT_BUTTON = 704;
  if (evt.eventCode == INPUT_GUI_MESSAGE_CODE && evt.yCoordOrFieldID == NEXT_HERO_PORTRAIT_BUTTON) {
    if (gEditedHeroExtra.field_11) {
      if (gEditedHeroExtra.heroID < NUM_HERO_PORTRAITS - 1)
        ++gEditedHeroExtra.heroID;
    } else {
      gEditedHeroExtra.field_11 = 1;
      gEditedHeroExtra.heroID = 0;
    }

    FillInHeroEdit(&gEditedHeroExtra);
    gpCellEditDialog->DrawWindow();

    return 1;
  } else {
    return EditHeroHandler_orig(evt);
  }
}

void RequestUserDefinedArtifacts() {
  shouldFillInArtifacts = true;
}