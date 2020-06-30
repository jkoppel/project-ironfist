#ifndef CREATURE_XML_H
#define CREATURE_XML_H

#include "xml/utils_xml.h"

class CreatureXML : public UtilsXML::XMLFile {
  public:
    tinyxml2::XMLError Read(const char* fileName);
};
#endif