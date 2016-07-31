{
  signed int result; // eax@38
  int v2; // [sp+14h] [bp-90h]@19
  signed int v3; // [sp+18h] [bp-8Ch]@5
  int v4; // [sp+1Ch] [bp-88h]@1
  signed int v5; // [sp+20h] [bp-84h]@5
  signed int v6; // [sp+9Ch] [bp-8h]@1
  signed int v7; // [sp+A0h] [bp-4h]@1

  v4 = this;
  v6 = 0;
  v7 = 0;
  if ( *(_DWORD *)this == 512 )
  {
    if ( *(_BYTE *)(this + 13) & 2 )
    {
      if ( *(_DWORD *)(this + 4) == 12 || *(_DWORD *)(this + 4) == 14 )
      {
        v5 = -1;
        v3 = *(_DWORD *)(this + 8);
        if ( v3 <= 30720 )
        {
          if ( v3 == 30720 )
          {
            v5 = 0;
          }
          else
          {
            switch ( v3 )
            {
              case 10:
                v5 = 1;
                break;
              case 11:
                v5 = 2;
                break;
              case 12:
                v5 = 3;
                break;
              case 13:
                v5 = 4;
                break;
              case 14:
                v5 = 5;
                break;
              case 15:
                v5 = 6;
                break;
              default:
                break;
            }
          }
        }
        if ( v5 >= 0 )
          display_message_window(adventureMapLocationMessages[v5 + 102], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      }
    }
    else
    {
      v2 = *(_DWORD *)(this + 4);
      if ( v2 == 12 )
      {
        switch ( *(_DWORD *)(this + 8) )
        {
          case 0xA:
            *(_DWORD *)&combatSpeed = (*(_DWORD *)&combatSpeed + 1) % 3;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          case 0xB:
            *(_DWORD *)&combatArmyInfoLevel = (*(_DWORD *)&combatArmyInfoLevel + 1) % 3;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          case 0xC:
            *(_DWORD *)&autoCombatUseSpells = 1 - *(_DWORD *)&autoCombatUseSpells;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          case 0xD:
            *(_DWORD *)&showCombatGrid = 1 - *(_DWORD *)&showCombatGrid;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          case 0xE:
            combatShadeLevel = 1 - combatShadeLevel;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          case 0xF:
            *(_DWORD *)&showCombatMouseHex = 1 - *(_DWORD *)&showCombatMouseHex;
            v6 = 1;
            dword_52FAF0 = 1;
            break;
          default:
            break;
        }
      }
      else
      {
        if ( v2 == 13 && *(_DWORD *)(this + 8) == 30720 )
          v7 = 1;
      }
    }
  }
  if ( v6 )
    sub_47A5B0(0);
  if ( v7 )
  {
    HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(v4 + 8);
    *(_DWORD *)(v4 + 8) = 10;
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(v4 + 8);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
