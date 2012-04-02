void __thiscall sub_4BFBE0(int this)
{
  int v1; // ecx@44
  int thisa; // [sp+Ch] [bp-18h]@1
  int spriteIdx; // [sp+18h] [bp-Ch]@9
  int spriteIdxa; // [sp+18h] [bp-Ch]@18
  int a4; // [sp+1Ch] [bp-8h]@6
  int a3; // [sp+20h] [bp-4h]@6
  int a3a; // [sp+20h] [bp-4h]@9

  thisa = this;
  if ( dword_524C14 && !dword_523F0C )
  {
    if ( dword_4F2AE4 )
    {
      *(_DWORD *)(this + 638) = dword_532DE4;
      *(_DWORD *)(this + 642) = dword_532DB4;
      *(_DWORD *)(this + 646) = dword_532DB0;
      *(_DWORD *)(this + 650) = dword_532DE8;
      *(_DWORD *)(this + 654) = dword_532DEC;
    }
    a3 = *(_DWORD *)(this + 502) + 224;
    a4 = *(_DWORD *)(this + 506) + 255;
    if ( *(_DWORD *)(this + 634) == 6 )
      a4 = *(_DWORD *)(this + 506) + 245;
    if ( *(_BYTE *)(this + 642) & 0x80 )
    {
      a3a = *(_DWORD *)(this + 502) + 256;
      spriteIdx = *(_DWORD *)(this + 646) + (*(_DWORD *)(this + 642) & 0x7F);
      if ( *(_DWORD *)(this + 634) == 6
        && !(*(_BYTE *)(usedToCheckForBoatByCastle(
                          (AdvManager *)this,
                          *(_DWORD *)(this + 470) + 7,
                          *(_DWORD *)(this + 474) + 7)
                      + 8) & 4) )
        rasterizeMirrored(
          *(Icon **)(thisa + 566),
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
        *(Icon **)(thisa + 4 * *(_DWORD *)(thisa + 634) + 538),
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
      if ( *(_DWORD *)(thisa + 634) == 6 )
      {
        rasterizeMirrored(
          *(Icon **)(thisa + 4 * curPlayer->color + 602),
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
        if ( !*(_DWORD *)(thisa + 650) )
          spriteIdx = (((unsigned __int64)*(_DWORD *)(thisa + 514) >> 32) ^ abs(*(_DWORD *)(thisa + 514)) & 7)
                    + (*(_DWORD *)(thisa + 642) & 0x7F)
                    - ((unsigned __int64)*(_DWORD *)(thisa + 514) >> 32)
                    + 56;
        rasterizeMirrored(
          *(Icon **)(thisa + 4 * curPlayer->color + 578),
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
        ++*(_DWORD *)(thisa + 518);
      }
    }
    else
    {
      spriteIdxa = *(_DWORD *)(this + 646) + *(_DWORD *)(this + 642);
      if ( *(_DWORD *)(this + 634) == 6
        && !(*(_BYTE *)(usedToCheckForBoatByCastle(
                          (AdvManager *)this,
                          *(_DWORD *)(this + 470) + 7,
                          *(_DWORD *)(this + 474) + 7)
                      + 8) & 4) )
        rasterize(
          *(Icon **)(thisa + 566),
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
        *(Icon **)(thisa + 4 * *(_DWORD *)(thisa + 634) + 538),
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
      if ( *(_DWORD *)(thisa + 634) == 6 )
      {
        rasterize(
          *(Icon **)(thisa + 4 * curPlayer->color + 602),
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
        if ( !*(_DWORD *)(thisa + 650) )
          spriteIdxa = (((unsigned __int64)*(_DWORD *)(thisa + 514) >> 32) ^ abs(*(_DWORD *)(thisa + 514)) & 7)
                     + (*(_DWORD *)(thisa + 642) & 0x7F)
                     - ((unsigned __int64)*(_DWORD *)(thisa + 514) >> 32)
                     + 56;
        rasterize(
          *(Icon **)(thisa + 4 * curPlayer->color + 578),
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
        ++*(_DWORD *)(thisa + 518);
      }
    }
    if ( *(_DWORD *)(thisa + 650) && *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) != 4 )
    {
      ++*(_DWORD *)(thisa + 646);
      if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 3
        && (*(_DWORD *)(thisa + 646) == 4 || *(_DWORD *)(thisa + 646) == 1) )
        ++*(_DWORD *)(thisa + 646);
      if ( !*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) )
      {
        dword_51E1BC = 1 - dword_51E1BC;
        if ( dword_51E1BC )
          --*(_DWORD *)(thisa + 646);
      }
    }
    if ( *(_DWORD *)(thisa + 646) >= 8 )
      *(_DWORD *)(thisa + 646) = 0;
    if ( !*(_DWORD *)(thisa + 654) )
    {
      if ( !*(_DWORD *)(thisa + 646) )
        dword_51E1B4 = dword_51E1B8;
      if ( *(_DWORD *)(thisa + 646) == 3
        || *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 4 && !dword_51E180 )
      {
        dword_51E180 = 1;
        if ( !dword_51E1BC )
        {
          v1 = *(_WORD *)usedToCheckForBoatByCastle(
                           (AdvManager *)thisa,
                           *(_DWORD *)(thisa + 470) + 7,
                           *(_DWORD *)(thisa + 474) + 7);
          dword_51E1B8 = (int)SoundManager::playSample(
                                soundManager,
                                *(Sample **)(thisa + 4 * (unsigned __int8)tileToTerrainType[v1] + 850));
        }
      }
    }
    if ( !dword_4F2AE4 )
    {
      dword_532DE4 = *(_DWORD *)(thisa + 638);
      dword_532DB4 = *(_DWORD *)(thisa + 642);
      dword_532DB0 = *(_DWORD *)(thisa + 646);
      dword_532DE8 = *(_DWORD *)(thisa + 650);
      dword_532DEC = *(_DWORD *)(thisa + 654);
    }
  }
}
