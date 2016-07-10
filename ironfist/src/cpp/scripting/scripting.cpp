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
#include "adventure/map.h";
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "town/town.h"


#include "scripting/hook.h"
#include "scripting/register.h"
#include "scripting/scripting.h"
#include "scripting/temporary_file.h"

using namespace std;

static string script_contents("");

static bool scripting_on = false;
static lua_State* map_lua = NULL;
static map<pair<int, string>, const char* > *triggers;
static map<int, const char* > *general_triggers;

static int triggerFiredCount[NUM_SCRIPT_EVENTS]; // Note: reset every game session

void SetGeneralHook(int id, const char* hook) {
  (*general_triggers)[id] = hook;
}

const char* GetGeneralHook(int id) {
  if (general_triggers->count(id) > 0) {
    return (*general_triggers)[id];
  } else {
    return NULL;
  }
}

void SetHook(int id, const char* obj, const char* hook) {
  (*triggers)[make_pair(id, string(obj))] = hook;
}

const char* GetHook(int id, const char* obj) {
  if (triggers->count(make_pair(id, obj)) > 0)
    return (*triggers)[make_pair(id, string(obj))];
  else
    return NULL;
}

static void CallHook(const char* hook) {
  if (hook != NULL) {
    lua_getglobal(map_lua, hook);

    if (lua_pcall(map_lua, 0, -1, 0)) {
      DisplayError();
    }
  }

}

static bool MaxTriggerFiringReached(int id) {
  // I've observed map victory events firing twice in a row. I haven't ruled out that this is also possible for map loss
  // Because we're only worried about it firing twice in a row, we need not worry about tracking this count across sessions
  if (id == SCRIPT_EVT_MAP_VICTORY || id == SCRIPT_EVT_MAP_LOSS) {
    return triggerFiredCount[id] > 0;
  } else {
    return false;
  }
}

void ScriptSignal(int id, const char* obj) {
  if (!scripting_on) {
    return;
  }

  if (MaxTriggerFiringReached(id)) {
    return;
  }

  triggerFiredCount[id]++;
  CallHook(GetHook(id, obj));
  CallHook(GetGeneralHook(id));
}

void ScriptSignal(int id, const string& obj) {
  const char* x = obj.c_str();
  ScriptSignal(id, x);
}

void ScriptSetSpecialVariableData(const char* nam, void* val) {
  if (!scripting_on) {
    return;
  }

  lua_pushlightuserdata(map_lua, val);
  lua_setglobal(map_lua, nam);
}

int l_msgbox(lua_State *L) {
  const char* msg = luaL_checkstring(L, 1);
  H2MessageBox((char*)msg);
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
  hero* hro = (hero*)lua_touserdata(L, 1);
  int creature = (int)luaL_checknumber(L, 2);
  short quantity = (short)luaL_checknumber(L, 3);
  short startQ = quantity;
  gpAdvManager->ExpansionRecruitEvent(hro, creature, &quantity);

  lua_pushinteger(L, startQ - quantity);
  return 1;
}

int l_trigger(lua_State *L) {
  int id = (int)luaL_checknumber(L, 1);
  const char* obj = lua_tolstring(L, 2, NULL); // string or NULL
  const char* hook = luaL_checkstring(L, 3);

  if (obj == NULL) {
    SetGeneralHook(id, hook);
  }
  else {
    SetHook(id, obj, hook);
  }

  return 0;
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
  lua_pushlightuserdata(L, GetCurrentHero());
  return 1;
}

int l_grantspell(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int sp = (int)luaL_checknumber(L, 2);
  hro->AddSpell(sp);
  return 0;
}

int l_forgetSpell(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  int spell = (int)luaL_checknumber(L, 2);
  hro->spellsLearned[spell] = 0;
  return 0;
}

int l_hasTroop(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
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
  hero *hro = (hero*)lua_touserdata(L, 1);
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
  hero *hro = (hero*)lua_touserdata(L, 1);
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
  lua_pushlightuserdata(L, &gpGame->players[n]);
  return 1;
}

