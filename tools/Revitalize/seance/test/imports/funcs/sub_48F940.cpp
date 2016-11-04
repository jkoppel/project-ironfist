{
  __int16 v36; // ax@26
  __int16 v37; // ax@27
  __int16 v38; // ax@53
  __int16 v39; // ax@60
  int v40; // ST28_4@60
  __int16 v41; // ax@60
  __int16 v42; // ax@65
  __int16 v43; // ax@67
  int v44; // ST28_4@67
  __int16 v45; // ax@67
  __int16 v46; // ax@71
  __int16 v47; // ax@80
  int v48; // ebx@144
  char v49; // al@161
  int v50; // ebx@171
  int v51; // ebx@184
  __int16 v52; // ax@190
  __int16 v53; // ax@190
  __int16 v54; // ax@199
  int v55; // eax@214
  int v56; // eax@217
  __int64 v57; // ST14_8@226
  __int16 v58; // ax@248
  char v59; // al@262
  char v60; // al@279
  signed int v61; // [sp+20h] [bp-13Ch]@144
  int v62; // [sp+30h] [bp-12Ch]@1
  float v63; // [sp+34h] [bp-128h]@256
  float v64; // [sp+38h] [bp-124h]@258
  int amt; // [sp+3Ch] [bp-120h]@104
  int v66; // [sp+50h] [bp-10Ch]@283
  char v67; // [sp+58h] [bp-104h]@226
  char v68; // [sp+5Ch] [bp-100h]@226
  signed int level; // [sp+60h] [bp-FCh]@144
  int xp; // [sp+64h] [bp-F8h]@144
  int arr[7]; // [sp+68h] [bp-F4h]@135
  int v72; // [sp+84h] [bp-D8h]@17
  char v73; // [sp+88h] [bp-D4h]@5
  int v74; // [sp+8Ch] [bp-D0h]@221
  char *v75; // [sp+90h] [bp-CCh]@7
  int v76; // [sp+94h] [bp-C8h]@165
  signed int type; // [sp+CCh] [bp-90h]@103
  int v78; // [sp+D0h] [bp-8Ch]@195
  unsigned int i; // [sp+D4h] [bp-88h]@165
  unsigned int j; // [sp+D8h] [bp-84h]@167
  ARTIFACT a2a; // [sp+DCh] [bp-80h]@190
  int v82; // [sp+E0h] [bp-7Ch]@190
  void *v83; // [sp+E4h] [bp-78h]@221
  int v84; // [sp+E8h] [bp-74h]@232
  char v85; // [sp+ECh] [bp-70h]@222
  int v86; // [sp+F0h] [bp-6Ch]@190
  int v87; // [sp+F4h] [bp-68h]@269
  int v88; // [sp+F8h] [bp-64h]@289
  int v89; // [sp+FCh] [bp-60h]@1
  int v90; // [sp+11Ch] [bp-40h]@1
  char v91; // [sp+120h] [bp-3Ch]@260
  int v92; // [sp+124h] [bp-38h]@112
  int v93; // [sp+128h] [bp-34h]@1
  char v94; // [sp+12Ch] [bp-30h]@133
  int v95; // [sp+130h] [bp-2Ch]@260
  int v96; // [sp+134h] [bp-28h]@260
  int v97; // [sp+138h] [bp-24h]@1
  Spell spell; // [sp+13Ch] [bp-20h]@10
  int a3a; // [sp+140h] [bp-1Ch]@133
  int creatureType; // [sp+144h] [bp-18h]@112
  signed int slot; // [sp+148h] [bp-14h]@133
  int v102; // [sp+14Ch] [bp-10h]@268
  void *v103; // [sp+150h] [bp-Ch]@1
  Player *v104; // [sp+154h] [bp-8h]@1
  int v105; // [sp+158h] [bp-4h]@10

  v62 = this;
  v103 = 0;
  v89 = *(_BYTE *)(a2 + 9) & 0x7F;
  v90 = 0;
  v97 = 0;
  v93 = curPlayerIdx;
  v104 = curPlayer;
  if ( *(_QWORD *)(a3 + 33) == a4 )
  {
    *(_DWORD *)(a3 + 37) = -1;
    *(_DWORD *)(a3 + 33) = *(_DWORD *)(a3 + 37);
  }
  --*(_DWORD *)(a3 + 53);
  switch ( v89 )
  {
    case 28:
      if ( *(_BYTE *)(a3 + 227) & 0x80 )
      {
        *(_DWORD *)(a3 + 227) &= 0xFFFFFF7Fu;
        *(_DWORD *)(a3 + 53) = 0;
        *(_BYTE *)(a3 + 44) = *(_BYTE *)(this + 638);
        *(_DWORD *)(this + 634) = *(_BYTE *)(a3 + 23);
        *(_DWORD *)(this + 642) = sub_4C0550(*(_DWORD *)(this + 638));
        *(_DWORD *)(v62 + 626) = 1;
        sub_4C1B30((void *)v62, (signed int)&v73);
      }
      goto LABEL_308;
    case 43:
      v75 = &gameObject->probablyArtifactGeneratedRandomly[8
                                                         * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)
                                                         + 103];
      sub_42CC90(-1, -1, (unsigned __int8)v75[4], (unsigned __int8)v75[5], a2, 3);
      *(_DWORD *)(a3 + 227) |= 0x80u;
      *(_DWORD *)(a3 + 53) = 0;
      v75[6] = *(_BYTE *)(a3 + 2);
      v75[7] = *(_BYTE *)(a3 + 3);
      *(_DWORD *)(v62 + 634) = 6;
      *(_DWORD *)(v62 + 638) = v75[3];
      *(_DWORD *)(v62 + 642) = sub_4C0550(*(_DWORD *)(v62 + 638));
      *(_DWORD *)(v62 + 626) = 1;
      goto LABEL_308;
    case 1:
    case 23:
    case 29:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 1008] == curPlayerIdx )
        goto LABEL_308;
      if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3] == -1 )
        goto LABEL_12;
      spell = gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4];
      v105 = sub_4B5BC0(
               a3,
               gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3],
               (int)&spell,
               a2);
      if ( v105 )
      {
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3] = -1;
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4] = 0;
        Hero::checkForLevelUp((Hero *)a3);
