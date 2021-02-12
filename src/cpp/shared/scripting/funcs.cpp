extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "adventure/adv.h"
#include "adventure/map.h"
#include "campaign/campaign.h"
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "town/town.h"
#include "artifacts.h"

#include "scripting/deepbinding.h"
#include "scripting/register.h"

#include "sound/sound.h"

enum SoundEffectWait { SND_DO_WAIT, SND_DONT_WAIT };

static bool PlaySoundEffect(std::string snd, SoundEffectWait wait, SAMPLE2* samp) {
	SAMPLE2 res = NULL_SAMPLE2;
	if (!snd.empty()) {
		char* src;
		snd += ".82m";
		src = strdup(snd.c_str());
		res = LoadPlaySample(src);
		if (samp != NULL) {
			memcpy(samp, &res, sizeof(SAMPLE2));
		}
		if (wait == SND_DO_WAIT) {
			WaitEndSample(res, res.sample);
		}
		free(src);
		return true;
	}
	return false;
}

static bool CheckLocationItem(mapCell *loc) {
	if (!(loc->objType&TILE_HAS_EVENT)) {
		return false;
	}
	switch (loc->objType^TILE_HAS_EVENT) {
		case LOCATION_ANCIENT_LAMP:
		case LOCATION_ARTIFACT:
		case LOCATION_RESOURCE:
		case LOCATION_CAMPFIRE:
		case LOCATION_TREASURE_CHEST:
		case LOCATION_SHIPWRECK_SURVIVOR:
		case LOCATION_FLOTSAM:
		case LOCATION_SEA_CHEST:
			return true;
	}
	return false;
}

static bool CheckBoolean(lua_State *L, int pos) {
	if (lua_isboolean(L, pos)) {
		return lua_toboolean(L, pos);
	}
	const char *msg = lua_pushfstring(L, "%s expected, got %s", lua_typename(L, LUA_TBOOLEAN), luaL_typename(L, pos));
	luaL_argerror(L, pos, msg);
	return false;
}

static int StackIndexOfArg(int argNumber, int numArgs) {
	return (numArgs - (argNumber - 1));
}

/************************************************ Dialogs ********************************************************/

static int l_msgBox(lua_State *L) {
  const char* msg = luaL_checkstring(L, 1);
  H2MessageBox((char*)msg);
  return 0;
}

extern int gbFunctionComplete;

static int l_AdvancedMessageBox(lua_State *L) {
  const char* msg = luaL_checkstring(L, 1);
  int dialogType = luaL_checkinteger(L, 2);
  int horizontal = luaL_checkinteger(L, 3);
  int vertical = luaL_checknumber(L, 4);
  int img1type = luaL_checknumber(L, 5);
  int img1arg = luaL_checknumber(L, 6);
  int img2type = luaL_checknumber(L, 7);
  int img2arg = luaL_checknumber(L, 8);
  int writeOr = luaL_checknumber(L, 9);
  int a10 = luaL_checknumber(L, 10);
  
  std::string msgCopy = msg;
  NormalDialog(&msgCopy[0], dialogType, horizontal, vertical, img1type, img1arg, img2type, img2arg, writeOr, a10);
 
  if (dialogType == DIALOG_LEARN_CHOICE) { // learn dialog
    lua_pushboolean(L, gpWindowManager->buttonPressedCode == BUTTON_CODE_LEARN_LEFT);
  } else if (dialogType == DIALOG_CANCEL_ALT) {
    lua_pushboolean(L, gbFunctionComplete);
  } else if (dialogType == DIALOG_YES_NO) {
    lua_pushboolean(L, gpWindowManager->buttonPressedCode == BUTTON_CODE_OKAY);
  } else {
    lua_pushboolean(L, true);
  }
  
  return 1;
}

static int l_questionBox(lua_State *L) {
  char* qst = (char*)luaL_checkstring(L, 1);
  lua_pushboolean(L, H2QuestionBox(qst));
  return 1;
}

static int l_inputBox(lua_State *L) {
  char* qst = (char*)luaL_checkstring(L, 1);
  int len = (int)luaL_checknumber(L, 2);
  char* input = H2InputBox(qst, len);
  lua_pushstring(L, input);
  FREE(input); // pushstring copies it
  return 1;
}

static int l_recruitBox(lua_State *L)
{
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  short quantity = (short)luaL_checknumber(L, 3);
  short startQ = quantity;
  gpAdvManager->ExpansionRecruitEvent(hro, creature, &quantity);

  lua_pushinteger(L, startQ - quantity);
  return 1;
} 

static void register_dialog_funcs(lua_State *L) {
  lua_register(L, "MessageBox", l_msgBox);
  lua_register(L, "AdvancedMessageBox", l_AdvancedMessageBox);
  lua_register(L, "QuestionBox", l_questionBox);
  lua_register(L, "InputBox", l_inputBox);
  lua_register(L, "RecruitBox", l_recruitBox);
}

/************************************************ Date ********************************************************/

