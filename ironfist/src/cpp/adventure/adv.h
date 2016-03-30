#ifndef TIED_ADV_H
#define TIED_ADV_H

#include "gui/gui.h"
class mapCell;

#define ORIG_SPELLS 65

#pragma pack(push, 1)

#define MAX_TOTAL_HEROES 48

enum PRIMARY_SKILL
{
  PRIMARY_SKILL_ATTACK = 0,
  PRIMARY_SKILL_DEFENSE = 1,
  PRIMARY_SKILL_SPELLPOWER = 2,
  PRIMARY_SKILL_KNOWLEDGE = 3,
};

enum SECONDARY_SKILL
{
  SECONDARY_SKILL_PATHFINDING = 0,
  SECONDARY_SKILL_ARCHERY = 1,
  SECONDARY_SKILL_LOGISTICS = 2,
  SECONDARY_SKILL_SCOUTING = 3,
  SECONDARY_SKILL_DIPLOMACY = 4,
  SECONDARY_SKILL_NAVIGATION = 5,
  SECONDARY_SKILL_LEADERSHIP = 6,
  SECONDARY_SKILL_WISDOM = 7,
  SECONDARY_SKILL_MYSTICISM = 8,
  SECONDARY_SKILL_LUCK = 9,
  SECONDARY_SKILL_BALLISTICS = 10,
  SECONDARY_SKILL_EAGLE_EYE = 11,
  SECONDARY_SKILL_NECROMANCY = 12,
  SECONDARY_SKILL_ESTATES = 13,
};

class armyGroup
{
public:
  char creatureTypes[5];
  __int16 quantities[5];
  armyGroup();

  int Add(int,int,int);
};

class hero
{
public:
  __int16 spellpoints;
  char idx;
  char ownerIdx;
  char field_4;
  char field_5;
  char field_6;
  char field_7;
  char field_8;
  char field_9;
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
  int mobility;
  int remainingMobility;
  int experience;
  __int16 oldLevel;
  char primarySkills[4];
  char field_43;
  char tempMoraleBonuses;
  char tempLuckBonuses;
  char field_46;
  int gazeboesVisited;
  int fortsVisited;
  int witchDoctorHutsVisited;
  int mercenaryCampsVisited;
  int standingStonesVisited;
  int treesOfKnowledgeVisited;
  int xanadusVisited;
  char randomSeed;
  char wisdomLastOffered;
  armyGroup army;
  char secondarySkillLevel[14];
  char skillIndex[14];
  int numSecSkillsKnown;
  
  /*
   * In order to put more space in the hero class for new spells,
   * we would need to decompile virtually the entire codebase, as doing so would also
   * change the size of the game class.
   *
   * We instead replace the statically-allocated spellsLearned array with a pointer to a dynamically-allocated one,
   * so that we only need to decompile the direct accesses.
   *
   * There ARE memory leaks associated with doing this. We've done much of what we can to avoid this,
   * but there's no easy way out, and the leak is upper-bounded by 3 kb every time you load a map
   */
  //char spellsLearned[65];
  char* spellsLearned;
  char _[ORIG_SPELLS - sizeof(char*)];

#define FIELD_AFTER_SPELLS_LEARNED artifacts
  char artifacts[14];
  int flags;
  char isCaptain;
  int field_E8;
#define LAST_SW_HERO_FIELD scrollSpell
  char scrollSpell[14];

  hero();
  ~hero(); //newly added
  void AddSpell(int);
  void AddSpell(int,int);
  int HasSpell(int);
  int GetNumSpells(int);
  int GetNthSpell(int,int);
  void UseSpell(int);
	  
  int HasArtifact(int);
  void TakeArtifact(int);

  signed char Stats(int);
  void SetSS(int,int);
  signed char GetSSLevel(int);
  int CalcMobility();

  void Read(int, signed char);
  void ResetSpellsLearned();

  void SetPrimarySkill(int,int);

  void Clear();
};

class recruitUnit
{
public:
  //managerVtable *vtable;
  //baseManager *next;
  //baseManager *prev;
  //int type;
  //int idx;
  //char name[30];
  //int ready;
  int field_36;
  int creatureType;
  int field_3E;
  int field_42;
  int field_46;
  int field_4A;
  int field_4E;
  int field_52;
  int field_56;
  armyGroup *army;
  int field_5E;
  int field_62;
  int field_66;
  int available;
  int field_6E;
  int field_72;
  int field_76;
  int field_7A;

  virtual int Open(int);
  int Open_orig(int);
};

class advManager : public baseManager {
public:
	char _[0x37E-sizeof(baseManager)];

	advManager();
	void PurgeMapChangeQueue();
	void CheckSetEvilInterface(int,int);
	
	void DemobilizeCurrHero();

	void CastSpell(int);
	void CastSpell_orig(int);

	void RedrawAdvScreen(int,int);

	virtual int Open(int);
	int Open_orig(int);

	void ExpansionRecruitEvent(class hero *,int,short *);

	mapCell* MoveHero(int,int,int *,int *,int *,int,int *,int);
	mapCell* MoveHero_orig(int,int,int *,int *,int *,int,int *,int);
	void TeleportTo(hero *, int x, int y, int, int);
	mapCell* GetCell(int x, int y);
};

extern advManager* gpAdvManager;

extern int giMapChangeCtr;

extern heroWindow* heroWin;
extern int giHeroScreenSrcIndex;

hero* GetCurrentHero();

int __fastcall GiveArtifact(hero*, int artifact, int checkEndGame, signed char scrollSpell);
void __fastcall GetMonsterCost(int, int * const);

#pragma pack(pop)

#endif