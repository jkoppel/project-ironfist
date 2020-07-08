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
  char* QueryTextAttribute(tinyxml2::XMLElement *el, const char* attribute);
  void QueryTextAttribute(tinyxml2::XMLElement *el, const char* attribute, char **dest);
  template<typename T>
  void PushBack(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const T &val) {
    tinyxml2::XMLElement *elem = doc->NewElement(name);
    elem->SetText(val);
    dest->InsertEndChild(elem);
  }
  template <typename T, size_t N>
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const T (&src)[N]) {
    for(int i = 0; i < ELEMENTS_IN(src); i++) {
        tinyxml2::XMLElement *elem = doc->NewElement(name);
        elem->SetAttribute("index", i);
        elem->SetAttribute("value", src[i]);
        dest->InsertEndChild(elem);
      }
  }
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::vector<int> &src);
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::string> &src);
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, int> &src);
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, SMACKER_VIDEOS> &src);
  void WriteArray(tinyxml2::XMLDocument *doc, tinyxml2::XMLNode *dest, const char* name, const std::map<int, std::set<int>> &src);
  
  void ReadMask(tinyxml2::XMLElement *src, long long *dest);
  void ReadBinary(tinyxml2::XMLElement *src, int *dest);

  class XMLFile {
    public:
      tinyxml2::XMLDocument *tempDoc = nullptr;
      XMLFile();
      ~XMLFile();
      const char* GetError();
  };
}

#endif