#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

#include<fstream>
#include<map>
#include<sstream>
#include<string>
#include<utility>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "town/town.h"


#include "scripting/register.h"
#include "scripting/scripting.h"
#include "scripting/temporary_file.h"

using namespace std;

static string script_contents("");

static bool scripting_on = false;
lua_State* map_lua = NULL;

static void DisplayLuaError() {
	const char* msg = luaL_checkstring(map_lua, -1);
	DisplayError(msg, "Script Error");
}

int StackIndexOfArg(int argNumber, int numArgs) {
  return (numArgs - (argNumber - 1));
}

void MakeLuaHeroTable(lua_State *L, void *ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr);
  lua_settable(L, -3);
  lua_getglobal(L, "hero_mt");
  lua_setmetatable(L,-2);
}

void MakeLuaTownTable(lua_State *L, void *ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr);
  lua_settable(L, -3);
  lua_getglobal(L, "town_mt");
  lua_setmetatable(L,-2);
}

void MakeLuaPlayerTable(lua_State *L, void *ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr);
  lua_settable(L, -3);
  lua_getglobal(L, "player_mt");
  lua_setmetatable(L,-2);
}

void MakeLuaBattleStackTable(lua_State *L, void *ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr);
  lua_settable(L, -3);
  lua_getglobal(L, "battleStack_mt");
  lua_setmetatable(L,-2);
}

void* GetPointerFromLuaClassTable(lua_State *L, int stackIndex) {
  lua_pushstring(L, "ptr");
  lua_gettable(L, -1-stackIndex);
  void* ret = (void*)(int)lua_tonumber(L, -1);
  lua_pop(L, 1);
  return ret;
}

int l_msgbox(lua_State *L) {
  const char* msg = luaL_checkstring(L, 1);
  H2MessageBox((char*)msg);
  return 0;
}

int l_AdvancedMessageBox(lua_State *L) {
	const char* msg = luaL_checkstring(L, 1);
	int yesno = luaL_checkinteger(L, 2);
	int horizontal = luaL_checkinteger(L, 3);
	int vertical = luaL_checknumber(L, 4);
	int img1type = luaL_checknumber(L, 5);
	int img1arg = luaL_checknumber(L, 6);
	int img2type = luaL_checknumber(L, 7);
	int img2arg = luaL_checknumber(L, 8);
	int writeOr = luaL_checknumber(L, 9);
	int a10 = luaL_checknumber(L, 10);
	NormalDialog((char*)msg, (int)yesno, (int)horizontal, (int)vertical, (int)img1type, (int)img1arg, (int)img2type, (int)img2arg,(int)writeOr, (int)a10);
	return 0; 
}

int l_questionBox(lua_State *L) {
  char* qst = (char*)luaL_checkstring(L, 1);
  lua_pushboolean(L, H2QuestionBox(qst));
  return 1;
}

int l_inputBox(lua_State *L) {
  char* qst = (char*)luaL_checkstring(L, 1);
  int len = (int)luaL_checknumber(L, 2);
  char* input = H2InputBox(qst, len);
  lua_pushstring(L, input);
  FREE(input); // pushstring copies it
  return 1;
}

int l_recruitBox(lua_State *L)
{
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  short quantity = (short)luaL_checknumber(L, 3);
  short startQ = quantity;
  gpAdvManager->ExpansionRecruitEvent(hro, creature, &quantity);

  lua_pushinteger(L, startQ - quantity);
  return 1;
}

int l_getday(lua_State *L) {
  lua_pushinteger(L, gpGame->day);
  return 1;
}

int l_getweek(lua_State *L) {
  lua_pushinteger(L, gpGame->week);
  return 1;
}

int l_getmonth(lua_State *L) {
  lua_pushinteger(L, gpGame->month);
  return 1;
}

int l_getcurrenthero(lua_State *L) {
  MakeLuaHeroTable(L, GetCurrentHero());
  return 1;
}

int l_grantspell(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int sp = (int)luaL_checknumber(L, 2);
  hro->AddSpell(sp);
  return 0;
}

int l_forgetSpell(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int spell = (int)luaL_checknumber(L, 2);
  hro->spellsLearned[spell] = 0;
  return 0;
}

