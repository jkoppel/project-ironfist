{
  int thisa; // [sp+28h] [bp-9Ch]@1
  char v5; // [sp+2Ch] [bp-98h]@120
  InputEvent a2a; // [sp+48h] [bp-7Ch]@115
  bool v7; // [sp+64h] [bp-60h]@67
  Hero *v8; // [sp+68h] [bp-5Ch]@67
  int v9; // [sp+6Ch] [bp-58h]@113
  float v10; // [sp+88h] [bp-3Ch]@98
  int v11; // [sp+8Ch] [bp-38h]@115
  int v12; // [sp+90h] [bp-34h]@122
  int v13; // [sp+94h] [bp-30h]@126
  int v14; // [sp+A8h] [bp-1Ch]@31
  int v15; // [sp+ACh] [bp-18h]@1
  int v16; // [sp+B0h] [bp-14h]@3
  int v17; // [sp+B4h] [bp-10h]@1
  int v18; // [sp+B8h] [bp-Ch]@38
  int v19; // [sp+BCh] [bp-8h]@1
  int v20; // [sp+C0h] [bp-4h]@2

  thisa = this;
  v15 = 1;
  v19 = *(_DWORD *)(a2 + 16);
  v17 = *(_DWORD *)(a2 + 20);
  switch ( *(_DWORD *)(a2 + 8) )
  {
    case 0x69:
    case 0x70:
    case 0x77:
    case 0x7E:
      v20 = (*(_DWORD *)(a2 + 8) - 105) / 7;
      if ( curPlayer->numHeroes > v20 )
      {
        v16 = *(&curPlayer->heroesOwned[v20] + curPlayer->_1[1]);
        if ( *(_BYTE *)(a2 + 13) & 2 )
        {
          sub_44EC40((void *)this, v16, v20, -1, -1);
        }
        else
        {
          if ( curPlayer->_1[0] == v16 )
          {
            *(_DWORD *)(this + 54) = 2;
            sub_443E90(this);
          }
          else
          {
            sub_455030((void *)this, 1, 0, 1);
            sub_450C10((void *)thisa, v16, 0);
          }
        }
      }
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      v16 = *(&curPlayer->_3[*(_DWORD *)(a2 + 8) + 36] + HIBYTE(curPlayer->field_45));
      if ( *(_BYTE *)(a2 + 13) & 2 )
      {
        sub_44FA80((void *)this, v16, *(_DWORD *)(a2 + 8) - 16, -1, -1);
      }
      else
      {
        sub_455030((void *)this, 1, 0, 1);
        if ( LOBYTE(curPlayer->field_45) == v16 )
        {
          *(_DWORD *)(thisa + 54) = 3;
          *(_DWORD *)a3 = sub_443E90(thisa);
        }
        else
        {
          sub_4509F0((AdvManager *)thisa, v16);
        }
      }
      break;
    case 0x1A:
      sub_450FB0((void *)this);
      break;
    case 0x16:
      v17 -= 194;
      if ( curPlayer->numHeroes <= 4 )
      {
        v20 = 0;
      }
      else
      {
        v20 = v17 / 92 / (curPlayer->numHeroes - 3);
        if ( curPlayer->numHeroes - 4 < v20 )
          v20 = curPlayer->numHeroes - 4;
      }
      curPlayer->_1[1] = v20;
      AdvManager::heroSelectionGUIStuff((AdvManager *)this, 1, 1);
      break;
    case 0x1B:
      sub_4511B0((void *)this);
      break;
    case 0x19:
      v17 -= 194;
      if ( curPlayer->numCastles <= 4 )
      {
        v20 = 0;
      }
      else
      {
        v20 = v17 / 92 / (curPlayer->numCastles - 3);
        if ( curPlayer->numCastles - 4 < v20 )
          v20 = curPlayer->numCastles - 4;
      }
      HIBYTE(curPlayer->field_45) = v20;
      sub_44D170((void *)this, 1, 1);
      break;
    case 0xA:
      if ( !(unsigned __int8)(*(&tileExplored[*(_DWORD *)(this + 470)]
                              + *(_DWORD *)(this + 486)
                              + mapWidth * (*(_DWORD *)(this + 474) + *(_DWORD *)(this + 490))) & byte_532C5C) )
        v15 = 0;
      v14 = usedToCheckForBoatByCastle(
              (AdvManager *)this,
              *(_DWORD *)(this + 470) + *(_DWORD *)(this + 486),
              *(_DWORD *)(this + 474) + *(_DWORD *)(this + 490));
      if ( *(_BYTE *)(a2 + 13) & 2 )
      {
        if ( v15 )
        {
          if ( *(_DWORD *)(thisa + 486) == 7
            && *(_DWORD *)(thisa + 490) == 7
            && curPlayer->_1[0] != -1
            && *(_DWORD *)(thisa + 678) )
          {
            v16 = 42;
            v18 = curPlayer->_1[0];
          }
          else
          {
            v16 = *(_BYTE *)(v14 + 9) & 0x7F;
            v18 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v14 + 4) >> 8) >> -5);
          }
          if ( v16 == 35 )
          {
            v19 = 32 * *(_DWORD *)(thisa + 486) - 89;
            if ( v19 < 30 )
              v19 = 30;
            if ( v19 + 224 > 448 )
              v19 = 224;
            v17 = 32 * *(_DWORD *)(thisa + 490) - 70;
            if ( v17 < 16 )
              v17 = 16;
            if ( v17 + 186 > 464 )
              v17 = 278;
            sub_44FA80((void *)thisa, v18, -1, v19, v17);
          }
          else
          {
            if ( v16 == 42 )
            {
              v19 = 32 * *(_DWORD *)(thisa + 486) - 73;
              if ( v19 < 30 )
                v19 = 30;
              if ( v19 + 192 > 448 )
                v19 = 256;
              v17 = 32 * *(_DWORD *)(thisa + 490) - 72;
              if ( v17 < 16 )
                v17 = 16;
              if ( v17 + 190 > 464 )
                v17 = 274;
              sub_44EC40((void *)thisa, v18, -1, v19, v17);
            }
            else
            {
              if ( *(&tileExplored[*(_DWORD *)(thisa + 470)]
                   + *(_DWORD *)(thisa + 486)
                   + mapWidth * (*(_DWORD *)(thisa + 474) + *(_DWORD *)(thisa + 490))) & (unsigned __int8)byte_532C5C )
                RightClickMenu((void *)thisa, *(_DWORD *)(thisa + 486), *(_DWORD *)(thisa + 490));
            }
          }
        }
        else
        {
          RightClickMenu((void *)thisa, *(_DWORD *)(thisa + 486), *(_DWORD *)(thisa + 490));
        }
      }
      else
      {
        if ( v15 )
        {
          v8 = 0;
          v7 = 0;
          if ( curPlayer->_1[0] != -1 )
          {
            v8 = &gameObject->heroes[curPlayer->_1[0]];
            v7 = sub_419790(gameObject, v8->field_2);
          }
          if ( v8 )
          {
            if ( *(_DWORD *)(thisa + 486) == 7
              && *(_DWORD *)(thisa + 490) == 7
              && curPlayer->_1[0] != -1
              && *(_DWORD *)(thisa + 678) )
            {
              *(_DWORD *)(thisa + 54) = 2;
              sub_443E90(thisa);
            }
            else
            {
              if ( (!v7
                 || *(_BYTE *)(a2 + 12) & 0xC
                 || *(_DWORD *)&showRoute
                 && (*(_DWORD *)&v8->_4[0] != *(_DWORD *)(thisa + 494)
                  || *(_DWORD *)&v8->_4[4] != *(_DWORD *)(thisa + 498)))
                && *(&pathfinder->field_2414[mapWidth * *(_DWORD *)(thisa + 498)].field_4 + 9 * *(_DWORD *)(thisa + 494)) & 1 )
              {
                *(_DWORD *)&v8->_4[0] = *(_DWORD *)(thisa + 494);
                *(_DWORD *)&v8->_4[4] = *(_DWORD *)(thisa + 498);
                sub_454B50((void *)thisa, 1, 1, 1);
              }
              else
              {
                *(_DWORD *)a3 = sub_443E90(thisa);
              }
            }
          }
          else
          {
            v16 = *(_BYTE *)(v14 + 9) & 0x7F;
            v18 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v14 + 4) >> 8) >> -5);
            if ( v16 == 42 )
            {
              if ( curPlayer->_1[0] == v18 )
              {
                *(_DWORD *)(thisa + 54) = 2;
                sub_443E90(thisa);
              }
              else
              {
                if ( gameObject->heroes[v18].probablyOwnerIdx == curPlayerIdx )
                  sub_450C10((void *)thisa, v18, 0);
              }
            }
            if ( v16 == 35 )
            {
              if ( LOBYTE(curPlayer->field_45) == v18 )
              {
                *(_DWORD *)(thisa + 54) = 3;
                *(_DWORD *)a3 = sub_443E90(thisa);
              }
              else
              {
                if ( gameObject->castles[v18].ownerIdx == curPlayerIdx )
                  sub_4509F0((AdvManager *)thisa, v18);
              }
            }
          }
        }
      }
      break;
    case 9:
      if ( *(_BYTE *)(a2 + 13) & 2 )
      {
        display_message_window(
          "{World Map}\n\nA miniature view of the known world.  Left click to move viewing area.",
          4,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      else
      {
        sub_450880((AdvManager *)this);
        switch ( mapHeight )
        {
          case 36:
            v10 = 4.0;
            break;
          case 72:
            v10 = 2.0;
            break;
          case 108:
            v10 = 1.3333;
            break;
          default:
            v10 = 1.0;
            break;
        }
        v19 = (signed __int64)((double)(v19 - 480) / v10);
        v17 = (signed __int64)((double)(v17 - 16) / v10);
        *(_DWORD *)(thisa + 470) = v19 - 7;
        *(_DWORD *)(thisa + 474) = v17 - 7;
        if ( *(_DWORD *)(thisa + 470) < -7 )
          *(_DWORD *)(thisa + 470) = -7;
        if ( *(_DWORD *)(thisa + 474) < -7 )
          *(_DWORD *)(thisa + 474) = -7;
        if ( mapWidth - 8 < *(_DWORD *)(thisa + 470) )
          *(_DWORD *)(thisa + 470) = mapWidth - 8;
        if ( mapHeight - 8 < *(_DWORD *)(thisa + 474) )
          *(_DWORD *)(thisa + 474) = mapHeight - 8;
        sub_44AA80(thisa, 1, 0);
        sub_448110((AdvManager *)thisa, 0);
        sub_447A00((void *)thisa, 0, 0);
        v9 = 0;
        while ( v9 != 16 )
        {
          passOnMessages();
          memcpy(&v9, InputManager::nextInputEvent(inputManager, &a2a), 0x1Cu);
          memcpy(&v11, &v9, 0x1Cu);
          while ( v9 != 16 && v9 )
          {
            if ( v9 == 4 )
              memcpy(&v11, &v9, 0x1Cu);
            passOnMessages();
            memcpy(&v9, InputManager::nextInputEvent(inputManager, (InputEvent *)&v5), 0x1Cu);
          }
          if ( v11 == 4 )
          {
            if ( v12 < 480 )
              v12 = 480;
            if ( v12 >= 624 )
              v12 = 623;
            if ( v13 < 16 )
              v13 = 16;
            if ( v13 >= 160 )
              v13 = 159;
            (*(void (__thiscall **)(MouseManager *))(LODWORD(mouseManager->vtable) + 8))(mouseManager);
            v19 = (signed __int64)((double)(v12 - 480) / v10);
            v17 = (signed __int64)((double)(v13 - 16) / v10);
            *(_DWORD *)(thisa + 470) = v19 - 7;
            *(_DWORD *)(thisa + 474) = v17 - 7;
            if ( *(_DWORD *)(thisa + 470) < -7 )
              *(_DWORD *)(thisa + 470) = -7;
            if ( *(_DWORD *)(thisa + 474) < -7 )
              *(_DWORD *)(thisa + 474) = -7;
            if ( mapWidth - 8 < *(_DWORD *)(thisa + 470) )
              *(_DWORD *)(thisa + 470) = mapWidth - 8;
            if ( mapHeight - 8 < *(_DWORD *)(thisa + 474) )
              *(_DWORD *)(thisa + 474) = mapHeight - 8;
            sub_44AA80(thisa, 1, 0);
            sub_448110((AdvManager *)thisa, 0);
            sub_447A00((void *)thisa, 0, 0);
            v11 = 0;
          }
        }
      }
      break;
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x14:
    case 0x15:
    case 0x17:
    case 0x18:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7D:
      break;
  }
  if ( *(_BYTE *)(a2 + 13) & 2 && *(_DWORD *)(a2 + 8) >= 2000 && *(_DWORD *)(a2 + 8) <= 2200 )
    display_message_window(
      "{Status Window}\n\nThis window provides information on the status of your hero or kingdom, and shows the date.  Left click here to cycle through these windows.",
      4,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
  return 1;
}
