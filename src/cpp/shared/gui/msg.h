#ifndef MSG_H
#define MSG_H

#pragma pack(push,1)

enum INPUT_EVENT_CODE {
  INPUT_KEYDOWN_EVENT_CODE = 0x1,
  INPUT_KEYUP_EVENT_CODE = 0x2,
  INPUT_MOUSEMOVE_EVENT_CODE = 0x4,
  INPUT_LEFT_CLICK_EVENT_CODE = 0x8,
  INPUT_LEFT_UP_EVENT_CODE = 0x10,
  INPUT_RIGHT_CLICK = 0x20,
  INPUT_RIGHT_UP_EVENT_CODE = 0x40,
  INPUT_GUI_MESSAGE_CODE = 0x200,
};

struct tag_message {
  INPUT_EVENT_CODE eventCode;
  int xCoordOrKeycode;
  int yCoordOrFieldID;
  int inputTypeBitmask;
  int altXCoord;
  int altYCoord;
  void *payload;
};

enum GUI_MESSAGE_CODE {
  GUI_MESSAGE_REPAINT = 0x2,
  GUI_MESSAGE_SET_TEXT = 0x3,
  GUI_MESSAGE_SET_IMG_IDX = 0x4,
  GUI_MESSAGE_ADD_FLAGS = 0x5,
  GUI_MESSAGE_REMOVE_FLAGS = 0x6,
  GUI_MESSAGE_SET_ICON = 0x9,
  GUI_MESSAGE_MOUSE_CLICK = 0xC,
  GUI_MESSAGE_BUTTON_PRESSED = 0xD,
  GUI_MESSAGE_SET_OFFSETX = 0x34,
  GUI_MESSAGE_SET_OFFSETY = 0x35,
  GUI_MESSAGE_SET_DROPLIST_INDEX = 0x36,
  GUI_MESSAGE_GET_DROPLIST_INDEX = 0x37,
  GUI_MESSAGE_DROPLIST_ADD = 0x38,
  GUI_MESSAGE_DROPLIST_CLEAR = 0x3B,
  GUI_MESSAGE_REPLACE_ICON = 0x3C,
  GUI_MESSAGE_SET_WIDTH = 0x3D,
};

#pragma pack(push, 1)
struct GUIMessage
{
  INPUT_EVENT_CODE eventCode;
  int messageType;
  int fieldID;
  int inputTypeBitmask;
  int altXCoord;
  int altYCoord;
  void *payload;
};
#pragma pack(pop)

#pragma pack(push, 1)
union Event
{
  tag_message inputEvt;
  GUIMessage guiMsg;
};
#pragma pack(pop)

#pragma pack(pop)

#endif