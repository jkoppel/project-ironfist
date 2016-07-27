{
  int result; // eax@3
  __int16 v4; // ax@95
  __int16 v5; // ax@105
  __int16 v6; // ax@106
  __int16 v7; // ax@106
  int v8; // ebx@174
  signed int v9; // ebx@215
  int v10; // ebx@215
  signed int v11; // ebx@216
  int v12; // ebx@216
  signed int v13; // [sp+44h] [bp-E4h]@69
  float v14; // [sp+54h] [bp-D4h]@144
  float v15; // [sp+58h] [bp-D0h]@146
  float v16; // [sp+5Ch] [bp-CCh]@58
  int v17[7]; // [sp+60h] [bp-C8h]@85
  int v18; // [sp+7Ch] [bp-ACh]@179
  char v19; // [sp+80h] [bp-A8h]@175
  int v20; // [sp+84h] [bp-A4h]@168
  int v21; // [sp+88h] [bp-A0h]@176
  int v22; // [sp+8Ch] [bp-9Ch]@176
  int v23; // [sp+90h] [bp-98h]@172
  int v24; // [sp+94h] [bp-94h]@175
  int row; // [sp+98h] [bp-90h]@168
  int j; // [sp+9Ch] [bp-8Ch]@170
  int i; // [sp+C4h] [bp-64h]@142
  int v28; // [sp+CCh] [bp-5Ch]@151
  char v29; // [sp+D4h] [bp-54h]@131
  int v30; // [sp+DCh] [bp-4Ch]@108
  int v31; // [sp+E4h] [bp-44h]@4
  int v32; // [sp+E8h] [bp-40h]@4
  char v33; // [sp+F0h] [bp-38h]@131
  int v34; // [sp+100h] [bp-28h]@108
  int v35; // [sp+110h] [bp-18h]@11
  int v36; // [sp+114h] [bp-14h]@148
  unsigned int v37; // [sp+124h] [bp-4h]@106

  if ( a2 || *((_WORD *)dword_51D5A4 + a1 + HIDWORD(a1) * mapWidth) == -32001 )
  {
    dword_532CD4 = 1;
    dword_532CD0 = 1;
    *(_DWORD *)a3 = 100;
    v31 = 0;
    v32 = usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1));
    if ( curPlayer->field_40 <= 15
      || LOBYTE(curPlayer->field_41) != (_DWORD)a1
      || HIBYTE(curPlayer->field_41) != HIDWORD(a1) )
    {
      if ( *(_BYTE *)(v32 + 9) & 0x80 )
      {
        switch ( *(_BYTE *)(v32 + 9) & 0x7F )
        {
          case 0x18:
            v31 = sub_4B94F0(
                    *(_BYTE *)(v32 + 3),
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5),
                    a3);
            break;
          case 0x1B:
            v35 = (signed int)*(_BYTE *)(v32 + 3) >> 1;
            if ( v35 == 6 )
              v31 = (signed __int64)((double)(100 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5))
                                   * flt_530718[6]);
            else
              v31 = (signed __int64)((double)(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)
                                   * flt_530718[v35]);
            break;
          case 6:
            v31 = (signed __int64)(flt_530730 * 1600.0);
            break;
          case 0x2A:
            v31 = sub_4B9820(
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5),
                    a1,
                    SHIDWORD(a1),
                    a2,
                    a3);
            break;
          case 0x23:
            v31 = sub_4B9DD0(
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5),
                    a1,
                    SHIDWORD(a1),
                    a2,
                    a3);
            break;
          case 8:
            v31 = (signed __int64)((flt_53071C + flt_530720 + flt_530724 + flt_530728 + flt_530718[0] + flt_53072C)
                                 / 6.0
                                 * 5.0
                                 + flt_530730 * 500.0);
            break;
          case 0x29:
            v31 = sub_4B8F20(
                    (signed int)*(_BYTE *)(v32 + 3) >> 1,
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5));
            break;
          case 1:
          case 0x17:
          case 0x1D:
            v31 = sub_4B91E0((unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5), a1, SHIDWORD(a1), a3);
            break;
          case 0x19:
            if ( gameObject->field_6236[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) + 278] & (unsigned __int8)byte_532C5C )
              v31 = 0;
            else
              v31 = *(_DWORD *)&curPlayer->_4[88];
            break;
          case 0x1A:
            if ( !(dword_51D5BC->flags1 & 8) )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 350.0);
            break;
          case 3:
            if ( !(dword_51D5BC->flags1 & 2) && dword_5306DC < 3 )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 200.0);
            break;
          case 0x46:
            if ( !(dword_51D5BC->flags2 & 1) && dword_5306DC < 3 )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 400.0);
            break;
          case 7:
            if ( !(dword_51D5BC->flags1 & 0x10) && dword_5306D4 < 3 )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 200.0);
            break;
          case 0x43:
            if ( !(dword_51D5BC->flags2 & 0x20) && dword_5306D4 < 3 )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 200.0);
            break;
          case 9:
            if ( !(dword_51D5BC->flags1 & 4) && dword_5306D4 < 3 )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 200.0);
            break;
          case 0x54:
            if ( !(dword_51D5BC->flags2 & 2) )
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 300.0);
            break;
          case 0x1F:
          case 0x4A:
          case 0x4B:
            if ( Hero::getPrimarySkill(dword_51D5BC, PRIMARY_SKILL_KNOWLEDGE) <= 0
              || !Hero::hasArtifact(dword_51D5BC, ARTIFACT_MAGIC_BOOK)
              || Hero::hasSpell(
                   dword_51D5BC,
                   (Spell)((unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) - 1)) )
            {
              v31 = 0;
            }
            else
            {
              if ( spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) - 1].level <= dword_51D5BC->secondarySkillLevel[7] + 2 )
              {
                v31 = *(_WORD *)&spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) - 1].appearingChance;
                if ( spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) - 1].attributes & 1 )
                {
                  if ( Hero::getPrimarySkill(dword_51D5BC, PRIMARY_SKILL_KNOWLEDGE) <= 40 )
                    v16 = flt_4F28B0[Hero::getPrimarySkill(dword_51D5BC, PRIMARY_SKILL_KNOWLEDGE)];
                  else
                    v16 = *(float *)&dword_4F2950;
                  v31 = (signed __int64)((double)v31 * v16);
                }
              }
            }
            break;
          case 0xA:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[4] )
              v31 = 0;
            else
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1000.0);
            break;
          case 0x44:
            v31 = 0;
            if ( !((1 << ((*(_WORD *)(v32 + 4) >> 3) & 0x1F)) & *(_DWORD *)&dword_51D5BC->_5[24]) )
            {
              v13 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) >> 6;
              if ( v13 == 1 )
              {
                v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1500.0);
              }
              else
              {
                if ( v13 == 2 )
                {
                  if ( curPlayer->resources[6] >= 2000 )
                    v31 = (signed __int64)((double)(signed int)(signed __int64)(*(float *)&dword_51D5BC->field_E7[1]
                                                                              * 1500.0)
                                         - flt_530730 * 2000.0);
                }
                else
                {
                  if ( v13 == 3 && curPlayer->resources[5] >= 10 )
                    v31 = (signed __int64)((double)(signed int)(signed __int64)(*(float *)&dword_51D5BC->field_E7[1]
                                                                              * 1500.0)
                                         - flt_53072C * 10.0);
                }
              }
              if ( v31 < 0 )
                v31 = 0;
            }
            break;
          case 0x28:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 99 )
            {
              v31 = 0;
            }
            else
            {
              memset(v17, 0, 0x1Cu);
              v17[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)] = 2;
              v31 = sub_4B13F0((int)v17);
            }
            break;
          case 0x5F:
            if ( (unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5 )
            {
              if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 7 )
                v31 = (signed __int64)(flt_530730 * 500.0);
              else
                v31 = (signed __int64)(flt_530714[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)]
                                     * 5.0);
            }
            else
            {
              v31 = 0;
            }
            break;
          case 0x5A:
            v31 = (signed __int64)(flt_530718[0] * 5.0);
            break;
          case 0x21:
            if ( ((unsigned __int16)(*(_WORD *)(v32 + 4) >> 3) >> 8) & 1 )
            {
              v4 = *(_WORD *)(v32 + 4) >> 3;
              v31 = (signed __int64)(flt_530730 * 1000.0 + (double)dword_4F2050[(unsigned __int8)v4]);
            }
            else
            {
              if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 1 )
                v31 = (signed __int64)(flt_530730 * 1500.0);
              else
                v31 = (signed __int64)(flt_530730 * 200.0);
            }
            if ( v31 <= 0 )
              v31 = 150;
            break;
          case 0x50:
          case 0x58:
            if ( (unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5 )
            {
              if ( (*(_WORD *)(v32 + 4) >> 3) & 0x80 )
              {
                v5 = *(_WORD *)(v32 + 4) >> 3;
                v31 = dword_4F2050[v5 & 0x7F];
              }
              else
              {
                v6 = *(_WORD *)(v32 + 4) >> 3;
                v35 = (v6 & 0xF) - 1;
                v7 = *(_WORD *)(v32 + 4) >> 3;
                v37 = (v7 & 0xF0u) >> 4;
                v31 = (signed __int64)((double)(signed int)v37 * flt_530718[v35]);
              }
            }
            else
            {
              v31 = 0;
            }
            break;
          case 0xB:
            v30 = 60;
            v34 = 0;
            goto LABEL_131;
          case 0x3C:
            v30 = 20;
            v34 = 0;
            goto LABEL_131;
          case 0x3A:
            v30 = 12;
            v34 = 1;
            goto LABEL_131;
          case 0x3B:
            v30 = 20;
            v34 = 1;
            goto LABEL_131;
          case 0x4E:
            v30 = 47;
            v34 = 1;
            goto LABEL_131;
          case 0x48:
            v30 = 38;
            v34 = 1;
            goto LABEL_131;
          case 0x3D:
            v30 = 61;
            v34 = 0;
            goto LABEL_131;
          case 0x53:
            if ( ((unsigned __int16)(*(_WORD *)(v32 + 4) >> 3) >> 8) & 1 )
            {
              v31 = 0;
              break;
            }
            v30 = 17;
            v34 = 0;
            goto LABEL_131;
          case 0x14:
            if ( ((unsigned __int16)(*(_WORD *)(v32 + 4) >> 3) >> 8) & 1 )
            {
              v31 = 0;
              break;
            }
            v30 = 36;
            v34 = 0;
            goto LABEL_131;
          case 0x4D:
            if ( ((unsigned __int16)(*(_WORD *)(v32 + 4) >> 3) >> 8) & 1 )
            {
              v31 = 0;
            }
            else
            {
              v30 = 55;
              v34 = 0;
LABEL_131:
              sub_4B36D0(
                v30,
                (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5),
                v34,
                (int)&v29,
                (int)&v31,
                (int)&v33);
              dword_532CD4 = 0;
            }
            break;
          case 0x57:
            v30 = 29;
            v34 = 1;
            goto LABEL_131;
          case 0xD:
            v30 = 1;
            v34 = 1;
            goto LABEL_131;
          case 0xE:
            v30 = 11;
            v34 = 1;
            goto LABEL_131;
          case 0x10:
            v30 = 0;
            v34 = 1;
            goto LABEL_131;
          case 0xF:
          case 0x41:
            v30 = 21;
            v34 = 1;
            goto LABEL_131;
          case 0x22:
            v30 = 58;
            v34 = 0;
            goto LABEL_131;
          case 0x25:
            v30 = 57;
            v34 = 0;
            goto LABEL_131;
          case 0x5C:
            v31 = dword_4F2050[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)];
            if ( v31 < 125 )
              v31 = 125;
            break;
          case 4:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 1 )
              v31 = 0;
            else
              v31 = *(_DWORD *)&artifactLevels[4 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)
                                             + 96];
            break;
          case 0xC:
          case 0x20:
          case 0x5B:
            v31 = sub_4B5D30((int)dword_51D5BC, v32, 1);
            break;
          case 0x4C:
            if ( (unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5 )
            {
              i = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) - 1;
              if ( spell_table[i].attributes & 1 )
              {
                if ( Hero::getPrimarySkill(dword_51D5BC, PRIMARY_SKILL_SPELLPOWER) <= 40 )
                  v14 = attackBonus[Hero::getPrimarySkill(dword_51D5BC, PRIMARY_SKILL_SPELLPOWER)];
                else
                  v14 = attackBonus[40];
                v15 = v14;
              }
              else
              {
                v15 = 1.0;
              }
              v36 = (signed __int64)((double)*(_WORD *)&spell_table[i].appearingChance
                                   * *(float *)&curPlayer->_4[100]
                                   * v15);
              for ( i = 0; i < 5; ++i )
              {
                *((_BYTE *)dword_5247BC + i) = 51;
                *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = 10;
              }
              sub_4B5140(
                (int)&dword_51D5BC->army,
                (int)dword_51D5BC,
                (unsigned int)dword_5247BC,
                0,
                0,
                v36,
                (int)&v28,
                (int)&v31);
              if ( !v28 )
                v31 = -50;
            }
            else
            {
              v31 = 0;
            }
            break;
          case 5:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 1 )
            {
              v31 = 0;
            }
            else
            {
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 100.0
                                   + *(float *)&curPlayer->_4[104]
                                   + *(float *)&dword_51D5BC->field_E7[1] * 300.0
                                   + flt_530730 * 2500.0
                                   + *(float *)&dword_51D5BC->field_E7[1] * 300.0
                                   + flt_530730 * -750.0);
              if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) == 5
                && curPlayer->resources[6] < 2500 )
                v31 = -100;
            }
            break;
          case 0x40:
            v36 = (signed __int64)((double)*((_BYTE *)dword_51D5A8 + a1 + HIDWORD(a1) * mapWidth)
                                 * (double)dword_4F1F38
                                 * flt_530730);
            for ( i = 0; i < 5; ++i )
            {
              *((_BYTE *)dword_5247BC + i) = gameObject->_8[7
                                                          * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)
                                                          + 3];
              *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = gameObject->_8[7
                                                                          * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5)
                                                                          + 4]
                                                           / 5;
            }
            sub_4B5140(
              (int)&dword_51D5BC->army,
              (int)dword_51D5BC,
              (unsigned int)dword_5247BC,
              0,
              0,
              v36,
              (int)&v28,
              (int)&v31);
            if ( !v28 )
              v31 = -50;
            break;
          case 0x24:
          case 0x27:
            if ( dword_51D7EC )
            {
              dword_51D7EC = 0;
              v20 = -9999;
              for ( row = 0; mapHeight > row; ++row )
              {
                for ( j = 0; j < mapWidth; ++j )
                {
                  v23 = usedToCheckForBoatByCastle(advManager, j, row);
                  if ( *(_BYTE *)(v32 + 9) == *(_BYTE *)(v23 + 9) )
                  {
                    if ( *(_BYTE *)(v32 + 3) == *(_BYTE *)(v23 + 3) )
                    {
                      v8 = abs(a1 - j);
                      if ( abs(HIDWORD(a1) - row) + v8 > 3 )
                      {
                        v24 = (signed __int64)((double)sub_4B1B60(__PAIR__(row, j), 0, 0, (int)&v19, 700) * 0.85);
                        if ( v24 > v20 )
                        {
                          v20 = v24;
                          v21 = j;
                          v22 = row;
                        }
                      }
                    }
                  }
                }
              }
              v18 = sub_4B1B60(*(_QWORD *)&dword_51D5BC->x, 0, 0, (int)&v19, 500);
              if ( v18 + 200 >= v20 )
              {
                if ( a2 )
                  v31 = -200;
                else
                  v31 = 0;
              }
              else
              {
                v31 = v20 - v18 - 200;
              }
              dword_51D7EC = 1;
              dword_532CD4 = 0;
            }
            else
            {
              v31 = 0;
            }
            break;
          case 0x3E:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[8] )
              v31 = 0;
            else
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1000.0);
            break;
          case 0x45:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[12] )
              v31 = 0;
            else
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1000.0);
            break;
          case 0x42:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[20] )
              v31 = 0;
            else
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1000.0);
            break;
          case 0x49:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[16] )
              v31 = 0;
            else
              v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 1000.0);
            break;
          case 0x56:
            if ( (1 << (*(_WORD *)(v32 + 4) >> 3)) & *(_DWORD *)&dword_51D5BC->_5[28] )
            {
              v31 = 0;
            }
            else
            {
              if ( dword_51D5BC->oldLevel + 2 * dword_51D5BC->secondarySkillLevel[4] < 10 )
                v31 = 0;
              else
                v31 = (signed __int64)(*(float *)&dword_51D5BC->field_E7[1] * 8000.0);
            }
            break;
          case 0x15:
            if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) + 1] == dword_51D5BC->probablyOwnerIdx
              || sub_4B8CB0(gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5) + 1]) )
              v31 = 0;
            else
              v31 = 1000;
            break;
          case 0x16:
            v31 = (signed __int64)((double)(500 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5))
                                 * flt_530730);
            break;
          case 0x2B:
            dword_532CEC = 1;
            v31 = 90;
            break;
          case 0x5D:
            v31 = 105;
            break;
          case 0x47:
            v9 = sub_4B6790(21, 22);
            v10 = sub_4B6790(15, 16) + v9;
            v31 = sub_4B6790(12, 13) + v10;
            break;
          case 0x61:
            v11 = sub_4B6790(3, 4);
            v12 = sub_4B6790(5, 6) + v11;
            v31 = sub_4B6790(40, 41) + v12;
            break;
          case 0x5E:
            v31 = sub_4B6AC0((int)dword_51D5BC, 1);
            break;
          case 0x52:
            if ( (unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5 )
              v31 = sub_4B6AC0((int)dword_51D5BC, 2);
            else
              v31 = 0;
            break;
          case 0x55:
            v31 = sub_4B6A60((int)dword_51D5BC, (unsigned __int8)((unsigned __int8)(*(_WORD *)(v32 + 4) >> 8) >> -5));
            break;
          case 2:
          case 0x1E:
          case 0x3F:
          case 0x4F:
          case 0x51:
          case 0x59:
          case 0x60:
            v31 = 0;
            break;
          case 0x7A:
            v31 = sub_4B8610(v32);
            break;
          case 0x77:
            v31 = sub_4B88B0(v32);
            break;
          case 0x78:
            v31 = sub_4B8910(v32);
            break;
          case 0x79:
            v31 = sub_4B8970(v32);
            break;
          case 0x7B:
            v31 = sub_4B8A70(v32);
            break;
          default:
            sprintf(
              globBuf,
              "AI encountered object type %d and doesn't know how to deal with it.   Tell Phil",
              *(_BYTE *)(v32 + 9) & 0x7F);
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            v31 = 0;
            break;
        }
      }
      else
      {
        if ( !(unsigned __int8)(*(&tileExplored[(_DWORD)a1] + HIDWORD(a1) * mapWidth) & byte_532C5C) )
          v31 = 5;
      }
    }
    else
    {
      v31 = dword_4F21EC * (curPlayer->field_40 - 15) / 100;
    }
    if ( dword_532C50 && dword_532CD4 )
      v31 = (signed __int64)((double)v31 * *(float *)&dword_5305C0);
    if ( dword_532CCC && dword_532CD0 )
      v31 = (signed __int64)((double)v31 * *(float *)&dword_5306D8);
    if ( !a2 )
    {
      if ( v31 > 0 && *(&tileExplored[(_DWORD)a1] + HIDWORD(a1) * mapWidth) & 0x80 && (*(_BYTE *)(v32 + 9) & 0x7F) != 24 )
        v31 = 0;
      if ( v31 >= 0 || (*(_BYTE *)(v32 + 9) & 0x7F) == 42 )
      {
        if ( v31 <= 32000 )
        {
          if ( v31 < -32000 )
            v31 = -32000;
        }
        else
        {
          v31 = 32000;
        }
      }
      else
      {
        v31 = 0;
      }
      *((_WORD *)dword_51D5A4 + a1 + HIDWORD(a1) * mapWidth) = v31;
    }
    result = v31;
  }
  else
  {
    result = *((_WORD *)dword_51D5A4 + a1 + HIDWORD(a1) * mapWidth);
  }
  return result;
}
