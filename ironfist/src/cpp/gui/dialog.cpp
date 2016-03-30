#include "dialog.h"
#include "gui.h"

extern heroWindowManager *gpWindowManager;

void H2MessageBox(char* msg) {
	NormalDialog(msg, DIALOG_OKAY, -1,-1,-1,0,-1,0,-1,0);
}
bool H2QuestionBox(char* msg)
{
	NormalDialog(msg, DIALOG_YES_NO, -1,-1,-1,0,-1,0,-1,0);
	return gpWindowManager->buttonPressedCode != 30726;
}
char* H2InputBox(char* msg, int len)
{
	char* res = new char[len + 1];
	GetDataEntry(msg, res, len + 1, 0, 0, 1);
	return res;
}