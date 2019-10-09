#ifndef SAVE_XML_H
#define SAVE_XML_H

#include "campaign/campaign.h"
#include "scripting/scripting.h"
#include "xml/utils_xml.h"
#include <set>
#include <vector>

class IronfistXML : public UtilsXML::XMLFile {
  public:
    tinyxml2::XMLError Save(const char* fileName);
    tinyxml2::XMLError Read(const char* fileName);
  private:
    luaTable *ReadTable(tinyxml2::XMLNode *root);
    void ReadTableElement(tinyxml2::XMLElement *elem, luaTable *lt);
    void WriteMapVarTable(tinyxml2::XMLNode *dest, std::string id, luaTable *lt);
    void WriteMapVariables(tinyxml2::XMLNode *dest);
    void ReadCampaign(tinyxml2::XMLNode* root, CAMPAIGN_TYPE campaignType);
    void ReadCampaignSavedHero(tinyxml2::XMLNode* root);
    void ReadMapHeader(tinyxml2::XMLNode* root);
    void ReadMap(tinyxml2::XMLNode* root);
    void ReadMapExtra(tinyxml2::XMLNode* root);
    void ReadPlayerData(tinyxml2::XMLNode* root, int dataIndex);
    void ReadHero(tinyxml2::XMLNode* root, int heroIndex);
    void ReadTown(tinyxml2::XMLNode* root, int townIdx);
    void ReadRoot(tinyxml2::XMLNode* root);
};

#endif