#include "campaign/campaign.h"

extern int dword_512A30[4];

void ExpCampaign::InitNewCampaign(int var) {
  this->campaignID = var;
  this->currentMapID = -1;
  this->mightBeNumberOfMaps = dword_512A30[var];
  this->ResetMapChoices();
  this->ResetMapsPlayed();
  this->ResetAwards();
  this->ResetBonusChoices();
}