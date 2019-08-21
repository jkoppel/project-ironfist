#include "campaign/campaign.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "sound/sound.h"

int expCampaignNumMaps[MAX_CAMPAIGNS] = {
  8,
  8,
  4,
  4,
  8, // dummy
};

SCampaignChoice xCampaignChoices[MAX_CAMPAIGNS][MAX_MAPS_IN_CAMPAIGN][MAX_CAMPAIGN_CHOICES] = {
  {
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MEDAL_OF_VALOR, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_STEALTH_SHIELD_OF_PROTECTION, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MINOR_SCROLL_OF_KNOWLEDGE, -1}},
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_WHITE_PEARL, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_BALLISTA_OF_QUICKNESS, -1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}},
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAJOR_SCROLL_OF_KNOWLEDGE, -1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 2}},
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MEDAL_OF_HONOR, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_CASTERS_BRACELET_OF_MAGIC, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_DEFENDER_HELM_OF_PROTECTION, -1}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_DEFENSE, 2}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}, {CAMPAIGN_CHOICE_ARMY, CREATURE_CRUSADER, 3}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY, -1}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_SULFUR, 10}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}, {CAMPAIGN_CHOICE_SPELL_SCROLL, SPELL_ANIMATE_DEAD, -1}},
    {{CAMPAIGN_CHOICE_SPELL, SPELL_VIEW_HEROES, -1}, {CAMPAIGN_CHOICE_ARMY, CREATURE_MAGE, 5}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ESTATES, 2}}
  },
  {
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 50}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_CRYSTAL, 10}},
    {{CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_ATTACK, 1}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_DEFENSE, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}, {CAMPAIGN_CHOICE_SPELL, SPELL_STEELSKIN, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LUCK, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_SPIKED_SHIELD, 1}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, -1000}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -10}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -2}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 20}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ARCHERY, 1}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_SPELLPOWER, 1}}
  },
  {
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000},{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_STEALTH_SHIELD_OF_PROTECTION, -1}},
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_FOREMOST_SCROLL_OF_KNOWLEDGE, -1}, {CAMPAIGN_CHOICE_SPELL, SPELL_FIREBLAST, -1}},
    {{CAMPAIGN_CHOICE_SPELL, SPELL_MASS_HASTE, -1}, {CAMPAIGN_CHOICE_SPELL, SPELL_SUMMON_EARTH_ELEMENTAL, -1}, {CAMPAIGN_CHOICE_SPELL, SPELL_CHAIN_LIGHTNING, -1}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 5}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_ORE, 5}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}}
  },
  {
    {{CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_NOMAD_BOOTS_OF_MOBILITY, -1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 500}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_PATHFINDING, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_NAVIGATION, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_SULFUR, 15}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ARCHERY, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 3000}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_ATTACK, 1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_NECROMANCY, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 2000}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}},
    {{-1, -1, -1}, {0, 0, 0}, {0, 0, 0}}
  },
  { // dummy
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 50}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_CRYSTAL, 10}},
    {{CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_ATTACK, 1}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_DEFENSE, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}, {CAMPAIGN_CHOICE_SPELL, SPELL_STEELSKIN, -1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_MAGES_RING_OF_POWER, -1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LOGISTICS, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_POWER_AXE_OF_DOMINION, -1}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LUCK, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}, {CAMPAIGN_CHOICE_ARTIFACT, ARTIFACT_SPIKED_SHIELD, 1}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, -1000}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -10}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, -2}},
    {{CAMPAIGN_CHOICE_RESOURCE, RESOURCE_GOLD, 1000}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_SCOUTING, 1}, {CAMPAIGN_CHOICE_RESOURCE, RESOURCE_WOOD, 20}},
    {{CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_LEADERSHIP, 1}, {CAMPAIGN_CHOICE_SECONDARY_SKILL, SECONDARY_SKILL_ARCHERY, 1}, {CAMPAIGN_CHOICE_PRIMARY_SKILL, PRIMARY_SKILL_SPELLPOWER, 1}}
  }
};

tag_rect xCampaignSelectionRects[MAX_CAMPAIGNS] = {
  {215, 49, 230, 150},
  {217, 275, 230, 150},
  {475, 132, 120, 180},
  {41, 132, 120, 180},
  {480, 380, 120, 180} // right bottom corner
};

SMACKER_VIDEOS rectToSMK[MAX_CAMPAIGNS] = {
  SMACKER_XCAMPAIGN_PREVIEW_PRICE_OF_LOALTY,
  SMACKER_XCAMPAIGN_PREVIEW_DESCENDANTS,
  SMACKER_XCAMPAIGN_PREVIEW_WIZARDS_ISLE,
  SMACKER_XCAMPAIGN_PREVIEW_VOYAGE_HOME,
  SMACKER_XCAMPAIGN_PREVIEW_DESCENDANTS // dummy
};

