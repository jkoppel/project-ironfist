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
          strcpy(this->infoMessage, off_4F6640);
      }
      else
      {
        if ( fieldID >= 128 )
        {
LABEL_3:
          strcpy(this->infoMessage, off_4F6644);
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
                strcpy(this->infoMessage, off_4F664C);
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
        strcpy(this->infoMessage, off_4F6654);
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
                strcpy(this->infoMessage, off_4F664C);
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
          strcpy(this->infoMessage, off_4F6658);
          break;
        case 2:
          strcpy(this->infoMessage, off_4F665C);
          break;
        case 3:
          if ( this->castle->factionID == 5 )
            strcpy(this->infoMessage, shrineName);
          else
            strcpy(this->infoMessage, off_4F6660);
          break;
        case 4:
        case 15:
          strcpy(this->infoMessage, off_4F6664);
          break;
        case 5:
          strcpy(this->infoMessage, off_4F6668);
          break;
        case 6:
          strcpy(this->infoMessage, off_4F666C);
          break;
        case 7:
          strcpy(this->infoMessage, off_4F6670);
          break;
        case 8:
          strcpy(this->infoMessage, off_4F6678);
          break;
        case 9:
          strcpy(this->infoMessage, off_4F667C);
          break;
        case 10:
          strcpy(this->infoMessage, off_4F6680);
          break;
        case 13:
          strcpy(this->infoMessage, off_4F6684);
          break;
        case 11:
          strcpy(this->infoMessage, off_4F6688);
          break;
        case 16:
          strcpy(this->infoMessage, off_4F668C);
          break;
        case 14:
          strcpy(this->infoMessage, special_building_names[this->castle->factionID]);
          break;
        case 12:
          strcpy(this->infoMessage, growth_building_names[this->castle->factionID]);
          break;
        default:
          break;
      }
    }
  }
  TownManager::refreshInfoMessage(thisa, thisa->infoMessage);
}
