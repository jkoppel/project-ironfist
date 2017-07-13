#include<string>

#include "analytics.h"
#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "prefs.h"
#include "scripting/callback.h"
#include "scripting/scripting.h"
#include "spell/spells.h"


char* gAlignmentNames[13] = {"Knight", "Barbarian", "Sorceress", "Warlock", "Wizard", "Necromancer",
                             "Multiple", "Random", NULL, NULL, NULL, NULL,
                             "Cyborg"};

int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}

extern int gbNoCDRom;


int game::SetupGame() {
	int oldNoCDRom = gbNoCDRom;
	gbNoCDRom = 0;
	int res = this->SetupGame_orig();
	gbNoCDRom = oldNoCDRom;
	return res;
}

void game::RandomizeHeroPool() {
	signed int idx;

	for( idx = 0; idx < MAX_HEROES; idx++) {
		this->heroes[idx].experience = Random(0, 50) + 40;
		this->SetRandomHeroArmies(idx, 0);
		this->heroes[idx].remainingMobility = this->heroes[idx].CalcMobility();
		this->heroes[idx].mobility = this->heroes[idx].remainingMobility;
		this->heroes[idx].randomSeed = Random(1, 255);
		this->heroes[idx].wisdomLastOffered = 1;
		switch(this->heroes[idx].factionID) {
		case FACTION_SORCERESS:
			this->heroes[idx].AddSpell(SPELL_BLESS);
			break;
		case FACTION_WARLOCK:
			this->heroes[idx].AddSpell(SPELL_CURSE);
			break;
		case FACTION_NECROMANCER:
			this->heroes[idx].AddSpell(SPELL_HASTE);
			break;
		case FACTION_WIZARD:
			this->heroes[idx].AddSpell(SPELL_STONESKIN);
			break;
		}
	}
}

extern char gMapName[]; // the map selected in the list
extern char gLastFilename[];
extern signed char xIsExpansionMap;

void game::InitNewGame(struct SMapHeader *a) {
	if (!strlen(gLastFilename)) { // game just started, no map was played yet
		std::string lastPlayed;
		if (xIsExpansionMap)
			lastPlayed = read_pref<std::string>("Last Map expansion");
		else
			lastPlayed = read_pref<std::string>("Last Map");

		if (lastPlayed.length() < 20) { // otherwise means no registry keys exist yet
			strcpy(gMapName, lastPlayed.c_str());
			strcpy(this->mapFilename, lastPlayed.c_str());
		}
	}
	this->InitNewGame_orig(a);
}

