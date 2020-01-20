#include <fstream>

#include "campaign/campaign.h"
#include "expansions.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "sound/sound.h"
#include "xml/campaign_xml.h"

std::map<int, int> expCampaignNumMaps = {
  {0, 8},
  {1, 8},
  {2, 4},
  {3, 4},
};

std::map<int, std::map<int, std::map<int, SCampaignChoice>>> xCampaignChoices = {
  { 0, {
    { 0, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MEDAL_OF_VALOR, -1}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_STEALTH_SHIELD_OF_PROTECTION, -1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MINOR_SCROLL_OF_KNOWLEDGE, -1}}}},
    { 1, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_WHITE_PEARL, -1}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_BALLISTA_OF_QUICKNESS, -1}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}}}},
    { 2, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAJOR_SCROLL_OF_KNOWLEDGE, -1}}, { 2, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 2}}}},
    { 3, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MEDAL_OF_HONOR, -1}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_CASTERS_BRACELET_OF_MAGIC, -1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_DEFENDER_HELM_OF_PROTECTION, -1}}}},
    { 4, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}}, { 2, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_DEFENSE, 2}}}},
    { 5, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}}, { 1, {CAMPAIGN_CHOICE_ARMY, CREATURE_CRUSADER, 3}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY, -1}}}},
    { 6, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_SULFUR, 10}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}}, { 2, {CAMPAIGN_CHOICE_SPELL_SCROLL, SPELL_ANIMATE_DEAD, -1}}}},
    { 7, {{ 0, {CAMPAIGN_CHOICE_SPELL, SPELL_VIEW_HEROES, -1}}, { 1, {CAMPAIGN_CHOICE_ARMY, CREATURE_MAGE, 5}}, { 2, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ESTATES, 2}}}}
  }},
  { 1, {
    { 0, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}}, { 1, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 50}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_CRYSTAL, 10}}}},
    { 1, {{ 0, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_ATTACK, 1}}, { 1, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_DEFENSE, 1}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}}}},
    { 2, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}}, { 1, {CAMPAIGN_CHOICE_SPELL, SPELL_STEELSKIN, -1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}}}},
    { 3, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}}}},
    { 4, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LUCK, 1}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_SPIKED_SHIELD, 1}}}},
    { 5, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, -1000}}, { 1, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -10}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -2}}}},
    { 6, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 20}}}},
    { 7, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ARCHERY, 1}}, { 2, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_SPELLPOWER, 1}}}}
  }},
  { 2, {
    { 0, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}}, { 2, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_STEALTH_SHIELD_OF_PROTECTION, -1}}}},
    { 1, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}}, { 1, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_FOREMOST_SCROLL_OF_KNOWLEDGE, -1}}, { 2, {CAMPAIGN_CHOICE_SPELL, SPELL_FIREBLAST, -1}}}},
    { 2, {{ 0, {CAMPAIGN_CHOICE_SPELL, SPELL_MASS_HASTE, -1}}, { 1, {CAMPAIGN_CHOICE_SPELL, SPELL_SUMMON_EARTH_ELEMENTAL, -1}}, { 2, {CAMPAIGN_CHOICE_SPELL, SPELL_CHAIN_LIGHTNING, -1}}}},
    { 3, {{ 0, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 5}}, { 1, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_ORE, 5}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}}}},
  }},
  { 3, {
    { 0, {{ 0, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_NOMAD_BOOTS_OF_MOBILITY, -1}}, { 1, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 500}}, { 2, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}}}},
    { 1, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_PATHFINDING, 1}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_NAVIGATION, 1}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_SULFUR, 15}}}},
    { 2, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ARCHERY, 1}}, { 1, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 3000}}, { 2, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_ATTACK, 1}}}},
    { 3, {{ 0, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_NECROMANCY, 1}}, { 1, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}}, { 2, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}}}},
  }}
};

std::map<int, tag_rect> xCampaignSelectionRects = {
  {0, {215, 49, 230, 150}},
  {1, {217, 275, 230, 150}},
  {2, {475, 132, 120, 180}},
  {3, {41, 132, 120, 180}}
};

std::map<int, SMACKER_VIDEOS> rectToSMK = {
  {0, SMACKER_XCAMPAIGN_PREVIEW_PRICE_OF_LOALTY},
  {1, SMACKER_XCAMPAIGN_PREVIEW_DESCENDANTS },
  {2, SMACKER_XCAMPAIGN_PREVIEW_WIZARDS_ISLE},
  {3, SMACKER_XCAMPAIGN_PREVIEW_VOYAGE_HOME}
};

