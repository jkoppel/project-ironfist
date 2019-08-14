#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#pragma pack(push, 1)

class ExpCampaign {
public:
  int campaignID;
  int currentMapID;
  int numMaps;
  char mapChoice[8];
  char mapsPlayed[8];
  short daysPlayed[8];
  char awards[11];
  char bonusChoices[8];
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


extern ExpCampaign xCampaign;

#pragma pack(pop)

#endif