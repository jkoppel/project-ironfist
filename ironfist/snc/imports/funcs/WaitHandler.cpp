{
  signed int result; // eax@27
  int v2; // [sp+10h] [bp-10h]@3
  tag_message *thisa; // [sp+18h] [bp-8h]@1
  signed int v4; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  v4 = 0;
  gbFunctionComplete = 1;
  PollSound();
  if ( thisa->eventCode == 512 )
  {
    if ( thisa->xCoordOrKeycode == 13 )
    {
      v2 = thisa->yCoord;
      if ( v2 >= 30720 && v2 <= 30722 )
      {
        gbFunctionComplete = 0;
        v4 = 1;
      }
    }
  }
  if ( !v4 )
  {
    switch ( giWaitType )
    {
      case 0:
        v4 = WaitForOtherPlayer();
        break;
      case 2:
        v4 = WaitForHost();
        break;
      case 1:
        v4 = WaitForGuest();
        break;
      case 3:
        v4 = InitNetGuest();
        break;
      case 4:
        v4 = InitNetHost();
        break;
      case 5:
        v4 = GUIModemCommandExec();
        break;
      case 6:
        v4 = GUIModemResponseExec();
        break;
      case 7:
        v4 = WaitForDirectConnect();
        break;
      case 8:
        v4 = dpWaitForFirstGuest();
        break;
      case 9:
        v4 = dpWaitForExtraGuests();
        break;
      case 10:
        v4 = dpWaitForHost();
        break;
      case 11:
        v4 = wsWaitForFirstGuest();
        break;
      case 12:
        v4 = wsWaitForExtraGuests();
        break;
      case 13:
        v4 = wsWaitForHost();
        break;
      default:
        break;
    }
  }
  CheckShingleUpdate();
  if ( v4 )
  {
    gpWindowManager->buttonPressedCode = 30721;
    thisa->eventCode = 512;
    thisa->yCoord = 10;
    thisa->xCoordOrKeycode = thisa->yCoord;
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}