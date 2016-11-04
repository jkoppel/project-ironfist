{
  signed int result; // eax@27
  int v2; // [sp+10h] [bp-10h]@3
  InputEvent *thisa; // [sp+18h] [bp-8h]@1
  signed int v4; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  v4 = 0;
  dword_523018 = 1;
  yieldToGlobalUpdater();
  if ( thisa->eventCode == 512 )
  {
    if ( thisa->xCoordOrKeycode == 13 )
    {
      v2 = thisa->yCoord;
      if ( v2 >= 30720 && v2 <= 30722 )
      {
        dword_523018 = 0;
        v4 = 1;
      }
    }
  }
  if ( !v4 )
  {
    switch ( dword_524750 )
    {
      case 0:
        v4 = sub_435E20();
        break;
      case 2:
        v4 = sub_40EAA0();
        break;
      case 1:
        v4 = sub_40EB00();
        break;
      case 3:
        v4 = sub_40E8F0();
        break;
      case 4:
        v4 = sub_40E790();
        break;
      case 5:
        v4 = sub_464230();
        break;
      case 6:
        v4 = sub_4643E0();
        break;
      case 7:
        v4 = sub_464760();
        break;
      case 8:
        v4 = sub_4051E0();
        break;
      case 9:
        v4 = sub_405370();
        break;
      case 10:
        v4 = sub_405400();
        break;
      case 11:
        v4 = sub_45FD40();
        break;
      case 12:
        v4 = sub_45FD70();
        break;
      case 13:
        v4 = sub_45FE30();
        break;
      default:
        break;
    }
  }
  sub_4398D0();
  if ( v4 )
  {
    HeroWindowManager::instance->buttonPressedCode = 30721;
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
