#include "artifacts.h"
#include "artifacts_xml.hxx"
#include <cmath>
#include <string>
#include <vector>

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
  const int NUM_SUPPORTED_ARTIFACTS = 256;

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
}


char *gArtifactNames[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactDesc[NUM_SUPPORTED_ARTIFACTS] = { 0 };
char *gArtifactEvents[NUM_SUPPORTED_ARTIFACTS] = { 0 };
unsigned char gArtifactLevel[NUM_SUPPORTED_ARTIFACTS] = { 0 };

std::vector<std::string> names;
std::vector<std::string> descriptions;
std::vector<std::string> events;


void LoadArtifacts() {
  auto allArtifacts = artifacts_("./DATA/artifacts.xml");
  const auto &artifactList = allArtifacts->artifact();

  const int artSize = MaxArtifactId(artifactList) + 1;
  names.resize(artSize);
  descriptions.resize(artSize);
  events.resize(artSize);

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

    // See level_t::value for the different levels here.  Ultimate artifacts
    // get level 0, major level 1, etc.  But the game expects values of 1, 2, 4, 8, etc.,
    // so we need 2^level to get the right number.
    const auto lvl = static_cast<unsigned char>(std::pow(2, static_cast<int>(art.level())));
    gArtifactLevel[i] = lvl;
  }
}
