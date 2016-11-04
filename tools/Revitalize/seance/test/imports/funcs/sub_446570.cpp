{
  int v4; // eax@20
  int v5; // eax@26
  int thisa; // [sp+10h] [bp-8h]@1
  signed int v8; // [sp+14h] [bp-4h]@23

  thisa = this;
  switch ( *(_DWORD *)(a2 + 8) )
  {
    case 0x17:
      if ( (signed int)HIBYTE(curPlayer->field_45) > 0 )
      {
        --HIBYTE(curPlayer->field_45);
        sub_44D170((void *)this, 1, 1);
      }
      break;
    case 0x18:
      if ( HIBYTE(curPlayer->field_45) + 4 < curPlayer->numCastles )
      {
        ++HIBYTE(curPlayer->field_45);
        sub_44D170((void *)this, 1, 1);
      }
      break;
    case 0x14:
      if ( curPlayer->_1[1] > 0 )
      {
        --curPlayer->_1[1];
        AdvManager::heroSelectionGUIStuff((AdvManager *)this, 1, 1);
      }
      break;
    case 0x15:
      if ( curPlayer->_1[1] + 4 < curPlayer->numHeroes )
      {
        ++curPlayer->_1[1];
        AdvManager::heroSelectionGUIStuff((AdvManager *)this, 1, 1);
      }
      break;
    case 2:
      *(_DWORD *)(this + 54) = 7;
      *(_DWORD *)a4 = sub_443E90(this);
      break;
    case 5:
      sub_4571A0((void *)this);
      break;
    case 6:
      *(_DWORD *)a3 = sub_457620((void *)this);
      break;
    case 4:
      if ( !sub_418E10(curPlayer)
        || (display_message_window(
              "One or more heroes may still move, are you sure you want to end your turn?",
              2,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0),
            HeroWindowManager::instance->buttonPressedCode != 30726) )
        GameInfo::endTurn(gameObject);
      break;
    case 1:
      sub_455030((void *)this, 1, 0, 1);
      v4 = sub_418CE0(curPlayer, 1);
      sub_450C10((void *)thisa, v4, 0);
      break;
    case 3:
      if ( dword_4F74A8 )
        sub_452F60((void *)this, -1, -1, 1);
      sub_456000((void *)thisa, 0);
      sub_462580(gameObject);
      v8 = 1;
      if ( dword_524238 == 1 )
      {
        MouseManager::setSpriteIdx(mouseManager, 0);
        if ( dword_4F74A8 )
          sub_452F60((void *)thisa, -1, -1, 1);
        sub_456000((void *)thisa, 0);
        v5 = (int)sub_498B70(&gameObject->heroes[dword_524238]);
        sub_497970(dword_5247B4, v5, 1);
        if ( dword_4F74A8 )
          sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
      }
      else
      {
        if ( dword_524238 == 2 )
        {
          sub_450880((AdvManager *)thisa);
          MouseManager::setSpriteIdx(mouseManager, 0);
          Castle::visit(&gameObject->castles[dword_5247B4], 1);
          v8 = 0;
        }
        else
        {
          if ( dword_4F74A8 )
            sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
        }
      }
      sub_4506B0((void *)thisa, 1, 0);
      if ( v8 )
        sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
      break;
    case 8:
      sub_4519A0(this);
      break;
    case 7:
      sub_457B20((void *)this);
      break;
    default:
      break;
  }
  if ( *(_DWORD *)(a2 + 8) >= 2000 && *(_DWORD *)(a2 + 8) <= 2200 )
  {
    if ( dword_52405C == 2 )
    {
      dword_52405C = 1;
    }
    else
    {
      if ( dword_52405C )
      {
        dword_52405C = 0;
      }
      else
      {
        if ( dword_50EAA0 == 2 )
          dword_52405C = 1;
        else
          dword_52405C = 2;
      }
    }
    dword_524798 = getTickCount() + 3000;
    sub_44D440((void *)thisa, 1, 1, 1);
  }
  return 1;
}