std::map<int, std::map<int, Point>> scenarioIconOffsets = {
  {0, {{0, {113, 310}}, {1, {187, 310}}, {2, {261, 352}}, {3, {261, 310}}, {4, {335, 352}}, {5, {370, 310}}, {6, {445, 352}}, {7, {479, 310}}}},
  {1, {{0, {111, 331}}, {1, {185, 331}}, {2, {259, 289}}, {3, {259, 373}}, {4, {333, 331}}, {5, {407, 373}}, {6, {407, 289}}, {7, {481, 331}}}},
  {2, {{0, {186, 310}}, {1, {260, 310}}, {2, {334, 352}}, {3, {408, 310}}}},
  {3, {{0, {222, 312}}, {1, {296, 312}}, {2, {370, 312}}, {3, {370, 354}}}}
};

std::map<int, std::string> xCampaignNames = {
  {0, "Price of Loyalty"},
  {1, "Descendants"},
  {2, "Wizard's Isle"},
  {3, "Voyage Home"}
};

std::map<int, std::string> xShortCampaignNames = {
  {0, "POL"},
  {1, "DES"},
  {2, "WIZ"},
  {3, "VOY"}
};

std::map<int, std::map<int, std::string>> xScenarioName = {
  { 0, {
    {0, "Uprising"},
    {1, "Island of Chaos"},
    {2, "Arrow's Flight"},
    {3, "The Abyss"},
    {4, "The Giant's Pass"},
    {5, "Aurora Borealis"},
    {6, "Betrayal's End"},
    {7, "Corruption's Heart"}
  }},
  { 1, {
    {0, "Conquer and Unify"},
    {1, "Border Towns"},
    {2, "The Wayward Son"},
    {3, "Crazy Uncle Ivan"},
    {4, "The Southern War"},
    {5, "Ivory Gates"},
    {6, "The Elven Lands"},
    {7, "The Epic Battle"}
  }},
  { 2, {
    {0, "The Shrouded Isles"},
    {1, "The Eternal Scrolls"},
    {2, "Power's End" },
    {3, "Fount of Wizardry"}
  }},
  { 3, {
    {0, "Stranded"},
    {1, "Pirate Isles"},
    {2, "King and Country"},
    {3, "Blood is Thicker"}
  }}
};

std::map<int, std::map<int, std::string>> xScenarioDescription = {
  { 0, {
    {0, "Subdue the unruly local lords in order to provide the Empire with facilities to operate in this region."},
    {1, "Eliminate all oposition in this area. Then the first piece of the artifact will be yours."},
    {2, "The sorceresses to the northeast are rebelling! For the good of the empire you must quash their feeble uprising on your way to the mountains."},
    {3, "Having prepared for your arrival, Kraeger has arranged for a force of necromancers to thwart your quest. You must capture the castle of Scabsdale before the first day of the third week, or the Necromancers will be too strong for you."},
    {4, "The barbarian despot in this area is, as yet, ignorant of your presence. Quickly, build up your forces before you are discovered and attacked! Secure the region by subduing all enemy forces."},
    {5, "The Empire is weak in this region. You will be unable to completely subdue all forces in this area, so take what you can before reprisal strikes. Remember, your true goal is to claim the Helmet of Anduran."},
    {6, "For the good of the Empire, eliminate Kraeger."},
    {7, "At last, you have the opportunity and the facilities to rid the Empire of the necromancer's evil. Eradicate them completely, and you will be sung as a hero for all time."}
  }},
  { 1, {
    {0, "Conquer and unite all the enemy tribes. Don't lose the hero Jarkonas, the forefather of all descendants."},
    {1, "Your rival, the kingdom of Harondale, is attacking weak towns on your border! Recover from their first strike and crush them completely!"},
    {2, "Find your wayward son Joseph who is rumored to be living in the desolate lands. Do it before the first day of the third month or it will be of no help to your family."},
    {3, "Rescue your crazy uncle Ivan. Find him before the first day of the fourth month or it will be no help to your kingdom."},
    {4, "Destroy the barbarians who are attacking the southern border of your kingdom! Recover your fallen towns, and then invade the jungle kingdom. Leave no enemy standing."},
    {5, "Retake the castle of Ivory Gates, which has fallen due to treachery."},
    {6, "Gain the favor of the elves. They will not allow trees to be chopped down, so we will send you wood every 2 weeks. You must complete your mission before the first day of the seventh month, or the kingdom will surely fall."},
    {7, "This is the final battle against your rival kingdom of Harondale. Eliminate everyone, and don't lose the hero Jarkonas VI."}
  }},
  { 2, {
    {0, "Your mission is to vanquish the warring mages in the magical Shrouded Isles. The completion of this task will give you a fighting chance against your rivals."},
    {1, "The location of the great library has been discovered! You must make your way to it, and reclaim the city of Chronos in which it lies."},
    {2, "Find the Orb of negation, which is said to be buried in this land. There are clues inscribed on stone obelisks which will help lead you to your prize. Find the Orb before the first day of the sixth month, or your rivals will surely have gotten to the fount before you."},
    {3, "You must take control of the castle of Magic, where the fount of wizardry lies. Do this and your victory will be supreme."}
  }},
  { 3, {
    {0, "Capture the town on the island off the southeast shore in order to construct a boat and travel back towards the mainland. Do not lose the hero Gallavant."},
    {1, "Find and defeat Martine, the pirate leader, who resides in Pirate's Cove. Do not lose Gallavant or your quest will be over."},
    {2, "Eliminate all the other forces who oppose the rule of Lord Alberon. Gallavant must not die."},
    {3, "Overthrow the entrenched monarchy of Lord Alberon, and claim all the land in your name. Gallavant must not die."}
  }}
};

