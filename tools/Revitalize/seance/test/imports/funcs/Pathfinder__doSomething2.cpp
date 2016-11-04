{
  Pathfinder *thisa; // esi@1
  int v13; // eax@4
  char v14; // al@13
  PathfindingInfo *v15; // edx@17
  signed int v16; // ebp@20
  int v17; // eax@23
  char *v18; // eax@23
  int v19; // edx@23
  int v20; // eax@32
  int v21; // eax@39
  __int64 v22; // ST18_8@53
  __int64 v23; // ST18_8@55
  int v24; // ecx@55
  int v25; // ecx@57
  int v26; // ecx@57
  char v27; // al@60
  char v28; // ST2C_1@66
  char v29; // ST28_1@66
  int v30; // ST24_4@66
  char v31; // ST20_1@66
  char v32; // ST1C_1@66
  int v33; // ST18_4@66
  char v34; // ST14_1@66
  int v35; // eax@66
  int v36; // eax@66
  int v37; // ST2C_4@69
  int v38; // eax@69
  int v39; // eax@69
  int v40; // eax@80
  int v41; // ecx@90
  signed int v42; // eax@92
  int v43; // edx@92
  int v44; // eax@92

  thisa = this;
  if ( !a11 )
  {
    dword_524808 = 0;
    dword_524760 = a8;
    sub_464C80(this);
    *(_DWORD *)&thisa->_1[4] = -1;
    *(_DWORD *)&thisa->_1[0] = -1;
    dword_526C80 = 0;
  }
  dword_5247C0 = 1;
  if ( (signed int)a10 < 0 )
  {
    dword_526C28 = 0;
  }
  else
  {
    v13 = a10 + HIDWORD(a10) * mapWidth;
    if ( !((unsigned __int8)byte_532C5C & tileExplored[v13]) )
      return v13;
    v13 = usedToCheckForBoatByCastle(advManager, a10, SHIDWORD(a10));
    dword_526C70 = v13;
    if ( *(_BYTE *)(v13 + 8) & 8 )
      return v13;
    if ( !tileToTerrainType[*(_WORD *)v13] )
    {
      LOBYTE(v13) = dword_526C70;
      if ( a6 )
      {
        if ( *(_BYTE *)(dword_526C70 + 9) == -85 )
          return v13;
      }
      else
      {
        LOBYTE(v13) = *(_BYTE *)(dword_526C70 + 9);
        if ( (_BYTE)v13 != -86 && (_BYTE)v13 != -85 && (_BYTE)v13 != -96 )
          return v13;
      }
    }
    dword_526C28 = 1;
    v14 = *(_BYTE *)(dword_526C70 + 2);
    dword_526CA8 = 999999;
    dword_526C44 = (unsigned __int8)(v14 & 2) >> 1;
  }
  if ( dword_526C28 )
  {
    if ( !a11 )
      goto LABEL_20;
    v15 = &thisa->field_2414[a10 + HIDWORD(a10) * mapWidth];
    *(_DWORD *)&byte_526C58 = *(_DWORD *)&v15->field_0;
    *((_DWORD *)&byte_526C58 + 1) = *(_DWORD *)&v15->field_4;
    *(&byte_526C58 + 8) = BYTE3(v15->field_5);
    if ( byte_526C5C & 1 )
    {
      LOBYTE(v13) = dword_526C80 + 75;
      if ( dword_526C80 + 75 >= (unsigned __int16)word_526C5A )
        return v13;
    }
  }
  if ( a11 )
  {
    v16 = a5;
    goto LABEL_22;
  }
LABEL_20:
  v16 = a5;
  Pathfinder::doSomething4(thisa, a2, a3, a4, 0, a5, 0, 0, 0, 0, 0, 0, 0);
LABEL_22:
  dword_526CB4 = (int)&gameObject->heroes[curPlayer->_1[0]];
  while ( thisa->field_0 )
  {
    v17 = thisa->field_0 - 1;
    thisa->field_0 = v17;
    v18 = (char *)thisa + 9 * v17;
    v19 = *((_DWORD *)v18 + 5);
    v18 += 20;
    *(_DWORD *)&byte_526C58 = v19;
    *((_DWORD *)&byte_526C58 + 1) = *((_DWORD *)v18 + 1);
    *(&byte_526C58 + 8) = v18[8];
    if ( dword_526C28 && dword_526CA8 < 999999 && (unsigned __int16)word_526C5A + 75 >= dword_526CA8 )
    {
      v13 = (unsigned __int16)word_526C5A;
      dword_526C80 = (unsigned __int16)word_526C5A;
      ++thisa->field_0;
      return v13;
    }
    if ( (unsigned __int16)word_526C5A <= v16 || v16 <= 0 )
    {
      if ( byte_526C5C & 4 )
      {
        dword_526C2C = 1;
        *(_DWORD *)dword_526C94 = (unsigned __int8)byte_526C5D;
        *(_DWORD *)dword_526CAC = (unsigned __int8)byte_526C5E;
      }
      else
      {
        dword_526C2C = 0;
      }
      if ( byte_526C5C & 2 )
      {
        v20 = *(_BYTE *)(usedToCheckForBoatByCastle(
                           advManager,
                           (unsigned __int8)byte_526C58,
                           (unsigned __int8)byte_526C59)
                       + 9) & 0x7F;
        dword_526C90 = v20;
        if ( v20 == 24 || v20 == 42 || v20 == 43 )
        {
          if ( !a7 )
            goto LABEL_72;
          if ( byte_526C5C & 4 )
            goto LABEL_72;
          *(_DWORD *)dword_526C94 = (unsigned __int8)byte_526C58;
          *(_DWORD *)dword_526CAC = (unsigned __int8)byte_526C59;
          dword_526C2C = 1;
          if ( dword_526C90 == 42 )
          {
            if ( gameObject->relatedToHeroForHireStatus[(unsigned __int16)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                        advManager,
                                                                                        (unsigned __int8)byte_526C58,
                                                                                        (unsigned __int8)byte_526C59)
                                                                                    + 4) >> 3)] == curPlayerIdx )
              goto LABEL_72;
          }
        }
        else
        {
          if ( v20 == 36 )
            goto LABEL_72;
          if ( v20 == 39 )
            goto LABEL_72;
          if ( !a7 )
            goto LABEL_72;
          if ( byte_526C5C & 4 )
            goto LABEL_72;
          v21 = usedToCheckForBoatByCastle(advManager, (unsigned __int8)byte_526C58, (unsigned __int8)byte_526C59);
          if ( sub_458D40(v21) )
            goto LABEL_72;
        }
      }
      if ( a6 )
      {
        dword_526C90 = *(_BYTE *)(usedToCheckForBoatByCastle(
                                    advManager,
                                    (unsigned __int8)byte_526C58,
                                    (unsigned __int8)byte_526C59)
                                + 9);
        if ( dword_526C90 != 28 )
          goto LABEL_55;
      }
      else
      {
        if ( !(*(&tileExplored[(unsigned __int8)byte_526C59 * mapWidth] + (unsigned __int8)byte_526C58) & 0x80)
          || a2 == (unsigned __int8)byte_526C58 && a3 == (unsigned __int8)byte_526C59 )
          goto LABEL_55;
        if ( a7 && !(byte_526C5C & 4) )
        {
          HIDWORD(v22) = (unsigned __int8)byte_526C59;
          LODWORD(v22) = (unsigned __int8)byte_526C58;
          if ( sub_456630(advManager, v22, (int)dword_526C94, (int)dword_526CAC, -1, -1) )
            dword_526C2C = 1;
LABEL_55:
          HIDWORD(v23) = (unsigned __int8)byte_526C59;
          LODWORD(v23) = (unsigned __int8)byte_526C58;
          Pathfinder::doSomething3(thisa, v23, (int)byte_526C30, (int)byte_526C78, 1, a6);
          dword_526CB0 = (unsigned __int8)tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(
                                                                        advManager,
                                                                        (unsigned __int8)byte_526C58,
                                                                        (unsigned __int8)byte_526C59)];
          v24 = (unsigned __int8)(*(_BYTE *)(usedToCheckForBoatByCastle(
                                               advManager,
                                               (unsigned __int8)byte_526C58,
                                               (unsigned __int8)byte_526C59)
                                           + 2) & 2) >> 1;
          dword_526C9C = 0;
          dword_526C4C = v24;
          dword_526C3C = dword_524760 - (unsigned __int16)word_526C5A;
          do
          {
            if ( byte_526C30[dword_526C9C] != -1 )
            {
              v25 = byte_4F1DC1[4 * dword_526C9C];
              dword_526C38 = (unsigned __int8)byte_526C58 + byte_4F1DC0[4 * dword_526C9C];
              dword_526C6C = (unsigned __int8)byte_526C59 + v25;
              v26 = dword_526C38 + dword_526C6C * mapWidth;
              dword_526CA4 = (int)&thisa->field_2414[v26];
              if ( !a7
                || byte_526C5C & 4
                || !(tileExplored[v26] & 0x80)
                || (v27 = *(_BYTE *)(dword_526CA4 + 4), !(v27 & 1))
                || !(v27 & 4)
                || *(_WORD *)(dword_526CA4 + 2) >= (unsigned __int16)word_526C5A + 300
                || !sub_456630(
                      advManager,
                      __PAIR__(dword_526C6C, dword_526C38),
                      (int)dword_526C94,
                      (int)dword_526CAC,
                      -1,
                      -1)
                || *(_BYTE *)(dword_526CA4 + 5) != *(_DWORD *)dword_526C94
                || *(_BYTE *)(dword_526CA4 + 6) != *(_DWORD *)dword_526CAC )
              {
                v28 = byte_526C60;
                v29 = byte_526C5F;
                v30 = (unsigned __int8)(byte_526C5C & 8) >> 3;
                v31 = dword_526CAC[0];
                v32 = dword_526C94[0];
                v33 = dword_526C2C;
                v34 = byte_526C78[dword_526C9C];
                v35 = usedToCheckForBoatByCastle(advManager, dword_526C38, dword_526C6C);
                v36 = sub_464D00(
                        dword_526CB0,
                        dword_526C9C,
                        dword_526C3C,
                        a9,
                        dword_526C4C,
                        (unsigned __int8)(*(_BYTE *)(v35 + 2) & 2) >> 1);
                Pathfinder::doSomething4(
                  thisa,
                  dword_526C38,
                  dword_526C6C,
                  dword_526C9C,
                  (unsigned __int16)word_526C5A + v36,
                  v16,
                  v34,
                  v33,
                  v32,
                  v31,
                  v30,
                  v29,
                  v28);
                if ( dword_526C28 )
                {
                  if ( __PAIR__(dword_526C6C, dword_526C38) == a10 )
                  {
                    if ( !(byte_526C5C & 4) )
                    {
                      v37 = dword_526C44;
                      v38 = usedToCheckForBoatByCastle(advManager, dword_526C38, dword_526C6C);
                      dword_526C98 = sub_464D00(
                                       byte_526C30[dword_526C9C],
                                       dword_526C9C,
                                       dword_524760 - (unsigned __int16)word_526C5A,
                                       a9,
                                       (unsigned __int8)(*(_BYTE *)(v38 + 2) & 2) >> 1,
                                       v37);
                      v39 = dword_526C98 + (unsigned __int16)word_526C5A;
                      if ( dword_526CA8 > v39 )
                        dword_526CA8 = dword_526C98 + (unsigned __int16)word_526C5A;
                    }
                  }
                }
              }
            }
            ++dword_526C9C;
          }
          while ( dword_526C9C < 8 );
          goto LABEL_72;
        }
      }
    }
