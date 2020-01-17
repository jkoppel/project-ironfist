#ifndef HERO_GLOBALS_H
#define HERO_GLOBALS_H

#include "game/game.h"
#include <vector>

// used for setting correct colors and factions for editor placed heroes
FACTION GetHeroOverlayFaction(int overlayObjectIdx);
int GetHeroOverlayColor(int overlayObjectIdx);
extern std::vector<std::string> heroNames;

#endif