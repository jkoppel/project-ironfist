{
  int v2; // [sp+10h] [bp-18h]@1
  int v3; // [sp+14h] [bp-14h]@10
  signed int v4; // [sp+18h] [bp-10h]@12
  int thisa; // [sp+20h] [bp-8h]@2
  char v6; // [sp+24h] [bp-4h]@5

  v2 = this;
  if ( curPlayer->_1[0] == -1 )
    thisa = 0;
  else
    thisa = (int)&gameObject->heroes[curPlayer->_1[0]];
  switch ( a2 )
  {
    case 61:
      v6 = 62;
      goto LABEL_10;
    case 62:
      v6 = 63;
      goto LABEL_10;
    case 63:
      v6 = 64;
      goto LABEL_10;
    case 64:
      v6 = 65;
      goto LABEL_10;
    case 60:
      v6 = 59;
LABEL_10:
      v3 = usedToCheckForBoatByCastle(advManager, *(_DWORD *)(thisa + 25), *(_DWORD *)(thisa + 29));
      if ( *(_BYTE *)(v3 + 9) != 151 )
      {
        display_message_window(
          "You must be standing on the entrance to a mine (sawmills and alchemists don't count) to cast this spell.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        return;
      }
      gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v3 + 4) >> 8) >> -5) + 3] = v6;
      v4 = Hero::getPrimarySkill((Hero *)thisa, PRIMARY_SKILL_SPELLPOWER);
      if ( v4 > 51 )
        LOBYTE(v4) = 51;
      gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v3 + 4) >> 8) >> -5) + 4] = 4 * v4;
      if ( a2 == 60 )
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(*(_WORD *)(v3 + 4) >> 8) >> -5), -1);
      goto LABEL_32;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
      sub_498F20((void *)this, a2, a2 == 53, a2 == 53);
      goto LABEL_32;
    case 54:
      *(_DWORD *)(this + 886) = 1;
      display_message_window("Enemy heroes are now fully identifiable.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      goto LABEL_32;
    case 55:
      sub_4545A0(this);
      goto LABEL_32;
    case 56:
    case 57:
    case 58:
      if ( *(_DWORD *)(thisa + 53) )
      {
        if ( *(_DWORD *)(thisa + 53) >= 225 )
          *(_DWORD *)(thisa + 53) -= 225;
        else
          *(_DWORD *)(thisa + 53) = 0;
        AdvManager::involvesSettingPointBars((AdvManager *)this, -1, 1, 1);
        if ( a2 == 56 )
          sub_453E30((void *)v2);
        else
          sub_454160((void *)v2, a2);
LABEL_32:
        if ( a2 != 56 && a2 != 57 )
        {
          if ( a2 != 58 )
            Hero::spendSpellPointsFor(&gameObject->heroes[curPlayer->_1[0]], a2);
        }
      }
      else
      {
        display_message_window(
          "Your hero is too tired to cast this spell today.  Try again tomorrow.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      return;
    case 59:
      if ( sub_4587A0((void *)this, thisa) )
        goto LABEL_32;
      return;
    default:
      goto LABEL_32;
  }
}
