{
  int v1; // ecx@44
  int spriteIdx; // [sp+18h] [bp-Ch]@9
  int spriteIdxa; // [sp+18h] [bp-Ch]@18
  int a4; // [sp+1Ch] [bp-8h]@6
  int a3; // [sp+20h] [bp-4h]@6
  int a3a; // [sp+20h] [bp-4h]@9

  if ( bShowIt && !bSpecialHideCursor )
  {
    if ( gbDrawSavedCursor )
    {
      this->field_27E = S1cursorDirection;
      this->field_282 = S1cursorBaseFrame;
      this->field_286 = S1cursorFrameCount;
      this->field_28A = S1cursorCycle;
      this->field_28E = S1cursorTurning;
    }
    a3 = this->field_1F6 + 224;
    a4 = this->field_1FA + 255;
    if ( this->field_27A == 6 )
      a4 = this->field_1FA + 245;
    if ( this->field_282 & 0x80 )
    {
      a3a = this->field_1F6 + 256;
      spriteIdx = this->field_286 + (this->field_282 & 0x7F);
      if ( this->field_27A == 6 && !(advManager::GetCell(this, this->viewX + 7, this->viewY + 7)->field_8 & 4) )
        FlipIconToBitmap(this->frothIcon, gpWindowManager->screenBuffer, a3a, a4, spriteIdx, 1, 0, 0, 480, 480, 0);
      FlipIconToBitmap(
        (icon *)this->heroIcons[this->field_27A],
        gpWindowManager->screenBuffer,
        a3a,
        a4,
        spriteIdx,
        1,
        0,
        0,
        480,
        480,
        0);
      if ( this->field_27A == 6 )
      {
        FlipIconToBitmap(
          (icon *)this->flagIcons2[gpCurPlayer->color],
          gpWindowManager->screenBuffer,
          a3a,
          a4,
          spriteIdx,
          0,
          0,
          0,
          0,
          0,
          0);
      }
      else
      {
        if ( !this->field_28A )
          spriteIdx = (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
                    + (this->field_282 & 0x7F)
                    - ((unsigned __int64)this->field_202 >> 32)
                    + 56;
        FlipIconToBitmap(
          (icon *)this->flagIcons1[gpCurPlayer->color],
          gpWindowManager->screenBuffer,
          a3a,
          a4,
          spriteIdx,
          1,
          0,
          0,
          480,
          480,
          0);
        ++this->field_206;
      }
    }
    else
    {
      spriteIdxa = this->field_286 + this->field_282;
      if ( this->field_27A == 6 && !(advManager::GetCell(this, this->viewX + 7, this->viewY + 7)->field_8 & 4) )
        IconToBitmap(this->frothIcon, gpWindowManager->screenBuffer, a3, a4, spriteIdxa, 1, 0, 0, 0x1E0u, 480, 0);
      IconToBitmap(
        (icon *)this->heroIcons[this->field_27A],
        gpWindowManager->screenBuffer,
        a3,
        a4,
        spriteIdxa,
        1,
        0,
        0,
        0x1E0u,
        480,
        0);
      if ( this->field_27A == 6 )
      {
        IconToBitmap(
          (icon *)this->flagIcons2[gpCurPlayer->color],
          gpWindowManager->screenBuffer,
          a3,
          a4,
          spriteIdxa,
          0,
          0,
          0,
          0,
          0,
          0);
      }
      else
      {
        if ( !this->field_28A )
          spriteIdxa = (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
                     + (this->field_282 & 0x7F)
                     - ((unsigned __int64)this->field_202 >> 32)
                     + 56;
        IconToBitmap(
          (icon *)this->flagIcons1[gpCurPlayer->color],
          gpWindowManager->screenBuffer,
          a3,
          a4,
          spriteIdxa,
          1,
          0,
          0,
          0x1E0u,
          480,
          0);
        ++this->field_206;
      }
    }
    if ( this->field_28A && *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) != 4 )
    {
      ++this->field_286;
      if ( *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) == 3
        && (this->field_286 == 4 || this->field_286 == 1) )
        ++this->field_286;
      if ( !*((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) )
      {
        EveryOther = 1 - EveryOther;
        if ( EveryOther )
          --this->field_286;
      }
    }
    if ( this->field_286 >= 8 )
      this->field_286 = 0;
    if ( !this->field_28E )
    {
      if ( !this->field_286 )
        hOldWalkSample = hNewWalkSample;
      if ( this->field_286 == 3
        || *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) == 4 && !bMoveSoundMade )
      {
        bMoveSoundMade = 1;
        if ( !EveryOther )
        {
          v1 = advManager::GetCell(this, this->viewX + 7, this->viewY + 7)->tileType;
          hNewWalkSample = (int)soundManager::MemorySample(
                                  gpSoundManager,
                                  this->walkSamples[(unsigned __int8)giGroundToTerrain[v1]]);
        }
      }
    }
    if ( !gbDrawSavedCursor )
    {
      S1cursorDirection = this->field_27E;
      S1cursorBaseFrame = this->field_282;
      S1cursorFrameCount = this->field_286;
      S1cursorCycle = this->field_28A;
      S1cursorTurning = this->field_28E;
    }
  }
}