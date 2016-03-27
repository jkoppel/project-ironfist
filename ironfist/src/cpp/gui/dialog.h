#ifndef DIALOG_H
#define DIALOG_H


enum DIALOG_TYPE {
	DIALOG_OKAY = 1
};


extern void __fastcall NormalDialog(char * msg,int,int x,int y,int img1Type,int img1Arg,int img2Type,int img2Arg,int writeOr,int);

void H2MessageBox(char* msg);

wchar_t* ConvertNarrowToWide(const char* msg);

void DisplayError(const char* msg, const char* title);

#endif