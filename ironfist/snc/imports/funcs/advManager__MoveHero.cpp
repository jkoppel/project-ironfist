{
  char *v9; // eax@3
  mapCell *v10; // ST90_4@5
  signed int v11; // ST74_4@5
  char *v12; // ST5C_4@16
  mapCell *v13; // eax@16
  sample_resource v14; // ST98_8@21
  int v15; // ebx@46
  signed int v16; // eax@46
  int v17; // edx@64
  int v18; // ecx@86
  int v20; // [sp+10h] [bp-80h]@19
  int v22; // [sp+20h] [bp-70h]@122
  int img2Arg; // [sp+24h] [bp-6Ch]@120
  int img2Type; // [sp+28h] [bp-68h]@120
  int img1Type; // [sp+2Ch] [bp-64h]@120
  int img1Arg; // [sp+30h] [bp-60h]@120
  int v27; // [sp+34h] [bp-5Ch]@68
  signed int v28; // [sp+44h] [bp-4Ch]@46
  int v29; // [sp+48h] [bp-48h]@3
  int v30; // [sp+4Ch] [bp-44h]@3
  int v31; // [sp+50h] [bp-40h]@3
  int v32; // [sp+58h] [bp-38h]@3
  int v33; // [sp+5Ch] [bp-34h]@5
  int v34; // [sp+60h] [bp-30h]@46
  mapCell *v35; // [sp+64h] [bp-2Ch]@3
  int v36; // [sp+68h] [bp-28h]@5
  mapCell *v37; // [sp+6Ch] [bp-24h]@89
  signed int i; // [sp+74h] [bp-1Ch]@12
  int j; // [sp+74h] [bp-1Ch]@64
  signed int k; // [sp+74h] [bp-1Ch]@109
  signed int l; // [sp+74h] [bp-1Ch]@120
  int hro; // [sp+80h] [bp-10h]@3
  int v43; // [sp+84h] [bp-Ch]@1
  int v44; // [sp+88h] [bp-8h]@5
  int v45; // [sp+8Ch] [bp-4h]@64

  v43 = 0;
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
    SetNoDialogMenus(0);
  gbHitEvent = 0;
  *(_DWORD *)a8 = 0;
  *(_DWORD *)a6 = 0;
  gbHeroMoving = 1;
  v35 = 0;
  v9 = (char *)gpGame + 250 * gpCurPlayer->curHeroIdx;
  hro = (int)(v9 + 10180);
  v32 = *(_DWORD *)(v9 + 10205);
  v30 = *(_DWORD *)(v9 + 10209);
  v31 = normalDirTable[4 * a2];
  v29 = byte_4F1DC1[4 * a2];
  bShowIt = advManager::GetMoveShowIt((int)(v9 + 10180), a2);
  if ( bShowIt )
    gbMoveShown = 1;
  v10 = advManager::GetCell(this, *(_DWORD *)(hro + 25), *(_DWORD *)(hro + 29));
  v11 = (unsigned __int8)giGroundToTerrain[v10->tileType];
  v44 = (int)advManager::GetCell(this, v31 + *(_DWORD *)(hro + 25), v29 + *(_DWORD *)(hro + 29));
  v33 = CalcTerrainCost(
          v11,
          a2 & 1,
          *(_DWORD *)(hro + 53),
          *(_BYTE *)(hro + 116),
          (LOBYTE(v10->field_2) >> 1) & 1,
          (*(_BYTE *)(v44 + 2) >> 1) & 1);
  v36 = CalcTerrainCost(
          (unsigned __int8)giGroundToTerrain[*(_WORD *)v44],
          0,
          *(_DWORD *)(hro + 53) - v33,
          *(_BYTE *)(hro + 116),
          (*(_BYTE *)(v44 + 2) >> 1) & 1,
          1);
  if ( !a9 && *(_DWORD *)(hro + 53) < v33 )
  {
    *(_DWORD *)a6 = 1;
    *(_DWORD *)(hro + 53) = 0;
    advManager::StopCursor(this, 1);
    goto LABEL_95;
  }
  SendMapChange(1, *(_BYTE *)(hro + 2), *(_DWORD *)(hro + 25), *(_DWORD *)(hro + 29), giCurPlayer, a3, a2);
  advManager::MobilizeCurrHero(this, 0);
  *a4 = v31 + *(_DWORD *)(hro + 25);
  *a5 = v29 + *(_DWORD *)(hro + 29);
  if ( this->field_27E != a2 )
    advManager::TurnTo((int)this, a2);
  *(_BYTE *)(hro + 44) = a2;
  if ( *(_BYTE *)(hro + 227) & 0x80 && *(_BYTE *)(v44 + 9) == 28 )
  {
    for ( i = 0; i < 48 && gpGame->probablyArtifactGeneratedRandomly[8 * i + 109] != *(_BYTE *)(hro + 2); ++i )
      ;
    v12 = &gpGame->probablyArtifactGeneratedRandomly[8 * i + 103];
    v13 = advManager::GetCell(this, *(_DWORD *)(hro + 25), *(_DWORD *)(hro + 29));
    v12[4] = v13->objType;
    v12[5] = v13->flags >> 3;
    v12[3] = LOBYTE(this->field_27E);
    v12[6] |= 0x80u;
    v13->objType = -85;
    v13->flags = v13->flags & 7 | 8 * i;
    v12[1] = *(_BYTE *)(hro + 25);
    v12[2] = *(_BYTE *)(hro + 29);
    advManager::StopCursor(this, 1);
    advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
    advManager::UpdateScreen(this, 0, 0);
    this->field_272 = 0;
  }
  if ( !(*(_BYTE *)(v44 + 9) & 0x80) || !advManager::ValidMoveWithEvent((int)gpAdvManager, hro, a2) )
    goto LABEL_41;
  v20 = *(_BYTE *)(v44 + 9) & 0x7F;
  if ( v20 != 35 )
  {
    if ( v20 == 42 )
    {
      if ( *(_BYTE *)(hro + 227) & 0x80
        && !(gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v44 + 4) >> 8) >> -5)].flags1 & 0x80) )
        goto LABEL_95;
      goto LABEL_33;
    }
    if ( v20 == 43 )
    {
      if ( *(_BYTE *)(hro + 227) & 0x80 )
        goto LABEL_95;
      advManager::StopCursor(this, 1);
      this->field_272 = 0;
      v14 = LoadPlaySample("killfade.82m");
      heroWindowManager::SaveFizzleSource(gpWindowManager, 192, 192, 96, 96);
      advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
      heroWindowManager::FizzleForward(
        gpWindowManager,
        192,
        192,
        96,
        96,
        (unsigned int)*(&gbThisNetHumanPlayer + giCurPlayer) < 1 ? 50 : -1,
        0,
        0);
      WaitEndSample(-1, v14);
    }
    else if ( StopOnTrigger(v44) )
    {
LABEL_33:
      advManager::StopCursor(this, 1);
      advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
      advManager::UpdateScreen(this, 0, 0);
      *(_DWORD *)(hro + 53) -= v33;
      if ( *(_DWORD *)(hro + 53) < v36 )
        *(_DWORD *)(hro + 53) = 0;
      v35 = (mapCell *)v44;
      goto LABEL_95;
    }
    goto LABEL_41;
  }
  if ( gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v44 + 4) >> 8) >> -5)].ownerIdx == giCurPlayer
    || !town::HasGarrison(&gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v44 + 4) >> 8) >> -5)]) )
  {
LABEL_41:
    if ( advManager::ValidMove((int)this, a2, 0) )
    {
      if ( *(_WORD *)(hro + 45) == 163 )
        gpGame->castles[*(_WORD *)(hro + 47)].visitingHeroIdx = -1;
      if ( this->field_A2 )
        *(_WORD *)(2 * (v31 + *(_DWORD *)(hro + 25))
                 + 2 * MAP_WIDTH * (v29 + *(_DWORD *)(hro + 29))
                 + this->sizeOfSomethingMapRelated) = 0;
      this->field_1FA = 0;
      this->field_1F6 = this->field_1FA;
      v15 = giVisRange[*(_BYTE *)(hro + 119)];
      v16 = hero::HasArtifact((hero *)hro, ARTIFACT_TELESCOPE);
      game::SetVisibility(v31 + this->viewX + 7, v29 + this->viewY + 7, giCurPlayer, ((unsigned int)v16 >= 1) + v15);
      this->field_2AE = 1;
      v28 = dword_51E188[*((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer))];
      v34 = giStepDelay[*((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer))];
      advManager::StartCursor((int)this, a2);
      if ( *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) == 4 )
      {
        if ( EveryOther )
          --this->field_282;
        bMoveSoundMade = 0;
        advManager::MoveOrigin((int)this, v31, v29);
        *(_DWORD *)(hro + 25) += v31;
        *(_DWORD *)(hro + 29) += v29;
        if ( advManager::ComboDraw(this, 0) )
          advManager::UpdateScreen(this, 0, 0);
        EveryOther = 1 - EveryOther;
      }
      else
      {
        if ( v31 != 1 || v29 != -1 )
        {
          if ( v31 != -1 || v29 != 1 )
          {
            if ( v31 != 1 || v29 != 1 )
            {
              if ( v31 == -1 && v29 == -1 )
              {
                giDeferObjDrawX = *(_DWORD *)(hro + 25) - 1;
                giDeferObjDrawY = *(_DWORD *)(hro + 29);
              }
            }
            else
            {
              giDeferObjDrawX = *(_DWORD *)(hro + 25);
              giDeferObjDrawY = *(_DWORD *)(hro + 29) + 1;
            }
          }
          else
          {
            giDeferObjDrawX = *(_DWORD *)(hro + 25);
            giDeferObjDrawY = *(_DWORD *)(hro + 29) + 1;
          }
        }
        else
        {
          giDeferObjDrawX = *(_DWORD *)(hro + 25) + 1;
          giDeferObjDrawY = *(_DWORD *)(hro + 29);
        }
        gbEnlargeScreenBlit = 0;
        dword_4F2E80 = 1;
        v17 = 16 % v28;
        v45 = 16 / v28;
        for ( j = 0; 2 * v45 > j; ++j )
        {
          if ( v45 == j )
          {
            advManager::MoveOrigin((int)this, v31, v29);
            *(_DWORD *)(hro + 25) += v31;
            *(_DWORD *)(hro + 29) += v29;
            this->field_1F6 = dword_51E1C4[v31];
            this->field_1FA = dword_51E1C4[v29];
          }
          v27 = KBTickCount();
          if ( j + 1 == 2 * v45 )
          {
            this->field_1F6 = 0;
            this->field_1FA = 0;
          }
          else
          {
            this->field_1F6 += v31 * v28;
            this->field_1FA += v29 * v28;
          }
          if ( advManager::ComboDraw(this, 0) )
          {
            giLimitUpdMinX = -1;
            advManager::UpdateScreen(this, 0, 0);
          }
          if ( bShowIt )
            DelayTilMilli(v34 + v27);
        }
        giDeferObjDrawY = -1;
        giDeferObjDrawX = -1;
        dword_4F2E80 = 0;
        advManager::DrawAdventureBorder((int)this, v17);
        gbEnlargeScreenBlit = 1;
      }
      *(_DWORD *)(hro + 53) -= v33;
      if ( *(_DWORD *)(hro + 53) < v36 )
      {
        *(_DWORD *)(hro + 53) = 0;
        a3 = 1;
      }
      v43 = GetMapEvent(*a4, *a5);
      if ( v43 && !a7 )
        a3 = 1;
      advManager::StopCursor(this, a3);
      if ( a7 && a3 && advManager::ComboDraw(this, 0) )
        advManager::UpdateScreen(this, 0, 0);
      advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 0);
      v18 = advManager::GetCell(this, this->viewX + 7, this->viewY + 7)->tileType;
      if ( (unsigned __int8)giGroundToTerrain[v18] != this->currentTerrain )
      {
        this->currentTerrain = (unsigned __int8)giGroundToTerrain[v18];
        if ( !*(_DWORD *)&useCDMusic )
          soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
      }
      this->field_1FA = 0;
      this->field_1F6 = this->field_1FA;
      v37 = advManager::GetCell(
              this,
              this->viewX + *(_DWORD *)&this->field_292[0],
              this->viewY + *(_DWORD *)&this->field_292[8]);
      *a4 = this->viewX + *(_DWORD *)&this->field_292[0];
      *a5 = this->viewY + *(_DWORD *)&this->field_292[8];
      if ( v37->objType & 0x80 || *(_BYTE *)(hro + 227) & 0x80 && v37->objType == 28 )
      {
        v35 = v37;
        switch ( v37->objType & 0x7F )
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
            v35 = 0;
            break;
          default:
            goto LABEL_95;
        }
      }
    }
    goto LABEL_95;
  }
  advManager::StopCursor(this, 1);
  advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
  advManager::UpdateScreen(this, 0, 0);
  *(_DWORD *)(hro + 53) -= v33;
  if ( *(_DWORD *)(hro + 53) < v36 )
    *(_DWORD *)(hro + 53) = 0;
  v35 = (mapCell *)v44;
