#ifndef CAMPAIGN_XML_H
#define CAMPAIGN_XML_H

#include "campaign/campaign.h"
#include "scripting/scripting.h"
#include "tinyxml2/tinyxml2.h"
#include <vector>

namespace CampaignMetadata {
  int ReadRoot(tinyxml2::XMLNode* root);
  void QueryText(tinyxml2::XMLElement *el, char *dest);
}

class CampaignXML {
  private:
    tinyxml2::XMLDocument tempDoc = nullptr;
    int campaignID = -1;
  public:
    tinyxml2::XMLError Read(const char* fileName);
    int GetCampaignID();
    const char* GetError();
};

#endif