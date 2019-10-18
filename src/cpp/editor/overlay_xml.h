#ifndef OVERLAY_XML_H
#define OVERLAY_XML_H

#include "xml/utils_xml.h"

class OverlayXML : public UtilsXML::XMLFile {
  public:
    tinyxml2::XMLError Read(const char* fileName);
};

#endif