static int l_getDay(lua_State *L) {
  lua_pushinteger(L, gpGame->day);
  return 1;
}

static int l_getWeek(lua_State *L) {
  lua_pushinteger(L, gpGame->week);
  return 1;
}

static int l_getMonth(lua_State *L) {
  lua_pushinteger(L, gpGame->month);
  return 1;
}

static void register_date_funcs(lua_State *L) {
  lua_register(L, "GetDay", l_getDay);
  lua_register(L, "GetWeek", l_getWeek);
  lua_register(L, "GetMonth", l_getMonth);
}

/************************************************ Player ********************************************************/

static int l_getNumPlayers(lua_State *L) {
	lua_pushinteger(L, gpGame->numPlayers);
	return 1;
}

static int l_getPlayer(lua_State *L) {
  int n = (int)luaL_checknumber(L, 1);
  deepbound_push(L, deepbind<playerData*>(&gpGame->players[n]));
  return 1;
}

static int l_getCurrentPlayer(lua_State *L) {
  deepbound_push(L, deepbind<playerData*>(gpCurPlayer));
  return 1;
}

static int l_getPlayerColor(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, p->color);
  return 1;
}

static int l_getNumHeroes(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, p->numHeroes);
  return 1;
}

static int l_getHero(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int n = (int)luaL_checknumber(L, 2);
  deepbound_push(L, deepbind<hero*>(&gpGame->heroes[p->heroesOwned[n]]));
  return 1;
}

static int l_getHeroForHire(lua_State *L) {
  playerData* p = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int n = (int)luaL_checknumber(L, 2);
  deepbound_push(L, deepbind<hero*>(&gpGame->heroes[p->heroesForPurchase[n]]));
  return 1;
}

static int l_giveResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] += val;
  return 0;
}

static int l_setResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int res = (int)luaL_checknumber(L, 2);
  int val = (int)luaL_checknumber(L, 3);
  player->resources[res] = val;
  return 0;
}

static int l_getResource(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int res = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, player->resources[res]);
  return 1;
}

static int l_shareVision(lua_State *L) {
  int sourcePlayer = (int)luaL_checknumber(L, 1);
  int destPlayer = (int)luaL_checknumber(L, 2);
  gpGame->ShareVision(sourcePlayer, destPlayer);
  return 0;
}

static int l_cancelShareVision(lua_State *L) {
  int sourcePlayer = (int)luaL_checknumber(L, 1);
  int destPlayer = (int)luaL_checknumber(L, 2);
  gpGame->CancelShareVision(sourcePlayer, destPlayer);
  return 0;
}

static int l_setDaysAfterTownLost(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int days = (int)luaL_checknumber(L, 2);
  player->daysLeftWithoutCastle = days;
  return 0;
}

static int l_getDaysAfterTownLost(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, player->daysLeftWithoutCastle);
  return 1;
}

