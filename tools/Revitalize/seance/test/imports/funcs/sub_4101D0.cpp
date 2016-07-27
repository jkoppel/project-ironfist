{
  signed int result; // eax@28
  signed int v2; // [sp+Ch] [bp-5Ch]@29
  signed int v3; // [sp+10h] [bp-58h]@19
  signed int v4; // [sp+18h] [bp-50h]@5
  int v5; // [sp+1Ch] [bp-4Ch]@1
  int a2; // [sp+20h] [bp-48h]@1
  signed int v7; // [sp+24h] [bp-44h]@3
  signed int v8; // [sp+28h] [bp-40h]@30
  signed int v9; // [sp+5Ch] [bp-Ch]@1

  a2 = this;
  v9 = 0;
  v5 = *(_DWORD *)this;
  if ( v5 != 4 )
  {
    if ( v5 == 512 )
    {
      if ( *(_BYTE *)(this + 13) & 2 )
      {
        v7 = -1;
        if ( *(_DWORD *)(this + 4) == 12 || *(_DWORD *)(this + 4) == 14 )
        {
          v4 = *(_DWORD *)(this + 8);
          if ( v4 <= 30720 )
          {
            switch ( v4 )
            {
              case 30720:
                v7 = 3;
                break;
              case 10:
                v7 = 0;
                break;
              case 11:
                v7 = 1;
                break;
              case 12:
                v7 = 2;
                break;
            }
          }
          if ( v7 != -1 )
            display_message_window((&off_4F65A0)[4 * v7], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      else
      {
        if ( *(_DWORD *)(this + 4) == 13 )
        {
          v3 = *(_DWORD *)(this + 8);
          if ( v3 >= 10 && (v3 <= 12 || v3 == 30720) )
          {
            HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(this + 8);
            v9 = 1;
          }
        }
      }
    }
    if ( v9 )
    {
      *(_DWORD *)(a2 + 8) = 10;
      *(_DWORD *)(a2 + 4) = *(_DWORD *)(a2 + 8);
      result = 2;
    }
    else
    {
      result = 1;
    }
    return result;
  }
  HeroWindowManager::handleInputThunk(HeroWindowManager::instance, (InputEvent *)this);
  if ( HeroWindowManager::instance->field_5E == *(_DWORD *)(a2 + 8) )
    return 1;
  HeroWindowManager::instance->field_5E = *(_DWORD *)(a2 + 8);
  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 <= 30720 )
  {
    if ( v2 == 30720 )
    {
      v8 = 4;
      goto LABEL_41;
    }
    if ( v2 == 10 )
    {
      v8 = 1;
      goto LABEL_41;
    }
    if ( v2 == 11 )
    {
      v8 = 2;
      goto LABEL_41;
    }
    if ( v2 == 12 )
    {
      v8 = 3;
      goto LABEL_41;
    }
  }
  v8 = 5;
LABEL_41:
  if ( v8 == 5 && combatManager->heroes[dword_4EE4A4]->field_E7[0] )
    v8 = 6;
  CombatManager::displayCombatMessage(combatManager, (&off_4F6580)[4 * v8], 1, 0, 0);
  return 1;
}
