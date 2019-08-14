#include "campaign/campaign.h"

extern int expCampaignNumMaps[4];

void ExpCampaign::InitNewCampaign(int var) {
  this->campaignID = var;
  this->currentMapID = -1;
  this->numMaps = expCampaignNumMaps[var];
  this->ResetMapChoices();
  this->ResetMapsPlayed();
  this->ResetAwards();
  this->ResetBonusChoices();
}