static int l_revealMap(lua_State *L) {
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

int l_SetBarrierTentVisited(lua_State *L) {
	playerData* plyd = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
	int tentcolor = luaL_checknumber(L, 2);
	plyd->SetBarrierTentVisited(tentcolor);

	return 0;
}

static void register_player_funcs(lua_State *L) {
  lua_register(L, "GetNumPlayers", l_getNumPlayers);
  lua_register(L, "GetPlayer", l_getPlayer);
  lua_register(L, "GetCurrentPlayer", l_getCurrentPlayer);
  lua_register(L, "GetPlayerColor", l_getPlayerColor);
  lua_register(L, "GetNumHeroes", l_getNumHeroes);
  lua_register(L, "GetHero", l_getHero);
  lua_register(L, "GetHeroForHire", l_getHeroForHire);
  lua_register(L, "GiveResource", l_giveResource);
  lua_register(L, "SetResource", l_setResource);
  lua_register(L, "GetResource", l_getResource);
  lua_register(L, "ShareVision", l_shareVision);
  lua_register(L, "CancelShareVision", l_cancelShareVision);
  lua_register(L, "SetDaysAfterTownLost", l_setDaysAfterTownLost);
  lua_register(L, "GetDaysAfterTownLost", l_getDaysAfterTownLost);
  lua_register(L, "RevealMap", l_revealMap);
  lua_register(L, "SetBarrierTentVisited", l_SetBarrierTentVisited);
}

/************************************************ Heroes ********************************************************/

static int l_getCurrentHero(lua_State *L) {
  deepbound_push(L, deepbind<hero*>(GetCurrentHero()));
  return 1;
}

static int l_grantSpell(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int sp = (int)luaL_checknumber(L, 2);
  hro->AddSpell(sp);
  return 0;
}

static int l_forgetSpell(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int spell = (int)luaL_checknumber(L, 2);
  hro->spellsLearned[spell] = 0;
  return 0;
}

static int l_hasTroop(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  int quantity = (int)luaL_checknumber(L, 3);
  for (int i = 0; i < CREATURES_IN_ARMY; i++) {
    if (hro->army.creatureTypes[i] == creature && hro->army.quantities[i] >= quantity) {
      lua_pushboolean(L, true);
      return 1;
    }
  }
  lua_pushboolean(L, false);
  return 1;
}

static int l_getCreatureAmount(lua_State *L) {
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

static int l_takeTroop(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int creature = (int)luaL_checknumber(L, 2);
  int quantity = (int)luaL_checknumber(L, 3);

  for (int i = 0; i < CREATURES_IN_ARMY; i++) {
    if (hro->army.creatureTypes[i] == creature) {
      if (hro->army.quantities[i] > quantity) {
        hro->army.quantities[i] -= quantity;
        break;
      }
      else if (hro->army.quantities[i] <= quantity) {
        quantity -= hro->army.quantities[i];
        hro->army.creatureTypes[i] = -1;
        hro->army.quantities[i] = 0;
      }
    }
  }
  return 0;
}

static int l_teleportHero(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int x = (int)luaL_checknumber(L, 2);
  int y = (int)luaL_checknumber(L, 3);

  // Working around a bug where TeleportTo will erroneously call
  // gpGame->SetVisibility(hero, viewX, viewY, heroViewingRadius)
  gpAdvManager->viewX = x;
  gpAdvManager->viewY = y;

  gpAdvManager->TeleportTo(hro, x, y, 0, 0);
  return 0;
}

static int l_getHeroName(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushstring(L, hro->name);
  return 1;
}

static int l_setHeroName(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  lua_pushstring(L, hro->name);
  strncpy(hro->name, luaL_checkstring(L, 2), ELEMENTS_IN(hro->name));
  return 0;
}

static int l_getHeroInPool(lua_State *L) {
  int n = (int)luaL_checknumber(L, 1);
  deepbound_push(L, deepbind<hero*>(&gpGame->heroes[n]));
  return 1;
}

static int l_getHeroOwner(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  
  if (hro->ownerIdx < 0) {
    lua_pushnil(L);
  } else {
    deepbound_push(L, deepbind<playerData*>(&gpGame->players[hro->ownerIdx]));
  }

  return 1;
}

static int l_grantArtifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  GiveArtifact(hro, art, 1, -1);
  return 0;
}

static int l_hasArtifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  lua_pushboolean(L, hro->HasArtifact(art));
  return 1;
}

static int l_takeArtifact(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int art = (int)luaL_checknumber(L, 2);
  hro->TakeArtifact(art);
  return 0;
}

static int l_countEmptyArtifactSlots(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->CountEmptyArtifactSlots());
  return 1;
}

static int l_countEmptyCreatureSlots(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->CountEmptyCreatureSlots());
  return 1;
}

static int l_setExperiencePoints(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int points = (int)luaL_checknumber(L, 2);
  hro->experience = points;
  hro->CheckLevel();
  return 0;
}

static int l_getExperiencePoints(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->experience);
  return 1;
}

static int l_setPrimarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int skill = (int)luaL_checknumber(L, 2);
  int amt = (int)luaL_checknumber(L, 3);
  hro->SetPrimarySkill(skill, amt);
  return 0;
}

static int l_getPrimarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->primarySkills[skill]);
  return 1;
}

static int l_setSpellpoints(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int points = (int)luaL_checknumber(L, 2);
  hro->spellpoints = points;
  return 0;
}

static int l_getSpellpoints(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->spellpoints);
  return 1;
}

static int l_setSecondarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int skill = (int)luaL_checknumber(L, 2);
  int level = (int)luaL_checknumber(L, 3);
  hro->SetSS(skill, level);
  return 0;
}

static int l_getSecondarySkill(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int skill = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, hro->GetSSLevel(skill));
  return 1;
}

static int l_grantArmy(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int cr = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  hro->army.Add(cr, n, -1);
  return 0;
}

static int l_getHeroMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->mobility);
  return 1;
}

static int l_setHeroMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int mobility = (int)luaL_checknumber(L, 2);
  hro->mobility = mobility;
  return 0;
}

static int l_getHeroRemainingMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->remainingMobility);
  return 1;
}

static int l_setHeroRemainingMobility(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int remainingMobility = (int)luaL_checknumber(L, 2);
  hro->remainingMobility = remainingMobility;
  return 0;
}

static int l_getHeroX(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->x);
  return 1;
}

static int l_getHeroY(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->y);
  return 1;
}

static int l_getHeroLevel(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->GetLevel());
  return 1;
}

static int l_getHeroTempMoraleBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->tempMoraleBonuses);
  return 1;
}

static int l_setHeroTempMoraleBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int moraleBonus = (int)luaL_checknumber(L, 2);
  hro->tempMoraleBonuses = moraleBonus;
  return 0;
}

static int l_getHeroTempLuckBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->tempLuckBonuses);
  return 1;
}

static int l_setHeroTempLuckBonuses(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int LuckBonus = (int)luaL_checknumber(L, 2);
  hro->tempLuckBonuses = LuckBonus;
  return 0;
}