std::map<int, std::map<int, int>> xCampaignDifficulties = {
  {0, {{0, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 2}, {6, 2}, {7, 3}}},
  {1, {{0, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}, {6, 2}, {7, 3}}},
  {2, {{0, 1}, {1, 1}, {2, 1}, {3, 2}}},
  {3, {{0, 0}, {1, 1}, {2, 2}, {3, 2}}}
};

std::map<int, std::map<int, std::set<int>>> mapsToComplete;
std::map<int, std::map<int, SMACKER_VIDEOS>> replaySMK;
std::map<int, std::map<int, SMACKER_VIDEOS>> victorySMK;
std::map<int, std::map<int, int>> awardsToGive;
std::map<int, std::map<int, std::set<std::pair<int, int>>>> xCampaignHeroesToLoad;
std::map<int, std::map<int, std::set<std::pair<int, int>>>> xCampaignHeroesToSave;

void ExpCampaign::InitNewCampaign(int var) {
  this->campaignID = var;
  this->currentMapID = -1;
  this->numMaps = expCampaignNumMaps[var];
  this->ResetMapChoices();
  this->ResetMapsPlayed();
  this->ResetAwards();
  this->ResetBonusChoices();
  gIronfistExtra.campaign.savedHeroData.clear();
}

void ExpCampaign::InitMap() {
  SCampaignChoice *campChoice = &xCampaignChoices[this->campaignID][this->currentMapID][this->bonusChoices[this->currentMapID]];
  for(int i = 0; i < ELEMENTS_IN(gpGame->relatedToPlayerPosAndColor); i++)
    gpGame->relatedToPlayerPosAndColor[i] = 0;
  for(int i = 0; i < ELEMENTS_IN(gpGame->playerHandicap); i++)
    gpGame->playerHandicap[i] = 0;
  for(int i = 0; i < ELEMENTS_IN(gpGame->newGameSelectedFaction); i++)
    gpGame->newGameSelectedFaction[i] = 0;
  for(int i = 0; i < ELEMENTS_IN(gpGame->somePlayerCodeOr10IfMayBeHuman); i++)
    gpGame->somePlayerCodeOr10IfMayBeHuman[i] = 0;
	gpGame->difficulty = 0;
  for(int i = 0; i < ELEMENTS_IN(gpGame->somePlayerNumData); i++)
    gpGame->somePlayerNumData[i] = 0;
  gpGame->relatedToNewGameSelection = 0;
  gpGame->numHumanPlayers = 0;
  for(int i = 0; i < ELEMENTS_IN(gpGame->field_47C); i++)
    gpGame->field_47C[i] = 0;

  sprintf(gpGame->mapFilename, "CAMP%d_%02d.HXC", this->campaignID + 1, this->currentMapID + 1);
  gpGame->relatedToNewGameInit = 0;
  if(this->currentMapID == 0)
    this->daysPlayed[0] = 0;
  strcpy(gMapName, gpGame->mapFilename);
  GetMapHeader(gpGame->mapFilename, &gpGame->mapHeader);
  gpGame->LoadGame("origdata.bin", 1, 0);
  gpGame->InitNewGame(0);
  gpGame->difficulty = xCampaignDifficulties[this->campaignID][this->currentMapID];
  gpGame->numPlayers = gpGame->mapHeader.numPlayers;
  gpGame->NewMap(gMapName);
  playerData *player0 = &gpGame->players[0];
  char heroIdx = player0->heroesOwned[0];
  hero *hero0 = &gpGame->heroes[heroIdx];
  
  CAMPAIGN_CHOICE_TYPES choiceType = (CAMPAIGN_CHOICE_TYPES)campChoice->type;
  if(choiceType < NUM_CAMPAIGN_CHOICE_TYPES) {
    switch(choiceType) {
      case CAMPAIGN_CHOICE_RESOURCE:
        player0->resources[campChoice->field] += campChoice->amount;
        break;
      case CAMPAIGN_CHOICE_ARTIFACT:
        if(player0->numHeroes > 0)
          GiveArtifact(hero0, (ARTIFACT)campChoice->field, 0, -1);
        break;
      case CAMPAIGN_CHOICE_SPELL:
        if(player0->numHeroes > 0)
          hero0->spellsLearned[campChoice->field] = true;
        break;
      case CAMPAIGN_CHOICE_SECONDARY_SKILL:
        if(player0->numHeroes > 0) {
          hero *hro;
          for(int i = 0; player0->numHeroes > i; ++i) {
            hro = &gpGame->heroes[player0->heroesOwned[i]];
            if(this->campaignID != 3 || this->currentMapID != 3) {
              if(this->campaignID != 3 || this->currentMapID != 2 || hro->heroID == 67)
                break;
            } else {
              if(hro->heroID == 65)
                break;
            }
          }
          hro->SetSS(campChoice->field, campChoice->amount);
        }
        break;
      case CAMPAIGN_CHOICE_ARMY:
        if(player0->numHeroes > 0)
          hero0->army.Add(campChoice->field, campChoice->amount, -1);
        break;
      case CAMPAIGN_CHOICE_PUZZLE_PIECES:
        player0->puzzlePieces = LOBYTE(campChoice->field);
        break;
      case CAMPAIGN_CHOICE_EXPERIENCE: {
        int tempInNewGameSetup = gbInNewGameSetup;
        gbInNewGameSetup = 1;
        if(player0->numHeroes > 0) {
          hero0->experience += campChoice->field;
          hero0->CheckLevel();
        }
        gbInNewGameSetup = tempInNewGameSetup;
        break;
      }
      case CAMPAIGN_CHOICE_PRIMARY_SKILL:
        if(player0->numHeroes > 0) {
          hero *hro;
          for(int i = 0; ; ++i) {
            if(player0->numHeroes > i) {
              hro = &gpGame->heroes[player0->heroesOwned[i]];
              if(this->campaignID == 3) {
                if(this->currentMapID == 2 && gpGame->heroes[player0->heroesOwned[i]].heroID != 67)
                  continue;
              }
            }
            break;
          }
          hro->primarySkills[campChoice->field] += campChoice->amount;
        }
        break;    
      case CAMPAIGN_CHOICE_SPELL_SCROLL:
        if(player0->numHeroes > 0)
          GiveArtifact(hero0, ARTIFACT_SPELL_SCROLL, 0, campChoice->field);
        break;
      case CAMPAIGN_CHOICE_NOT_AVAILABLE:
        break;
    }
  }
  for(int award = 0; award < ELEMENTS_IN(this->awards); ++award) {
    if(this->awards[award]) {
      switch(award) {
        case 1:
          if(player0->numHeroes > 0)
            GiveArtifact(hero0, ARTIFACT_BREASTPLATE_OF_ANDURAN, 0, -1);
          break;
        case 3:
          if(player0->numHeroes > 0)
            GiveArtifact(hero0, ARTIFACT_HELMET_OF_ANDURAN, 0, -1);
          break;
        case 4:
          for(int i = 0; i < MAX_HEROES; ++i) {
            if(gpGame->heroes[i].heroID == 61)
              gpGame->heroes[i].Deallocate(0);
          }
          break;
        case 5:
          if(player0->numHeroes > 0)
            GiveArtifact(hero0, ARTIFACT_BATTLE_GARB_OF_ANDURAN, 0, -1);
          break;
        case 8:
          if(player0->numHeroes > 0)
            GiveArtifact(hero0, ARTIFACT_LEGENDARY_SCEPTER, 0, -1);
          break;
        case 9:
          if(player0->numHeroes > 0)
            hero0->spellsLearned[SPELL_SET_EARTH_GUARDIAN] = 1;
          break;
        case 10:
          if(player0->numHeroes > 0)
            GiveArtifact(hero0, ARTIFACT_SPHERE_OF_NEGATION, 0, -1);
          break;
        case 0:
        case 2:
        case 6:
        case 7:
          continue;
      }
    }
  }
  int saveIdx = 0;
  for(auto data : xCampaignHeroesToLoad[this->campaignID][this->currentMapID]) {
    LoadCampaignSavedHero(data.first, data.second, saveIdx);
    saveIdx++;
  }
  gbRetreatWin = 1;
}

