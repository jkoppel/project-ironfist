void __thiscall CombatManager::displayCombatMessage(CombatManager *this, char *message, int a3, int a4, int a5)
{
  CombatManager *thisa; // [sp+Ch] [bp-1BCh]@1
  char buf[400]; // [sp+10h] [bp-1B8h]@17
  char *newline; // [sp+1A0h] [bp-28h]@16
  InputEvent a2; // [sp+1A4h] [bp-24h]@26
  int v9; // [sp+1C0h] [bp-8h]@26
  int v10; // [sp+1C4h] [bp-4h]@26

  thisa = this;
  if ( combatGraphicsOff )
  {
    if ( a4 )
      logDisplayCombatMessage(message);
  }
  else
  {
    if ( this->checkedInsub4c3d60 && !this->field_F357 )
    {
      if ( a5 )
      {
        strcpy(this->combatMessageRow1, byte_51E3A0);
        strcpy(thisa->combatMessageRow2, message);
        thisa->otherCombatMessageRelatedTime = 0;
        thisa->combatMessageRelatedTime = thisa->otherCombatMessageRelatedTime;
        thisa->couldBeShouldResetCombatMessage = 0;
      }
      else
      {
        if ( a4 )
        {
          if ( this->combatMessageRelatedTime )
            strcpy(this->combatMessageRow1, this->combatMessageRow2);
          else
            strcpy(this->combatMessageRow1, byte_51E3A8);
          thisa->otherCombatMessageRelatedTime = thisa->combatMessageRelatedTime;
          thisa->combatMessageRelatedTime = getTickCount() + 2500;
        }
        else
        {
          if ( getTickCount() < this->combatMessageRelatedTime )
            return;
          strcpy(thisa->combatMessageRow1, byte_51E3A4);
          thisa->otherCombatMessageRelatedTime = 0;
          thisa->combatMessageRelatedTime = thisa->otherCombatMessageRelatedTime;
        }
        newline = findCharInString(message, '\n');
        if ( newline )
        {
          *newline = 0;
          strcpy(buf, message);
          if ( message >= newline || *(newline - 1) != '.' )
            strcat(buf, L" ");
          else
            strcat(buf, "  ");
          strcat(buf, newline + 1);
          if ( Font::numLinesNeededToDisplay(bigFont, buf, 474) > 1 )
          {
            strcpy(thisa->combatMessageRow1, message);
            strcpy(thisa->combatMessageRow2, newline + 1);
          }
          else
          {
            strcpy(thisa->combatMessageRow2, buf);
          }
          *newline = '\n';
        }
        else
        {
          strcpy(thisa->combatMessageRow2, message);
        }
      }
      a2.eventCode = INPUT_GUI_MESSAGE_CODE;
      a2.xCoordOrKeycode = 3;
      a2.yCoord = 12;
      a2.payload = thisa->combatMessageRow1;
      GUIWindow::processMessage(thisa->window, (Event *)&a2);
      a2.yCoord = 13;
      a2.payload = thisa->combatMessageRow2;
      GUIWindow::processMessage(thisa->window, (Event *)&a2);
      v9 = dword_4F7480;
      v10 = dword_4F7488;
      dword_4F7488 = 0;
      dword_4F7480 = 0;
      GUIWindow::repaintComponentsInRange(thisa->window, 0, 10, 13);
      doNothing2();
      if ( a3 )
        HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 83, 446, 0x1DAu, 33);
      dword_4F7480 = v9;
      dword_4F7488 = v10;
    }
  }
}
