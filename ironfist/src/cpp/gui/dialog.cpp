#include<stdio.h>
#include<string>
#include<Windows.h>

#include "base.h"
#include "dialog.h"

void H2MessageBox(char* msg) {
	if (msg) {
		NormalDialog(msg, DIALOG_OKAY, -1, -1, -1, 0, -1, 0, -1, 0);
	}
}

static wchar_t* ConvertNarrowToWide(const char* msg) {
	int wideCharMsgLen = MultiByteToWideChar(CP_ACP, 0, msg, -1, NULL, 0);
	wchar_t* wideCharMsg = (wchar_t*)ALLOC(wideCharMsgLen * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, msg, -1, wideCharMsg, wideCharMsgLen);
	return wideCharMsg;
}

void DisplayError(const char* msg, const char* title) {
	wchar_t* wideCharMsg = ConvertNarrowToWide(msg);
	wchar_t* wideCharTitle = ConvertNarrowToWide(title);
	MessageBox(NULL, (LPCWSTR)wideCharMsg, (LPCWSTR)wideCharTitle, MB_OK);
	FREE(wideCharMsg);
	FREE(wideCharTitle);
}

void ErrorSavingMapVariable(const char* mapVariableId) {
	const std::string s1("MapVariable '");
	const std::string s2("' could not be saved properly.");
	const std::string mapVariableIdString(mapVariableId);
	const std::string errorMessage = s1 + mapVariableIdString + s2;
	const std::string errorLabel("mapVariable Error");
	DisplayError(errorMessage.c_str(), errorLabel.c_str());
}
