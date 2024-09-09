#include<string>
#include<Windows.h>

#include "base.h"
#include "combat/creatures.h"
#include "dialog.h"
#include "game/game.h"
#include "gui.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "spell/spell_constants.h"

extern heroWindowManager *gpWindowManager;
extern heroWindow *pNormalDialogWindow;
extern int giDialogTimeout;
extern int giResType1;
void H2MessageBox(char* msg) {
	if (msg) {
		NormalDialog(msg, DIALOG_OKAY, -1, -1, -1, 0, -1, 0, -1, 0);
	}
}

void H2MessageBox(std::string &msg) {
  if (!msg.empty()) {
    H2MessageBox(&msg[0]);
  }
}

bool H2QuestionBox(char* msg) {
  NormalDialog(msg, DIALOG_YES_NO, -1,-1,-1,0,-1,0,-1,0);
  return gpWindowManager->buttonPressedCode != BUTTON_NO;
}



char* H2InputBox(char* msg, int len) {
  char* res = (char*) ALLOC(len+1);
  GetDataEntry(msg, res, len + 1, 0, 0, 1);
  return res;
}

void DisplayError(const char* msg, const char* title) {
	MessageBoxA(NULL, msg, title, MB_OK);
}

void DisplayError(std::string msg, std::string title) {
	MessageBoxA(NULL, msg.c_str(), title.c_str(), MB_OK);
}

extern int giResType2;
extern int giResExtra1;
extern int giResExtra2;
extern SSpellInfo gsSpellInfo[];
extern char *gStatNames[NUM_PRIMARY_SKILLS];
extern mouseManager* gpMouseManager;
extern int __fastcall WaitHandler(struct tag_message &);

