#ifndef HERO_GLOBALS_H
#define HERO_GLOBALS_H

#include "game/game.h"

// used for setting correct colors and factions for editor placed heroes
FACTION GetHeroOverlayFaction(int overlayObjectIdx);
int GetHeroOverlayColor(int overlayObjectIdx);

#endif