void ExpCampaign::Autosave() {
  if(this->currentMapID != -1) {
    this->mapsPlayed[this->currentMapID] = 1;
    sprintf(gText, "%s_%d", xShortCampaignNames[this->campaignID].c_str(), this->currentMapID + 1);
    int saveIdx = 0;
    for(auto data : xCampaignHeroesToSave[this->campaignID][this->currentMapID]) {
      SaveCampaignHero(data.first, data.second, saveIdx);
      saveIdx++;
    }
    gpGame->SaveGame(gText, 1, 0);
  }
}

CAMPAIGN_TYPE GetCurrentCampaignType() {
  if(xIsPlayingExpansionCampaign)
    return CAMPAIGN_TYPE_EXPANSION;
  else if(gbInCampaign)
    return CAMPAIGN_TYPE_ORIGINAL;
  else
    return CAMPAIGN_TYPE_NONE;
}

int __fastcall ExpansionCampaignRect(int x, int y) {
  for(int i = 0; i < xCampaignSelectionRects.size(); i++) {
    if(PointInRect(x, y, &xCampaignSelectionRects[i]))
      return i;
  }
  return -1;
}

SMACKER_VIDEOS GetCampaignRectangleSmackerVideo(int rectID) {
  return rectToSMK[rectID];
}

