#ifndef GAME_H
#define GAME_H

#include "adventure/adv.h"
#include "town/town.h"

#define MAX_HEROES 54
#define MAX_TOWNS 72

extern signed char gcColorToPlayerPos[];

extern int gbHumanPlayer[];

#pragma pack(push,1)

enum FACTION
{
	FACTION_KNIGHT = 0x0,
	FACTION_BARBARIAN = 0x1,
	FACTION_SORCERESS = 0x2,
	FACTION_WARLOCK = 0x3,
	FACTION_WIZARD = 0x4,
	FACTION_NECROMANCER = 0x5,
	FACTION_MULTIPLE = 0x6,
	FACTION_RANDOM = 0x7,
};

struct mapCell;
struct mapCellExtra;

class fullMap {
public:
	mapCell *tiles;
	mapCellExtra *cellExtras;
	int width;
	int height;
	int numCellExtras;
	fullMap();
	~fullMap();

	void Read(int,int);
	void Write(int);
};

struct SMapHeader {
	int field_0;
	__int16 field_4;
	char width;
	char height;
	char hasPlayer[6];
	char playerMayBeHuman[6];
	char playerMayBeComp[6];
	char numPlayers;
	char minHumans;
	char maxHumans;
	char winConditionType;
	char field_1E;
	char allowDefeatAllVictory;
	__int16 winConditionArgument;
	int field_22;
	char playerFactions[6];
	__int16 field_2C;
	int field_2E;
	int field_32;
	char field_36;
	char field_37;
	char field_38;
	char field_39;
	char name[60];
	char description[298];
	char field_1A0;
	char field_1A1;
	char numRumors;
	char numEvents;
};


#define BUILDING_RIGHT_TURRET_BUILT     0x1
#define BUILDING_LEFT_TURRET_BUILT      0x2
#define BUILDING_SPECIAL_DEFENSE_BUILT  0x20


class playerData {
public:
	char color;
	char numHeroes;
	char curHeroIdx;
	char field_3;
	char heroesOwned[8];
	char heroesForPurchase[2];
	char _2;
	int personality;
	char _3[45];
	char field_40;
	__int16 field_41;
	char field_43;
	char numCastles;
	__int16 field_45;
	char castlesOwned[MAX_TOWNS];
	int resources[7];
	char _4[60];
	int field_E7[7];
	char _5[23];
	char field_11A;

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
	char guadianQty;
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

class game {
public:
	__int16 gameDifficulty;
	char field_2;
	char field_3;
	char field_4;
	char _1[120];
	char field_7D;
	char hasDwarfAlliance;
	char field_7F;
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
	int field_44D;
	__int16 field_451;
	char playerHandicap[6];
	char field_459[6];
	char field_45F[6];
	char difficulty;
	char mapFilename[40];
	char numPlayers;
	char couldBeNumDefeatedPlayers;
	char playerDead[6];
	__int16 day;
	__int16 week;
	__int16 month;
	playerData players[6];
	fullMap map;
	char numObelisks;
	town castles[MAX_TOWNS];
	char field_2773[72];
	char field_27BB[9];
	hero heroes[MAX_HEROES];
	char relatedToHeroForHireStatus[54];
	mine mines[144];
	char field_60A6[144];
	char artifactGeneratedRandomly[103];
	boat boats[48];
	char boatBuilt[48];
	char obeliskVisitedMasks[48];
	char field_637D[24];
	char field_6395;
	char field_6396;
	char field_6397;
	int field_6398;
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

	int SetupGame();
	int SetupGame_orig();
	void SetupTowns();

	void RandomizeHeroPool();
	void SetRandomHeroArmies(int,int);

	int GetRandomNumTroops(int);
	void GiveTroopsToNeutralTown(int);
	void LoadGame(char*, int, int);
	void LoadGame_orig(char*, int, int);
	void NewMap(char*);
	void NewMap_orig(char*);
	int SaveGame(char*, int, signed char);
	void SetupOrigData();
	void SetMapSize(int, int);
	void SetupAdjacentMons();
	void SetVisibility(int,int,int,int);

	void ClaimTown(int,int,int);

	void NextPlayer();
	void NextPlayer_orig();

	void PerDay();
	void PerDay_orig();
};

extern game* gpGame;

extern int gbGameOver;

#pragma pack(pop)

#endif