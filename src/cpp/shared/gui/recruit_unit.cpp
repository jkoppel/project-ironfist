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
  gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_ADD_FLAGS, BUTTON_EXIT, 16392);
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
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_REMOVE_FLAGS, BUTTON_OK, 2);
    gpWindowManager->BroadcastMessage(INPUT_GUI_MESSAGE_CODE, GUI_MESSAGE_ADD_FLAGS, BUTTON_OK, 16392);
  }

  hmnuRecruitSave = hmnuCurrent;
  KBChangeMenu(hmnuDflt);

  this->type = MANAGER_TYPE_RECRUIT_UNIT;
  this->idx = id;
  this->ready = 1;
  strcpy(this->name, "recruitManager");
  return 0;
}

void recruitUnit::Update() {
  GUISetText(this->window, 67, "Available: " + std::to_string(*this->available));
  GUISetText(this->window, 68, std::to_string(this->amountSelected));
  this->costTotalGold = this->costSingleGold * this->amountSelected;
  GUISetText(this->window, 77, std::to_string(this->costTotalGold));
  if(this->resource != -1) {
    this->costTotalResource = this->costSingleResource * this->amountSelected;
    GUISetText(this->window, 79, std::to_string(this->costTotalResource));
  }
}

void __fastcall SetupRecruitWin(heroWindow *window, int creature, int goldCost, int resourceCost, int resourceAmt, int numAvail) {
  sprintf(gText, "Recruit %s", GetMonsterName(creature));
  gText[8] = toupper(gText[8]);
  GUISetText(window, 64, gText);
  GUISetText(window, 73, std::to_string(goldCost));
  if(resourceCost != -1) {
    GUISetImgIdx(window, 74, resourceCost);
    GUISetImgIdx(window, 78, resourceCost);
    GUISetText(window, 75, std::to_string(resourceAmt));
  }
  GUISetText(window, 67, "Available: " + std::to_string(numAvail));
  sprintf(gText, "monh%04d.icn", creature);
  GUISetIcon(window, 66, gText);
}