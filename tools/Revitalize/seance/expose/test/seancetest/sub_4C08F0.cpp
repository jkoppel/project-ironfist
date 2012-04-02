int __thiscall sub_4C08F0(AdvManager *this, int a2, signed int a3, int *a4, int *a5, int a6, int a7, signed int a8, int a9)
{
  char *v9; // eax@3
  int v10; // ST90_4@5
  signed int v11; // ST74_4@5
  char *v12; // ST5C_4@16
  int v13; // eax@16
  sample_resource v14; // ST98_8@21
  int v15; // ebx@46
  signed int v16; // eax@46
  int v17; // ecx@86
  int v19; // [sp+10h] [bp-80h]@19
  AdvManager *thisb; // [sp+14h] [bp-7Ch]@1
  int v21; // [sp+20h] [bp-70h]@122
  int img2Arg; // [sp+24h] [bp-6Ch]@120
  int img2Type; // [sp+28h] [bp-68h]@120
  int img1Type; // [sp+2Ch] [bp-64h]@120
  int img1Arg; // [sp+30h] [bp-60h]@120
  int v26; // [sp+34h] [bp-5Ch]@68
  signed int v27; // [sp+44h] [bp-4Ch]@46
  int v28; // [sp+48h] [bp-48h]@3
  int v29; // [sp+4Ch] [bp-44h]@3
  int v30; // [sp+50h] [bp-40h]@3
  int v31; // [sp+58h] [bp-38h]@3
  int v32; // [sp+5Ch] [bp-34h]@5
  int v33; // [sp+60h] [bp-30h]@46
  int v34; // [sp+64h] [bp-2Ch]@3
  int v35; // [sp+68h] [bp-28h]@5
  int v36; // [sp+6Ch] [bp-24h]@89
  signed int i; // [sp+74h] [bp-1Ch]@12
  int j; // [sp+74h] [bp-1Ch]@64
  signed int k; // [sp+74h] [bp-1Ch]@109
  signed int l; // [sp+74h] [bp-1Ch]@120
  int hero; // [sp+80h] [bp-10h]@3
  int v42; // [sp+84h] [bp-Ch]@1
  int v43; // [sp+88h] [bp-8h]@5
  int v44; // [sp+8Ch] [bp-4h]@64

  thisb = this;
  v42 = 0;
  if ( *(&byte_524758 + curPlayerIdx) )
    sub_485C90(0);
  dword_523ECC = 0;
  *(_DWORD *)a8 = 0;
  *(_DWORD *)a6 = 0;
  dword_4F3084 = 1;
  v34 = 0;
  v9 = (char *)gameObject + 250 * curPlayer->_1[0];
  hero = (int)(v9 + 10180);
  v31 = *(_DWORD *)(v9 + 10205);
  v29 = *(_DWORD *)(v9 + 10209);
  v30 = byte_4F1DC0[4 * a2];
  v28 = byte_4F1DC1[4 * a2];
  dword_524C14 = sub_4C0840((int)(v9 + 10180), a2);
  if ( dword_524C14 )
    dword_5247A8 = 1;
  v10 = usedToCheckForBoatByCastle(thisb, *(_DWORD *)(hero + 25), *(_DWORD *)(hero + 29));
  v11 = (unsigned __int8)tileToTerrainType[*(_WORD *)v10];
  v43 = usedToCheckForBoatByCastle(thisb, v30 + *(_DWORD *)(hero + 25), v28 + *(_DWORD *)(hero + 29));
  v32 = sub_464D00(
          v11,
          a2 & 1,
          *(_DWORD *)(hero + 53),
          *(_BYTE *)(hero + 116),
          (*(_BYTE *)(v10 + 2) >> 1) & 1,
          (*(_BYTE *)(v43 + 2) >> 1) & 1);
  v35 = sub_464D00(
          (unsigned __int8)tileToTerrainType[*(_WORD *)v43],
          0,
          *(_DWORD *)(hero + 53) - v32,
          *(_BYTE *)(hero + 116),
          (*(_BYTE *)(v43 + 2) >> 1) & 1,
          1);
  if ( !a9 && *(_DWORD *)(hero + 53) < v32 )
  {
    *(_DWORD *)a6 = 1;
    *(_DWORD *)(hero + 53) = 0;
    sub_4BFAC0(thisb, 1);
    goto LABEL_95;
  }
  sub_4C3190(1, *(_BYTE *)(hero + 2), *(_DWORD *)(hero + 25), *(_DWORD *)(hero + 29), curPlayerIdx, a3, a2);
  sub_450820((int)thisb, 0);
  *a4 = v30 + *(_DWORD *)(hero + 25);
  *a5 = v28 + *(_DWORD *)(hero + 29);
  if ( thisb->field_27E != a2 )
    sub_4C05E0((int)thisb, a2);
  *(_BYTE *)(hero + 44) = a2;
  if ( *(_BYTE *)(hero + 227) & 0x80 && *(_BYTE *)(v43 + 9) == 28 )
  {
    for ( i = 0; i < 48 && gameObject->probablyArtifactGeneratedRandomly[8 * i + 109] != *(_BYTE *)(hero + 2); ++i )
      ;
    v12 = &gameObject->probablyArtifactGeneratedRandomly[8 * i + 103];
    v13 = usedToCheckForBoatByCastle(thisb, *(_DWORD *)(hero + 25), *(_DWORD *)(hero + 29));
    v12[4] = *(_BYTE *)(v13 + 9);
    v12[5] = *(_WORD *)(v13 + 4) >> 3;
    v12[3] = LOBYTE(thisb->field_27E);
    v12[6] |= 0x80u;
    *(_BYTE *)(v13 + 9) = -85;
    *(_WORD *)(v13 + 4) = *(_WORD *)(v13 + 4) & 7 | 8 * i;
    v12[1] = *(_BYTE *)(hero + 25);
    v12[2] = *(_BYTE *)(hero + 29);
    sub_4BFAC0(thisb, 1);
    sub_447C20(thisb, thisb->viewX, thisb->viewY, 0, 1);
    sub_447A00(thisb, 0, 0);
    thisb->field_272 = 0;
  }
  if ( !(*(_BYTE *)(v43 + 9) & 0x80) || !sub_4C1CB0((int)advManager, hero, a2) )
    goto LABEL_41;
  v19 = *(_BYTE *)(v43 + 9) & 0x7F;
  if ( v19 != 35 )
  {
    if ( v19 == 42 )
    {
      if ( *(_BYTE *)(hero + 227) & 0x80
        && !(gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v43 + 4) >> 8) >> -5)].flags1 & 0x80) )
        goto LABEL_95;
      goto LABEL_33;
    }
    if ( v19 == 43 )
    {
      if ( *(_BYTE *)(hero + 227) & 0x80 )
        goto LABEL_95;
      sub_4BFAC0(thisb, 1);
      thisb->field_272 = 0;
      v14 = playSample("killfade.82m");
      HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 192, 192, 96, 96);
      sub_447C20(thisb, thisb->viewX, thisb->viewY, 0, 1);
      sub_4C7E00(
        HeroWindowManager::instance,
        192,
        192,
        96,
        96,
        (unsigned int)*(&byte_524758 + curPlayerIdx) < 1 ? 50 : -1,
        0,
        0);
      waitForSampleToFinish(-1, v14);
    }
    else
    {
      if ( sub_458D40(v43) )
      {
LABEL_33:
        sub_4BFAC0(thisb, 1);
        sub_447C20(thisb, thisb->viewX, thisb->viewY, 0, 1);
        sub_447A00(thisb, 0, 0);
        *(_DWORD *)(hero + 53) -= v32;
        if ( *(_DWORD *)(hero + 53) < v35 )
          *(_DWORD *)(hero + 53) = 0;
        v34 = v43;
        goto LABEL_95;
      }
    }
    goto LABEL_41;
  }
  if ( gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v43 + 4) >> 8) >> -5)].ownerIdx == curPlayerIdx
    || !Castle::hasGarrison(&gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v43 + 4) >> 8) >> -5)]) )
  {
LABEL_41:
    if ( sub_4C1E00((int)thisb, a2, 0) )
    {
      if ( *(_WORD *)(hero + 45) == 163 )
        gameObject->castles[*(_WORD *)(hero + 47)].visitingHeroIdx = -1;
      if ( thisb->field_A2 )
        *(_WORD *)(2 * (v30 + *(_DWORD *)(hero + 25)) + 2 * mapWidth * (v28 + *(_DWORD *)(hero + 29)) + thisb->field_9E) = 0;
      thisb->field_1FA = 0;
      thisb->field_1F6 = thisb->field_1FA;
      v15 = byte_4F3B10[*(_BYTE *)(hero + 119)];
      v16 = Hero::hasArtifact((Hero *)hero, ARTIFACT_TELESCOPE);
      explore(v30 + thisb->viewX + 7, v28 + thisb->viewY + 7, curPlayerIdx, ((unsigned int)v16 >= 1) + v15);
      thisb->field_2AE = 1;
      v27 = dword_51E188[*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx))];
      v33 = dword_51E1A0[*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx))];
      sub_4BF980((int)thisb, a2);
      if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 4 )
      {
        if ( dword_51E1BC )
          --thisb->field_282;
        dword_51E180 = 0;
        sub_4C2300((int)thisb, v30, v28);
        *(_DWORD *)(hero + 25) += v30;
        *(_DWORD *)(hero + 29) += v28;
        if ( sub_452F20(thisb, 0) )
          sub_447A00(thisb, 0, 0);
        dword_51E1BC = 1 - dword_51E1BC;
      }
      else
      {
        if ( v30 != 1 || v28 != -1 )
        {
          if ( v30 != -1 || v28 != 1 )
          {
            if ( v30 != 1 || v28 != 1 )
            {
              if ( v30 == -1 && v28 == -1 )
              {
                dword_4F4BC0 = *(_DWORD *)(hero + 25) - 1;
                dword_4F4BC4 = *(_DWORD *)(hero + 29);
              }
            }
            else
            {
              dword_4F4BC0 = *(_DWORD *)(hero + 25);
              dword_4F4BC4 = *(_DWORD *)(hero + 29) + 1;
            }
          }
          else
          {
            dword_4F4BC0 = *(_DWORD *)(hero + 25);
            dword_4F4BC4 = *(_DWORD *)(hero + 29) + 1;
          }
        }
        else
        {
          dword_4F4BC0 = *(_DWORD *)(hero + 25) + 1;
          dword_4F4BC4 = *(_DWORD *)(hero + 29);
        }
        fullScreenRelated = 0;
        dword_4F2E80 = 1;
        v44 = 16 / v27;
        for ( j = 0; 2 * v44 > j; ++j )
        {
          if ( v44 == j )
          {
            sub_4C2300((int)thisb, v30, v28);
            *(_DWORD *)(hero + 25) += v30;
            *(_DWORD *)(hero + 29) += v28;
            thisb->field_1F6 = dword_51E1C4[v30];
            thisb->field_1FA = dword_51E1C4[v28];
          }
          v26 = getTickCount();
          if ( j + 1 == 2 * v44 )
          {
            thisb->field_1F6 = 0;
            thisb->field_1FA = 0;
          }
          else
          {
            thisb->field_1F6 += v30 * v27;
            thisb->field_1FA += v28 * v27;
          }
          if ( sub_452F20(thisb, 0) )
          {
            xOff = -1;
            sub_447A00(thisb, 0, 0);
          }
          if ( dword_524C14 )
            sleepUntil(v33 + v26);
        }
        dword_4F4BC4 = -1;
        dword_4F4BC0 = -1;
        dword_4F2E80 = 0;
        sub_4564F0((int)thisb);
        fullScreenRelated = 1;
      }
      *(_DWORD *)(hero + 53) -= v32;
      if ( *(_DWORD *)(hero + 53) < v35 )
      {
        *(_DWORD *)(hero + 53) = 0;
        a3 = 1;
      }
      v42 = sub_42E250(*a4, *a5);
      if ( v42 && !a7 )
        a3 = 1;
      sub_4BFAC0(thisb, a3);
      if ( a7 && a3 && sub_452F20(thisb, 0) )
        sub_447A00(thisb, 0, 0);
      sub_452F60(thisb, thisb->viewX + 7, thisb->viewY + 7, 0);
      v17 = *(_WORD *)usedToCheckForBoatByCastle(thisb, thisb->viewX + 7, thisb->viewY + 7);
      if ( (unsigned __int8)tileToTerrainType[v17] != thisb->field_A6 )
      {
        thisb->field_A6 = (unsigned __int8)tileToTerrainType[v17];
        if ( !*(_DWORD *)&useCDMusic )
          SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisb->field_A6]);
      }
      thisb->field_1FA = 0;
      thisb->field_1F6 = thisb->field_1FA;
      v36 = usedToCheckForBoatByCastle(
              thisb,
              thisb->viewX + *(_DWORD *)&thisb->field_292[0],
              thisb->viewY + *(_DWORD *)&thisb->field_292[8]);
      *a4 = thisb->viewX + *(_DWORD *)&thisb->field_292[0];
      *a5 = thisb->viewY + *(_DWORD *)&thisb->field_292[8];
      if ( *(_BYTE *)(v36 + 9) & 0x80 || *(_BYTE *)(hero + 227) & 0x80 && *(_BYTE *)(v36 + 9) == 28 )
      {
        v34 = v36;
        switch ( *(_BYTE *)(v36 + 9) & 0x7F )
        {
          case 0x38:
          case 0x39:
          case 0x62:
          case 0x63:
          case 0x64:
          case 0x65:
          case 0x66:
          case 0x67:
          case 0x68:
          case 0x69:
          case 0x6A:
          case 0x6B:
          case 0x6C:
          case 0x6D:
          case 0x6E:
          case 0x6F:
          case 0x70:
          case 0x71:
          case 0x72:
          case 0x73:
            v34 = 0;
            break;
          default:
            goto LABEL_95;
        }
      }
    }
    goto LABEL_95;
  }
  sub_4BFAC0(thisb, 1);
  sub_447C20(thisb, thisb->viewX, thisb->viewY, 0, 1);
  sub_447A00(thisb, 0, 0);
  *(_DWORD *)(hero + 53) -= v32;
  if ( *(_DWORD *)(hero + 53) < v35 )
    *(_DWORD *)(hero + 53) = 0;
  v34 = v43;