Point expCampaignWidgetOffsets[MAX_CAMPAIGNS][MAX_MAPS_IN_CAMPAIGN] = {
  {{113, 310}, {187, 310}, {261, 352}, {261, 310}, {335, 352}, {370, 310}, {445, 352}, {479, 310}},
  {{111, 331}, {185, 331}, {259, 289}, {259, 373}, {333, 331}, {407, 373}, {407, 289}, {481, 331}},
  {{186, 310}, {260, 310}, {334, 352}, {408, 310}, {-1, -1},   {-1, -1},   {-1, -1},   {-1, -1}},
  {{222, 312}, {296, 312}, {370, 312}, {370, 354}, {-1, -1},   {-1, -1},   {-1, -1},   {-1, -1}},
  {{111, 331}, {185, 331}, {259, 289}, {259, 373}, {333, 331}, {407, 373}, {407, 289}, {481, 331}} // dummy
};

char *xHSCampaignNames[] = {
  "Price of Loyalty",
  "Descendants",
  "Wizard's Isle",
  "Voyage Home",
  "Cyborg Campaign" // dummy
};

char *xShortCampaignNames[] = {
  "POL",
  "DES",
  "WIZ",
  "VOY",
  "CYB" // dummy
};

char *xScenarioName[][MAX_MAPS_IN_CAMPAIGN] = {
  {
    "Uprising",
    "Island of Chaos",
    "Arrow's Flight",
    "The Abyss",
    "The Giant's Pass",
    "Aurora Borealis",
    "Betrayal's End",
    "Corruption's Heart",
  },
  {
    "Conquer and Unify",
    "Border Towns",
    "The Wayward Son",
    "Crazy Uncle Ivan",
    "The Southern War",
    "Ivory Gates",
    "The Elven Lands",
    "The Epic Battle"
  },
  {
    "The Shrouded Isles",
    "The Eternal Scrolls",
    "Power's End",
    "Fount of Wizardry",
    "",
    "",
    "",
    ""
  },
  {
    "Stranded",
    "Pirate Isles",
    "King and Country",
    "Blood is Thicker",
    "",
    "",
    "",
    ""
  },
  { // dummy
    "Cyborg campaign map 1",
    "Cyborg campaign map 2",
    "Cyborg campaign map 3",
    "Cyborg campaign map 4",
    "Cyborg campaign map 5",
    "Cyborg campaign map 6",
    "Cyborg campaign map 7",
    "Cyborg campaign map 8",
  }
};

char *xScenarioDescription[][MAX_MAPS_IN_CAMPAIGN] = {
  {
    "Subdue the unruly local lords in order to provide the Empire with facilities to operate in this region.",
    "Eliminate all oposition in this area. Then the first piece of the artifact will be yours.",
    "The sorceresses to the northeast are rebelling! For the good of the empire you must quash their feeble uprising on your way to the mountains.",
    "Having prepared for your arrival, Kraeger has arranged for a force of necromancers to thwart your quest. You must capture the castle of Scabsdale before the first day of the third week, or the Necromancers will be too strong for you.",
    "The barbarian despot in this area is, as yet, ignorant of your presence. Quickly, build up your forces before you are discovered and attacked! Secure the region by subduing all enemy forces.",
    "The Empire is weak in this region. You will be unable to completely subdue all forces in this area, so take what you can before reprisal strikes. Remember, your true goal is to claim the Helmet of Anduran.",
    "For the good of the Empire, eliminate Kraeger.",
    "At last, you have the opportunity and the facilities to rid the Empire of the necromancer's evil. Eradicate them completely, and you will be sung as a hero for all time.",
  },
  {
    "Conquer and unite all the enemy tribes. Don't lose the hero Jarkonas, the forefather of all descendants.",
    "Your rival, the kingdom of Harondale, is attacking weak towns on your border! Recover from their first strike and crush them completely!",
    "Find your wayward son Joseph who is rumored to be living in the desolate lands. Do it before the first day of the third month or it will be of no help to your family.",
    "Rescue your crazy uncle Ivan. Find him before the first day of the fourth month or it will be no help to your kingdom.",
    "Destroy the barbarians who are attacking the southern border of your kingdom! Recover your fallen towns, and then invade the jungle kingdom. Leave no enemy standing.",
    "Retake the castle of Ivory Gates, which has fallen due to treachery.",
    "Gain the favor of the elves. They will not allow trees to be chopped down, so we will send you wood every 2 weeks. You must complete your mission before the first day of the seventh month, or the kingdom will surely fall.",
    "This is the final battle against your rival kingdom of Harondale. Eliminate everyone, and don't lose the hero Jarkonas VI.",
  },
  {
    "Your mission is to vanquish the warring mages in the magical Shrouded Isles. The completion of this task will give you a fighting chance against your rivals.",
    "The location of the great library has been discovered! You must make your way to it, and reclaim the city of Chronos in which it lies.",
    "Find the Orb of negation, which is said to be buried in this land. There are clues inscribed on stone obelisks which will help lead you to your prize. Find the Orb before the first day of the sixth month, or your rivals will surely have gotten to the fount before you.",
    "You must take control of the castle of Magic, where the fount of wizardry lies. Do this and your victory will be supreme."
    "",
    "",
    "",
    ""
  },
  {
    "Capture the town on the island off the southeast shore in order to construct a boat and travel back towards the mainland. Do not lose the hero Gallavant.",
    "Find and defeat Martine, the pirate leader, who resides in Pirate's Cove. Do not lose Gallavant or your quest will be over.",
    "Eliminate all the other forces who oppose the rule of Lord Alberon. Gallavant must not die.",
    "Overthrow the entrenched monarchy of Lord Alberon, and claim all the land in your name. Gallavant must not die."
    "",
    "",
    "",
    ""
  },
  { // dummy
    "Cyborg campaign description 1",
    "Cyborg campaign description 2",
    "Cyborg campaign description 3",
    "Cyborg campaign description 4",
    "Cyborg campaign description 5",
    "Cyborg campaign description 6",
    "Cyborg campaign description 7",
    "Cyborg campaign description 8"
  }
};

