{
  char *v4; // [sp+14h] [bp-8h]@10
  army *targ; // [sp+18h] [bp-4h]@7

  if ( !gbNoShowCombat )
  {
    switch ( spell )
    {
      case SPELL_FIREBALL:
      case SPELL_FIREBLAST:
      case SPELL_METEOR_SHOWER:
      case SPELL_COLD_RING:
        sprintf(gText, "Cast %s", gSpellNames[spell]);
        break;
      case SPELL_TELEPORT:
        if ( !bInTeleportGetDest )
          goto LABEL_8;
        sprintf(gText, "Teleport Here");
        break;
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD:
        targ = &this->creatures[this->currentActionSide][combatManager::FindResurrectArmyIndex(
                                                           this,
                                                           this->currentActionSide,
                                                           (Spell)spell,
                                                           hex)];
        goto LABEL_9;
      default:
LABEL_8:
        targ = &this->creatures[this->combatGrid[hex].unitOwner][this->combatGrid[hex].stackIdx];
LABEL_9:
        if ( targ->quantity == 1 )
          v4 = gArmyNames[targ->creatureIdx];
        else
          v4 = gArmyNamesPlural[targ->creatureIdx];
        sprintf(gText, "Cast %s on %s", gSpellNames[spell], v4);
        break;
    }
    combatManager::CombatMessage(this, gText, 1, 0, 0);
  }
}