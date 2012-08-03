{
  int v1; // eax@2
  __int16 v2; // ax@4
  int v3; // eax@4
  int v4; // eax@5
  __int16 v5; // ax@11
  int v7; // [sp+0h] [bp-33Ch]@0
  void *v8; // [sp+Ch] [bp-330h]@1
  char v9; // [sp+10h] [bp-32Ch]@2
  int v10; // [sp+30h] [bp-30Ch]@1
  int v11; // [sp+34h] [bp-308h]@1
  char v12; // [sp+3Ch] [bp-300h]@1

  v8 = this;
  mouseManager::HideColorPointer(gpMouseManager);
  memcpy(&v12, gpBufferPalette->contents, 0x300u);
  gpWindowManager->field_56 = 0;
  congratsText = (char *)BaseAlloc(0x1F4u, "F:\\h2xsrc\\Source\\KB.CPP", word_50D9D4 + 9);
  v11 = CalcBaseScore(giCurTurn);
  v10 = v11 * gpGame->field_0 / 100;
  soundManager::PlayAmbientMusic(gpSoundManager, -1, 0, -1, v7);
  if ( v8 == (void *)1 )
  {
    v1 = GetMonType(v10, 1);
    sprintf(&v9, gArmyNames[v1]);
  }
  else if ( v8 == (void *)2 )
  {
    v2 = ExpCampaign::Days((int)&xCampaign);
    v3 = GetMonType(v2, 2);
    sprintf(&v9, gArmyNames[v3]);
  }
  else
  {
    v4 = GetMonType(*(_WORD *)&gpGame->_1[181], v8);
    sprintf(&v9, gArmyNames[v4]);
  }
  v9 -= 32;
  if ( gpGame->_10[32] )
    sprintf(&v9, "Cheater!!!");
  if ( v8 == (void *)1 )
  {
    sprintf(
      congratsText,
      "Congratulations!\n\nDays: %d\nBase Score: %d\nDifficulty: %d\n\nScore: %d\n\nRating:\n%s\n",
      giCurTurn,
      v11,
      gpGame->field_0,
      v10,
      &v9);
  }
  else if ( v8 == (void *)2 )
  {
    v5 = ExpCampaign::Days((int)&xCampaign);
    sprintf(congratsText, "Congratulations!\n\nDays: %d\n\nRating:\n%s\n", v5, &v9);
  }
  else
  {
    sprintf(congratsText, "Congratulations!\n\nDays: %d\n\nRating:\n%s\n", *(_WORD *)&gpGame->_1[181], &v9);
  }
  PlaySmacker(2);
  memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
  SmackFade(gpBufferPalette->contents, &v12);
  memcpy(gPalette->contents, &v12, 0x300u);
  memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
  mouseManager::ShowColorPointer(gpMouseManager);
  AddScoreToHighScore(v10, giCurTurn, gpGame->field_0, 1, &gpGame->_3[13]);
  BaseFree(congratsText, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D9D4 + 78);
  congratsText = 0;
  gpWindowManager->field_56 = 1;
  return memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
}