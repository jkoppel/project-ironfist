{
  signed int result; // eax@3
  int v2; // [sp+Ch] [bp-8h]@4

  if ( this->guiMsg.eventCode == 4 )
  {
    heroWindowManager::ConvertToHover(gpWindowManager, &this->inputEvt);
    if ( gpWindowManager->field_5E == this->inputEvt.yCoord )
    {
      result = 1;
    }
    else
    {
      gpWindowManager->field_5E = this->inputEvt.yCoord;
      v2 = this->guiMsg.fieldID;
      if ( v2 > 30720 )
      {
LABEL_9:
        combatManager::CombatMessage(gpCombatManager, off_4F64AC, 1, 0, 0);
      }
      else if ( v2 == 30720 )
      {
        combatManager::CombatMessage(gpCombatManager, off_4F64A0, 1, 0, 0);
      }
      else
      {
        switch ( v2 )
        {
          case 2:
            combatManager::CombatMessage(gpCombatManager, cSpellHelp, 1, 0, 0);
            break;
          case 3:
            combatManager::CombatMessage(gpCombatManager, off_4F6494, 1, 0, 0);
            break;
          case 6:
          case 7:
          case 8:
          case 9:
            combatManager::CombatMessage(gpCombatManager, off_4F64A8, 1, 0, 0);
            break;
          default:
            goto LABEL_9;
        }
      }
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}