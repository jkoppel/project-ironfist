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
  MouseManager *thisa; // [sp+10h] [bp-14h]@1
  char filename; // [sp+14h] [bp-10h]@22

  thisa = this;
  if ( !this->field_7E )
  {
    spriteIdx = spriteIdxArg;
    if ( spriteIdxArg >= 0 )
    {
      if ( this->ready == 1 && this->spriteIdx != spriteIdxArg && !dword_51F568 )
      {
        dword_51F568 = 1;
        ++mouseSemaphore1;
        ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
        if ( gameOrEditorIdx == 1 )
          thisa->cursorCategory = 0;
        if ( spriteIdxArg == 1000 )
          spriteIdx = thisa->spriteIdx;
        else
          thisa->spriteIdx = spriteIdxArg;
        v3 = dword_51F3D8[thisa->cursorCategory];
        v4 = spriteIdx + v3 < 0;
        v5 = spriteIdx + v3;
        thisa->cursorIdx = v5;
        if ( v4 || (v6 = 1, v5 >= 96) )
          v6 = 0;
        assertTrue(v6, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 458);
        if ( dword_4F19B0 )
        {
          sub_4CE410(thisa, 1);
        }
        else
        {
          v7 = thisa->cursorIdx;
          if ( !*(HCURSOR *)((char *)&cursorCache + v7 * 4) )
          {
            cursorBitmapFileContents[v7] = KBAlloc(0x400u, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 480);
            cursorBmBits[thisa->cursorIdx] = KBAlloc(0x100u, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 481);
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
            fileID = ResourceManager::setResource(resourceManager, &filename, 1);
            ResourceManager::pointToFile(resourceManager, fileID);
            ResourceManager::readFromCurrentFile(resourceManager, cursorBitmapFileContents[thisa->cursorIdx], 6u);
            ResourceManager::readFromCurrentFile(resourceManager, cursorBitmapFileContents[thisa->cursorIdx], 0x400u);
            v10 = 0;
            memset(cursorBmBits[thisa->cursorIdx], 0, 0x100u);
            v11 = 0;
            do
            {
              v12 = 0;
              do
              {
                v13 = thisa->cursorIdx;
                v14 = cursorBitmapFileContents[v13];
                if ( *((_BYTE *)v14 + v12 + v10) )
                {
                  if ( *((_BYTE *)v14 + v12 + v10) == 1 )
                    *((_BYTE *)cursorBmBits[v13] + (v12 >> 3) + v11 + 128) |= 1 << (7 - (v12 & 7));
                }
                else
                {
                  *((_BYTE *)cursorBmBits[v13] + (v12 >> 3) + v11) |= 1 << (7 - (v12 & 7));
                }
                ++v12;
              }
              while ( v12 < 32 );
              v11 += 4;
              v10 += 32;
            }
            while ( v10 < 1024 );
            *(&cursorBITMAPs.bmType + 6 * thisa->cursorIdx) = 0;
            dword_5330BC[6 * thisa->cursorIdx] = 32;
            dword_5330C0[6 * thisa->cursorIdx] = 64;
            dword_5330C4[6 * thisa->cursorIdx] = 4;
            word_5330C8[12 * thisa->cursorIdx] = 1;
            word_5330CA[12 * thisa->cursorIdx] = 1;
            dword_5330C4[6 * thisa->cursorIdx] = 4;
            dword_5330CC[6 * thisa->cursorIdx] = (int)cursorBmBits[thisa->cursorIdx];
            dword_533B40[thisa->cursorIdx] = CreateBitmapIndirect(&cursorBITMAPs + thisa->cursorIdx);
            assertTrue((int)dword_533B40[thisa->cursorIdx], "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 514);
            cursorICONINFOs[thisa->cursorIdx].fIcon = 0;
            if ( thisa->cursorCategory == 2 )
            {
              v15 = 15;
              cursorICONINFOs[thisa->cursorIdx].xHotspot = 15;
              cursorIdxa = thisa->cursorIdx;
            }
            else
            {
              cursorICONINFOs[thisa->cursorIdx].xHotspot = cursorHotspots[thisa->cursorIdx].x;
              cursorIdxa = thisa->cursorIdx;
              v15 = cursorHotspots[cursorIdxa].y;
            }
            cursorICONINFOs[cursorIdxa].yHotspot = v15;
            cursorICONINFOs[thisa->cursorIdx].hbmMask = dword_533B40[thisa->cursorIdx];
            cursorICONINFOs[thisa->cursorIdx].hbmColor = 0;
            *(&cursorCache + thisa->cursorIdx) = CreateIconIndirect(&cursorICONINFOs[thisa->cursorIdx]);
            assertTrue((int)*(&cursorCache + thisa->cursorIdx), "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 533);
          }
          SetCursor(*(&cursorCache + thisa->cursorIdx));
        }
        ResourceManager::popFileAndOffsetOffStack(resourceManager);
        dword_51F568 = 0;
        --mouseSemaphore1;
      }
    }
  }
}
