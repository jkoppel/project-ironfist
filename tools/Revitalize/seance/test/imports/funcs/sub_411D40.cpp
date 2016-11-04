{
  char *result; // eax@14
  TownManager *thisa; // [sp+Ch] [bp-Ch]@1
  signed int v4; // [sp+10h] [bp-8h]@8
  signed int v5; // [sp+14h] [bp-4h]@1

  thisa = this;
  this->field_14A = -1;
  v5 = 0;
  if ( ArmyInfo::getNumStacks(this->field_DE->army) == 1
    && thisa->field_DE == thisa->visitingArmyDisplay
    && thisa->field_E6 != thisa->field_DE )
    v5 = 1;
  if ( thisa->field_E6 != thisa->field_DE || thisa->field_E2 != thisa->field_EA )
  {
    v4 = 0;
    if ( thisa->field_DE->army->creatureTypes[thisa->field_E2] == thisa->field_E6->army->creatureTypes[thisa->field_EA] )
      v4 = 1;
    if ( v4 )
    {
      if ( a2 )
      {
        sprintf(
          thisa->infoMessage,
          off_4F6620,
          creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 5;
      }
      else
      {
        if ( v5 )
          return strcpy(thisa->infoMessage, off_4F6624);
        sprintf(
          thisa->infoMessage,
          off_4F6628,
          creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 2;
      }
    }
    else
    {
      if ( a2 && thisa->field_E6->army->creatureTypes[thisa->field_EA] == -1 )
      {
        sprintf(
          thisa->infoMessage,
          off_4F662C,
          creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 5;
      }
    }
  }
  else
  {
    sprintf(
      thisa->infoMessage,
      off_4F6630,
      creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
    thisa->field_14A = 1;
  }
  result = (char *)thisa;
  if ( thisa->field_14A == -1 )
  {
    if ( thisa->field_E6->army->creatureTypes[thisa->field_EA] == -1 )
    {
      if ( v5 )
      {
        result = strcpy(thisa->infoMessage, off_4F6634);
      }
      else
      {
        sprintf(
          thisa->infoMessage,
          off_4F6638,
          creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        result = (char *)thisa;
        thisa->field_14A = 3;
      }
    }
    else
    {
      sprintf(
        thisa->infoMessage,
        off_4F663C,
        creatureSingularNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]],
        creatureSingularNames[thisa->field_E6->army->creatureTypes[thisa->field_EA]]);
      result = (char *)thisa;
      thisa->field_14A = 3;
    }
  }
  return result;
}
