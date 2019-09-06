#include<stdio.h>

#include "base.h"

#include "adventure/adv.h"
#include "adventure/map.h"
#include "game/game.h"
#include "gui/dialog.h"

extern char *xBarrierColor[];
extern char *xPasswordStrings[];

int GetBarrierColor(int cellExtraInfo) {
    return cellExtraInfo & 7;
}

char* GetBarrierPassword(int cellExtraInfo) {
    return xPasswordStrings[cellExtraInfo >> 3];
}

void advManager::PasswordEvent(mapCell *cell, hero *hero) {
    SAMPLE2 res = NULL_SAMPLE2;
    int barrierColor = GetBarrierColor(cell->extraInfo);
    this->EventSound(cell->objType & 0x7F, barrierColor, &res);
    sprintf(gText,"You enter the tent and find an old woman staring into a glowing gem. "
                   "\"I have learned much in the way of scrying. Let me share a secret.\" "
                   "With that, she leans into your ear and whispers the keyword for the %s border guard",
                   xBarrierColor[barrierColor]);
    H2MessageBox(gText);
    gpCurPlayer->barrierTentsVisited |= 1 << barrierColor;
}


void playerData::SetBarrierTentVisited(int color) {	
	this->barrierTentsVisited |= (1 << color);
}
 
int advManager::BarrierEvent(mapCell *cell, hero *hero) {
    SAMPLE2 res = NULL_SAMPLE2;
    int barrierColor = GetBarrierColor(cell->extraInfo);
    char *password = GetBarrierPassword(cell->extraInfo);
    sprintf(
        gText,
        "A magical %s barrier stands tall before you, blocking your way.  Runes on the arch read, \"Speak the key and you may pass.\"",
        xBarrierColor[barrierColor]);
    H2MessageBox(gText);

    if (gpCurPlayer->barrierTentsVisited & (1 << barrierColor)) {
        this->EventSound(cell->objType & 0x7F, barrierColor, &res);
        sprintf(gText, "As you speak the magic word \"%s\", the glowing barrier dissolves into nothingness.", password);
        H2MessageBox(gText);
        return 1;
    } else {
        H2MessageBox("You try guessing in vein, but nothing happens.");
        return 0;
		
    }
	 
}

