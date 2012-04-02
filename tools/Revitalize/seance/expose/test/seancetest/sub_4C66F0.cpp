void __thiscall sub_4C66F0(CombatManager *this, int a2, int a3)
{
  signed int v3; // ST54_4@41
  signed int v4; // eax@72
  int v5; // ST34_4@82
  int v6; // ST44_4@82
  ICNHeader *v7; // eax@82
  CombatManager *thisa; // [sp+Ch] [bp-7Ch]@1
  signed int v9; // [sp+10h] [bp-78h]@74
  int y; // [sp+14h] [bp-74h]@80
  int spriteIdx; // [sp+18h] [bp-70h]@74
  int offsetY; // [sp+1Ch] [bp-6Ch]@19
  int j; // [sp+20h] [bp-68h]@49
  int i; // [sp+20h] [bp-68h]@54
  int l; // [sp+20h] [bp-68h]@60
  int k; // [sp+20h] [bp-68h]@65
  signed int m; // [sp+20h] [bp-68h]@74
  int offsetX; // [sp+28h] [bp-60h]@17
  int offsetXa; // [sp+28h] [bp-60h]@41
  int offsetXb; // [sp+28h] [bp-60h]@83
  int v21; // [sp+30h] [bp-58h]@41
  char v22; // [sp+3Ch] [bp-4Ch]@1
  char v23; // [sp+3Dh] [bp-4Bh]@1
  char v24; // [sp+3Eh] [bp-4Ah]@1
  char v25; // [sp+3Fh] [bp-49h]@1
  char v26; // [sp+40h] [bp-48h]@1
  char v27; // [sp+41h] [bp-47h]@1
  char v28; // [sp+42h] [bp-46h]@1
  char v29; // [sp+43h] [bp-45h]@1
  char v30; // [sp+44h] [bp-44h]@1
  char v31; // [sp+45h] [bp-43h]@1
  char v32; // [sp+46h] [bp-42h]@1
  char v33; // [sp+47h] [bp-41h]@1
  char v34; // [sp+48h] [bp-40h]@1
  char v35; // [sp+49h] [bp-3Fh]@1
  char v36; // [sp+4Ah] [bp-3Eh]@1
  char v37; // [sp+4Bh] [bp-3Dh]@1
  char v38; // [sp+4Ch] [bp-3Ch]@1
  char v39; // [sp+4Dh] [bp-3Bh]@1
  char v40; // [sp+4Eh] [bp-3Ah]@1
  char v41; // [sp+4Fh] [bp-39h]@1
  char v42; // [sp+50h] [bp-38h]@1
  char v43; // [sp+51h] [bp-37h]@1
  char v44; // [sp+52h] [bp-36h]@1
  char v45; // [sp+53h] [bp-35h]@1
  char v46; // [sp+54h] [bp-34h]@1
  char v47; // [sp+55h] [bp-33h]@1
  char v48; // [sp+56h] [bp-32h]@1
  char v49; // [sp+57h] [bp-31h]@1
  char v50; // [sp+58h] [bp-30h]@1
  char v51; // [sp+59h] [bp-2Fh]@1
  char v52; // [sp+5Ah] [bp-2Eh]@1
  char v53; // [sp+5Bh] [bp-2Dh]@1
  char v54; // [sp+5Ch] [bp-2Ch]@1
  char v55; // [sp+5Dh] [bp-2Bh]@1
  char v56; // [sp+5Eh] [bp-2Ah]@1
  char v57; // [sp+5Fh] [bp-29h]@1
  char v58; // [sp+60h] [bp-28h]@1
  char v59; // [sp+61h] [bp-27h]@1
  char v60; // [sp+62h] [bp-26h]@1
  char v61; // [sp+63h] [bp-25h]@1
  char v62; // [sp+64h] [bp-24h]@1
  char v63; // [sp+65h] [bp-23h]@1
  char v64; // [sp+66h] [bp-22h]@1
  char v65; // [sp+67h] [bp-21h]@1
  char v66; // [sp+68h] [bp-20h]@1
  char v67; // [sp+69h] [bp-1Fh]@1
  char v68; // [sp+6Ah] [bp-1Eh]@1
  char v69; // [sp+6Bh] [bp-1Dh]@1
  char v70; // [sp+6Ch] [bp-1Ch]@1
  char v71; // [sp+6Dh] [bp-1Bh]@1
  char v72; // [sp+6Eh] [bp-1Ah]@1
  char v73; // [sp+6Fh] [bp-19h]@1
  char v74; // [sp+70h] [bp-18h]@1
  char v75; // [sp+71h] [bp-17h]@1
  char v76; // [sp+72h] [bp-16h]@1
  char v77; // [sp+73h] [bp-15h]@1
  char v78; // [sp+74h] [bp-14h]@1
  char v79; // [sp+75h] [bp-13h]@1
  char v80; // [sp+76h] [bp-12h]@1
  char v81; // [sp+77h] [bp-11h]@1
  char v82; // [sp+78h] [bp-10h]@1
  char v83; // [sp+79h] [bp-Fh]@1
  char v84; // [sp+7Ah] [bp-Eh]@1
  char v85; // [sp+7Bh] [bp-Dh]@1
  char v86; // [sp+7Ch] [bp-Ch]@1
  char v87; // [sp+7Dh] [bp-Bh]@1
  char v88; // [sp+7Eh] [bp-Ah]@1
  char v89; // [sp+7Fh] [bp-9h]@1
  char v90; // [sp+80h] [bp-8h]@1
  char v91; // [sp+81h] [bp-7h]@1
  char v92; // [sp+82h] [bp-6h]@1
  char v93; // [sp+83h] [bp-5h]@1
  int v94; // [sp+84h] [bp-4h]@39

  thisa = this;
  v22 = 22;
  v23 = 10;
  v24 = -1;
  v25 = -1;
  v26 = -1;
  v27 = -1;
  v28 = -1;
  v29 = -1;
  v30 = -1;
  v31 = -1;
  v32 = -1;
  v33 = -1;
  v34 = 11;
  v35 = 10;
  v36 = 32;
  v37 = 10;
  v38 = -1;
  v39 = -1;
  v40 = -1;
  v41 = -1;
  v42 = -1;
  v43 = -1;
  v44 = -1;
  v45 = -1;
  v46 = 1;
  v47 = 10;
  v48 = 22;
  v49 = 10;
  v50 = 43;
  v51 = 10;
  v52 = -1;
  v53 = -1;
  v54 = -1;
  v55 = -1;
  v56 = -1;
  v57 = -1;
  v58 = 11;
  v59 = 0;
  v60 = 32;
  v61 = 0;
  v62 = 11;
  v63 = 21;
  v64 = 32;
  v65 = 21;
  v66 = -1;
  v67 = -1;
  v68 = -1;
  v69 = -1;
  v70 = 1;
  v71 = 0;
  v72 = 22;
  v73 = 0;
  v74 = 43;
  v75 = 0;
  v76 = 11;
  v77 = 21;
  v78 = 32;
  v79 = 21;
  v80 = -1;
  v81 = -1;
  v82 = 1;
  v83 = 0;
  v84 = 22;
  v85 = 0;
  v86 = 43;
  v87 = 0;
  v88 = 1;
  v89 = 21;
  v90 = 22;
  v91 = 21;
  v92 = 43;
  v93 = 21;
  if ( !combatGraphicsOff && this->checkedInsub4c3d60 && *(_DWORD *)&combatArmyInfoLevel && !dword_51E3EC )
  {
    dword_51E3EC = 1;
    if ( *(_DWORD *)&this->_15[4 * a2 + 100] != -1
      && (*(&this->field_F553 + a2) != 5 || *(_DWORD *)&this->_15[4 * a2 + 100] != 1)
      && (*(&this->field_F553 + a2) != 555 || *(_DWORD *)&this->_15[4 * a2 + 100]) )
      goto LABEL_88;
    if ( *(&this->field_F553 + a2) >= 0 )
    {
      dword_4F7488 = 1;
      combatScreenRedrawRectLeft = *(&this->field_F553 + a2);
      combatScreenRedrawRectTop = *(_DWORD *)&this->_16[4 * a2];
      combatScreenRedrawRectRight = *(&this->field_F553 + a2) + *(_DWORD *)&this->_16[4 * a2 + 8] - 1;
      combatScreenRedrawRectBot = *(_DWORD *)&this->_16[4 * a2] + *(_DWORD *)&this->_16[4 * a2 + 16] - 1;
      CombatManager::drawBattlefield(this, 0, 0, 0, 0, 0, 1, 1);
      HeroWindowManager::redrawRectangle(
        HeroWindowManager::instance,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
        combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      dword_4F7488 = 0;
      *(&thisa->field_F553 + a2) = -1;
    }
    if ( *(_DWORD *)&thisa->_15[4 * a2 + 100] != -1 )
    {
LABEL_88:
      if ( *(_DWORD *)&combatArmyInfoLevel == 2 )
      {
        if ( a2 )
        {
          if ( *(_DWORD *)&thisa->_15[4 * a2 + 100] )
            offsetX = 555;
          else
            offsetX = 5;
          if ( *(_DWORD *)&thisa->_15[104] == *(_DWORD *)&thisa->_15[100] )
            offsetY = 154;
          else
            offsetY = 299;
        }
        else
        {
          if ( *(_DWORD *)&thisa->_15[100] )
            offsetX = 555;
          else
            offsetX = 5;
          offsetY = 299;
        }
        *(_DWORD *)&thisa->_16[4 * a2 + 8] = 83;
        *(_DWORD *)&thisa->_16[4 * a2 + 16] = 141;
      }
      else
      {
        if ( a2 )
        {
          if ( *(_DWORD *)&thisa->_15[4 * a2 + 100] )
            offsetX = 555;
          else
            offsetX = 5;
          if ( *(_DWORD *)&thisa->_15[104] == *(_DWORD *)&thisa->_15[100] )
            offsetY = 288;
          else
            offsetY = 366;
        }
        else
        {
          if ( *(_DWORD *)&thisa->_15[100] )
            offsetX = 555;
          else
            offsetX = 5;
          offsetY = 366;
        }
        *(_DWORD *)&thisa->_16[4 * a2 + 8] = 83;
        *(_DWORD *)&thisa->_16[4 * a2 + 16] = 74;
      }
      *(&thisa->field_F553 + a2) = offsetX;
      *(_DWORD *)&thisa->_16[4 * a2] = offsetY;
      v94 = dword_4F7488;
      if ( a3 )
        dword_4F7488 = 0;
      v21 = (int)&thisa->creatures[*(_DWORD *)&thisa->_15[4 * a2 + 100]][*(_DWORD *)&thisa->_15[4 * a2 + 108]];
      v3 = Icon::drawToScreenAndSetRectBounds(
             thisa->combatScreenIcons[10],
             offsetX,
             offsetY,
             *(_DWORD *)&combatArmyInfoLevel != 2,
             (H2RECT *)&thisa->_15[68],
             0,
             0,
             0,
             0);
      offsetXa = offsetX + 6;
      if ( v3 )
      {
        if ( *(_DWORD *)(v21 + 150) <= 1 )
          sprintf(globBuf, off_4F6FC4, *(_DWORD *)(v21 + 150));
        else
          sprintf(globBuf, off_4F6FC0, *(_DWORD *)(v21 + 150));
        Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 7, 57, 12, 1, 1);
        if ( *(_DWORD *)&combatArmyInfoLevel == 2 )
        {
          Font::drawString(smallFont, off_4F6FC8, offsetXa + 8, offsetY + 20, 57, 12, 1, 0);
          Font::drawString(smallFont, off_4F6FCC, offsetXa + 8, offsetY + 29, 57, 12, 1, 0);
          Font::drawString(smallFont, off_4F6FD0, offsetXa + 8, offsetY + 38, 57, 12, 1, 0);
          Font::drawString(smallFont, off_4F6FD4, offsetXa + 8, offsetY + 47, 57, 12, 1, 0);
          Font::drawString(smallFont, off_4F6FD8, offsetXa + 8, offsetY + 56, 57, 12, 1, 0);
          Font::drawString(smallFont, off_4F6FDC, offsetXa + 8, offsetY + 65, 57, 12, 1, 0);
          if ( *(_BYTE *)(v21 + 208) & 4 )
            Font::drawString(smallFont, off_4F6FE0, offsetXa + 8, offsetY + 74, 57, 12, 1, 0);
          sprintf(globBuf, "%d", *(_BYTE *)(v21 + 198));
          Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 20, 57, 12, 1, 2);
          sprintf(globBuf, "%d", *(_BYTE *)(v21 + 199));
          Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 29, 57, 12, 1, 2);
          sprintf(globBuf, "%d", *(_WORD *)(v21 + 194));
          Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 38, 57, 12, 1, 2);
          sprintf(globBuf, "%d-%d", *(_BYTE *)(v21 + 200), *(_BYTE *)(v21 + 201));
          Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 47, 57, 12, 1, 2);
          if ( *(_DWORD *)(v21 + 242) <= 0 )
          {
            if ( *(_DWORD *)(v21 + 242) >= 0 )
            {
              Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 45, offsetY + 56, 5, 0);
            }
            else
            {
              for ( i = 0; -*(_DWORD *)(v21 + 242) > i; ++i )
                Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 57 - 10 * i, offsetY + 56, 3, 0);
            }
          }
          else
          {
            for ( j = 0; *(_DWORD *)(v21 + 242) > j; ++j )
              Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 57 - 10 * j, offsetY + 56, 4, 0);
          }
          if ( *(_DWORD *)(v21 + 246) <= 0 )
          {
            if ( *(_DWORD *)(v21 + 246) >= 0 )
            {
              Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 50, offsetY + 65, 2, 0);
            }
            else
            {
              for ( k = 0; -*(_DWORD *)(v21 + 246) > k; ++k )
                Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 57 - 10 * k, offsetY + 65, 0, 0);
            }
          }
          else
          {
            for ( l = 0; *(_DWORD *)(v21 + 246) > l; ++l )
              Icon::drawToScreen(thisa->combatScreenIcons[11], offsetXa + 57 - 10 * l, offsetY + 65, 1, 0);
          }
          if ( *(_BYTE *)(v21 + 208) & 4 )
          {
            sprintf(globBuf, "%d", *(_BYTE *)(v21 + 202));
            Font::drawString(smallFont, globBuf, offsetXa + 8, offsetY + 74, 57, 12, 1, 2);
          }
        }
        v4 = *(_DWORD *)(v21 + 262);
        if ( v4 >= 6 )
          v4 = 6;
        v9 = v4;
        spriteIdx = -1;
        for ( m = 0; m < v9; ++m )
        {
          ++spriteIdx;
          while ( !*(_BYTE *)(spriteIdx + v21 + 266) )
            ++spriteIdx;
          if ( *(_DWORD *)&combatArmyInfoLevel == 2 )
            y = offsetY + 86;
          else
            y = offsetY + 19;
          v5 = (unsigned __int8)*(&v23 + 4 * (3 * v9 - 3) + 2 * m) + y;
          v6 = ((19 - getNthHeader(thisa->combatScreenIcons[12], spriteIdx)->width) >> 1)
             + (unsigned __int8)*(&v22 + 4 * (3 * v9 - 3) + 2 * m)
             + offsetXa
             + 6;
          v7 = getNthHeader(thisa->combatScreenIcons[12], spriteIdx);
          Icon::drawToScreen(thisa->combatScreenIcons[12], v6, ((19 - v7->height) >> 1) + v5, spriteIdx, 0);
        }
      }
      dword_4F7488 = v94;
      offsetXb = offsetXa - 6;
      if ( a3 )
        HeroWindowManager::redrawRectangle(
          HeroWindowManager::instance,
          offsetXb,
          offsetY,
          *(_DWORD *)&thisa->_16[4 * a2 + 8],
          *(_DWORD *)&thisa->_16[4 * a2 + 16]);
      dword_51E3EC = 0;
    }
    else
    {
      dword_51E3EC = 0;
    }
  }
}
