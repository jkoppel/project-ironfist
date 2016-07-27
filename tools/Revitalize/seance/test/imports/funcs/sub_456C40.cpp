{
  __int64 v1; // qax@15
  int v2; // [sp+Ch] [bp-6Ch]@1
  GUIWindow *thisa; // [sp+18h] [bp-60h]@4
  char v4; // [sp+1Ch] [bp-5Ch]@1
  char v5; // [sp+1Dh] [bp-5Bh]@1
  char v6; // [sp+1Eh] [bp-5Ah]@1
  char v7; // [sp+1Fh] [bp-59h]@1
  char v8; // [sp+20h] [bp-58h]@1
  char v9; // [sp+21h] [bp-57h]@1
  char v10; // [sp+22h] [bp-56h]@1
  char v11; // [sp+23h] [bp-55h]@1
  char v12; // [sp+24h] [bp-54h]@1
  char v13; // [sp+25h] [bp-53h]@1
  char v14; // [sp+26h] [bp-52h]@1
  char v15; // [sp+27h] [bp-51h]@1
  char v16; // [sp+28h] [bp-50h]@1
  char v17; // [sp+29h] [bp-4Fh]@1
  char v18; // [sp+2Ah] [bp-4Eh]@1
  char v19; // [sp+2Bh] [bp-4Dh]@1
  char v20; // [sp+2Ch] [bp-4Ch]@1
  char v21; // [sp+2Dh] [bp-4Bh]@1
  char v22; // [sp+2Eh] [bp-4Ah]@1
  char v23; // [sp+2Fh] [bp-49h]@1
  char v24; // [sp+30h] [bp-48h]@1
  char v25; // [sp+31h] [bp-47h]@1
  char v26; // [sp+32h] [bp-46h]@1
  char v27; // [sp+33h] [bp-45h]@1
  char v28; // [sp+34h] [bp-44h]@1
  char v29; // [sp+35h] [bp-43h]@1
  char v30; // [sp+36h] [bp-42h]@1
  char v31; // [sp+37h] [bp-41h]@1
  char v32; // [sp+38h] [bp-40h]@1
  char v33; // [sp+39h] [bp-3Fh]@1
  char v34; // [sp+3Ah] [bp-3Eh]@1
  char v35; // [sp+3Bh] [bp-3Dh]@1
  char v36; // [sp+3Ch] [bp-3Ch]@1
  char v37; // [sp+3Dh] [bp-3Bh]@1
  char v38; // [sp+3Eh] [bp-3Ah]@1
  char v39; // [sp+3Fh] [bp-39h]@1
  char v40; // [sp+40h] [bp-38h]@1
  char v41; // [sp+41h] [bp-37h]@1
  char v42; // [sp+42h] [bp-36h]@1
  char v43; // [sp+43h] [bp-35h]@1
  char v44; // [sp+44h] [bp-34h]@1
  char v45; // [sp+45h] [bp-33h]@1
  char v46; // [sp+46h] [bp-32h]@1
  char v47; // [sp+47h] [bp-31h]@1
  char v48; // [sp+48h] [bp-30h]@1
  char v49; // [sp+49h] [bp-2Fh]@1
  char v50; // [sp+4Ah] [bp-2Eh]@1
  char v51; // [sp+4Bh] [bp-2Dh]@1
  int spriteIdx; // [sp+4Ch] [bp-2Ch]@1
  int i; // [sp+50h] [bp-28h]@20
  int v54; // [sp+54h] [bp-24h]@1
  int v55; // [sp+58h] [bp-20h]@9
  Icon *v56; // [sp+5Ch] [bp-1Ch]@1
  int v57; // [sp+60h] [bp-18h]@9
  GUIWindow *a2; // [sp+64h] [bp-14h]@5
  unsigned int v59; // [sp+68h] [bp-10h]@22
  unsigned int v60; // [sp+6Ch] [bp-Ch]@22
  int v61; // [sp+70h] [bp-8h]@9
  int v62; // [sp+74h] [bp-4h]@9

  v2 = (int)this;
  sub_419500(gameObject, curPlayerIdx, 0);
  v4 = 23;
  v5 = 7;
  v6 = 44;
  v7 = 5;
  v8 = 24;
  v9 = 47;
  v10 = 1;
  v11 = 39;
  v12 = 16;
  v13 = 36;
  v14 = 11;
  v15 = 45;
  v16 = 31;
  v17 = 2;
  v18 = 30;
  v19 = 38;
  v20 = 43;
  v21 = 4;
  v22 = 3;
  v23 = 14;
  v24 = 40;
  v25 = 37;
  v26 = 34;
  v27 = 0;
  v28 = 12;
  v29 = 17;
  v30 = 35;
  v31 = 42;
  v32 = 15;
  v33 = 8;
  v34 = 26;
  v35 = 41;
  v36 = 28;
  v37 = 46;
  v38 = 10;
  v39 = 22;
  v40 = 21;
  v41 = 6;
  v42 = 32;
  v43 = 18;
  v44 = 19;
  v45 = 29;
  v46 = 13;
  v47 = 27;
  v48 = 9;
  v49 = 20;
  v50 = 33;
  v51 = 25;
  v54 = 0;
  SoundManager::couldBePlayCDTrack(soundManager, 23);
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  v56 = ResourceManager::getIconByFilename(resourceManager, "puzzle.icn");
  for ( spriteIdx = 0; spriteIdx < 48; ++spriteIdx )
    Icon::drawToScreen(v56, 0, 0, spriteIdx, 0);
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 16, 16, 0x1C0u, 448);
  HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 16, 16, 448, 448);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    a2 = GUIWindow_constructorFromFile(thisa, 480, 16, "viewpuzl.bin");
  else
    a2 = 0;
  if ( !a2 )
    fatalOutOfMemoryError();
  HeroWindowManager::addWindow(HeroWindowManager::instance, a2, -1, 1);
  v57 = gameObject->_10[24] - 7;
  v55 = gameObject->_10[25] - 7;
  v62 = 0;
  v61 = 0;
  v62 = (gameObject->_10[25] + gameObject->_10[24]) % 3 - 1;
  v61 = (5 * gameObject->_10[25] + 2 * gameObject->_10[24]) % 3 - 1;
  if ( (gameObject->_10[25] + gameObject->_10[24]) % 3 == 1 )
  {
    if ( v62 <= 0 )
    {
      if ( v62 < 0 )
        --v62;
    }
    else
    {
      ++v62;
    }
  }
  else
  {
    v1 = (signed int)gameObject->_10[25] + (signed int)gameObject->_10[24];
    if ( (HIDWORD(v1) ^ ((BYTE4(v1) ^ (unsigned __int8)v1) - BYTE4(v1)) & 1) - HIDWORD(v1) == 1 )
    {
      if ( v61 <= 0 )
      {
        if ( v61 < 0 )
          --v61;
      }
      else
      {
        ++v61;
      }
    }
  }
  v57 += v62;
  v55 += v61;
  sub_457110((void *)v2, v57, v55, gameObject->_10[24], gameObject->_10[25]);
  for ( i = 16; i < 464; ++i )
  {
    v59 = (unsigned int)&HeroWindowManager::instance->screenBuffer->contents[640 * i + 16];
    v60 = v59 + 448;
    while ( v59 < v60 )
    {
      *(_BYTE *)v59 = byte_4F0300[*(_BYTE *)v59];
      ++v59;
    }
  }
  for ( spriteIdx = 0; spriteIdx < 48; ++spriteIdx )
  {
    if ( !sub_4D05D8((int)&unk_523420, spriteIdx) )
    {
      Icon::drawToScreen(v56, 0, 0, (unsigned __int8)*(&v4 + spriteIdx), 0);
      ++v54;
    }
  }
  if ( v54 == 48 )
    HeroWindowManager::deleteSomeBMP(HeroWindowManager::instance);
  else
    sub_4C7E00(HeroWindowManager::instance, 16, 16, 448, 448, 220, 0, 0);
  HeroWindowManager::displayWindow(HeroWindowManager::instance, a2, sub_432A10, 0);
  operator delete(a2);
  sub_447C20((AdvManager *)v2, *(_DWORD *)(v2 + 470), *(_DWORD *)(v2 + 474), 0, 1);
  sub_447A00((void *)v2, 0, 0);
  sub_44AA80(v2, 1, 0);
  SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(v2 + 166)]);
}
