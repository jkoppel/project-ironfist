{
  signed int result; // eax@3
  __int16 v2; // ST1C_2@36
  char *v3; // ST10_4@36
  __int16 v4; // bx@36
  __int16 v5; // ax@36
  void *v6; // [sp+Ch] [bp-90h]@1
  TextWidget *thisa; // [sp+10h] [bp-8Ch]@35
  GUIIcon *v8; // [sp+14h] [bp-88h]@30
  GUIIcon *v9; // [sp+18h] [bp-84h]@4
  char v10; // [sp+1Ch] [bp-80h]@18
  char v11; // [sp+1Dh] [bp-7Fh]@18
  char v12; // [sp+1Eh] [bp-7Eh]@18
  char v13; // [sp+1Fh] [bp-7Dh]@18
  char v14; // [sp+20h] [bp-7Ch]@18
  char v15; // [sp+21h] [bp-7Bh]@18
  char v16; // [sp+22h] [bp-7Ah]@18
  char v17; // [sp+23h] [bp-79h]@18
  char v18; // [sp+24h] [bp-78h]@18
  char v19; // [sp+25h] [bp-77h]@18
  char v20; // [sp+26h] [bp-76h]@18
  char v21; // [sp+27h] [bp-75h]@18
  char v22; // [sp+28h] [bp-74h]@18
  char v23; // [sp+29h] [bp-73h]@18
  char v24; // [sp+2Ah] [bp-72h]@18
  char v25; // [sp+2Bh] [bp-71h]@18
  char v26; // [sp+2Ch] [bp-70h]@18
  char v27; // [sp+2Dh] [bp-6Fh]@18
  char v28; // [sp+2Eh] [bp-6Eh]@18
  char v29; // [sp+2Fh] [bp-6Dh]@18
  char v30; // [sp+30h] [bp-6Ch]@18
  char v31; // [sp+31h] [bp-6Bh]@18
  char v32; // [sp+32h] [bp-6Ah]@18
  char v33; // [sp+33h] [bp-69h]@18
  char v34; // [sp+34h] [bp-68h]@18
  char v35; // [sp+35h] [bp-67h]@18
  char v36; // [sp+36h] [bp-66h]@18
  char v37; // [sp+37h] [bp-65h]@18
  char v38; // [sp+38h] [bp-64h]@18
  char v39; // [sp+39h] [bp-63h]@18
  char v40; // [sp+3Ah] [bp-62h]@18
  char v41; // [sp+3Bh] [bp-61h]@18
  char v42; // [sp+3Ch] [bp-60h]@18
  char v43; // [sp+3Dh] [bp-5Fh]@18
  char v44; // [sp+3Eh] [bp-5Eh]@18
  char v45; // [sp+3Fh] [bp-5Dh]@18
  char v46; // [sp+40h] [bp-5Ch]@18
  char v47; // [sp+41h] [bp-5Bh]@18
  char v48; // [sp+42h] [bp-5Ah]@18
  char v49; // [sp+43h] [bp-59h]@18
  char v50; // [sp+44h] [bp-58h]@18
  ICNHeader *v51; // [sp+4Ch] [bp-50h]@21
  __int16 imgIdx[2]; // [sp+50h] [bp-4Ch]@17
  int v53; // [sp+54h] [bp-48h]@28
  int v54; // [sp+58h] [bp-44h]@28
  int v55; // [sp+5Ch] [bp-40h]@15
  int v56; // [sp+60h] [bp-3Ch]@21
  Icon *res; // [sp+64h] [bp-38h]@15
  int v58; // [sp+6Ch] [bp-30h]@21
  char str[20]; // [sp+70h] [bp-2Ch]@18
  int i; // [sp+84h] [bp-18h]@9
  Hero *v61; // [sp+88h] [bp-14h]@4
  int v62; // [sp+8Ch] [bp-10h]@21
  int v63; // [sp+90h] [bp-Ch]@21
  int v64; // [sp+94h] [bp-8h]@4
  int v65; // [sp+98h] [bp-4h]@30

  v6 = this;
  if ( dword_50EAB0 || dword_50EAA0 != 3 )
  {
    sub_44D610(this);
    dword_50EAA0 = 3;
    v61 = &gameObject->heroes[curPlayer->_1[0]];
    v64 = 0;
    v9 = (GUIIcon *)operator new(0x2Du);
    if ( v9 )
      *(_DWORD *)((char *)v6 + 58) = GUIIcon_constructor(v9, 480, 392, 143, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v6 + 58) = 0;
    if ( !*(_DWORD *)((char *)v6 + 58) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v6 + 154), *(AbstractGUIComponent **)((char *)v6 + 58), -1);
    for ( i = 0; i < 5; ++i )
    {
      if ( v61->army.creatureTypes[i] != -1 )
        ++v64;
    }
    if ( v64 )
    {
      v55 = 0;
      res = ResourceManager::getIconByFilename(resourceManager, "mons32.icn");
      for ( i = 0; i < 5; ++i )
      {
        *(_DWORD *)imgIdx = v61->army.creatureTypes[i];
        if ( *(_DWORD *)imgIdx != -1 )
        {
          v10 = 50;
          v11 = 3;
          v12 = 96;
          v13 = 3;
          v14 = 50;
          v15 = 17;
          v16 = 73;
          v17 = 17;
          v18 = 96;
          v19 = 17;
          v20 = 27;
          v21 = 32;
          v22 = 73;
          v23 = 32;
          v24 = 119;
          v25 = 32;
          v26 = 3;
          v27 = -1;
          v28 = -1;
          v29 = -1;
          v30 = -1;
          v31 = 2;
          v32 = 4;
          v33 = -1;
          v34 = -1;
          v35 = -1;
          v36 = 0;
          v37 = 1;
          v38 = 6;
          v39 = -1;
          v40 = -1;
          v41 = 0;
          v42 = 1;
          v43 = 5;
          v44 = 6;
          v45 = -1;
          v46 = 0;
          v47 = 1;
          v48 = 5;
          v49 = 6;
          v50 = 7;
          *(_DWORD *)&str[4 * v55] = KBAlloc(6u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F5A0 + 68);
          if ( v61->army.quantities[i] <= 1999 )
            sprintf(*(char **)&str[4 * v55], "%d", v61->army.quantities[i]);
          else
            sprintf(*(char **)&str[4 * v55], "%dk", v61->army.quantities[i] / 1000);
          v56 = *(&v26 + 5 * v64 + v55 - 5);
          v63 = (unsigned __int8)*(&v10 + 2 * v56);
          v62 = (unsigned __int8)*(&v11 + 2 * v56);
          v58 = v62 + 25;
          v51 = &res->headersAndImageData[*(_DWORD *)imgIdx];
          if ( v56 && v56 != 1 )
          {
            if ( v51->height < 37 )
              v62 += 37 - v51->height;
          }
          else
          {
            v58 -= 2;
            if ( v51->height < 35 )
              v62 += 35 - v51->height;
          }
          v53 = Font::getFlattenedStringWidth(smallFont, *(const char **)&str[4 * v55]);
          v54 = v53 + v51->width;
          if ( v54 > 45 )
            v54 = 45;
          v63 -= (v54 + 1) / 2;
          v65 = v63 + v54 - 1 - (v53 - 1);
          v8 = (GUIIcon *)operator new(0x2Du);
          if ( v8 )
            *(_DWORD *)((char *)v6 + 4 * v55 + 66) = GUIIcon_constructor(
                                                       v8,
                                                       v63 + 480,
                                                       v62 + 392,
                                                       32,
                                                       28,
                                                       "mons32.icn",
                                                       imgIdx[0],
                                                       0,
                                                       v55 + 2002,
                                                       16,
                                                       1);
          else
            *(_DWORD *)((char *)v6 + 4 * v55 + 66) = 0;
          if ( !*(_DWORD *)((char *)v6 + 4 * v55 + 66) )
            fatalOutOfMemoryError();
          thisa = (TextWidget *)operator new(0x2Bu);
          if ( thisa )
          {
            v2 = v55 + 2101;
            v3 = *(char **)&str[4 * v55];
            v4 = ((v61->army.quantities[i] <= 1999) - 1) & 4;
            v5 = strlen(*(const char **)&str[4 * v55]);
            *(_DWORD *)((char *)v6 + 4 * v55 + 110) = TextWidget_constructor(
                                                        thisa,
                                                        v65 + 480,
                                                        v58 + 392,
                                                        5 * v5 + v4,
                                                        12,
                                                        v3,
                                                        "smalfont.fnt",
                                                        1,
                                                        v2,
                                                        512,
                                                        1);
          }
          else
          {
            *(_DWORD *)((char *)v6 + 4 * v55 + 110) = 0;
          }
          if ( !*(_DWORD *)((char *)v6 + 4 * v55 + 110) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(
            *(GUIWindow **)((char *)v6 + 154),
            *(AbstractGUIComponent **)((char *)v6 + 4 * v55 + 66),
            -1);
          GUIWindow::insertElement(
            *(GUIWindow **)((char *)v6 + 154),
            *(AbstractGUIComponent **)((char *)v6 + 4 * v55++ + 110),
            -1);
        }
      }
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
