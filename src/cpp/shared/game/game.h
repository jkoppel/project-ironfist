#ifndef GAME_H
#define GAME_H

#include "adventure/adv.h"
#include "adventure/map.h"
#include "artifacts.h"
#include "combat/army.h"
#include "town/town.h"

#define NUM_PLAYERS 6
#define MAX_HEROES 54
#define MAX_TOWNS 72
#define MAX_BOATS 48
#define NUM_DIFFICULTIES 5

extern signed char gcColorToPlayerPos[];

extern int gbHumanPlayer[];

#pragma pack(push,1)

extern char* gAlignmentNames[];

extern H2RECT gMapViewportRegion;

#define BUILDING_RIGHT_TURRET_BUILT     0x1
#define BUILDING_LEFT_TURRET_BUILT      0x2
#define BUILDING_SPECIAL_DEFENSE_BUILT  0x20

enum WIN_CONDITION_TYPES {
  WIN_CONDITION_CAPTURE_CASTLE = 0x1,
  WIN_CONDITION_DEFEAT_HERO = 0x2,
  WIN_CONDITION_FIND_ARTIFACT = 0x3,
  WIN_CONDITION_DEFEAT_COLOR = 0x4,
  WIN_CONDITION_ACCUMULATE_GOLD = 0x5,
};

extern void __fastcall KBChangeMenu(void*);
extern void *hmnuRecruitSave;
extern void *hmnuCurrent;
extern void *hmnuDflt;

enum MOUSE_CURSOR_CATEGORY {
  MOUSE_CURSOR_CATEGORY_ADVENTURE = 0x0,
  MOUSE_CURSOR_CATEGORY_COMBAT = 0x1,
  MOUSE_CURSOR_CATEGORY_SPELL = 0x2,
};

class mouseManager : public baseManager {
public:
	bitmap *bitmap;
  int spriteIdx;
  icon *cursorIcon;
  MOUSE_CURSOR_CATEGORY cursorCategory;
  int cursorIdx;
  int field_4A;
  int field_4E;
  int field_52;
  int field_56;
  int field_5A;
  int cursorTopLeftX;
  int cursorTopLeftY;
  int field_66;
  int field_6A;
  int field_6E;
  int field_72;
  int cursorWidth;
  int cursorHeight;
  int field_7E;
  int couldBeShowMouse;
  int cursorDisabled;

	mouseManager();
	void ShowColorPointer();
  void SetPointer(char *mse, int spriteIdx, int protoCategory);
};

extern mouseManager* gpMouseManager;

class playerData {
public:
	char color;
	char numHeroes;
	char curHeroIdx;
	char relatedToSomeSortOfHeroCountOrIdx;
	char heroesOwned[8];
	char heroesForPurchase[2];
	char relatedToMaxOrNumHeroes;
	int personality;
	char _3[45];
	char field_40;
	__int16 field_41;
	char daysLeftWithoutCastle;
	char numCastles;
  __int8 mightBeCurCastleIdx;
  __int8 relatedToUnknown;
	char castlesOwned[MAX_TOWNS];
	int resources[7];
  char hasEvilFaction;
  char barrierTentsVisited;
  char _4_2[58];
	int field_E7[7];
	char _5[23];
	char field_11A;

	int HasMobileHero();

	void Read(int);
	void Write(int);
};

extern int giCurPlayer;
extern playerData* gpCurPlayer;

struct mine
{
	char field_0;
	char owner;
	char type;
	char guardianType;
	char guardianQty;
	char x;
	char y;
};

struct boat
{
	char idx;
	char x;
	char y;
	char field_3;
	char underlyingObjType;
	char underlyingObjExtra;
	char field_6;
	char owner;
};

struct randomHeroCreatureInfo {
  enum CREATURES creatureType;
  int lowQuantity;
  int highQuantity;
};

class game {
public:
	__int16 gameDifficulty;
	char relatedToCurViewSideOrCampaign;
	char field_3;
	char relatedToCampaignMap;
	char _1[120];
	char field_7D;
	char hasDwarfAlliance;
	char maybeIsGoodCampaign;
	char field_80;
	char field_81;
	char field_82;
	char field_83;
	char field_84;
	char field_85;
	char isDwarfbane;
	char hasDragonAlliance;
	char field_88;
	char _11[193];
	char lastSaveFile[251];
	char _12[100];
	SMapHeader mapHeader;
	char relatedToPlayerPosAndColor[NUM_PLAYERS];
	char playerHandicap[NUM_PLAYERS];
	char newGameSelectedFaction[NUM_PLAYERS];
	char somePlayerCodeOr10IfMayBeHuman[NUM_PLAYERS];
	char difficulty;
	char mapFilename[40];
	char numPlayers;
	char couldBeNumDefeatedPlayers;
	char playerDead[NUM_PLAYERS];
	__int16 day;
	__int16 week;
	__int16 month;
	playerData players[NUM_PLAYERS];
	fullMap map;
	char numObelisks;
	town castles[MAX_TOWNS];
	char field_2773[72];
	char builtToday[9];
	hero heroes[MAX_HEROES];
	char relatedToHeroForHireStatus[54];
	mine mines[144];
	char field_60A6[144];
	char artifactGeneratedRandomly[103];
	boat boats[48];
	char boatBuilt[48];
	char obeliskVisitedMasks[48];
	char field_637D[24];
	char ultimateArtifactLocX;
	char ultimateArtifactLocY;
	char ultimateArtifactIdx;
	heroWindow* newGameWindow;
	char _B[14];
	char currentRumor[301];
	__int16 numRumors;
	__int16 rumorIndices[30];
	__int16 numEvents;
	char eventIndices[60];
	char _C[40];
	__int16 field_657B;
	char _D[140];
	int (__thiscall *callback)(tag_message *);
	char field_660D;
	char field_660E;