int l_hasTroop(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  int quantity = (int)luaL_checknumber(L, 3);
  for (int i = 0; i < CREATURES_IN_ARMY; i++) {
    if (hro->army.creatureTypes[i] && hro->army.creatureTypes[i] == creature && hro->army.quantities[i] >= quantity) {
      lua_pushboolean(L, true);
      return 1;
    }
  }
  lua_pushboolean(L, false);
  return 1;
}

int l_getCreatureAmount(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int creature = (int)luaL_checknumber(L, 2);
  int quantity = 0;

  for (int i = 0; i < CREATURES_IN_ARMY; i++) {
    if (hro->army.creatureTypes[i] == creature) {
      quantity += hro->army.quantities[i];
    }
  }

  lua_pushinteger(L, quantity);
  return 1;
}

int l_takeTroop(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  int quantity = (int)luaL_checknumber(L, 3);

  for (int i = 0; i < CREATURES_IN_ARMY; i++) {
    if (hro->army.creatureTypes[i] == creature) {
      if (hro->army.quantities[i] > quantity) {
        hro->army.quantities[i] -= quantity;
        break;
      } else if (hro->army.quantities[i] <= quantity) {
        quantity -= hro->army.quantities[i];
        hro->army.creatureTypes[i] = -1;
        hro->army.quantities[i] = 0;
      }
    }
  }
  return 0;
}

int l_getplayer(lua_State *L) {
  int n = (int)luaL_checknumber(L, 1);
  MakeLuaPlayerTable(L, &gpGame->players[n]);
  return 1;
}

int l_getCurrentPlayer(lua_State *L) {
  MakeLuaPlayerTable(L, gpCurPlayer);
  return 1;
}

int l_getPlayerColor(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, p->color);
  return 1;
}

int l_getnumheroes(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, p->numHeroes);
  return 1;
}

int l_gethero(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int n = (int)luaL_checknumber(L, 2);
  MakeLuaHeroTable(L, &gpGame->heroes[p->heroesOwned[n]]);
  return 1;
}

int l_getheroforhire(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int n = (int)luaL_checknumber(L, 2);
  MakeLuaHeroTable(L, &gpGame->heroes[p->heroesForPurchase[n]]);
  return 1;
}

int l_teleportHero(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int x = (int)luaL_checknumber(L, 2);
  int y = (int)luaL_checknumber(L, 3);
  gpAdvManager->TeleportTo(hro, x, y, 0, 0);
  return 0;
}

int l_getHeroName(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushstring(L, hro->name);
  return 1;
}

int l_setHeroName(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  lua_pushstring(L, hro->name);
  strncpy(hro->name, luaL_checkstring(L, 2), ELEMENTS_IN(hro->name));
  return 0;
}

int l_giveResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] += val;
  return 0;
}

int l_setResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] = val;
  return 0;
}

int l_getResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int res = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, player->resources[res]);
  return 1;
}

// FIXME: What is this 3?
int l_mapSetObject(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  int obj = (int)luaL_checknumber(L, 3);

  mapCell* cell = gpAdvManager->GetCell(x, y);
  cell->overlayIndex = 3;
  cell->objectIndex = obj;
  cell->objType = obj & 0x7F;
  return 0;
}

int l_mapPutArmy(lua_State *L) {
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	int monIdx = (int)luaL_checknumber(L, 3);
	int monQty = (int)luaL_checknumber(L, 4);

	lua_pushinteger(L, gpAdvManager->MapPutArmy(x, y, monIdx, monQty));
	return 1;
}

int l_getheroinpool(lua_State *L) {
  int n = (int)luaL_checknumber(L, 1);
  MakeLuaHeroTable(L, &gpGame->heroes[n]);
  return 1;
}

int l_getheroowner(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->ownerIdx);
  return 1;
}

int l_grantartifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  GiveArtifact(hro, art, 1, -1);
  return 0;
}

int l_hasartifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  lua_pushboolean(L, hro->HasArtifact(art));
  return 1;
}

int l_takeartifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  hro->TakeArtifact(art);
  return 0;
}