LABEL_72:
    ++dword_526CA0;
  }
  LOBYTE(v13) = a12;
  if ( a12 )
  {
    dword_526C8C = 0;
    LOBYTE(v13) = mapWidth;
    if ( mapWidth > 0 )
    {
      do
      {
        for ( dword_526C64 = 0; mapWidth > dword_526C64; ++dword_526C64 )
        {
          if ( (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, dword_526C8C, dword_526C64) + 9) & 0x7F) == 24 )
          {
            dword_526C70 = usedToCheckForBoatByCastle(advManager, dword_526C8C, dword_526C64);
            dword_526C9C = 0;
            do
            {
              v40 = byte_4F1DC1[4 * dword_526C9C];
              dword_526C50 = dword_526C8C + byte_4F1DC0[4 * dword_526C9C];
              dword_526C88 = dword_526C64 + v40;
              if ( dword_526C50 >= 0 && dword_526C50 < mapWidth && dword_526C88 >= 0 && mapHeight > dword_526C88 )
              {
                dword_526C84 = usedToCheckForBoatByCastle(advManager, dword_526C50, dword_526C88);
                dword_526C68 = 1;
                if ( (1 << dword_526C9C) & 0x38
                  && *(_BYTE *)(dword_526C84 + 3) != -1
                  && (*(_BYTE *)(dword_526C84 + 2) & 0xFC) != -68
                  && !(*(_BYTE *)(dword_526C84 + 8) & 0x80) )
                  dword_526C68 = 0;
                if ( dword_526C68 )
                {
                  v41 = dword_526C50 + dword_526C88 * mapWidth;
                  if ( thisa->field_2414[v41].field_4 & 1 )
                  {
                    if ( !(*(_BYTE *)(dword_526C84 + 9) & 0x80) )
                    {
                      v42 = (unsigned __int8)tileToTerrainType[*(_WORD *)dword_526C84];
                      HIWORD(v43) = 0;
                      dword_526CB0 = v42;
                      LOWORD(v43) = thisa->field_2414[v41].field_2;
                      dword_526C48 = v43;
                      v44 = sub_464D00(
                              v42,
                              dword_526C9C,
                              dword_524760 - v43,
                              a9,
                              (unsigned __int8)(*(_BYTE *)(dword_526C84 + 2) & 2) >> 1,
                              (unsigned __int8)(*(_BYTE *)(dword_526C70 + 2) & 2) >> 1);
                      Pathfinder::doSomething4(
                        thisa,
                        dword_526C8C,
                        dword_526C64,
                        ((_BYTE)dword_526C9C + 4) & 7,
                        v44 + dword_526C48,
                        v16,
                        1,
                        0,
                        -1,
                        -1,
                        0,
                        -1,
                        -1);
                    }
                  }
                }
              }
              ++dword_526C9C;
            }
            while ( dword_526C9C < 8 );
          }
        }
        v13 = dword_526C8C + 1;
        dword_526C8C = v13;
      }
      while ( mapWidth > v13 );
    }
  }
  dword_524808 = 1;
  return v13;
}
