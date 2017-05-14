#ifndef DIALOG_H
#define DIALOG_H

#include<string>

enum DIALOG_TYPE {
  DIALOG_OKAY = 1,
  DIALOG_YES_NO = 2,
  DIALOG_OR = 1,
  DIALOG_EMPTY = 0,
};

enum IMAGE_TYPE {
  IMAGE_EMPTY = -1,
  IMAGE_LOGS = 0,
  IMAGE_MERCURY = 1,
  IMAGE_IRON = 2,
  IMAGE_SULFUR = 3,
  IMAGE_MINERALS = 4,
  IMAGE_GEMS = 5,
  IMAGE_COINS = 6,
  IMAGE_ARTIFACT = 7,
  IMAGE_SPELLS = 8,
  IMAGE_PLAYERS = 9,
  IMAGE_RAINBOW = 10,
  IMAGE_STORM = 11,
  IMAGE_GOLD = 12,
  IMAGE_GOLD2 = 13,
  IMAGE_EXP = 14,
  IMAGE_HERO = 15,	
  IMAGE_SKILLS2 = 17,
  IMAGE_UNIT = 18,
  IMAGE_SKILLS1 = 25,
 


};





const int BUTTON_CODE_OKAY = 30725;
const int BUTTON_CODE_CANCEL = 30726;

extern void __fastcall NormalDialog(char * msg,int,int x,int y,int img1Type,int img1Arg,int img2Type,int img2Arg,int writeOr,int);
void __fastcall GetDataEntry(char *,char *,int,char *,int,int);

void H2MessageBox(char* msg);
bool H2QuestionBox(char* qst);
char* H2InputBox(char *qst, int len);
void H2NormalDialog(char* msg, int YESNO, int vertical, int horizontal, int img1type, int img1arg, int img2type, int img2arg, int Or);
void DisplayError(const char* msg, const char* title);

void DisplayError(std::string msg, std::string title);

#endif