int l_getCurrentPlayer(lua_State *L) {
  lua_pushlightuserdata(L, gpCurPlayer);
  return 1;
}

int l_getnumheroes(lua_State *L) {
  playerData* p = (playerData*)lua_touserdata(L, 1);
  lua_pushinteger(L, p->numHeroes);
  return 1;
}

int l_gethero(lua_State *L) {
  playerData* p = (playerData*)lua_touserdata(L, 1);
  int n = (int)luaL_checknumber(L, 2);
  lua_pushlightuserdata(L, &gpGame->heroes[p->heroesOwned[n]]);
  return 1;
}

int l_getheroforhire(lua_State *L) {
  playerData* p = (playerData*)lua_touserdata(L, 1);
  int n = (int)luaL_checknumber(L, 2);
  lua_pushlightuserdata(L, &gpGame->heroes[p->heroesForPurchase[n]]);
  return 1;
}

int l_teleportHero(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  int x = (int)luaL_checknumber(L, 2);
  int y = (int)luaL_checknumber(L, 3);
  gpAdvManager->TeleportTo(hro, x, y, 0, 0);
  return 0;
}

int l_getHeroName(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  lua_pushstring(L, hro->name);
  return 1;
}

int l_setHeroName(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  strncpy(hro->name, luaL_checkstring(L, 2), ELEMENTS_IN(hro->name));
  return 0;
}

int l_giveResource(lua_State *L) {
  playerData *player = (playerData*)lua_touserdata(L, 1);
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] += val;
  return 0;
}

int l_setResource(lua_State *L) {
  playerData *player = (playerData*)lua_touserdata(L, 1);
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] = val;
  return 0;
}

int l_getResource(lua_State *L) {
  playerData *player = (playerData*)lua_touserdata(L, 1);
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


int l_getheroinpool(lua_State *L) {
  int n = (int)luaL_checknumber(L, 1);
  lua_pushlightuserdata(L, &gpGame->heroes[n]);
  return 1;
}

int l_getheroowner(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  lua_pushinteger(L, hro->ownerIdx);
  return 1;
}

int l_grantartifact(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int art = (int)luaL_checknumber(L, 2);
  GiveArtifact(hro, art, 1, -1);
  return 0;
}

int l_hasartifact(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int art = (int)luaL_checknumber(L, 2);
  lua_pushboolean(L, hro->HasArtifact(art));
  return 1;
}

int l_takeartifact(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int art = (int)luaL_checknumber(L, 2);
  hro->TakeArtifact(art);
  return 0;
}

int l_setprimaryskill(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int skill = (int)luaL_checknumber(L, 2);
  int amt = (int)luaL_checknumber(L, 3);
  hro->SetPrimarySkill(skill, amt);
  return 0;
}

int l_getPrimarySkill(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->primarySkills[skill]);
  return 1;
}

int l_setspellpoints(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int points = (int)luaL_checknumber(L, 2);
  hro->spellpoints = points;
  return 0;
}

int l_getSpellpoints(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  lua_pushinteger(L, hro->spellpoints);
  return 1;
}

int l_setsecondaryskill(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int skill = (int)luaL_checknumber(L, 2);
  int level = (int)luaL_checknumber(L, 3);
  hro->SetSS(skill, level);
  return 0;
}

int l_getSecondarySkill(lua_State *L) {
  hero *hro = (hero*)lua_touserdata(L, 1);
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->GetSSLevel(skill));
  return 1;
}

int l_grantarmy(lua_State *L) {
  hero* hro = (hero*)lua_touserdata(L, 1);
  int cr = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  hro->army.Add(cr, n, -1);
  return 0;
}

int l_getcurrenttown(lua_State *L) {
  lua_pushlightuserdata(L, gpTownManager->castle);
  return 1;
}


