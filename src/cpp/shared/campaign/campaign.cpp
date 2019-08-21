#include "game/game.h"
#include "campaign/campaign.h"

extern int expCampaignNumMaps[MAX_CAMPAIGNS];

tag_rect xCampaignSelectionRects[] = {
  {215, 49, 230, 150},
  {217, 275, 230, 150},
  {475, 132, 120, 180},
  {41, 132, 120, 180},
  {480, 380, 120, 180} // right bottom corner
};

void ExpCampaign::InitNewCampaign(int var) {
  this->campaignID = var;
  this->currentMapID = -1;
  this->numMaps = expCampaignNumMaps[var];
  this->ResetMapChoices();
  this->ResetMapsPlayed();
  this->ResetAwards();
  this->ResetBonusChoices();
}

CAMPAIGN_TYPE GetCurrentCampaignType() {
  if(xIsPlayingExpansionCampaign)
    return CAMPAIGN_TYPE_EXPANSION;
  else if(gbInCampaign)
    return CAMPAIGN_TYPE_ORIGINAL;
  else
    return CAMPAIGN_TYPE_NONE;
}

int __fastcall ExpansionCampaignRect(int x, int y) {
  for(int i = 0; i < ELEMENTS_IN(xCampaignSelectionRects); i++) {
    if(PointInRect(x, y, &xCampaignSelectionRects[i]))
      return i;
  }
  return -1;
}

SMACKER_VIDEOS GetCampaignRectangleSmackerVideo(int rectID) {
  SMACKER_VIDEOS rectToSMK[] = {
    SMACKER_XCAMPAIGN_PREVIEW_PRICE_OF_LOALTY,
    SMACKER_XCAMPAIGN_PREVIEW_DESCENDANTS,
    SMACKER_XCAMPAIGN_PREVIEW_WIZARDS_ISLE,
    SMACKER_XCAMPAIGN_PREVIEW_VOYAGE_HOME,
    SMACKER_XCAMPAIGN_PREVIEW_WIZARDS_ISLE // dummy
  };
  return rectToSMK[rectID];
}

int ExpCampaign::HandleVictory() {
  short days = 0;
  if(this->currentMapID > -1) {
    days = this->Days();
    this->mapsPlayed[this->currentMapID] = 1;
  }
  memset(this->mapChoice, 0, this->numMaps);
  unsigned int campID = this->campaignID;
  if(campID < MAX_CAMPAIGNS) {
    switch(campID) {
      case 0u:
        this->HandleVictory1();
        break;
      case 1u:
        this->HandleVictory2();
        break;
      case 2u:
        this->HandleVictory3();
        break;
      case 3u:
        this->HandleVictory4();
        break;
      default:
        break;
    }
  }

  bool result;
  if(this->IsCompleted()) {
    result = 0;
  } else {
    this->currentMapID = -1;
    for(int i = 0; i < this->numMaps; ++i) {
      if(this->mapChoice[i]) {
        this->daysPlayed[i] = days;
        if(this->currentMapID == -1)
          this->currentMapID = i;
      }
    }
    this->ShowInfo(false, 0);
    result = gpWindowManager->buttonPressedCode == BUTTON_OK;
  }
  return result;
}