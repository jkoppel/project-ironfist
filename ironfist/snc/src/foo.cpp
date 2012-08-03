
struct armyGroup
{
  char creatureTypes[5];
  __int16 quantities[5];
};
struct town
{
  char idx;
  char ownerIdx;
  char alignment;
  char factionID;
  char field_4;
  char field_5;
  __int16 field_6;
  armyGroup garrison;
  char visitingHeroIdx;
  unsigned int buildingsBuiltFlags;
  char mageGuildLevel;
  char field_1D;
  __int16 numCreaturesInDwelling[12];
  char field_36;
  char mayNotBeUpgradedToCastle;
  char _2[4];
  char mageGuildSpells[5][4];
  char numSpellsOfLevel[5];
  __int16 field_55;
  char name[12];
  char field_63;
};
struct hero
{
  __int16 spellpoints;
  char couldBeHeroIdx;
  char probablyOwnerIdx;
  char _2[6];
  char name[13];
  char factionID;
  char heroID;
  int x;
  int y;
  __int16 field_21;
  __int16 field_23;
  __int16 field_25;
  __int16 field_27;
  __int16 field_29;
  __int16 field_2B;
  __int16 occupiedObjType;
  __int16 occupiedObjVal;
  __int16 field_31;
  __int16 field_33;
  __int16 field_35;
  __int16 field_37;
  int experience;
  __int16 oldLevel;
  char primarySkills[4];
  char _5[33];
  char wisdomLastOffered;
  armyGroup army;
  char secondarySkillLevel[14];
  char ordinalSkillWasLearned[14];
  int numSecSkillsKnown;
  char spellsLearned[65];
  char artifacts[14];
  char flags1;
  char flags2;
  char flags3;
  char flags4;
  char field_E7[5];
  char scrollSpell[14];
};