void __fastcall NormalDialog(char *msg, int type, int x, int y, int img1Type, int img1Arg, int img2Type, int img2Arg, int writeOr, signed int timeout) {
  if(!gbRemoteOn)
    timeout = 0;
  if(timeout <= 1 || timeout >= 20000)
    giDialogTimeout = timeout;
  else
    giDialogTimeout = KBTickCount() + timeout;
  int offsetX = 0;
  int offsetY = 0;
  int widgetFieldId = 100;
  int width = 0;
  bool primSkillFlag = false;
  if(img1Type == IMAGE_GROUP_PRIMARY_SKILLS && img1Arg >= 100) {
    img1Arg -= 100;
    primSkillFlag = true;
  }
  if(img1Type > IMAGE_GROUP_UNIT && img1Type < IMAGE_GROUP_PRIMARY_SKILLS)
    img1Type = IMAGE_EMPTY;
  heroWindow *pNormalDialogWindow_old = pNormalDialogWindow;
  int giResType1_old = giResType1;
  int giResExtra1_old = giResExtra1;
  int giResType2_old = giResType2;
  int giResExtra2_old = giResExtra2;

  giResType1 = img1Type;
  giResExtra1 = img1Arg;
  giResType2 = img2Type;
  giResExtra2 = img2Arg;
  int imgTypes[2];
  int imgArgs[2];
  imgTypes[0] = img1Type;
  imgArgs[0] = img1Arg;
  imgTypes[1] = img2Type;
  imgArgs[1] = img2Arg;
  int numLines = bigFont->LineLength(msg, 244);
  int msgHeight = 16 * numLines;

  int maxImgHeight = 0;
  int height = 0;
  if(type != DIALOG_RIGHT_CLICK)
    msgHeight += 39;
  for(int i = 0; i < 2; ++i) {
    switch(imgTypes[i]) {
    case IMAGE_GROUP_ARTIFACTS:
      height = 76;
      break;
    case IMAGE_LUCK:
      height = 28;
      break;
    case IMAGE_BADLUCK:
      height = 57;
      break;
    case IMAGE_GOOD_MORALE:
      height = 62;
      break;
    case IMAGE_BAD_MORALE:
      height = 59;
      break;
    case IMAGE_EXP:
      height = (unsigned int)(imgArgs[i] + 1) < 1 ? 64 : 76;
      break;
    case IMAGE_GROUP_PLAYERS:
      height = 55;
      break;
    case IMAGE_GROUP_HERO:
      height = 111;
      break;
    case IMAGE_GOLD:
      height = 26;
      break;
    case IMAGE_WOOD:
    case IMAGE_MERCURY:
    case IMAGE_ORE:
    case IMAGE_SULFUR:
    case IMAGE_CRYSTALS:
    case IMAGE_GEMS:
      height = 44;
      break;
    case IMAGE_GROUP_SPELLS:
      height = 79;
      break;
    case IMAGE_GROUP_SECONDARY_SKILLS:
      height = 81;
      break;
    case IMAGE_GROUP_UNIT:
      height = 105;
      break;
    case IMAGE_GROUP_PRIMARY_SKILLS:
      height = 105;
      break;
    default:
      height = 0;
      break;
    }
    if(height > maxImgHeight)
      maxImgHeight = height;
  }
  if(maxImgHeight > 0)
    msgHeight += maxImgHeight + 14;
  int windowType = (msgHeight - 25) / 45;
  if(windowType > 6)
    windowType = 6;

  int imgOffsetX = 306;
  int imgOffsetY = 45 * windowType + 180;
  if(x == -1 || imgOffsetX + x >= 639)
    x = 159;
  if(y == -1 || imgOffsetY + y >= 479) {
    y = (480 - imgOffsetY) / 2;
    if(y > 28)
      y = 28;
  }

  char text[50];
  sprintf(text, "evntwin%d.bin", windowType);
  pNormalDialogWindow = new heroWindow(x, y, text);
  if(!pNormalDialogWindow)
    MemError();

  if(type != DIALOG_LEARN_CHOICE && type != 8)
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_LEARN_LEFT, 6, (void *)6);
  if(type != DIALOG_LEARN_CHOICE)
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_LEARN_RIGHT, 6, (void *)6);
  if(type != DIALOG_CANCEL_ALT && type != DIALOG_CANCEL)
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_CANCEL, 6, (void *)6);
  if(type != DIALOG_OKAY_ALT && type != DIALOG_OKAY && type != DIALOG_CANCEL)
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_OK, 6, (void *)6);
  if(type != DIALOG_YES_NO) {
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_YES, 6, (void *)6);
	GUIBroadcastMessage(pNormalDialogWindow, BUTTON_NO, 6, (void *)6);
  }

  char *buf[2];
  for(int i = 0; i < 2; ++i) {
    if(imgTypes[i] == IMAGE_EMPTY)
      break;
    buf[i] = (char *)BaseAlloc(80u, __FILE__, __LINE__);
	int borderSpriteIdx;
    if(imgTypes[i] > IMAGE_GOLD) {
      switch(imgTypes[i]) {
      case IMAGE_GROUP_SPELLS:
        sprintf(buf[i], "%s", gSpellNames[imgArgs[i]]);
        strcpy(text, "spells.icn");
        borderSpriteIdx = gsSpellInfo[imgArgs[i]].magicBookIconIdx;
        break;
      case IMAGE_GROUP_PLAYERS:
        sprintf(buf[i], "%s", "");
        strcpy(text, "brcrest.icn");
        borderSpriteIdx = imgArgs[i];
        break;
      case IMAGE_GROUP_PRIMARY_SKILLS:
        sprintf(buf[i], "%s", "");
        strcpy(text, "primskil.icn");
        borderSpriteIdx = 4;
        break;
      case IMAGE_GROUP_UNIT:
        sprintf(buf[i], "%s", "");
        strcpy(text, "strip.icn");
        borderSpriteIdx = 12;
        break;
      case IMAGE_GROUP_SECONDARY_SKILLS:
		if((imgArgs[i] / 3) == 15)
		  sprintf(buf[i], "Cybernetics");
		else
		  sprintf(buf[i], "%s", gSecondarySkills[imgArgs[i] / 3]);
        strcpy(text, "secskill.icn");
        borderSpriteIdx = imgArgs[i] / 3 + 1;
        break;
      case IMAGE_GROUP_HERO:
		strcpy(buf[i], "");
        sprintf(text, "surrendr.icn");
        borderSpriteIdx = 4;
        break;
      default:
        if(imgTypes[i] < IMAGE_LUCK || imgTypes[i] > IMAGE_EXP) {
          strcpy(buf[i], "");
          strcpy(text, "resource.icn");
          borderSpriteIdx = imgTypes[i];
        } else {
          strcpy(buf[i], "");
          strcpy(text, "expmrl.icn");
          borderSpriteIdx = imgTypes[i] - 10;
          if(imgTypes[i] == IMAGE_EXP && imgArgs[i] != IMAGE_EMPTY)
            sprintf(buf[i], "%d", imgArgs[i]);
        }
        break;
      }
    } else {
      if(imgArgs[i] <= 0) {
        if(imgArgs[i]) {
          if(imgArgs[i] >= -100000)
            sprintf(buf[i], "%d/day", -imgArgs[i]);
          else
            sprintf(buf[i], "%d", imgArgs[i] + 100000);
        } else {
          strcpy(buf[i], "");
        }
      } else {
        sprintf(buf[i], "%d", imgArgs[i]);
      }
      strcpy(text, "resource.icn");
      borderSpriteIdx = imgTypes[i];
    }

    switch(imgTypes[i]) {
    case IMAGE_GROUP_PRIMARY_SKILLS:
      width = 94;
      height = 105;
      break;
    case IMAGE_GROUP_ARTIFACTS:
      width = 76;
      height = 76;
      break;
    case IMAGE_LUCK:
      width = 64;
      height = 28;
      break;
    case IMAGE_BADLUCK:
      width = 64;
      height = 57;
      break;
    case IMAGE_GOOD_MORALE:
      width = 64;
      height = 62;
      break;
    case IMAGE_BAD_MORALE:
      width = 64;
      height = 59;
      break;
    case IMAGE_EXP:
      width = 64;
      height = 64;
      break;
    case IMAGE_GROUP_PLAYERS:
      width = 50;
      height = 55;
      break;
    case IMAGE_GROUP_HERO:
      width = 111;
      height = 105;
      break;
    case IMAGE_GOLD:
      width = 76;
      height = 26;
      break;
    case IMAGE_WOOD:
    case IMAGE_MERCURY:
    case IMAGE_ORE:
    case IMAGE_SULFUR:
    case IMAGE_CRYSTALS:
    case IMAGE_GEMS:
      width = 38;
      height = 32;
      break;
    case IMAGE_GROUP_SPELLS:
      width = 70;
      height = 55;
      break;
    case IMAGE_GROUP_SECONDARY_SKILLS:
      width = 75;
      height = 65;
      break;
    case IMAGE_GROUP_UNIT:
      width = 94;
      height = 105;
      break;
    default:
      break;
    }
    int height_tmp = height;
    if(strlen(buf[i]))
      height += 12;
    if(i) {
      offsetX = imgOffsetX - 87;
    } else if(imgTypes[1] == IMAGE_EMPTY) {
      offsetX = (imgOffsetX - 17) / 2 + 17;
    } else {
      offsetX = 104;
    }
    offsetY = imgOffsetY - height - 48;
    if(type != DIALOG_RIGHT_CLICK)
      offsetY -= 39;
    if(imgTypes[0] == IMAGE_GROUP_SECONDARY_SKILLS && imgTypes[1] == IMAGE_GROUP_SECONDARY_SKILLS) {
      if(i)
        offsetX += 4;
      else
        offsetX -= 4;
    }

	iconWidget *icnWidget = new iconWidget(
      offsetX + ((unsigned int)(imgTypes[i] - 8) < 1 ? 2 : 0) - width / 2,
      offsetY,
      width,
      height_tmp,
      text,
      borderSpriteIdx,
      0,
      -1,
      ((unsigned int)(imgTypes[i] - 8) < 1) + 16,
      1);
    if(!icnWidget)
      MemError();
    pNormalDialogWindow->AddWidget(icnWidget, -1);

    if(imgTypes[i] == IMAGE_GROUP_ARTIFACTS) {
	  iconWidget *widget = new iconWidget(
        offsetX - width / 2 + 6,
        offsetY + 6,
        76,
        76,
        "artifact.icn",
        imgArgs[i] + 1,
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
    }
    if(imgTypes[i] == IMAGE_GROUP_PRIMARY_SKILLS) {
      iconWidget *widget = new iconWidget(
        offsetX - width / 2 + 6,
        offsetY + 6,
        82,
        93,
        "primskil.icn",
        imgArgs[i],
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
      strcpy(buf[i], gStatNames[imgArgs[i]]);
    }
    if(imgTypes[i] == IMAGE_GROUP_UNIT) {
	  iconWidget *widget = new iconWidget(
        offsetX - width / 2 + 6,
        offsetY + 6,
        82,
        93,
        "strip.icn",
        gMonsterDatabase[imgArgs[i]].faction + 4,
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);

      sprintf(text, "monh%04d.icn", imgArgs[i]);
	  widget = new iconWidget(offsetX - width / 2 + 6, offsetY + 6, 82, 93, text, 0, 0, -1, 16, 1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
    }
    if(imgTypes[i] == IMAGE_GROUP_PLAYERS) {
      iconWidget *widget = new iconWidget(
        offsetX - width / 2 - 4,
        offsetY - 4,
        58,
        55,
        "brcrest.icn",
        6,
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
    }
    if(imgTypes[i] == IMAGE_GROUP_SECONDARY_SKILLS) {
	  iconWidget *widget = new iconWidget(
        offsetX - width / 2 - 3,
        offsetY - 3,
        71,
        81,
        "secskill.icn",
        15,
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
    }
    if(imgTypes[i] == IMAGE_GROUP_HERO) {
      sprintf(text, "port%04d.icn", imgArgs[i]);
	  iconWidget *widget = new iconWidget(
        offsetX - width / 2 + 5,
        offsetY + 5,
        101,
        95,
        text,
        0,
        0,
        -1,
        16,
        1);
      if(!widget)
        MemError();
      pNormalDialogWindow->AddWidget(widget, -1);
    }
	int posY;
    if(imgTypes[i] == IMAGE_GROUP_SECONDARY_SKILLS) {
	  widgetFieldId++;
	  textWidget *widget = new textWidget(
        offsetX - 50,
		offsetY + height - 72,
        100,
        (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
        buf[i],
        "smalfont.fnt",
        1,
		widgetFieldId,
        512,
        1);
      if(!widget)
        MemError();	  
      pNormalDialogWindow->AddWidget(widget, -1);

      buf[i] = (char *)BaseAlloc(0x50u, __FILE__, __LINE__);
      posY = offsetY + height - 24;
      sprintf(buf[i], "%s", secondarySkillLevels[imgArgs[i] % 3 + 1]);
    } else if(imgTypes[i] == IMAGE_GROUP_PRIMARY_SKILLS) {
      posY = offsetY + height - 93;
    } else {
      posY = offsetY + height - 10;
    }

	widgetFieldId++;
    textWidget *txtWidget = new textWidget(
      offsetX - 50,
      posY,
      100,
      (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
      buf[i],
      "smalfont.fnt",
      1,
      widgetFieldId,
      512,
      1);
    if(!txtWidget)
      MemError();	
    pNormalDialogWindow->AddWidget(txtWidget, -1);

    if(imgTypes[i] == IMAGE_GROUP_PRIMARY_SKILLS && primSkillFlag) {
      char *plusOneBuf = (char *)BaseAlloc(5u, __FILE__, __LINE__);
      strcpy(plusOneBuf, "+1 ");
	  widgetFieldId++;
	  textWidget *widget = new textWidget(
        offsetX - 50,
        offsetY + height - 22,
        100,
        16,
        plusOneBuf,
        "bigfont.fnt",
        1,
        widgetFieldId,
        512,
        1);
      if(!widget)
        MemError();	  
      pNormalDialogWindow->AddWidget(widget, -1);
    }
    border *brdr = new border(offsetX - width / 2, offsetY, width, height, i + 7700, 1, 0, 0);
    pNormalDialogWindow->AddWidget(brdr, -1);
  }
  GUIBroadcastMessage(pNormalDialogWindow, 1, 3, msg);

  if(writeOr == 1) {
    char *content = (char *)BaseAlloc(3u, __FILE__, __LINE__);
    strcpy(content, "or");
    textWidget *widget = new textWidget(imgOffsetX / 2 - 10, offsetY + 43, 40, 12, content, "smalfont.fnt", 1, widgetFieldId, 512, 1);
    if(!widget)
      MemError();
    pNormalDialogWindow->AddWidget(widget, -1);
  }

  int cursorCategory = gpMouseManager->cursorCategory;
  int mouseSpriteIdx = gpMouseManager->spriteIdx;
  while(gpMouseManager->cursorDisabled)
    gpMouseManager->ShowColorPointer();
  gpMouseManager->SetPointer("advmice.mse", 0, -999);

  if(type != DIALOG_CANCEL_ALT && type != DIALOG_OKAY_ALT) {
    if(type == DIALOG_RIGHT_CLICK) {
      gpWindowManager->AddWindow(pNormalDialogWindow, -1, 1);
      QuickViewWait();
      gpWindowManager->RemoveWindow(pNormalDialogWindow);
    } else {
      gpWindowManager->DoDialog(pNormalDialogWindow, EventWindowHandler, 0);
    }
  } else {
    gpWindowManager->DoDialog(pNormalDialogWindow, WaitHandler, 0);
  }

  delete pNormalDialogWindow;
  gpMouseManager->SetPointer("\0\0\0", mouseSpriteIdx, cursorCategory);
  giResType1 = giResType1_old;
  giResExtra1 = giResExtra1_old;
  giResType2 = giResType2_old;
  giResExtra2 = giResExtra2_old;
  pNormalDialogWindow = pNormalDialogWindow_old;
  return;
}

extern int giOverviewItems[];
extern int giOverviewType;
extern iconWidget *OVScrollKnob;
extern int giOverviewTop[];
extern int iLastDynamicType;
extern int iLastDynamicTop;
extern heroWindow *overWin;
extern int __fastcall GetMobilityFrame(int a1);
extern int __fastcall GetManaFrame(signed int a1);
extern char *cSecSkillDesc[14][3];

std::vector<iconWidget*> icons;
std::vector<textWidget*> texts;

void game::Overview() {
	this->Overview_orig();
	icons.clear();
	texts.clear();
}

void game::SetupDynamicStuff(int a2, int a3, int a4) {
  char *str;

  if(a3) {
    if(giOverviewItems[giOverviewType] > 4) {
	  float knobOffsetY = 303.0 / (double)(giOverviewItems[giOverviewType] - 4);
      OVScrollKnob->offsetY = (signed __int64)((double)giOverviewTop[giOverviewType] * knobOffsetY + 18.0 + 0.4);
    } else {
      OVScrollKnob->offsetY = 169;
    }
  }

  if(a4 || giOverviewType != iLastDynamicType || giOverviewTop[iLastDynamicType] != iLastDynamicTop) {
	  for(auto icn : icons) {
		  overWin->RemoveWidget(icn);
		  delete icn;
	  }
	  icons.clear();
	  for(auto txt : texts) {
		  overWin->RemoveWidget(txt);
		  delete txt;
	  }
	  texts.clear();
    for(int row = 0; row < 4; ++row) {
      int fieldOffset = 200 * row + 200;
      if(row + giOverviewTop[giOverviewType] >= giOverviewItems[giOverviewType])
        break;

	  iconWidget *icn = new iconWidget(
		  30,
		  86 * row + 17,
		  594,
		  82,
		  "overview.icn",
		  giOverviewType + 10,
		  0,
		  200 * row + 202,
		  16,
		  1);

	  icons.push_back(icn);
	  overWin->AddWidget(icn, -1);

      if(giOverviewType == 1) {
        town *twn = &this->castles[*(&gpCurPlayer->castlesOwned[row] + giOverviewTop[giOverviewType])];
		str = new char[strlen(twn->name)];
        strcpy(str, twn->name);

          textWidget* txt = new textWidget(
            35,
            86 * row + 80,
            132,
            10,
            str,
            "smalfont.fnt",
            1,
            200 * row + 203,
            512,
            1);

		texts.push_back(txt);
        overWin->AddWidget(txt, -1);

        int imgIdx = twn->factionID;
        if(!twn->BuildingBuilt(BUILDING_CASTLE))
          imgIdx += 6;
		iconWidget *icn = new iconWidget(
            47,
            86 * row + 36,
            46,
            22,
            "minitown.icn",
            imgIdx,
            0,
            200 * row + 204,
            16,
            1);
		icons.push_back(icn);
		overWin->AddWidget(icn, -1);

        if(gpGame->builtToday[twn->idx]) {
			iconWidget *icn = new iconWidget(
              42,
              86 * row + 31,
              0,
              0,
              "locators.icn",
              24,
              0,
              200 * row + 244,
              16,
              1);
			icons.push_back(icn);
			overWin->AddWidget(icn, -1);
        }

        bool hasCaptain = false;
        hero *hro = nullptr;
        if(twn->visitingHeroIdx == -1) {
          if(twn->BuildingBuilt(BUILDING_CAPTAIN))
            hasCaptain = true;
        } else {
          hro = &this->heroes[twn->visitingHeroIdx];
        }
        if(hro || hasCaptain) {
			iconWidget *icn = new iconWidget(
            112,
            86 * row + 36,
            46,
            22,
            "portxtra.icn",
            0,
            0,
            200 * row + 239,
            16,
            1);
			icons.push_back(icn);
			overWin->AddWidget(icn, -1);

          std::string icnName;
		  int spriteId;
          if(hasCaptain) {
            spriteId = twn->factionID;
            icnName = "minicapt.icn";
          }
          else {
            spriteId = hro->heroID;
            icnName = "miniport.icn";
          }
            
          
		  icn = new iconWidget(
            107,
            86 * row + 31,
            51,
            27,
            &icnName[0],
            spriteId,
            0,
            200 * row + 240,
            16,
            1);

		  icons.push_back(icn);
		  overWin->AddWidget(icn, -1);


		  int mobility = 0;
          if(!hasCaptain)
            mobility = hro->remainingMobility;

		  icn = new iconWidget(
            112,
            86 * row + 36,
            0,
            0,
            "mobility.icn",
			GetMobilityFrame(mobility),
            0,
            200 * row + 243,
            16,
            1);

		  icons.push_back(icn);
		  overWin->AddWidget(icn, -1);
		  int spellpoints;
		  if(!hasCaptain)
			  spellpoints = hro->spellpoints;
		  else {
			if(twn->factionID != 1 && twn->factionID)
				spellpoints = 20;
			else
				spellpoints = 10;
		  }          	  
          
		  icn = new iconWidget(
            151,
            86 * row + 36,
            0,
            0,
            "mana.icn",
			GetManaFrame(spellpoints),
            0,
            200 * row + 241,
            16,
            1);

		  icons.push_back(icn);
		  overWin->AddWidget(icn, -1);

        }
        int creatureCounter = 0;
        for(int creature = 0; creature < CREATURES_IN_ARMY; ++creature) {
          if(twn->garrison.creatureTypes[creature] != -1 && twn->garrison.quantities[creature] > 0) {
			  iconWidget *icn = new iconWidget(
                41 * creatureCounter + 173,
                86 * row + 35,
                42,
                40,
                "mons32.icn",
                twn->garrison.creatureTypes[creature],
                0,
                creature + fieldOffset + 5,
                17,
                1);

			  icons.push_back(icn);
			  overWin->AddWidget(icn, -1);
			  std::string quantity = std::to_string(twn->garrison.quantities[creature]);
			  str = new char[quantity.length()];
			  strcpy(str, quantity.c_str());

			textWidget* txt = new textWidget(
                41 * creatureCounter + 173,
                86 * row + 81,
                40,
                12,
                str,
                "smalfont.fnt",
                1,
                creature + fieldOffset + 10,
                512,
                1);

			  texts.push_back(txt);
			  overWin->AddWidget(txt, -1);
            ++creatureCounter;
          }
        }
        int dwellingCounter = 0;
		int v59;
        for(int dwelling = 0; dwelling < NUM_DWELLINGS; ++dwelling) {
          switch(dwelling) {
          case 0:
            v59 = 0;
            break;
          case 1:
            v59 = 1;
            break;
          case 2:
            v59 = 6;
            break;
          case 3:
            v59 = 2;
            break;
          case 4:
            v59 = 7;
            break;
          case 5:
            v59 = 3;
            break;
          case 6:
            v59 = 8;
            break;
          case 7:
            v59 = 4;
            break;
          case 8:
            v59 = 9;
            break;
          case 9:
            v59 = 5;
            break;
          case 10:
            v59 = 10;
            break;
          default:
            v59 = 11;
            break;
          }
          if((1 << (v59 + BUILDING_DWELLING_1)) & twn->buildingsBuiltFlags) {
			  iconWidget *icn = new iconWidget(
              41 * dwellingCounter + 378,
              86 * row + 35,
              42,
              40,
              "mons32.icn",
              gDwellingType[twn->factionID][v59],
              0,
              fieldOffset + v59 + 15,
              17,
              1);

			  icons.push_back(icn);
			  overWin->AddWidget(icn, -1);
			  std::string numCreatures = std::to_string(twn->numCreaturesInDwelling[v59]);
			  str = new char[numCreatures.length()];
			  strcpy(str, numCreatures.c_str());

			textWidget* txt = new textWidget(
              41 * dwellingCounter + 378,
              86 * row + 81,
              40,
              12,
              str,
              "smalfont.fnt",
              1,
              fieldOffset + v59 + 27,
              512,
              1);
			texts.push_back(txt);
			overWin->AddWidget(txt, -1);
            ++dwellingCounter;
          }
        }
      } else {
        hero *hro = &this->heroes[*(&gpCurPlayer->heroesOwned[row] + giOverviewTop[giOverviewType])];
		iconWidget *icn = new iconWidget(
          35,
          86 * row + 21,
          46,
          22,
          "portxtra.icn",
          0,
          0,
          200 * row + 300,
          16,
          1);

		icons.push_back(icn);
		overWin->AddWidget(icn, -1);
		icn = new iconWidget(
          30,
          86 * row + 16,
          51,
          27,
          "miniport.icn",
          hro->heroID,
          0,
          200 * row + 301,
          16,
          1);
		icons.push_back(icn);
		overWin->AddWidget(icn, -1);

		icn = new iconWidget(
          35,
          86 * row + 21,
          0,
          0,
          "mobility.icn",
		  GetMobilityFrame(hro->remainingMobility),
          0,
          200 * row + 303,
          16,
          1);

		icons.push_back(icn);
		overWin->AddWidget(icn, -1);

		icn = new iconWidget(
          74,
          86 * row + 21,
          0,
          0,
          "mana.icn",
		  GetManaFrame(hro->spellpoints),
          0,
          200 * row + 241,
          16,
          1);

		icons.push_back(icn);
		overWin->AddWidget(icn, -1);

        for(int skillIdx = 0; skillIdx < NUM_PRIMARY_SKILLS; ++skillIdx) {
		  std::string skillVal = std::to_string(hro->Stats(skillIdx));
		  str = new char[skillVal.length()];
		  strcpy(str, skillVal.c_str());

		  textWidget* txt = new textWidget(
            35 * skillIdx + 105,
            86 * row + 39,
            14,
            8,
			str,
            "smalfont.fnt",
            1,
            skillIdx + fieldOffset + 142,
            512,
            2);
		  texts.push_back(txt);
		  overWin->AddWidget(txt, -1);
        }
        for(int pSkill = 0; pSkill < NUM_PRIMARY_SKILLS; ++pSkill) {
			iconWidget *icn = new iconWidget(
              35 * pSkill + 87,
              86 * row + 17,
              35,
              30,
              "overview.icn",
              15,
              0,
              pSkill + fieldOffset + 170,
              16,
              1);

			icons.push_back(icn);
			overWin->AddWidget(icn, -1);
        }
        int creatureCounter = 0;
        for(int creature = 0; creature < CREATURES_IN_ARMY; ++creature) {
          if(hro->army.creatureTypes[creature] != -1 && hro->army.quantities[creature] > 0) {
			  iconWidget *icn = new iconWidget(
                40 * creatureCounter + 30,
                86 * row + 47,
                42,
                40,
                "mons32.icn",
                hro->army.creatureTypes[creature],
                0,
                creature + fieldOffset + 104,
                17,
                1);

			  icons.push_back(icn);
			  overWin->AddWidget(icn, -1);
			  std::string quantity = std::to_string(hro->army.quantities[creature]);
			  str = new char[quantity.length()];
			  strcpy(str, quantity.c_str());
			textWidget* txt = new textWidget(
              40 * creatureCounter + 30,
              86 * row + 87,
              40,
              12,
              str,
              "smalfont.fnt",
              1,
              creature + fieldOffset + 109,
              512,
              1);

			texts.push_back(txt);
			overWin->AddWidget(txt, -1);
            ++creatureCounter;
          }
        }
        for(int skillIdx = 0; skillIdx < 8; ++skillIdx) {
          int sSkill = hro->GetNthSS(skillIdx);
          if(sSkill != -1) {
            int subRow = skillIdx / 4;
            int column = (unsigned __int8)((char)skillIdx % -4);

			iconWidget *icn = new iconWidget(
                35 * column + 233,
                86 * row + 42 * subRow + 20,
                34,
                34,
                "overview.icn",
                12,
                0,
                skillIdx + fieldOffset + 154,
                16,
                1);

			icons.push_back(icn);
			overWin->AddWidget(icn, -1);

			int imgIdx = sSkill;
			if(hro->factionID == FACTION_CYBORG && sSkill == SECONDARY_SKILL_WISDOM)
			  imgIdx = 14; // Cybernetics secondary skill small image
			icn = new iconWidget(
              35 * column + 234,
              86 * row + 42 * subRow + 21,
              32,
              32,
              "miniss.icn",
			  imgIdx,
              0,
              skillIdx + fieldOffset + 146,
              16,
              1);

			icons.push_back(icn);
			overWin->AddWidget(icn, -1);

            int lvl = hro->GetSSLevel(sSkill);
			std::string level = std::to_string(lvl);
			str = new char[level.length()];
			strcpy(str, level.c_str());

			textWidget* txt = new textWidget(
              35 * column + 255,
              86 * row + 42 * subRow + 45,
              8,
              8,
              str,
              "smalfont.fnt",
              1,
              skillIdx + fieldOffset + 162,
              512,
              2);

			texts.push_back(txt);
			overWin->AddWidget(txt, -1);
          }
        }
        int artifactCounter = 0;
        for(int artifactIdx = 0; artifactIdx < MAX_ARTIFACTS; ++artifactIdx) {
          if(hro->artifacts[artifactIdx] != -1) {
            int subRow = artifactCounter / 7;
            int column = artifactCounter % 7;

			iconWidget *icn = new iconWidget(
              35 * column + 378,
              86 * row + 42 * subRow + 20,
              34,
              34,
              "overview.icn",
              12,
              0,
              artifactIdx + fieldOffset + 128,
              16,
              1);

			icons.push_back(icn);
			overWin->AddWidget(icn, -1);

			icn = new iconWidget(
              35 * column + 379,
              86 * row + 42 * subRow + 21,
              32,
              32,
              "artfx.icn",
              hro->artifacts[artifactIdx],
              0,
              artifactIdx + fieldOffset + 114,
              16,
              1);

			icons.push_back(icn);
            overWin->AddWidget(icn, -1);
            ++artifactCounter;
          }
        }
      }
    }
    if(a2) {
      overWin->DrawWindow(0, 110, 999);
      gpWindowManager->UpdateScreenRegion(30, 16, 0x262u, 341);
    }
  }
}

extern char *cSecSkillDesc[14][3];
extern soundManager* gpSoundManager;
extern char *cyberneticsDesc[3];

int __fastcall EventWindowHandler(tag_message &evt) {
	// Level up select secondary skill window
	if(giResType1 == 17 || giResType2 == 17) { 
		if(!gpSoundManager->MusicPlaying() && gpAdvManager->ready == 1)
			gpSoundManager->SwitchAmbientMusic(giTerrainToMusicTrack[gpAdvManager->currentTerrain]);

		if(giDialogTimeout && KBTickCount() > giDialogTimeout) {
			evt.eventCode = INPUT_GUI_MESSAGE_CODE;
			gpWindowManager->buttonPressedCode = evt.yCoordOrFieldID;
			evt.yCoordOrFieldID = 10;
			evt.xCoordOrKeycode = evt.yCoordOrFieldID;
			giDialogTimeout = 0;
			return 2;
		}

		if(evt.eventCode != INPUT_GUI_MESSAGE_CODE)
			return 1;

		if(evt.xCoordOrKeycode == 14) {
			if((evt.inputTypeBitmask >> 8) & 2) { // right click
				int imgArg = -1;
				int widgetId = evt.yCoordOrFieldID;
				if(widgetId == 7700) { // left skill
					imgArg = giResExtra1;
				} else if(widgetId == 7701) { // right skill
					imgArg = giResExtra2;
				} else
					return 1;
				if((imgArg / 3) == 15)
					NormalDialog(cyberneticsDesc[imgArg % 3], DIALOG_RIGHT_CLICK, -1, -1, -1, 0, -1, 0, -1, 0);
				else
					NormalDialog(cSecSkillDesc[imgArg / 3][imgArg % 3], DIALOG_RIGHT_CLICK, -1, -1, -1, 0, -1, 0, -1, 0);
			}
			return 1;
		}
		switch(evt.yCoordOrFieldID) {
			case 0x7800:
			case 0x7801:
			case 0x7802:
			case 0x7803:
			case 0x7805:
			case 0x7806:
			case 0x7807:
			case 0x7808:
				gpWindowManager->buttonPressedCode = evt.yCoordOrFieldID;
				evt.yCoordOrFieldID = 10;
				evt.xCoordOrKeycode = evt.yCoordOrFieldID;
				giDialogTimeout = 0;
				return 2;
			case 0x7804:
				return 1;
		}
		return 0;
	} else
		return EventWindowHandler_orig(evt);
}

void __fastcall UpdateHeroScreenStatusBar(struct tag_message &evt) {
	UpdateHeroScreenStatusBar_orig(evt);
	// Change hero screen secondary skill status bar message on hover
	int widgetId = evt.yCoordOrFieldID;
	if(widgetId >= 400 && widgetId < 424) {
		int skillIdx = widgetId - 400; // icon
		if(widgetId > 415) // bottom description
			skillIdx -= 16;
		else if(widgetId > 408) // top description
			skillIdx -= 8;
		if(gpHVHero->numSecSkillsKnown > skillIdx) {
			int skillType = gpHVHero->GetNthSS(skillIdx);
			if(gpHVHero->factionID == FACTION_CYBORG && skillType == SECONDARY_SKILL_WISDOM) {
				sprintf(gText, "View %s Cybernetics Info", secondarySkillLevels[gpHVHero->secondarySkillLevel[skillType]]);
				HeroMessageUpdate(gText);
			}
		}
	}
}

void __fastcall SetupHeroView() {
	int noDismiss = gbNoDismiss;
	if(gpHVHero->occupiedObjType == LOCATION_HERO_IN_CASTLE)
		noDismiss = 1;

	sprintf(gText, "%s the %s", gpHVHero->name, gAlignmentNames[gpHVHero->factionID]);
	GUIBroadcastMessage(heroWin, 2, 3, gText);

	if(gpHVHero->ownerIdx != giCurPlayer || gpCurPlayer->numHeroes == 1) {
		GUIBroadcastMessage(heroWin, 300, 5, (void *)4096);
		GUIBroadcastMessage(heroWin, 301, 5, (void *)4096);
		GUIBroadcastMessage(heroWin, 300, 6, (void *)2);
		GUIBroadcastMessage(heroWin, 301, 6, (void *)2);
	}

	for(int i = 0; i < 5; ++i) {
		GUIBroadcastMessage(heroWin, i + 81, 6, (void *)4);
		GUIBroadcastMessage(heroWin, i + 102, 6, (void *)4);
	}

	int xCoordOrKeycode;
	if(noDismiss || gpTownManager->field_15A || !gpCurPlayer->numCastles && gpCurPlayer->numHeroes == 1)
		xCoordOrKeycode = 6;
	else
		xCoordOrKeycode = 5;

	GUIBroadcastMessage(heroWin, 30723, xCoordOrKeycode, (void *)6);

	sprintf(gText, "port%04d.icn", gpHVHero->heroID);
	GUIBroadcastMessage(heroWin, 65, 9, gText);

	for(int i = 0; i < 4; ++i) {
		sprintf(gText, "%d", gpHVHero->Stats(i));
		GUIBroadcastMessage(heroWin, i + 76, 3, gText);
	}

	int v11 = gpGame->GetLuck(gpHVHero, 0, gpHVHero->GetOccupiedTown());
	int v12 = abs(v11);
	if(v12 <= 0)
		v12 = 1;

	int v9;
	for(int i = 0; i < 3; ++i) {
		if(i < v12)
			xCoordOrKeycode = 5;
		else
			xCoordOrKeycode = 6;
		if(i == 1 && v11) {
			v9 = 0;
		} else {
			if(i || !v11)
				v9 = i;
			else
				v9 = 1;
		}
		GUIBroadcastMessage(heroWin, v9 + 203, xCoordOrKeycode, (void *)6);
	}

	for(int i = 0; i < 3; ++i) {
		void *payload;
		if(v11 >= 0) {
			if(v11)
				payload = (void *)2;
			else
				payload = (void *)6;
		} else {
			payload = (void *)3;
		}
		GUIBroadcastMessage(heroWin, i + 203, 4, payload);
	}

	int v13 = gpHVHero->army.GetMorale(gpHVHero, gpHVHero->GetOccupiedTown(), 0);
	v12 = abs(v13);
	if(v12 <= 0)
		v12 = 1;

	for(int i = 0; i < 3; ++i) {
		if(i < v12)
			xCoordOrKeycode = 5;
		else
			xCoordOrKeycode = 6;
		if(i == 1 && v13) {
			v9 = 0;
		} else {
			if(i || !v13)
				v9 = i;
			else
				v9 = 1;
		}
		GUIBroadcastMessage(heroWin, xCoordOrKeycode, 4, (void *)6);
	}

	for(int i = 0; i < 3; ++i) {
		void *payload;
		if(v13 >= 0) {
			if(v13)
				payload = (void *)4;
			else
				payload = (void *)7;
		} else {
			payload = (void *)5;
		}
		GUIBroadcastMessage(heroWin, i + 200, 4, payload);
	}

	sprintf(gText, "%d", gpHVHero->experience);
	GUIBroadcastMessage(heroWin, 207, 3, gText);

	if(gpHVHero->flags & HERO_ARMY_COMPACT)
		xCoordOrKeycode = 6;
	else
		xCoordOrKeycode = 5;
	GUIBroadcastMessage(heroWin, 213, xCoordOrKeycode, (void *)4);

	if(gpHVHero->flags & HERO_ARMY_COMPACT)
		xCoordOrKeycode = 5;
	else
		xCoordOrKeycode = 6;
	GUIBroadcastMessage(heroWin, 215, xCoordOrKeycode, (void *)4);

	sprintf(gText, "%d/%d", gpHVHero->spellpoints, 10 * gpHVHero->Stats(PRIMARY_SKILL_KNOWLEDGE));
	GUIBroadcastMessage(heroWin, 212, 3, gText);

	sprintf(gText, "crest.icn");
	GUIBroadcastMessage(heroWin, 86, 9, gText);
	GUIBroadcastMessage(heroWin, 86, 4, (void *)gpCurPlayer->color);

	gpHVHero->UpdateArmies();
	for(int i = 0; i < 8; ++i) {
		if(gpHVHero->numSecSkillsKnown <= i) {
			GUIBroadcastMessage(heroWin, i + 400, 4, 0);
			GUIBroadcastMessage(heroWin, i + 408, 6, (void *)6);
			GUIBroadcastMessage(heroWin, i + 416, 6, (void *)6);
		} else {
			int imgIdx;
			int skill = gpHVHero->GetNthSS(i);
			if(skill == SECONDARY_SKILL_WISDOM & gpHVHero->factionID == FACTION_CYBORG)
				imgIdx = 16; // Cybernetics secondary skill image
			else
				imgIdx = skill + 1;
			GUIBroadcastMessage(heroWin, i + 400, 4, (void *)imgIdx);
			GUIBroadcastMessage(heroWin, i + 408, 5, (void *)6);
			GUIBroadcastMessage(heroWin, i + 416, 5, (void *)6);

			char * str = "Cybernetics";
			if(!(skill == SECONDARY_SKILL_WISDOM & gpHVHero->factionID == FACTION_CYBORG))
				str = gSecondarySkills[skill];
			GUIBroadcastMessage(heroWin, i + 408, 3, str);

			char skillLevel = gpHVHero->GetSSLevel(skill);
			int v5 = skillLevel - gpHVHero->secondarySkillLevel[skill];
			if(v5 <= 0)
				sprintf(gText, "%s", secondarySkillLevels[gpHVHero->secondarySkillLevel[skill]]);
			else
				sprintf(gText, "%s+%d", secondarySkillLevels[gpHVHero->secondarySkillLevel[skill]], v5);
			GUIBroadcastMessage(heroWin, i + 416, 3, gText);
		}
	}

	for(int i = 0; i < 14; ++i) {
		if(gpHVHero->artifacts[i] == -1) {
			GUIBroadcastMessage(heroWin, i + 20, 4, 0);
			GUIBroadcastMessage(heroWin, i + 20, 6, (void *)2);
		} else {
			GUIBroadcastMessage(heroWin, i + 20, 5, (void *)2);
			GUIBroadcastMessage(heroWin, i + 20, 4, (void *)(gpHVHero->artifacts[i] + 1));
		}
	}

	tag_message evt;
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.yCoordOrFieldID = -1;
	evt.xCoordOrKeycode = -1;
	evt.payload = 0;
	UpdateHeroScreenStatusBar(evt);
}