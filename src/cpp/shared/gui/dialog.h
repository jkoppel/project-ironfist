#ifndef DIALOG_H
#define DIALOG_H

#include<string>

#include "gui/gui_utils.h"

extern void* hmnuAdv;

extern void __fastcall NormalDialog_orig(char * msg, int, int x, int y, int img1Type, int img1Arg, int img2Type, int img2Arg, int writeOr, int);
void __fastcall NormalDialog(char *msg, int a2, int x, int y, int img1Type, int img1Arg, int img2Type, int img2Arg, int writeOr, signed int a10);
extern void __fastcall UpdateHeroScreenStatusBar_orig(struct tag_message &evt);
extern void __fastcall HeroMessageUpdate(char *);

extern int giResType1;
extern int giResType2;
extern int giResExtra1;
extern int giResExtra2;
extern int giOverviewType;
extern int giOverviewItems[];
extern int giOverviewTop[];
extern int iLastDynamicType;
extern int iLastDynamicTop;

extern int __fastcall WaitHandler(struct tag_message &);
extern int __fastcall GetMobilityFrame(int a1);
extern int __fastcall GetManaFrame(signed int a1);

extern int giDialogTimeout;

#endif
