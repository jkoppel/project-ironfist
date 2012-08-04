{
  int result; // eax@15
  signed int v3; // [sp+10h] [bp-1Ch]@30
  signed int v4; // [sp+14h] [bp-18h]@13
  int v5; // [sp+18h] [bp-14h]@18
  int spriteIdx; // [sp+20h] [bp-Ch]@9
  int spriteIdxa; // [sp+20h] [bp-Ch]@34
  int a4; // [sp+24h] [bp-8h]@6
  int a3; // [sp+28h] [bp-4h]@6

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
      spriteIdx = this->field_286 + (this->field_282 & 0x7F);
      if ( this->field_276 && this->field_27A == 6 )
      {
        if ( spriteIdx < 9 || spriteIdx >= 36 )
          v4 = 0;
        else
          v4 = 36;
        result = IconToBitmap(
                   this->boatShadowIcon,
                   gpWindowManager->screenBuffer,
                   this->field_1F6 + 224,
                   a4,
                   v4 + spriteIdx,
                   1,
                   0,
                   0,
                   0x1E0u,
                   480,
                   0);
      }
      else
      {
        result = (int)this;
        if ( this->field_276 )
        {
          result = (int)this;
          if ( this->field_27A != 6 )
          {
            v5 = this->field_286 + (this->field_282 & 0x7F);
            if ( spriteIdx == 51 )
              v5 = 56;
            if ( v5 == 50 )
              v5 = 57;
            if ( v5 == 49 )
              v5 = 58;
            if ( v5 == 47 )
              v5 = 55;
            if ( v5 == 46 )
              v5 = 55;
            if ( v5 < 9 || v5 >= 36 )
              v3 = 0;
            else
              v3 = 50;
            result = IconToBitmap(
                       this->shadowIcon,
                       gpWindowManager->screenBuffer,
                       this->field_1F6 + 224,
                       a4,
                       v3 + v5,
                       1,
                       0,
                       0,
                       0x1E0u,
                       480,
                       0);
          }
        }
      }
    }
    else
    {
      spriteIdxa = this->field_286 + this->field_282;
      if ( this->field_276 && this->field_27A == 6 )
      {
        result = IconToBitmap(
                   this->boatShadowIcon,
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
      }
      else
      {
        result = (int)this;
        if ( this->field_276 )
        {
          result = (int)this;
          if ( this->field_27A != 6 )
            result = IconToBitmap(
                       this->shadowIcon,
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
        }
      }
    }
    if ( !gbDrawSavedCursor )
    {
      S1cursorDirection = this->field_27E;
      S1cursorBaseFrame = this->field_282;
      S1cursorFrameCount = this->field_286;
      S1cursorCycle = this->field_28A;
      result = this->field_28E;
      S1cursorTurning = this->field_28E;
    }
  }
  return result;
}