int ExpCampaign::HandleVictory() {
  short days = 0;
  if(this->currentMapID > -1) {
    days = this->Days();
    this->mapsPlayed[this->currentMapID] = 1;
  }
  memset(this->mapChoice, 0, this->numMaps);
  switch(this->campaignID) {
    case 0:
      this->HandleVictory1();
      break;
    case 1:
      this->HandleVictory2();
      break;
    case 2:
      this->HandleVictory3();
      break;
    case 3:
      this->HandleVictory4();
      break;
    default:
      this->HandleVictoryCustomCampaign();
  }

  bool result;
  if(this->IsCompleted()) {
    result = 0;
  } else {
    this->currentMapID = -1;
    for(int i = 0; i < this->numMaps; ++i) {
      if(this->mapChoice[i]) {
        this->daysPlayed[i] = days;
        if(this->currentMapID == -1)
          this->currentMapID = i;
      }
    }
    this->ShowInfo(false, 0);
    result = gpWindowManager->buttonPressedCode == BUTTON_OK;
  }
  return result;
}

void ExpCampaign::HandleVictoryCustomCampaign() {
  unsigned int mapID = this->currentMapID + 1;
  PlaySmacker(victorySMK[this->campaignID][mapID]);
  for(auto map : mapsToComplete[this->campaignID][mapID])
    this->mapChoice[map] = 1;
  if(awardsToGive[this->campaignID].count(mapID))
    this->awards[mapID] = awardsToGive[this->campaignID][mapID];
}

