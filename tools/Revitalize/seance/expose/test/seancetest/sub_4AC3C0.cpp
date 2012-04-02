MouseManager *__thiscall sub_4AC3C0(void *this, int a2)
{
  char *v2; // eax@8
  MouseManager *result; // eax@124
  int v4; // [sp+0h] [bp-A0h]@0
  int v5; // [sp+4h] [bp-9Ch]@0
  int v6; // [sp+8h] [bp-98h]@0
  int v7; // [sp+Ch] [bp-94h]@26
  int v8; // [sp+10h] [bp-90h]@26
  int v9; // [sp+14h] [bp-8Ch]@26
  int v10; // [sp+18h] [bp-88h]@26
  void *v11; // [sp+1Ch] [bp-84h]@1
  int v12; // [sp+20h] [bp-80h]@0
  int v13; // [sp+24h] [bp-7Ch]@0
  int v14; // [sp+28h] [bp-78h]@0
  int v15; // [sp+2Ch] [bp-74h]@0
  int v16; // [sp+30h] [bp-70h]@0
  int v17; // [sp+34h] [bp-6Ch]@0
  int v18; // [sp+38h] [bp-68h]@0
  int v19; // [sp+3Ch] [bp-64h]@0
  signed int a8; // [sp+40h] [bp-60h]@68
  int a6; // [sp+44h] [bp-5Ch]@68
  int v22; // [sp+48h] [bp-58h]@36
  int v23; // [sp+4Ch] [bp-54h]@35
  int a2a; // [sp+50h] [bp-50h]@40
  int v25; // [sp+54h] [bp-4Ch]@35
  int v26; // [sp+58h] [bp-48h]@35
  int v27; // [sp+5Ch] [bp-44h]@80
  int v28; // [sp+60h] [bp-40h]@114
  int v29; // [sp+64h] [bp-3Ch]@114
  int v30; // [sp+68h] [bp-38h]@61
  int i; // [sp+6Ch] [bp-34h]@6
  int v32; // [sp+70h] [bp-30h]@40
  void *v33; // [sp+74h] [bp-2Ch]@1
  int v34; // [sp+78h] [bp-28h]@1
  int v35; // [sp+7Ch] [bp-24h]@24
  char *v36; // [sp+80h] [bp-20h]@13
  int v37; // [sp+84h] [bp-1Ch]@23
  int v38; // [sp+88h] [bp-18h]@26
  int a5; // [sp+8Ch] [bp-14h]@81
  int a4; // [sp+90h] [bp-10h]@81
  int v41; // [sp+94h] [bp-Ch]@1
  char v42; // [sp+98h] [bp-8h]@76
  signed int a3; // [sp+9Ch] [bp-4h]@68

  v11 = this;
  v34 = 0;
  v41 = 0;
  v33 = 0;
  logUpTo7Ints((int)"DO AI 1", a2, -999, -999, -999, -999, -999, -999);
  yieldToGlobalUpdater();
  if ( !dword_4EF268 && (!dword_524794 || dword_524794 == a2) )
  {
    logUpTo7Ints((int)"DO AI", a2, -999, -999, -999, -999, -999, -999);
    sub_4B8A90();
    sub_4AD0C0(a2);
    if ( gameObject->day == 1 || gameObject->day == 1 )
    {
      for ( i = 0; curPlayer->numHeroes > i; ++i )
      {
        v2 = (char *)gameObject + 250 * curPlayer->heroesOwned[i];
        v12 = (int)(v2 + 10180);
        *(_WORD *)(v2 + 10187) = -99;
      }
    }
    unknown_libname_21();
    sub_4AC280();
    for ( i = 0; i < 7; ++i )
    {
      sprintf(
        globBuf,
        "RES - %15s  %d  %d",
        resourceNames[i],
        curPlayer->resources[i],
        *(_DWORD *)&curPlayer->_4[4 * i + 60]);
      debugLog(globBuf);
    }
    sub_4AADD0(v11);
    sub_4B6490();
    while ( 1 )
    {
      v36 = sub_4AE470(a2);
      if ( !v36 )
        break;
      sub_4AC340(v36);
      dword_51D5BC = (Hero *)v36;
      if ( (unsigned __int8)v36[41] == 255 || dword_51D5BC->_4[10] )
      {
        dword_5306DC = ArmyInfo::computeMorale(&dword_51D5BC->army, dword_51D5BC, 0, 0);
        dword_5306D4 = computeLuck(dword_51D5BC, 0, 0);
        ArmyInfo::computeMorale(&dword_51D5BC->army, dword_51D5BC, 0, 0);
        dword_5305C4 = -1;
        dword_532CE0 = 0;
        if ( dword_4EF268 )
          break;
        debugLog("\n\n\n\n");
        debugLog("===================================");
        logUpTo7Ints((int)"Player with HeroTOMOVE", a2, -999, -999, -999, -999, -999, -999);
        debugLog(dword_51D5BC->name);
        debugLog(L"\n");
        sub_4AB580();
        sub_4AB9B0();
        dword_51D598 = 0;
        if ( *(_DWORD *)&blackoutComputer || dword_4F7494 || !sub_456B40(dword_51D5BC->x, dword_51D5BC->y, byte_5306F0) )
        {
          dword_524C14 = 0;
          sub_450C10(advManager, dword_51D5BC->field_2, 0);
        }
        else
        {
          dword_524C14 = 1;
          sub_450C10(advManager, dword_51D5BC->field_2, 0);
        }
        v37 = 0;
        sub_4AA5F0(0, 0, 0);
        if ( dword_51D5BC->flags1 & 0x80 )
          v35 = 15;
        else
          v35 = 5;
        v38 = *(_DWORD *)&dword_51D5BC->_4[16] + 800;
        v10 = gameObject->difficulty;
        v9 = v35;
        v35 = (signed __int64)((1.7 - (double)v10 * 0.1) * (double)v35);
        v8 = gameObject->difficulty - 1;
        v7 = v38;
        v38 = (signed __int64)(((double)v8 * 0.06 + 0.8) * (double)v38);
LABEL_27:
        if ( v37 || *(_DWORD *)&dword_51D5BC->_4[20] < 75 )
        {
          *(_DWORD *)&dword_51D5BC->_4[20] = 0;
          sub_4507F0((int)advManager);
        }
        else
        {
          if ( dword_4EF268 )
            break;
          if ( *(_DWORD *)&dword_51D5BC->_4[20] == *(_DWORD *)&dword_51D5BC->_4[16]
            && curPlayer->field_40 > 15
            && LOBYTE(curPlayer->field_41) == dword_51D5BC->x
            && HIBYTE(curPlayer->field_41) == dword_51D5BC->y )
            sub_4469E0(advManager, *(_QWORD *)&dword_51D5BC->x);
          do
          {
            do
            {
              v25 = sub_4AE590(v11, (int *)dword_51D5BC->_4, (int *)&dword_51D5BC->_4[4], v38, (int)&v26);
              v23 = sub_419C90(gameObject, dword_51D5BC->x, dword_51D5BC->y);
              if ( v23 != -1 )
              {
                v22 = (int)&gameObject->castles[v23];
                if ( gameObject->castles[v23].alignment )
                {
                  if ( (*(_BYTE *)(usedToCheckForBoatByCastle(
                                     advManager,
                                     *(_DWORD *)&dword_51D5BC->_4[0],
                                     *(_DWORD *)&dword_51D5BC->_4[4])
                                 + 9) & 0x7F) != 42 )
                    *(_DWORD *)&dword_51D5BC->_4[20] = 0;
                }
              }
              if ( v26 != -1 )
              {
                a2a = v26;
                v32 = 99;
                goto LABEL_79;
              }
            }
            while ( v25 < 1000 && v26 == -1 && sub_4ABD20(v25) );
            if ( v25 < 75 && gameObject->day == 7 && *(_WORD *)&dword_51D5BC->_4[12] == 163 )
              *(_DWORD *)&dword_51D5BC->_4[20] = 0;
            for ( i = 0; dword_532CE0 > i; ++i )
            {
              if ( dword_5305D8[2 * i] == *(_DWORD *)&dword_51D5BC->_4[0]
                && dword_5305DC[2 * i] == *(_DWORD *)&dword_51D5BC->_4[4]
                && *(_BYTE *)(usedToCheckForBoatByCastle(
                                advManager,
                                *(_DWORD *)&dword_51D5BC->_4[0],
                                *(_DWORD *)&dword_51D5BC->_4[4])
                            + 9) != 163 )
                *(_DWORD *)&dword_51D5BC->_4[20] = 0;
            }
            if ( dword_532CE0 < 30 )
            {
              dword_5305D8[2 * dword_532CE0] = dword_51D5BC->x;
              dword_5305DC[2 * dword_532CE0++] = dword_51D5BC->y;
            }
            dword_51D598 = 1;
            if ( *(_DWORD *)&dword_51D5BC->_4[20] == *(_DWORD *)&dword_51D5BC->_4[16] )
            {
              v41 = 0;
              sub_4B6490();
            }
            if ( *(_DWORD *)&dword_51D5BC->_4[0] == -1 || *(_DWORD *)&dword_51D5BC->_4[4] == -1 )
            {
              v37 = 1;
              goto LABEL_27;
            }
            v30 = 0;
            sub_450C10(advManager, dword_51D5BC->field_2, 0);
            Pathfinder::doSomething6(
              pathfinder,
              dword_51D5BC->x,
              dword_51D5BC->y,
              *(_DWORD *)&dword_51D5BC->_4[0],
              *(_DWORD *)&dword_51D5BC->_4[4],
              *(_DWORD *)&dword_51D5BC->_4[20]);
            if ( !pathfinder->field_8 )
            {
              v37 = 1;
              goto LABEL_113;
            }
            if ( pathfinder->field_8 <= 0 )
            {
              v37 = 1;
              goto LABEL_113;
            }
            sub_447A00(advManager, 0, 0);
          }
          while ( v25 > 1000
               && Hero::hasSpell(dword_51D5BC, SPELL_DIMENSION_DOOR)
               && dword_51D5BC->spellpoints >= 30
               && sub_4AC120((int)dword_51D5BC) );
          v32 = 0;
          i = pathfinder->field_8 - 1;
          a6 = 0;
          a8 = 0;
          a3 = 1;
          while ( i >= 0 && v32 < v35 )
          {
            a3 = v32 + 1 == v35 || !i;
            if ( i > 0 )
            {
              a6 = 0;
              a8 = 0;
              if ( sub_4AB290((int)&v42) )
              {
                *((_BYTE *)&pathfinder->field_2418 + i) = v42;
                a3 = 1;
              }
            }
            a2a = *((_BYTE *)&pathfinder->field_2418 + i);
LABEL_79:
            if ( sub_4C0840((int)dword_51D5BC, a2a) )
            {
              v27 = dword_524C14;
              dword_524C14 = 1;
              MouseManager::disableCursor(mouseManager);
              ++v34;
              dword_524C14 = v27;
            }
            v30 = sub_4C08F0(advManager, a2a, a3, &a4, &a5, (int)&a6, 1, (signed int)&a8, 0);
            ++v32;
            if ( v30 || a6 || a8 )
              break;
            --i;
          }
          if ( dword_51D5BC->probablyOwnerIdx != curPlayerIdx )
          {
            if ( !v33 )
            {
              v33 = (void *)1;
              sub_4AADD0(v11);
            }
            goto LABEL_120;
          }
          if ( *(_DWORD *)&dword_51D5BC->_4[16] >> 1 >= *(_DWORD *)&dword_51D5BC->_4[20] && !v41 )
          {
            v41 = 1;
            sub_4B6490();
          }
          if ( i < 0
            && curPlayer->field_40 > 15
            && LOBYTE(curPlayer->field_41) == dword_51D5BC->x
            && HIBYTE(curPlayer->field_41) == dword_51D5BC->y )
          {
            if ( *(_DWORD *)&dword_51D5BC->_4[20] == *(_DWORD *)&dword_51D5BC->_4[16] )
              sub_4469E0(advManager, -1i64);
            else
              *(_DWORD *)&dword_51D5BC->_4[20] = 0;
          }
          if ( i < 0
            && ((dword_51D5BC->x != *(_DWORD *)&dword_51D5BC->_4[0] || *(_DWORD *)&dword_51D5BC->_4[4] != dword_51D5BC->y)
             && !v30
             || *(_DWORD *)&dword_51D5BC->_4[20] < 75
             || a6 && !v30) )
            v37 = 1;
          v27 = dword_524C14;
          dword_524C14 = 1;
          while ( v34 )
          {
            MouseManager::enableCursor(mouseManager);
            --v34;
          }
          dword_524C14 = v27;
          sub_44AA80((int)advManager, 1, 0);
LABEL_113:
          if ( !v30 )
            goto LABEL_27;
          sub_48F940(
            (int)advManager,
            v30,
            (int)dword_51D5BC,
            __PAIR__(a5, a4),
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            (int)v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            a8,
            a6,
            v22,
            v23,
            a2a,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            i,
            v32,
            v33,
            v34,
            v35);
          if ( curPlayer->_1[0] != -1 )
          {
            sub_4AC340(dword_51D5BC);
            sub_4AA5F0(1, *(_DWORD *)&dword_51D5BC->_4[0], *(_DWORD *)&dword_51D5BC->_4[4]);
            goto LABEL_27;
          }
        }
LABEL_120:
        if ( *(_WORD *)&dword_51D5BC->_4[12] == 163 )
          sub_4AADD0(v11);
      }
      else
      {
        *(_DWORD *)&dword_51D5BC->_4[20] = 0;
      }
    }
  }
  GameInfo::fixSeveralInvariants(gameObject);
  dword_51D5BC = 0;
  sub_4B8B90();
  while ( 1 )
  {
    result = mouseManager;
    if ( !mouseManager->cursorDisabled )
      break;
    MouseManager::enableCursor(mouseManager);
  }
  return result;
}