static int l_grantSpellScroll(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int sp = (int)luaL_checknumber(L, 2);
  GiveArtifact(hro, ARTIFACT_SPELL_SCROLL, 1, sp);
  return 0;
}

static int l_getHeroFaction(lua_State *L) {
  hero *hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, hro->factionID);
  return 1;
}

static int l_setHeroFaction(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int newFaction = (int)luaL_checknumber(L, 2);
  hro->factionID = newFaction;
  return 0;
}

static void register_hero_funcs(lua_State *L) {
  lua_register(L, "GetCurrentHero", l_getCurrentHero);
  lua_register(L, "GrantSpell", l_grantSpell);
  lua_register(L, "ForgetSpell", l_forgetSpell);
  lua_register(L, "HasTroop", l_hasTroop);
  lua_register(L, "GetCreatureAmount", l_getCreatureAmount);
  lua_register(L, "TakeTroop", l_takeTroop);
  lua_register(L, "TeleportHero", l_teleportHero);
  lua_register(L, "GetHeroName", l_getHeroName);
  lua_register(L, "SetHeroName", l_setHeroName);
  lua_register(L, "GetHeroInPool", l_getHeroInPool);
  lua_register(L, "GetHeroOwner", l_getHeroOwner);
  lua_register(L, "GrantArtifact", l_grantArtifact);
  lua_register(L, "HasArtifact", l_hasArtifact);
  lua_register(L, "TakeArtifact", l_takeArtifact);
  lua_register(L, "CountEmptyArtifactSlots", l_countEmptyArtifactSlots);
  lua_register(L, "CountEmptyCreatureSlots", l_countEmptyCreatureSlots);
  lua_register(L, "SetExperiencePoints", l_setExperiencePoints);
  lua_register(L, "GetExperiencePoints", l_getExperiencePoints);
  lua_register(L, "SetPrimarySkill", l_setPrimarySkill);
  lua_register(L, "GetPrimarySkill", l_getPrimarySkill);
  lua_register(L, "SetSpellpoints", l_setSpellpoints);
  lua_register(L, "GetSpellpoints", l_getSpellpoints);
  lua_register(L, "SetSecondarySkill", l_setSecondarySkill);
  lua_register(L, "GetSecondarySkill", l_getSecondarySkill);
  lua_register(L, "GrantArmy", l_grantArmy);
  lua_register(L, "GetHeroMobility", l_getHeroMobility);
  lua_register(L, "SetHeroMobility", l_setHeroMobility);
  lua_register(L, "GetHeroRemainingMobility", l_getHeroRemainingMobility);
  lua_register(L, "SetHeroRemainingMobility", l_setHeroRemainingMobility);
  lua_register(L, "GetHeroX", l_getHeroX);
  lua_register(L, "GetHeroY", l_getHeroY);
  lua_register(L, "GetHeroLevel", l_getHeroLevel);
  lua_register(L, "GetHeroTempMoraleBonuses", l_getHeroTempMoraleBonuses);
  lua_register(L, "SetHeroTempMoraleBonuses", l_setHeroTempMoraleBonuses);
  lua_register(L, "GetHeroTempLuckBonuses", l_getHeroTempLuckBonuses);
  lua_register(L, "SetHeroTempLuckBonuses", l_setHeroTempLuckBonuses);
  lua_register(L, "GrantSpellScroll", l_grantSpellScroll);
  lua_register(L, "GetHeroFaction", l_getHeroFaction);
  lua_register(L, "SetHeroFaction", l_setHeroFaction);
}

/************************************** Map *******************************************/

// FIXME: What is this 3?
static int l_mapSetObject(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  int obj = (int)luaL_checknumber(L, 3);

  mapCell* cell = gpAdvManager->GetCell(x, y);
  cell->overlayIndex = 3;
  cell->objectIndex = obj;
  cell->objType = obj & 0x7F;
  return 0;
}

static int l_mapPutArmy(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  int monIdx = (int)luaL_checknumber(L, 3);
  int monQty = (int)luaL_checknumber(L, 4);

  lua_pushinteger(L, gpAdvManager->MapPutArmy(x, y, monIdx, monQty));
  return 1;
}

/* Note: This doesn't really work, at least not in the way you want
 * EraseObj has special casing for a number of objects which are normally deleted in the game
 * (e.g.: monsters, resources, jails). This special casing will make it find other tiles (namely, shadows)
 * associated with the deleted object and delete them as well.
 * 
 * If you try to delete other objects, you will need to manually call this for every single tile -- and
 * if there are multiple overlays on a tile, you don't control which one is deleted. Furthermore,
 * if the tile was impassable, it will still be impassable. It appears that the impassability of tiles
 * is controlled by some mixture of display flag 0x20 (or was it 0x80? I forget) and other stuff
 * (like whether it has an object?). We still need to figure out exactly how that works.
 */
static int l_mapEraseObj(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  mapCell *cell = gpAdvManager->GetCell(x, y);
  gpAdvManager->EraseObj(cell, x, y);
  gpAdvManager->CompleteDraw(0);
  return 0;
}