void game::NewMap(char* mapname) {
  send_event(mapAction, mapname);
  if (xIsExpansionMap)
	  write_pref("Last Map expansion", std::string(gMapName));
  else
	  write_pref("Last Map", std::string(gMapName));
  this->ResetIronfistGameState();
  this->NewMap_orig(mapname);
  ScriptingInit(std::string(mapname));
  gpGame->firstDayEventDone = false;
  gpGame->allowAIArmySharing = true;
}
/*
//----- (0041C580) --------------------------------------------------------
void __thiscall game::NewMap(char *name) {
  int mightBeOffsetForNextFaction; // eax@105
  int heroLocationX; // ST74_4@110
  int heroLocationY; // ST6C_4@110
  mapCell *heroCell; // ST34_4@110
  int randomVal1; // ebx@116
  int randomVal2; // ebx@116
  int distanceYBetweenUltimateArtifactAndHero; // ebx@126
  int randomVal4; // ebx@137
  int randomVal5; // ebx@137
  int lossConditionArgumentLocX; // ecx@158
  int relatedToWinConditionLocX; // ecx@164
  double resourceMultiplierFromHandicap; // [sp+14h] [bp-68h]@151
  int ultimateArtifactLocYRadiusOffset; // [sp+1Ch] [bp-60h]@133
  int ultimateArtifactLocXRadiusOffset; // [sp+20h] [bp-5Ch]@130
  int playerIdxnFaction; // [sp+2Ch] [bp-50h]@171
  char *expansionCampaignHeroName; // [sp+30h] [bp-4Ch]@0
  char expansionCampaignHeroID; // [sp+34h] [bp-48h]@0
  FACTION factionSorceressOrNecromancer; // [sp+38h] [bp-44h]@76
  signed int probablyFaction; // [sp+38h] [bp-44h]@90
  signed int heroIdxA; // [sp+3Ch] [bp-40h]@78
  signed int heroIdxB; // [sp+3Ch] [bp-40h]@95
  signed int someSortOfCastleIdxOrRelatedToCastles; // [sp+44h] [bp-38h]@53
  int relatedToLastMsgNumHumanPlayers; // [sp+4Ch] [bp-30h]@7
  signed int faction; // [sp+50h] [bp-2Ch]@87
  int numPlayers; // [sp+54h] [bp-28h]@42
  signed int numPlayersa; // [sp+54h] [bp-28h]@57
  signed int numPlayersb; // [sp+54h] [bp-28h]@108
  int ultimateArtifactLocY; // [sp+54h] [bp-28h]@116
  int resourceType; // [sp+54h] [bp-28h]@148
  signed int castlesOwnedIdx; // [sp+54h] [bp-28h]@188
  signed int playerIdx; // [sp+58h] [bp-24h]@7
  signed int playerIdxa; // [sp+58h] [bp-24h]@15
  signed int playerIdxb; // [sp+58h] [bp-24h]@20
  signed int playerIdxc; // [sp+58h] [bp-24h]@23
  signed int playerIdxd; // [sp+58h] [bp-24h]@26
  signed int playerIdxe; // [sp+58h] [bp-24h]@29
  signed int playerIdxf; // [sp+58h] [bp-24h]@32
  signed int playerIdxg; // [sp+58h] [bp-24h]@35
  signed int playerIdxh; // [sp+58h] [bp-24h]@42
  signed int playerIdxi; // [sp+58h] [bp-24h]@51
  int playerIdxj; // [sp+58h] [bp-24h]@69
  signed int playerIdxk; // [sp+58h] [bp-24h]@106
  int ultimateArtifactLocX; // [sp+58h] [bp-24h]@116
  signed int playerIdxm; // [sp+58h] [bp-24h]@144
  signed int playerIdxn; // [sp+58h] [bp-24h]@169
  int lossConditionArgumentLocY; // [sp+5Ch] [bp-20h]@158
  int relatedToWinConditionLocY; // [sp+5Ch] [bp-20h]@164
  signed int someSortOfLoopCount; // [sp+60h] [bp-1Ch]@116
  int relatedToPlayerColor; // [sp+68h] [bp-14h]@7
  int lastToken; // [sp+6Ch] [bp-10h]@1
  signed int goesFrom0To1; // [sp+74h] [bp-8h]@55
  int randomVal3; // [sp+78h] [bp-4h]@116

  lastToken = FindLastToken(gMapName, 46);
  if (lastToken && StrEqNoCase((int *)(lastToken + 1), (int *)"MX2"))
    LOBYTE(xIsExpansionMap) = 1;
  if (xIsExpansionMap)
    gTownEligibleBuildMask[5] |= 4u;
  else
    gTownEligibleBuildMask[5] &= 0xFFFFFFFBu;
  gbInNewGameSetup = 1;
  giCurPlayer = 0;
  gpCurPlayer = gpGame->players;
  giCurPlayerBit = 1;
  giCurWatchPlayerBit = 1;
  giCurWatchPlayer = 0;
  relatedToPlayerColor = Random(0, 5);          // Constant here (related to player colors)
  relatedToLastMsgNumHumanPlayers = iLastMsgNumHumanPlayers;
  for (playerIdx = 0; playerIdx < 6; ++playerIdx) {
    if (gpGame->mapHeader.numPlayers > playerIdx) {
      if (this->somePlayerCodeOr10IfMayBeHuman[playerIdx] == 10)
        gbSetupGamePosToRealGamePos[playerIdx] = relatedToLastMsgNumHumanPlayers++;
      else
        gbSetupGamePosToRealGamePos[playerIdx] = this->somePlayerCodeOr10IfMayBeHuman[playerIdx];
    } else {
      gbSetupGamePosToRealGamePos[playerIdx] = -1;
    }
  }
  for (playerIdxa = 0; playerIdxa < 6; ++playerIdxa) {
    this->players[playerIdxa].color = -1;
    gcColorToPlayerPos[playerIdxa] = -1;
    gcColorToSetupPos[playerIdxa] = -1;
    if (gpGame->relatedToColorOfPlayerOrFaction[playerIdxa] == 7)// gpGame->field_459 changed to relatedToColorOfPlayerOrFaction
      gpGame->relatedToColorOfPlayerOrFaction[playerIdxa] = relatedToPlayerColor;
    relatedToPlayerColor = (relatedToPlayerColor + 1) % 6;// Constant here (related to next player color)
  }
  for (playerIdxb = 0; this->numPlayers > playerIdxb; ++playerIdxb)
    gcColorToSetupPos[this->relatedToPlayerPosAndColor[playerIdxb]] = playerIdxb;// field_44D changed to relatedToPlayerPosAndColor
  for (playerIdxc = 0; this->numPlayers > playerIdxc; ++playerIdxc)
    this->players[gbSetupGamePosToRealGamePos[playerIdxc]].color = this->relatedToPlayerPosAndColor[playerIdxc];
  for (playerIdxd = 0; this->numPlayers > playerIdxd; ++playerIdxd)
    gcColorToPlayerPos[this->players[playerIdxd].color] = playerIdxd;
  for (playerIdxe = 0; this->numPlayers > playerIdxe; ++playerIdxe) {
    this->players[playerIdxe].numCastles = 0;
    BYTE1(this->players[playerIdxe].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx) = 0;// playerData->field_45 changed to relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx
    LOBYTE(this->players[playerIdxe].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx) = -1;// Consider splitting this into multiple variables
    this->players[playerIdxe].numHeroes = 0;
    this->players[playerIdxe].relatedToSomeSortOfHeroCountOrIdx = 0;
    this->players[playerIdxe].curHeroIdx = -1;
  }
  this->RandomizeHeroPool();                // Check this function (design question; hardcoded, faction-specific data; SetupRandomHeroArmies does this as well)
  strcpy(gMapName, name);
  this->LoadMap(gMapName);
  this->InitRandomArtifacts();
  this->ProcessRandomObjects();             // Check this function (Creature limit constants; within RandomizeTown: faction limit constants)
  this->ProcessMapExtra();
  this->SetupTowns;                       // Check this function (design question; as the faction Idx increases, the chances of getting certain spells increases; this happens because faction ordering represents their aptitudes for magic)
  this->InitializePasswords();
  for (playerIdxf = 0; playerIdxf < 6; ++playerIdxf)
    this->players[playerIdxf].barrierTentsVisited = 0;
  this->RandomizeEvents;
  this->ProcessOnMapHeroes;               // Check this function (design question; the game depends on the mathematical relationships between the number of heroes and factions in order to properly execute logic here; there is also no default case to be generalized)
  this->couldBeNumDefeatedPlayers = 0;
  for (playerIdxg = this->numPlayers; playerIdxg < 6; ++playerIdxg)
    this->playerDead[playerIdxg] = 1;
  if (this->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_COLOR
      || this->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_HERO) {
    this->mapHeader.relatedToWinConditionType = 1;
    this->mapHeader.allowDefeatAllVictory = 0;
  }
  if (this->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_COLOR) {
    numPlayers = 0;
    for (playerIdxh = 0; playerIdxh < 6; ++playerIdxh) {
      if (this->mapHeader.hasPlayer[playerIdxh])
        ++numPlayers;
      if (this->mapHeader.winConditionArgumentOrLocX + 1 == numPlayers) {
        HIWORD(this->mapHeader.lossConditionArgumentOrLocY) = playerIdxh;
        playerIdxh = 99;
      }
    }
  }
  if (this->mapHeader.winConditionType == WIN_CONDITION_FIND_ARTIFACT)
    this->mapHeader.relatedToWinConditionType = 1;// field_1E changed to relatedToWinConditionType
  for (playerIdxi = 0; this->numPlayers > playerIdxi; ++playerIdxi) {
    this->players[playerIdxi].field_40 = 0;
    LOBYTE(this->players[playerIdxi].field_41) = -1;
    HIBYTE(this->players[playerIdxi].field_41) = -1;// Consider splitting this into multiple variables
    someSortOfCastleIdxOrRelatedToCastles = -1;
    if (!this->mapHeader.noStartingHeroInCastle && this->players[playerIdxi].numCastles > 0) {
      for (goesFrom0To1 = 0; goesFrom0To1 < 2; ++goesFrom0To1) {
        for (numPlayersa = 0; this->players[playerIdxi].numCastles > numPlayersa; ++numPlayersa) {
          if (someSortOfCastleIdxOrRelatedToCastles == -1
              && this->castles[*((_BYTE *)(&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx)
                                 + numPlayersa
                                 + 2)].visitingHeroIdx == -1
              && (this->castles[*((_BYTE *)(&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx)
                                  + numPlayersa
                                  + 2)].buildingsBuiltFlags & 0x40
                  || goesFrom0To1 == 1))
            someSortOfCastleIdxOrRelatedToCastles = numPlayersa;
        }
      }
    }
    if (someSortOfCastleIdxOrRelatedToCastles != -1) {
      *(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi) = this->GetNewHeroId playerIdxi, this->castles[*((_BYTE *)&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx + someSortOfCastleIdxOrRelatedToCastles + 2)].factionID, 0);// Constant here (within GetNewHeroId)
      this->relatedToHeroForHireStatus[*(&this->players[0].heroesOwned[284 * playerIdxi]
                                         + this->players[playerIdxi].numHeroes
                                         - playerIdxi)] = playerIdxi;// 283 is playerData object size; players[6] is array of playerData. There is lots of unnecessary pointer arithmetic here that could just be replaced by using the indices for the elements in the array within the array brackets.
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].ownerIdx = playerIdxi;
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].x = this->castles[*((_BYTE *)&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx + someSortOfCastleIdxOrRelatedToCastles + 2)].x;
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].y = this->castles[*((_BYTE *)&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx + someSortOfCastleIdxOrRelatedToCastles + 2)].y;
      this->castles[*((_BYTE *)&this->players[playerIdxi].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx
                      + someSortOfCastleIdxOrRelatedToCastles
                      + 2)].visitingHeroIdx = *(&this->players[0].heroesOwned[284 * playerIdxi]
                                                + this->players[playerIdxi].numHeroes
                                                - playerIdxi);
      this->SetVisibility(
        this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes
                       - playerIdxi)].x,
        this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes
                       - playerIdxi)].y,
        playerIdxi,
        giVisRange[this->heroes[this->players[playerIdxi].heroesOwned[0]].secondarySkillLevel[3]]);
      ++this->players[playerIdxi].numHeroes;
    }
  }
  for (playerIdxj = 0; this->numPlayers > playerIdxj; ++playerIdxj) {
    if (playerIdxj || !gbInCampaign || !this->maybeIsGoodCampaign && !this->field_84)// this->field_7F changed to maybeIsGoodCampaign
      goto LABEL_195;
    factionSorceressOrNecromancer = this->maybeIsGoodCampaign ? FACTION_SORCERESS : FACTION_NECROMANCER;
    for (heroIdxA = 0;
         heroIdxA < 54
         && (this->heroes[heroIdxA].factionID != factionSorceressOrNecromancer
             || this->relatedToHeroForHireStatus[heroIdxA] != -1);
         ++heroIdxA)
      ;
    if (heroIdxA < 54) {
      if (this->maybeIsGoodCampaign) {
        this->heroes[heroIdxA].experience += 5000;
        &(this->heroes[heroIdxA])->CheckLevel();
        strcpy(this->heroes[heroIdxA].name, "Sister Eliza");
        this->heroes[heroIdxA].heroID = 56;
      } else {
        this->heroes[heroIdxA].experience += 5000;
        &(this->heroes[heroIdxA])->CheckLevel();
        strcpy(this->heroes[heroIdxA].name, "Brother Brax");
        this->heroes[heroIdxA].heroID = 59;
      }
      this->players[0].heroesForPurchase[0] = heroIdxA;
      this->relatedToHeroForHireStatus[this->players[0].heroesForPurchase[0]] = 64;
      faction = this->heroes[heroIdxA].factionID;
    } else {
    LABEL_195:
      if (!xIsPlayingExpansionCampaign || playerIdxj)
        goto LABEL_196;
      probablyFaction = -1;                     // Constant here
      if ((&xCampaign)->HasAward(6)) {
        probablyFaction = FACTION_WIZARD;       // Constant here
        expansionCampaignHeroName = (&xCampaign)->JosephName();
        expansionCampaignHeroID = 64;
      } else if ((&xCampaign)->HasAward(7)) {
        probablyFaction = FACTION_BARBARIAN;    // Constant here
        expansionCampaignHeroName = (&xCampaign)->IvanName();
        expansionCampaignHeroID = 63;
      }
      if (probablyFaction == -1)              // Constant here
        goto LABEL_196;
      for (heroIdxB = 0;
           heroIdxB < 54
           && (this->heroes[heroIdxB].factionID != probablyFaction || this->relatedToHeroForHireStatus[heroIdxB] != -1);
           ++heroIdxB)
        ;
      if (heroIdxB >= 54) {
      LABEL_196:
        faction = Random(0, 5);                 // Constant here
        if (this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[this->players[playerIdxj].color]] < 6)
          faction = this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[this->players[playerIdxj].color]];// May need to redefine these tables; unsure
        this->players[playerIdxj].heroesForPurchase[0] = this->GetNewHeroId(playerIdxj, faction, 0);
        this->relatedToHeroForHireStatus[this->players[playerIdxj].heroesForPurchase[0]] = 64;
      } else {
        this->heroes[heroIdxB].experience = 5000;
        &(this->heroes[heroIdxB])->CheckLevel();// Check this function
        strcpy(this->heroes[heroIdxB].name, expansionCampaignHeroName);
        this->heroes[heroIdxB].heroID = expansionCampaignHeroID;
        this->players[0].heroesForPurchase[0] = heroIdxB;
        this->relatedToHeroForHireStatus[this->players[0].heroesForPurchase[0]] = 64;
        faction = this->heroes[heroIdxB].factionID;
      }
    }
    mightBeOffsetForNextFaction = Random(1, 5); // Constant here
    this->players[playerIdxj].heroesForPurchase[1] = this->GetNewHeroId(
      playerIdxj,
      (faction + mightBeOffsetForNextFaction) % 6,
      0);
    this->relatedToHeroForHireStatus[this->players[playerIdxj].heroesForPurchase[1]] = 64;
  }
  for (playerIdxk = 0; this->numPlayers > playerIdxk; ++playerIdxk) {
    for (numPlayersb = 0; this->players[playerIdxk].numHeroes > numPlayersb; ++numPlayersb) {
      heroLocationX = this->heroes[this->players[playerIdxk].heroesOwned[numPlayersb]].x;
      heroLocationY = this->heroes[this->players[playerIdxk].heroesOwned[numPlayersb]].y;
      this->heroes[this->players[playerIdxk].heroesOwned[numPlayersb]].occupiedObjType = *(&this->map.tiles[heroLocationX].objType
                                                                                           + 12
                                                                                           * heroLocationY
                                                                                           * this->map.width);// The pointer arithmetic can be replaced by taking the offsets and adding them to the index value within the tiles[] array brackets. The "12" should be removed since that is just to account for the 12-byte size of the mapCell type, which tiles[] is an array of
      this->heroes[this->players[playerIdxk].heroesOwned[numPlayersb]].occupiedObjVal = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[heroLocationX].field_4_1_1_isShadow_1_13_extraInfo + 6 * heroLocationY * this->map.width) >> 8) >> -5);// A doubly-bad decompilation error
      *(&this->map.tiles[heroLocationX].objType + 12 * heroLocationY * this->map.width) = -86;
      heroCell = &this->map.tiles[heroLocationY * this->map.width] + heroLocationX;
      heroCell->field_4_1_1_isShadow_1_13_extraInfo = heroCell->field_4_1_1_isShadow_1_13_extraInfo & 7 | 8 * this->players[playerIdxk].heroesOwned[numPlayersb];
    }
    if (this->players[playerIdxk].numHeroes <= 0) {
      if (this->players[playerIdxk].numCastles > 0)
        LOBYTE(this->players[playerIdxk].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx) = BYTE2(this->players[playerIdxk].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx);
    } else {
      this->players[playerIdxk].curHeroIdx = this->players[playerIdxk].heroesOwned[0];
    }
  }
  ultimateArtifactLocX = -1;
  ultimateArtifactLocY = -1;
  someSortOfLoopCount = 0;
  randomVal1 = Random(1, 30);
  randomVal2 = Random(1, 20) + randomVal1;
  randomVal3 = Random(1, 20) + randomVal2;
  while (1) {
    if (ultimateArtifactLocX >= 9) {
      if (ultimateArtifactLocY >= 9) {
        if (MAP_WIDTH - 10 >= ultimateArtifactLocX) {
          if (MAP_HEIGHT - 10 >= ultimateArtifactLocY) {
            if (*(&this->map.tiles[ultimateArtifactLocX].objectIndex + 12 * ultimateArtifactLocY * this->map.width) == 255) {
              if (*(&this->map.tiles[ultimateArtifactLocX].overlayIndex + 12 * ultimateArtifactLocY * this->map.width) == 255) {
                if (giGroundToTerrain[*(&this->map.tiles[ultimateArtifactLocY * this->map.width].groundIndex
                                        + 6 * ultimateArtifactLocX)]) {
                  if (iLastMsgNumHumanPlayers != 1)
                    break;
                  if (someSortOfLoopCount >= 200)
                    break;
                  distanceYBetweenUltimateArtifactAndHero = abs(ultimateArtifactLocY - this->heroes[this->players[0].heroesOwned[0]].y);
                  if (abs(ultimateArtifactLocX - this->heroes[this->players[0].heroesOwned[0]].x)
                      + distanceYBetweenUltimateArtifactAndHero > randomVal3)
                    break;
                }
              }
            }
          }
        }
      }
    }
    if (someSortOfLoopCount >= 400 || giUltimateArtifactBaseX <= 0)// giUABaseX changed to giUltimateArtifactBaseX
    {
      ultimateArtifactLocX = Random(9, MAP_WIDTH - 10);
      ultimateArtifactLocY = Random(9, MAP_HEIGHT - 10);
    } else {
      if (giUltimateArtifactRadius)           // giUARadius changed to giUltimateArtifactRadius
        ultimateArtifactLocXRadiusOffset = Random(-giUltimateArtifactRadius, giUltimateArtifactRadius);
      else
        ultimateArtifactLocXRadiusOffset = 0;
      ultimateArtifactLocX = ultimateArtifactLocXRadiusOffset + giUltimateArtifactBaseX;
      if (giUltimateArtifactRadius)
        ultimateArtifactLocYRadiusOffset = Random(-giUltimateArtifactRadius, giUltimateArtifactRadius);
      else
        ultimateArtifactLocYRadiusOffset = 0;
      ultimateArtifactLocY = ultimateArtifactLocYRadiusOffset + giUltimateArtifactBaseY;// giUABaseY changed to giUltimateArtifactBaseY
    }
    randomVal4 = Random(1, 30);
    randomVal5 = Random(1, 20) + randomVal4;
    randomVal3 = Random(1, 20) + randomVal5;
    ++someSortOfLoopCount;
  }
  this->ultimateArtifactLocX = ultimateArtifactLocX;// this->field_6395 changed to ultimateArtifactLocX
  this->ultimateArtifactLocY = ultimateArtifactLocY;// this->field_6396 changed to ultimateArtifactLocY
  this->ultimateArtifactIdx = Random(0, 7);     // this->field_6397 changed to ultimateArtifactIdx
  if (gbInCampaign
      && (!this->relatedToCurViewSideOrCampaign && this->relatedToCampaignMap == 7// this->field_4 changed to relatedToCampaignMap
          || this->relatedToCurViewSideOrCampaign == 1 && this->relatedToCampaignMap == 8))// this->field_2 changed to relatedToCurViewSide
    this->ultimateArtifactIdx = 6;
  for (playerIdxm = 0; this->numPlayers > playerIdxm; ++playerIdxm) {
    if (gbHumanPlayer[playerIdxm]) {
      this->players[playerIdxm].personality = 3;
      memcpy(this->players[playerIdxm].resources, giPlayerInitialResourcesHuman[this->difficulty], 28u);// unk_4F1E00 changed to giPlayerInitialResourcesHuman
      if (this->playerHandicap[playerIdxm]) {
        for (resourceType = RESOURCE_WOOD; resourceType < NUM_RESOURCES; ++resourceType) {
          if (this->playerHandicap[playerIdxm] == 1)
            resourceMultiplierFromHandicap = 0.85;
          else
            resourceMultiplierFromHandicap = 0.7;
          this->players[playerIdxm].resources[resourceType] = (signed __int64)((double)this->players[playerIdxm].resources[resourceType]
                                                                               * resourceMultiplierFromHandicap);
        }
      }
    } else {
      this->players[playerIdxm].personality = Random(0, 2);
      memcpy(this->players[playerIdxm].resources, giPlayerInitialResourcesAI[this->difficulty], 28u);// unk_4F1E90 changed to giPlayerInitialResourcesAI
    }
  }
  this->SetupAdjacentMons;
  if (this->mapHeader.lossConditionType == 2) // field_22 changed to lossConditionType
  {
    lossConditionArgumentLocX = *(_WORD *)&this->mapHeader.lossConditionArgumentOrLocX;// field_23 changed to lossConditionArgumentOrLocX
    lossConditionArgumentLocY = LOWORD(this->mapHeader.lossConditionArgumentOrLocY);// field_2E changed to relatedTo_HIWORD_Unknown_LOWORD_lossConditionArgumentOrLocY
    *(_WORD *)&this->mapHeader.lossConditionArgumentOrLocX = 0;
    if (*(&this->map.tiles[lossConditionArgumentLocX].objType + 12 * lossConditionArgumentLocY * this->map.width) == 170) {
      *(_WORD *)&this->mapHeader.lossConditionArgumentOrLocX = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[lossConditionArgumentLocX].field_4_1_1_isShadow_1_13_extraInfo + 6 * lossConditionArgumentLocY * this->map.width) >> 8) >> -5);
    } else if (*(&this->map.tiles[lossConditionArgumentLocX].objType + 12 * (lossConditionArgumentLocY - 1) * this->map.width) == 170) {
      *(_WORD *)&this->mapHeader.lossConditionArgumentOrLocX = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[lossConditionArgumentLocX].field_4_1_1_isShadow_1_13_extraInfo + 6 * (lossConditionArgumentLocY - 1) * this->map.width) >> 8) >> -5);
    } else {
      this->mapHeader.lossConditionType = 0;
    }
  }
  if (this->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_HERO) {
    relatedToWinConditionLocX = this->mapHeader.winConditionArgumentOrLocX;// winConditionArgument changed to winConditionArgumentOrLocX
    relatedToWinConditionLocY = this->mapHeader.winConditionArgumentOrLocY;// field_2C changed to winConditionArgumentOrLocY
    this->mapHeader.winConditionArgumentOrLocX = 0;
    if (*(&this->map.tiles[relatedToWinConditionLocX].objType + 12 * relatedToWinConditionLocY * this->map.width) == 170) {
      this->mapHeader.winConditionArgumentOrLocX = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[relatedToWinConditionLocX].field_4_1_1_isShadow_1_13_extraInfo
                                                                                         + 6
                                                                                         * relatedToWinConditionLocY
                                                                                         * this->map.width) >> 8) >> -5);
    } else if (*(&this->map.tiles[relatedToWinConditionLocX].objType + 12 * (relatedToWinConditionLocY - 1) * this->map.width) == 170) {
      this->mapHeader.winConditionArgumentOrLocX = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[relatedToWinConditionLocX].field_4_1_1_isShadow_1_13_extraInfo
                                                                                         + 6
                                                                                         * (relatedToWinConditionLocY - 1)
                                                                                         * this->map.width) >> 8) >> -5);
    } else {
      this->mapHeader.winConditionType = 0;
    }
  }
  for (playerIdxn = 0; this->numPlayers > playerIdxn; ++playerIdxn) {
    playerIdxnFaction = 0;
    if (this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[this->players[playerIdxn].color]] < 0
        || this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[this->players[playerIdxn].color]] >= 6)// Constant here (may be related to factions)
    {
      if (this->players[playerIdxn].numCastles) {
        playerIdxnFaction = gpGame->castles[BYTE2(this->players[playerIdxn].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx)].factionID;
      } else if (this->players[playerIdxn].numHeroes) {
        playerIdxnFaction = gpGame->heroes[this->players[playerIdxn].heroesOwned[0]].factionID;
      }
    } else {
      playerIdxnFaction = this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[this->players[playerIdxn].color]];
    }
    this->players[playerIdxn].hasEvilFaction = playerIdxnFaction == FACTION_BARBARIAN
      || playerIdxnFaction == FACTION_WARLOCK
      || playerIdxnFaction == FACTION_NECROMANCER;// playerData->_4_1 changed to hasEvilFaction
    if (gbInCampaign && !playerIdxn)          // constants for factions above
      this->players[0].hasEvilFaction = this->relatedToCurViewSideOrCampaign == 1;// field_2 changed to relatedToCurViewSideOrCampaign
    for (castlesOwnedIdx = 0; gpGame->players[playerIdxn].numCastles > castlesOwnedIdx; ++castlesOwnedIdx)
      (&gpGame->castles[*((_BYTE *)&gpGame->players[playerIdxn].relatedTo_HIBYTE_Unknown_LOBYTE_mightBeCurCastleIdx
                          + castlesOwnedIdx
                          + 2)])->GiveSpells(0);
    gpGame->players[playerIdxn].relatedToMaxOrNumHeroes = gpGame->players[playerIdxn].numHeroes;// playerData->_2 changed to relatedToMaxOrNumHeroes
  }
  gpPhilAI->GetGameAIVars();
  gbInNewGameSetup = 0;
  this->SetupNewRumour();
  gpAdvManager->CheckSetEvilInterface(0, -1);
}
// 4F0A00: using guessed type int MAP_WIDTH;
// 4F0A04: using guessed type int MAP_HEIGHT;
// 522F90: using guessed type __int16 giUltimateArtifactRadius;
// 522FB4: using guessed type __int16 giUltimateArtifactBaseX;
// 522FB8: using guessed type __int16 giUltimateArtifactBaseY;
// 5235D4: using guessed type int iLastMsgNumHumanPlayers;
// 523EDC: using guessed type int giCurWatchPlayer;
// 5304A0: using guessed type char xIsPlayingExpansionCampaign;
// 5306F0: using guessed type char giCurWatchPlayerBit;
// 532C5C: using guessed type char giCurPlayerBit;
*/
void game::NextPlayer() {
	/*
	 * Because heroes no longer regain movement on hire.
	 * we need to make sure all heroes in hero pool regain movement between turns.
	 */
	NextPlayer_orig();
	for(int i = 0; i < MAX_HEROES; i++) {
		hero *h = &this->heroes[i];
		h->mobility = h->CalcMobility();
		h->remainingMobility = h->mobility;
	}
}

