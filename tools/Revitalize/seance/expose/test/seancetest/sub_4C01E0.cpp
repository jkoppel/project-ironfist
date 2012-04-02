int __thiscall sub_4C01E0(int this)
{
  int result; // eax@15
  int v2; // [sp+Ch] [bp-20h]@1
  signed int v3; // [sp+10h] [bp-1Ch]@30
  signed int v4; // [sp+14h] [bp-18h]@13
  int v5; // [sp+18h] [bp-14h]@18
  int spriteIdx; // [sp+20h] [bp-Ch]@9
  int spriteIdxa; // [sp+20h] [bp-Ch]@34
  int a4; // [sp+24h] [bp-8h]@6
  int a3; // [sp+28h] [bp-4h]@6

  v2 = this;
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
      spriteIdx = *(_DWORD *)(this + 646) + (*(_DWORD *)(this + 642) & 0x7F);
      if ( *(_DWORD *)(this + 630) && *(_DWORD *)(this + 634) == 6 )
      {
        if ( spriteIdx < 9 || spriteIdx >= 36 )
          v4 = 0;
        else
          v4 = 36;
        result = rasterize(
                   *(Icon **)(this + 574),
                   HeroWindowManager::instance->screenBuffer,
                   *(_DWORD *)(this + 502) + 224,
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
        result = this;
        if ( *(_DWORD *)(this + 630) )
        {
          result = this;
          if ( *(_DWORD *)(this + 634) != 6 )
          {
            v5 = *(_DWORD *)(this + 646) + (*(_DWORD *)(this + 642) & 0x7F);
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
            result = rasterize(
                       *(Icon **)(this + 570),
                       HeroWindowManager::instance->screenBuffer,
                       *(_DWORD *)(this + 502) + 224,
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
      spriteIdxa = *(_DWORD *)(this + 646) + *(_DWORD *)(this + 642);
      if ( *(_DWORD *)(this + 630) && *(_DWORD *)(this + 634) == 6 )
      {
        result = rasterize(
                   *(Icon **)(this + 574),
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
      }
      else
      {
        result = this;
        if ( *(_DWORD *)(this + 630) )
        {
          result = this;
          if ( *(_DWORD *)(this + 634) != 6 )
            result = rasterize(
                       *(Icon **)(this + 570),
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
        }
      }
    }
    if ( !dword_4F2AE4 )
    {
      dword_532DE4 = *(_DWORD *)(v2 + 638);
      dword_532DB4 = *(_DWORD *)(v2 + 642);
      dword_532DB0 = *(_DWORD *)(v2 + 646);
      dword_532DE8 = *(_DWORD *)(v2 + 650);
      result = *(_DWORD *)(v2 + 654);
      dword_532DEC = *(_DWORD *)(v2 + 654);
    }
  }
  return result;
}
