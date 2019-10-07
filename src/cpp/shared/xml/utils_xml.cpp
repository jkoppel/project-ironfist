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