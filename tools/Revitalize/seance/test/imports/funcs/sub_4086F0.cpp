{
  CREATURE_FLAGS v3; // [sp+Ch] [bp-1Ch]@17
  int v4; // [sp+10h] [bp-18h]@6
  int v5; // [sp+14h] [bp-14h]@5
  int v6; // [sp+18h] [bp-10h]@1
  signed int v7; // [sp+20h] [bp-8h]@1
  int a9; // [sp+24h] [bp-4h]@2

  v6 = this;
  v7 = 0;
  if ( *(_BYTE *)(a2 + 13) & 2 )
    a9 = 1;
  else
    a9 = 0;
  if ( *(_DWORD *)a2 != 512 )
    return 1;
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 == 12 )
  {
LABEL_6:
    v4 = *(_DWORD *)(a2 + 8);
    if ( v4 == 66 )
    {
      GameInfo::showStackInfo(gameObject, 119, 32, *(CREATURES *)(this + 58), 0, 0, 1, 1u, a9, 0, 0, 0, 0);
    }
    else
    {
      if ( v4 == 68 && !a9 )
      {
        *(_DWORD *)(a2 + 4) = 7;
        GUIWindow::processMessage(*(GUIWindow **)(this + 82), (Event *)a2);
        *(_DWORD *)(v6 + 122) = atoi(*(const char **)(a2 + 24));
        if ( *(_DWORD *)(v6 + 122) < 0 )
          *(_DWORD *)(v6 + 122) = 0;
        if ( *(_DWORD *)(v6 + 122) > *(_DWORD *)(v6 + 110) )
          *(_DWORD *)(v6 + 122) = *(_DWORD *)(v6 + 110);
      }
    }
    sub_4085C0(v6);
    GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v6 + 82), 1, 0, 32767);
    goto LABEL_50;
  }
  if ( v5 != 13 )
  {
    if ( v5 != 14 )
      goto LABEL_50;
    goto LABEL_6;
  }
  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 > (CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800) )
  {
    if ( v3 == 30722 && !a9 )
    {
      if ( *(_DWORD *)(this + 122) )
      {
        if ( ArmyInfo::hasRoomForCreatureType(*(ArmyInfo **)(this + 90), *(_DWORD *)(this + 58)) )
        {
          ArmyInfo::addCreatures(*(ArmyInfo **)(v6 + 90), *(_DWORD *)(v6 + 58), *(_DWORD *)(v6 + 122), -1);
          curPlayer->resources[6] -= *(_DWORD *)(v6 + 66) * *(_DWORD *)(v6 + 122);
          if ( *(_DWORD *)(v6 + 70) != -1 )
            curPlayer->resources[*(_DWORD *)(v6 + 70)] -= *(_DWORD *)(v6 + 74) * *(_DWORD *)(v6 + 122);
          **(_WORD **)(v6 + 106) -= *(_WORD *)(v6 + 122);
          *(_DWORD *)(v6 + 98) = 1;
          v7 = 1;
        }
        else
        {
          v7 = 1;
          *(_DWORD *)(v6 + 102) = 1;
        }
      }
      else
      {
        v7 = 1;
      }
    }
  }
  else
  {
    switch ( v3 )
    {
      case 30721:
        if ( !a9 )
        {
          *(_DWORD *)(this + 122) = 0;
          v7 = 1;
        }
        break;
      case 69:
        if ( !a9 )
        {
          ++*(_DWORD *)(this + 122);
          if ( *(_DWORD *)(this + 122) > *(_DWORD *)(this + 110) )
            *(_DWORD *)(this + 122) = *(_DWORD *)(this + 110);
          sub_4085C0(this);
          GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
      case 70:
        if ( !a9 )
        {
          --*(_DWORD *)(this + 122);
          if ( *(_DWORD *)(this + 122) < 0 )
            *(_DWORD *)(this + 122) = 0;
          sub_4085C0(this);
          GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
      default:
        if ( v3 == 71 && !a9 )
        {
          *(_DWORD *)(this + 122) = *(_DWORD *)(this + 110);
          sub_4085C0(this);
          GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
    }
  }
LABEL_50:
  if ( v7 == 1 )
  {
    *(_DWORD *)a2 = 16384;
    *(_DWORD *)(a2 + 4) = 4;
    return 2;
  }
  return 1;
}