int l_countemptyartifactslots(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->CountEmptyArtifactSlots());
  return 1; 
}

int l_countemptycreatureslots(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
	lua_pushinteger(L, hro->CountEmptyCreatureSlots());
	return 1;
}

int l_setprimaryskill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int skill = (int)luaL_checknumber(L, 2);
  int amt = (int)luaL_checknumber(L, 3);
  hro->SetPrimarySkill(skill, amt);
  return 0;
}

int l_getPrimarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->primarySkills[skill]);
  return 1;
}

int l_setspellpoints(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int points = (int)luaL_checknumber(L, 2);
  hro->spellpoints = points;
  return 0;
}

int l_getSpellpoints(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->spellpoints);
  return 1;
}

int l_setsecondaryskill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int skill = (int)luaL_checknumber(L, 2);
  int level = (int)luaL_checknumber(L, 3);
  hro->SetSS(skill, level);
  return 0;
}

int l_getSecondarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->GetSSLevel(skill));
  return 1;
}

int l_grantarmy(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int cr = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  hro->army.Add(cr, n, -1);
  return 0;
}

int l_getcurrenttown(lua_State *L) {
  MakeLuaTownTable(L, gpTownManager->castle);
  return 1;
}


int l_hasvisitinghero(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushboolean(L, twn->visitingHeroIdx >= 0);
  return 1;
}

int l_getvisitinghero(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  MakeLuaHeroTable(L, &gpGame->heroes[twn->visitingHeroIdx]);
  return 1;
}

int l_buildincurrenttown(lua_State *L) {
  int obj = (int)luaL_checknumber(L, 1);
  gpTownManager->BuildObj(obj);
  return 0;
}

int l_getTown(lua_State *L) {
  int index = (int)luaL_checknumber(L, 1);
  if (index < MAX_TOWNS) {
    MakeLuaTownTable(L, &gpGame->castles[index]);
  }
  return 1;
}

int l_getTownName(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushstring(L, twn->name);
  return 1;
}

int l_setTownName(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  strcpy(twn->name, luaL_checkstring(L, 2));
  return 1;
}

int l_getTownByName(lua_State *L) {
  char *name = (char*)luaL_checkstring(L, 1);
  for (int i = 0; i < MAX_TOWNS; i++) {
    if (strcmp(gpGame->castles[i].name, name) == 0) {
      MakeLuaTownTable(L, &gpGame->castles[i]);
      return 1;
    }
  }
  lua_pushinteger(L, -1);
  return 1;
}

int l_getPlayerTown(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int index = (int)luaL_checknumber(L, 2);

  if (index < MAX_TOWNS) {
    MakeLuaTownTable(L, &gpGame->castles[player->castlesOwned[index]]);
  }
  return 1;
}

int l_buildInTown(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int building = (int)luaL_checknumber(L, 2);
  twn->BuildBuilding(building);
  return 0;
}

int l_getTownFaction(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->factionID);
  return 1;
}

int l_setTownFaction(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int faction = (int)luaL_checknumber(L, 2);
  twn->factionID = (char)faction;
  return 0;
}


int l_setnumguildspells(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  twn->SetNumSpellsOfLevel(l, n);
  twn->GiveSpells(NULL);
  return 0;
}

int l_setguildspell(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 4));
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  int s = (int)luaL_checknumber(L, 4);
  twn->mageGuildSpells[l][n] = s;
  twn->GiveSpells(NULL);
  return 0;
}

int l_getCreatureCost(lua_State *L) {
  int creature = (int)luaL_checknumber(L, 1);
  int cost[NUM_RESOURCES];
  GetMonsterCost(creature, cost);
  for (int i = 0; i < NUM_RESOURCES; i++) {
    lua_pushinteger(L, cost[i]);
  }
  return 7;
}

// FIXME: DraggonFantasy's version used getFirstEmptyHex. That was more useful
int l_battleSummonCreature(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  int hex = (int)luaL_checknumber(L, 2);
  int creature = (int)luaL_checknumber(L, 3);
  int quantity = (int)luaL_checknumber(L, 4);

  gpCombatManager->AddArmy(side, creature, quantity, hex, 0, 1);
  return 0;
}

