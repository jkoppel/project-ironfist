{
  signed int result; // eax@28
  signed int v2; // [sp+Ch] [bp-5Ch]@29
  int v3; // [sp+10h] [bp-58h]@19
  int v4; // [sp+18h] [bp-50h]@5
  INPUT_EVENT_CODE v5; // [sp+1Ch] [bp-4Ch]@1
  tag_message *a2; // [sp+20h] [bp-48h]@1
  signed int v7; // [sp+24h] [bp-44h]@3
  signed int v8; // [sp+28h] [bp-40h]@30
  signed int v9; // [sp+5Ch] [bp-Ch]@1

  a2 = this;
  v9 = 0;
  v5 = this->eventCode;
  if ( v5 != 4 )
  {
    if ( v5 == 512 )
    {
      if ( BYTE1(this->inputTypeBitmask) & 2 )
      {
        v7 = -1;
        if ( this->xCoordOrKeycode == 12 || this->xCoordOrKeycode == 14 )
        {
          v4 = this->yCoord;
          if ( v4 <= 30720 )
          {
            switch ( v4 )
            {
              case 30720:
                v7 = 3;
                break;
              case 10:
                v7 = 0;
                break;
              case 11:
                v7 = 1;
                break;
              case 12:
                v7 = 2;
                break;
            }
          }
          if ( v7 != -1 )
            NormalDialog((&cViewGeneralLongHelp)[4 * v7], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      else if ( this->xCoordOrKeycode == 13 )
      {
        v3 = this->yCoord;
        if ( v3 >= 10 && (v3 <= 12 || v3 == 30720) )
        {
          gpWindowManager->buttonPressedCode = this->yCoord;
          v9 = 1;
        }
      }
    }
    if ( v9 )
    {
      a2->yCoord = 10;
      a2->xCoordOrKeycode = a2->yCoord;
      result = 2;
    }
    else
    {
      result = 1;
    }
    return result;
  }
  heroWindowManager::ConvertToHover(gpWindowManager, this);
  if ( gpWindowManager->field_5E == a2->yCoord )
    return 1;
  gpWindowManager->field_5E = a2->yCoord;
  v2 = a2->yCoord;
  if ( v2 <= 30720 )
  {
    if ( v2 == 30720 )
    {
      v8 = 4;
      goto LABEL_41;
    }
    if ( v2 == 10 )
    {
      v8 = 1;
      goto LABEL_41;
    }
    if ( v2 == 11 )
    {
      v8 = 2;
      goto LABEL_41;
    }
    if ( v2 == 12 )
    {
      v8 = 3;
      goto LABEL_41;
    }
  }
  v8 = 5;
LABEL_41:
  if ( v8 == 5 && gpCombatManager->heroes[iViewGeneralWhichSide]->field_E7[0] )
    v8 = 6;
  combatManager::CombatMessage(gpCombatManager, (&cViewGeneralHelp)[4 * v8], 1, 0, 0);
  return 1;
}