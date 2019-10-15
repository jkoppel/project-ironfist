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

void WriteCampaignMetadata(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* root) {
  int campaignID = xCampaign.campaignID;
  if(campaignID < 4)
    return;

  tinyxml2::XMLElement *metadata = doc->NewElement("campaignMetadata");
  PushBack(doc, metadata, "id", campaignID);
  PushBack(doc, metadata, "name", xCampaignNames[campaignID].c_str());
  PushBack(doc, metadata, "shortName", xShortCampaignNames[campaignID].c_str());
  PushBack(doc, metadata, "numMaps", expCampaignNumMaps[campaignID]);
  WriteArray(doc, metadata, "scenarioName", xScenarioName[campaignID]);
  WriteArray(doc, metadata, "scenarioDescription", xScenarioDescription[campaignID]);
  WriteArray(doc, metadata, "scenarioDifficulty", xCampaignDifficulties[campaignID]);

  for(int index = 0u; index < scenarioIconOffsets[campaignID].size(); index++) {
    tinyxml2::XMLElement *icn = doc->NewElement("scenarioIcon");
    icn->SetAttribute("scenarioID", index);
    icn->SetAttribute("x", scenarioIconOffsets[campaignID][index]._x);
    icn->SetAttribute("y", scenarioIconOffsets[campaignID][index]._y);
    metadata->InsertEndChild(icn);
  }

  for(int index = 0u; index < xCampaignChoices[campaignID].size(); index++) {
    for(int choiceID = 0u; choiceID < MAX_CAMPAIGN_CHOICES; choiceID++) {
      tinyxml2::XMLElement *choiceElem = doc->NewElement("choice");
      choiceElem->SetAttribute("scenarioID", index);
      choiceElem->SetAttribute("id", choiceID);
      SCampaignChoice choice = xCampaignChoices[campaignID][index][choiceID];
      choiceElem->SetAttribute("type", choice.type);
      choiceElem->SetAttribute("field", choice.field);
      choiceElem->SetAttribute("amount", choice.amount);
      metadata->InsertEndChild(choiceElem);
    }
  }

  WriteArray(doc, metadata, "replaySMK", replaySMK[campaignID]);
  WriteArray(doc, metadata, "victorySMK", victorySMK[campaignID]);
  WriteArray(doc, metadata, "mapToComplete", mapsToComplete[campaignID]);
  WriteArray(doc, metadata, "award", awardsToGive[campaignID]);

  for(int scenario = 0u; scenario < xCampaignHeroesToSave[campaignID].size(); scenario++) {
    for(auto &heroData : xCampaignHeroesToSave[campaignID][scenario]) {
      tinyxml2::XMLElement *heroElem = doc->NewElement("saveHero");
      heroElem->SetAttribute("scenarioID", scenario);
      heroElem->SetAttribute("playerID", heroData.first);
      heroElem->SetAttribute("ownedHeroID", heroData.second);
      metadata->InsertEndChild(heroElem);
    }
  }

  for(int scenario = 0u; scenario < xCampaignHeroesToLoad[campaignID].size(); scenario++) {
    for(auto &heroData : xCampaignHeroesToLoad[campaignID][scenario]) {
      tinyxml2::XMLElement *heroElem = doc->NewElement("loadHero");
      heroElem->SetAttribute("scenarioID", scenario);
      heroElem->SetAttribute("playerID", heroData.first);
      heroElem->SetAttribute("ownedHeroID", heroData.second);
      metadata->InsertEndChild(heroElem);
    }
  }
  root->InsertEndChild(metadata);
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