int l_isHexEmpty(lua_State *L) {
  int hexno = (int)luaL_checknumber(L, 1);
  if (!ValidHex(hexno)) {
    lua_pushboolean(L, 0);
  } else {
    hexcell *cell = &gpCombatManager->combatGrid[hexno];
    lua_pushboolean(L, cell->unitOwner == -1 && !cell->isBlocked);
  }

  return 1;
}

int l_battleHasHero(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  lua_pushboolean(L, gpCombatManager->heroes[side] != NULL);
  return 1;
}

int l_battleGetHero(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  MakeLuaHeroTable(L, gpCombatManager->heroes[side]);
  return 1;
}

int l_battleMessage(lua_State *L) {
  char* message = (char*)luaL_checkstring(L, 1);
  gpCombatManager->CombatMessage(message);
  return 0;
}

int l_battleGetNumStacks(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  lua_pushinteger(L, gpCombatManager->numCreatures[side]);
  return 1;
}

int l_battleGetStack(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  int idx = (int)luaL_checknumber(L, 2);
  MakeLuaBattleStackTable(L, &gpCombatManager->creatures[side][idx]);
  return 1;
}

int l_getStackSide(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->owningSide);
  return 1;
}

int l_getStackType(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creatureIdx);
  return 1;
}

int l_getStackQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->quantity);
  return 1;
}

int l_setStackQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int quantity = (int)luaL_checknumber(L, 2);
  creat->quantity = quantity;
  return 0;
}

int l_getStackInitialQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->initialQuantity);
  return 1;
}

int l_setStackInitialQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int initialQuantity = (int)luaL_checknumber(L, 2);
  creat->initialQuantity = initialQuantity;
  return 0;
}

int l_getStackHex(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->occupiedHex);
  return 1;
}

int l_getStackMorale(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->morale);
  return 1;
}

int l_setStackMorale(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int morale = (int)luaL_checknumber(L, 2);
  creat->morale = morale;
  return 0;
}

int l_getStackLuck(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->luck);
  return 1;
}

int l_setStackLuck(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int luck = (int)luaL_checknumber(L, 2);
  creat->luck = luck;
  return 0;
}

int l_sharevision(lua_State *L) {
  int sourcePlayer = (int)luaL_checknumber(L, 1);
  int destPlayer = (int)luaL_checknumber(L, 2);
  gpGame->ShareVision(sourcePlayer, destPlayer);
  return 0;
}

int l_setDaysAfterTownLost(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int days = (int)luaL_checknumber(L, 2);
  player->daysLeftWithoutCastle = days;
  return 0;
}

int l_getDaysAfterTownLost(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, player->daysLeftWithoutCastle);
  return 1;
}

int l_getherolevel(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->GetLevel());
	return 1;
}

int l_getHeroTempMoraleBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->tempMoraleBonuses);
  return 1;
}

int l_setHeroTempMoraleBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int moraleBonus = (int)luaL_checknumber(L, 2);
  hro->tempMoraleBonuses = moraleBonus;
  return 0;
}

int l_getHeroTempLuckBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->tempLuckBonuses);
  return 1;
}

int l_setHeroTempLuckBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int LuckBonus = (int)luaL_checknumber(L, 2);
  hro->tempLuckBonuses = LuckBonus;
  return 0;
}

int l_getHeroMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->mobility);
  return 1;
}

int l_setHeroMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int mobility = (int)luaL_checknumber(L, 2);
  hro->mobility = mobility;
  return 0;
}

int l_getHeroRemainingMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->remainingMobility);
  return 1;
}

int l_setHeroRemainingMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int remainingMobility = (int)luaL_checknumber(L, 2);
  hro->remainingMobility = remainingMobility;
  return 0;
}

int l_getHeroX(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->x);
  return 1;
}

int l_getHeroY(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->y);
  return 1;
}

