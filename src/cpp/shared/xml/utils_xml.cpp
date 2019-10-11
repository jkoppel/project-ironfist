#include "xml/utils_xml.h"

namespace UtilsXML {
  tinyxml2::XMLError QueryShortText(tinyxml2::XMLElement *el, short *dest) {
    int val;
    tinyxml2::XMLError res = el->QueryIntText(&val);
    *dest = (short)val;
    return res;
  }

  tinyxml2::XMLError QueryCharText(tinyxml2::XMLElement *el, char *dest) {
    int val;
    tinyxml2::XMLError res = el->QueryIntText(&val);
    *dest = (char)val;
    return res;
  }

  void QueryText(tinyxml2::XMLElement *el, char *dest) {
    const char* text = el->GetText();
    if(text)
      strcpy(dest, text);
    else
      strcpy(dest, "");
  }

  void QueryText(tinyxml2::XMLElement *el, std::string &dest) {
    const char* text = el->GetText();
    dest = text;
  }

  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::vector<int> &src) {
    for(int i = 0; i < src.size(); i++) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i);
        elem->SetAttribute("value", src[i]);
        dest->InsertEndChild(elem);
      }
  }

  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::string> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second.c_str());
        dest->InsertEndChild(elem);
      }
  }

  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, int> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second);
        dest->InsertEndChild(elem);
      }
  }

  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, SMACKER_VIDEOS> &src) {
    for(auto &i : src) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", i.second);
        dest->InsertEndChild(elem);
      }
  }

  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::set<int>> &src) {
    for(auto &i : src) {
      for(auto val : i.second) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i.first);
        elem->SetAttribute("value", val);
        dest->InsertEndChild(elem);
      }
    }
  }

  XMLFile::XMLFile() {
    tempDoc = new tinyxml2::XMLDocument(true);
  }

  XMLFile::~XMLFile() {
    if(tempDoc)
      delete tempDoc;
  }

  const char* XMLFile::GetError() {
    return tempDoc->ErrorStr();
  }
}