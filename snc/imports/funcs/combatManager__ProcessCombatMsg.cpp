{
  int v2; // eax@41
  int v4; // [sp+18h] [bp-64h]@16
  INPUT_EVENT_CODE v5; // [sp+20h] [bp-5Ch]@1
  combatManager *thisa; // [sp+24h] [bp-58h]@1
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
        PopNetBox(0, (void *)0xFFFFFFFF);
        break;
      case 61:
        heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 639u, 479);
        break;
      case 63:
        combatManager::SetCombatViewArmySmallLevel(this, (*(_DWORD *)&combatArmyInfoLevel + 1) % 3);
        break;
      case 64:
        combatManager::SetCombatGrid(
          this,
          1 - *(_DWORD *)&showCombatGrid,
          *(int *)&showCombatMouseHex,
          combatShadeLevel);
        break;
      case 65:
        combatManager::SetCombatGrid(
          this,
          *(int *)&showCombatGrid,
          1 - *(_DWORD *)&showCombatMouseHex,
          combatShadeLevel);
        break;
      case 66:
        combatManager::SetCombatGrid(this, *(int *)&showCombatGrid, *(int *)&showCombatMouseHex, 1 - combatShadeLevel);
        break;
      case 67:
        giSpellEffectShowType = (giSpellEffectShowType + 1) % 3;
        combatManager::DrawFrame(this, 1, 0, 0, 0, 75, 1, 1);
        break;
      case 87:
        if ( evt->inputTypeBitmask & 3 )
        {
          combatManager::VaporizeCreature(this, 1, 1);
        }
        else if ( evt->inputTypeBitmask & 0xC )
        {
          combatManager::RippleCreature(this, 1, 1, 1);
          combatManager::RippleCreature(thisa, 1, 1, 2);
        }
        else
        {
          combatManager::RippleCreature(this, 1, 1, 0);
        }
        break;
      case 57:
        giNextAction = 3;
        break;
      case 2:
        mouseManager::MouseCoords(&a1, &y);
        break;
      case 35:
        if ( this->heroes[this->currentActionSide] )
        {
          mouseManager::SetPointer(gpMouseManager, 6);
          combatManager::ViewGeneral(thisa, thisa->currentActionSide, 1, 0);
          combatManager::ResetMouse(thisa);
        }
        break;
      case 20:
        mouseManager::SetPointer(gpMouseManager, 6);
        combatManager::ViewArmy(
          thisa,
          (int)&thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx],
          0);
        combatManager::ResetMouse(thisa);
        break;
      case 46:
        if ( this->heroes[this->currentActionSide] )
        {
          if ( combatManager::IsNegationSphereInEffect(this) )
          {
            NormalDialog(
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
          else if ( !*(&thisa->field_353F + thisa->currentActionSide) || giDebugLevel )
          {
            mouseManager::SetPointer(gpMouseManager, 6);
            giCurGeneral = thisa->currentActionSide;
            combatManager::ViewSpells(thisa, 0);
            combatManager::ResetMouse(thisa);
          }
          else
          {
            NormalDialog("You have already cast a spell this round.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
        else
        {
          NormalDialog("You have no hero to cast a spell.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
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
              combatManager::RightClick((int)this, this->field_F2C3);
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
            NormalDialog(cLongCombatHelp[v10], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      else
      {
        v4 = evt->xCoordOrKeycode;
        if ( v4 == 12 )
        {
          if ( evt->yCoord == 64 )
            combatManager::DoCommand((int)this, this->field_F2CF);
        }
        else if ( v4 == 13 )
        {
          switch ( evt->yCoord )
          {
            case 3:
              this->notHandlingInputEvent = 1;
              break;
            case 2:
              giNextAction = 3;
              break;
            case 1:
              giNextAction = 7;
              break;
            case 4:
              combatManager::CombatSystemOptions(this);
              break;
            default:
              return 1;
          }
        }
      }
    }
    return 1;
  }
  if ( this->notHandlingInputEvent )
    return 1;
  memcpy(&v11, inputManager::PeekEvent(gpInputManager, &a2), 0x1Cu);
  if ( v11 == 4 )
    return 1;
  if ( InCombatArea(evt->altXCoord, evt->altYCoord) )
    hexIdx = combatManager::GetGridIndex(thisa, x, a3);
  else
    hexIdx = -1;
  combatManager::UpdateMouseGrid(thisa, hexIdx, 0);
  if ( InCombatArea(evt->altXCoord, evt->altYCoord) )
  {
    if ( thisa->field_F2C3 == hexIdx && hexIdx != -1 )
    {
      if ( thisa->field_F2CF == 7 )
        combatManager::CheckSetMouseDirection(thisa, x, a3, hexIdx);
    }
    else
    {
      thisa->field_F2C3 = hexIdx;
      thisa->field_F2CB = -99;
      thisa->field_F2CF = combatManager::GetCommand((int)thisa, thisa->field_F2C3);
      *(_DWORD *)&thisa->_15[60] = -1;
      if ( thisa->field_F2CF == 7 )
      {
        combatManager::SetCombatDirections(thisa, hexIdx);
        combatManager::CheckSetMouseDirection(thisa, x, a3, hexIdx);
      }
      else
      {
        v2 = combatManager::GetPointer(thisa->field_F2CF, hexIdx);
        mouseManager::SetPointer(gpMouseManager, v2);
      }
    }
    if ( thisa->field_F2CB != thisa->field_F2CF )
    {
      thisa->field_F2CB = thisa->field_F2CF;
      combatManager::CombatMessage(thisa, thisa->field_F2CF);
    }
  }
  else
  {
    if ( x < 590 )
    {
      if ( x > 50 || a3 >= 460 )
      {
        if ( x > 50 )
          combatManager::CombatMessage(thisa, off_4F6600, 1, 0, 0);
        else
          combatManager::CombatMessage(thisa, off_4F65FC, 1, 0, 0);
      }
      else
      {
        combatManager::CombatMessage(thisa, off_4F65F8, 1, 0, 0);
      }
    }
    else
    {
      combatManager::CombatMessage(thisa, off_4F65F4, 1, 0, 0);
    }
    mouseManager::SetPointer(gpMouseManager, 6);
    thisa->field_F2C3 = -1;
    thisa->field_F2CB = -99;
  }
  return 1;
}