  // New state
  bool sharePlayerVision[NUM_PLAYERS][NUM_PLAYERS];
	// AI redistribute troops toggle
	bool allowAIArmySharing = true;
  // Used for OnMapStart
  bool firstDayEventDone = false;

	int SetupGame();
	int SetupGame_orig();
	void SetupTowns();

	void RandomizeHeroPool();

	int GetRandomNumTroops(int);
	void InitNewGame(struct SMapHeader *a);
	void InitNewGame_orig(struct SMapHeader *a);
	void LoadGame(char*, int, int);
	void LoadGame_orig(char*, int, int);
	void NewMap(char*);
	void NewMap_orig(char*);
	int SaveGame(char*, int, signed char);
	void SetupOrigData();
	void SetMapSize(int, int);
	void SetupAdjacentMons();
	void SetVisibility(int,int,int,int);
  void SetVisibility_orig(int, int, int, int);

	void ClaimTown(int,int,int);
  int GetTownId(int,int);
  
	void NextPlayer();
	void NextPlayer_orig();

	void PerDay();
	void PerDay_orig();
  void PerWeek();
  void PerWeek_orig();
  void PerMonth();
  void PerMonth_orig();

  void ResetIronfistGameState();
  void ShareVision(int sourcePlayer, int destPlayer);
  void CancelShareVision(int sourcePlayer, int destPlayer);
	
  void MakeAllWaterVisible(int player);
  void MakeAllWaterVisible_orig(int player);

  void InitRandomArtifacts();
  int GetRandomArtifactId(int allowedLevels, int allowNegatives);
  int LoadMap(char *nam);
  void ProcessRandomObjects();
  int ProcessMapExtra();
  void __cdecl InitializePasswords();
  int RandomizeEvents();
  void ProcessOnMapHeroes();
  int GetNewHeroId(int playerIdx, signed int faction, int getPowerfulHero);
  void SetupNewRumour();
  void GiveArmy(class armyGroup *, int, int, int);

  void SetRandomHeroArmies(int heroIdx, int isAI);
  void GiveTroopsToNeutralTown(int castleIdx);
  int RandomScan(signed char*, int, int, int, signed char);
  int GetBoatsBuilt();
  int CreateBoat(int x, int y, int doSend);
  void ViewArmy(int unused, int unused2, int creature, int numTroops, town *twn, int a7, int a8, int a9, hero *hro, army *arm, armyGroup *armyGr, int creatureType);
  int getNumberOfThievesGuilds(int playerIdx);
  void UpdateNewGameWindow();
  void RandomizeTown(int argX, int argY, int mightBeUseless);
  void ConvertObject(int x1, int y1, int x2, int y2, int fromObjTileset, signed int fromObjIndexLow, signed int fromObjIndexHigh, int toObjTileset, int toObjectIndexLow, int fromObjType, int toObjType);
  void ShowScenInfo();
  int CalcDifficultyRating();
  void DrawNGKPDisplayString(int updateScreen);
  void GetLossConditionText(char *text);
  void GetVictoryConditionText(char *text);
  void RandomizeMine(int x, int y);

private:
  void PropagateVision();
};

enum GAME_DIFFICULTY {
	DIFFICULTY_EASY = 0,
	DIFFICULTY_NORMAL = 1,
	DIFFICULTY_HARD = 2,
	DIFFICULTY_EXPERT = 3,
	DIFFICULTY_IMPOSSIBLE = 4,
};

enum PERSONALITY_TYPE {
  PERSONALITY_WARRIOR = 0,
  PERSONALITY_BUILDER = 1,
  PERSONALITY_EXPLORER = 2,
  PERSONALITY_HUMAN = 3,
};

extern void __fastcall CheckEndGame_orig(int a, int b);
void __fastcall CheckEndGame(int a, int b);

int __fastcall HandleAppSpecificMenuCommands(int a1);
int __fastcall HandleAppSpecificMenuCommands_orig(int a1);

bool IsWellDisabled();

extern game* gpGame;
extern int gbInCampaign;

extern int gbGameOver;

extern __int16 giUltimateArtifactBaseX;
extern __int16 giUltimateArtifactBaseY;
extern __int16 giUltimateArtifactRadius;

extern char gpcBeforeGSpellLimits[];
extern int giPlayerInitialResourcesHuman[NUM_DIFFICULTIES][NUM_RESOURCES];
extern int giPlayerInitialResourcesAI[NUM_DIFFICULTIES][NUM_RESOURCES];

extern int __fastcall FindLastToken(const char *a1, char a2);
extern char __fastcall StrEqNoCase(int *a1, int *a2);

extern int gbInNewGameSetup;
extern int iLastMsgNumHumanPlayers;
extern bool gbSetupGamePosToRealGamePos[];
extern signed char gcColorToSetupPos[];
extern signed char giVisRange[];
extern unsigned char xIsPlayingExpansionCampaign;
extern int giCurTurn;
extern int giMonthType;
extern int giMonthTypeExtra;
extern unsigned char randomMineResources[NUM_RESOURCES];

extern randomHeroCreatureInfo randomHeroArmyBounds[MAX_FACTIONS][2];
extern int neutralTownCreatureTypes[MAX_FACTIONS][5];

extern signed __int8 gHeroSkillBonus[MAX_FACTIONS][2][4];

extern int getCastleOwnedIdx(playerData *player, int castleIdx);
int __fastcall NewGameHandler(tag_message &msg);
extern int __fastcall NewGameHandler_orig(tag_message &msg);
int __fastcall TransmitRemoteData(char*, int, int, signed char a4, signed char a5, signed char a6, signed char a7);

#pragma pack(pop)

#endif