int l_startbattle(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 4));
	int mon1 = (int)luaL_checknumber(L, 2);
	int mon1quantity = (int)luaL_checknumber(L, 3);
	int switchSides = (int)luaL_checknumber(L, 4);
	mapCell* mapcell = gpAdvManager->GetCell(hro->x, hro->y);
	int winningSide = gpAdvManager->CombatMonsterEvent(hro, mon1, mon1quantity, mapcell, hro->x, hro->y, switchSides, hro->x, hro->y, -1, 0, 0, -1, 0, 0);
	lua_pushinteger(L, winningSide);
	return 1;
}

int l_toggleAIArmySharing(lua_State *L) {
	bool toggle = luaL_checknumber(L, 1);
	gpGame->allowAIArmySharing = toggle;
	return 0;
}

int l_getTownOwner(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->ownerIdx);
  return 1;
}

int l_setTownOwner(lua_State *L) {
  int townIdx = (int)luaL_checknumber(L, 1);
  int playerIdx = (int)luaL_checknumber(L, 2);
  gpGame->ClaimTown(townIdx, playerIdx, 0);
  return 0;
}

int l_getTownX(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->x);
  return 1;
}

int l_getTownY(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->y);
  return 1;
}

int l_getTownIDFromPos(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, gpGame->GetTownId(x, y));
  return 1;
}

int l_revealMap(lua_State *L) {
	playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 4));
	int x = (int)luaL_checknumber(L, 2);
	int y = (int)luaL_checknumber(L, 3);
	int radius = (int)luaL_checknumber(L, 4);

	for (int i = 0; i < gpGame->numPlayers; i++) {
		if (&gpGame->players[i] == player) {
			gpGame->SetVisibility(x, y, i, radius);
			break;
		}
	}
	return 1;
}

int l_getguildspell(lua_State *L) {
	town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
	int l = (int)luaL_checknumber(L, 2);
	int n = (int)luaL_checknumber(L, 3);
	int s = twn->mageGuildSpells[l][n];
	lua_pushinteger(L, s);
	return 1;
}

