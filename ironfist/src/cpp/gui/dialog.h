#ifndef DIALOG_H
#define DIALOG_H


enum DIALOG_TYPE {
  DIALOG_OKAY = 1,
  DIALOG_YES_NO = 2
};

const int BUTTON_CODE_OKAY = 30725;
const int BUTTON_CODE_CANCEL = 30726;

extern void __fastcall NormalDialog(char * msg,int,int x,int y,int img1Type,int img1Arg,int img2Type,int img2Arg,int writeOr,int);
void __fastcall GetDataEntry(char *,char *,int,char *,int,int);

void H2MessageBox(char* msg);
bool H2QuestionBox(char* qst);
char* H2InputBox(char *qst, int len);

wchar_t* ConvertNarrowToWide(const char* msg);

void DisplayError(const char* msg, const char* title);

#endif
