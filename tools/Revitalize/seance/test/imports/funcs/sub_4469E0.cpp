{
  __int16 v3; // ax@21
  __int16 v4; // ax@21
  int thisa; // [sp+Ch] [bp-44h]@1
  char v6; // [sp+1Ch] [bp-34h]@29
  int v7; // [sp+3Ch] [bp-14h]@9
  int i; // [sp+40h] [bp-10h]@48
  sample_resource res; // [sp+44h] [bp-Ch]@1
  char *hero; // [sp+4Ch] [bp-4h]@1

  thisa = (int)this;
  res = stru_5230F8;
  hero = (char *)&gameObject->heroes[curPlayer->_1[0]];
  if ( *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[20] != *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[16] )
  {
    if ( dword_524810[curPlayerIdx] )
    {
      display_message_window(
        "Digging for artifacts requires a whole day, try again tomorrow.",
        1,
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
LABEL_52:
    curPlayer->field_40 = 0;
    return 1;
  }
  if ( Hero::numArtifacts((Hero *)hero) == 14 )
  {
    if ( dword_524810[curPlayerIdx] )
    {
      display_message_window(
        "Searching for the Ultimate Artifact is fruitless.  Your hero could not carry it even if he found it - all his artifact slots are full.",
        1,
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
    goto LABEL_52;
  }
  sub_450820(thisa, 0);
  sub_448110((AdvManager *)thisa, 0);
  sub_447A00((void *)thisa, 0, 0);
  if ( (_DWORD)a2 == -1 )
  {
    LODWORD(a2) = *(_DWORD *)(thisa + 470) + 7;
    HIDWORD(a2) = *(_DWORD *)(thisa + 474) + 7;
  }
  v7 = usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2));
  if ( *(_BYTE *)(v7 + 3) != 255 && ((*(_BYTE *)(v7 + 2) >> 2) & 0x3F) != 47 || *(_BYTE *)(v7 + 7) != 255 )
  {
    if ( dword_524810[curPlayerIdx] )
    {
      display_message_window("Try searching on clear ground.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      return 1;
    }
    goto LABEL_52;
  }
  if ( !tileToTerrainType[*(_WORD *)v7] )
  {
    if ( dword_524810[curPlayerIdx] )
    {
      display_message_window("Try looking on land!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      return 1;
    }
    goto LABEL_52;
  }
  if ( dword_524810[curPlayerIdx] )
    res = playSample("DIGSOUND.82M");
  if ( *(_BYTE *)(v7 + 3) == 255 || ((*(_BYTE *)(v7 + 2) >> 2) & 0x3F) == 47 )
  {
    *(_BYTE *)(v7 + 2) = *(_BYTE *)(v7 + 2) & 3 | 0xE0;
    *(_BYTE *)(v7 + 3) = -116;
    v3 = *(_WORD *)(v7 + 4);
    LOBYTE(v3) = v3 | 1;
    *(_WORD *)(v7 + 4) = v3;
    v4 = *(_WORD *)(v7 + 4);
    LOBYTE(v4) = v4 | 2;
    *(_WORD *)(v7 + 4) = v4;
    *(_BYTE *)(v7 + 8) |= 0x80u;
  }
  sub_448110((AdvManager *)thisa, 0);
  sub_447A00((void *)thisa, 0, 0);
  if ( gameObject->_10[24] != (_DWORD)a2 || gameObject->_10[25] != HIDWORD(a2) || gameObject->_10[26] == -1 )
  {
    if ( dword_524810[curPlayerIdx] )
      display_message_window("Nothing here.\nWhere could it be?", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  else
  {
    if ( Hero::numArtifacts((Hero *)hero) < 14 )
    {
      v6 = 0;
      if ( byte_5304A0 )
        v6 = sub_4729B0((int)&unk_530450);
      if ( dword_524810[curPlayerIdx] )
      {
        SoundManager::couldBePlayCDTrack(soundManager, 41);
        if ( v6 )
          sprintf(
            globBuf,
            "%s%s",
            "Congratulations! After spending many hours digging here, you have uncovered the ",
            artifactNames[98]);
        else
          sprintf(
            globBuf,
            "%s%s",
            "Congratulations! After spending many hours digging here, you have uncovered the ",
            artifactNames[gameObject->_10[26]]);
        display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( v6 )
          displayArtifactDescription(ARTIFACT_SPHERE_OF_NEGATION, 0, -1);
        else
          displayArtifactDescription((ARTIFACT)gameObject->_10[26], 0, -1);
        SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(thisa + 166)]);
      }
      if ( v6 )
        grantArtifact((Hero *)hero, ARTIFACT_SPHERE_OF_NEGATION, 1, -1);
      else
        grantArtifact((Hero *)hero, (ARTIFACT)gameObject->_10[26], 1, -1);
      gameObject->_10[26] = -1;
    }
    else
    {
      if ( dword_524810[curPlayerIdx] )
        display_message_window("You have no room to carry another artifact!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  if ( dword_524810[curPlayerIdx] )
    waitForSampleToFinish(-1, res);
  for ( i = 0; gameObject->numPlayers > i; ++i )
    sub_4190F0(i);
  *(_DWORD *)(hero + 53) = 0;
  sub_44D440((void *)thisa, 1, 1, 1);
  sub_455140((void *)thisa);
  sub_4456D0(0, 0);
  checkGameEnd(0, 0);
  return 1;
}
