#include "xml/artifact_xml.h"

#include "artifacts.h"
#include "combat/creatures.h"

using namespace UtilsXML;

void ReadArtifactData(tinyxml2::XMLNode* root) {
  for(tinyxml2::XMLNode* artifact = root->FirstChild(); artifact; artifact = artifact->NextSibling()) {
    tinyxml2::XMLElement *artElem = artifact->ToElement();
    const int id = artElem->IntAttribute("id");
    if (id < 0) {
      continue;
    }

    artifactNames[id] = QueryTextAttribute(artElem, "name");
    gArtifactNames[id] = &(artifactNames[id][0]);
    std::string level_attr = std::string(QueryTextAttribute(artElem, "level"));
    ArtifactLevel level = ARTIFACT_LEVEL_UNUSED;
    if(level_attr == "ultimate")
      level = ARTIFACT_LEVEL_ULTIMATE;
    else if(level_attr == "major")
      level = ARTIFACT_LEVEL_MAJOR;
    else if(level_attr == "minor")
      level = ARTIFACT_LEVEL_MINOR;
    else if(level_attr == "treasure")
      level = ARTIFACT_LEVEL_TREASURE;
   else if(level_attr == "spellbook")
     level = ARTIFACT_LEVEL_SPELLBOOK;
   else if(level_attr == "unused")
     level = ARTIFACT_LEVEL_UNUSED;

    gArtifactLevel[id] = level;

    artifactIsCursed[id] = artElem->BoolAttribute("cursed", 0);
    artifactIsCampaignOnly[id] = artElem->BoolAttribute("campaign_only", 0);

    std::string title, description;
    for(tinyxml2::XMLNode* property = artElem->FirstChild(); property; property = property->NextSibling()) {
      tinyxml2::XMLElement *propElem = property->ToElement();
      std::string name = propElem->Name();
      if(name == "title") {
        QueryText(propElem, title);
      } else if(name == "description") {
        QueryText(propElem, description);
      } else if(name == "event") {
        QueryText(propElem, artifactEvents[id]);
        gArtifactEvents[id] = &artifactEvents[id][0u];
      }
    }
    artifactDescriptions[id] = "{" + title + "}\n\n" + description;
    gArtifactDesc[id] = &artifactDescriptions[id][0u];
  }
}

tinyxml2::XMLError ArtifactXML::Read(const char* fileName) {
  tinyxml2::XMLError eResult = tempDoc->LoadFile(fileName);
  if(!eResult) {
    tinyxml2::XMLNode *pRoot = tempDoc->FirstChild();
    ReadArtifactData(pRoot);
  }
  return eResult;
}