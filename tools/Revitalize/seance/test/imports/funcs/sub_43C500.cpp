{
  int v2; // eax@41
  int v4; // [sp+18h] [bp-64h]@16
  INPUT_EVENT_CODE v5; // [sp+20h] [bp-5Ch]@1
  CombatManager *thisa; // [sp+24h] [bp-58h]@1
  char a2; // [sp+28h] [bp-54h]@32
  int y; // [sp+44h] [bp-38h]@73
  int a1; // [sp+48h] [bp-34h]@73
  int v10; // [sp+4Ch] [bp-30h]@5
  int v11; // [sp+50h] [bp-2Ch]@32
  int v12; // [sp+6Ch] [bp-10h]@1
  signed int hexIdx; // [sp+70h] [bp-Ch]@34
  signed int a3; // [sp+74h] [bp-8h]@1
  signed int x; // [sp+78h] [bp-4h]@1

  thisa = this;
  x = evt->altXCoord;
  a3 = evt->altYCoord;
  v12 = 0;
  v5 = evt->eventCode;
  if ( v5 == INPUT_KEYDOWN_EVENT_CODE )
  {
    switch ( evt->xCoordOrKeycode )
    {
      case 60:
        sub_435F20(0, (void *)0xFFFFFFFF);
        break;
      case 61:
        HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 639u, 479);
        break;
      case 63:
        CombatManager::setCombatArmyInfoLevel(this, (*(_DWORD *)&combatArmyInfoLevel + 1) % 3);
        break;
      case 64:
        sub_4423C0(this, 1 - *(_DWORD *)&showCombatGrid, *(int *)&showCombatMouseHex, combatShadeLevel);
        break;
      case 65:
        sub_4423C0(this, *(int *)&showCombatGrid, 1 - *(_DWORD *)&showCombatMouseHex, combatShadeLevel);
        break;
      case 66:
        sub_4423C0(this, *(int *)&showCombatGrid, *(int *)&showCombatMouseHex, 1 - combatShadeLevel);
        break;
      case 67:
        dword_4F38A0 = (dword_4F38A0 + 1) % 3;
        CombatManager::drawBattlefield(this, 1, 0, 0, 0, 75, 1, 1);
        break;
      case 87:
        if ( evt->inputTypeBitmask & 3 )
        {
          sub_4A3B10(this, 1, 1);
        }
        else
        {
          if ( evt->inputTypeBitmask & 0xC )
          {
            sub_4A3DB0(this, 1, 1, 1);
            sub_4A3DB0(thisa, 1, 1, 2);
          }
          else
          {
            sub_4A3DB0(this, 1, 1, 0);
          }
        }
        break;
      case 57:
        couldBeCreatureActionType = 3;
        break;
      case 2:
        retrieveVirtualCursorCoordinates(&a1, &y);
        break;
      case 35:
        if ( this->heroes[this->currentActionSide] )
        {
          MouseManager::setSpriteIdx(mouseManager, 6);
          sub_40FAF0(thisa, thisa->currentActionSide, 1, 0);
          sub_440ED0(thisa);
        }
        break;
      case 20:
        MouseManager::setSpriteIdx(mouseManager, 6);
        sub_410530(thisa, (int)&thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx], 0);
        sub_440ED0(thisa);
        break;
      case 46:
        if ( this->heroes[this->currentActionSide] )
        {
          if ( CombatManager::sphereOfNegationInEffect(this) )
          {
            display_message_window(
              "The Sphere of Negation artifact is in effect for this battle, disabling all combat spells.",
              1,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0);
          }
          else
          {
            if ( !*(&thisa->field_353F + thisa->currentActionSide) || debugLogLevel )
            {
              MouseManager::setSpriteIdx(mouseManager, 6);
              dword_524BE4 = thisa->currentActionSide;
              CombatManager::castCombatSpell(thisa, 0);
              sub_440ED0(thisa);
            }
            else
            {
              display_message_window("You have already cast a spell this round.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
          }
        }
        else
        {
          display_message_window("You have no hero to cast a spell.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
        break;
      default:
        return 1;
    }
    return 1;
  }
  if ( v5 != INPUT_MOUSEMOVE_EVENT_CODE )
  {
    if ( v5 == INPUT_GUI_MESSAGE_CODE )
    {
      if ( BYTE1(evt->inputTypeBitmask) & 2 )
      {
        if ( evt->xCoordOrKeycode == 12 || evt->xCoordOrKeycode == 14 )
        {
          v10 = -1;
          switch ( evt->yCoord )
          {
            case 0x40:
              sub_43D810((int)this, this->field_F2C3);
              break;
            case 1:
              v10 = 0;
              break;
            case 2:
              v10 = 1;
              break;
            case 3:
              v10 = 2;
              break;
            case 4:
              v10 = 3;
              break;
            case 0xA:
            case 0xB:
            case 0xC:
            case 0xD:
              v10 = 4;
              break;
            default:
              break;
          }
          if ( v10 != -1 )
            display_message_window(combatButtonHelp[v10], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      else
      {
        v4 = evt->xCoordOrKeycode;
        if ( v4 == 12 )
        {
          if ( evt->yCoord == 64 )
            sub_43DAC0((int)this, this->field_F2CF);
        }
        else
        {
          if ( v4 == 13 )
          {
            switch ( evt->yCoord )
            {
              case 3:
                this->notHandlingInputEvent = 1;
                break;
              case 2:
                couldBeCreatureActionType = 3;
                break;
              case 1:
                couldBeCreatureActionType = 7;
                break;
              case 4:
                sub_47A4B0(this);
                break;
              default:
                return 1;
            }
          }
        }
      }
    }
    return 1;
  }
  if ( this->notHandlingInputEvent )
    return 1;
  memcpy(&v11, InputManager::lastInputEvent(inputManager, &a2), 0x1Cu);
  if ( v11 == 4 )
    return 1;
  if ( virtualCoordsWithinCombatScreen(evt->altXCoord, evt->altYCoord) )
    hexIdx = CombatManager::getHexIdxForMouseCoords(thisa, x, a3);
  else
    hexIdx = -1;
  sub_4C4960(thisa, hexIdx, 0);
  if ( virtualCoordsWithinCombatScreen(evt->altXCoord, evt->altYCoord) )
  {
    if ( thisa->field_F2C3 == hexIdx && hexIdx != -1 )
    {
      if ( thisa->field_F2CF == 7 )
        sub_43BE40(thisa, x, a3, hexIdx);
    }
    else
    {
      thisa->field_F2C3 = hexIdx;
      thisa->field_F2CB = -99;
      thisa->field_F2CF = sub_43D2F0((int)thisa, thisa->field_F2C3);
      *(_DWORD *)&thisa->_15[60] = -1;
      if ( thisa->field_F2CF == 7 )
      {
        sub_43B590(thisa, hexIdx);
        sub_43BE40(thisa, x, a3, hexIdx);
      }
      else
      {
        v2 = sub_43C470(thisa->field_F2CF, hexIdx);
        MouseManager::setSpriteIdx(mouseManager, v2);
      }
    }
    if ( thisa->field_F2CB != thisa->field_F2CF )
    {
      thisa->field_F2CB = thisa->field_F2CF;
      sub_4C3820(thisa, thisa->field_F2CF);
    }
  }
  else
  {
    if ( x < 590 )
    {
      if ( x > 50 || a3 >= 460 )
      {
        if ( x > 50 )
          CombatManager::displayCombatMessage(thisa, off_4F6600, 1, 0, 0);
        else
          CombatManager::displayCombatMessage(thisa, off_4F65FC, 1, 0, 0);
      }
      else
      {
        CombatManager::displayCombatMessage(thisa, off_4F65F8, 1, 0, 0);
      }
    }
    else
    {
      CombatManager::displayCombatMessage(thisa, off_4F65F4, 1, 0, 0);
    }
    MouseManager::setSpriteIdx(mouseManager, 6);
    thisa->field_F2C3 = -1;
    thisa->field_F2CB = -99;
  }
  return 1;
}
