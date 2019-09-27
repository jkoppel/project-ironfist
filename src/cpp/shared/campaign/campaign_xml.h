#ifndef CAMPAIGN_XML_H
#define CAMPAIGN_XML_H

#include "campaign/campaign.h"
#include "scripting/scripting.h"
#include "tinyxml2/tinyxml2.h"
#include <vector>

class CampaignXML {
private:
  tinyxml2::XMLDocument tempDoc = nullptr;
  int campaignID = -1;
public:
  tinyxml2::XMLError Read(const char* fileName);
  int GetCampaignID();
  const char* GetError();
  private:
    tinyxml2::XMLError QueryShortText(tinyxml2::XMLElement *el, short *dest);
    void QueryText(tinyxml2::XMLElement *el, char *dest);
    void QueryText(tinyxml2::XMLElement *el, std::string &dest);
    void ReadRoot(tinyxml2::XMLNode* root);
};

#endif