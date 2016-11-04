{
  int hex; // [sp+14h] [bp-4h]@2

  switch ( this->inputEvt.eventCode )
  {
    case 4:
      hex = CombatManager::getHexIdxForMouseCoords(combatManager, this->inputEvt.xCoordOrKeycode, this->inputEvt.yCoord);
      if ( dword_51A198 != hex )
      {
        if ( CombatManager::spellWillAffectUnitIn(combatManager, combatManager->current_spell_id, hex) )
        {
          dword_51A198 = hex;
          MouseManager::setSpriteIdx(mouseManager, spell_table[combatManager->current_spell_id].spriteIdx);
          CombatManager::showCastMessage(combatManager, combatManager->current_spell_id, hex);
        }
        else
        {
          dword_51A198 = -1;
          MouseManager::setSpriteIdx(mouseManager, 0);
          if ( combatManager->current_spell_id == SPELL_TELEPORT && dword_519FD8 )
            CombatManager::displayCombatMessage(combatManager, "Invalid Teleport Destination", 1, 0, 0);
          else
            CombatManager::displayCombatMessage(combatManager, "Select Spell Target", 1, 0, 0);
        }
      }
      return 1;
    case 8:
      if ( dword_51A198 == -1 )
        return 1;
      if ( dword_519FD8 )
      {
        dword_524C68 = dword_51A198;
      }
      else
      {
        notTargetForAISpell = dword_51A198;
        if ( combatManager->current_spell_id == 4 )
        {
          dword_519FD8 = 1;
          dword_51A198 = -1;
          this->inputEvt.eventCode = 4;
          this->inputEvt.xCoordOrKeycode = this->inputEvt.altXCoord;
          this->inputEvt.yCoord = this->inputEvt.altYCoord;
          castSpellHexSelectionCallback(this);
          CombatManager::displayCombatMessage(combatManager, "Select teleport destination.", 1, 0, 0);
          return 1;
        }
      }
      dword_519FD8 = 0;
      this->inputEvt.eventCode = 512;
      this->inputEvt.xCoordOrKeycode = 10;
      return 2;
    case 1:
      if ( this->guiMsg.messageType == 1 )
        goto LABEL_19;
      return 1;
    case 32:
LABEL_19:
      combatManager->current_spell_id = -1;
      couldBeCreatureActionType = 0;
      this->inputEvt.eventCode = 512;
      this->inputEvt.xCoordOrKeycode = 10;
      dword_519FD8 = 0;
      return 2;
    default:
      return 1;
  }
}
