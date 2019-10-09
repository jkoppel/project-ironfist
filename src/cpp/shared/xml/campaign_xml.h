#ifndef CAMPAIGN_XML_H
#define CAMPAIGN_XML_H

#include "xml/utils_xml.h"

class CampaignXML : public UtilsXML::XMLFile {
  private:
    int campaignID = -1;
  public:
    tinyxml2::XMLError Read(const char* fileName);
    int GetCampaignID();
};

int ReadCampaignMetadata(tinyxml2::XMLNode* root);
void WriteCampaignMetadata(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* root);

#endif