void set_lua_globals(lua_State *L) {
  lua_register(L, "MessageBox", l_msgbox);
  lua_register(L, "AdvancedMessageBox", l_AdvancedMessageBox);
  lua_register(L, "GetDay", l_getday);
  lua_register(L, "GetWeek", l_getweek);
  lua_register(L, "GetMonth", l_getmonth);
  lua_register(L, "GetCurrentHero", l_getcurrenthero);
  lua_register(L, "GetPlayer", l_getplayer);
  lua_register(L, "GetNumHeroes", l_getnumheroes);
  lua_register(L, "GetHero", l_gethero);
  lua_register(L, "GetHeroForHire", l_getheroforhire);
  lua_register(L, "GetHeroInPool", l_getheroinpool);
  lua_register(L, "GetHeroOwner", l_getheroowner);
  lua_register(L, "GrantArtifact", l_grantartifact);
  lua_register(L, "GrantSpell", l_grantspell);
  lua_register(L, "GrantArmy", l_grantarmy);
  lua_register(L, "HasArtifact", l_hasartifact);
  lua_register(L, "TakeArtifact", l_takeartifact);
  lua_register(L, "SetPrimarySkill", l_setprimaryskill);
  lua_register(L, "SetSpellpoints", l_setspellpoints);
  lua_register(L, "SetSecondarySkill", l_setsecondaryskill);
  lua_register(L, "GetCurrentTown", l_getcurrenttown);
  lua_register(L, "HasVisitingHero", l_hasvisitinghero);
  lua_register(L, "GetVisitingHero", l_getvisitinghero);
  lua_register(L, "BuildInCurrentTown", l_buildincurrenttown);
  lua_register(L, "SetNumGuildSpells", l_setnumguildspells);
  lua_register(L, "SetGuildSpell", l_setguildspell);
  lua_register(L, "ShareVision", l_sharevision);
  lua_register(L, "GetHeroLevel", l_getherolevel);
  lua_register(L, "GetHeroTempMoraleBonuses", l_getHeroTempMoraleBonuses);
  lua_register(L, "SetHeroTempMoraleBonuses", l_setHeroTempMoraleBonuses);
  lua_register(L, "GetHeroTempLuckBonuses", l_getHeroTempLuckBonuses);
  lua_register(L, "SetHeroTempLuckBonuses", l_setHeroTempLuckBonuses);
  lua_register(L, "GetHeroMobility", l_getHeroMobility);
  lua_register(L, "SetHeroMobility", l_setHeroMobility);
  lua_register(L, "GetHeroRemainingMobility", l_getHeroRemainingMobility);
  lua_register(L, "SetHeroRemainingMobility", l_setHeroRemainingMobility);
  lua_register(L, "GetHeroX", l_getHeroX);
  lua_register(L, "GetHeroY", l_getHeroY);
  lua_register(L, "StartBattle", l_startbattle);
  lua_register(L, "CountEmptyArtifactSlots", l_countemptyartifactslots);
  lua_register(L, "CountEmptyCreatureSlots", l_countemptycreatureslots);
	
  // Tales of Enroth functions
  lua_register(L, "QuestionBox", l_questionBox);
  lua_register(L, "InputBox", l_inputBox);
  lua_register(L, "RecruitBox", l_recruitBox);
  lua_register(L, "SetDaysAfterTownLost", l_setDaysAfterTownLost);
  lua_register(L, "GetDaysAfterTownLost", l_getDaysAfterTownLost);

  lua_register(L, "GiveResource", l_giveResource);
  lua_register(L, "SetResource", l_setResource);
  lua_register(L, "GetResource", l_getResource);
  lua_register(L, "GetCreatureCost", l_getCreatureCost);

  lua_register(L, "BattleSummonCreature", l_battleSummonCreature);
  lua_register(L, "IsHexEmpty", l_isHexEmpty);
  lua_register(L, "BattleHasHero", l_battleHasHero);
  lua_register(L, "BattleGetHero", l_battleGetHero);
  lua_register(L, "BattleMessage", l_battleMessage);

  lua_register(L, "BattleNumStacksForSide", l_battleGetNumStacks);
  lua_register(L, "BattleGetStack", l_battleGetStack);
  lua_register(L, "GetStackSide", l_getStackSide);
  lua_register(L, "GetStackQuantity", l_getStackQuantity);
  lua_register(L, "SetStackQuantity", l_setStackQuantity);
  lua_register(L, "GetStackInitialQuantity", l_getStackInitialQuantity);
  lua_register(L, "SetStackInitialQuantity", l_setStackInitialQuantity);
  lua_register(L, "GetStackType", l_getStackType);
  lua_register(L, "GetStackHex", l_getStackHex);
  lua_register(L, "GetStackMorale", l_getStackMorale);
  lua_register(L, "SetStackMorale", l_setStackMorale);
  lua_register(L, "GetStackLuck", l_getStackLuck);
  lua_register(L, "SetStackLuck", l_setStackLuck);

  lua_register(L, "GetTown", l_getTown);
  lua_register(L, "GetTownName", l_getTownName);
  lua_register(L, "SetTownName", l_setTownName);
  lua_register(L, "GetTownByName", l_getTownByName);
  lua_register(L, "GetPlayerTown", l_getPlayerTown);
  lua_register(L, "BuildInTown", l_buildInTown);
  lua_register(L, "GetTownFaction", l_getTownFaction);
  lua_register(L, "SetTownFaction", l_setTownFaction);

  lua_register(L, "MapSetObject", l_mapSetObject);
  lua_register(L, "MapPutArmy", l_mapPutArmy);

  lua_register(L, "GetCurrentPlayer", l_getCurrentPlayer);
  lua_register(L, "GetPlayerColor", l_getPlayerColor);
  lua_register(L, "TeleportHero", l_teleportHero);
  lua_register(L, "GetHeroName", l_getHeroName);
  lua_register(L, "SetHeroName", l_setHeroName);
  lua_register(L, "ForgetSpell", l_forgetSpell);
  lua_register(L, "HasTroop", l_hasTroop);
  lua_register(L, "GetCreatureAmount", l_getCreatureAmount);
  lua_register(L, "TakeTroop", l_takeTroop);
  lua_register(L, "GetPrimarySkill", l_getPrimarySkill);
  lua_register(L, "GetSpellpoints", l_getSpellpoints);
  lua_register(L, "GetSecondarySkill", l_getSecondarySkill);

  lua_register(L, "ToggleAIArmySharing", l_toggleAIArmySharing);

  lua_register(L, "GetTownOwner", l_getTownOwner);
  lua_register(L, "SetTownOwner", l_setTownOwner);
  lua_register(L, "GetTownX", l_getTownX);
  lua_register(L, "GetTownY", l_getTownY);
  lua_register(L, "GetTownIdFromPos", l_getTownIDFromPos);

  lua_register(L, "RevealMap", l_revealMap);

  set_scripting_consts(L);
}

