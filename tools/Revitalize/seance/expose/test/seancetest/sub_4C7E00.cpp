void __thiscall sub_4C7E00(HeroWindowManager *this, int x, int y, int width, int height, int delay, const void *a7, int a8)
{
  int v8; // ecx@2
  int v9; // eax@4
  int v10; // eax@12
  Bitmap *v11; // eax@14
  void *v12; // ebp@17
  int v13; // eax@18
  int v14; // eax@20
  int v15; // esi@20
  int v16; // ecx@20
  int v17; // edi@21
  __int16 v18; // dx@22
  __int16 v19; // bx@22
  signed int v20; // esi@25
  __int64 v21; // qax@26
  AbstractResource *v22; // ecx@29
  HeroWindowManager *v23; // [sp+10h] [bp-2Ch]@1
  Bitmap **v24; // [sp+14h] [bp-28h]@15
  signed int v25; // [sp+18h] [bp-24h]@17
  int v26; // [sp+1Ch] [bp-20h]@18
  void *pal; // [sp+20h] [bp-1Ch]@14
  int v28; // [sp+24h] [bp-18h]@19
  int v29; // [sp+28h] [bp-14h]@19
  int v30; // [sp+2Ch] [bp-10h]@2
  int v31; // [sp+30h] [bp-Ch]@17
  int v32; // [sp+38h] [bp-4h]@12

  v23 = this;
  if ( dword_524C14 )
  {
    v8 = x;
    fullScreenRelated = 0;
    v30 = 0;
    if ( x < 0 )
    {
      x = 0;
      width += v8;
    }
    v9 = y;
    if ( y < 0 )
    {
      y = 0;
      height += v9;
    }
    if ( x + width > 640 )
      width = 640 - x;
    if ( y + height > 480 )
      height = 480 - y;
    if ( width > 0 && height > 0 )
    {
      v10 = v23->field_56;
      v23->field_56 = 0;
      v32 = v10;
      if ( delay == -1 )
        delay = 150;
      pal = KBAlloc(0x300u, "F:\\h2xsrc\\Base\\WINMGR.CPP", 808);
      v11 = (Bitmap *)operator new(0x1Au);
      if ( v11 )
      {
        v24 = (Bitmap **)&v23->field_4E;
        v23->field_4E = Bitmap_constructor(v11, 0, width, height);
      }
      else
      {
        v23->field_4E = 0;
        v24 = (Bitmap **)&v23->field_4E;
      }
      v12 = KBAlloc(0x10000u, "F:\\h2xsrc\\Base\\WINMGR.CPP", 810);
      blit(v23->screenBuffer, x, y, width, height, *v24, 0, 0);
      v25 = 0;
      v31 = height + y;
      do
      {
        sprintf(globBuf, "CCYCLE%02d.BIN", v25);
        v13 = ResourceManager::setResource(resourceManager, globBuf, 1);
        ResourceManager::pointToFile(resourceManager, v13);
        ResourceManager::readFromCurrentFile(resourceManager, v12, 0x10000u);
        v26 = y;
        if ( y < v31 )
        {
          v28 = 640 * y;
          v29 = 0;
          do
          {
            v14 = (int)&v23->someBMP->contents[v23->someBMP->width * (v26 - y)];
            v15 = (int)(&v23->screenBuffer->contents[x] + v28);
            v16 = (int)&(*v24)->contents[v29];
            if ( x < width + x )
            {
              v17 = width;
              do
              {
                v18 = *(_BYTE *)v16;
                v19 = *(_BYTE *)v14++ << 8;
                ++v16;
                ++v15;
                --v17;
                *(_BYTE *)(v15 - 1) = *((_BYTE *)v12 + (unsigned __int16)(v18 | v19));
              }
              while ( v17 );
            }
            v28 += 640;
            v29 += width;
            ++v26;
          }
          while ( v26 < v31 );
        }
        yieldToGlobalUpdater();
        sleepUntil(v30 + delay);
        v30 = getTickCount();
        renderBitmapToScreenWithWinG(v23->screenBuffer, x, y, width, height, x, y);
        if ( a7 )
        {
          memcpy(pal, a7, 0x300u);
          v20 = 0;
          do
          {
            v21 = (v25 + 1) * ((signed int)*(_BYTE *)(a8 + v20) - (signed int)*((_BYTE *)a7 + v20));
            ++v20;
            *((_BYTE *)pal + v20 - 1) += ((BYTE4(v21) & 7) + (signed int)v21) >> 3;
          }
          while ( v20 < 768 );
          sub_49CFB0((PaletteContents *)pal);
        }
        yieldToGlobalUpdater();
        ++v25;
      }
      while ( v25 < 8 );
      sleepUntil(v30 + delay);
      blit(*v24, 0, 0, width, height, v23->screenBuffer, x, y);
      renderBitmapToScreenWithWinG(v23->screenBuffer, x, y, width, height, x, y);
      fullScreenRelated = 1;
      v23->field_56 = v32;
      v22 = (AbstractResource *)v23->someBMP;
      if ( v22 )
        v22->vtable->cleanUp(v22, 1);
      v23->someBMP = 0;
      if ( *v24 )
        (*v24)->vtable->cleanUp((AbstractResource *)*v24, 1);
      *v24 = 0;
      KBFree(v12, (int)"F:\\h2xsrc\\Base\\WINMGR.CPP", 897);
      KBFree(pal, (int)"F:\\h2xsrc\\Base\\WINMGR.CPP", 898);
    }
  }
}
