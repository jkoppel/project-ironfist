#ifndef ADV_H
#define ADV_H

#include "gui/gui.h"
#include "resource/resources.h"

#include "base.h"

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

  armyGroup() {
      for (int i = 0; i < ELEMENTS_IN(this->creatureTypes); i++) {
          this->creatureTypes[i] = -1;
      }

      for (int i = 0; i < ELEMENTS_IN(this->quantities); i++) {
          this->quantities[i] = 0;
      }
  };

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
  int CalcMobility();

  void Read(int, signed char);
  void ResetSpellsLearned();

  void SetPrimarySkill(int,int);

  void Clear();
};

enum HERO_FLAGS {
	HERO_AT_SEA = 0x80
};

char cHeroTypeInitial[];

class mapCell;

class advManager : public baseManager {
public:
	char _[0xA6-sizeof(baseManager)];
	int currentTerrain;
	char _1[0x12C];
	int viewX;
	int viewY;
	int field_1DE;
	int field_1E2;
	int xOff;
	int yOff;
	char _2[0xB8];
    int heroMobilized;
    char _3[0xD4];

	advManager();

	mapCell *GetCell(int x, int y);

	void PurgeMapChangeQueue();
	void CheckSetEvilInterface(int,int);
	
	void DemobilizeCurrHero();

	void DimensionDoor();
	void TeleportTo(hero*, int, int, int, int);

	void CastSpell(int);
	void CastSpell_orig(int);

	void RedrawAdvScreen(int,int);
	void UpdateRadar(int, int);
    void UpdateHeroLocator(int, int, int);
    void EventSound(int locType, int locType2, SAMPLE2 *samp);

	virtual int Open(int);
	int Open_orig(int);

    void PasswordEvent(mapCell *tile, hero *hero);
    int BarrierEvent(mapCell *tile, hero *hero);
};

extern advManager* gpAdvManager;

extern int giMapChangeCtr;

extern heroWindow* heroWin;
extern int giHeroScreenSrcIndex;

hero* GetCurrentHero();

int __fastcall GiveArtifact(hero*, int artifact, int checkEndGame, signed char scrollSpell);

#pragma pack(pop)

#endif