LABEL_12:
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), curPlayerIdx);
        if ( v89 == 23 )
        {
          for ( spell = 61; (signed int)spell < 64; ++spell )
          {
            if ( Hero::hasSpell((Hero *)a3, spell) && getSpellCost(spell, (Hero *)a3) < *(_WORD *)a3 )
            {
              *(_WORD *)a3 -= getSpellCost(spell, (Hero *)a3);
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3] = spell + 1;
              v72 = Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_SPELLPOWER);
              if ( v72 > 51 )
                v72 = 51;
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4] = 5 * v72;
              spell = 999;
            }
          }
        }
      }
      goto LABEL_308;
    case 21:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 1008] != curPlayerIdx )
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), curPlayerIdx);
      goto LABEL_308;
    case 6:
      if ( !(((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1) )
        goto LABEL_28;
      if ( Hero::numArtifacts((Hero *)a3) < 14 )
      {
        v37 = *(_WORD *)(a2 + 4) >> 3;
        grantArtifact((Hero *)a3, (ARTIFACT)(unsigned __int8)v37, 1, -1);
      }
      else
      {
        v36 = *(_WORD *)(a2 + 4) & 7;
        LOBYTE(v36) = v36 | 0x10;
        *(_WORD *)(a2 + 4) = v36;
LABEL_28:
        if ( sub_4B5100(
               500 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5),
               125 * (4 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 4)) )
        {
          grantResource((Hero *)a3, 6, 500 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5));
        }
        else
        {
          giveXPToHero(
            (Hero *)a3,
            125 * (4 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 4),
            1);
          Hero::checkForLevelUp((Hero *)a3);
        }
      }
      v90 = 1;
      goto LABEL_308;
    case 84:
      if ( !(*(_BYTE *)(a3 + 228) & 2) )
      {
        *(_DWORD *)(a3 + 49) += 400;
        *(_DWORD *)(a3 + 53) += 400;
        *(_DWORD *)(a3 + 227) |= 0x200u;
        ++*(_BYTE *)(a3 + 68);
      }
      goto LABEL_308;
    case 3:
      if ( !(*(_BYTE *)(a3 + 227) & 2) )
      {
        *(_DWORD *)(a3 + 227) |= 2u;
        ++*(_BYTE *)(a3 + 68);
      }
      goto LABEL_308;
    case 7:
      if ( !(*(_BYTE *)(a3 + 227) & 0x10) )
      {
        *(_DWORD *)(a3 + 227) |= 0x10u;
        ++*(_BYTE *)(a3 + 69);
      }
      goto LABEL_308;
    case 67:
      if ( !(*(_BYTE *)(a3 + 228) & 0x20) )
      {
        *(_DWORD *)(a3 + 227) |= 0x2000u;
        ++*(_BYTE *)(a3 + 69);
      }
      goto LABEL_308;
    case 9:
      if ( !(*(_BYTE *)(a3 + 227) & 4) )
      {
        *(_DWORD *)(a3 + 227) |= 4u;
        ++*(_BYTE *)(a3 + 69);
      }
      goto LABEL_308;
    case 26:
      if ( !(*(_BYTE *)(a3 + 227) & 8) )
      {
        *(_DWORD *)(a3 + 227) |= 8u;
        ++*(_BYTE *)(a3 + 68);
        *(_DWORD *)(a3 + 49) += 800;
        *(_DWORD *)(a3 + 53) += 800;
      }
      goto LABEL_308;
    case 70:
      if ( !(*(_BYTE *)(a3 + 228) & 1) )
      {
        *(_DWORD *)(a3 + 227) |= 0x100u;
        *(_BYTE *)(a3 + 68) += 2;
      }
      goto LABEL_308;
    case 4:
      if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) != 1 )
      {
        grantArtifact(
          (Hero *)a3,
          (ARTIFACT)((unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 2),
          1,
          -1);
        v38 = *(_WORD *)(a2 + 4) & 7;
        LOBYTE(v38) = v38 | 8;
        *(_WORD *)(a2 + 4) = v38;
      }
      goto LABEL_308;
    case 95:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        grantResource(
          (Hero *)a3,
          (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1,
          (unsigned int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 7 < 1 ? 500 : 5);
        *(_WORD *)(a2 + 4) &= 7u;
      }
      goto LABEL_308;
    case 88:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        v39 = *(_WORD *)(a2 + 4) >> 3;
        v40 = (v39 & 0xF0u) >> 4;
        v41 = *(_WORD *)(a2 + 4) >> 3;
        grantResource((Hero *)a3, (v41 & 0xF) - 1, v40);
        *(_WORD *)(a2 + 4) &= 7u;
      }
      goto LABEL_308;
    case 80:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        if ( (*(_WORD *)(a2 + 4) >> 3) & 0x80 )
        {
          if ( Hero::numArtifacts((Hero *)a3) != 14 )
          {
            v42 = *(_WORD *)(a2 + 4) >> 3;
            spell = v42 & 0x7F;
            grantArtifact((Hero *)a3, (ARTIFACT)(v42 & 0x7F), 1, -1);
          }
          *(_WORD *)(a2 + 4) &= 7u;
        }
        else
        {
          v43 = *(_WORD *)(a2 + 4) >> 3;
          v44 = (v43 & 0xF0u) >> 4;
          v45 = *(_WORD *)(a2 + 4) >> 3;
          grantResource((Hero *)a3, (v45 & 0xF) - 1, v44);
          *(_WORD *)(a2 + 4) &= 7u;
        }
      }
      goto LABEL_308;
    case 33:
      if ( ((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1 && Hero::numArtifacts((Hero *)a3) < 14 )
      {
        v46 = *(_WORD *)(a2 + 4) >> 3;
        grantArtifact((Hero *)a3, (ARTIFACT)(unsigned __int8)v46, 1, -1);
        grantResource((Hero *)a3, 6, 1000);
      }
      else
      {
        if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
          grantResource((Hero *)a3, 6, 1500);
      }
      v90 = 1;
      goto LABEL_308;
    case 90:
      switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
      {
        case 1u:
          grantResource((Hero *)a3, 0, 5);
          break;
        case 2u:
          grantResource((Hero *)a3, 0, 5);
          grantResource((Hero *)a3, 6, 200);
          break;
        case 3u:
          grantResource((Hero *)a3, 0, 10);
          grantResource((Hero *)a3, 6, 500);
          break;
        case 0u:
          break;
      }
      v90 = 1;
      goto LABEL_308;
    case 8:
      grantResource(
        (Hero *)a3,
        6,
        100 * ((signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) >> 4));
      v47 = *(_WORD *)(a2 + 4) >> 3;
      grantResource(
        (Hero *)a3,
        v47 & 0xF,
        (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) >> 4);
      v90 = 1;
      goto LABEL_308;
    case 62:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 75)) )
      {
        ++*(_BYTE *)(a3 + 64);
        *(_DWORD *)(a3 + 75) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
      }
      goto LABEL_308;
    case 86:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 95))
        && *(_WORD *)(a3 + 61) + 2 * *(_BYTE *)(a3 + 120) >= 10 )
      {
        ++*(_BYTE *)(a3 + 63);
        ++*(_BYTE *)(a3 + 64);
        ++*(_BYTE *)(a3 + 66);
        ++*(_BYTE *)(a3 + 65);
        *(_DWORD *)(a3 + 95) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
      }
      goto LABEL_308;
    case 66:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 87)) )
      {
        ++*(_BYTE *)(a3 + 65);
        *(_DWORD *)(a3 + 87) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
      }
      goto LABEL_308;
    case 69:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 79)) )
      {
        ++*(_BYTE *)(a3 + 66);
        *(_DWORD *)(a3 + 79) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
      }
      goto LABEL_308;
    case 73:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 83)) )
      {
        ++*(_BYTE *)(a3 + 63);
        *(_DWORD *)(a3 + 83) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
      }
      goto LABEL_308;
    case 10:
      if ( !((1 << (*(_WORD *)(a2 + 4) >> 3)) & *(_DWORD *)(a3 + 71)) )
      {
        giveXPToHero((Hero *)a3, 1000, 1);
        *(_DWORD *)(a3 + 71) |= 1 << (*(_WORD *)(a2 + 4) >> 3);
        Hero::checkForLevelUp((Hero *)a3);
      }
      goto LABEL_308;
    case 22:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        grantResource((Hero *)a3, 6, 500 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5));
        *(_WORD *)(a2 + 4) &= 7u;
      }
      goto LABEL_308;
    case 27:
      type = (signed int)*(_BYTE *)(a2 + 3) >> 1;
      if ( type == 6 )
        amt = 100 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
      else
        amt = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
      grantResource((Hero *)a3, type, amt);
      v90 = 1;
      goto LABEL_308;
    case 40:
      if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) != 99 )
      {
        grantResource((Hero *)a3, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), 2);
        *(_WORD *)(a2 + 4) = *(_WORD *)(a2 + 4) & 7 | 0x318;
      }
      goto LABEL_308;
    case 71:
      Hero::transmuteStacks((Hero *)a3, 15, 16);
      Hero::transmuteStacks((Hero *)a3, 12, 13);
      Hero::transmuteStacks((Hero *)a3, 21, 22);
      goto LABEL_308;
    case 97:
      Hero::transmuteStacks((Hero *)a3, 40, 41);
      Hero::transmuteStacks((Hero *)a3, 3, 4);
      Hero::transmuteStacks((Hero *)a3, 5, 6);
      goto LABEL_308;
    case 60:
      creatureType = 20;
      v92 = 0;
      goto LABEL_132;
    case 61:
      creatureType = 61;
      v92 = 0;
      goto LABEL_132;
    case 83:
      if ( ((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1 )
        goto LABEL_308;
      creatureType = 17;
      v92 = 0;
      goto LABEL_132;
    case 77:
      if ( ((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1 )
        goto LABEL_308;
      creatureType = 55;
      v92 = 0;
      goto LABEL_132;
    case 20:
      if ( ((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1 )
        goto LABEL_308;
      creatureType = 36;
      v92 = 0;
      goto LABEL_132;
    case 72:
      creatureType = 38;
      v92 = 1;
      goto LABEL_132;
    case 11:
      creatureType = 60;
      v92 = 0;
      goto LABEL_132;
    case 37:
      creatureType = 57;
      v92 = 0;
      goto LABEL_132;
    case 34:
      creatureType = 58;
      v92 = 0;
      goto LABEL_132;
    case 58:
      creatureType = 12;
      v92 = 1;
      goto LABEL_132;
    case 59:
      creatureType = 20;
      v92 = 1;
      goto LABEL_132;
    case 13:
      creatureType = 1;
      v92 = 1;
      goto LABEL_132;
    case 14:
      creatureType = 11;
      v92 = 1;
      goto LABEL_132;
    case 16:
      creatureType = 0;
      v92 = 1;
      goto LABEL_132;
    case 15:
    case 65:
      creatureType = 21;
      v92 = 1;
      goto LABEL_132;
    case 87:
      creatureType = 29;
      v92 = 1;
      goto LABEL_132;
    case 78:
      creatureType = 47;
      v92 = 1;
LABEL_132:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        sub_4B36D0(
          creatureType,
          (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5),
          v92,
          (int)&a3a,
          (int)&v94,
          (int)&slot);
        if ( a3a > 0 )
        {
          addCreaturesToArmy((ArmyInfo *)(a3 + 101), creatureType, a3a, slot);
          *(_WORD *)(a2 + 4) = *(_WORD *)(a2 + 4) & 7 | 8
                                                      * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)
                                                       - (_WORD)a3a);
          if ( !v92 )
          {
            getCreatureCosts(creatureType, arr);
            for ( spell = 0; (signed int)spell < 7; ++spell )
              curPlayer->resources[spell] -= a3a * arr[spell];
          }
        }
      }
      if ( !((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) && v89 == 11 )
        v90 = 1;
      goto LABEL_308;
    case 24:
      sub_4932B0(a2, a3, (int)&v90);
      goto LABEL_308;
    case 68:
      if ( !((1 << ((*(_WORD *)(a2 + 4) >> 3) & 0x1F)) & *(_DWORD *)(a3 + 91)) )
      {
        level = levelForXP(*(_DWORD *)(a3 + 57));
        v48 = experienceForLevel(level + 1);
        xp = v48 - experienceForLevel(level);
        v61 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) >> 6;
        if ( v61 == 1 )
        {
          giveXPToHero((Hero *)a3, xp, 1);
          *(_DWORD *)(a3 + 91) |= 1 << (((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) & 0x1F);
          Hero::checkForLevelUp((Hero *)a3);
        }
        else
        {
          if ( v61 == 2 )
          {
            if ( curPlayer->resources[6] > 2000 )
            {
              curPlayer->resources[6] -= 2000;
              giveXPToHero((Hero *)a3, xp, 1);
              *(_DWORD *)(a3 + 91) |= 1 << (((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) & 0x1F);
              Hero::checkForLevelUp((Hero *)a3);
            }
          }
          else
          {
            if ( v61 == 3 && curPlayer->resources[5] > 10 )
            {
              curPlayer->resources[5] -= 10;
              giveXPToHero((Hero *)a3, xp, 1);
              *(_DWORD *)(a3 + 91) |= 1 << (((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) & 0x1F);
              Hero::checkForLevelUp((Hero *)a3);
            }
          }
        }
      }
      goto LABEL_308;
    case 25:
      if ( !(gameObject->field_6236[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 278] & (unsigned __int8)byte_532C5C) )
      {
        gameObject->field_6236[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 278] |= byte_532C5C;
        sub_4190F0(curPlayerIdx);
      }
      goto LABEL_308;
    case 31:
    case 74:
    case 75:
      if ( Hero::hasArtifact((Hero *)a3, ARTIFACT_MAGIC_BOOK)
        && spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1].level <= *(_BYTE *)(a3 + 123) + 2 )
      {
        v49 = Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_KNOWLEDGE);
        Hero::learnSpell((Hero *)a3, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1, v49);
      }
      goto LABEL_308;
    case 35:
      sub_4B6560(a2, a3, a4);
      goto LABEL_308;
    case 39:
      sub_48F6B0(a3);
      goto LABEL_165;
    case 36:
LABEL_165:
      v76 = 0;
      for ( i = 0; (signed int)i < mapHeight; ++i )
      {
        for ( j = 0; (signed int)j < mapWidth; ++j )
        {
          if ( *(&gameObject->map.tiles[j].objType + 12 * i * gameObject->map.width) == (unsigned __int8)((unsigned __int8)v89 | 0x80) )
          {
            if ( *((_BYTE *)&gameObject->map.tiles[j].field_2 + 12 * i * gameObject->map.width + 1) == *(_BYTE *)(a2 + 3) )
            {
              v50 = abs(i - HIDWORD(a4));
              if ( abs(j - a4) + v50 > ((unsigned int)(v89 - 36) < 1 ? 1 : 3) )
                ++v76;
            }
          }
        }
      }
      if ( v76 < 1 )
        goto LABEL_308;
      if ( v76 > 1 )
        v76 = unseededNextRand(1, v76);
      i = 0;
LABEL_179:
      if ( (signed int)i < mapHeight )
      {
        for ( j = 0; ; ++j )
        {
          if ( (signed int)j >= mapWidth )
          {
            ++i;
            goto LABEL_179;
          }
          if ( *(&gameObject->map.tiles[j].objType + 12 * i * gameObject->map.width) == (unsigned __int8)((unsigned __int8)v89 | 0x80) )
          {
            if ( *((_BYTE *)&gameObject->map.tiles[j].field_2 + 12 * i * gameObject->map.width + 1) == *(_BYTE *)(a2 + 3) )
            {
              v51 = abs(i - HIDWORD(a4));
              if ( abs(j - a4) + v51 > ((unsigned int)(v89 - 36) < 1 ? 1 : 3) )
              {
                --v76;
                if ( v76 <= 0 )
                  break;
              }
            }
          }
        }
      }
      sub_4BFAC0((AdvManager *)v62, 1);
      sub_453A20(advManager, a3, __PAIR__(i, j), 0, 0);
      goto LABEL_308;
    case 41:
      v52 = *(_WORD *)(a2 + 4) >> 3;
      v82 = (v52 & 0xF0u) >> 4;
      a2a = (signed int)*(_BYTE *)(a2 + 3) >> 1;
      v53 = *(_WORD *)(a2 + 4) >> 3;
      v86 = v53 & 0x7F;
      if ( Hero::numArtifacts((Hero *)a3) == 14 )
        goto LABEL_308;
      if ( a2a == 86 )
      {
        grantArtifact((Hero *)a3, ARTIFACT_SPELL_SCROLL, 1, (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
        v90 = 1;
        goto LABEL_308;
      }
      if ( ((unsigned __int16)(*(_WORD *)(a2 + 4) >> 3) >> 8) & 1 )
      {
        if ( v86 == 57 )
        {
          v78 = 50;
        }
        else
        {
          v78 = 1;
          if ( !sub_4B5210(a2a, v86, 1) )
            goto LABEL_308;
        }
        if ( sub_4B5BC0(a3, v86, (int)&v78, a2) )
        {
LABEL_204:
          for ( spell = 0; (signed int)spell < 7; ++spell )
          {
            if ( curPlayer->resources[spell] < 0 )
              curPlayer->resources[spell] = 0;
          }
          grantArtifact((Hero *)a3, a2a, 1, -1);
          v90 = 1;
        }
      }
      else
      {
        v54 = *(_WORD *)(a2 + 4) >> 3;
        switch ( v54 & 0xF )
        {
          case 4:
            if ( *(_BYTE *)(a3 + 123) )
              goto LABEL_204;
            goto LABEL_308;
          case 5:
            if ( *(_BYTE *)(a3 + 122) )
              goto LABEL_204;
            goto LABEL_308;
          case 1:
            goto LABEL_204;
          case 3:
            if ( !(unsigned int)sub_4B5310(a2a, 2000, 0, 0) )
              goto LABEL_308;
            gameObject->players[*(_BYTE *)(a3 + 3)].resources[6] -= 2000;
            goto LABEL_204;
          case 6:
            if ( !(unsigned int)sub_4B5310(a2a, 2500, v82, 3) )
              goto LABEL_308;
            gameObject->players[*(_BYTE *)(a3 + 3)].resources[6] -= 2500;
            v55 = 283 * *(_BYTE *)(a3 + 3) + 4 * v82;
            *(int *)((char *)gameObject->players[0].resources + v55) -= 3;
            goto LABEL_204;
          case 7:
            if ( !(unsigned int)sub_4B5310(a2a, 3000, v82, 5) )
              goto LABEL_308;
            gameObject->players[*(_BYTE *)(a3 + 3)].resources[6] -= 3000;
            v56 = 283 * *(_BYTE *)(a3 + 3) + 4 * v82;
            *(int *)((char *)gameObject->players[0].resources + v56) -= 5;
            goto LABEL_204;
          default:
            goto LABEL_308;
        }
      }
      goto LABEL_308;
    case 42:
      v83 = &gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)];
      v74 = dword_524C14;
      if ( *((_BYTE *)v83 + 3) == curPlayerIdx )
      {
        sub_4B3FE0(a3, (int)v83, 0, (int)&v85);
      }
      else
      {
        if ( *(_WORD *)((char *)v83 + 45) == 163 )
          v103 = &gameObject->castles[*(_WORD *)((char *)v83 + 47)];
        if ( dword_524810[*((_BYTE *)v83 + 3)] )
        {
          if ( v103 )
            *((_BYTE *)v103 + 23) = *((_BYTE *)v83 + 2);
          v84 = sub_4938B0(
                  (void *)this,
                  a4,
                  a3,
                  (const void *)(a3 + 101),
                  (int)v103,
                  (int)v83,
                  (char *)v83 + 101,
                  a4,
                  SBYTE4(a4),
                  -1,
                  1);
          if ( !v84 && v103 )
            sub_420F30(gameObject, *(_BYTE *)v103, curPlayerIdx, 0);
        }
        else
        {
          HIDWORD(v57) = v83;
          LODWORD(v57) = (char *)v83 + 101;
          v105 = sub_4B38C0(a3 + 101, a3, v57, 0, 0, (float *)&v68, (float *)&v67);
          if ( v105 && v103 )
            v105 = sub_4B38C0(
                     a3 + 101,
                     a3,
                     (unsigned int)((char *)v103 + 8),
                     1,
                     *(_BYTE *)v103,
                     (float *)&v68,
                     (float *)&v67);
        }
        sub_448110((AdvManager *)v62, 0);
LABEL_308:
        if ( v90 )
          sub_48BA30(v62, a2, a4, SHIDWORD(a4));
        curPlayerIdx = v93;
        curPlayer = v104;
        if ( *(_BYTE *)(a3 + 3) != -1 )
          Hero::checkForLevelUp((Hero *)a3);
        checkGameEnd(0, 0);
      }
      return;
    case 93:
      v90 = 1;
      goto LABEL_308;
    case 5:
      switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
      {
        case 2u:
          giveXPToHero((Hero *)a3, 1000, 1);
          break;
        case 3u:
          giveXPToHero((Hero *)a3, 1000, 1);
          Hero::acquireRandomArtifact((Hero *)a3);
          break;
        case 4u:
          giveXPToHero((Hero *)a3, 1000, 1);
          grantResource((Hero *)a3, 6, 2500);
          break;
        case 5u:
          if ( gameObject->players[*(_BYTE *)(a3 + 3)].resources[6] < 2500 )
          {
            sub_48F630(this, a3);
          }
          else
          {
            if ( sub_4B5370(2500) )
              gameObject->players[*(_BYTE *)(a3 + 3)].resources[6] -= 2500;
            else
              sub_48F630(v62, a3);
          }
          break;
        case 1u:
          break;
      }
      v58 = *(_WORD *)(a2 + 4) & 7;
      LOBYTE(v58) = v58 | 8;
      *(_WORD *)(a2 + 4) = v58;
      goto LABEL_308;
    case 76:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5
        && !Hero::hasSpell((Hero *)a3, (Spell)((unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1)) )
      {
        for ( spell = 0; (signed int)spell < 5; ++spell )
        {
          *((_BYTE *)dword_5247BC + spell) = 51;
          *(_WORD *)((char *)dword_5247BC + 2 * spell + 5) = 10;
        }
        spell = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1;
        if ( spell_table[spell].attributes & 1 )
        {
          v63 = Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_SPELLPOWER) <= 40 ? attackBonus[Hero::getPrimarySkill(
                                                                                                  (Hero *)a3,
                                                                                                  PRIMARY_SKILL_SPELLPOWER)] : attackBonus[40];
          v64 = v63;
        }
        else
        {
          v64 = 1.0;
        }
        v96 = (signed __int64)((double)*(_WORD *)&spell_table[spell].appearingChance
                             * *(float *)&curPlayer->_4[100]
                             * v64);
        sub_4B5140(a3 + 101, a3, (unsigned int)dword_5247BC, 0, 0, v96, (int)&v95, (int)&v91);
        if ( v95 )
        {
          spell = 50;
          v105 = sub_4B5BC0(a3, 51, (int)&spell, a2);
          if ( v105 )
          {
            v59 = Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_KNOWLEDGE);
            Hero::learnSpell((Hero *)a3, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) - 1, v59);
            *(_WORD *)(a2 + 4) &= 7u;
          }
        }
      }
      goto LABEL_308;
    case 12:
    case 32:
    case 91:
      sub_4B5D30(a3, a2, 0);
      goto LABEL_308;
    case 64:
      for ( spell = 0; (signed int)spell < 5; ++spell )
      {
        *((_BYTE *)dword_5247BC + spell) = gameObject->_8[7
                                                        * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)
                                                        + 3];
        *(_WORD *)((char *)dword_5247BC + 2 * spell + 5) = gameObject->_8[7
                                                                        * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)
                                                                        + 4]
                                                         / 5;
      }
      v102 = (signed __int64)((double)*((_BYTE *)dword_51D5A8 + a4 + HIDWORD(a4) * mapWidth)
                            * (double)dword_4F1F38
                            * flt_530730);
      sub_4B5140(a3 + 101, a3, (unsigned int)dword_5247BC, 0, 0, v102, (int)&v95, (int)&v91);
      if ( v95 )
      {
        v87 = gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4];
        v105 = sub_4B5BC0(
                 a3,
                 gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3],
                 (int)&v87,
                 a2);
        if ( v87 > 255 )
          v87 = 255;
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4] = v87;
        if ( v105 )
        {
          Hero::checkForLevelUp((Hero *)a3);
          sub_4270A0(gameObject, a4 - 2, HIDWORD(a4) - 1, a4 + 1, HIDWORD(a4) - 1, 56, 0, 4, 26, 104, 64, 23);
          sub_4270A0(gameObject, a4 - 2, SHIDWORD(a4), a4 + 1, SHIDWORD(a4), 56, 5, 9, 26, 109, 64, 23);
          sub_4270A0(gameObject, a4 - 2, HIDWORD(a4) - 1, a4 + 1, HIDWORD(a4) - 1, 51, 0, 3, 32, 75, 64, 23);
          sub_4270A0(gameObject, a4 - 2, SHIDWORD(a4), a4 + 1, SHIDWORD(a4), 51, 4, 7, 32, 80, 64, 23);
          sub_4270A0(gameObject, a4, SHIDWORD(a4), a4, SHIDWORD(a4), 29, 5, 5, 29, 4, 64, 23);
          gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 2] = 6;
          gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 3] = -1;
          gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 4] = 0;
          sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), curPlayerIdx);
        }
      }
      goto LABEL_308;
    case 96:
      explore(a4, SHIDWORD(a4), curPlayerIdx, 20);
      goto LABEL_308;
    case 92:
      if ( Hero::numArtifacts((Hero *)a3) < 14 )
        grantArtifact((Hero *)a3, (ARTIFACT)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), 1, -1);
      v90 = 1;
      goto LABEL_308;
    case 82:
      if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
      {
        *(_WORD *)(a2 + 4) &= 7u;
        v60 = Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_KNOWLEDGE);
        if ( *(_WORD *)a3 < 20 * v60 )
          *(_WORD *)a3 = 20 * v60;
      }
      goto LABEL_308;
    case 94:
      if ( !(*(_BYTE *)(a3 + 228) & 0x10) )
      {
        *(_WORD *)(a2 + 4) &= 7u;
        v66 = 10 * Hero::getPrimarySkill((Hero *)a3, PRIMARY_SKILL_KNOWLEDGE);
        if ( *(_WORD *)a3 < v66 )
        {
          *(_DWORD *)(a3 + 227) |= 0x1000u;
          *(_WORD *)a3 = v66;
        }
      }
      goto LABEL_308;
    case 85:
      if ( !*(_BYTE *)(a3 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) + 116) )
        Hero::learnSecondarySkill((Hero *)a3, (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5), 1);
      goto LABEL_308;
    case 79:
      v88 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5));
      if ( *(_BYTE *)v88 )
      {
        if ( unseededNextRand(0, 100) >= 40 )
        {
          sub_48F630(v62, a3);
        }
        else
        {
          for ( spell = 0; (signed int)spell < 7; ++spell )
          {
            gameObject->players[curPlayerIdx].resources[spell] += *(_DWORD *)(v88 + 4 * spell + 1);
            if ( gameObject->players[curPlayerIdx].resources[spell] < 0 )
              gameObject->players[curPlayerIdx].resources[spell] = 0;
          }
          if ( *(_WORD *)(v88 + 29) != -1 && Hero::numArtifacts((Hero *)a3) < 14 )
            grantArtifact((Hero *)a3, (ARTIFACT)*(_WORD *)(v88 + 29), 1, -1);
          *(_BYTE *)v88 = 0;
        }
      }
      goto LABEL_308;
    case 119:
      v90 = sub_492310(a2, a3);
      goto LABEL_308;
    case 120:
      sub_492380(a2, a3);
      goto LABEL_308;
    case 122:
      sub_4923E0(a2, a3);
      goto LABEL_308;
    case 121:
      sub_492750(a2, a3);
      goto LABEL_308;
    case 123:
      sub_4928E0(this, a2, a3, a4, SHIDWORD(a4));
      goto LABEL_308;
    case 30:
    case 2:
    case 81:
    case 89:
    case 63:
    case 17:
    case 18:
    case 19:
    case 38:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
      goto LABEL_308;
  }
}
