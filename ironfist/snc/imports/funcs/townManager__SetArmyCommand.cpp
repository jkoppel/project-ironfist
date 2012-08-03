{
  townManager *thisa; // [sp+Ch] [bp-Ch]@1
  signed int v3; // [sp+10h] [bp-8h]@8
  signed int v4; // [sp+14h] [bp-4h]@1

  thisa = this;
  this->field_14A = -1;
  v4 = 0;
  if ( armyGroup::GetNumArmies(this->field_DE->army) == 1
    && thisa->field_DE == thisa->visitingArmyDisplay
    && thisa->field_E6 != thisa->field_DE )
    v4 = 1;
  if ( thisa->field_E6 != thisa->field_DE || thisa->field_E2 != thisa->field_EA )
  {
    v3 = 0;
    if ( thisa->field_DE->army->creatureTypes[thisa->field_E2] == thisa->field_E6->army->creatureTypes[thisa->field_EA] )
      v3 = 1;
    if ( v3 )
    {
      if ( a2 )
      {
        sprintf(thisa->infoMessage, cTownCommand, gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 5;
      }
      else
      {
        if ( v4 )
        {
          strcpy(thisa->infoMessage, off_4F6624);
          return;
        }
        sprintf(thisa->infoMessage, off_4F6628, gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 2;
      }
    }
    else if ( a2 && thisa->field_E6->army->creatureTypes[thisa->field_EA] == -1 )
    {
      sprintf(thisa->infoMessage, off_4F662C, gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
      thisa->field_14A = 5;
    }
  }
  else
  {
    sprintf(thisa->infoMessage, off_4F6630, gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
    thisa->field_14A = 1;
  }
  if ( thisa->field_14A == -1 )
  {
    if ( thisa->field_E6->army->creatureTypes[thisa->field_EA] == -1 )
    {
      if ( v4 )
      {
        strcpy(thisa->infoMessage, off_4F6634);
      }
      else
      {
        sprintf(thisa->infoMessage, off_4F6638, gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]]);
        thisa->field_14A = 3;
      }
    }
    else
    {
      sprintf(
        thisa->infoMessage,
        off_4F663C,
        gArmyNames[thisa->field_DE->army->creatureTypes[thisa->field_E2]],
        gArmyNames[thisa->field_E6->army->creatureTypes[thisa->field_EA]]);
      thisa->field_14A = 3;
    }
  }
}