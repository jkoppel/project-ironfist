{
  heroWindow *v2; // eax@1
  listBox *thisa; // esi@1
  int v4; // edi@1
  int v5; // ebx@1
  signed int i; // ebp@1
  int v7; // eax@5
  int v8; // eax@8
  int v9; // eax@12
  int v10; // eax@17
  int v11; // eax@24
  int v12; // edi@26
  int v13; // ebx@27
  int v14; // eax@29
  int v15; // eax@31
  heroWindow *v16; // ebx@31
  int v17; // edi@31
  __int16 v18; // cx@31
  int v19; // eax@32
  int v20; // ecx@34
  int v21; // ST14_4@34
  int v22; // eax@34
  int v23; // [sp+10h] [bp-8h]@11
  int v24; // [sp+10h] [bp-8h]@16

  v2 = this->parentWindow;
  thisa = this;
  v4 = v2->xOffset + this->field_44[14];
  v5 = v2->yOffset + this->field_44[15];
  for ( i = 0; thisa->field_28 > i; ++i )
  {
    if ( i )
    {
      if ( thisa->field_28 - i == 1 )
      {
        icon::DrawToBuffer(thisa->icon, v4, v5, thisa->field_44[2], 0);
        if ( thisa->field_2A > i )
        {
          v23 = i + thisa->field_40;
          if ( thisa->field_34 == v23 )
            v9 = thisa->field_2E;
          else
            v9 = thisa->field_2C;
          font::DrawBoundedString(
            (font *)thisa->fontID,
            *(const char **)(*(_DWORD *)&thisa->field_3C + 4 * v23),
            v4 + 5,
            v5 + 2,
            thisa->field_44[16] - 10,
            *(_DWORD *)(thisa->fontID + 16) + 1,
            v9,
            thisa->field_30);
        }
        continue;
      }
      icon::DrawToBuffer(thisa->icon, v4, v5, thisa->field_44[1], 0);
      if ( thisa->field_2A > i )
      {
        v24 = i + thisa->field_40;
        if ( thisa->field_34 == v24 )
          v10 = thisa->field_2E;
        else
          v10 = thisa->field_2C;
        font::DrawBoundedString(
          (font *)thisa->fontID,
          *(const char **)(*(_DWORD *)&thisa->field_3C + 4 * v24),
          v4 + 5,
          v5 + 2,
          thisa->field_44[16] - 10,
          *(_DWORD *)(thisa->fontID + 16) + 1,
          v10,
          thisa->field_30);
      }
      v8 = thisa->field_44[12];
    }
    else
    {
      icon::DrawToBuffer(thisa->icon, v4, v5, thisa->field_44[0], 0);
      if ( thisa->field_2A > 0 )
      {
        if ( thisa->field_34 == thisa->field_40 )
          v7 = thisa->field_2E;
        else
          v7 = thisa->field_2C;
        font::DrawBoundedString(
          (font *)thisa->fontID,
          *(const char **)(*(_DWORD *)&thisa->field_3C + 4 * thisa->field_40),
          v4 + 5,
          v5 + 4,
          thisa->field_44[16] - 10,
          *(_DWORD *)(thisa->fontID + 16) + 1,
          v7,
          thisa->field_30);
      }
      v8 = thisa->field_44[11];
    }
    v5 += v8;
  }
  if ( LOBYTE(thisa->field_72[12]) )
    v11 = thisa->field_44[4];
  else
    v11 = thisa->field_44[3];
  icon::DrawToBuffer(
    thisa->icon,
    thisa->parentWindow->xOffset + thisa->field_44[18],
    thisa->parentWindow->yOffset + thisa->field_44[19],
    v11,
    0);
  v12 = 2;
  icon::DrawToBuffer(
    thisa->icon,
    thisa->field_44[22] + thisa->parentWindow->xOffset,
    thisa->field_72[0] + thisa->parentWindow->yOffset,
    thisa->field_44[7],
    0);
  if ( thisa->field_28 - 2 > 2 )
  {
    do
    {
      v13 = v12++ - 1;
      icon::DrawToBuffer(
        thisa->icon,
        thisa->field_44[22] + thisa->parentWindow->xOffset,
        thisa->field_72[0] + thisa->parentWindow->yOffset + v13 * thisa->field_44[12],
        thisa->field_44[8],
        0);
    }
    while ( thisa->field_28 - 2 > v12 );
  }
  icon::DrawToBuffer(
    thisa->icon,
    thisa->field_44[22] + thisa->parentWindow->xOffset,
    thisa->field_72[0] + thisa->parentWindow->yOffset + (v12 - 1) * thisa->field_44[12],
    thisa->field_44[9],
    0);
  if ( HIBYTE(thisa->field_72[12]) )
    v14 = thisa->field_44[6];
  else
    v14 = thisa->field_44[5];
  v15 = icon::DrawToBuffer(
          thisa->icon,
          thisa->parentWindow->xOffset + thisa->field_72[3],
          thisa->parentWindow->yOffset + thisa->field_72[4],
          v14,
          0);
  LOWORD(v15) = thisa->field_44[22];
  v16 = thisa->parentWindow;
  v17 = v16->xOffset + v15 + 5;
  v18 = thisa->field_42;
  thisa->field_72[7] = v17;
  if ( v18 <= 0 )
    v19 = thisa->field_72[11] / 2;
  else
    v19 = thisa->field_72[11] * thisa->field_40 / v18;
  v20 = v16->yOffset;
  LOWORD(v20) = thisa->field_72[0] + v20;
  v21 = thisa->field_44[10];
  v22 = v20 + v19 + 3;
  thisa->field_72[8] = v22;
  icon::DrawToBuffer(thisa->icon, (signed __int16)v17, (signed __int16)v22, v21, 0);
  if ( a2 )
    heroWindowManager::UpdateScreenRegion(
      gpWindowManager,
      thisa->parentWindow->xOffset + thisa->offsetX,
      thisa->parentWindow->yOffset + thisa->offsetY,
      thisa->width,
      thisa->height);
}