static void LoadScriptContents(string &filnam) {
  ifstream in(filnam);
  stringstream buffer;
  buffer << in.rdbuf();
  script_contents = buffer.str();
}

void RunScript(string& script_filename) {
  map_lua = luaL_newstate();
  scripting_on = true;

  luaL_openlibs(map_lua);

  set_lua_globals(map_lua);

  if (luaL_dofile(map_lua, ".\\SCRIPTS\\MODULES\\binding.lua")) {
    DisplayLuaError();
  }

  LoadScriptContents(script_filename);

  if (luaL_dofile(map_lua, script_filename.c_str())) {
    DisplayLuaError();
  }
}

void ScriptingInit(string& map_filnam) {
  ScriptingShutdown();

  string script_file = ".\\SCRIPTS\\" + map_filnam + ".lua";
  struct stat st;

  if (stat(script_file.c_str(), &st) == 0) { //script exists
    RunScript(script_file);
  }
}

void ScriptingInitFromString(string &script) {
  string filename = dumpToTemp(string(script));
  RunScript(filename);
  remove(filename.c_str());
}

void ScriptingShutdown() {
  if (map_lua != NULL) {
    lua_close(map_lua);
    map_lua = NULL;
    scripting_on = false;
  }

  script_contents = "";
}

// Returns "" if none
string& GetScriptContents() {
  return script_contents;
}

void ErrorMapVariable(std::string& mapVariableId, const std::string& s2, const std::string& addErrorMessage) {
	const std::string s1("MapVariable '");
	const std::string errorMessage = s1 + mapVariableId + s2 + addErrorMessage;
	const std::string errorLabel("mapVariable Error");
	DisplayError(errorMessage, errorLabel);
}

void ErrorSavingMapVariable(std::string& mapVariableId, const std::string& addErrorMessage) {
	const std::string s2("' could not be saved properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

void ErrorLoadingMapVariable(std::string& mapVariableId, const std::string& addErrorMessage) {
	const std::string s2("' could not be loaded properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

bool isTable(MapVarType type) {
	return (type == MAPVAR_TYPE_TABLE);
}

bool isStringNumBool(MapVarType type) {
	return (type == MAPVAR_TYPE_STRING || type == MAPVAR_TYPE_NUMBER || type == MAPVAR_TYPE_BOOLEAN);
}

MapVarType StringToMapVarType(std::string stringType) {
	if (stringType == "string") {
		return MAPVAR_TYPE_STRING;
	} else if (stringType == "number") {
		return MAPVAR_TYPE_NUMBER;
	} else if (stringType == "boolean") {
		return MAPVAR_TYPE_BOOLEAN;
	} else if (stringType == "table") {
		return MAPVAR_TYPE_TABLE;
	} else {
		return MAPVAR_TYPE_ERROR;
	}
}

static std::string getMVKeyFromLUA() {
	MapVarType type = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -2)));
	if (type == MAPVAR_TYPE_STRING) {
		std::string stringValue(lua_tostring(map_lua, -2));
		return stringValue;
	} else if (type == MAPVAR_TYPE_NUMBER) {
		return std::to_string(lua_tonumber(map_lua, -2));
	}
}

static std::string GetMVValueFromLUA(MapVarType &type) {
	if (type == MAPVAR_TYPE_STRING) {
		std::string stringValue(lua_tostring(map_lua, -1));
		return stringValue;
	} else if (type == MAPVAR_TYPE_NUMBER) {
		return std::to_string(lua_tonumber(map_lua, -1));
	} else if (type == MAPVAR_TYPE_BOOLEAN) {
		return std::to_string(lua_toboolean(map_lua, -1));
	}
}

static luaTable *GetMVTablesFromLUA(std::string &mapVariableId) {
	luaTable *lt = new luaTable;
	lua_pushnil(map_lua);
	while (lua_next(map_lua, -2) != 0) {
		std::string key = getMVKeyFromLUA();
		mapVariable *mapVar = new mapVariable;
		MapVarType valueType = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -1)));
		mapVar->type = valueType;
		if (isStringNumBool(valueType)) {
			std::string *sV = new std::string(GetMVValueFromLUA(valueType));
			mapVar->singleValue = sV;
			(*lt)[key] = *mapVar;
			lua_pop(map_lua, 1);
		} else if (isTable(valueType)) {
			mapVar->tableValue = GetMVTablesFromLUA(key);
			(*lt)[key] = *mapVar;
		} else {
			ErrorSavingMapVariable(mapVariableId, " Wrong type in the table.");
		}
	}
	lua_pop(map_lua, 1);
	return lt;
}