int l_hasvisitinghero(lua_State *L) {
  town* twn = (town*)lua_touserdata(L, 1);
  lua_pushboolean(L, twn->visitingHeroIdx >= 0);
  return 1;
}

int l_getvisitinghero(lua_State *L) {
  town* twn = (town*)lua_touserdata(L, 1);
  lua_pushlightuserdata(L, &gpGame->heroes[twn->visitingHeroIdx]);
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
    lua_pushlightuserdata(L, &gpGame->castles[index]);
  }
  return 1;
}

int l_getTownByName(lua_State *L) {
  char *name = (char*)luaL_checkstring(L, 1);
  for (int i = 0; i < MAX_TOWNS; i++) {
    if (strcmp(gpGame->castles[i].name, name) == 0) {
      lua_pushlightuserdata(L, &gpGame->castles[i]);
      return 1;
    }
  }
  lua_pushinteger(L, -1);
  return 1;
}

int l_getPlayerTown(lua_State *L) {
  playerData *player = (playerData*)lua_touserdata(L, 1);
  int index = (int)luaL_checknumber(L, 2);

  if (index < MAX_TOWNS) {
    lua_pushlightuserdata(L, &gpGame->castles[player->castlesOwned[index]]);
  }

  return 1;
}

int l_buildInTown(lua_State *L) {
  town *twn = (town*)lua_touserdata(L, 1);
  int building = (int)luaL_checknumber(L, 2);
  twn->BuildBuilding(building);
  return 0;
}

int l_getTownFaction(lua_State *L) {
  town *twn = (town*)lua_touserdata(L, 1);
  lua_pushinteger(L, twn->factionID);
  return 1;
}

int l_setTownFaction(lua_State *L) {
  town *twn = (town*)lua_touserdata(L, 1);
  int faction = (int)luaL_checknumber(L, 2);
  twn->factionID = (char)faction;
  return 0;
}


int l_setnumguildspells(lua_State *L) {
  town* twn = (town*)lua_touserdata(L, 1);
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  twn->SetNumSpellsOfLevel(l, n);
  twn->GiveSpells(NULL);
  return 0;
}

int l_setguildspell(lua_State *L) {
  town* twn = (town*)lua_touserdata(L, 1);
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
  lua_pushlightuserdata(L, gpCombatManager->heroes[side]);
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
  lua_pushlightuserdata(L, &gpCombatManager->creatures[side][idx]);
  return 1;
}

int l_getStackSide(lua_State *L) {
  army *creat = (army*)lua_touserdata(L, 1);
  lua_pushinteger(L, creat->owningSide);
  return 1;
}

int l_getStackType(lua_State *L) {
  army *creat = (army*)lua_touserdata(L, 1);
  lua_pushinteger(L, creat->creatureIdx);
  return 1;
}

int l_getStackQuantity(lua_State *L) {
  army *creat = (army*)lua_touserdata(L, 1);
  lua_pushinteger(L, creat->quantity);
  return 1;
}

int l_getStackHex(lua_State *L) {
  army *creat = (army*)lua_touserdata(L, 1);
  lua_pushinteger(L, creat->occupiedHex);
  return 1;
}

int l_sharevision(lua_State *L) {
  int sourcePlayer = (int)luaL_checknumber(L, 1);
  int destPlayer = (int)luaL_checknumber(L, 2);
  gpGame->ShareVision(sourcePlayer, destPlayer);
  return 0;
}

int l_setDaysAfterTownLost(lua_State *L)
{
  playerData *player = (playerData*)lua_touserdata(L, 1);
  int days = (int)luaL_checknumber(L, 2);
  player->daysLeftWithoutCastle = days;
  return 0;
}
int l_getherolevel(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	lua_pushinteger(L, hro->GetLevel());
	return 1;
}

