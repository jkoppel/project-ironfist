#include "msg.h"
#include "gui/gui.h"


void GUIAddFlag(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_ADD_FLAGS, (void*)p);
}

void GUIRemoveFlag(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_REMOVE_FLAGS, (void*)p);
}

void GUISetImgIdx(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_IMG_IDX, (void*)p);
}

void GUISetIcon(heroWindow* hwnd, int f, char* p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_ICON, (void*)p);
}

void GUISetText(heroWindow* hwnd, int f, char* p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_TEXT, (void*)p);
}

void GUIDroplistAdd(heroWindow* hwnd, int f, char* p) {
  GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_DROPLIST_ADD, (void*)p);
}


void GUIBroadcastMessage(heroWindow* hwnd, int f, int c, void* p) {
	tag_message evt;
	evt.yCoordOrFieldID = f;
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.xCoordOrKeycode = c;
	evt.payload = p;
	hwnd->BroadcastMessage(evt);
}

void GUIBroadcastMessageDirect(heroWindow* hwnd, int f, int c, void* p, tag_message& evt) {
  evt.yCoordOrFieldID = f;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = c;
  evt.payload = p;
  hwnd->BroadcastMessage(evt);
}