{
  int hex; // [sp+14h] [bp-4h]@2

  switch ( this->inputEvt.eventCode )
  {
    case 4:
      hex = combatManager::GetGridIndex(gpCombatManager, this->inputEvt.xCoordOrKeycode, this->inputEvt.yCoord);
      if ( indexToCastOn != hex )
      {
        if ( combatManager::ValidSpellTarget(gpCombatManager, gpCombatManager->current_spell_id, hex) )
        {
          indexToCastOn = hex;
          mouseManager::SetPointer(gpMouseManager, gsSpellInfo[gpCombatManager->current_spell_id].spriteIdx);
          combatManager::SpellMessage(gpCombatManager, gpCombatManager->current_spell_id, hex);
        }
        else
        {
          indexToCastOn = -1;
          mouseManager::SetPointer(gpMouseManager, 0);
          if ( gpCombatManager->current_spell_id == SPELL_TELEPORT && bInTeleportGetDest )
            combatManager::CombatMessage(gpCombatManager, "Invalid Teleport Destination", 1, 0, 0);
          else
            combatManager::CombatMessage(gpCombatManager, "Select Spell Target", 1, 0, 0);
        }
      }
      return 1;
    case 8:
      if ( indexToCastOn == -1 )
        return 1;
      if ( bInTeleportGetDest )
      {
        giNextActionGridIndex2 = indexToCastOn;
      }
      else
      {
        giNextActionGridIndex = indexToCastOn;
        if ( gpCombatManager->current_spell_id == 4 )
        {
          bInTeleportGetDest = 1;
          indexToCastOn = -1;
          this->inputEvt.eventCode = 4;
          this->inputEvt.xCoordOrKeycode = this->inputEvt.altXCoord;
          this->inputEvt.yCoord = this->inputEvt.altYCoord;
          HandleCastSpell(this);
          combatManager::CombatMessage(gpCombatManager, "Select teleport destination.", 1, 0, 0);
          return 1;
        }
      }
      bInTeleportGetDest = 0;
      this->inputEvt.eventCode = 512;
      this->inputEvt.xCoordOrKeycode = 10;
      return 2;
    case 1:
      if ( this->guiMsg.messageType == 1 )
        goto LABEL_19;
      return 1;
    case 32:
LABEL_19:
      gpCombatManager->current_spell_id = -1;
      giNextAction = 0;
      this->inputEvt.eventCode = 512;
      this->inputEvt.xCoordOrKeycode = 10;
      bInTeleportGetDest = 0;
      return 2;
    default:
      return 1;
  }
}