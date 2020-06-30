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

  char* QueryTextAttribute(tinyxml2::XMLElement *el, const char* attribute) {
    const char* text;
    el->QueryStringAttribute(attribute, &text);
    if(text)
      return (char*)text;
    else
      return "invalid name";
  }

  void QueryTextAttribute(tinyxml2::XMLElement *el, const char* attribute, char **dest) {
    const char* text;
    el->QueryStringAttribute(attribute, &text);
    if(*dest)
      delete *dest;
    *dest = new char[strlen(text) + 1];
    strcpy(*dest, text);
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

  void ReadMask(tinyxml2::XMLElement *src, long long *dest) {
    std::string text = src->GetText();
    int i = 0;
    long long result = 0;
    for(auto c : text) {
      if(c == '0' || c == '1') {
        if(c == '1')
          result |= (1LL << (sizeof(long long) * 8 - i - 1));
        i++;
      }
    }
    // flipping
    result = (result >> 32) | ((result & 0xFFFFFFFF) << 32);
    *dest = result;
  }

  void ReadBinary(tinyxml2::XMLElement *src, int *dest) {
    std::string text = src->GetText();
    int i = 0;
    int result = 0;
    for(auto c : text) {
      if(c == '0' || c == '1') {
        if(c == '1')
          result |= (1 << i);
        i++;
      }
    }
    *dest = result;
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