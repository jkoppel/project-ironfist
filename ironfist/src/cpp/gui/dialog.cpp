#include "dialog.h"

#include "base.h"
#include<stdio.h>
#include<Windows.h>

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
	char *s1 = "MapVariable '";
	char *s2 = "' could not be saved properly.";
	int len = strlen(mapVariableId) + strlen(s1) + strlen(s2) + 1;
	char *errorMessage = (char *)ALLOC(len);
	_snprintf_s(errorMessage, len * sizeof(*errorMessage), len, "%s%s%s", s1, mapVariableId, s2);
	DisplayError((const char*)errorMessage, "mapVariable Error");
	FREE(errorMessage);
}
