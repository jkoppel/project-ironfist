void __thiscall TownManager::setMessageForMouseover(TownManager *this, GUIMessage *evt)
{
  TownManager *thisa; // [sp+10h] [bp-8h]@1
  int fieldID; // [sp+14h] [bp-4h]@1

  thisa = this;
  fieldID = evt->fieldID;
  this->field_14A = -1;
  if ( fieldID > 30 )
  {
    if ( fieldID > 122 )
    {
      if ( fieldID > 129 )
      {
        if ( fieldID == 30720 )
          strcpy((int)this->infoMessage);
      }
      else
      {
        if ( fieldID >= 128 )
        {
LABEL_3:
          strcpy((int)this->infoMessage);
        }
        else
        {
          if ( fieldID >= 123 && fieldID <= 127 )
          {
            if ( this->field_E2 == -1 )
            {
              this->field_D6 = this->visitingArmyDisplay;
              this->field_DA = fieldID - 123;
              if ( this->field_D6->army && this->field_D6->army->creatureTypes[this->field_DA] != -1 )
              {
                sprintf(
                  this->infoMessage,
                  off_4F6650,
                  creatureSingularNames[this->field_D6->army->creatureTypes[this->field_DA]]);
                thisa->field_14A = 0;
              }
              else
              {
                strcpy((int)this->infoMessage);
                thisa->field_14A = -1;
              }
            }
            else
            {
              this->field_E6 = this->visitingArmyDisplay;
              this->field_EA = fieldID - 123;
              sub_411D40(this, evt->inputTypeBitmask & 3);
            }
          }
        }
      }
    }
    else
    {
      if ( fieldID == 122 )
      {
        strcpy((int)this->infoMessage);
        thisa->field_14A = 4;
      }
      else
      {
        if ( fieldID == 116 )
        {
          sprintf(
            this->infoMessage,
            "%s: %d, %s: %d, %s: %d",
            "Month",
            gameObject->month,
            "Week",
            gameObject->week,
            "Day",
            gameObject->day);
        }
        else
        {
          if ( fieldID >= 117 && fieldID <= 121 )
          {
            if ( this->field_E2 == -1 )
            {
              this->field_D6 = this->garrisonDisplay;
              this->field_DA = fieldID - 117;
              if ( this->field_D6->army->creatureTypes[this->field_DA] == -1 )
              {
                strcpy((int)this->infoMessage);
              }
              else
              {
                sprintf(
                  this->infoMessage,
                  off_4F6650,
                  creatureSingularNames[this->field_D6->army->creatureTypes[this->field_DA]]);
                thisa->field_14A = 0;
              }
            }
            else
            {
              this->field_E6 = this->garrisonDisplay;
              this->field_EA = fieldID - 117;
              sub_411D40(this, evt->inputTypeBitmask & 3);
            }
          }
        }
      }
    }
  }
  else
  {
    if ( fieldID >= 19 )
    {
      sprintf(
        this->infoMessage,
        off_4F6674,
        creatureSingularNames[LOBYTE((&buildingShortNames[3 * this->castle->factionID + 27])[fieldID + 1])]);
    }
    else
    {
      switch ( fieldID + 1 )
      {
        case 0:
          goto LABEL_3;
        case 1:
          strcpy((int)this->infoMessage);
          break;
        case 2:
          strcpy((int)this->infoMessage);
          break;
        case 3:
          strcpy((int)this->infoMessage);
          break;
        case 4:
        case 15:
          strcpy((int)this->infoMessage);
          break;
        case 5:
          strcpy((int)this->infoMessage);
          break;
        case 6:
          strcpy((int)this->infoMessage);
          break;
        case 7:
          strcpy((int)this->infoMessage);
          break;
        case 8:
          strcpy((int)this->infoMessage);
          break;
        case 9:
          strcpy((int)this->infoMessage);
          break;
        case 10:
          strcpy((int)this->infoMessage);
          break;
        case 13:
          strcpy((int)this->infoMessage);
          break;
        case 11:
          strcpy((int)this->infoMessage);
          break;
        case 16:
          strcpy((int)this->infoMessage);
          break;
        case 14:
          strcpy((int)this->infoMessage);
          break;
        case 12:
          strcpy((int)this->infoMessage);
          break;
        default:
          break;
      }
    }
  }
  TownManager::refreshInfoMessage(thisa, thisa->infoMessage);
}
