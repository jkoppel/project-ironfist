{
  int spriteIdx; // esi@2
  int v3; // eax@11
  char v4; // sf@11
  int v5; // eax@11
  int v6; // ecx@12
  int v7; // edi@16
  MOUSE_CURSOR_CATEGORY v8; // eax@17
  int fileID; // eax@22
  signed int v10; // eax@22
  int v11; // edi@22
  signed int v12; // esi@23
  int v13; // ebx@24
  void *v14; // ecx@24
  DWORD v15; // edx@31
  int cursorIdxa; // eax@31
  const char *v17; // [sp-8h] [bp-2Ch]@18
  int v18; // [sp-4h] [bp-28h]@18
  mouseManager *thisa; // [sp+10h] [bp-14h]@1
  char filename; // [sp+14h] [bp-10h]@22

  thisa = this;
  if ( !this->field_7E )
  {
    spriteIdx = spriteIdxArg;
    if ( spriteIdxArg >= 0 )
    {
      if ( this->ready == 1 && this->spriteIdx != spriteIdxArg && !gbInSetPointer )
      {
        gbInSetPointer = 1;
        ++gbPutzingWithMouseCtr;
        resourceManager::SavePosition(gpResourceManager);
        if ( giCurExe == 1 )
          thisa->cursorCategory = 0;
        if ( spriteIdxArg == 1000 )
          spriteIdx = thisa->spriteIdx;
        else
          thisa->spriteIdx = spriteIdxArg;
        v3 = iMouseOffset[thisa->cursorCategory];
        v4 = spriteIdx + v3 < 0;
        v5 = spriteIdx + v3;
        thisa->cursorIdx = v5;
        if ( v4 || (v6 = 1, v5 >= 96) )
          v6 = 0;
        ProcessAssert(v6, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 458);
        if ( gbColorMice )
        {
          mouseManager::NewUpdate(thisa, 1);
        }
        else
        {
          v7 = thisa->cursorIdx;
          if ( !*(HCURSOR *)((char *)&hMouseCursor + v7 * 4) )
          {
            cColorBits[v7] = BaseAlloc(0x400u, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 480);
            cAndBits[thisa->cursorIdx] = BaseAlloc(0x100u, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 481);
            v8 = thisa->cursorCategory;
            if ( v8 )
            {
              if ( v8 == 2 )
              {
                v18 = spriteIdx;
                v17 = "SPELBW%02d.BMP";
              }
              else
              {
                v18 = spriteIdx + 1;
                v17 = "CMSEBW%02d.BMP";
              }
            }
            else
            {
              v18 = spriteIdx + 1;
              v17 = "ADVMBW%02d.BMP";
            }
            sprintf(&filename, v17, v18);
            fileID = resourceManager::MakeId(gpResourceManager, &filename, 1);
            resourceManager::PointToFile(gpResourceManager, fileID);
            resourceManager::ReadBlock(gpResourceManager, cColorBits[thisa->cursorIdx], 6u);
            resourceManager::ReadBlock(gpResourceManager, cColorBits[thisa->cursorIdx], 0x400u);
            v10 = 0;
            memset(cAndBits[thisa->cursorIdx], 0, 0x100u);
            v11 = 0;
            do
            {
              v12 = 0;
              do
              {
                v13 = thisa->cursorIdx;
                v14 = cColorBits[v13];
                if ( *((_BYTE *)v14 + v12 + v10) )
                {
                  if ( *((_BYTE *)v14 + v12 + v10) == 1 )
                    *((_BYTE *)cAndBits[v13] + (v12 >> 3) + v11 + 128) |= 1 << (7 - (v12 & 7));
                }
                else
                {
                  *((_BYTE *)cAndBits[v13] + (v12 >> 3) + v11) |= 1 << (7 - (v12 & 7));
                }
                ++v12;
              }
              while ( v12 < 32 );
              v11 += 4;
              v10 += 32;
            }
            while ( v10 < 1024 );
            *(&bmpAndMask.bmType + 6 * thisa->cursorIdx) = 0;
            dword_5330BC[6 * thisa->cursorIdx] = 32;
            dword_5330C0[6 * thisa->cursorIdx] = 64;
            dword_5330C4[6 * thisa->cursorIdx] = 4;
            word_5330C8[12 * thisa->cursorIdx] = 1;
            word_5330CA[12 * thisa->cursorIdx] = 1;
            dword_5330C4[6 * thisa->cursorIdx] = 4;
            dword_5330CC[6 * thisa->cursorIdx] = (int)cAndBits[thisa->cursorIdx];
            hbmpAndMask[thisa->cursorIdx] = CreateBitmapIndirect(&bmpAndMask + thisa->cursorIdx);
            ProcessAssert((int)hbmpAndMask[thisa->cursorIdx], "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 514);
            IconInfo[thisa->cursorIdx].fIcon = 0;
            if ( thisa->cursorCategory == 2 )
            {
              v15 = 15;
              IconInfo[thisa->cursorIdx].xHotspot = 15;
              cursorIdxa = thisa->cursorIdx;
            }
            else
            {
              IconInfo[thisa->cursorIdx].xHotspot = iHotSpot[thisa->cursorIdx].x;
              cursorIdxa = thisa->cursorIdx;
              v15 = iHotSpot[cursorIdxa].y;
            }
            IconInfo[cursorIdxa].yHotspot = v15;
            IconInfo[thisa->cursorIdx].hbmMask = hbmpAndMask[thisa->cursorIdx];
            IconInfo[thisa->cursorIdx].hbmColor = 0;
            *(&hMouseCursor + thisa->cursorIdx) = CreateIconIndirect(&IconInfo[thisa->cursorIdx]);
            ProcessAssert((int)*(&hMouseCursor + thisa->cursorIdx), "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 533);
          }
          SetCursor(*(&hMouseCursor + thisa->cursorIdx));
        }
        resourceManager::RestorePosition(gpResourceManager);
        gbInSetPointer = 0;
        --gbPutzingWithMouseCtr;
      }
    }
  }
}