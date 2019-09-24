#include "campaign/campaign_xml.h"

tinyxml2::XMLError CampaignXML::Read(const char* fileName) {
  tinyxml2::XMLError eResult = tempDoc.LoadFile(fileName);
  if(!eResult) {
    tinyxml2::XMLNode *pRoot = tempDoc.FirstChild();
    ReadRoot(pRoot);
  }
  return eResult;
}

tinyxml2::XMLError CampaignXML::QueryShortText(tinyxml2::XMLElement *el, short *dest) {
  int val;
  tinyxml2::XMLError res = el->QueryIntText(&val);
  *dest = (short)val;
  return res;
}

void CampaignXML::QueryText(tinyxml2::XMLElement *el, char *dest) {
  const char* text = el->GetText();
  if(text)
    strcpy(dest, text);
  else
    strcpy(dest, "");
}

void CampaignXML::QueryText(tinyxml2::XMLElement *el, std::string &dest) {
  const char* text = el->GetText();
  dest = text;
}

void CampaignXML::ReadRoot(tinyxml2::XMLNode* root) {
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
    else if(name == "hover") {
      rectToSMK[campaignID] = (SMACKER_VIDEOS)elem->IntAttribute("smk");
      tag_rect rect;
      rect.x = elem->IntAttribute("x");
      rect.y = elem->IntAttribute("y");
      rect.width = elem->IntAttribute("width");
      rect.height = elem->IntAttribute("height");
      xCampaignSelectionRects[campaignID] = rect;      
    } else if(name == "scenarioName") QueryText(elem, xScenarioName[campaignID][index]);
    else if(name == "scenarioDescription") QueryText(elem, xScenarioDescription[campaignID][index]);
    else if(name == "scenarioDifficulty") elem->QueryIntText(&xCampaignDifficulties[campaignID][index]);
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
    else if(name == "mapToComplete") mapsToComplete[campaignID][index].push_back(value);
    else if(name == "award") awardsToGive[campaignID][index] = value;
  }
}

const char* CampaignXML::GetError() {
  return tempDoc.ErrorStr();
}

int CampaignXML::GetCampaignID() {
  return campaignID;
}