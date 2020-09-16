#ifndef ARTIFACT_XML_H
#define ARTIFACT_XML_H

#include "xml/utils_xml.h"

class ArtifactXML : public UtilsXML::XMLFile {
  public:
    tinyxml2::XMLError Read(const char* fileName);
};
#endif