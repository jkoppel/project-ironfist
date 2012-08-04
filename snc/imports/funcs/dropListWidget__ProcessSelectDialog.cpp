{
  int v1; // ebx@1
  signed __int16 v2; // si@1
  __int16 v3; // dx@1
  __int16 v4; // ax@2
  __int16 v5; // cx@2
  int v6; // ecx@11
  int v7; // esi@11
  int v8; // edx@11
  int v9; // edi@11
  __int16 v10; // bp@11
  __int16 v11; // ax@11
  __int16 v12; // di@11
  __int16 v13; // dx@11
  __int16 v14; // bp@11
  __int16 v15; // si@11
  int v16; // ebp@11
  int v17; // ebp@11
  int v18; // eax@11
  int v19; // eax@11
  unsigned __int8 v20; // zf@11
  unsigned __int8 v21; // sf@11
  __int16 v22; // bp@15
  __int16 v23; // dx@15
  bitmap *v24; // ecx@16
  int v25; // eax@21
  int v26; // edx@21
  int v27; // edi@21
  int v28; // esi@21
  int v29; // ecx@21
  int v30; // eax@22
  __int16 v31; // ax@24
  __int16 v32; // ax@25
  __int16 v33; // cx@28
  __int16 v34; // ax@28
  __int16 v35; // ax@30
  int v36; // ecx@37
  signed __int16 v37; // ax@37
  __int16 v38; // cx@39
  int v39; // eax@39
  int v40; // edx@39
  int v41; // ecx@42
  int v42; // eax@42
  int v43; // eax@43
  int v44; // ecx@47
  int v45; // edx@49
  int v46; // esi@53
  int v47; // eax@53
  int v48; // eax@59
  int v49; // edi@60
  int v50; // eax@63
  int v51; // edx@64
  int v52; // eax@67
  int v53; // ecx@67
  int v54; // eax@67
  int v55; // ecx@68
  __int16 v56; // ax@74
  __int16 v57; // ax@78
  int v58; // eax@81
  __int16 v59; // si@84
  int v60; // eax@84
  int v61; // ecx@95
  __int16 v62; // [sp+10h] [bp-4Ch]@11
  __int16 v63; // [sp+14h] [bp-48h]@11
  __int16 v64; // [sp+18h] [bp-44h]@11
  __int16 v65; // [sp+1Ch] [bp-40h]@11
  signed int v66; // [sp+20h] [bp-3Ch]@1
  tag_message a2; // [sp+24h] [bp-38h]@11
  int v68; // [sp+40h] [bp-1Ch]@21
  int v69; // [sp+44h] [bp-18h]@22
  int v70; // [sp+50h] [bp-Ch]@21
  int v71; // [sp+54h] [bp-8h]@21

  v66 = 1;
  v1 = this;
  *(_BYTE *)(this + 172) = 0;
  *(_BYTE *)(this + 173) = 0;
  *(_BYTE *)(this + 175) = 0;
  *(_BYTE *)(this + 174) = 0;
  *(_WORD *)(this + 68) = 0;
  *(_WORD *)(this + 70) = 0;
  v2 = *(_WORD *)(this + 60);
  v3 = *(_WORD *)(this + 48);
  if ( v2 > v3 )
  {
    v4 = v2 - v3;
    v5 = *(_WORD *)(this + 62);
    *(_WORD *)(v1 + 70) = v2 - v3;
    *(_WORD *)(v1 + 68) = v5;
    if ( v5 < 0 )
      *(_WORD *)(v1 + 68) = 0;
    if ( *(_WORD *)(v1 + 68) > v4 )
      *(_WORD *)(v1 + 68) = v4;
  }
  if ( *(_WORD *)(v1 + 70) <= 0 )
  {
    if ( v2 <= 3 )
      v2 = 3;
    *(_WORD *)(v1 + 50) = v2;
  }
  else
  {
    *(_WORD *)(v1 + 50) = v3;
  }
  v6 = *(_DWORD *)(v1 + 36);
  v7 = *(_WORD *)(v1 + 80);
  v8 = 13 * *(_WORD *)(v1 + 78);
  LOWORD(a2.eventCode) = *(_WORD *)(*(_DWORD *)(v6 + 18) + v8 + 6);
  *(_WORD *)(v1 + 116) = a2.eventCode;
  v9 = *(_WORD *)(v1 + 82);
  LOWORD(v7) = *(_WORD *)(13 * v7 + *(_DWORD *)(v6 + 18) + 6);
  *(_WORD *)(v1 + 118) = v7;
  v10 = *(_WORD *)(v1 + 108);
  v11 = *(_WORD *)(13 * v9 + *(_DWORD *)(v6 + 18) + 6);
  LOWORD(v9) = *(_WORD *)(v1 + 110);
  *(_WORD *)(v1 + 120) = v11;
  v12 = *(_WORD *)(v1 + 114) + v9;
  *(_WORD *)(v1 + 130) = v10;
  *(_WORD *)(v1 + 132) = v12;
  v13 = *(_WORD *)(*(_DWORD *)(v6 + 18) + v8 + 4);
  v14 = a2.eventCode + (_WORD)v7 * (*(_WORD *)(v1 + 50) - 2);
  *(_WORD *)(v1 + 134) = v13;
  v15 = v14 + v11;
  v16 = *(_WORD *)(v1 + 84);
  *(_WORD *)(v1 + 136) = v15;
  v17 = *(_DWORD *)(v6 + 18) + 13 * v16;
  v62 = *(_WORD *)(v17 + 4);
  *(_WORD *)(v1 + 142) = v62;
  v18 = *(_WORD *)(v1 + 88);
  LOWORD(v17) = *(_WORD *)(v17 + 6);
  a2.eventCode = *(_WORD *)(v1 + 88);
  v64 = v17;
  *(_WORD *)(v1 + 144) = v17;
  v19 = *(_DWORD *)(v6 + 18) + a2.eventCode + 12 * v18;
  v65 = *(_WORD *)(v19 + 4);
  *(_WORD *)(v1 + 158) = v65;
  v63 = *(_WORD *)(v19 + 6);
  *(_WORD *)(v1 + 160) = v63;
  *(_WORD *)(v1 + 122) = *(_WORD *)(v1 + 108);
  v20 = *(_WORD *)(v1 + 70) == 0;
  v21 = *(_WORD *)(v1 + 70) < 0;
  *(_WORD *)(v1 + 124) = v12;
  if ( v21 | v20 )
    *(_WORD *)(v1 + 126) = v13;
  else
    *(_WORD *)(v1 + 126) = v13 + v62;
  v20 = *(_WORD *)(v1 + 70) == 0;
  v21 = *(_WORD *)(v1 + 70) < 0;
  *(_WORD *)(v1 + 128) = v15;
  if ( !(v21 | v20) )
  {
    v22 = *(_WORD *)(v1 + 28) + *(_WORD *)(v1 + 24) - v62;
    *(_WORD *)(v1 + 138) = v22;
    *(_WORD *)(v1 + 140) = v12;
    *(_WORD *)(v1 + 154) = v22;
    *(_WORD *)(v1 + 156) = v12 - v63 + v15;
    v23 = v12 - v63 + v15 - (v12 + v64);
    *(_WORD *)(v1 + 146) = v22;
    *(_WORD *)(v1 + 148) = v12 + v64;
    *(_WORD *)(v1 + 150) = v65;
    *(_WORD *)(v1 + 152) = v23;
    *(_WORD *)(v1 + 170) = v23 - *(_WORD *)(v1 + 168) - 7;
  }
  icon::DrawToBuffer(
    (icon *)v6,
    *(_WORD *)(v1 + 100) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40),
    *(_WORD *)(v1 + 102) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44),
    *(_WORD *)(v1 + 76),
    0);
  heroWindowManager::UpdateScreenRegion(
    gpWindowManager,
    *(_WORD *)(v1 + 100) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40),
    *(_WORD *)(v1 + 102) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44),
    *(_WORD *)(v1 + 104),
    *(_WORD *)(v1 + 106));
  v24 = (bitmap *)operator new(26);
  if ( v24 )
    *(_DWORD *)(v1 + 176) = bitmap::bitmap(v24, 0, *(_WORD *)(v1 + 126), *(_WORD *)(v1 + 128));
  else
    *(_DWORD *)(v1 + 176) = 0;
  bitmap::GrabScreen(*(bitmap **)(v1 + 176), *(_WORD *)(v1 + 122), *(_WORD *)(v1 + 124));
