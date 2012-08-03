{
  CREATURE_FLAGS v3; // [sp+Ch] [bp-1Ch]@14
  int v4; // [sp+10h] [bp-18h]@3
  int v5; // [sp+14h] [bp-14h]@2
  int v6; // [sp+18h] [bp-10h]@1
  signed int v7; // [sp+20h] [bp-8h]@1

  v6 = this;
  v7 = 0;
  if ( *(_DWORD *)a2 != 512 )
    return 1;
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 == 12 )
  {
LABEL_3:
    v4 = *(_DWORD *)(a2 + 8);
    if ( v4 == 66 )
    {
      game::ViewArmy(
        gpGame,
        119,
        32,
        *(CREATURES *)(this + 58),
        0,
        0,
        1,
        1u,
        (*(_BYTE *)(a2 + 13) & 2) != 0,
        0,
        0,
        0,
        0);
    }
    else if ( v4 == 68 && !(*(_BYTE *)(a2 + 13) & 2) )
    {
      *(_DWORD *)(a2 + 4) = 7;
      heroWindow::BroadcastMessage(*(heroWindow **)(this + 82), (Event *)a2);
      *(_DWORD *)(v6 + 122) = atoi(*(int **)(a2 + 24));
      if ( *(_DWORD *)(v6 + 122) < 0 )
        *(_DWORD *)(v6 + 122) = 0;
      if ( *(_DWORD *)(v6 + 122) > *(_DWORD *)(v6 + 110) )
        *(_DWORD *)(v6 + 122) = *(_DWORD *)(v6 + 110);
    }
    recruitUnit::Update(v6);
    heroWindow::DrawWindow(*(heroWindow **)(v6 + 82), 1, 0, 32767);
    goto LABEL_47;
  }
  if ( v5 != 13 )
  {
    if ( v5 != 14 )
      goto LABEL_47;
    goto LABEL_3;
  }
  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 > (CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800) )
  {
    if ( v3 == 30722 && !(*(_BYTE *)(a2 + 13) & 2) )
    {
      if ( *(_DWORD *)(this + 122) )
      {
        if ( armyGroup::CanJoin(*(armyGroup **)(this + 90), *(_DWORD *)(this + 58)) )
        {
          armyGroup::Add(*(armyGroup **)(v6 + 90), *(_DWORD *)(v6 + 58), *(_DWORD *)(v6 + 122), -1);
          gpCurPlayer->resources[6] -= *(_DWORD *)(v6 + 66) * *(_DWORD *)(v6 + 122);
          if ( *(_DWORD *)(v6 + 70) != -1 )
            gpCurPlayer->resources[*(_DWORD *)(v6 + 70)] -= *(_DWORD *)(v6 + 74) * *(_DWORD *)(v6 + 122);
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
      case CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800:
        if ( !(*(_BYTE *)(a2 + 13) & 2) )
        {
          *(_DWORD *)(this + 122) = 0;
          v7 = 1;
        }
        break;
      case RETALIATED|SHOOTER|TWO_HEXER:
        if ( !(*(_BYTE *)(a2 + 13) & 2) )
        {
          ++*(_DWORD *)(this + 122);
          if ( *(_DWORD *)(this + 122) > *(_DWORD *)(this + 110) )
            *(_DWORD *)(this + 122) = *(_DWORD *)(this + 110);
          recruitUnit::Update(this);
          heroWindow::DrawWindow(*(heroWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
      case RETALIATED|SHOOTER|FLYER:
        if ( !(*(_BYTE *)(a2 + 13) & 2) )
        {
          --*(_DWORD *)(this + 122);
          if ( *(_DWORD *)(this + 122) < 0 )
            *(_DWORD *)(this + 122) = 0;
          recruitUnit::Update(this);
          heroWindow::DrawWindow(*(heroWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
      default:
        if ( v3 == 71 && !(*(_BYTE *)(a2 + 13) & 2) )
        {
          *(_DWORD *)(this + 122) = *(_DWORD *)(this + 110);
          recruitUnit::Update(this);
          heroWindow::DrawWindow(*(heroWindow **)(v6 + 82), 1, 0, 32767);
        }
        break;
    }
  }
LABEL_47:
  if ( v7 == 1 )
  {
    *(_DWORD *)a2 = 16384;
    *(_DWORD *)(a2 + 4) = 4;
    return 2;
  }
  return 1;
}