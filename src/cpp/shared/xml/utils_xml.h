#ifndef UTILS_XML_H
#define UTILS_XML_H

#include "tinyxml2/tinyxml2.h"

#include <string>

namespace UtilsXML {
  tinyxml2::XMLError QueryShortText(tinyxml2::XMLElement *el, short *dest);
  tinyxml2::XMLError QueryCharText(tinyxml2::XMLElement *el, char *dest);
  void QueryText(tinyxml2::XMLElement *el, char *dest);
  void QueryText(tinyxml2::XMLElement *el, std::string &dest);

  class XMLFile {
    public:
      tinyxml2::XMLDocument *tempDoc = nullptr;
      XMLFile();
      ~XMLFile();
      const char* GetError();
  };
}

#endif