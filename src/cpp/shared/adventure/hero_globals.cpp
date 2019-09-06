#include "hero_globals.h"
#include <map>

std::map<int, FACTION> heroOverlayFactions = {
  {0, FACTION_KNIGHT}, {7, FACTION_KNIGHT}, {14, FACTION_KNIGHT}, {21, FACTION_KNIGHT}, {28, FACTION_KNIGHT}, {35, FACTION_KNIGHT}, 
  {1, FACTION_BARBARIAN}, {8, FACTION_BARBARIAN}, {15, FACTION_BARBARIAN}, {22, FACTION_BARBARIAN}, {29, FACTION_BARBARIAN}, {36, FACTION_BARBARIAN},
  {2, FACTION_SORCERESS}, {9, FACTION_SORCERESS}, {16, FACTION_SORCERESS}, {23, FACTION_SORCERESS}, {30, FACTION_SORCERESS}, {37, FACTION_SORCERESS},
  {3, FACTION_WARLOCK},   {10, FACTION_WARLOCK}, {17, FACTION_WARLOCK}, {24, FACTION_WARLOCK}, {31, FACTION_WARLOCK}, {38, FACTION_WARLOCK},
  {4, FACTION_WIZARD}, {11, FACTION_WIZARD}, {18, FACTION_WIZARD}, {25, FACTION_WIZARD}, {32, FACTION_WIZARD}, {39, FACTION_WIZARD},
  {5, FACTION_NECROMANCER}, {12, FACTION_NECROMANCER}, {19, FACTION_NECROMANCER}, {26, FACTION_NECROMANCER}, {33, FACTION_NECROMANCER}, {40, FACTION_NECROMANCER},
  {6, FACTION_MULTIPLE}, {13, FACTION_MULTIPLE}, {20, FACTION_MULTIPLE}, {27, FACTION_MULTIPLE}, {34, FACTION_MULTIPLE}, {41, FACTION_MULTIPLE},
  {42, FACTION_CYBORG}, {43, FACTION_CYBORG}, {44, FACTION_CYBORG}, {45, FACTION_CYBORG}, {46, FACTION_CYBORG}, {47, FACTION_CYBORG}
};

// objectIndex / color
std::map<int, int> heroOverlayColors = {
  {0, 0}, {7, 1}, {14, 2}, {21, 3}, {28, 4}, {35, 5}, 
  {1, 0}, {8, 1}, {15, 2}, {22, 3}, {29, 4}, {36, 5},
  {2, 0}, {9, 1}, {16, 2}, {23, 3}, {30, 4}, {37, 5},
  {3, 0}, {10, 1}, {17, 2}, {24, 3}, {31, 4}, {38, 5},
  {4, 0}, {11, 1}, {18, 2}, {25, 3}, {32, 4}, {39, 5},
  {5, 0}, {12, 1}, {19, 2}, {26, 3}, {33, 4}, {40, 5},
  {6, 0}, {13, 1}, {20, 2}, {27, 3}, {34, 4}, {41, 5},
  {42, 0}, {43, 1}, {44, 2}, {45, 3}, {46, 4}, {47, 5}
};

FACTION GetHeroOverlayFaction(int overlayObjectIdx) {
  return heroOverlayFactions[overlayObjectIdx];
}

int GetHeroOverlayColor(int overlayObjectIdx) {
  return heroOverlayColors[overlayObjectIdx];
}

std::vector<std::string> heroNames = {
  "Lord Kilburn",
  "Sir Gallant",
  "Ector",
  "Gwenneth",
  "Tyro",
  "Ambrose",
  "Ruby",
  "Maximus",
  "Dimitri",
  "Thundax",
  "Fineous",
  "Jojosh",
  "Crag Hack",
  "Jezebel",
  "Jaclyn",
  "Ergon",
  "Tsabu",
  "Atlas",
  "Astra",
  "Natasha",
  "Troyan",
  "Vatawna",
  "Rebecca",
  "Gem",
  "Ariel",
  "Carlawn",
  "Luna",
  "Arie",
  "Alamar",
  "Vesper",
  "Crodo",
  "Barok",
  "Kastore",
  "Agar",
  "Falagar",
  "Wrathmont",
  "Myra",
  "Flint",
  "Dawn",
  "Halon",
  "Myrini",
  "Wilfrey",
  "Sarakin",
  "Kalindra",
  "Mandigal",
  "Zom",
  "Darlana",
  "Zam",
  "Ranloo",
  "Charity",
  "Rialdo",
  "Roxana",
  "Sandro",
  "Celia",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "Lord Varuun",
  "John Carver"
};