LABEL_95:
  sub_44AA80((int)thisb, 1, 1);
  dword_4F3084 = 0;
  if ( !a9 && (*(_DWORD *)(hero + 25) != v31 || *(_DWORD *)(hero + 29) != v29) )
  {
    if ( *(&tileExplored[*(_DWORD *)(hero + 25)] + mapWidth * *(_DWORD *)(hero + 29)) & 0x80
      && !(*(_BYTE *)(hero + 227) & 0x80)
      && (!v34 || (*(_BYTE *)(v34 + 9) & 0x7F) != 43) )
    {
      sub_4C1B30(thisb, a8);
      if ( *(_BYTE *)(hero + 3) != curPlayerIdx )
        v34 = 0;
    }
  }
  if ( *(&byte_524758 + curPlayerIdx) )
    sub_485C90(1);
  if ( v42 )
  {
    if ( a7 )
    {
      if ( *(_BYTE *)(v42 + 31) )
      {
        for ( k = 0; k < 7; ++k )
        {
          gameObject->players[curPlayerIdx].resources[k] += *(_DWORD *)(v42 + 4 * k + 1);
          if ( gameObject->players[curPlayerIdx].resources[k] < 0 )
            gameObject->players[curPlayerIdx].resources[k] = 0;
        }
        if ( *(_WORD *)(v42 + 29) != -1 && Hero::numArtifacts((Hero *)hero) < 14 )
          grantArtifact((Hero *)hero, (ARTIFACT)*(_WORD *)(v42 + 29), 1, -1);
        if ( *(_BYTE *)(v42 + 32) )
          *(_BYTE *)(v42 + 37) = 0;
      }
    }
    else
    {
      img1Type = -1;
      img1Arg = 0;
      img2Type = -1;
      img2Arg = 0;
      for ( l = 0; l < 7; ++l )
      {
        v21 = *(_DWORD *)(v42 + 4 * l + 1);
        if ( gameObject->players[curPlayerIdx].resources[l] < -v21 )
          v21 = -gameObject->players[curPlayerIdx].resources[l];
        gameObject->players[curPlayerIdx].resources[l] += *(_DWORD *)(v42 + 4 * l + 1);
        if ( gameObject->players[curPlayerIdx].resources[l] < 0 )
          gameObject->players[curPlayerIdx].resources[l] = 0;
        if ( v21 )
        {
          if ( img1Type != -1 )
          {
            img2Type = img1Type;
            img2Arg = img1Arg;
          }
          img1Type = l;
          img1Arg = v21;
        }
      }
      if ( *(_WORD *)(v42 + 29) != -1 && Hero::numArtifacts((Hero *)hero) < 14 )
      {
        grantArtifact((Hero *)hero, (ARTIFACT)*(_WORD *)(v42 + 29), 1, -1);
        if ( img1Type != -1 )
        {
          img2Type = img1Type;
          img2Arg = img1Arg;
        }
        img1Type = 7;
        img1Arg = *(_WORD *)(v42 + 29);
      }
      if ( *(_BYTE *)(v42 + 32) )
        *(_BYTE *)(v42 + 37) = 0;
      if ( img1Type >= 0 && img1Type <= 6 && img1Arg < 0 )
        img1Arg -= 100000;
      if ( img2Type >= 0 && img2Type <= 6 && img2Arg < 0 )
        img2Arg -= 100000;
      display_message_window((char *)(v42 + 49), 1, -1, -1, img1Type, img1Arg, img2Type, img2Arg, -1, 0);
      dword_523ECC = 1;
    }
  }
  return v34;
}
