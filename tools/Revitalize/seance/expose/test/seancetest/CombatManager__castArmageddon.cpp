void __usercall CombatManager::castArmageddon(CombatManager *this<ecx>, int a2<ebx>)
{
  PaletteContents *v2; // ST14_4@23
  void *v3; // eax@23
  int v4; // eax@48
  unsigned __int8 *v5; // eax@50
  int v6; // ecx@50
  PaletteContents *v7; // eax@79
  CombatManager *thisa; // [sp+34h] [bp-F8h]@1
  int v9; // [sp+38h] [bp-F4h]@56
  int v10; // [sp+3Ch] [bp-F0h]@53
  Palette *thisb; // [sp+48h] [bp-E4h]@18
  const void *v12; // [sp+4Ch] [bp-E0h]@52
  void *v13; // [sp+50h] [bp-DCh]@58
  signed int m; // [sp+54h] [bp-D8h]@35
  float f; // [sp+58h] [bp-D4h]@37
  signed int l; // [sp+5Ch] [bp-D0h]@25
  signed int ii; // [sp+5Ch] [bp-D0h]@40
  signed int k; // [sp+60h] [bp-CCh]@23
  int jj; // [sp+64h] [bp-C8h]@58
  PaletteContents *armageddonPaletteContents; // [sp+68h] [bp-C4h]@23
  int v21; // [sp+6Ch] [bp-C0h]@48
  signed int n; // [sp+70h] [bp-BCh]@37
  int tick; // [sp+74h] [bp-B8h]@48
  int v24; // [sp+78h] [bp-B4h]@48
  int v25; // [sp+7Ch] [bp-B0h]@35
  int v26; // [sp+80h] [bp-ACh]@35
  int v27; // [sp+84h] [bp-A8h]@35
  int v28; // [sp+88h] [bp-A4h]@35
  int v29; // [sp+8Ch] [bp-A0h]@35
  int v30; // [sp+90h] [bp-9Ch]@35
  int v31; // [sp+94h] [bp-98h]@35
  int v32; // [sp+98h] [bp-94h]@35
  int v33; // [sp+9Ch] [bp-90h]@35
  int v34; // [sp+A0h] [bp-8Ch]@35
  int v35; // [sp+A4h] [bp-88h]@35
  int v36; // [sp+A8h] [bp-84h]@35
  int v37; // [sp+ACh] [bp-80h]@35
  int v38; // [sp+B0h] [bp-7Ch]@35
  int v39; // [sp+B4h] [bp-78h]@35
  int v40; // [sp+B8h] [bp-74h]@35
  int v41; // [sp+BCh] [bp-70h]@35
  int v42; // [sp+C0h] [bp-6Ch]@35
  int v43; // [sp+C4h] [bp-68h]@35
  int v44; // [sp+C8h] [bp-64h]@35
  int v45; // [sp+CCh] [bp-60h]@35
  int v46; // [sp+D0h] [bp-5Ch]@35
  int v47; // [sp+D4h] [bp-58h]@35
  int v48; // [sp+D8h] [bp-54h]@35
  int v49; // [sp+DCh] [bp-50h]@35
  int v50; // [sp+E0h] [bp-4Ch]@35
  int v51; // [sp+E4h] [bp-48h]@35
  int v52; // [sp+E8h] [bp-44h]@35
  int v53; // [sp+ECh] [bp-40h]@35
  int v54; // [sp+F0h] [bp-3Ch]@35
  size_t v55; // [sp+F4h] [bp-38h]@48
  int v56; // [sp+F8h] [bp-34h]@48
  Palette *armageddonPalette; // [sp+FCh] [bp-30h]@17
  int j; // [sp+100h] [bp-2Ch]@3
  CreatureStack *creat; // [sp+104h] [bp-28h]@5
  int damTaken; // [sp+108h] [bp-24h]@6
  int ll; // [sp+10Ch] [bp-20h]@65
  int damage; // [sp+110h] [bp-1Ch]@1
  int kk; // [sp+114h] [bp-18h]@63
  PaletteContents *a1; // [sp+118h] [bp-14h]@63
  int i; // [sp+11Ch] [bp-10h]@1
  Palette *pal; // [sp+120h] [bp-Ch]@17
  PaletteContents *v67; // [sp+124h] [bp-8h]@63
  int anyoneDamaged; // [sp+128h] [bp-4h]@1

  thisa = this;
  damage = 50 * this->heroSpellpowers[this->currentActionSide];
  anyoneDamaged = 0;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; thisa->numCreatures[i] > j; ++j )
    {
      creat = &thisa->creatures[i][j];
      if ( CreatureStack::rollSpellSucceeds(&thisa->creatures[i][j], SPELL_ARMAGEDDON) )
      {
        damTaken = damage;
        if ( creat->creatureIdx == CREATURE_IRON_GOLEM || creat->creatureIdx == CREATURE_STEEL_GOLEM )
          damTaken = (signed __int64)((double)damTaken * 0.5);
        if ( thisa->heroes[i] )
        {
          if ( Hero::hasArtifact(thisa->heroes[i], ARTIFACT_BROACH_OF_SHIELDING) )
            damTaken = (signed __int64)((double)damTaken * 0.5);
        }
        CreatureStack::takeDamage(creat, damTaken, SPELL_ARMAGEDDON);
        anyoneDamaged = 1;
      }
    }
  }
  if ( anyoneDamaged )
  {
    sprintf(globBuf, "The armageddon does %d damage.", damage);
    CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
  }
  pal = 0;
  armageddonPalette = 0;
  if ( !combatGraphicsOff )
  {
    HeroWindowManager::instance->field_56 = 0;
    pal = ResourceManager::getPal(resourceManager, "kb.pal");
    thisb = (Palette *)operator new(20);
    if ( thisb )
      armageddonPalette = Palette_constructor(thisb);
    else
      armageddonPalette = 0;
    if ( !armageddonPalette )
      fatalOutOfMemoryError();
    v2 = Palette::getContents(pal);
    v3 = Palette::getContents(armageddonPalette);
    memcpy(v3, v2, 0x300u);
    animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                              + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 75.0);
    armageddonPaletteContents = Palette::getContents(armageddonPalette);
    for ( k = 0; k < 16; ++k )
    {
      for ( l = 0; l < 256; ++l )
      {
        if ( armageddonPaletteContents->colors[l].red < 63 )
          ++armageddonPaletteContents->colors[l].red;
        if ( armageddonPaletteContents->colors[l].green < 63 )
          ++armageddonPaletteContents->colors[l].green;
        if ( armageddonPaletteContents->colors[l].blue < 63 )
          ++armageddonPaletteContents->colors[l].blue;
      }
      sleepUntilPointer(&animationFrameSwitchTime);
      someSortOfPaletteSwap(armageddonPaletteContents, 1);
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 20.0);
    }
    v25 = 2;
    v26 = 2;
    v27 = 4;
    v28 = 1;
    v29 = 3;
    v30 = -2;
    v31 = 0;
    v32 = -6;
    v33 = 2;
    v34 = -2;
    v35 = -1;
    v36 = 3;
    v37 = -5;
    v38 = 4;
    v39 = -8;
    v40 = 6;
    v41 = -4;
    v42 = 2;
    v43 = -1;
    v44 = 1;
    v45 = -3;
    v46 = -3;
    v47 = -7;
    v48 = -5;
    v49 = -5;
    v50 = -7;
    v51 = -2;
    v52 = -3;
    v53 = 0;
    v54 = 0;
    MouseManager::disableCursor(mouseManager);
    memcpy(thisa->probablyBitmapForCombatScreen->contents, HeroWindowManager::instance->screenBuffer->contents, 283520u);
    for ( m = 0; m < 4; ++m )
    {
      f = (double)(4 - m) * 0.75;
      for ( n = 0; n < 15; ++n )
      {
        if ( !m )
        {
          for ( ii = 0; ii < 256; ++ii )
          {
            if ( armageddonPaletteContents->colors[ii].green > 3 )
              armageddonPaletteContents->colors[ii].green -= 3;
            if ( armageddonPaletteContents->colors[ii].blue > 3 )
              armageddonPaletteContents->colors[ii].blue -= 3;
          }
          someSortOfPaletteSwap(armageddonPaletteContents, 1);
        }
        v56 = (signed __int64)((double)*(&v25 + 2 * n) * f);
        v24 = (signed __int64)((double)*(&v26 + 2 * n) * f);
        tick = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 15.0);
        yieldToGlobalUpdater();
        v55 = 640 - abs((signed __int64)((double)*(&v25 + 2 * n) * f));
        v21 = 443 - abs((signed __int64)((double)*(&v26 + 2 * n) * f)) - 1;
        v4 = v24;
        if ( v24 <= 0 )
          v4 = 0;
        v5 = &thisa->probablyBitmapForCombatScreen->contents[640 * v4];
        v6 = v56;
        if ( v56 <= 0 )
          v6 = 0;
        v12 = &v5[v6];
        if ( v56 <= 0 )
          v10 = -v56;
        else
          v10 = 0;
        if ( v24 <= 0 )
          v9 = -v24;
        else
          v9 = 0;
        v13 = &HeroWindowManager::instance->screenBuffer->contents[640 * v9] + v10;
        for ( jj = 0; v21 > jj; ++jj )
        {
          memcpy(v13, v12, v55);
          v12 = (char *)v12 + 640;
          v13 = (char *)v13 + 640;
        }
        renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 640u, 443, 0, 0);
        sleepUntilPointer(&tick);
      }
    }
  }
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  CreatureStack::doAttackAndDamageTakenAnimations(creat, -1, 1, -1, -1);
  a1 = Palette::getContents(armageddonPalette);
  v67 = Palette::getContents(pal);
  for ( kk = 0; kk < 16; ++kk )
  {
    for ( ll = 0; ll < 768; ++ll )
    {
      if ( *(&a1->colors[0].red + ll) != *(&v67->colors[0].red + ll) )
      {
        if ( *(&a1->colors[0].red + ll) <= *(&v67->colors[0].red + ll) )
        {
          if ( *(&a1->colors[0].red + ll) + 3 >= *(&v67->colors[0].red + ll) )
            *(&a1->colors[0].red + ll) = *(&v67->colors[0].red + ll);
          else
            *(&a1->colors[0].red + ll) += 3;
        }
        else
        {
          if ( *(&a1->colors[0].red + ll) - 3 <= *(&v67->colors[0].red + ll) )
            *(&a1->colors[0].red + ll) = *(&v67->colors[0].red + ll);
          else
            *(&a1->colors[0].red + ll) -= 3;
        }
      }
    }
    someSortOfPaletteSwap(a1, 1);
    sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 20.0));
  }
  v7 = Palette::getContents(pal);
  someSortOfPaletteSwap(v7, 1);
  HeroWindowManager::instance->field_56 = 1;
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)pal);
  if ( armageddonPalette )
    ((void (__thiscall *)(Palette *))armageddonPalette->vtable->cleanUp)(armageddonPalette);
  MouseManager::enableCursor(mouseManager);
}