char xCampaignDifficulties[MAX_CAMPAIGNS][MAX_MAPS_IN_CAMPAIGN] = {
  { 0, 1, 1, 1, 1, 2, 2, 3 },
  { 0, 1, 1, 1, 2, 2, 2, 3 },
  { 1, 1, 1, 2, -1, -1, -1, -1 },
  { 0, 1, 2, 2, -1, -1, -1, -1 },
  { 0, 1, 1, 1, 2, 2, 2, 3 } // dummy
};

void ExpCampaign::InitNewCampaign(int var) {
  this->campaignID = var;
  this->currentMapID = -1;
  this->numMaps = expCampaignNumMaps[var];
  this->ResetMapChoices();
  this->ResetMapsPlayed();
  this->ResetAwards();
  this->ResetBonusChoices();
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
  for(int i = 0; i < MAX_CAMPAIGNS; i++) {
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
  unsigned int campID = this->campaignID;
  if(campID < MAX_CAMPAIGNS) {
    switch(campID) {
      case 0u:
        this->HandleVictory1();
        break;
      case 1u:
        this->HandleVictory2();
        break;
      case 2u:
        this->HandleVictory3();
        break;
      case 3u:
        this->HandleVictory4();
        break;
      case 4u:
        this->HandleVictoryCyborg();
        break;
      default:
        break;
    }
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

void ExpCampaign::HandleVictoryCyborg() {
  unsigned int mapID = this->currentMapID + 1;
  if(mapID <= MAPS_IN_CYBORG_CAMPAIGN) {
    switch(mapID) {
      case 0u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_INTRO);
        this->mapChoice[0] = 1;
        break;
      case 1u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_1);
        this->mapChoice[1] = 1;
        break;
      case 2u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_2);
        this->mapChoice[2] = 1;
        this->mapChoice[3] = 1;
        break;
      case 3u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_3);
        this->mapChoice[4] = 1;
        this->awards[6] = 1;
        break;
      case 4u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_3);
        this->mapChoice[4] = 1;
        this->awards[7] = 1;
        break;
      case 5u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_4);
        this->mapChoice[5] = 1;
        this->mapChoice[6] = 1;
        break;
      case 6u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_5);
        this->mapChoice[7] = 1;
        this->awards[8] = 1;
        break;
      case 7u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_5);
        this->mapChoice[7] = 1;
        this->awards[0] = 1;
        break;
      case 8u:
        PlaySmacker(SMACKER_XCAMPAIGN_DESCENDANTS_6);
        break;
      default:
        return;
    }
  }
}

void ExpCampaign::ShowInfo(int inGame, int unused) {
  const int CAMP_NAME_WIDGET_OFFSET = 18;
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
    Point *offsets = &expCampaignWidgetOffsets[this->campaignID][i];
    int fieldID = 850 + i;
    widget *guiObj = new iconWidget(offsets->_x, offsets->_y, 41, 41, "x_cmpext.icn", 0, 0, fieldID, 16, 1);
    if(!guiObj)
      MemError();
    this->window->AddWidget(guiObj, -1);
  }

  iconWidget* campNameWidget = new iconWidget(24, 25, 376, 49, "x_cmpext.icn", CAMP_NAME_WIDGET_OFFSET + this->campaignID, 0, -1, 16, 1);
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