LABEL_20:
  dropListWidget::DrawDropStuff(v1);
  while ( 2 )
  {
    PollSound();
    Process1WindowsMessage();
    memcpy(&v68, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
    (*(void (__stdcall **)(int *))(LODWORD(gpMouseManager->vtable) + 8))(&v68);
    v25 = *(_DWORD *)(v1 + 4);
    v26 = *(_DWORD *)(v25 + 40);
    v27 = *(_DWORD *)(v25 + 44);
    v28 = v70 - v26;
    v29 = v71 - v27;
    switch ( v68 )
    {
      default:
        continue;
      case 1:
        v30 = v69 - 71;
        switch ( v69 )
        {
          default:
            continue;
          case 71:
            *(_WORD *)(v1 + 68) = 0;
            *(_WORD *)(v1 + 62) = 0;
            goto LABEL_20;
          case 72:
            v31 = *(_WORD *)(v1 + 62);
            if ( v31 > 0 )
            {
              *(_WORD *)(v1 + 62) = v31 - 1;
              v32 = *(_WORD *)(v1 + 62);
              if ( v32 > 0 )
              {
                if ( *(_WORD *)(v1 + 68) > v32 )
                  *(_WORD *)(v1 + 68) = v32;
              }
            }
            break;
          case 73:
            v33 = *(_WORD *)(v1 + 48);
            v34 = *(_WORD *)(v1 + 68) - v33 + 1;
            *(_WORD *)(v1 + 68) = v34;
            if ( v34 < 0 )
              *(_WORD *)(v1 + 68) = 0;
            v35 = *(_WORD *)(v1 + 62) - v33 + 1;
            *(_WORD *)(v1 + 62) = v35;
            if ( v35 < 0 )
              *(_WORD *)(v1 + 62) = 0;
            break;
          case 79:
            *(_WORD *)(v1 + 68) = *(_WORD *)(v1 + 70);
            *(_WORD *)(v1 + 62) = *(_WORD *)(v1 + 60) - 1;
            break;
          case 80:
            if ( *(_WORD *)(v1 + 60) - 1 > *(_WORD *)(v1 + 62) )
              ++*(_WORD *)(v1 + 62);
            if ( *(_WORD *)(v1 + 48) + (signed int)*(_WORD *)(v1 + 68) - 1 < *(_WORD *)(v1 + 62) )
              *(_WORD *)(v1 + 68) = *(_WORD *)(v1 + 62) - *(_WORD *)(v1 + 48) + 1;
            break;
          case 81:
            LOWORD(v30) = *(_WORD *)(v1 + 68);
            LOWORD(v26) = *(_WORD *)(v1 + 48);
            v36 = v30 + v26 - 1;
            v37 = *(_WORD *)(v1 + 70);
            *(_WORD *)(v1 + 68) = v36;
            if ( v37 < (signed __int16)v36 )
              *(_WORD *)(v1 + 68) = v37;
            LOWORD(v30) = *(_WORD *)(v1 + 62);
            v38 = *(_WORD *)(v1 + 60);
            v39 = v30 + v26 - 1;
            v40 = *(_WORD *)(v1 + 60);
            *(_WORD *)(v1 + 62) = v39;
            if ( v40 - 1 < (signed __int16)v39 )
              *(_WORD *)(v1 + 62) = v38 - 1;
            break;
        }
        goto LABEL_20;
      case 4:
        if ( *(_BYTE *)(v1 + 175) )
        {
          v41 = v29 - *(_WORD *)(v1 + 132);
          v42 = *(_WORD *)(v1 + 116);
          if ( v41 <= v42 )
            v43 = 0;
          else
            v43 = (v41 - v42) / *(_WORD *)(v1 + 118) + 1;
          if ( v43 < 0 )
            v43 = 0;
          v44 = *(_WORD *)(v1 + 50);
          if ( v43 >= v44 )
            v43 = v44 - 1;
          v45 = *(_WORD *)(v1 + 68) + v43;
          if ( *(_WORD *)(v1 + 60) > v45 && *(_WORD *)(v1 + 62) != v45 )
          {
            *(_WORD *)(v1 + 62) = *(_WORD *)(v1 + 68) + v43;
            goto LABEL_20;
          }
        }
        else if ( *(_BYTE *)(v1 + 174) )
        {
          v46 = *(_WORD *)(v1 + 70);
          v47 = (v46 + 1) * (v29 - *(_WORD *)(v1 + 168) / 2 - *(_WORD *)(v1 + 148) - 4) / *(_WORD *)(v1 + 170);
          if ( v47 < 0 )
            v47 = 0;
          if ( v47 > v46 )
            v47 = *(_WORD *)(v1 + 70);
          if ( *(_WORD *)(v1 + 68) != v47 )
          {
            *(_WORD *)(v1 + 68) = v47;
            goto LABEL_20;
          }
        }
        continue;
      case 8:
        v48 = *(_WORD *)(v1 + 122);
        if ( v28 < v48 )
          goto LABEL_95;
        v49 = *(_WORD *)(v1 + 124);
        if ( v29 < v49 || v48 + *(_WORD *)(v1 + 126) <= v28 || v49 + *(_WORD *)(v1 + 128) <= v29 )
          goto LABEL_95;
        v50 = *(_WORD *)(v1 + 130);
        if ( v28 < v50
          || (v51 = *(_WORD *)(v1 + 132), v29 < v51)
          || v50 + *(_WORD *)(v1 + 134) <= v28
          || v51 + *(_WORD *)(v1 + 136) <= v29 )
        {
          if ( *(_WORD *)(v1 + 144) + (signed int)*(_WORD *)(v1 + 140) <= v29 )
          {
            if ( *(_WORD *)(v1 + 156) > v29 )
            {
              v58 = *(_WORD *)(v1 + 164);
              if ( v29 >= v58 && v58 + *(_WORD *)(v1 + 168) > v29 )
                *(_BYTE *)(v1 + 174) = 1;
              v59 = *(_WORD *)(v1 + 70);
              v60 = (*(_WORD *)(v1 + 70) + 1)
                  * (v29 - *(_WORD *)(v1 + 168) / 2 - *(_WORD *)(v1 + 148) - 4)
                  / *(_WORD *)(v1 + 170);
              *(_WORD *)(v1 + 68) = v60;
              if ( (signed __int16)v60 < 0 )
                *(_WORD *)(v1 + 68) = 0;
              if ( *(_WORD *)(v1 + 68) > v59 )
                *(_WORD *)(v1 + 68) = v59;
            }
            else
            {
              v57 = *(_WORD *)(v1 + 68);
              if ( *(_WORD *)(v1 + 70) > v57 )
                *(_WORD *)(v1 + 68) = v57 + 1;
              *(_BYTE *)(v1 + 173) = 1;
            }
          }
          else
          {
            v56 = *(_WORD *)(v1 + 68);
            if ( v56 > 0 )
              *(_WORD *)(v1 + 68) = v56 - 1;
            *(_BYTE *)(v1 + 172) = 1;
          }
          goto LABEL_20;
        }
        v52 = v29;
        v53 = *(_WORD *)(v1 + 116);
        v54 = v52 - v51;
        if ( v54 <= v53 )
          v55 = *(_WORD *)(v1 + 68);
        else
          v55 = *(_WORD *)(v1 + 68) + (v54 - v53) / *(_WORD *)(v1 + 118) + 1;
        *(_BYTE *)(v1 + 175) = 1;
        if ( *(_WORD *)(v1 + 60) > v55 && *(_WORD *)(v1 + 62) != v55 )
        {
          *(_WORD *)(v1 + 62) = v55;
          goto LABEL_20;
        }
        continue;
      case 16:
        if ( v66 )
        {
          v66 = 0;
          icon::DrawToBuffer(
            *(icon **)(v1 + 36),
            v26 + *(_WORD *)(v1 + 100),
            v27 + *(_WORD *)(v1 + 102),
            *(_WORD *)(v1 + 74),
            0);
          heroWindowManager::UpdateScreenRegion(
            gpWindowManager,
            *(_WORD *)(v1 + 100) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40),
            *(_WORD *)(v1 + 102) + *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44),
            *(_WORD *)(v1 + 104),
            *(_WORD *)(v1 + 106));
          continue;
        }
        if ( !*(_BYTE *)(v1 + 175) )
        {
          if ( *(_BYTE *)(v1 + 172) || *(_BYTE *)(v1 + 173) || *(_BYTE *)(v1 + 174) )
          {
            *(_BYTE *)(v1 + 174) = 0;
            *(_BYTE *)(v1 + 173) = 0;
            *(_BYTE *)(v1 + 172) = 0;
            goto LABEL_20;
          }
          continue;
        }
LABEL_95:
        bitmap::DrawToBuffer(*(bitmap **)(v1 + 176), *(_WORD *)(v1 + 122), *(_WORD *)(v1 + 124));
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          *(_WORD *)(v1 + 122),
          *(_WORD *)(v1 + 124),
          *(_WORD *)(v1 + 126),
          *(_WORD *)(v1 + 128));
        v61 = *(_DWORD *)(v1 + 176);
        if ( v61 )
          (**(void (__stdcall ***)(_DWORD))v61)(1);
        *(_DWORD *)(v1 + 176) = 0;
        (**(void (__thiscall ***)(_DWORD))v1)(v1);
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 24),
          *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 26),
          *(_WORD *)(v1 + 28),
          *(_WORD *)(v1 + 30));
        return;
    }
  }
}