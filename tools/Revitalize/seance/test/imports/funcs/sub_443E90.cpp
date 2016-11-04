{
  int v1; // eax@58
  int v2; // eax@59
  int thisa; // [sp+10h] [bp-7Ch]@1
  char v5; // [sp+14h] [bp-78h]@32
  InputEvent a2; // [sp+30h] [bp-5Ch]@25
  int i; // [sp+4Ch] [bp-40h]@18
  signed int a8; // [sp+50h] [bp-3Ch]@20
  int a6; // [sp+54h] [bp-38h]@20
  char v10; // [sp+58h] [bp-34h]@1
  int v11; // [sp+5Ch] [bp-30h]@25
  MapTile *loc; // [sp+78h] [bp-14h]@1
  int v13; // [sp+7Ch] [bp-10h]@12
  Hero *v14; // [sp+80h] [bp-Ch]@2
  Castle *v15; // [sp+84h] [bp-8h]@50
  char v16; // [sp+88h] [bp-4h]@1

  thisa = this;
  loc = 0;
  v16 = 0;
  v10 = 0;
  if ( curPlayer->_1[0] == -1 )
    v14 = 0;
  else
    v14 = &gameObject->heroes[curPlayer->_1[0]];
  switch ( *(_DWORD *)(this + 54) + 1 )
  {
    case 2:
      if ( v14 )
      {
        *(_DWORD *)&v14->_4[0] = *(_DWORD *)(this + 494);
        *(_DWORD *)&v14->_4[4] = *(_DWORD *)(this + 498);
        goto LABEL_7;
      }
      break;
    case 8:
LABEL_7:
      if ( v14 )
      {
        if ( *(_DWORD *)&v14->_4[0] != -1 )
        {
          if ( *(_DWORD *)&v14->_4[4] != -1 )
          {
            Pathfinder::doSomething6(pathfinder, v14->x, v14->y, *(_DWORD *)&v14->_4[0], *(_DWORD *)&v14->_4[4], 59999);
            if ( pathfinder->field_8 > 0 )
            {
              v13 = *(_DWORD *)(thisa + 162);
              sub_450820(thisa, 1);
              if ( *(_DWORD *)&showRoute || v13 )
              {
                sub_454B50((void *)thisa, 0, 0, 0);
              }
              else
              {
                if ( *(_DWORD *)(thisa + 162) && *(_DWORD *)(thisa + 54) != 7 )
                  sub_455030((void *)thisa, 1, 0, 1);
              }
              MouseManager::disableCursor(mouseManager);
              InputManager::resetInfoFields(inputManager);
              for ( i = pathfinder->field_8 - 1; i >= 0; --i )
              {
                loc = (MapTile *)sub_4C08F0(
                                   (AdvManager *)thisa,
                                   *((_BYTE *)&pathfinder->field_2418 + i),
                                   (unsigned int)i < 1,
                                   &qword_50EA98,
                                   &qword_50EA98 + 1,
                                   (int)&a6,
                                   0,
                                   (signed int)&a8,
                                   0);
                AdvManager::involvesSettingPointBars((AdvManager *)thisa, -1, 1, 1);
                if ( loc || a6 || a8 || dword_523ECC )
                  break;
                memcpy(&v11, InputManager::nextInputEvent(inputManager, &a2), 0x1Cu);
                while ( v11 )
                {
                  if ( v11 == 1 || v11 == 8 || v11 == 32 || v11 == 512 )
                  {
                    v16 = 1;
                    sub_4BFAC0((AdvManager *)thisa, 1);
                    goto LABEL_34;
                  }
                  passOnMessages();
                  memcpy(&v11, InputManager::nextInputEvent(inputManager, (InputEvent *)&v5), 0x1Cu);
                }
              }
LABEL_34:
              if ( i <= 0 && v14->x == *(_DWORD *)&v14->_4[0] && *(_DWORD *)&v14->_4[4] == v14->y
                || v16 && !*(_DWORD *)&showRoute
                || loc )
              {
                sub_455030((void *)thisa, 1, 1, 1);
              }
              else
              {
                if ( *(_DWORD *)(thisa + 54) == 7 || *(_DWORD *)&showRoute )
                  sub_454B50((void *)thisa, 0, 1, 1);
              }
              while ( mouseManager->cursorDisabled )
                MouseManager::enableCursor(mouseManager);
              SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(thisa + 166)]);
              sub_44D440((void *)thisa, 1, 1, 1);
              if ( loc )
              {
                sub_4BFAC0((AdvManager *)thisa, 1);
                AdvManager::visitLocation((AdvManager *)thisa, loc, *(__int64 *)&qword_50EA98);
                loc = 0;
              }
              sub_4456D0(0, 0);
              v10 = 1;
              sub_455140((void *)thisa);
            }
          }
        }
      }
      break;
    case 7:
      sub_450880((AdvManager *)this);
      MouseManager::setSpriteIdx(mouseManager, 0);
      v15 = &gameObject->castles[*(_WORD *)&v14->_4[14]];
      Castle::visit(v15, 0);
      loc = 0;
      break;
    case 4:
      sub_450880((AdvManager *)this);
      MouseManager::setSpriteIdx(mouseManager, 0);
      loc = (MapTile *)usedToCheckForBoatByCastle(
                         (AdvManager *)thisa,
                         gameObject->castles[LOBYTE(curPlayer->field_45)].field_4,
                         gameObject->castles[LOBYTE(curPlayer->field_45)].field_5);
      Castle::visit(&gameObject->castles[LOBYTE(curPlayer->field_45)], 0);
      loc = 0;
      break;
    case 3:
      if ( v14 )
      {
        MouseManager::setSpriteIdx(mouseManager, 0);
        if ( dword_4F74A8 )
          sub_452F60((void *)thisa, -1, -1, 1);
        sub_456000((void *)thisa, 0);
        sub_497970(curPlayer->_1[0], 0, 0);
        if ( dword_4F74A8 )
          sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
        sub_4506B0((void *)thisa, 1, 0);
        sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
      }
      break;
    case 5:
      v1 = usedToCheckForBoatByCastle(
             (AdvManager *)this,
             *(_DWORD *)(this + 470) + *(_DWORD *)(this + 486),
             *(_DWORD *)(this + 474) + *(_DWORD *)(this + 490));
      sub_450C10((void *)thisa, (unsigned __int8)((unsigned __int8)(*(_WORD *)(v1 + 4) >> 8) >> -5), 0);
      break;
    case 6:
      v2 = usedToCheckForBoatByCastle(
             (AdvManager *)this,
             *(_DWORD *)(this + 470) + *(_DWORD *)(this + 486),
             *(_DWORD *)(this + 474) + *(_DWORD *)(this + 490));
      sub_4509F0((AdvManager *)thisa, (unsigned __int8)((unsigned __int8)(*(_WORD *)(v2 + 4) >> 8) >> -5));
      break;
    case 0:
      break;
  }
  *(_DWORD *)(thisa + 54) = -1;
  *(_DWORD *)(thisa + 490) = -1;
  *(_DWORD *)(thisa + 486) = *(_DWORD *)(thisa + 490);
  if ( v10 )
    sub_455380((void *)thisa);
  return loc;
}
