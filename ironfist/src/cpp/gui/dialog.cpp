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

void ErrorMapVariable(const char* mapVariableId, const std::string s2, std::string addErrorMessage) {
	const std::string s1("MapVariable '");
	const std::string mapVariableIdString(mapVariableId);
	const std::string errorMessage = s1 + mapVariableIdString + s2 + addErrorMessage;
	const std::string errorLabel("mapVariable Error");
	DisplayError(errorMessage, errorLabel);
}

void ErrorSavingMapVariable(const char* mapVariableId, std::string addErrorMessage) {
	const std::string s2("' could not be saved properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

void ErrorLoadingMapVariable(const char* mapVariableId, std::string addErrorMessage) {
	const std::string s2("' could not be loaded properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

void ErrorMapVariable(std::string mapVariableId, const std::string s2, std::string addErrorMessage) {
	const std::string s1("MapVariable '");
	const std::string errorMessage = s1 + mapVariableId + s2 + addErrorMessage;
	const std::string errorLabel("mapVariable Error");
	DisplayError(errorMessage, errorLabel);
}

void ErrorSavingMapVariable(std::string mapVariableId, std::string addErrorMessage) {
	const std::string s2("' could not be saved properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

void ErrorLoadingMapVariable(std::string mapVariableId, std::string addErrorMessage) {
	const std::string s2("' could not be loaded properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}