LABEL_95:
  advManager::UpdateRadar((int)this, 1, 1);
  gbHeroMoving = 0;
  if ( !a9 && (*(_DWORD *)(hro + 25) != v32 || *(_DWORD *)(hro + 29) != v30) )
  {
    if ( *(&mapExtra[*(_DWORD *)(hro + 25)] + MAP_WIDTH * *(_DWORD *)(hro + 29)) & 0x80
      && !(*(_BYTE *)(hro + 227) & 0x80)
      && (!v35 || (v35->objType & 0x7F) != 43) )
    {
      advManager::CheckAdjacentMon(this, a8);
      if ( *(_BYTE *)(hro + 3) != giCurPlayer )
        v35 = 0;
    }
  }
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
    SetNoDialogMenus(1);
  if ( v43 )
  {
    if ( a7 )
    {
      if ( *(_BYTE *)(v43 + 31) )
      {
        for ( k = 0; k < 7; ++k )
        {
          gpGame->players[giCurPlayer].resources[k] += *(_DWORD *)(v43 + 4 * k + 1);
          if ( gpGame->players[giCurPlayer].resources[k] < 0 )
            gpGame->players[giCurPlayer].resources[k] = 0;
        }
        if ( *(_WORD *)(v43 + 29) != -1 && hero::NumArtifacts((hero *)hro) < 14 )
          GiveArtifact((hero *)hro, (ARTIFACT)*(_WORD *)(v43 + 29), 1, -1);
        if ( *(_BYTE *)(v43 + 32) )
          *(_BYTE *)(v43 + 37) = 0;
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
        v22 = *(_DWORD *)(v43 + 4 * l + 1);
        if ( gpGame->players[giCurPlayer].resources[l] < -v22 )
          v22 = -gpGame->players[giCurPlayer].resources[l];
        gpGame->players[giCurPlayer].resources[l] += *(_DWORD *)(v43 + 4 * l + 1);
        if ( gpGame->players[giCurPlayer].resources[l] < 0 )
          gpGame->players[giCurPlayer].resources[l] = 0;
        if ( v22 )
        {
          if ( img1Type != -1 )
          {
            img2Type = img1Type;
            img2Arg = img1Arg;
          }
          img1Type = l;
          img1Arg = v22;
        }
      }
      if ( *(_WORD *)(v43 + 29) != -1 && hero::NumArtifacts((hero *)hro) < 14 )
      {
        GiveArtifact((hero *)hro, (ARTIFACT)*(_WORD *)(v43 + 29), 1, -1);
        if ( img1Type != -1 )
        {
          img2Type = img1Type;
          img2Arg = img1Arg;
        }
        img1Type = 7;
        img1Arg = *(_WORD *)(v43 + 29);
      }
      if ( *(_BYTE *)(v43 + 32) )
        *(_BYTE *)(v43 + 37) = 0;
      if ( img1Type >= 0 && img1Type <= 6 && img1Arg < 0 )
        img1Arg -= 100000;
      if ( img2Type >= 0 && img2Type <= 6 && img2Arg < 0 )
        img2Arg -= 100000;
      NormalDialog((char *)(v43 + 49), 1, -1, -1, img1Type, img1Arg, img2Type, img2Arg, -1, 0);
      gbHitEvent = 1;
    }
  }
  return v35;
}