void ExpCampaign::ShowInfo(int inGame, int unused) {
  this->anIntVariable = inGame;
  gpMouseManager->SetPointer("advmice.mse", 0, -999);
  gpMouseManager->ReallyShowPointer();
  int tmpEvilInterface = gbUseEvilInterface;
  gbUseEvilInterface = 1;
  this->mightBeScenarioID = this->currentMapID;

  this->window = new heroWindow(0, 0, "x_camp.bin");
  if(!this->window)
    MemError();

  for(int i = 0; i < this->numMaps; ++i) {
    Point *offsets = &scenarioIconOffsets[this->campaignID][i];
    int fieldID = 850 + i;
    widget *guiObj = new iconWidget(offsets->_x, offsets->_y, 41, 41, "x_cmpext.icn", 0, 0, fieldID, 16, 1);
    if(!guiObj)
      MemError();
    this->window->AddWidget(guiObj, -1);
  }

  iconWidget* campNameWidget = new iconWidget(24, 25, 376, 49, "x_cmphdr.icn", this->campaignID, 0, -1, 16, 1);
  if(!campNameWidget)
    MemError();
  this->window->AddWidget(campNameWidget, -1);

  if(!inGame)
    GUIRemoveFlag(this->window, 901, 6);

  if(gbLowMemory)
    GUIRemoveFlag(this->window, 902, 6);

  gpSoundManager->SwitchAmbientMusic(24);
  this->UpdateInfo(0);
  gpWindowManager->DoDialog(this->window, ExpCampaign::MessageHandler, 0);
  delete this->window;

  gbUseEvilInterface = tmpEvilInterface;
  if(gpWindowManager->buttonPressedCode == 901) {
    NormalDialog("Are you sure you want to restart this scenario?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if(gpWindowManager->buttonPressedCode == 30725) {
      this->InitMap();
      gpAdvManager->field_A2 = 0;
      giBottomViewOverride = 0;
      gpWindowManager->FadeScreen(1, 8, gPalette);
      gpAdvManager->SetInitialMapOrigin();
      gpAdvManager->RedrawAdvScreen(1, 0);
      gpWindowManager->FadeScreen(0, 8, gPalette);
    }
  }
}

std::vector<std::string> xCampaignAwards = {
  "Elven alliance",
  "Breastplate",
  "Wood bonus",
  "Helmet",
  "Kraeger Defeated",
  "Battle Garb",
  "Wayward son",
  "Uncle Ivan",
  "Legendary Sceptre",
  "Guardian Spell",
  "Sphere of Negation"
};

std::vector<std::string> xCampaignShortSkillLevel = {
  "Bas.",
  "Adv.",
  "Exp."
};

