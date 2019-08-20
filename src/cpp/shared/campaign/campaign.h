#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#pragma pack(push, 1)

#define MAX_MAPS_IN_CAMPAIGN 8
#define MAX_CAMPAIGNS 4
#define MAX_CAMPAIGN_CHOICES 3

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
  CAMPAIGN_CHOICE_SPELL_SCROLL = 10
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
  char awards[11];
  char bonusChoices[MAX_MAPS_IN_CAMPAIGN];
  int unknownVariable;
  int mightBeScenarioID;
  int window;
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
  
};

CAMPAIGN_TYPE GetCurrentCampaignType();
extern ExpCampaign xCampaign;
extern SCampaignChoice xCampaignChoice[MAX_CAMPAIGNS][MAX_MAPS_IN_CAMPAIGN][MAX_CAMPAIGN_CHOICES];

int __fastcall ExpansionCampaignRect(int x, int y);

#pragma pack(pop)

#endif