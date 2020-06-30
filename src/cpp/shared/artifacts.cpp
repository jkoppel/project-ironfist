#include "artifacts.h"
#include "gui/dialog.h"
#include "xml/artifact_xml.h"
#include <algorithm>
#include <cmath>
#include <string>

/*
 *
 * Also still unsupported:
 * 1) AI Artifact value tables
 *
 * FURTHERMORE
 *
 * For some strange reason, the assembly for the method UpdateHeroStatus bar
 * refers to table of primary-skill names by its offset relative the artifact events table.
 * Thus, there is some gibberish when you right-click a hero, and when two heroes trade.
 *
 * game::GetVictoryConditionText also does funny stuff in looking up artifact names  
 */

std::map<int, std::string> artifactNames;
std::map<int, std::string> artifactDescriptions;
std::map<int, std::string> artifactEvents;
std::map<int, int> artifactIsCursed;
std::map<int, int> isGenerated;
std::map<int, int> artifactIsCampaignOnly;

char *gArtifactNames[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactDesc[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactEvents[NUM_SUPPORTED_ARTIFACTS] = { 0 };
unsigned char gArtifactLevel[NUM_SUPPORTED_ARTIFACTS] = { 0 };

void LoadArtifacts() {
  ArtifactXML xmlDoc;
  tinyxml2::XMLError err = xmlDoc.Read("./DATA/artifacts.xml");
  if(err) {
    H2MessageBox("Could not load XML. " + std::string(xmlDoc.GetError()));
    exit(1);
  }
}

int __fastcall IsCursedItem(int artId) {
  if (artifactIsCursed.find(artId) == artifactIsCursed.end()) {
    return 0;
  }

  return artifactIsCursed[artId];
}

bool IsArtifactValid(int id) {
  if (artifactNames.find(id) == artifactNames.end()) {
    return false;
  }
  if (GetArtifactName(id).empty()) {
    return false;
  }
  if (GetArtifactLevel(id) == ARTIFACT_LEVEL_UNUSED) {
    return false;
  }

  return true;
}

bool IsArtifactGenerated(int id) {
  return isGenerated[id] == 1;
}

bool IsArtifactGenerationAllowed(int id) {
  if (!IsArtifactValid(id)) {
    return false;
  }
  if (IsArtifactGenerated(id)) {
    return false;
  }
  if (id == ARTIFACT_SPELL_SCROLL) {  // TODO: learn how to add a random spell to these
    return false;
  }
  if (artifactIsCampaignOnly[id]) {
    return false;
  }

  return true;
}

void GenerateArtifact(int id) {
  isGenerated[id] = 1;
}

void ResetGeneratedArtifacts() {
  isGenerated.clear();
}

void ResetGeneratedArtifacts(int matchingLevels) {
  for(auto &art : isGenerated) {
    int id = art.first;
    if (gArtifactLevel[id] & matchingLevels) {
      art.second = 0;
    }
  }
}

void DeserializeGeneratedArtifacts(const std::vector<int> &src) {
  ResetGeneratedArtifacts();
  for (auto i = 0u; i < src.size(); ++i) {
    isGenerated[i] = src[i];
  }
}

std::vector<int> SerializeGeneratedArtifacts() {
  std::vector<int> artifacts;
  artifacts.resize(isGenerated.rbegin()->first + 1, 0);
  for(auto art : isGenerated) {
    artifacts[art.first] = art.second;
  }
  return artifacts;
}

int GetArtifactLevel(int id) {
  return gArtifactLevel[id];
}

std::string GetArtifactName(int id) {
  return artifactNames[id];
}

std::string GetArtifactDescription(int id) {
  return gArtifactDesc[id];
}