void ExpCampaign::UpdateInfo(int drawWindow) {
  for(int i = 0; this->numMaps > i; ++i) {
    int imgIdx;
    if(this->mapChoice[i]) {
      imgIdx = 1;
    } else {
      if(this->mapsPlayed[i])
        imgIdx = 0;
      else
        imgIdx = 2;
    }
    if(this->mightBeScenarioID == i)
      imgIdx += 3 * this->campaignID + 3;
    GUISetImgIdx(this->window, 850 + i, imgIdx);
  }
  sprintf(gText, "x_track%d.icn", this->campaignID + 1);
  GUISetIcon(this->window, 809, gText);
  sprintf(gText, "%d", this->mightBeScenarioID + 1);
  GUISetText(this->window, 801, gText);
  sprintf(gText, "%s", xScenarioName[this->campaignID][this->mightBeScenarioID].c_str());
  GUISetText(this->window, 802, gText);
  sprintf(gText, "%s", xScenarioDescription[this->campaignID][this->mightBeScenarioID].c_str());
  GUISetText(this->window, 803, gText);
  sprintf(gText, "%d", this->daysPlayed[this->mightBeScenarioID]);
  GUISetText(this->window, 804, gText);

  bool hasAward = false;
  strcpy(gText, "");
  for(int award = 0; award < ELEMENTS_IN(this->awards); ++award) {
    if(this->awards[award]) {
      hasAward = true;
      strcat(gText, xCampaignAwards[award].c_str());
      strcat(gText, "\n");
    }
  }
  if(!hasAward)
    sprintf(gText, "None");
  GUISetText(this->window, 805, gText);

  for(int i = 0; i < MAX_CAMPAIGN_CHOICES; ++i) {
    SCampaignChoice *choice = &xCampaignChoices[this->campaignID][this->mightBeScenarioID][i];
    CAMPAIGN_CHOICE_TYPES campChoice = (CAMPAIGN_CHOICE_TYPES)choice->type;
    switch(campChoice) {
      case CAMPAIGN_CHOICE_RESOURCE:
        sprintf(gText, "%d %s", choice->amount, gResourceNames[choice->field]);
        break;
      case CAMPAIGN_CHOICE_ARTIFACT:
        switch(choice->field) {
          case ARTIFACT_MINOR_SCROLL_OF_KNOWLEDGE:
            strcpy(gText, "Minor Scroll");
            break;
          case ARTIFACT_MAGES_RING_OF_POWER:
            strcpy(gText, "Mage's Ring");
            break;
          case ARTIFACT_DEFENDER_HELM_OF_PROTECTION:
            strcpy(gText, "Defender Helm");
            break;
          case ARTIFACT_POWER_AXE_OF_DOMINION:
            strcpy(gText, "Power Axe");
            break;
          case ARTIFACT_DRAGON_SWORD_OF_DOMINION:
            strcpy(gText, "Dragon Sword");
            break;
          case ARTIFACT_DIVINE_BREASTPLATE_OF_PROTECTION:
            strcpy(gText, "Breastplate");
            break;
          case ARTIFACT_FIZBIN_OF_MISFOURTUNE:
            strcpy(gText, "Fizbin Medal");
            break;
          case ARTIFACT_THUNDER_MACE_OF_DOMINION:
            strcpy(gText, "Thunder Mace");
            break;
          case ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION:
            strcpy(gText, "Gauntlets");
            break;
          case ARTIFACT_MAJOR_SCROLL_OF_KNOWLEDGE:
            strcpy(gText, "Major Scroll");
            break;
          case ARTIFACT_FOREMOST_SCROLL_OF_KNOWLEDGE:
            strcpy(gText, "Foremost Scroll");
            break;
          case ARTIFACT_BALLISTA_OF_QUICKNESS:
            strcpy(gText, "Ballista");
            break;
          case ARTIFACT_STEALTH_SHIELD_OF_PROTECTION:
            strcpy(gText, "Stealth Shield");
            break;
          case ARTIFACT_NOMAD_BOOTS_OF_MOBILITY:
            strcpy(gText, "Nomad Boots");
            break;
          case ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY:
            strcpy(gText, "Traveler's Boots");
            break;
          default:
            sprintf(gText, "%s", gArtifactNames[choice->field]);
        }
        break;
      case CAMPAIGN_CHOICE_SPELL:
        if(choice->field == SPELL_SUMMON_EARTH_ELEMENTAL)
          sprintf(gText, "Summon Earth");
        else
          sprintf(gText, "%s", gSpellNames[choice->field]);
        break;
      case CAMPAIGN_CHOICE_SECONDARY_SKILL:
        if((choice->amount != 1 || choice->field != SECONDARY_SKILL_NECROMANCY) && (choice->amount != 2 || choice->field != SECONDARY_SKILL_LOGISTICS))
          sprintf(gText, "%s %s", secondarySkillLevels[choice->amount], gSecondarySkills[choice->field]);
        else
          sprintf(gText, "%s %s", xCampaignShortSkillLevel[choice->amount].c_str(), gSecondarySkills[choice->field]);
        break;
      case CAMPAIGN_CHOICE_ARMY: {
        std::string creatureName = GetCreaturePluralName(choice->field);
        creatureName[0] -= 32;
        sprintf(gText, "%d %s", choice->amount, creatureName.c_str());
        break;
      }
      case CAMPAIGN_CHOICE_PUZZLE_PIECES:
        sprintf(gText, "%d %s", choice->field, "Puzzle Pieces");
        break;
      case CAMPAIGN_CHOICE_EXPERIENCE:
        sprintf(gText, "%d %s", choice->field, "Experience");
        break;
      case CAMPAIGN_CHOICE_NOT_AVAILABLE:
        sprintf(gText, "n/a");
        break;
      case CAMPAIGN_CHOICE_ALIGNMENT:
        sprintf(gText, gAlignmentNames[choice->field]);
        break;
      case CAMPAIGN_CHOICE_PRIMARY_SKILL:
        sprintf(gText, "%s +%d", gStatNames[choice->field], choice->amount);
        break;
      case CAMPAIGN_CHOICE_SPELL_SCROLL: {
        if(choice->field == SPELL_DISRUPTING_RAY || choice->field == SPELL_ANIMATE_DEAD)
          sprintf(gText, "%s", gSpellNames[choice->field]);
        else
          sprintf(gText, "%s %s", gSpellNames[choice->field], "Scroll");        
        break;
      }
      default:
        break;
    }
    GUISetText(this->window, 806 + i, gText);
  }
  for(int i = 0; i < MAX_CAMPAIGN_CHOICES; ++i) {
    int fieldID = 810 + i;
    int imgIdx;
    if(this->anIntVariable || !this->mapChoice[this->mightBeScenarioID])
      imgIdx = 9;
    else
      imgIdx = 8;
    GUISetImgIdx(this->window, fieldID, imgIdx);

    if(this->bonusChoices[this->mightBeScenarioID] == i)
      GUIAddFlag(this->window, fieldID, 4);
    else
      GUIRemoveFlag(this->window, fieldID, 4);
  }
  if(drawWindow)
    this->window->DrawWindow();
}

