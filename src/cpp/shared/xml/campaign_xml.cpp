#include "xml/campaign_xml.h"

#include "campaign/campaign.h"
#include "xml/utils_xml.h"

using namespace UtilsXML;

// Returns Campaign ID
int ReadCampaignMetadata(tinyxml2::XMLNode* root) {
  int campaignID = -1;
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "id") elem->QueryIntText(&campaignID);
    else if(name == "name") {
      const char* text = elem->GetText();
      if(text)
        xCampaignNames[campaignID] = text;
      else
        xCampaignNames[campaignID] = "empty name";
    }
    else if(name == "shortName") QueryText(elem, xShortCampaignNames[campaignID]);
    else if(name == "numMaps") elem->QueryIntText(&expCampaignNumMaps[campaignID]);
    else if(name == "scenarioName") {
      const char* text = elem->Attribute("value");
      if(text) xScenarioName[campaignID][index] = text;
    }
    else if(name == "scenarioDescription") {
      const char* text = elem->Attribute("value");
      if(text) xScenarioDescription[campaignID][index] = text;
    }
    else if(name == "scenarioDifficulty") xCampaignDifficulties[campaignID][index] = value;
    else if(name == "scenarioIcon") {
      int scenarioID = elem->IntAttribute("scenarioID");
      scenarioIconOffsets[campaignID][scenarioID]._x = elem->IntAttribute("x");
      scenarioIconOffsets[campaignID][scenarioID]._y = elem->IntAttribute("y");
    } else if(name == "choice") {
      int scenarioID = elem->IntAttribute("scenarioID");
      int choiceID = elem->IntAttribute("id");
      SCampaignChoice choice;
      choice.type = elem->IntAttribute("type");
      choice.field = elem->IntAttribute("field");
      choice.amount = elem->IntAttribute("amount");
      xCampaignChoices[campaignID][scenarioID][choiceID] = choice;
    } else if(name == "replaySMK") replaySMK[campaignID][index] = (SMACKER_VIDEOS)value;
    else if(name == "victorySMK") victorySMK[campaignID][index] = (SMACKER_VIDEOS)value;
    else if(name == "mapToComplete") mapsToComplete[campaignID][index].insert(value);
    else if(name == "award") awardsToGive[campaignID][index] = value;
    else if(name == "saveHero") {
      int scenarioID = elem->IntAttribute("scenarioID");
      int playerID = elem->IntAttribute("playerID");
      int ownedHeroID = elem->IntAttribute("ownedHeroID");
      xCampaignHeroesToSave[campaignID][scenarioID].insert({playerID, ownedHeroID});
    }
    else if(name == "loadHero") {
      int scenarioID = elem->IntAttribute("scenarioID");
      int playerID = elem->IntAttribute("playerID");
      int ownedHeroID = elem->IntAttribute("ownedHeroID");
      xCampaignHeroesToLoad[campaignID][scenarioID].insert({playerID, ownedHeroID});
    }
  }
  return campaignID;
}

tinyxml2::XMLError CampaignXML::Read(const char* fileName) {
  tinyxml2::XMLError eResult = tempDoc->LoadFile(fileName);
  if(!eResult) {
    tinyxml2::XMLNode *pRoot = tempDoc->FirstChild();
    campaignID = ReadCampaignMetadata(pRoot);
  }
  return eResult;
}

int CampaignXML::GetCampaignID() {
  return campaignID;
}