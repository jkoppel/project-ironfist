void __thiscall sub_4C3820(CombatManager *this, int a2)
{
  char *v2; // eax@4
  CombatManager *thisa; // [sp+10h] [bp-14h]@1
  CREATURES v4; // [sp+14h] [bp-10h]@3
  CREATURES v5; // [sp+14h] [bp-10h]@28
  int v6; // [sp+1Ch] [bp-8h]@3
  int v7; // [sp+20h] [bp-4h]@3

  thisa = this;
  if ( this->checkedInsub4c3d60 && !combatGraphicsOff )
  {
    v4 = this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creatureIdx;
    v6 = 0;
    v7 = 0;
    if ( *(_QWORD *)&this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetOwner >= 0i64 )
    {
      v2 = (char *)this
         + 24234 * this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetOwner
         + 1154 * this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].targetStackIdx;
      v6 = (int)(v2 + 13647);
      v7 = *(_DWORD *)(v2 + 13765);
    }
    switch ( a2 )
    {
      case 0:
        if ( this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.creature_flags & 4
          && !this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.shots
          && v6 )
          strcpy(globBuf, off_4F65D0);
        else
          strcpy(globBuf, off_4F65B0);
        break;
      case 1:
        sprintf(globBuf, off_4F65B4, creatureSingularNames[v4]);
        break;
      case 2:
        sprintf(globBuf, off_4F65B8, creatureSingularNames[v4]);
        break;
      case 7:
        sprintf(globBuf, off_4F65BC, creatureSingularNames[v7]);
        break;
      case 3:
      case 15:
        sprintf(
          globBuf,
          off_4F65C0,
          creatureSingularNames[v7],
          this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].creature.shots);
        break;
      case 4:
        if ( this->heroes[this->currentActionSide] && this->heroes[this->currentActionSide]->field_E7[0] )
          strcpy(globBuf, off_4F65D4);
        else
          strcpy(globBuf, off_4F65C4);
        break;
      case 13:
        if ( this->heroes[1 - this->currentActionSide] && this->heroes[1 - this->currentActionSide]->field_E7[0] )
          strcpy(globBuf, off_4F65D8);
        else
          strcpy(globBuf, off_4F65C8);
        break;
      case 5:
        if ( this->field_F2C3 == 77 )
        {
          sprintf(globBuf, off_4F65DC);
        }
        else
        {
          v5 = this->creatures[this->otherCurrentSideThing][this->combatGrid[this->field_F2C3].stackIdx].creatureIdx;
          if ( (signed int)v5 < 0 )
            sprintf(globBuf, byte_51E3B4);
          else
            sprintf(globBuf, off_4F65CC, creatureSingularNames[v5]);
        }
        break;
      default:
        break;
    }
    CombatManager::displayCombatMessage(thisa, globBuf, 1, 0, 0);
  }
}
