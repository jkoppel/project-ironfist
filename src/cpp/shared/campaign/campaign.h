#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <map>
#include <set>

#include "adventure/adv.h"
#include "gui/gui.h"
#include "smacker.h"

#pragma pack(push, 1)

#define MAX_MAPS_IN_CAMPAIGN 8
#define MAX_CAMPAIGN_CHOICES 3
#define MAX_CAMPAIGN_AWARDS 11

enum CAMPAIGN_TYPE {
  CAMPAIGN_TYPE_NONE = 0,
  CAMPAIGN_TYPE_ORIGINAL = 1,
  CAMPAIGN_TYPE_EXPANSION = 2
};

enum CAMPAIGN_CHOICE_TYPES {
  CAMPAIGN_CHOICE_RESOURCE = 0,
  CAMPAIGN_CHOICE_ARTIFACT = 1,
  CAMPAIGN_CHOICE_SPELL = 2,
  CAMPAIGN_CHOICE_SECONDARY_SKILL = 3,
  CAMPAIGN_CHOICE_ARMY = 4,
  CAMPAIGN_CHOICE_PUZZLE_PIECES = 5,
  CAMPAIGN_CHOICE_EXPERIENCE = 6,
  CAMPAIGN_CHOICE_NOT_AVAILABLE = 7,
  CAMPAIGN_CHOICE_ALIGNMENT = 8,
  CAMPAIGN_CHOICE_PRIMARY_SKILL = 9,
  CAMPAIGN_CHOICE_SPELL_SCROLL = 10,
  NUM_CAMPAIGN_CHOICE_TYPES = 11
};

struct SCampaignChoice {
  char type;
  short field;
  short amount;
};

class ExpCampaign {
public:
  int campaignID;
  int currentMapID;
  int numMaps;
  char mapChoice[MAX_MAPS_IN_CAMPAIGN];
  char mapsPlayed[MAX_MAPS_IN_CAMPAIGN];
  short daysPlayed[MAX_MAPS_IN_CAMPAIGN];
  char awards[MAX_CAMPAIGN_AWARDS];
  char bonusChoices[MAX_MAPS_IN_CAMPAIGN];
  int unknownVariable;
  int mightBeScenarioID;
  heroWindow* window;
  int anIntVariable;

  ExpCampaign();

  void InitNewCampaign(int var);
  void ResetMapChoices();
  void ResetMapsPlayed();
  void ResetAwards();
  void ResetBonusChoices();

  char HasAward(int a2);
  char *JosephName();
  char *IvanName();
  int HandleVictory();
  void HandleVictory1();
  void HandleVictory2();
  void HandleVictory3();
  void HandleVictory4();
  void HandleVictoryCustomCampaign();
  void ReplaySmacker();
  void ReplaySmacker1();
  void ReplaySmacker2();
  void ReplaySmacker3();
  void ReplaySmacker4();
  void ReplaySmackerCustomCampaign();
  unsigned char IsCompleted();
  short Days();
  void ShowInfo(int inGame, int unused);
  void InitMap();
  void UpdateInfo(int);
  void Autosave();
  int Choose();

private:
    static int __fastcall MessageHandler(struct tag_message &);
};

CAMPAIGN_TYPE GetCurrentCampaignType();
SMACKER_VIDEOS GetCampaignRectangleSmackerVideo(int rectID);
extern ExpCampaign xCampaign;
extern int __fastcall ExpLoadCampaignHandler(struct tag_message &);

int __fastcall ExpansionCampaignRect(int x, int y);
int LoadCampaignFromFile(std::string filename);
void LoadCampaignSavedHero(int playerID, int ownedHeroIdx, int saveIdx);
void SaveCampaignHero(int playerID, int ownedHeroIdx, int saveIdx);

extern std::map<int, std::string> xCampaignNames;
extern std::map<int, std::string> xShortCampaignNames;
extern std::map<int, std::map<int, Point>> scenarioIconOffsets;
extern std::map<int, SMACKER_VIDEOS> rectToSMK;
extern std::map<int, tag_rect> xCampaignSelectionRects;
extern std::map<int, std::map<int, std::map<int, SCampaignChoice>>> xCampaignChoices;
extern std::map<int, int> expCampaignNumMaps;
extern std::map<int, std::map<int, std::string>> xScenarioName;
extern std::map<int, std::map<int, std::string>> xScenarioDescription;
extern std::map<int, std::map<int, int>> xCampaignDifficulties;
extern std::map<int, std::map<int, std::set<int>>> mapsToComplete;
extern std::map<int, std::map<int, SMACKER_VIDEOS>> replaySMK;
extern std::map<int, std::map<int, SMACKER_VIDEOS>> victorySMK;
extern std::map<int, std::map<int, int>> awardsToGive;
extern std::map<int, std::map<int, std::set<std::pair<int, int>>>> xCampaignHeroesToLoad;
extern std::map<int, std::map<int, std::set<std::pair<int, int>>>> xCampaignHeroesToSave;

#pragma pack(pop)

#endif
