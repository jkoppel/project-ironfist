#ifndef TIED_ADV_H
#define TIED_ADV_H

#include "spell/spells.h"
#include "gui/gui.h"

#pragma pack(push, 1)

#define MAX_TOTAL_HEROES 48

enum PRIMARY_SKILL
{
  PRIMARY_SKILL_ATTACK = 0,
  PRIMARY_SKILL_DEFENSE = 1,
  PRIMARY_SKILL_SPELLPOWER = 2,
  PRIMARY_SKILL_KNOWLEDGE = 3,
};

class armyGroup
{
public:
  char creatureTypes[5];
  __int16 quantities[5];
  armyGroup();

  int Add(int,int,int);
};

struct hero
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

  signed char Stats(int);
  int CalcMobility();

  void Read(int, signed char);
  void ResetSpellsLearned();

  void Clear();
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
};

extern advManager* gpAdvManager;

extern int giMapChangeCtr;

extern heroWindow* heroWin;
extern int giHeroScreenSrcIndex;

#pragma pack(pop)

#endif