void game::PerDay() {
	this->PerDay_orig();
	ScriptCallback("OnNewDay", this->month, this->week, this->day);
}

void game::ResetIronfistGameState() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = false;
        }
    }
}

extern int gbGameOver;
extern int giEndSequence;

void __fastcall CheckEndGame(int a, int b) {
  CheckEndGame_orig(a, b);
  if (gbGameOver) {
    if (giEndSequence) {
      ScriptCallback("OnMapVictory");
    } else {
      ScriptCallback("OnMapLoss");
    }
  }
}

int __fastcall HandleAppSpecificMenuCommands(int a1) {
  int spell; // [sp+24h] [bp-8h]@55
  hero *hro; // [sp+28h] [bp-4h]@1

  hro = 0;
  if (gpCurPlayer && gpCurPlayer->curHeroIdx != -1)
    hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  switch (a1) {
    case 40143: // MENUITEM "Free Spells"
      gpGame->_B[1] = 1;
      if (gbInCampaign)
        gpGame->_11[72] = 1;
      if (hro) {
        for (spell = 0; spell < NUM_SPELLS; ++spell)
          hro->AddSpell(spell, 10); // Knowledge argument "10" is redundant due to zeroing out of value in modified AddSpell
        hro->spellpoints = 999;
      }
      return 0;
    default:
      return HandleAppSpecificMenuCommands_orig(a1);
  }
}

class philAI {

	char _; // Yes, this is a 1-byte object.

public:
	void RedistributeTroops_orig(armyGroup *, armyGroup *, int, int, int, int, int);
	void RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5);
};

void philAI::RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5) {
	if (gpGame->allowAIArmySharing) {
		RedistributeTroops_orig(army1, army2, a1, a2, a3, a4, a5);
	}
}