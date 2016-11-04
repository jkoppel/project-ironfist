{
  int result; // eax@3
  int v2; // ST40_4@30
  int v3; // ST1C_4@42
  signed int v4; // eax@42
  signed int v5; // [sp+Ch] [bp-18h]@38
  signed int v6; // [sp+14h] [bp-10h]@10
  int v7; // [sp+18h] [bp-Ch]@6
  int a2; // [sp+1Ch] [bp-8h]@1
  int spell; // [sp+20h] [bp-4h]@39

  a2 = this;
  if ( *(_DWORD *)this == 4 )
  {
    HeroWindowManager::handleInputThunk(HeroWindowManager::instance, (InputEvent *)this);
    if ( HeroWindowManager::instance->field_5E == *(_DWORD *)(a2 + 8) )
      result = 1;
    else
      result = ((int (__thiscall *)(int))gameObject->callback)(a2);
    return result;
  }
  if ( *(_DWORD *)this != 512 )
    return 1;
  v7 = *(_DWORD *)(this + 4);
  if ( v7 != 12 )
  {
    if ( v7 == 13 )
    {
      if ( *(_DWORD *)(this + 4) != 14 )
      {
        if ( !(*(_BYTE *)(this + 13) & 2) )
        {
          v6 = *(_DWORD *)(this + 8);
          if ( v6 <= 30720 )
          {
            if ( v6 == 30720 )
            {
              *(_DWORD *)(this + 8) = 10;
            }
            else
            {
              switch ( v6 )
              {
                case 6:
                case 7:
                case 8:
                case 9:
                  sprintf(globBuf, off_4F64B0, dword_522FB0->spellpoints);
                  display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
                  break;
                case 2:
                  if ( *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] )
                  {
                    *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] -= 12;
                    if ( *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] < 0 )
                      *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] = 0;
                    sub_4219A0((int)gameObject);
                    GUIWindow::move(*(GUIWindow **)&gameObject->_10[620], 0, 0);
                  }
                  else
                  {
                    sub_4219A0((int)gameObject);
                    GUIWindow::move(*(GUIWindow **)&gameObject->_10[620], 0, 0);
                  }
                  break;
                case 3:
                  if ( *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] + 12 < *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 640] )
                    *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] += 12;
                  sub_4219A0((int)gameObject);
                  GUIWindow::move(*(GUIWindow **)&gameObject->_10[620], 0, 0);
                  break;
                case 4:
                  *(_DWORD *)&gameObject->_10[628] = 1;
                  sub_4219A0((int)gameObject);
                  GUIWindow::move(*(GUIWindow **)&gameObject->_10[620], 0, 0);
                  break;
                case 5:
                  *(_DWORD *)&gameObject->_10[628] = 0;
                  sub_4219A0((int)gameObject);
                  GUIWindow::move(*(GUIWindow **)&gameObject->_10[620], 0, 0);
                  break;
                default:
                  break;
              }
            }
          }
        }
      }
LABEL_50:
      if ( *(_DWORD *)(a2 + 8) == 10 )
      {
        *(_DWORD *)(a2 + 4) = *(_DWORD *)(a2 + 8);
        return 2;
      }
      return 1;
    }
    if ( v7 != 14 )
      goto LABEL_50;
  }
  if ( *(_DWORD *)(this + 4) == 14 || *(_BYTE *)(this + 13) & 2 )
  {
    switch ( *(_DWORD *)(this + 8) )
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
        v2 = Hero::getKthSpellKnown(
               *(Hero **)&gameObject->_10[624],
               *(_DWORD *)&gameObject->_10[628],
               *(_DWORD *)(this + 8) - 100 + *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] + 1);
        display_message_window(spell_descriptions[v2], 4, -1, -1, 8, v2, -1, 0, -1, 0);
        break;
      case 2:
        display_message_window(off_4F6490, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 3:
        display_message_window(off_4F6494, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 4:
        display_message_window(off_4F6498, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 5:
        display_message_window(off_4F649C, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case 6:
      case 7:
      case 8:
      case 9:
        sprintf(globBuf, off_4F64B0, dword_522FB0->spellpoints);
        display_message_window(globBuf, 4, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      default:
        goto LABEL_50;
    }
    goto LABEL_50;
  }
  v5 = *(_DWORD *)(this + 8);
  if ( v5 < 100 || v5 > 111 )
    goto LABEL_50;
  spell = Hero::getKthSpellKnown(
            *(Hero **)&gameObject->_10[624],
            *(_DWORD *)&gameObject->_10[628],
            *(_DWORD *)(this + 8) - 100 + *(_DWORD *)&gameObject->_10[4 * *(_DWORD *)&gameObject->_10[628] + 632] + 1);
  if ( LOBYTE(gameObject->field_660D) )
  {
    display_message_window(spell_descriptions[spell], 1, -1, -1, 8, spell, -1, 0, -1, 0);
    result = 1;
  }
  else
  {
    if ( getSpellCost(spell, dword_522FB0) <= dword_522FB0->spellpoints )
    {
      *(_DWORD *)&gameObject->_10[648] = spell;
      *(_DWORD *)(a2 + 4) = 10;
      result = 2;
    }
    else
    {
      v3 = dword_522FB0->spellpoints;
      v4 = getSpellCost(spell, dword_522FB0);
      sprintf(globBuf, "That spell costs %d mana.  You only have %d mana, so you can't cast the spell.", v4, v3);
      display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      result = 0;
    }
  }
  return result;
}
