#ifndef CREATURES_H
#define CREATURES_H

#include<string.h>
#include<stdio.h>
#include <string>
#include <vector>

#include "adventure/adv.h"

#pragma pack(push, 1)

enum CREATURES
{
  CREATURE_PEASANT = 0,
  CREATURE_ARCHER = 1,
  CREATURE_RANGER = 2,
  CREATURE_PIKEMAN = 3,
  CREATURE_VETERAN_PIKEMAN = 4,
  CREATURE_SWORDSMAN = 5,
  CREATURE_MASTER_SWORDSMAN = 6,
  CREATURE_CAVALRY = 7,
  CREATURE_CHAMPION = 8,
  CREATURE_PALADIN = 9,
  CREATURE_CRUSADER = 10,
  CREATURE_GOBLIN = 11,
  CREATURE_ORC = 12,
  CREATURE_ORC_CHIEF = 13,
  CREATURE_WOLF = 14,
  CREATURE_OGRE = 15,
  CREATURE_OGRE_LORD = 16,
  CREATURE_TROLL = 17,
  CREATURE_WAR_TROLL = 18,
  CREATURE_CYCLOPS = 19,
  CREATURE_SPRITE = 20,
  CREATURE_DWARF = 21,
  CREATURE_BATTLE_DWARF = 22,
  CREATURE_ELF = 23,
  CREATURE_GRAND_ELF = 24,
  CREATURE_DRUID = 25,
  CREATURE_GREATER_DRUID = 26,
  CREATURE_UNICORN = 27,
  CREATURE_PHOENIX = 28,
  CREATURE_CENTAUR = 29,
  CREATURE_GARGOYLE = 30,
  CREATURE_GRIFFIN = 31,
  CREATURE_MINOTAUR = 32,
  CREATURE_MINOTAUR_KING = 33,
  CREATURE_HYDRA = 34,
  CREATURE_GREEN_DRAGON = 35,
  CREATURE_RED_DRAGON = 36,
  CREATURE_BLACK_DRAGON = 37,
  CREATURE_HALFLING = 38,
  CREATURE_BOAR = 39,
  CREATURE_IRON_GOLEM = 40,
  CREATURE_STEEL_GOLEM = 41,
  CREATURE_ROC = 42,
  CREATURE_MAGE = 43,
  CREATURE_ARCHMAGE = 44,
  CREATURE_GIANT = 45,
  CREATURE_TITAN = 46,
  CREATURE_SKELETON = 47,
  CREATURE_ZOMBIE = 48,
  CREATURE_MUTANT_ZOMBIE = 49,
  CREATURE_MUMMY = 50,
  CREATURE_ROYAL_MUMMY = 51,
  CREATURE_VAMPIRE = 52,
  CREATURE_VAMPIRE_LORD = 53,
  CREATURE_LICH = 54,
  CREATURE_POWER_LICH = 55,
  CREATURE_BONE_DRAGON = 56,
  CREATURE_ROGUE = 57,
  CREATURE_NOMAD = 58,
  CREATURE_GHOST = 59,
  CREATURE_GENIE = 60,
  CREATURE_MEDUSA = 61,
  CREATURE_EARTH_ELEMENTAL = 62,
  CREATURE_AIR_ELEMENTAL = 63,
  CREATURE_FIRE_ELEMENTAL = 64,
  CREATURE_WATER_ELEMENTAL = 65,
  CREATURE_RANDMON_ANY = 66,
  CREATURE_RANDMON_1 = 67,
  CREATURE_RANDMON_2 = 68,
  CREATURE_RANDMON_3 = 69,
  CREATURE_RANDMON_4 = 70,
  CREATURE_RANDHERO = 71,
  CREATURE_KOBOLD = 72,
  CREATURE_BLOODSUCKER = 73,
  CREATURE_HARPY = 74,
  CREATURE_BLACK_KNIGHT = 75,
  CREATURE_CATOBLEBA = 76,
  CREATURE_TREANT = 77,
  CREATURE_CYBER_KOBOLD_SPEARMAN = 78,
  CREATURE_CYBER_PLASMA_BERSERKER = 79,
  CREATURE_CYBER_PLASMA_LANCER = 80,
  CREATURE_CYBER_INDIGO_PANTHER = 81,
  CREATURE_CYBER_SHADOW_ASSASSIN = 82,
  CREATURE_CYBER_BEHEMOTH = 83,

