{
  army *v2; // eax@4
  int creatIdx; // [sp+14h] [bp-10h]@3
  CREATURES creatIdxa; // [sp+14h] [bp-10h]@28
  char *v6; // [sp+1Ch] [bp-8h]@3
  int v7; // [sp+20h] [bp-4h]@3

  if ( this->checkedInsub4c3d60 && !gbNoShowCombat )
  {
    creatIdx = this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creatureIdx;
    v6 = 0;
    v7 = 0;
    if ( *(_QWORD *)&this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetOwner >= 0i64 )
    {
      v2 = (army *)((char *)this
                  + 24234 * this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetOwner
                  + 1154 * this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetStackIdx);
      v6 = &v2[11].gap_129[656];
      v7 = *(_DWORD *)&v2[11].gap_129[774];
    }
    switch ( a2 )
    {
      case 0:
        if ( this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.creature_flags & 4
          && !this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.shots
          && v6 )
          strcpy(gText, off_4F65D0);
        else
          strcpy(gText, off_4F65B0);
        break;
      case 1:
        sprintf(gText, off_4F65B4, gArmyNames[creatIdx]);
        break;
      case 2:
        sprintf(gText, off_4F65B8, gArmyNames[creatIdx]);
        break;
      case 7:
        sprintf(gText, off_4F65BC, gArmyNames[v7]);
        break;
      case 3:
      case 15:
        sprintf(
          gText,
          off_4F65C0,
          gArmyNames[v7],
          this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.shots);
        break;
      case 4:
        if ( this->heroes[this->currentActionSide] && this->heroes[this->currentActionSide]->field_E7[0] )
          strcpy(gText, off_4F65D4);
        else
          strcpy(gText, off_4F65C4);
        break;
      case 13:
        if ( this->heroes[1 - this->currentActionSide] && this->heroes[1 - this->currentActionSide]->field_E7[0] )
          strcpy(gText, off_4F65D8);
        else
          strcpy(gText, off_4F65C8);
        break;
      case 5:
        if ( this->field_F2C3 == 77 )
        {
          sprintf(gText, off_4F65DC);
        }
        else
        {
          creatIdxa = this->creatures[this->otherCurrentSideThing][this->combatGrid[this->field_F2C3].stackIdx].creatureIdx;
          if ( (signed int)creatIdxa < 0 )
            sprintf(gText, byte_51E3B4);
          else
            sprintf(gText, off_4F65CC, gArmyNames[creatIdxa]);
        }
        break;
      default:
        break;
    }
    combatManager::CombatMessage(this, gText, 1, 0, 0);
  }
}