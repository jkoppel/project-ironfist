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
  return gpWindowManager->buttonPressedCode != BUTTON_CODE_CANCEL;
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

void __fastcall NormalDialog(char *msg, int a2, int x, int y, int img1Type, int img1Arg, int img2Type, int img2Arg, int writeOr, signed int a10) {
  //NormalDialog_orig(msg, a2, x, y, img1Type, img1Arg, img2Type, img2Arg, writeOr, a10);
  //if(img1Type == 17 && img1Arg == 45) {
	//  pNormalDialogWindow->idx = pNormalDialogWindow->idx;
  //}
  //return;
  __int16 v10; // ST54_2@186
  __int16 v11; // ST50_2@195
  __int16 v12; // ST4C_2@202
  char *msga; // [sp+18h] [bp-114h]@1
  textWidget *v16; // [sp+34h] [bp-F8h]@212
  border *v17; // [sp+38h] [bp-F4h]@207
  textWidget *v18; // [sp+3Ch] [bp-F0h]@201
  textWidget *v19; // [sp+40h] [bp-ECh]@194
  textWidget *v20; // [sp+44h] [bp-E8h]@185
  iconWidget *v21; // [sp+48h] [bp-E4h]@178
  iconWidget *v22; // [sp+4Ch] [bp-E0h]@171
  iconWidget *v23; // [sp+50h] [bp-DCh]@164
  iconWidget *v24; // [sp+54h] [bp-D8h]@157
  iconWidget *v25; // [sp+58h] [bp-D4h]@152
  iconWidget *v26; // [sp+5Ch] [bp-D0h]@145
  iconWidget *v27; // [sp+60h] [bp-CCh]@138
  iconWidget *v28; // [sp+64h] [bp-C8h]@132
  heroWindow *v29; // [sp+68h] [bp-C4h]@48
  char *plusOneBuf; // [sp+6Ch] [bp-C0h]@201
  __int16 height; // [sp+70h] [bp-BCh]@117
  int a3; // [sp+74h] [bp-B8h]@185
  int a3a; // [sp+74h] [bp-B8h]@190
  widget *v34; // [sp+78h] [bp-B4h]@208
  int borderSpriteIdx; // [sp+7Ch] [bp-B0h]@78
  signed int v36; // [sp+84h] [bp-A8h]@7
  heroWindow *v37; // [sp+88h] [bp-A4h]@13
  int spriteIdx; // [sp+8Ch] [bp-A0h]@218
  int v39; // [sp+90h] [bp-9Ch]@41
  char *content; // [sp+94h] [bp-98h]@212
  signed int v41; // [sp+98h] [bp-94h]@7
  tag_message event; // [sp+9Ch] [bp-90h]@53
  int v43; // [sp+B8h] [bp-74h]@13
  int v44; // [sp+BCh] [bp-70h]@13
  textWidget *component; // [sp+C0h] [bp-6Ch]@69
  int i; // [sp+C4h] [bp-68h]@15
  int v47; // [sp+C8h] [bp-64h]@7
  int v48; // [sp+CCh] [bp-60h]@7
  int numLines; // [sp+D0h] [bp-5Ch]@13
  int msgHeight; // [sp+D4h] [bp-58h]@13
  int v51; // [sp+D8h] [bp-54h]@7
  int width; // [sp+DCh] [bp-50h]@7
  int v53; // [sp+E0h] [bp-4Ch]@18
  int v54; // [sp+E4h] [bp-48h]@13
  int v55; // [sp+E8h] [bp-44h]@13
  int v56; // [sp+ECh] [bp-40h]@13
  int windowType; // [sp+F0h] [bp-3Ch]@39
  int imgArgs[2]; // [sp+104h] [bp-28h]@13
  int v60; // [sp+10Ch] [bp-20h]@41
  int buf[2]; // [sp+110h] [bp-1Ch]@70
  int imgTypes[2]; // [sp+118h] [bp-14h]@13
  signed int protoCategory; // [sp+120h] [bp-Ch]@218
  widget *guiObj; // [sp+124h] [bp-8h]@69
  char text[50];

  msga = msg;
  if(!gbRemoteOn)
    a10 = 0;
  if(a10 <= 1 || a10 >= 20000)
    giDialogTimeout = a10;
  else
    giDialogTimeout = KBTickCount() + a10;
  v51 = 0;
  v47 = 0;
  v36 = 100;
  width = 0;
  v48 = 0;
  v41 = 0;
  if(img1Type == 25 && img1Arg >= 100) {
    img1Arg -= 100;
    v41 = 1;
  }
  if(img1Type >= 19 && img1Type <= 24)
    img1Type = -1;
  v37 = pNormalDialogWindow;
  v54 = giResType1;
  v44 = giResExtra1;
  v56 = giResType2;
  v43 = giResExtra2;
  giResType1 = img1Type;
  giResExtra1 = img1Arg;
  giResType2 = img2Type;
  giResExtra2 = img2Arg;
  imgTypes[0] = img1Type;
  imgArgs[0] = img1Arg;
  imgTypes[1] = img2Type;
  imgArgs[1] = img2Arg;
  numLines = bigFont->LineLength(msga, 244);
  msgHeight = 16 * numLines;
  v55 = 0;
  if(a2 != 4)
    msgHeight += 39;
  for(i = 0; i < 2; ++i) {
    switch(imgTypes[i]) {
    case 7:
      v53 = 76;
      break;
    case 10:
      v53 = 28;
      break;
    case 11:
      v53 = 57;
      break;
    case 12:
      v53 = 62;
      break;
    case 13:
      v53 = 59;
      break;
    case 14:
      v53 = (unsigned int)(imgArgs[i] + 1) < 1 ? 64 : 76;
      break;
    case 9:
      v53 = 55;
      break;
    case 15:
      v53 = 111;
      break;
    case 6:
      v53 = 26;
      break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      v53 = 44;
      break;
    case 8:
      v53 = 79;
      break;
    case 17:
      v53 = 81;
      break;
    case 18:
      v53 = 105;
      break;
    case 25:
      v53 = 105;
      break;
    default:
      v53 = 0;
      break;
    }
    if(v53 > v55)
      v55 = v53;
  }
  if(v55 > 0)
    msgHeight += v55 + 14;
  windowType = (msgHeight - 25) / 45;
  if(windowType > 6)
    windowType = 6;
  v60 = 306;
  v39 = 45 * windowType + 180;
  if(x == -1 || v60 + x >= 639)
    x = 159;
  if(y == -1 || v39 + y >= 479) {
    y = (480 - v39) / 2;
    if(y > 28)
      y = 28;
  }
  sprintf(text, "evntwin%d.bin", windowType);
  v29 = new heroWindow(x, y, text);
  if(v29)
    pNormalDialogWindow = v29;
  else
    pNormalDialogWindow = 0;
  if(!pNormalDialogWindow)
    MemError();
  event.eventCode = INPUT_GUI_MESSAGE_CODE;
  event.xCoordOrKeycode = 6;
  event.payload = (void *)6;
  if(a2 != 7 && a2 != 8) {
    event.yCoordOrFieldID = 30727;
    pNormalDialogWindow->BroadcastMessage(event);
  }
  if(a2 != 7) {
    event.yCoordOrFieldID = 30728;
    pNormalDialogWindow->BroadcastMessage(event);
  }
  if(a2 != 6 && a2 != 3) {
    event.yCoordOrFieldID = 30721;
    pNormalDialogWindow->BroadcastMessage(event);
  }
  if(a2 != 5 && a2 != 1 && a2 != 3) {
    event.yCoordOrFieldID = 30722;
    pNormalDialogWindow->BroadcastMessage(event);
  }
  if(a2 != 2) {
    event.yCoordOrFieldID = 30725;
    pNormalDialogWindow->BroadcastMessage(event);
    event.yCoordOrFieldID = 30726;
    pNormalDialogWindow->BroadcastMessage(event);
  }
  for(i = 0; i < 2; ++i) {
    guiObj = 0;
    component = 0;
    if(imgTypes[i] == -1)
      break;
    buf[i] = (int)BaseAlloc(80u, __FILE__, __LINE__);
    if(imgTypes[i] > 6) {
      switch(imgTypes[i]) {
      case 8:
        sprintf((char *)buf[i], "%s", gSpellNames[imgArgs[i]]);
        strcpy(text, "spells.icn");
        borderSpriteIdx = gsSpellInfo[imgArgs[i]].magicBookIconIdx;
        break;
      case 9:
        //sprintf((char *)buf[i], "%s", unk_50E028);
        strcpy(text, "brcrest.icn");
        borderSpriteIdx = imgArgs[i];
        break;
      case 25:
        //sprintf((char *)buf[i], "%s", unk_50E03C);
        strcpy(text, "primskil.icn");
        borderSpriteIdx = 4;
        break;
      case 18:
        //sprintf((char *)buf[i], "%s", &unk_50E054);
        strcpy(text, "strip.icn");
        borderSpriteIdx = 12;
        break;
      case 17:
		if((imgArgs[i] / 3) == 15)
		  sprintf((char *)buf[i], "Cybernetics");
		else
		  sprintf((char *)buf[i], "%s", gSecondarySkills[imgArgs[i] / 3]);
        strcpy(text, "secskill.icn");
        borderSpriteIdx = imgArgs[i] / 3 + 1;
        break;
      case 15:
        //sprintf((char *)buf[i], "%s", &unk_50E07C);
        sprintf(text, "surrendr.icn");
        borderSpriteIdx = 4;
        break;
      default:
        if(imgTypes[i] != 14 && imgTypes[i] != 12 && imgTypes[i] != 13 && imgTypes[i] != 10 && imgTypes[i] != 11) {
          //strcpy((char *)buf[i], byte_50E0A8);
          strcpy(text, "resource.icn");
          borderSpriteIdx = imgTypes[i];
        } else {
          //strcpy((char *)buf[i], byte_50E094);
          strcpy(text, "expmrl.icn");
          borderSpriteIdx = imgTypes[i] - 10;
          if(imgTypes[i] == 14 && imgArgs[i] != -1)
            sprintf((char *)buf[i], "%d", imgArgs[i]);
        }
        break;
      }
    } else {
      if(imgArgs[i] <= 0) {
        if(imgArgs[i]) {
          if(imgArgs[i] >= -100000)
            sprintf((char *)buf[i], "%d/day", -imgArgs[i]);
          else
            sprintf((char *)buf[i], "%d", imgArgs[i] + 100000);
        } else {
          //strcpy((char *)buf[i], byte_50DFF8);
        }
      } else {
        sprintf((char *)buf[i], "%d", imgArgs[i]);
      }
      strcpy(text, "resource.icn");
      borderSpriteIdx = imgTypes[i];
    }
    switch(imgTypes[i]) {
    case 25:
      width = 94;
      v53 = 105;
      break;
    case 7:
      width = 76;
      v53 = 76;
      break;
    case 10:
      width = 64;
      v53 = 28;
      break;
    case 11:
      width = 64;
      v53 = 57;
      break;
    case 12:
      width = 64;
      v53 = 62;
      break;
    case 13:
      width = 64;
      v53 = 59;
      break;
    case 14:
      width = 64;
      v53 = 64;
      break;
    case 9:
      width = 50;
      v53 = 55;
      break;
    case 15:
      width = 111;
      v53 = 105;
      break;
    case 6:
      width = 76;
      v53 = 26;
      break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      width = 38;
      v53 = 32;
      break;
    case 8:
      width = 70;
      v53 = 55;
      break;
    case 17:
      width = 75;
      v53 = 65;
      break;
    case 18:
      width = 94;
      v53 = 105;
      break;
    default:
      break;
    }
    height = v53;
    if(strlen((char *)buf[i]))
      v53 += 12;
    if(i) {
      v51 = v60 - 87;
    } else if(imgTypes[1] == -1) {
      v51 = (v60 - 17) / 2 + 17;
    } else {
      v51 = 104;
    }
    v47 = v39 - v53 - 48;
    if(a2 != 4)
      v47 -= 39;
    if(imgTypes[0] == 17 && imgTypes[1] == 17) {
      if(i)
        v51 += 4;
      else
        v51 -= 4;
    }
    v28 = new iconWidget(
      v51 + ((unsigned int)(imgTypes[i] - 8) < 1 ? 2 : 0) - width / 2,
      v47,
      width,
      height,
      text,
      borderSpriteIdx,
      0,
      -1,
      ((unsigned int)(imgTypes[i] - 8) < 1) + 16,
      1);
    if(v28)
      guiObj = v28;
    else
      guiObj = 0;
    if(!guiObj)
      MemError();
    pNormalDialogWindow->AddWidget(guiObj, -1);
    if(imgTypes[i] == 7) {
      v27 = new iconWidget(
        v51 - width / 2 + 6,
        v47 + 6,
        76,
        76,
        "artifact.icn",
        LOWORD(imgArgs[i]) + 1,
        0,
        -1,
        16,
        1);
      if(v27)
        guiObj = v27;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
    }
    if(imgTypes[i] == 25) {
      v26 = new iconWidget(
        v51 - width / 2 + 6,
        v47 + 6,
        82,
        93,
        "primskil.icn",
        imgArgs[i],
        0,
        -1,
        16,
        1);
      if(v26)
        guiObj = v26;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
      strcpy((char *)buf[i], gStatNames[imgArgs[i]]);
    }
    if(imgTypes[i] == 18) {
      v25 = new iconWidget(
        v51 - width / 2 + 6,
        v47 + 6,
        82,
        93,
        "strip.icn",
        gMonsterDatabase[imgArgs[i]].faction + 4,
        0,
        -1,
        16,
        1);
      if(v25)
        guiObj = v25;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
      sprintf(text, "monh%04d.icn", imgArgs[i]);
      v24 = new iconWidget(v51 - width / 2 + 6, v47 + 6, 82, 93, text, 0, 0, -1, 16, 1);
      if(v24)
        guiObj = v24;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
    }
    if(imgTypes[i] == 9) {
      v23 = new iconWidget(
        v51 - width / 2 - 4,
        v47 - 4,
        58,
        55,
        "brcrest.icn",
        6,
        0,
        -1,
        16,
        1);
      if(v23)
        guiObj = v23;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
    }
    if(imgTypes[i] == 17) {
      v22 = new iconWidget(
        v51 - width / 2 - 3,
        v47 - 3,
        71,
        81,
        "secskill.icn",
        15,
        0,
        -1,
        16,
        1);
      if(v22)
        guiObj = v22;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
    }
    if(imgTypes[i] == 15) {
      sprintf(text, "port%04d.icn", imgArgs[i]);
      v21 = new iconWidget(
        v51 - width / 2 + 5,
        v47 + 5,
        101,
        95,
        text,
        0,
        0,
        -1,
        16,
        1);
      if(v21)
        guiObj = v21;
      else
        guiObj = 0;
      if(!guiObj)
        MemError();
      pNormalDialogWindow->AddWidget(guiObj, -1);
    }
    if(imgTypes[i] == 17) {
      a3 = v47 + v53 - 72;
      v20 = new textWidget(
        v51 - 50,
        a3,
        100,
        (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
        (char *)buf[i],
        "smalfont.fnt",
        1,
        v10,
        512,
        1);
      if(v20) {
        v10 = v36++;
        component = v20;
      } else {
        component = 0;
      }
      if(!component)
        MemError();
      pNormalDialogWindow->AddWidget((widget *)component, -1);
      buf[i] = (int)BaseAlloc(0x50u, __FILE__, __LINE__);
      a3a = v47 + v53 - 24;
      sprintf((char *)buf[i], "%s", secondarySkillLevels[imgArgs[i] % 3 + 1]);
    } else if(imgTypes[i] == 25) {
      a3a = v47 + v53 - 93;
    } else {
      a3a = v47 + v53 - 10;
    }
    v19 = new textWidget(
      v51 - 50,
      a3a,
      100,
      (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
      (char *)buf[i],
      "smalfont.fnt",
      1,
      v11,
      512,
      1);
    if(v19) {
      v11 = v36++;
      component = v19;
    } else {
      component = 0;
    }
    if(!component)
      MemError();
    pNormalDialogWindow->AddWidget((widget *)component, -1);
    if(imgTypes[i] == 25 && v41) {
      plusOneBuf = (char *)BaseAlloc(5u, __FILE__, __LINE__);
      strcpy(plusOneBuf, "+1 ");
      v18 = new textWidget(
        v51 - 50,
        v47 + v53 - 22,
        100,
        16,
        plusOneBuf,
        "bigfont.fnt",
        1,
        v12,
        512,
        1);
      if(v18) {
        v12 = v36++;
        component = v18;
      } else {
        component = 0;
      }
      if(!component)
        MemError();
      pNormalDialogWindow->AddWidget((widget *)component, -1);
    }
    v17 = new border(v51 - width / 2, v47, width, v53, i + 7700, 1, 0, 0);
    if(v17)
      v34 = v17;
    else
      v34 = 0;
    pNormalDialogWindow->AddWidget(v34, -1);
  }
  event.eventCode = INPUT_GUI_MESSAGE_CODE;
  event.xCoordOrKeycode = 3;
  event.yCoordOrFieldID = 1;
  event.payload = msga;
  pNormalDialogWindow->BroadcastMessage(event);
  if(writeOr == 1) {
    content = (char *)BaseAlloc(3u, __FILE__, __LINE__);
    strcpy(content, "or");
    v16 = new textWidget(v60 / 2 - 10, v47 + 43, 40, 12, content, "smalfont.fnt", 1, v36, 512, 1);
    if(v16)
      component = v16;
    else
      component = 0;
    if(!component)
      MemError();
    pNormalDialogWindow->AddWidget((widget *)component, -1);
  }
  protoCategory = gpMouseManager->cursorCategory;
  spriteIdx = gpMouseManager->spriteIdx;
  while(gpMouseManager->cursorDisabled)
    gpMouseManager->ShowColorPointer();
  gpMouseManager->SetPointer("advmice.mse", 0, -999);
  if(a2 != 6 && a2 != 5) {
    if(a2 == 4) {
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
  gpMouseManager->SetPointer("\0\0\0", spriteIdx, protoCategory);
  giResType1 = v54;
  giResExtra1 = v44;
  giResType2 = v56;
  giResExtra2 = v43;
  pNormalDialogWindow = v37;
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
					NormalDialog(cyberneticsDesc[imgArg % 3], 4, -1, -1, -1, 0, -1, 0, -1, 0);
				else
					NormalDialog(cSecSkillDesc[imgArg / 3][imgArg % 3], 4, -1, -1, -1, 0, -1, 0, -1, 0);
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