void set_lua_globals(lua_State *L) {
  lua_register(L, "MessageBox", l_msgbox);
  lua_register(L, "Trigger", l_trigger);
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

  // Tales of Enroth functions
  lua_register(L, "QuestionBox", l_questionBox);
  lua_register(L, "InputBox", l_inputBox);
  lua_register(L, "RecruitBox", l_recruitBox);
  lua_register(L, "SetDaysAfterTownLost", l_setDaysAfterTownLost);

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
  lua_register(L, "GetStackType", l_getStackType);
  lua_register(L, "GetStackHex", l_getStackHex);

  lua_register(L, "GetTown", l_getTown);
  lua_register(L, "GetTownByName", l_getTownByName);
  lua_register(L, "GetPlayerTown", l_getPlayerTown);
  lua_register(L, "BuildInTown", l_buildInTown);
  lua_register(L, "GetTownFaction", l_getTownFaction);
  lua_register(L, "SetTownFaction", l_setTownFaction);

  lua_register(L, "MapSetObject", l_mapSetObject);

  lua_register(L, "GetCurrentPlayer", l_getCurrentPlayer);
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

  lua_setconst(L, "NEW_DAY", SCRIPT_EVT_NEW_DAY);
  lua_setconst(L, "MAP_START", SCRIPT_EVT_MAP_START);
  lua_setconst(L, "TOWN_LOADED", SCRIPT_EVT_TOWN_LOADED);
  lua_setconst(L, "HERO_MOVE", SCRIPT_EVT_MOVEHERO);
  lua_setconst(L, "UNIT_RECRUIT", SCRIPT_EVT_RECRUIT);
  lua_setconst(L, "BATTLE_START", SCRIPT_EVT_BATTLE_START);
  lua_setconst(L, "BATTLE_ATTACK_MELEE", SCRIPT_EVT_BATTLE_ATTACK_M);
  lua_setconst(L, "MAP_VICTORY", SCRIPT_EVT_MAP_VICTORY);
  lua_setconst(L, "MAP_LOSS", SCRIPT_EVT_MAP_LOSS);

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
  triggers = new map<pair<int, string>, const char* >;
  general_triggers = new map<int, const char* >;
  scripting_on = true;

  for (int i = 0; i < ELEMENTS_IN(triggerFiredCount); i++) {
    triggerFiredCount[i] = 0;
  }

  luaL_openlibs(map_lua);

  set_lua_globals(map_lua);

  LoadScriptContents(script_filename);

  if (luaL_dofile(map_lua, script_filename.c_str())) {
    DisplayError();
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
}

void ScriptingShutdown() {
  if (map_lua != NULL) {
    lua_close(map_lua);
    map_lua = NULL;
    delete triggers;
    delete general_triggers;
    scripting_on = false;
  }

  script_contents = "";
}

// Returns "" if none
string& GetScriptContents() {
  return script_contents;
}

void GetNextMapVariable(int &key, const char *&mapVariableId, const char *&mapVariableValue) {
  // PUSH THE MAP VARIABLES LIST TO THE TOP OF THE STACK OR nil IF THERE IS NO LIST
  lua_getglobal(map_lua, "mapVariables");

  // CHECK IF THERE IS INDEED A LIST OF MAP VARIABLES
  if (lua_isnil(map_lua, -1)) {
    mapVariableId = "noMapVariables";
    return;
  }

  // GO TO THE mapVariable INDEXED BY key
  if (key >= 0) {
    lua_pushnumber(map_lua, key);
  }
  else {
    lua_pushnil(map_lua);
  }
  if (lua_next(map_lua, -2)) {
    key = lua_tointeger(map_lua, -2);
    mapVariableId = lua_tostring(map_lua, -1);
    lua_pop(map_lua, 2);
    lua_getglobal(map_lua, mapVariableId);
    mapVariableValue = lua_tostring(map_lua, -1);
  }
  else {
    mapVariableId = "noMapVariables";
  }
}

void SetMapVariables(const char *id, const char *quantity) {
  lua_pushstring(map_lua, quantity);
  lua_setglobal(map_lua, id);
}

void DisplayError() {
  const char* msg = luaL_checkstring(map_lua, -1);
  DisplayError(msg, "Script Error");
}