void ExpCampaign::ReplaySmacker() {
  switch(this->campaignID) {
    case 0:
      this->ReplaySmacker1();
      break;
    case 1:
      this->ReplaySmacker2();
      break;
    case 2:
      this->ReplaySmacker3();
      break;
    case 3:
      this->ReplaySmacker4();
      break;
    default:
      this->ReplaySmackerCustomCampaign();
  }
  gpWindowManager->cycleColors = 1;
};

void ExpCampaign::ReplaySmackerCustomCampaign() {
  if(this->mightBeScenarioID < MAX_MAPS_IN_CAMPAIGN) {
    PlaySmacker(replaySMK[this->campaignID][this->mightBeScenarioID]);
  }
}

int LoadCampaignFromFile(std::string filename) {
  filename = ".\\CAMPAIGNS\\" + filename;
  CampaignXML xml;
  tinyxml2::XMLError err = xml.Read(filename.c_str());
  if(err) {
    std::string error_message = "Could not load " + filename + "\n" + std::string(xml.GetError());
    H2MessageBox(error_message);
    return -1;
  }
  return xml.GetCampaignID();
}

void LoadCampaignSavedHero(int playerID, int ownedHeroIdx, int saveIdx) {
  int heroIdx = gpGame->players[playerID].heroesOwned[ownedHeroIdx];
  hero *hro = &gpGame->heroes[heroIdx];
  campaignExtra::partialHeroData *savedHero = &gIronfistExtra.campaign.savedHeroData[saveIdx];

  for(int i = 0; i < ELEMENTS_IN(hro->primarySkills); i++)
    hro->primarySkills[i] = savedHero->primarySkills[i];
  for(int i = 0; i < ELEMENTS_IN(hro->skillIndex); i++) {
    hro->skillIndex[i] = savedHero->skillIndex[i];
    hro->secondarySkillLevel[i] = savedHero->secondarySkillLevel[i];
  }
  //for(int i = 0; i < ELEMENTS_IN(hro->artifacts); i++)
  //  hro->artifacts[i] = savedHero->artifacts[i];
  //for(int i = 0; i < ELEMENTS_IN(hro->scrollSpell); i++)
  //  hro->scrollSpell[i] = savedHero->scrollSpell[i];
  for(int i = 0; i < NUM_SPELLS; i++)
    hro->spellsLearned[i] = savedHero->spellsLearned[i];
  hro->numSecSkillsKnown = savedHero->numSecSkillsKnown;
  //hro->army = savedHero->army;
  hro->experience = savedHero->experience;
}

void SaveCampaignHero(int playerID, int ownedHeroIdx, int saveIdx) {
  int heroIdx = gpGame->players[playerID].heroesOwned[ownedHeroIdx];
  hero *hro = &gpGame->heroes[heroIdx];
  campaignExtra::partialHeroData *savedHero = &gIronfistExtra.campaign.savedHeroData[saveIdx];

  for(int i = 0; i < ELEMENTS_IN(hro->primarySkills); i++)
    savedHero->primarySkills[i] = hro->primarySkills[i];
  for(int i = 0; i < ELEMENTS_IN(hro->skillIndex); i++) {
    savedHero->skillIndex[i] = hro->skillIndex[i];
    savedHero->secondarySkillLevel[i] = hro->secondarySkillLevel[i];
  }
  //for(int i = 0; i < ELEMENTS_IN(hro->artifacts); i++)
  //  savedHero->artifacts[i] = hro->artifacts[i];
  //for(int i = 0; i < ELEMENTS_IN(hro->scrollSpell); i++)
  //  savedHero->scrollSpell[i] = hro->scrollSpell[i];
  for(int i = 0; i < NUM_SPELLS; i++)
    savedHero->spellsLearned[i] = hro->spellsLearned[i];
  savedHero->numSecSkillsKnown = hro->numSecSkillsKnown;
  //savedHero->army = hro->army;
  savedHero->experience = hro->experience;
}

