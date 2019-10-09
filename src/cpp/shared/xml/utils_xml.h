#ifndef UTILS_XML_H
#define UTILS_XML_H

#include "smacker.h"
#include "tinyxml2/tinyxml2.h"

#include <map>
#include <set>
#include <string>
#include <vector>

namespace UtilsXML {
  tinyxml2::XMLError QueryShortText(tinyxml2::XMLElement *el, short *dest);
  tinyxml2::XMLError QueryCharText(tinyxml2::XMLElement *el, char *dest);
  void QueryText(tinyxml2::XMLElement *el, char *dest);
  void QueryText(tinyxml2::XMLElement *el, std::string &dest);
  template<typename T>
  void PushBack(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const T &val) {
    tinyxml2::XMLElement *elem = doc->NewElement(name);
    elem->SetText(val);
    dest->InsertEndChild(elem);
  }
  template <typename T>
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const T &src) {
    for(int i = 0; i < ELEMENTS_IN(src); i++) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i);
        elem->SetAttribute("value", src[i]);
        dest->InsertEndChild(elem);
      }
  }
  template <>
  inline void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::vector<int> &src) {
    for(int i = 0; i < src.size(); i++) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i);
        elem->SetAttribute("value", src[i]);
        dest->InsertEndChild(elem);
      }
  }
  template <>
  inline void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::string> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second.c_str());
        dest->InsertEndChild(elem);
      }
  }
  template <>
  inline void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, int> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second);
        dest->InsertEndChild(elem);
      }
  }
  template <>
  inline void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, SMACKER_VIDEOS> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second);
        dest->InsertEndChild(elem);
      }
  }
  template <>
  inline void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::set<int>> &src) {
    for(auto &i : src) {
      for(auto val : i.second) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", val);
        dest->InsertEndChild(elem);
      }
    }
  }
  template<typename T>
  void WriteCampaignDDArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const T &src) {
    for(int i = 0; i < ELEMENTS_IN(src); i++)
        for(int j = 0; j < ELEMENTS_IN(src[i]); j++) {
            tinyxml2::XMLElement *elem = doc->NewElement(name);
            elem->SetAttribute("campID", i);
            elem->SetAttribute("mapID", j);
            elem->SetAttribute("value", (int)src[i][j]);
            dest->InsertEndChild(elem);
          }
  }
  class XMLFile {
    public:
      tinyxml2::XMLDocument *tempDoc = nullptr;
      XMLFile();
      ~XMLFile();
      const char* GetError();
  };
}

#endif