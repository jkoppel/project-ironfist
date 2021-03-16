#ifndef TOWN_H
#define TOWN_H

#include "adventure/adv.h"
#include "town/town_globals.h"

#pragma pack(push,1)

extern signed char gSpellLimits[];
// Remember build screen 3x9 ?
#define NUM_BUILDING_SLOTS 18
extern unsigned char castleSlotsUse[NUM_BUILDING_SLOTS];
extern unsigned char castleSlotsBase[NUM_BUILDING_SLOTS];
extern char* cHeroTypeShortName[MAX_FACTIONS];
extern char *gStatNames[NUM_PRIMARY_SKILLS];
extern int gHeroGoldCost;
extern int gMageBuildingCosts[][NUM_RESOURCES];
extern int gNeutralBuildingCosts[][NUM_RESOURCES];
extern int xShrineBuildingCost[NUM_RESOURCES];

class town {
public:
  char idx;
  char ownerIdx;
  char alignment;
  char factionID;
  char x;
  char y;
  char buildDockRelated;
  char boatCell;
  armyGroup garrison;
  char visitingHeroIdx;
  unsigned int buildingsBuiltFlags;
  char mageGuildLevel;
  char field_1D;
  __int16 numCreaturesInDwelling[NUM_DWELLINGS];
  char exists;
  char mayNotBeUpgradedToCastle;
  char field_38;
  char playerPos;
  __int16 extraIdx;
  char mageGuildSpells[5][4];
  char numSpellsOfLevel[5];
  __int16 field_55;
  char name[12];
  char field_63;

  town();

  void GiveSpells(hero *captain);
  void SelectSpells();
  void SetNumSpellsOfLevel(int,int);
  int CanBuildDock();
  void CalcNumLevelArchers(int *numArchers, int *attack);

  void BuildBuilding(int);
  bool BuildingBuilt(int) const;
  bool DwellingBuilt(int) const;
  bool IsDisallowed(int) const;

  // Get the index of the most upgraded building built at the given tier.
  // Returns integer in range [0, NUM_DWELLINGS), or -1 for an invalid
  // tier outside range [0, 5].
  int DwellingIndex(int) const;

  void SetFaction(FACTION faction);
};

class townObject {
public:
  int animationLength;
  int animationIdx;
  int built;
  int buildingCode;
  icon *icon;
  border *guiElement;
  townObject(int faction, int buildingCode, char *filename);
  ~townObject();
};

class townManager : public baseManager {
public:
  town* castle;
  icon *couldBeBackground;
  townObject *buildingDisplays[32];
  int curBuilding;
  int factionID;
  int field_C6;
  heroWindow *townScreen;
  strip *garrisonDisplay;
  strip *visitingArmyDisplay;
  strip *currentDisplay;
  int currentCreature;
  strip *field_DE;
  int field_E2;
  strip *field_E6;
  int field_EA;
  bankBox *bankbox;
  char infoMessage[80];
  int field_142;
  int field_146;
  int field_14A;
  int isRecruitingHero;
  int canBuyFlags;
  int canBuildFlags;
  int field_15A;
  int buildingToBuild;
  heroWindow *curScreen;
  heroWindow *dialog;
  int field_16A;
  int field_16E;
  int recruitHeroConfirmed;
  hero *heroBeingRecruited;
  townManager();

  void BuildObj(signed int);

  int Main(tag_message&);
  virtual int Open(int);
  int Open_orig(int);
  void SetupMage(heroWindow*);
  void SetupWell(heroWindow*);
  void SetupWell_orig(heroWindow*);

  int RecruitHero(int,int);
  int RecruitHero_orig(int,int);
  void RedrawTownScreen();
  void SetCommandAndText(struct tag_message &evt);
  void DrawTown(int a2, int a3);
  void UnloadTown();
  void ChangeTown();
  void SetupCastle(heroWindow *window, int a3);
  void SetupThievesGuild(heroWindow *window, int strength);
  void DoTavern();
  int BuyBuild(int building, int notEnoughResources, int isRightClick);
  int BuyBuild_orig(int building, int notEnoughResources, int isRightClick);
  void DoCommand(int cmd);
  void ShiftQualChange();
  void SetupExtraStuff();
  void ShowText(char *msg);
};

void InitializeTownConstants();

char *__fastcall GetBuildingName(int faction, int building);
char * __fastcall GetBuildingInfo(int faction, int building, int withTitle);
char * __fastcall GetBuildingInfo_orig(int faction, int building, int withTitle);
int GetDwellingType(int faction, int dwellingIndex);
char * GetDwellingName(int faction, int dwellingIndex);
extern char*__fastcall GetTownName(int idx);
extern void __fastcall QuickViewRecruit(town *castle, int dwellingIdx);
extern int __fastcall MageGuildHandler(tag_message &evt);
extern int __fastcall CastleHandler(tag_message &evt);
extern int __fastcall CanBuy(town *twn, int building);
int __fastcall CanBuild(town *twn, int building);
extern void __fastcall DoTradingPost(int isMarket, float efficiency);

extern townManager* gpTownManager;

#pragma pack(pop)

#endif
