#include "artifacts.h"
#include "artifacts_xml.hxx"
#include <algorithm>
#include <cmath>
#include <string>

/*
 *
 * Also still unsupported:
 * 1) Random artifacts
 * 2) AI Artifact value tables
 *
 * FURTHERMORE
 *
 * For some strange reason, the assembly for the method UpdateHeroStatus bar
 * refers to table of primary-skill names by its offset relative the artifact events table.
 * Thus, there is some gibberish when you right-click a hero, and when two heroes trade.
 *
 * game::GetVictoryConditionText also does funny stuff in looking up artifact names  
 */

namespace {
  int MaxArtifactId(const artifacts::artifact_sequence &artifactList) {
    int maxId = -1;
    for (const auto &art : artifactList) {
      const int i = art.id();
      if (i > maxId && i < NUM_SUPPORTED_ARTIFACTS) {
        maxId = i;
      }
    }
    return maxId;
  }

  template <typename T>
  std::string JoinSequence(const T &seq) {
    std::string ret;
    for (const auto &str : seq) {
      ret += str;
    }
    return ret;
  }

  int GetArtifactLevel(level_t::value lvl) {
    switch (lvl) {
    case level_t::ultimate:
      return 1;
    case level_t::major:
      return 2;
    case level_t::minor:
      return 4;
    case level_t::treasure:
      return 8;
    case level_t::spellbook:
      return 16;
    case level_t::unused:
    default:
      return 32;
    }
  }

  std::vector<std::string> names;
  std::vector<std::string> descriptions;
  std::vector<std::string> events;
  std::vector<int> isCursed;
  std::vector<int> isGenerated;
}

char *gArtifactNames[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactDesc[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactEvents[NUM_SUPPORTED_ARTIFACTS] = { 0 };
unsigned char gArtifactLevel[NUM_SUPPORTED_ARTIFACTS] = { 0 };

void LoadArtifacts() {
  auto allArtifacts = artifacts_("./DATA/artifacts.xml");
  const auto &artifactList = allArtifacts->artifact();

  const int artSize = MaxArtifactId(artifactList) + 1;
  names.resize(artSize);
  descriptions.resize(artSize);
  events.resize(artSize);
  isCursed.resize(artSize, 0);
  isGenerated.resize(artSize, 0);

  for (const auto &art : artifactList) {
    const int i = art.id();
    if (i < 0 || i >= artSize) {
      continue;
    }

    names[i] = art.name();
    gArtifactNames[i] = &(names[i][0]);

    if (art.description().size() > 0 && art.title().size() > 0) {
      std::string desc = "{";
      desc += JoinSequence(art.title());
      desc += "}\n\n";
      desc += JoinSequence(art.description());
      descriptions[i] = desc;
    }
    gArtifactDesc[i] = &(descriptions[i][0]);

    events[i] = JoinSequence(art.event());
    gArtifactEvents[i] = &(events[i][0]);

    gArtifactLevel[i] = GetArtifactLevel(art.level());

    if (art.cursed()) {
      isCursed[i] = art.cursed().get();
    }
  }
}

int __fastcall IsCursedItem(int artId) {
  const int size = isCursed.size();
  if (artId < 0 || artId >= size) {
    return 0;
  }

  return isCursed[artId];
}

bool IsArtifactGenerated(int id) {
  return isGenerated[id] == 1;
}

void GenerateArtifact(int id) {
  isGenerated[id] = 1;
}

void ResetGeneratedArtifacts() {
  std::fill(isGenerated.begin(), isGenerated.end(), 0);
}

void ResetGeneratedArtifacts(int matchingLevels) {
  for (auto i = 0u; i < isGenerated.size(); ++i) {
    if (gArtifactLevel[i] & matchingLevels) {
      isGenerated[i] = 0;
    }
  }
}

void DeserializeGeneratedArtifacts(const std::vector<int> &src) {
  ResetGeneratedArtifacts();
  const auto size = std::min(src.size(), isGenerated.size());
  for (auto i = 0u; i < size; ++i) {
    isGenerated[i] = src[i];
  }
}

const std::vector<int> & SerializeGeneratedArtifacts() {
  return isGenerated;
}