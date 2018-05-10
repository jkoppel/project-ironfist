#include<string>
#include<Windows.h>

#include "base.h"
#include "dialog.h"
#include "gui.h"

extern heroWindowManager *gpWindowManager;

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