static int l_mapFizzleObj(lua_State *L) {
	SAMPLE2 res;
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	bool snd = CheckBoolean(L, 3);
	mapCell *cell = gpAdvManager->GetCell(x, y);
	gpAdvManager->CompleteDraw(0);
	gpWindowManager->SaveFizzleSource(gMapViewportRegion._left, gMapViewportRegion._top, gMapViewportRegion.getWidth(), gMapViewportRegion.getHeight());
	if (snd) {
		if (!PlaySoundEffect((!CheckLocationItem(cell)?"killfade":("pickup0"+std::to_string(Random(1, 7)))), SND_DONT_WAIT, &res)) {
			snd = false;
		}
	}
	gpAdvManager->EraseObj(cell, x, y);
	gpAdvManager->CompleteDraw(0);
	PollSound();
	gpWindowManager->FizzleForward(gMapViewportRegion._left, gMapViewportRegion._top, gMapViewportRegion.getWidth(), gMapViewportRegion.getHeight(), -1, 0, 0);
	if (snd) {
		WaitEndSample(res, res.sample);
	}
	return 0;
}

static int l_mapSetTerrainTile(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  int tileno = (int)luaL_checknumber(L, 3);

  __int8 flip = MAP_CELL_NO_FLIP;
  if (lua_gettop(L) >= 4) {
    flip = (__int8)luaL_checknumber(L, 4);
  }

  mapCell *cell = gpAdvManager->GetCell(x, y);
  cell->groundIndex = tileno;
  cell->SetTileFlip(flip);
  gpAdvManager->CompleteDraw(0);
  return 0;
}

static void register_map_funcs(lua_State *L) {
  lua_register(L, "MapSetObject", l_mapSetObject);
  lua_register(L, "MapPutArmy", l_mapPutArmy);
  lua_register(L, "MapEraseSquare", l_mapEraseObj);
  lua_register(L, "MapFizzle", l_mapFizzleObj);
  lua_register(L, "MapSetTileTerrain", l_mapSetTerrainTile);
}

/************************************** Town *******************************************/

static int l_getCurrentTown(lua_State *L) {
  deepbound_push(L, deepbind<town*>(gpTownManager->castle));
  return 1;
}

static int l_hasVisitingHero(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushboolean(L, twn->visitingHeroIdx >= 0);
  return 1;
}

static int l_getVisitingHero(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  deepbound_push(L, deepbind<hero*>(&gpGame->heroes[twn->visitingHeroIdx]));
  return 1;
}

static int l_buildInCurrentTown(lua_State *L) {
  int obj = (int)luaL_checknumber(L, 1);
  gpTownManager->BuildObj(obj);
  return 0;
}

static int l_getTown(lua_State *L) {
  int index = (int)luaL_checknumber(L, 1);
  if (index < MAX_TOWNS) {
    deepbound_push(L, deepbind<town*>(&gpGame->castles[index]));
  }
  return 1;
}

static int l_getTownName(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushstring(L, twn->name);
  return 1;
}

static int l_setTownName(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  strcpy(twn->name, luaL_checkstring(L, 2));
  return 1;
}

static int l_getTownByName(lua_State *L) {
  char *name = (char*)luaL_checkstring(L, 1);
  for (int i = 0; i < MAX_TOWNS; i++) {
    if (strcmp(gpGame->castles[i].name, name) == 0) {
      deepbound_push(L, deepbind<town*>(&gpGame->castles[i]));
      return 1;
    }
  }
  lua_pushinteger(L, -1);
  return 1;
}

static int l_getPlayerTown(lua_State *L) {
  playerData *player = (playerData*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int index = (int)luaL_checknumber(L, 2);

  if (index < MAX_TOWNS) {
    deepbound_push(L, deepbind<town*>(&gpGame->castles[player->castlesOwned[index]]));
  }
  return 1;
}

static int l_buildInTown(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int building = (int)luaL_checknumber(L, 2);
  twn->BuildBuilding(building);
  return 0;
}

static int l_getTownFaction(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->factionID);
  return 1;
}

static int l_setTownFaction(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  FACTION faction = (FACTION)(int)luaL_checknumber(L, 2);
  twn->SetFaction(faction);
  return 0;
}

static int l_getCreatureCost(lua_State *L) {
  int creature = (int)luaL_checknumber(L, 1);
  int cost[NUM_RESOURCES];
  GetMonsterCost(creature, cost);
  for (int i = 0; i < NUM_RESOURCES; i++) {
    lua_pushinteger(L, cost[i]);
  }
  return 7;
}

static int l_getTownOwner(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->ownerIdx);
  return 1;
}

static int l_setTownOwner(lua_State *L) {
  int townIdx = (int)luaL_checknumber(L, 1);
  int playerIdx = (int)luaL_checknumber(L, 2);
  gpGame->ClaimTown(townIdx, playerIdx, 0);
  return 0;
}

static int l_getTownX(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->x);
  return 1;
}

