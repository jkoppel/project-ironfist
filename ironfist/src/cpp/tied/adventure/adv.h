#ifndef TIED_ADV_H
#define TIED_ADV_H

#include "tied/gui/gui.h"

#pragma pack(push, 1)

#define MAX_TOTAL_HEROES 48

class armyGroup
{
public:
  char creatureTypes[5];
  __int16 quantities[5];
  armyGroup();
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
  int probablyMovement;
  __int16 field_35;
  __int16 field_37;
  int experience;
  __int16 oldLevel;
  char primarySkills[4];
  char field_43;
  char tempMoraleBonuses;
  char tempLuckBonuses;
  char _2[30];
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
   * This is currently disabled, as it has become clear that adding new spells will be extremely awkward without
   * first "Ironfisting" (ironplating? tempering?) the map files
   */
  char spellsLearned[65];
  //char* spellsLearned;
  //char _[61];

  char artifacts[14];
  char flags1;
  char flags2;
  char flags3;
  char flags4;
  char isCaptain;
  int field_E8;
  char scrollSpell[14];

  hero();
  ~hero(); //newly added
  void AddSpell(int,int);
  int HasSpell(int);
  int GetNumSpells(int);
  int GetNthSpell(int,int);
	  
  int HasArtifact(int);

  signed char Stats(int);
};

extern heroWindow* heroWin;
extern int giHeroScreenSrcIndex;

#pragma pack(pop)

#endif