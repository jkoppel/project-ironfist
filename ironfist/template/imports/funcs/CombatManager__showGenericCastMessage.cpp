{
  CombatManager *thisa; // [sp+Ch] [bp-1D8h]@1
  const char *v5; // [sp+10h] [bp-1D4h]@3
  char message[400]; // [sp+18h] [bp-1CCh]@8
  char creatureName[60]; // [sp+1A8h] [bp-3Ch]@5

  thisa = this;
  if ( stack )
  {
    if ( stack->quantity <= 1 )
      v5 = creatureSingularNames[stack->creatureIdx];
    else
      v5 = creaturePluralNames[stack->creatureIdx];
    sprintf(creatureName, v5);
  }
  if ( a2 )
  {
    switch ( spell )
    {
      case SPELL_PARALYZE:
        sprintf(message, "The %s are paralyzed by the Cyclopes!", creatureName);
        break;
      case SPELL_BLIND:
        sprintf(message, "The Unicorns' attack blinds the %s!", creatureName);
        break;
      case SPELL_MEDUSA_PETRIFY:
        sprintf(message, "The Medusas' gaze turns the %s to stone!", creatureName);
        break;
      case SPELL_CURSE:
        sprintf(message, "The Mummies' curse falls upon the %s!", creatureName);
        break;
      case SPELL_ARCHMAGI_DISPEL:
        sprintf(message, "The Archmagi dispel all good spells\non the %s!", creatureName);
        break;
    }
  }
  else
  {
    if ( stack )
    {
      if ( thisa->heroes[thisa->currentActionSide]->field_E7[0] )
        sprintf(message, "The captain casts '%s' on the %s.", spell_names[spell], creatureName);
      else
        sprintf(
          message,
          "%s casts '%s' on the %s.",
          thisa->heroes[thisa->currentActionSide]->name,
          spell_names[spell],
          creatureName);
    }
    else
    {
      if ( thisa->heroes[thisa->currentActionSide]->field_E7[0] )
        sprintf(message, "The captain casts '%s'.", spell_names[spell]);
      else
        sprintf(message, "%s casts '%s'.", thisa->heroes[thisa->currentActionSide]->name, spell_names[spell]);
    }
  }
  CombatManager::displayCombatMessage(thisa, message, 1, 1, 0);
}