static int l_getTownY(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, twn->y);
  return 1;
}

static int l_getTownIDFromPos(lua_State *L) {
  int x = (int)luaL_checknumber(L, 1);
  int y = (int)luaL_checknumber(L, 2);
  lua_pushinteger(L, gpGame->GetTownId(x, y));
  return 1;
}

static int l_setNumberOfCreatures(lua_State *L) {
  town* cstle = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int dwllng = (int)luaL_checknumber(L, 2);
  int numcrtrs = (int)luaL_checknumber(L, 3);
  cstle->numCreaturesInDwelling[dwllng] = numcrtrs;
  return 0;
}

static int l_setNumGuildSpells(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  twn->SetNumSpellsOfLevel(l, n);
  twn->GiveSpells(NULL);
  return 0;
}

static int l_setGuildSpell(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 4));
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  int s = (int)luaL_checknumber(L, 4);
  twn->mageGuildSpells[l][n] = s;
  twn->GiveSpells(NULL);
  return 0;
}

static int l_getGuildSpell(lua_State *L) {
  town* twn = (town*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
  int l = (int)luaL_checknumber(L, 2);
  int n = (int)luaL_checknumber(L, 3);
  int s = twn->mageGuildSpells[l][n];
  lua_pushinteger(L, s);
  return 1;
}

static int l_disallowBuilding(lua_State *L) {
  int townIdx = (int)luaL_checknumber(L, 1);
  int building = (int)luaL_checknumber(L, 2);
  if(building >= 0 && building < BUILDING_MAX && townIdx >= 0 && townIdx < MAX_TOWNS)
    gpGame->disallowedBuildings[townIdx][building] = true;
  return 0;
}

static void register_town_funcs(lua_State *L) {
  lua_register(L, "GetCurrentTown", l_getCurrentTown);
  lua_register(L, "HasVisitingHero", l_hasVisitingHero);
  lua_register(L, "GetVisitingHero", l_getVisitingHero);
  lua_register(L, "BuildInCurrentTown", l_buildInCurrentTown);
  lua_register(L, "GetTown", l_getTown);
  lua_register(L, "GetTownName", l_getTownName);
  lua_register(L, "SetTownName", l_setTownName);
  lua_register(L, "GetTownByName", l_getTownByName);
  lua_register(L, "GetPlayerTown", l_getPlayerTown);
  lua_register(L, "BuildInTown", l_buildInTown);
  lua_register(L, "GetTownFaction", l_getTownFaction);
  lua_register(L, "SetTownFaction", l_setTownFaction);
  lua_register(L, "GetCreatureCost", l_getCreatureCost);
  lua_register(L, "GetTownOwner", l_getTownOwner);
  lua_register(L, "SetTownOwner", l_setTownOwner);
  lua_register(L, "GetTownX", l_getTownX);
  lua_register(L, "GetTownY", l_getTownY);
  lua_register(L, "GetTownIdFromPos", l_getTownIDFromPos);
  lua_register(L, "SetNumberOfCreatures", l_setNumberOfCreatures);
  lua_register(L, "SetNumGuildSpells", l_setNumGuildSpells);
  lua_register(L, "SetGuildSpell", l_setGuildSpell);
  lua_register(L, "GetGuildSpell", l_getGuildSpell);
  lua_register(L, "DisallowBuilding", l_disallowBuilding);
}

/************************************* Battle ******************************************/

// FIXME: DraggonFantasy's version used getFirstEmptyHex. That was more useful
static int l_battleSummonCreature(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  int hex = (int)luaL_checknumber(L, 2);
  int creature = (int)luaL_checknumber(L, 3);
  int quantity = (int)luaL_checknumber(L, 4);

  gpCombatManager->AddArmy(side, creature, quantity, hex, 0, 1);
  return 0;
}

static int l_isHexEmpty(lua_State *L) {
  int hexno = (int)luaL_checknumber(L, 1);
  if (!ValidHex(hexno)) {
    lua_pushboolean(L, 0);
  }
  else {
    hexcell *cell = &gpCombatManager->combatGrid[hexno];
    lua_pushboolean(L, cell->unitOwner == -1 && !cell->isBlocked);
  }

  return 1;
}

static int l_battleHasHero(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  lua_pushboolean(L, gpCombatManager->heroes[side] != NULL);
  return 1;
}

static int l_battleGetHero(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  deepbound_push(L, deepbind<hero*>(gpCombatManager->heroes[side]));
  return 1;
}

static int l_battleMessage(lua_State *L) {
  char* message = (char*)luaL_checkstring(L, 1);
  gpCombatManager->CombatMessage(message);
  return 0;
}

static int l_battleGetNumStacks(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  lua_pushinteger(L, gpCombatManager->numCreatures[side]);
  return 1;
}

static int l_battleGetStack(lua_State *L) {
  int side = (int)luaL_checknumber(L, 1);
  int idx = (int)luaL_checknumber(L, 2);
  deepbound_push(L, deepbind<army*>(&gpCombatManager->creatures[side][idx]));
  return 1;
}

static int l_getStackSide(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->owningSide);
  return 1;
}

