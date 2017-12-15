//#include "base.h"

#include "adventure/map.h"

#include "editor.h"
#include "gui/msg.h"

extern HeroExtra gEditedHeroExtra;

extern int __fastcall EditHeroHandler_orig(tag_message&);
extern void __stdcall FillInHeroEdit(HeroExtra*);

#define NUM_HERO_PORTRAITS 72

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