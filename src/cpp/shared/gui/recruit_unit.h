#ifndef RECRUIT_UNIT_H
#define RECRUIT_UNIT_H

#include "adventure/adv.h"
#include "town/town.h"

#pragma pack(push,1)

class recruitUnit : public baseManager {
public:
  int field_36;
  int creatureType;
  int field_3E;
  int costSingleGold;
  int resource;
  int costSingleResource;
  int field_4E;
  heroWindow* window;
  int field_56;
  armyGroup *army;
  int field_5E;
  int field_62;
  int field_66;
  short* available;
  int maxBuyable;
  int costTotalGold;
  int costTotalResource;
  int amountSelected;
   
  recruitUnit(armyGroup *armyGrp, int creature, short *available);
  recruitUnit(town *twn, int dwelling, int a4);

  virtual int Main(struct tag_message &a2);
  virtual int Open(int id);
  void Update();
  void Close();
};

void __fastcall SetupRecruitWin(heroWindow *window, int creature, int goldCost, int specialResource, int resourceAmt, int numAvail);

#pragma pack(pop)

#endif