static int l_getStackType(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creatureIdx);
  return 1;
}

static int l_getStackQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->quantity);
  return 1;
}

static int l_setStackQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int quantity = (int)luaL_checknumber(L, 2);
  creat->quantity = quantity;
  return 0;
}

static int l_getStackInitialQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->initialQuantity);
  return 1;
}

static int l_setStackInitialQuantity(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int initialQuantity = (int)luaL_checknumber(L, 2);
  creat->initialQuantity = initialQuantity;
  return 0;
}

static int l_getStackHex(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->occupiedHex);
  return 1;
}

static int l_getStackMorale(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->morale);
  return 1;
}

static int l_setStackMorale(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int morale = (int)luaL_checknumber(L, 2);
  creat->morale = morale;
  return 0;
}

static int l_getStackLuck(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->luck);
  return 1;
}

static int l_setStackLuck(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int luck = (int)luaL_checknumber(L, 2);
  creat->luck = luck;
  return 0;
}

static int l_getStackAttack(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creature.attack);
  return 1;
}

static int l_setStackAttack(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int attack = (int)luaL_checknumber(L, 2);
  creat->creature.attack = attack;
  return 0;
}

static int l_getStackDefense(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creature.defense);
  return 1;
}

static int l_setStackDefense(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int defense = (int)luaL_checknumber(L, 2);
  creat->creature.defense = defense;
  return 0;
}

static int l_getStackSpeed(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creature.speed);
  return 1;
}

static int l_setStackSpeed(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int speed = (int)luaL_checknumber(L, 2);
  creat->creature.speed = speed;
  return 0;
}

static int l_getStackShots(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creature.shots);
  return 1;
}

static int l_setStackShots(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int shots = (int)luaL_checknumber(L, 2);
  creat->creature.shots = shots;
  return 0;
}

static int l_getStackHp(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 1));
  lua_pushinteger(L, creat->creature.hp - creat->damage);
  return 1;
}

static int l_setStackHp(lua_State *L) {
  army *creat = (army*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 2));
  int hp = (int)luaL_checknumber(L, 2);
  creat->damage = creat->creature.hp - hp;
  return 0;
}

static void register_battle_funcs(lua_State *L) {
  lua_register(L, "BattleSummonCreature", l_battleSummonCreature);
  lua_register(L, "IsHexEmpty", l_isHexEmpty);
  lua_register(L, "BattleHasHero", l_battleHasHero);
  lua_register(L, "BattleGetHero", l_battleGetHero);
  lua_register(L, "BattleMessage", l_battleMessage);
  lua_register(L, "BattleNumStacksForSide", l_battleGetNumStacks);
  lua_register(L, "BattleGetStack", l_battleGetStack);
  lua_register(L, "GetStackSide", l_getStackSide);
  lua_register(L, "GetStackType", l_getStackType);
  lua_register(L, "GetStackQuantity", l_getStackQuantity);
  lua_register(L, "SetStackQuantity", l_setStackQuantity);
  lua_register(L, "GetStackInitialQuantity", l_getStackInitialQuantity);
  lua_register(L, "SetStackInitialQuantity", l_setStackInitialQuantity);
  lua_register(L, "GetStackHex", l_getStackHex);
  lua_register(L, "GetStackMorale", l_getStackMorale);
  lua_register(L, "SetStackMorale", l_setStackMorale);
  lua_register(L, "GetStackLuck", l_getStackLuck);
  lua_register(L, "SetStackLuck", l_setStackLuck);
  lua_register(L, "GetStackAttack", l_getStackAttack);
  lua_register(L, "SetStackAttack", l_setStackAttack);
  lua_register(L, "GetStackDefense", l_getStackDefense);
  lua_register(L, "SetStackDefense", l_setStackDefense);
  lua_register(L, "GetStackSpeed", l_getStackSpeed);
  lua_register(L, "SetStackSpeed", l_setStackSpeed);
  lua_register(L, "GetStackShots", l_getStackShots);
  lua_register(L, "SetStackShots", l_setStackShots);
  lua_register(L, "GetStackHp", l_getStackHp);
  lua_register(L, "SetStackHp", l_setStackHp);
}

/**************************************** Campaign *********************************************/

static int l_getCampaignChoiceType(lua_State *L) {
  int curMapID = xCampaign.currentMapID;
  SCampaignChoice *curChoice = &xCampaignChoices[xCampaign.campaignID][curMapID][xCampaign.bonusChoices[curMapID]];
  lua_pushinteger(L, curChoice->type);
	return 1;
}

static int l_getCampaignChoiceField(lua_State *L) {
  int curMapID = xCampaign.currentMapID;
  SCampaignChoice *curChoice = &xCampaignChoices[xCampaign.campaignID][curMapID][xCampaign.bonusChoices[curMapID]];
  lua_pushinteger(L, curChoice->field);
	return 1;
}

