#include "gui/recruit_unit.h"
#include "scripting/callback.h"

recruitUnit::recruitUnit(armyGroup *armyGrp, int creature, short *available) {
  this->field_36 = -1;
  this->field_4E = 0;
  this->army = armyGrp;
  this->creatureType = creature;
  this->available = available;

  int resourceCosts[NUM_RESOURCES];
  GetMonsterCost(this->creatureType, resourceCosts);
  this->costSingleGold = resourceCosts[RESOURCE_GOLD];
  this->resource = -1;
  this->costSingleResource = 0;
  for(int i = 0; i < RESOURCE_GOLD; ++i) {
    if(resourceCosts[i]) {
      this->resource = i;
      this->costSingleResource = resourceCosts[this->resource];
      break;
    }
  }
}

recruitUnit::recruitUnit(town *twn, int dwelling, int a4) {
  this->field_36 = 35;
  this->field_4E = a4;
  this->army = &twn->garrison;
  this->creatureType = gDwellingType[twn->factionID][dwelling];
  this->available = &twn->numCreaturesInDwelling[dwelling];

  int resourceCosts[NUM_RESOURCES];
  GetMonsterCost(this->creatureType, resourceCosts);
  this->costSingleGold = resourceCosts[RESOURCE_GOLD];
  this->resource = -1;
  this->costSingleResource = 0;
  for(int i = 0; i < RESOURCE_GOLD; ++i) {
    if(resourceCosts[i]) {
      this->resource = i;
      this->costSingleResource = resourceCosts[this->resource];
      break;
    }
  }
}

int recruitUnit::Open(int id) {
  ScriptCallback("OnUnitRecruit", this->creatureType);

  this->window = new heroWindow(143, 16, this->resource == -1 ? "recruit0.bin" : "recruit1.bin");
  if(!this->window)
    MemError();

  this->amountSelected = 0;
  this->costTotalGold = 0;
  this->costTotalResource = 0;
  SetupRecruitWin(this->window, this->creatureType, this->costSingleGold, this->resource, this->costSingleResource, *this->available);
  
  gpMouseManager->SetPointer("advmice.mse", 0, -999);
  this->Update();
  gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, 5, 30720, 16392);
  gpWindowManager->AddWindow(this->window, -1, 1);

  int buyableByGold = gpCurPlayer->resources[RESOURCE_GOLD] / this->costSingleGold;
  if(this->resource == -1) {
    this->maxBuyable = buyableByGold;
  } else {
    int maxBuyable = buyableByGold;
    int buyableByResource = gpCurPlayer->resources[this->resource] / this->costSingleResource;
    if(buyableByGold >= buyableByResource)
      maxBuyable = buyableByResource;
    this->maxBuyable = maxBuyable;
  }

  if(*this->available < this->maxBuyable)
    this->maxBuyable = *this->available;

  this->field_62 = 0;
  this->field_66 = 0;
  if(!*this->available) {
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, 6, 30722, 2);
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, 5, 30722, 16392);
  }

  hmnuRecruitSave = hmnuCurrent;
  KBChangeMenu(hmnuDflt);

  this->type = 16384;
  this->idx = id;
  this->ready = 1;
  strcpy(this->name, "recruitManager");
  return 0;
}

void recruitUnit::Update() {
  tag_message evt;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 3;
  sprintf(gText, "%s%d", "Available: ", *this->available);
  evt.yCoordOrFieldID = 67;
  evt.payload = gText;
  this->window->BroadcastMessage(evt);
  sprintf(gText, "%d", this->amountSelected);
  evt.yCoordOrFieldID = 68;
  this->window->BroadcastMessage(evt);
  this->costTotalGold = this->costSingleGold * this->amountSelected;
  sprintf(gText, "%d", this->costTotalGold);
  evt.yCoordOrFieldID = 77;
  this->window->BroadcastMessage(evt);
  if(this->resource != -1) {
    this->costTotalResource = this->costSingleResource * this->amountSelected;
    sprintf(gText, "%d", this->costTotalResource);
    evt.yCoordOrFieldID = 79;
    this->window->BroadcastMessage(evt);
  }
}

void __fastcall SetupRecruitWin(heroWindow *window, int creature, int goldCost, int resourceCost, int resourceAmt, int numAvail) {
  sprintf(gText, "Recruit %s", GetMonsterName(creature));
  gText[8] = toupper(gText[8]);
  tag_message evt;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 3;
  evt.yCoordOrFieldID = 64;
  evt.payload = gText;
  window->BroadcastMessage(evt);
  sprintf(gText, "%d", goldCost);
  evt.yCoordOrFieldID = 73;
  window->BroadcastMessage(evt);
  if(resourceCost != -1) {
    sprintf(gText, "%d", resourceAmt);
    evt.yCoordOrFieldID = 75;
    window->BroadcastMessage(evt);
  }
  sprintf(gText, "%s%d", "Available: ", numAvail);
  evt.yCoordOrFieldID = 67;
  evt.payload = gText;
  window->BroadcastMessage(evt);
  sprintf(gText, "monh%04d.icn", creature);
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 9;
  evt.yCoordOrFieldID = 66;
  evt.payload = gText;
  window->BroadcastMessage(evt);
  if(resourceCost != -1) {
    evt.xCoordOrKeycode = 4;
    evt.yCoordOrFieldID = 74;
    evt.payload = (void *)resourceCost;
    window->BroadcastMessage(evt);
    evt.xCoordOrKeycode = 4;
    evt.yCoordOrFieldID = 78;
    window->BroadcastMessage(evt);
  }
}