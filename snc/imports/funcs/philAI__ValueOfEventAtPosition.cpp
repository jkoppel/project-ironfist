{
  int result; // eax@3
  __int16 v5; // ax@95
  __int16 v6; // ax@105
  __int16 v7; // ax@106
  __int16 v8; // ax@106
  int v9; // ebx@174
  signed int v10; // ebx@215
  int v11; // ebx@215
  signed int v12; // ebx@216
  int v13; // ebx@216
  signed int v14; // [sp+44h] [bp-E4h]@69
  int v15; // [sp+50h] [bp-D8h]@1
  float v16; // [sp+54h] [bp-D4h]@144
  float v17; // [sp+58h] [bp-D0h]@146
  float v18; // [sp+5Ch] [bp-CCh]@58
  int v19[7]; // [sp+60h] [bp-C8h]@85
  int v20; // [sp+7Ch] [bp-ACh]@179
  int v21; // [sp+80h] [bp-A8h]@175
  int v22; // [sp+84h] [bp-A4h]@168
  int v23; // [sp+88h] [bp-A0h]@176
  int v24; // [sp+8Ch] [bp-9Ch]@176
  mapCell *v25; // [sp+90h] [bp-98h]@172
  int v26; // [sp+94h] [bp-94h]@175
  int row; // [sp+98h] [bp-90h]@168
  int j; // [sp+9Ch] [bp-8Ch]@170
  int i; // [sp+C4h] [bp-64h]@142
  int v30; // [sp+CCh] [bp-5Ch]@151
  char v31; // [sp+D4h] [bp-54h]@131
  int v32; // [sp+DCh] [bp-4Ch]@108
  int v33; // [sp+E4h] [bp-44h]@4
  unsigned int v34; // [sp+E8h] [bp-40h]@4
  char v35; // [sp+F0h] [bp-38h]@131
  int v36; // [sp+100h] [bp-28h]@108
  int v37; // [sp+110h] [bp-18h]@11
  int v38; // [sp+114h] [bp-14h]@148
  unsigned int v39; // [sp+124h] [bp-4h]@106

  v15 = (int)this;
  if ( a2 || *((_WORD *)gaiHeroEventStratRVOfPos + a1 + HIDWORD(a1) * MAP_WIDTH) == -32001 )
  {
    gbReduceByReload = 1;
    gbReduceByBerserk = 1;
    *(_DWORD *)a3 = 100;
    v33 = 0;
    v34 = (unsigned int)advManager::GetCell(gpAdvManager, a1, SHIDWORD(a1));
    if ( gpCurPlayer->field_40 <= 15
      || LOBYTE(gpCurPlayer->field_41) != (_DWORD)a1
      || HIBYTE(gpCurPlayer->field_41) != HIDWORD(a1) )
    {
      if ( *(_BYTE *)(v34 + 9) & 0x80 )
      {
        switch ( *(_BYTE *)(v34 + 9) & 0x7F )
        {
          case LOCATION_ARMY_CAMP:
            v33 = philAI::EvaluateMonsterEvent(
                    *(_BYTE *)(v34 + 3),
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5),
                    a3);
            break;
          case LOCATION_RESOURCE:
            v37 = (signed int)*(_BYTE *)(v34 + 3) >> 1;
            if ( v37 == 6 )
              v33 = (signed __int64)((double)(100 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5))
                                   * gafAITurnCostResource[6]);
            else
              v33 = (signed __int64)((double)(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)
                                   * gafAITurnCostResource[v37]);
            break;
          case LOCATION_TREASURE_CHEST:
            v33 = (signed __int64)(flt_530730 * 1600.0);
            break;
          case LOCATION_HERO:
            v33 = philAI::EvaluateHeroEvent(
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5),
                    a1,
                    SHIDWORD(a1),
                    a2,
                    a3);
            break;
          case LOCATION_TOWN:
            v33 = philAI::EvaluateTownEvent(
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5),
                    a1,
                    SHIDWORD(a1),
                    a2,
                    a3);
            break;
          case LOCATION_CAMPFIRE:
            v33 = (signed __int64)((flt_53071C
                                  + flt_530720
                                  + flt_530724
                                  + flt_530728
                                  + gafAITurnCostResource[0]
                                  + flt_53072C)
                                 / 6.0
                                 * 5.0
                                 + flt_530730 * 500.0);
            break;
          case LOCATION_ARTIFACT:
            v33 = philAI::EvaluateArtifactEvent(
                    (signed int)*(_BYTE *)(v34 + 3) >> 1,
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5));
            break;
          case LOCATION_ALCHEMIST_LAB:
          case LOCATION_MINE:
          case LOCATION_SAWMILL:
            v33 = philAI::EvaluateMineEvent(
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5),
                    a1,
                    SHIDWORD(a1),
                    a3);
            break;
          case LOCATION_OBELISK:
            if ( gpGame->field_6236[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) + 278] & (unsigned __int8)giCurPlayerBit )
              v33 = 0;
            else
              v33 = *(_DWORD *)&gpCurPlayer->_4[88];
            break;
          case LOCATION_OASIS:
            if ( !(gpCurAIHero->flags1 & 8) )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 350.0);
            break;
          case LOCATION_BUOY:
            if ( !(gpCurAIHero->flags1 & 2) && giCurAIHeroMorale < 3 )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 200.0);
            break;
          case LOCATION_TEMPLE:
            if ( !(gpCurAIHero->flags2 & 1) && giCurAIHeroMorale < 3 )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 400.0);
            break;
          case LOCATION_FAERIE_RING:
            if ( !(gpCurAIHero->flags1 & 0x10) && giCurAIHeroLuck < 3 )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 200.0);
            break;
          case LOCATION_IDOL:
            if ( !(gpCurAIHero->flags2 & 0x20) && giCurAIHeroLuck < 3 )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 200.0);
            break;
          case LOCATION_FOUNTAIN:
            if ( !(gpCurAIHero->flags1 & 4) && giCurAIHeroLuck < 3 )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 200.0);
            break;
          case LOCATION_WATERING_HOLE:
            if ( !(gpCurAIHero->flags2 & 2) )
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 300.0);
            break;
          case LOCATION_SHRINE_FIRST:
          case LOCATION_SHRINE_SECOND_ORDER:
          case LOCATION_SHRINE_THIRD_ORDER:
            if ( hero::Stats(gpCurAIHero, PRIMARY_SKILL_KNOWLEDGE) <= 0
              || !hero::HasArtifact(gpCurAIHero, ARTIFACT_MAGIC_BOOK)
              || hero::HasSpell(
                   gpCurAIHero,
                   (Spell)((unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) - 1)) )
            {
              v33 = 0;
            }
            else if ( gsSpellInfo[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) - 1].level <= gpCurAIHero->secondarySkillLevel[7] + 2 )
            {
              v33 = *(_WORD *)&gsSpellInfo[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) - 1].appearingChance;
              if ( gsSpellInfo[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) - 1].attributes & 1 )
              {
                if ( hero::Stats(gpCurAIHero, PRIMARY_SKILL_KNOWLEDGE) <= 40 )
                  v18 = gfStatPower[hero::Stats(gpCurAIHero, PRIMARY_SKILL_KNOWLEDGE)];
                else
                  v18 = *(float *)&dword_4F2950;
                v33 = (signed __int64)((double)v33 * v18);
              }
            }
            break;
          case LOCATION_GAZEBO:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[4] )
              v33 = 0;
            else
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
            break;
          case LOCATION_TREE_OF_KNOWLEDGE:
            v33 = 0;
            if ( !((1 << ((*(_WORD *)(v34 + 4) >> 3) & 0x1F)) & *(_DWORD *)&gpCurAIHero->_5[24]) )
            {
              v14 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) >> 6;
              if ( v14 == 1 )
              {
                v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1500.0);
              }
              else if ( v14 == 2 )
              {
                if ( gpCurPlayer->resources[6] >= 2000 )
                  v33 = (signed __int64)((double)(signed int)(signed __int64)(*(float *)&gpCurAIHero->field_E7[1]
                                                                            * 1500.0)
                                       - flt_530730 * 2000.0);
              }
              else if ( v14 == 3 && gpCurPlayer->resources[5] >= 10 )
              {
                v33 = (signed __int64)((double)(signed int)(signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1500.0)
                                     - flt_53072C * 10.0);
              }
              if ( v33 < 0 )
                v33 = 0;
            }
            break;
          case LOCATION_WINDMILL:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 99 )
            {
              v33 = 0;
            }
            else
            {
              memset(v19, 0, 0x1Cu);
              v19[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)] = 2;
              v33 = philAI::RVConversion((int)v19);
            }
            break;
          case LOCATION_MAGIC_GARDEN:
            if ( (unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5 )
            {
              if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 7 )
                v33 = (signed __int64)(flt_530730 * 500.0);
              else
                v33 = (signed __int64)(flt_530714[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)]
                                     * 5.0);
            }
            else
            {
              v33 = 0;
            }
            break;
          case LOCATION_FLOTSAM:
            v33 = (signed __int64)(gafAITurnCostResource[0] * 5.0);
            break;
          case LOCATION_SEA_CHEST:
            if ( ((unsigned __int16)(*(_WORD *)(v34 + 4) >> 3) >> 8) & 1 )
            {
              v5 = *(_WORD *)(v34 + 4) >> 3;
              v33 = (signed __int64)(flt_530730 * 1000.0 + (double)gArtifactBaseRV[(unsigned __int8)v5]);
            }
            else if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 1 )
            {
              v33 = (signed __int64)(flt_530730 * 1500.0);
            }
            else
            {
              v33 = (signed __int64)(flt_530730 * 200.0);
            }
            if ( v33 <= 0 )
              v33 = 150;
            break;
          case LOCATION_WAGON:
          case LOCATION_LEAN_TO:
            if ( (unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5 )
            {
              if ( (*(_WORD *)(v34 + 4) >> 3) & 0x80 )
              {
                v6 = *(_WORD *)(v34 + 4) >> 3;
                v33 = gArtifactBaseRV[v6 & 0x7F];
              }
              else
              {
                v7 = *(_WORD *)(v34 + 4) >> 3;
                v37 = (v7 & 0xF) - 1;
                v8 = *(_WORD *)(v34 + 4) >> 3;
                v39 = (v8 & 0xF0u) >> 4;
                v33 = (signed __int64)((double)(signed int)v39 * gafAITurnCostResource[v37]);
              }
            }
            else
            {
              v33 = 0;
            }
            break;
          case LOCATION_ANCIENT_LAMP:
            v32 = 60;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_TREE_CITY:
            v32 = 20;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_WATCH_TOWER:
            v32 = 12;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_TREE_HOUSE:
            v32 = 20;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_EXCAVATION:
            v32 = 47;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_HALFLING_HOLE:
            v32 = 38;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_RUINS:
            v32 = 61;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_TROLL_BRIDGE:
            if ( ((unsigned __int16)(*(_WORD *)(v34 + 4) >> 3) >> 8) & 1 )
            {
              v33 = 0;
              break;
            }
            v32 = 17;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_DRAGON_CITY:
            if ( ((unsigned __int16)(*(_WORD *)(v34 + 4) >> 3) >> 8) & 1 )
            {
              v33 = 0;
              break;
            }
            v32 = 36;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_CITY_OF_DEAD:
            if ( ((unsigned __int16)(*(_WORD *)(v34 + 4) >> 3) >> 8) & 1 )
            {
              v33 = 0;
            }
            else
            {
              v32 = 55;
              v36 = 0;
LABEL_131:
              philAI::EvaluateOneTimeCreaturePurchase(
                v32,
                (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5),
                v36,
                (int)&v31,
                (int)&v33,
                (int)&v35);
              gbReduceByReload = 0;
            }
            break;
          case LOCATION_CAVE:
            v32 = 29;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_ARCHERS_HOUSE:
            v32 = 1;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_GOBLIN_HUT:
            v32 = 11;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_PEASANT_HUT:
            v32 = 0;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_DWARF_COTTAGE:
          case LOCATION_DWARF_CABIN:
            v32 = 21;
            v36 = 1;
            goto LABEL_131;
          case LOCATION_DESRT_TENT:
            v32 = 58;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_WAGON_CAMP:
            v32 = 57;
            v36 = 0;
            goto LABEL_131;
          case LOCATION_SHIPWRECK_SURVIVOR:
            v33 = gArtifactBaseRV[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)];
            if ( v33 < 125 )
              v33 = 125;
            break;
          case LOCATION_SKELETON:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 1 )
              v33 = 0;
            else
              v33 = *(_DWORD *)&gArtifactLevel[4 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)
                                             + 96];
            break;
          case LOCATION_GRAVEYARD:
          case LOCATION_SHIPWRECK:
          case LOCATION_DERELICT_SHIP:
            v33 = philAI::FightEvent((int)gpCurAIHero, v34, 1);
            break;
          case LOCATION_PYRAMID:
            if ( (unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5 )
            {
              i = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) - 1;
              if ( gsSpellInfo[i].attributes & 1 )
              {
                if ( hero::Stats(gpCurAIHero, PRIMARY_SKILL_SPELLPOWER) <= 40 )
                  v16 = gfBattleStat[hero::Stats(gpCurAIHero, PRIMARY_SKILL_SPELLPOWER)];
                else
                  v16 = gfBattleStat[40];
                v17 = v16;
              }
              else
              {
                v17 = 1.0;
              }
              v38 = (signed __int64)((double)*(_WORD *)&gsSpellInfo[i].appearingChance
                                   * *(float *)&gpCurPlayer->_4[100]
                                   * v17);
              for ( i = 0; i < 5; ++i )
              {
                *((_BYTE *)gpMonGroup + i) = 51;
                *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = 10;
              }
              philAI::ChooseEvaluateBattle(
                (int)&gpCurAIHero->army,
                (int)gpCurAIHero,
                (unsigned int)gpMonGroup,
                0,
                0,
                v38,
                (int)&v30,
                (int)&v33);
              if ( !v30 )
                v33 = -50;
            }
            else
            {
              v33 = 0;
            }
            break;
          case LOCATION_DAEMON_CAVE:
            if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 1 )
            {
              v33 = 0;
            }
            else
            {
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 100.0
                                   + *(float *)&gpCurPlayer->_4[104]
                                   + *(float *)&gpCurAIHero->field_E7[1] * 300.0
                                   + flt_530730 * 2500.0
                                   + *(float *)&gpCurAIHero->field_E7[1] * 300.0
                                   + flt_530730 * -750.0);
              if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) == 5
                && gpCurPlayer->resources[6] < 2500 )
                v33 = -100;
            }
            break;
          case LOCATION_ABANDONED_MINE:
            v38 = (signed __int64)((double)*((_BYTE *)gaiTurnValueOfMine + a1 + HIDWORD(a1) * MAP_WIDTH)
                                 * (double)dword_4F1F38
                                 * flt_530730);
            for ( i = 0; i < 5; ++i )
            {
              *((_BYTE *)gpMonGroup + i) = gpGame->_8[7
                                                    * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)
                                                    + 3];
              *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = gpGame->_8[7
                                                                    * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5)
                                                                    + 4]
                                                         / 5;
            }
            philAI::ChooseEvaluateBattle(
              (int)&gpCurAIHero->army,
              (int)gpCurAIHero,
              (unsigned int)gpMonGroup,
              0,
              0,
              v38,
              (int)&v30,
              (int)&v33);
            if ( !v30 )
              v33 = -50;
            break;
          case LOCATION_STONE_LITHS:
          case LOCATION_WHIRLPOOL:
            if ( dword_51D7EC )
            {
              dword_51D7EC = 0;
              v22 = -9999;
              for ( row = 0; MAP_HEIGHT > row; ++row )
              {
                for ( j = 0; j < MAP_WIDTH; ++j )
                {
                  v25 = advManager::GetCell(gpAdvManager, j, row);
                  if ( *(_BYTE *)(v34 + 9) == v25->objType )
                  {
                    if ( *(_BYTE *)(v34 + 3) == HIBYTE(v25->field_2) )
                    {
                      v9 = abs(a1 - j);
                      if ( abs(HIDWORD(a1) - row) + v9 > 3 )
                      {
                        v26 = (signed __int64)((double)philAI::StrategicValueOfPosition(v15, j, row, 0, 0, &v21, 700)
                                             * 0.85);
                        if ( v26 > v22 )
                        {
                          v22 = v26;
                          v23 = j;
                          v24 = row;
                        }
                      }
                    }
                  }
                }
              }
              v20 = philAI::StrategicValueOfPosition(v15, gpCurAIHero->x, gpCurAIHero->y, 0, 0, &v21, 500);
              if ( v20 + 200 >= v22 )
              {
                if ( a2 )
                  v33 = -200;
                else
                  v33 = 0;
              }
              else
              {
                v33 = v22 - v20 - 200;
              }
              dword_51D7EC = 1;
              gbReduceByReload = 0;
            }
            else
            {
              v33 = 0;
            }
            break;
          case LOCATION_FORT:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[8] )
              v33 = 0;
            else
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
            break;
          case LOCATION_WITCH_DOCTORS_HUT:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[12] )
              v33 = 0;
            else
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
            break;
          case LOCATION_STANDING_STONES:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[20] )
              v33 = 0;
            else
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
            break;
          case LOCATION_MERCENARY_CAMP:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[16] )
              v33 = 0;
            else
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
            break;
          case LOCATION_XANADU:
            if ( (1 << (*(_WORD *)(v34 + 4) >> 3)) & *(_DWORD *)&gpCurAIHero->_5[28] )
            {
              v33 = 0;
            }
            else if ( gpCurAIHero->oldLevel + 2 * gpCurAIHero->secondarySkillLevel[4] < 10 )
            {
              v33 = 0;
            }
            else
            {
              v33 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 8000.0);
            }
            break;
          case LOCATION_LIGHTHOUSE:
            if ( gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) + 1] == gpCurAIHero->probablyOwnerIdx
              || OnMySide(gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5) + 1]) )
              v33 = 0;
            else
              v33 = 1000;
            break;
          case LOCATION_WATERWHEEL:
            v33 = (signed __int64)((double)(500 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5))
                                 * flt_530730);
            break;
          case LOCATION_BOAT:
            dword_532CEC = 1;
            v33 = 90;
            break;
          case LOCATION_BOTTLE:
            v33 = 105;
            break;
          case LOCATION_HILL_FORT:
            v10 = philAI::ComputeUpgradeValue(21, 22);
            v11 = philAI::ComputeUpgradeValue(15, 16) + v10;
            v33 = philAI::ComputeUpgradeValue(12, 13) + v11;
            break;
          case LOCATION_FREEMANS_FOUNDRY:
            v12 = philAI::ComputeUpgradeValue(3, 4);
            v13 = philAI::ComputeUpgradeValue(5, 6) + v12;
            v33 = philAI::ComputeUpgradeValue(40, 41) + v13;
            break;
          case LOCATION_MAGIC_WELL:
            v33 = philAI::ManaRefreshValue((int)gpCurAIHero, 1);
            break;
          case LOCATION_ARTESIAN_SPRING:
            if ( (unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5 )
              v33 = philAI::ManaRefreshValue((int)gpCurAIHero, 2);
            else
              v33 = 0;
            break;
          case LOCATION_WITCH_HUT:
            v33 = philAI::ComputeValueOfFreeSS(
                    (int)gpCurAIHero,
                    (unsigned __int8)((unsigned __int8)(*(_WORD *)(v34 + 4) >> 8) >> -5));
            break;
          case LOCATION_SIGN:
          case LOCATION_ORACLE:
          case LOCATION_TRADING_POST:
          case LOCATION_SPHINX:
          case LOCATION_TAR_PIT:
          case LOCATION_MAGELLANS_MAPS:
          case LOCATION_OBSERVATION_TOWER:
            v33 = 0;
            break;
          case LOCATION_ALCHEMIST_TOWER:
            v33 = philAI::EvaluateGenericSite(v34);
            break;
          case LOCATION_BARRIER:
            v33 = philAI::EvaluateBarrier(v34);
            break;
          case LOCATION_TRAVELLER_TENT:
            v33 = philAI::EvaluatePassword(v34);
            break;
          case LOCATION_EXPANSION_DWELLING:
            v33 = philAI::EvaluateRecruitSite(v34);
            break;
          case LOCATION_JAIL:
            v33 = philAI::EvaluateJail(v34);
            break;
          default:
            sprintf(
              gText,
              "AI encountered object type %d and doesn't know how to deal with it.   Tell Phil",
              *(_BYTE *)(v34 + 9) & 0x7F);
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            v33 = 0;
            break;
        }
      }
      else if ( !(unsigned __int8)(*(&mapExtra[(_DWORD)a1] + HIDWORD(a1) * MAP_WIDTH) & giCurPlayerBit) )
      {
        v33 = 5;
      }
    }
    else
    {
      v33 = gUltArtifactAvgValue * (gpCurPlayer->field_40 - 15) / 100;
    }
    if ( gbTroopReload && gbReduceByReload )
      v33 = (signed __int64)((double)v33 * *(float *)&fReduceFactor);
    if ( gbBerserk && gbReduceByBerserk )
      v33 = (signed __int64)((double)v33 * *(float *)&fBerserkFactor);
    if ( !a2 )
    {
      if ( v33 > 0 && *(&mapExtra[(_DWORD)a1] + HIDWORD(a1) * MAP_WIDTH) & 0x80 && (*(_BYTE *)(v34 + 9) & 0x7F) != 24 )
        v33 = 0;
      if ( v33 >= 0 || (*(_BYTE *)(v34 + 9) & 0x7F) == 42 )
      {
        if ( v33 <= 32000 )
        {
          if ( v33 < -32000 )
            v33 = -32000;
        }
        else
        {
          v33 = 32000;
        }
      }
      else
      {
        v33 = 0;
      }
      *((_WORD *)gaiHeroEventStratRVOfPos + a1 + HIDWORD(a1) * MAP_WIDTH) = v33;
    }
    result = v33;
  }
  else
  {
    result = *((_WORD *)gaiHeroEventStratRVOfPos + a1 + HIDWORD(a1) * MAP_WIDTH);
  }
  return result;
}