static int l_getCampaignChoiceAmount(lua_State *L) {
  int curMapID = xCampaign.currentMapID;
  SCampaignChoice *curChoice = &xCampaignChoices[xCampaign.campaignID][curMapID][xCampaign.bonusChoices[curMapID]];
  lua_pushinteger(L, curChoice->amount);
	return 1;
}

static int l_getCampaignChoice(lua_State *L) {
  int curMapID = xCampaign.currentMapID;
  SCampaignChoice *curChoice = &xCampaignChoices[xCampaign.campaignID][curMapID][xCampaign.bonusChoices[curMapID]];
  deepbound_push(L, deepbind<SCampaignChoice*>(curChoice));
	return 1;
}

static void register_campaign_funcs(lua_State *L) {
  lua_register(L, "GetCampaignChoiceType", l_getCampaignChoiceType);
  lua_register(L, "GetCampaignChoiceField", l_getCampaignChoiceField);
  lua_register(L, "GetCampaignChoiceAmount", l_getCampaignChoiceAmount);
  lua_register(L, "GetCampaignChoice", l_getCampaignChoice);
}

/************************************** Uncategorized ******************************************/

static int l_playsoundeffect(lua_State *L) {
	std::string snd = std::string(luaL_checkstring(L, 1));
	PlaySoundEffect(snd, SND_DO_WAIT, NULL);
	return 0;
}

static int l_getinclinedtojoin(lua_State *L) {
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	int inclinedToJoin = 0;
	if ((x >= 0) && (y >= 0) && (x < gpGame->map.width) && (y < gpGame->map.height)) {
		int cellIdx = y * gpGame->map.height + x;
		if (gpGame->map.tiles[cellIdx].objType == (LOCATION_ARMY_CAMP | TILE_HAS_EVENT)) {
			inclinedToJoin = (gpGame->map.tiles[cellIdx].extraInfo & MAP_CELL_EXTRA_MONSTER_AMOUNT);
		}
	}
	if (inclinedToJoin) {
		lua_pushinteger(L, 1);
	} else {
		lua_pushinteger(L, 0);
	}
	return 1;
}

static int l_setinclinedtojoin(lua_State *L) {
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	bool inclinedToJoin = CheckBoolean(L, 3);
	if ((x >= 0) && (y >= 0) && (x < gpGame->map.width) && (y < gpGame->map.height)) {
		int cellIdx = y * gpGame->map.height + x;
		if (gpGame->map.tiles[cellIdx].objType == (LOCATION_ARMY_CAMP | TILE_HAS_EVENT)) {
			if (inclinedToJoin) {
				gpGame->map.tiles[cellIdx].extraInfo |= MAP_CELL_EXTRA_MONSTER_AMOUNT;
			} else {
				gpGame->map.tiles[cellIdx].extraInfo &= ~MAP_CELL_EXTRA_MONSTER_AMOUNT;
			}
		}
	}
	return 0;
}

static int l_startbattle(lua_State *L) {
  hero* hro = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 4));
  int mon1 = (int)luaL_checknumber(L, 2);
  int mon1quantity = (int)luaL_checknumber(L, 3);
  int switchSides = (int)luaL_checknumber(L, 4);
  mapCell* mapcell = gpAdvManager->GetCell(hro->x, hro->y);
  int winningSide = gpAdvManager->CombatMonsterEvent(hro, mon1, mon1quantity, mapcell, hro->x, hro->y, switchSides, hro->x, hro->y, -1, 0, 0, -1, 0, 0);
  lua_pushinteger(L, winningSide);
  return 1;
}

static int l_toggleAIArmySharing(lua_State *L) {
  bool toggle = CheckBoolean(L, 1);
  gpGame->allowAIArmySharing = toggle;
  return 0;
}

static int l_forceComputerPlayerChase(lua_State *L) {
	hero* src = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(1, 3));
	hero* dst = (hero*)GetPointerFromLuaClassTable(L, StackIndexOfArg(2, 3));
	bool force = CheckBoolean(L, 3);
	gpGame->ForceComputerPlayerChase(src, dst, force);
	return 0;
}

static void register_uncategorized_funcs(lua_State *L) {
  lua_register(L, "PlaySoundEffect", l_playsoundeffect);
  lua_register(L, "GetInclinedToJoin", l_getinclinedtojoin);
  lua_register(L, "SetInclinedToJoin", l_setinclinedtojoin);
  lua_register(L, "StartBattle", l_startbattle);
  lua_register(L, "ToggleAIArmySharing", l_toggleAIArmySharing);
  lua_register(L, "ForceComputerPlayerChase", l_forceComputerPlayerChase);
}

/****************************************************************************************************************/


void set_scripting_funcs(lua_State *L) {
  register_dialog_funcs(L);
  register_date_funcs(L);
  register_player_funcs(L);
  register_hero_funcs(L);
  register_map_funcs(L);
  register_town_funcs(L);
  register_battle_funcs(L);
  register_campaign_funcs(L);
  register_uncategorized_funcs(L);
}