std::map<std::string, mapVariable> LoadMapVariablesFromLUA() {

	std::map<std::string, mapVariable> mapVariables;

    if (!scripting_on) {
      return mapVariables;
    }

	lua_getglobal(map_lua, "mapVariables");

	if (lua_isnil(map_lua, -1)) return mapVariables;

	lua_pushnil(map_lua);
	while (lua_next(map_lua, -2) != 0) {
		std::string mapVariableId(lua_tostring(map_lua, -1));
		lua_getglobal(map_lua, mapVariableId.c_str());
		MapVarType mapVariableType = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -1)));
		mapVariable *mapVar = new mapVariable;
		mapVar->type = mapVariableType;
		if (isTable(mapVariableType)) {
			mapVar->tableValue = GetMVTablesFromLUA(mapVariableId);
		} else if (isStringNumBool(mapVariableType)) {
			std::string *sV = new std::string;
			*sV = GetMVValueFromLUA(mapVariableType);
			mapVar->singleValue = sV;
			lua_pop(map_lua, 1);
		} else {
			ErrorSavingMapVariable(mapVariableId, " A map variable can only be a table, number, string or boolean.");
		}
		lua_pop(map_lua, 1);
		mapVariables[mapVariableId] = *mapVar;
	}
	return mapVariables;
}

static void PushStringNumBoolToLUA(MapVarType type, std::string value) {
	if (type == MAPVAR_TYPE_STRING) {
		lua_pushstring(map_lua, value.c_str());
	} else if (type == MAPVAR_TYPE_NUMBER) {
		lua_pushnumber(map_lua, atof(value.c_str()));
	} else if (type == MAPVAR_TYPE_BOOLEAN) {
		lua_pushboolean(map_lua, atoi(value.c_str()));
	}
}

static void PushTableToLUA(luaTable *lt) {
	lua_newtable(map_lua);
	int top = lua_gettop(map_lua);
	for (luaTable::const_iterator it = (*lt).begin(); it != (*lt).end(); ++it) {
		if (it->second.type == MAPVAR_TYPE_TABLE) {
			lua_pushstring(map_lua, it->first.c_str());
			PushTableToLUA(it->second.tableValue);
			lua_settable(map_lua, top);
		} else {
			lua_pushstring(map_lua, it->first.c_str());
			PushStringNumBoolToLUA(it->second.type, *it->second.singleValue);
			lua_settable(map_lua, top);
		}
	}
}

void WriteMapVariablesToLUA(std::map<std::string, mapVariable> &mapVariables) {
    if (!scripting_on) {
      DisplayError("Warning: Map variables detected in map without a script.", "Ironfist bug detected");
      return;
    }

	for (std::map<std::string, mapVariable>::const_iterator it = mapVariables.begin(); it != mapVariables.end(); ++it) {
		if (isTable(it->second.type)) {
			PushTableToLUA(it->second.tableValue);
			lua_setglobal(map_lua, it->first.c_str());
		} else {
			PushStringNumBoolToLUA(it->second.type, *it->second.singleValue);
			lua_setglobal(map_lua, it->first.c_str());
		}
	}
}