enum ARTIFACT
{
  ARTIFACT_ULTIMATE_BOOK_OF_KNOWLEDGE = 0,
  ARTIFACT_ULTIMATE_SWORD_OF_DOMINION = 1,
  ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION = 2,
  ARTIFACT_ULTIMATE_WAND_OF_MAGIC = 3,
  ARTIFACT_ULTIMATE_SHIELD = 4,
  ARTIFACT_ULTIMATE_STAFF = 5,
  ARTIFACT_ULTIMATE_CROWN = 6,
  ARTIFACT_GOLDEN_GOOSE = 7,
  ARTIFACT_ARCANE_NECKLACE_OF_MAGIC = 8,
  ARTIFACT_CASTERS_BRACELET_OF_MAGIC = 9,
  ARTIFACT_MAGES_RING_OF_POWER = 10,
  ARTIFACT_WITCHS_BROACH_OF_MAGIC = 11,
  ARTIFACT_MEDAL_OF_VALOR = 12,
  ARTIFACT_MEDAL_OF_COURAGE = 13,
  ARTIFACT_MEDAL_OF_HONOR = 14,
  ARTIFACT_MEDAL_OF_DISTINCTION = 15,
  ARTIFACT_FIZBIN_OF_MISFOURTUNE = 16,
  ARTIFACT_THUNDER_MACE_OF_DOMINION = 17,
  ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION = 18,
  ARTIFACT_DEFENDER_HELM_OF_PROTECTION = 19,
  ARTIFACT_GIANT_FLAIL_OF_DOMINION = 20,
  ARTIFACT_BALLISTA_OF_QUICKNESS = 21,
  ARTIFACT_STEALTH_SHIELD_OF_PROTECTION = 22,
  ARTIFACT_DRAGON_SWORD_OF_DOMINION = 23,
  ARTIFACT_POWER_AXE_OF_DOMINION = 24,
  ARTIFACT_DIVINE_BREASTPLATE_OF_PROTECTION = 25,
  ARTIFACT_MINOR_SCROLL_OF_KNOWLEDGE = 26,
  ARTIFACT_MAJOR_SCROLL_OF_KNOWLEDGE = 27,
  ARTIFACT_SUPERIOR_SCROLL_OF_KNOWLEDGE = 28,
  ARTIFACT_FOREMOST_SCROLL_OF_KNOWLEDGE = 29,
  ARTIFACT_ENDLESS_SACK_OF_GOLD = 30,
  ARTIFACT_ENDLESS_BAG_OF_GOLD = 31,
  ARTIFACT_ENDLESS_PURSE_OF_GOLD = 32,
  ARTIFACT_NOMAD_BOOTS_OF_MOBILITY = 33,
  ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY = 34,
  ARTIFACT_LUCKY_RABBITS_FOOT = 35,
  ARTIFACT_GOLDEN_HORSESHOE = 36,
  ARTIFACT_GAMBLERS_LUCKY_COIN = 37,
  ARTIFACT_FOUR_LEAF_CLOVER = 38,
  ARTIFACT_TRUE_COMPASS_OF_MOBILITY = 39,
  ARTIFACT_SAILORS_ASTROLABE_OF_MOBILITY = 40,
  ARTIFACT_EVIL_EYE = 41,
  ARTIFACT_ENCHANTED_HOURGLASS = 42,
  ARTIFACT_GOLD_WATCH = 43,
  ARTIFACT_SKULLCAP = 44,
  ARTIFACT_ICE_CLOAK = 45,
  ARTIFACT_FIRE_CLOAK = 46,
  ARTIFACT_LIGHTNING_HELM = 47,
  ARTIFACT_EVERCOLD_ICICLE = 48,
  ARTIFACT_EVERHOT_LAVA_ROCK = 49,
  ARTIFACT_LIGHTNING_ROD = 50,
  ARTIFACT_SNAKE_RING = 51,
  ARTIFACT_ANKH = 52,
  ARTIFACT_BOOK_OF_ELEMENTS = 53,
  ARTIFACT_ELEMENTAL_RING = 54,
  ARTIFACT_HOLY_PENDANT = 55,
  ARTIFACT_PENDANT_OF_FREE_WILL = 56,
  ARTIFACT_PENDANT_OF_LIFE = 57,
  ARTIFACT_SERENITY_PENDANT = 58,
  ARTIFACT_SEEING_EYE_PENDANT = 59,
  ARTIFACT_KINETIC_PENDANT = 60,
  ARTIFACT_PENDANT_OF_DEATH = 61,
  ARTIFACT_WAND_OF_NEGATION = 62,
  ARTIFACT_GOLDEN_BOW = 63,
  ARTIFACT_TELESCOPE = 64,
  ARTIFACT_STATESMANS_QUILL = 65,
  ARTIFACT_WIZARDS_HAT = 66,
  ARTIFACT_POWER_RING = 67,
  ARTIFACT_AMMO_CART = 68,
  ARTIFACT_TAX_LIEN = 69,
  ARTIFACT_HIDEOUS_MASK = 70,
  ARTIFACT_ENDLESS_POUCH_OF_SULFUR = 71,
  ARTIFACT_ENDLESS_VIAL_OF_MERCURY = 72,
  ARTIFACT_ENDLESS_POUCH_OF_GEMS = 73,
  ARTIFACT_ENDLESS_CORD_OF_WOOD = 74,
  ARTIFACT_ENDLESS_CART_OF_ORE = 75,
  ARTIFACT_ENDLESS_POUCH_OF_CRYSTAL = 76,
  ARTIFACT_SPIKED_HELM = 77,
  ARTIFACT_SPIKED_SHIELD = 78,
  ARTIFACT_WHITE_PEARL = 79,
  ARTIFACT_BLACK_PEARL = 80,
  ARTIFACT_MAGIC_BOOK = 81,
  ARTIFACT_SPELL_SCROLL = 86,
  ARTIFACT_ARM_OF_THE_MARTYR = 87,
  ARTIFACT_BREASTPLATE_OF_ANDURAN = 88,
  ARTIFACT_BROACH_OF_SHIELDING = 89,
  ARTIFACT_BATTLE_GARB_OF_ANDURAN = 90,
  ARTIFACT_CRYSTAL_BALL = 91,
  ARTIFACT_HEART_OF_FIRE = 92,
  ARTIFACT_HEART_OF_ICE = 93,
  ARTIFACT_HELMET_OF_ANDURAN = 94,
  ARTIFACT_HOLY_HAMMER = 95,
  ARTIFACT_LEGENDARY_SCEPTER = 96,
  ARTIFACT_MASTHEAD = 97,
  ARTIFACT_SPHERE_OF_NEGATION = 98,
  ARTIFACT_STAFF_OF_WIZARDRY = 99,
  ARTIFACT_SWORD_BREAKER = 100,
  ARTIFACT_SWORD_OF_ANDURAN = 101,
  ARTIFACT_SPADE_OF_NECROMANCY = 102,
};
enum PRIMARY_SKILL
{
  PRIMARY_SKILL_ATTACK = 0,
  PRIMARY_SKILL_DEFENSE = 1,
  PRIMARY_SKILL_SPELLPOWER = 2,
  PRIMARY_SKILL_KNOWLEDGE = 3,
};


class town
{
public:

  char idx;
  char ownerIdx;
  char alignment;
  char factionID;
  char field_4;
  char field_5;
  __int16 field_6;
  armyGroup garrison;
  char visitingHeroIdx;
  unsigned int buildingsBuiltFlags;
  char mageGuildLevel;
  char field_1D;
  __int16 numCreaturesInDwelling[12];
  char field_36;
  char mayNotBeUpgradedToCastle;
  char _2[4];
  char mageGuildSpells[5][4];
  char numSpellsOfLevel[5];
  __int16 field_55;
  char name[12];
  char field_63;
  void GiveSpells( hero * captain);
};

void town::GiveSpells( hero * captain)
{
  char v2; // al@12
  town *thisa; // [sp+Ch] [bp-10h]@1
  signed int j; // [sp+10h] [bp-Ch]@10
  int i; // [sp+14h] [bp-8h]@8
  hero *hro; // [sp+18h] [bp-4h]@4

  if ( captain || this->visitingHeroIdx != -1 )
    {
      if ( captain )
        hro = captain;
      else
        hro = &gpGame->heroes[this->visitingHeroIdx];
      if ( hro->HasArtifact(ARTIFACT_MAGIC_BOOK) && this->buildingsBuiltFlags & 1 )
        {
          for ( i = 0; hro->secondarySkillLevel[7] + 2 > i; ++i )
            {
              for ( j = 0; this->numSpellsOfLevel[i] > j; ++j )
                {
                  v2 = hro->Stats(PRIMARY_SKILL_KNOWLEDGE);
                  hro->AddSpell(this->mageGuildSpells[i][j], v2);
                }
            }
        }
    }
}