  CREATURE_INVALID = 255,
  MAX_CREATURES
};

extern std::vector<CREATURES> CREATURES_RANDOMIZABLE;

#define MAX_BASE_CREATURE 65
#define MIN_IRONFIST_CREATURE 72
#define MAX_IRONFIST_CREATURE 83

enum CREATURE_FLAGS : __int16 {
  TWO_HEXER = 0x1,
  FLYER = 0x2,
  SHOOTER = 0x4,
  TWO_HEX_ATTACKER = 0x8,
  DEAD = 0x10,
  HAS_GOOD_MORALE = 0x20,
  RETALIATED = 0x40,
  MAYBE_NOT_LOST_TURN = 0x80,
  MIRROR_IMAGE = 0x100,
  CREATURE_RED = 0x200,
  UNDEAD = 0x400,
  CREATURE_BROWN = 0x2000,
  CREATURE_PETRIFIED = 0x4000,
};

enum CREATURE_ATTRIBUTES : __int8 {
  ATTR_MIRROR_IMAGE = 0x1,
  ATTR_BLOODLUST_RED = 0x2,
  ATTR_UNDEAD = 0x4,
  ATTR_BROWN = 0x20,
  ATTR_PETRIFY_GRAY = 0x40,
};

enum CREATURE_EVENT_CODE {
	CREATURE_MOVED_CODE = 0,
	CREATURE_TOOK_TURN_EVENT_CODE = 1,
	CREATURE_TOOK_DAMAGE_CODE = 2,
};

#define STRIKE_AND_RETURN "strike-and-return"
#define PLASMA_BLAST "plasma-blast"
#define TELEPORTER "teleporter"
#define ASTRAL_DODGE "astral-dodge"
#define SHADOW_MARK "shadow-mark"
#define JUMPER "jumper"
#define CHARGER "charger"

extern char *speedText[];

struct tag_monsterInfo
{
  __int16 cost;
  int fight_value;
  char fight_value_aux;
  char growth;
  __int16 hp;
  char faction;
  char speed;
  char attack;
  char defense;
  char min_damage;
  char max_damage;
  char shots;
  char short_name[5];
  __int16 creature_flags;
  __int16 _;


  tag_monsterInfo() {}
  tag_monsterInfo(int c, int f, int f2, int g, int h, int f3, int s, int a, int d, int m, int m2, int s2,
					const char* s3, int c2, int _2) : 
						cost((short)c), fight_value(f), fight_value_aux(f2), growth(g), hp(h),
						faction(f3), speed(s), attack(a), defense(d), min_damage(m), max_damage(m2), shots(s2),
						creature_flags(c2), _(_2) {
							const size_t nameSize = sizeof(this->short_name);
							strncpy_s(this->short_name, nameSize, s3, nameSize - 1);
						}
};



tag_monsterInfo gMonsterDatabase[];
struct attributeNameTableEntry{char* name; int flag;};
struct SecondaryResourceNameTableEntry { std::string name; int resource_id; };
void GrantCreatureAttribute(int id, std::string name);
extern int giNumCreatures;
extern char *cMonFilename[MAX_CREATURES];
extern char *cArmyFrameFileNames[MAX_CREATURES];
extern char *gArmyNames[MAX_CREATURES];
extern char *gArmyNamesPlural[MAX_CREATURES];
extern char *cArmyProjectileFileNames[MAX_CREATURES];
extern int gMonSecondaryResourceCost[MAX_CREATURES][NUM_SECONDARY_RESOURCES];
extern std::vector<std::vector<int>> ironfistAttributeTable;
extern attributeNameTableEntry creatureAttributeNameTable[5];
extern SecondaryResourceNameTableEntry SecondaryResourceNameTable[];

int gMonRandBound[][2];

int CreatureHasAttribute(int id, const std::string &name);
char* GetCreatureName(int id);
char* GetCreaturePluralName(int id);
int GetNumCreatures();

void LoadCreatures();
void UnloadCreatures();


void __fastcall GetMonsterCost(int, int *const);
char *__fastcall GetMonsterName(int id);

#pragma pack(pop)

#endif