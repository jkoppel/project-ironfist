{
  signed int result; // eax@33
  signed int v2; // [sp+Ch] [bp-E0h]@18
  signed int v3; // [sp+14h] [bp-D8h]@5
  int v4; // [sp+18h] [bp-D4h]@1
  signed int v5; // [sp+1Ch] [bp-D0h]@5
  char msg; // [sp+20h] [bp-CCh]@19
  int v7; // [sp+E8h] [bp-4h]@1

  v4 = this;
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
            v5 = 4;
          }
          else
          {
            switch ( v3 )
            {
              case 101:
                v5 = 0;
                break;
              case 102:
                v5 = 1;
                break;
              case 106:
                v5 = 2;
                break;
              case 105:
                v5 = 3;
                break;
              default:
                break;
            }
          }
        }
        if ( v5 >= 0 )
          display_message_window(adventureMapLocationMessages[v5 + 96], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      }
    }
    else
    {
      if ( *(_DWORD *)(this + 4) == 13 )
      {
        v2 = *(_DWORD *)(this + 8);
        if ( v2 <= 30720 )
        {
          if ( v2 == 30720 )
          {
LABEL_26:
            v7 = 1;
          }
          else
          {
            switch ( v2 )
            {
              case 101:
                strcpy(&msg, "Are you sure you want to restart?  (Your current game will be lost)");
                goto LABEL_22;
              case 102:
                strcpy(&msg, "Are you sure you want to load a new game?  (Your current game will be lost)");
                goto LABEL_22;
              case 105:
                strcpy(&msg, "Are you sure you want to quit?");
LABEL_22:
                v7 = 1;
                if ( !dword_5235D8 )
                {
                  display_message_window(&msg, 2, -1, -1, -1, 0, -1, 0, -1, 0);
                  if ( HeroWindowManager::instance->buttonPressedCode == 30726 )
                    v7 = 0;
                }
                break;
              case 106:
                goto LABEL_26;
              default:
                break;
            }
          }
        }
      }
    }
  }
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
