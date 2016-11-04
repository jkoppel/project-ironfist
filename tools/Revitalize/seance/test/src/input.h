
#ifndef INPUT_H
#define INPUT_H

enum INPUT_EVENT_CODE
{
  INPUT_KEYDOWN_EVENT_CODE = 0x1,
  INPUT_KEYUP_EVENT_CODE = 0x2,
  INPUT_MOUSEMOVE_EVENT_CODE = 0x4,
  INPUT_LEFT_CLICK_EVENT_CODE = 0x8,
  INPUT_LEFT_UP_EVENT_CODE = 0x10,
  INPUT_RIGHT_CLICK = 0x20,
  INPUT_RIGHT_UP_EVENT_CODE = 0x40,
  INPUT_GUI_MESSAGE_CODE = 0x200,
}

struct InputEvent
{
  INPUT_EVENT_CODE eventCode;
  int xCoordOrKeycode;
  int yCoord;
  int inputTypeBitmask;
  int altXCoord;
  int altYCoord;
  void *payload;
}

#endif
