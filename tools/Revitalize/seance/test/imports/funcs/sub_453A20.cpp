{
  int v5; // ebx@18
  signed int v6; // eax@18
  int v8; // [sp+Ch] [bp-24h]@1
  int v9; // [sp+18h] [bp-18h]@3
  int v10; // [sp+1Ch] [bp-14h]@3
  signed int v11; // [sp+20h] [bp-10h]@5
  int v12; // [sp+24h] [bp-Ch]@1
  int v13; // [sp+2Ch] [bp-4h]@26

  v8 = (int)this;
  v12 = dword_524C14;
  if ( !a5 )
    sub_4C3190(9, *(_BYTE *)(a2 + 2), a3, BYTE4(a3), -999, 0, 0);
  v9 = usedToCheckForBoatByCastle((AdvManager *)v8, a3, SHIDWORD(a3));
  v10 = usedToCheckForBoatByCastle((AdvManager *)v8, *(_DWORD *)(a2 + 25), *(_DWORD *)(a2 + 29));
  if ( *(_WORD *)(a2 + 45) == 163 )
    gameObject->castles[*(_WORD *)(a2 + 47)].visitingHeroIdx = -1;
  v11 = 0;
  if ( *(_BYTE *)(v10 + 8) & 0x40 )
  {
    *(_BYTE *)(v10 + 8) -= 64;
    v11 = 1;
  }
  else
  {
    sub_42CC90(*(_DWORD *)(a2 + 25), *(_DWORD *)(a2 + 29), *(_WORD *)(a2 + 45), *(_WORD *)(a2 + 47), 0, 99);
  }
  sub_448110((AdvManager *)v8, 0);
  if ( !*(&byte_524758 + curPlayerIdx) )
    dword_524C14 = !*(_DWORD *)&blackoutComputer && sub_456B40(*(_DWORD *)(a2 + 25), *(_DWORD *)(a2 + 29), byte_5306F0)
                || sub_456B40(a3, SHIDWORD(a3), byte_5306F0);
  if ( v12 )
    sub_455030((void *)v8, 1, 1, 1);
  if ( dword_524C14 )
  {
    *(_DWORD *)(v8 + 470) = a3 - 7;
    *(_DWORD *)(v8 + 474) = HIDWORD(a3) - 7;
    sleep(90);
  }
  *(_DWORD *)(a2 + 25) = a3;
  *(_DWORD *)(a2 + 29) = HIDWORD(a3);
  v5 = byte_4F3B10[*(_BYTE *)(a2 + 119)];
  v6 = Hero::hasArtifact((Hero *)a2, ARTIFACT_TELESCOPE);
  explore(*(_DWORD *)(v8 + 470) + 7, *(_DWORD *)(v8 + 474) + 7, curPlayerIdx, ((unsigned int)v6 >= 1) + v5);
  if ( dword_524C14 )
  {
    *(_BYTE *)(v9 + 8) |= 0x40u;
    HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 16, 16, 448, 448);
    sub_448110((AdvManager *)v8, 0);
    yieldToGlobalUpdater();
    sub_4C7E00(HeroWindowManager::instance, 16, 16, 448, 448, -1, 0, 0);
    yieldToGlobalUpdater();
  }
  else
  {
    *(_WORD *)(a2 + 45) = *(_BYTE *)(v9 + 9);
    *(_WORD *)(a2 + 47) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v9 + 4) >> 8) >> -5);
    if ( v11 )
    {
      *(_BYTE *)(v9 + 8) |= 0x40u;
    }
    else
    {
      *(_BYTE *)(v9 + 9) = -86;
      *(_WORD *)(v9 + 4) = *(_WORD *)(v9 + 4) & 7 | 8 * *(_BYTE *)(a2 + 2);
    }
    if ( *(_DWORD *)(v8 + 634) == 6 )
      *(_DWORD *)(a2 + 227) |= 0x80u;
    *(_DWORD *)(v8 + 626) = 0;
  }
  sub_452F60((void *)v8, *(_DWORD *)(v8 + 470) + 7, *(_DWORD *)(v8 + 474) + 7, 1);
  v13 = (unsigned __int8)tileToTerrainType[*(_WORD *)v9];
  if ( *(_DWORD *)(v8 + 166) != v13 )
  {
    *(_DWORD *)(v8 + 166) = v13;
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(v8 + 166)]);
  }
  sub_4456D0(0, 0);
  sub_44AA80(v8, 1, 0);
  sub_448110((AdvManager *)v8, 0);
  return sub_455380((void *)v8);
}
