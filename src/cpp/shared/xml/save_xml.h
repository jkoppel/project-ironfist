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
    template<typename T>
    void PushBack(tinyxml2::XMLNode *dest, const char* name, const T &val) {
      tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
      elem->SetText(val);
      dest->InsertEndChild(elem);
    }
    template<typename T>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const T &src) {
      for(int i = 0; i < ELEMENTS_IN(src); i++) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i);
          elem->SetAttribute("value", src[i]);
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::vector<int> &src) {
      for(int i = 0; i < src.size(); i++) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i);
          elem->SetAttribute("value", src[i]);
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::string> &src) {
      for(auto &i : src) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i.first);
          elem->SetAttribute("value", i.second.c_str());
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::map<int, int> &src) {
      for(auto &i : src) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i.first);
          elem->SetAttribute("value", i.second);
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::map<int, SMACKER_VIDEOS> &src) {
      for(auto &i : src) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i.first);
          elem->SetAttribute("value", i.second);
          dest->InsertEndChild(elem);
        }
    }
    template<>
    void WriteArray(tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::set<int>> &src) {
      for(auto &i : src) {
        for(auto val : i.second) {
          tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
          elem->SetAttribute("index", i.first);
          elem->SetAttribute("value", val);
          dest->InsertEndChild(elem);
        }
      }
    }
    template<typename T>
    void WriteCampaignDDArray(tinyxml2::XMLNode *dest, const char* name, const T &src) {
      for(int i = 0; i < ELEMENTS_IN(src); i++)
          for(int j = 0; j < ELEMENTS_IN(src[i]); j++) {
              tinyxml2::XMLElement *elem = tempDoc->NewElement(name);
              elem->SetAttribute("campID", i);
              elem->SetAttribute("mapID", j);
              elem->SetAttribute("value", (int)src[i][j]);
              dest->InsertEndChild(elem);
            }
    }
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