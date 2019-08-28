#ifndef IRONFIST_XML_H
#define IRONFIST_XML_H

#include "campaign/campaign.h"
#include "scripting/scripting.h"
#include "tinyxml2/tinyxml2.h"
#include <vector>

class IronfistXML {
private:
  tinyxml2::XMLDocument tempDoc = nullptr;
public:
  void Save(const char* fileName);
  void Read(const char* fileName);
  private:
    template<typename T>
    void PushBack(tinyxml2::XMLNode *dest, const char* name, const T &val) {
      tinyxml2::XMLElement *elem = tempDoc.NewElement(name);
      elem->SetText(val);
      dest->InsertEndChild(elem);
    }
    template<typename T>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const T &src) {
      for(int i = 0; i < ELEMENTS_IN(src); i++) {
          tinyxml2::XMLElement *elem = tempDoc.NewElement(name);
          elem->SetAttribute("index", i);
          elem->SetAttribute("value", src[i]);
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::vector<int> &src) {
      for(int i = 0; i < src.size(); i++) {
          tinyxml2::XMLElement *elem = tempDoc.NewElement(name);
          elem->SetAttribute("index", i);
          elem->SetAttribute("value", src[i]);
          dest->InsertEndChild(elem);
        }
    }
    template<typename T>
    void WriteCampaignDDArray(tinyxml2::XMLNode *dest, const char* name, const T &src) {
      for(int i = 0; i < ELEMENTS_IN(src); i++)
          for(int j = 0; j < ELEMENTS_IN(src[i]); j++) {
              tinyxml2::XMLElement *elem = tempDoc.NewElement(name);
              elem->SetAttribute("campID", i);
              elem->SetAttribute("mapID", j);
              elem->SetAttribute("value", (int)src[i][j]);
              dest->InsertEndChild(elem);
            }
    }
    luaTable *ReadTable(tinyxml2::XMLNode *root);
    void WriteMapVarTable(tinyxml2::XMLNode *dest, std::string id, luaTable *lt);
    void WriteMapVariables(tinyxml2::XMLNode *dest);
    tinyxml2::XMLError QueryShortText(tinyxml2::XMLElement *el, short *dest);
    tinyxml2::XMLError QueryCharText(tinyxml2::XMLElement *el, char *dest);
    void QueryText(tinyxml2::XMLElement *el, char *dest);
    void ReadCampaign(tinyxml2::XMLNode* root, CAMPAIGN_TYPE campaignType);
    void ReadMapHeader(tinyxml2::XMLNode* root);
    void ReadMap(tinyxml2::XMLNode* root);
    void ReadMapExtra(tinyxml2::XMLNode* root);
    void ReadPlayerData(tinyxml2::XMLNode* root, int dataIndex);
    void ReadHero(tinyxml2::XMLNode* root, int heroIndex);
    void ReadTown(tinyxml2::XMLNode* root, int townIdx);
    void ReadRoot(tinyxml2::XMLNode* root);
};

#endif