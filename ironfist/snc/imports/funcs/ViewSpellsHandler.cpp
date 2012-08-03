{
  int result; // eax@3
  int v2; // ST40_4@30
  int v3; // ST1C_4@42
  signed int v4; // eax@42
  int v5; // [sp+Ch] [bp-18h]@38
  int v6; // [sp+14h] [bp-10h]@10
  int v7; // [sp+18h] [bp-Ch]@6
  tag_message *a2; // [sp+1Ch] [bp-8h]@1
  int spell; // [sp+20h] [bp-4h]@39

  a2 = this;
  if ( this->eventCode == 4 )
  {
    heroWindowManager::ConvertToHover(gpWindowManager, this);
    if ( gpWindowManager->field_5E == a2->yCoord )
      result = 1;
    else
      result = ((int (__thiscall *)(tag_message *))gpGame->callback)(a2);
    return result;
  }
  if ( this->eventCode != 512 )
    return 1;
  v7 = this->xCoordOrKeycode;
  if ( v7 != 12 )
  {
    if ( v7 == 13 )
    {
      if ( this->xCoordOrKeycode != 14 )
      {
        if ( !(BYTE1(this->inputTypeBitmask) & 2) )
        {
          v6 = this->yCoord;
          if ( v6 <= 30720 )
          {
            if ( v6 == 30720 )
            {
              this->yCoord = 10;
            }
            else
            {
              switch ( v6 )
              {
                case 6:
                case 7:
                case 8:
                case 9:
                  sprintf(gText, off_4F64B0, viewSpellsHero->spellpoints);
                  NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
                  break;
                case 2:
                  if ( *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] )
                  {
                    *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] -= 12;
                    if ( *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] < 0 )
                      *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] = 0;
                    game::UpdateSpellWidgets((int)gpGame);
                    heroWindow::MoveWindow(*(heroWindow **)&gpGame->_10[620], 0, 0);
                  }
                  else
                  {
                    game::UpdateSpellWidgets((int)gpGame);
                    heroWindow::MoveWindow(*(heroWindow **)&gpGame->_10[620], 0, 0);
                  }
                  break;
                case 3:
                  if ( *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] + 12 < *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 640] )
                    *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] += 12;
                  game::UpdateSpellWidgets((int)gpGame);
                  heroWindow::MoveWindow(*(heroWindow **)&gpGame->_10[620], 0, 0);
                  break;
                case 4:
                  *(_DWORD *)&gpGame->_10[628] = 1;
                  game::UpdateSpellWidgets((int)gpGame);
                  heroWindow::MoveWindow(*(heroWindow **)&gpGame->_10[620], 0, 0);
                  break;
                case 5:
                  *(_DWORD *)&gpGame->_10[628] = 0;
                  game::UpdateSpellWidgets((int)gpGame);
                  heroWindow::MoveWindow(*(heroWindow **)&gpGame->_10[620], 0, 0);
                  break;
                default:
                  break;
              }
            }
          }
        }
      }
LABEL_50:
      if ( a2->yCoord == 10 )
      {
        a2->xCoordOrKeycode = a2->yCoord;
        return 2;
      }
      return 1;
    }
    if ( v7 != 14 )
      goto LABEL_50;
  }
  if ( this->xCoordOrKeycode == 14 || BYTE1(this->inputTypeBitmask) & 2 )
  {
    switch ( this->yCoord )
    {
      case 0x64:
      case 0x65:
      case 0x66:
      case 0x67:
      case 0x68:
      case 0x69:
      case 0x6A:
      case 0x6B:
      case 0x6C:
      case 0x6D:
      case 0x6E:
      case 0x6F:
        v2 = hero::GetNthSpell(
               *(hero **)&gpGame->_10[624],
               *(_DWORD *)&gpGame->_10[628],
               this->yCoord - 100 + *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] + 1);
        NormalDialog(gSpellDesc[v2], 4, -1, -1, 8, v2, -1, 0, -1, 0);
        break;
      case 2:
        NormalDialog(cSpellHelp, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 3:
        NormalDialog(off_4F6494, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 4:
        NormalDialog(off_4F6498, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 5:
        NormalDialog(off_4F649C, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 6:
      case 7:
      case 8:
      case 9:
        sprintf(gText, off_4F64B0, viewSpellsHero->spellpoints);
        NormalDialog(gText, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      default:
        goto LABEL_50;
    }
    goto LABEL_50;
  }
  v5 = this->yCoord;
  if ( v5 < 100 || v5 > 111 )
    goto LABEL_50;
  spell = hero::GetNthSpell(
            *(hero **)&gpGame->_10[624],
            *(_DWORD *)&gpGame->_10[628],
            this->yCoord - 100 + *(_DWORD *)&gpGame->_10[4 * *(_DWORD *)&gpGame->_10[628] + 632] + 1);
  if ( LOBYTE(gpGame->field_660D) )
  {
    NormalDialog(gSpellDesc[spell], 1, -1, -1, 8, spell, -1, 0, -1, 0);
    result = 1;
  }
  else if ( GetManaCost(spell, viewSpellsHero) <= viewSpellsHero->spellpoints )
  {
    *(_DWORD *)&gpGame->_10[648] = spell;
    a2->xCoordOrKeycode = 10;
    result = 2;
  }
  else
  {
    v3 = viewSpellsHero->spellpoints;
    v4 = GetManaCost(spell, viewSpellsHero);
    sprintf(gText, "That spell costs %d mana.  You only have %d mana, so you can't cast the spell.", v4, v3);
    NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    result = 0;
  }
  return result;
}