void __thiscall AdvManager::drawMainHero(AdvManager *this)
{
  int v1; // ecx@44
  int spriteIdx; // [sp+18h] [bp-Ch]@9
  int spriteIdxa; // [sp+18h] [bp-Ch]@18
  int a4; // [sp+1Ch] [bp-8h]@6
  int a3; // [sp+20h] [bp-4h]@6
  int a3a; // [sp+20h] [bp-4h]@9

  if ( dword_524C14 && !dword_523F0C )
  {
    if ( dword_4F2AE4 )
    {
      this->field_27E = dword_532DE4;
      this->field_282 = dword_532DB4;
      this->field_286 = dword_532DB0;
      this->field_28A = dword_532DE8;
      this->field_28E = dword_532DEC;
    }
    a3 = this->field_1F6 + 224;
    a4 = this->field_1FA + 255;
    if ( this->field_27A == 6 )
      a4 = this->field_1FA + 245;
    if ( this->field_282 & 0x80 )
    {
      a3a = this->field_1F6 + 256;
      spriteIdx = this->field_286 + (this->field_282 & 0x7F);
      if ( this->field_27A == 6 && !(AdvManager::getTile(this, this->viewX + 7, this->viewY + 7)->field_8 & 4) )
        rasterizeMirrored(
          this->frothIcon,
          HeroWindowManager::instance->screenBuffer,
          a3a,
          a4,
          spriteIdx,
          1,
          0,
          0,
          480,
          480,
          0);
      rasterizeMirrored(
        (Icon *)this->heroIcons[this->field_27A],
        HeroWindowManager::instance->screenBuffer,
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
        rasterizeMirrored(
          (Icon *)this->flagIcons2[curPlayer->color],
          HeroWindowManager::instance->screenBuffer,
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
        rasterizeMirrored(
          (Icon *)this->flagIcons1[curPlayer->color],
          HeroWindowManager::instance->screenBuffer,
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
      if ( this->field_27A == 6 && !(AdvManager::getTile(this, this->viewX + 7, this->viewY + 7)->field_8 & 4) )
        rasterize(
          this->frothIcon,
          HeroWindowManager::instance->screenBuffer,
          a3,
          a4,
          spriteIdxa,
          1,
          0,
          0,
          0x1E0u,
          480,
          0);
      rasterize(
        (Icon *)this->heroIcons[this->field_27A],
        HeroWindowManager::instance->screenBuffer,
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
        rasterize(
          (Icon *)this->flagIcons2[curPlayer->color],
          HeroWindowManager::instance->screenBuffer,
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
        rasterize(
          (Icon *)this->flagIcons1[curPlayer->color],
          HeroWindowManager::instance->screenBuffer,
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
    if ( this->field_28A && *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) != 4 )
    {
      ++this->field_286;
      if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 3
        && (this->field_286 == 4 || this->field_286 == 1) )
        ++this->field_286;
      if ( !*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) )
      {
        dword_51E1BC = 1 - dword_51E1BC;
        if ( dword_51E1BC )
          --this->field_286;
      }
    }
    if ( this->field_286 >= 8 )
      this->field_286 = 0;
    if ( !this->field_28E )
    {
      if ( !this->field_286 )
        dword_51E1B4 = dword_51E1B8;
      if ( this->field_286 == 3
        || *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 4 && !dword_51E180 )
      {
        dword_51E180 = 1;
        if ( !dword_51E1BC )
        {
          v1 = AdvManager::getTile(this, this->viewX + 7, this->viewY + 7)->tileType;
          dword_51E1B8 = (int)SoundManager::playSample(
                                soundManager,
                                this->walkSamples[(unsigned __int8)tileToTerrainType[v1]]);
        }
      }
    }
    if ( !dword_4F2AE4 )
    {
      dword_532DE4 = this->field_27E;
      dword_532DB4 = this->field_282;
      dword_532DB0 = this->field_286;
      dword_532DE8 = this->field_28A;
      dword_532DEC = this->field_28E;
    }
  }
}
