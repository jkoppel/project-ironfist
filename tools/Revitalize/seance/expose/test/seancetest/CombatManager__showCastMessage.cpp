void __thiscall CombatManager::showCastMessage(CombatManager *this, int spell, int hex)
{
  char *v4; // [sp+14h] [bp-8h]@10
  CreatureStack *targ; // [sp+18h] [bp-4h]@7

  if ( !combatGraphicsOff )
  {
    switch ( spell )
    {
      case SPELL_FIREBALL:
      case SPELL_FIREBLAST:
      case SPELL_METEOR_SHOWER:
      case SPELL_COLD_RING:
        sprintf(globBuf, "Cast %s", spell_names[spell]);
        break;
      case SPELL_TELEPORT:
        if ( !dword_519FD8 )
          goto LABEL_8;
        sprintf(globBuf, "Teleport Here");
        break;
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD:
        targ = &this->creatures[this->currentActionSide][CombatManager::getCorpseStackIdx(
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
          v4 = creatureSingularNames[targ->creatureIdx];
        else
          v4 = creaturePluralNames[targ->creatureIdx];
        sprintf(globBuf, "Cast %s on %s", spell_names[spell], v4);
        break;
    }
    CombatManager::displayCombatMessage(this, globBuf, 1, 0, 0);
  }
}
