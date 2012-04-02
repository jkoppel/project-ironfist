int __stdcall sub_4B1570(__int64 a1, int a2, __int64 a3, int a4, __int64 a5, int a6, int a7)
{
  signed int v7; // eax@4
  int v8; // eax@9
  int v9; // eax@14
  int result; // eax@28
  wchar_t v11[2]; // [sp+24h] [bp-B0h]@63
  char prefix; // [sp+28h] [bp-ACh]@65
  int v13; // [sp+8Ch] [bp-48h]@61
  int v14; // [sp+94h] [bp-40h]@1
  int v15; // [sp+98h] [bp-3Ch]@15
  int v16; // [sp+9Ch] [bp-38h]@3
  int v17; // [sp+A0h] [bp-34h]@1
  char v18; // [sp+A4h] [bp-30h]@4
  int v19; // [sp+A8h] [bp-2Ch]@3
  int v20; // [sp+ACh] [bp-28h]@1
  int v21; // [sp+B0h] [bp-24h]@1
  int v22; // [sp+B4h] [bp-20h]@1
  int v23; // [sp+B8h] [bp-1Ch]@8
  int v24; // [sp+BCh] [bp-18h]@1
  int v25; // [sp+C0h] [bp-14h]@1
  int v26; // [sp+C4h] [bp-10h]@1
  unsigned int v27; // [sp+C8h] [bp-Ch]@13
  float v28; // [sp+CCh] [bp-8h]@41
  unsigned int v29; // [sp+D0h] [bp-4h]@13

  v20 = 0;
  v14 = 100;
  v25 = 100;
  v17 = *(_BYTE *)(usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1)) + 9);
  v22 = v17 & 0x7F;
  v24 = 100;
  v21 = 100;
  v26 = 100;
  if ( abs(a1 - dword_51D5BC->x) > 1 || abs(HIDWORD(a1) - dword_51D5BC->y) > 1 )
  {
    v19 = sub_4B1B60(*(_QWORD *)&dword_51D5BC->x, 0, 1, (int)&v18, 0);
    v7 = sub_4B1B60(a1, 0, 1, (int)&v14, a7);
    v16 = v7 - v19;
  }
  else
  {
    v19 = 0;
    v16 = 0;
  }
  if ( v22 == 43 && v16 < 0 )
    v16 = 0;
  v23 = 0;
  if ( a2 )
  {
    v8 = aiHandleObject(a3, 1, (int)&v21);
    v23 += v8;
  }
  if ( a4 )
  {
    v20 = sub_4B1B60(a5, 1, 1, (int)&v25, 0);
    if ( v20 < 0 )
      v23 += v20;
  }
  if ( sub_456630(advManager, a1, (int)&v29, (int)&v27, -1, -1) )
  {
    v9 = usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1));
    if ( sub_458D40(v9) )
    {
      v15 = aiHandleObject(__PAIR__(v27, v29), 1, (int)&v26);
      if ( v15 < 0 )
        v23 += v15;
      if ( v21 == 100 )
        v21 = v26;
      else
        v21 = v26 * v21 / 100;
    }
  }
  if ( v17 & 0x80 || LOBYTE(curPlayer->field_41) == (_DWORD)a1 && HIBYTE(curPlayer->field_41) == HIDWORD(a1) )
    v15 = aiHandleObject(a1, a6, (int)&v24);
  else
    v15 = 0;
  if ( v24 < 100 )
    v16 = v24 * v16 / 100;
  if ( v14 >= 30 )
  {
    if ( v14 < 100 )
    {
      v15 = v15 * v14 / 100;
      v16 = v14 * v16 / 100;
    }
    if ( v25 >= 30 )
    {
      if ( v25 < 100 )
      {
        v15 = v15 * v25 / 100;
        v16 = v25 * v16 / 100;
      }
      if ( v21 >= 100 )
      {
        v23 += v15;
      }
      else
      {
        if ( v23 <= 0 )
          v23 += v21 * (v15 + v16) / 100;
        else
          v23 = v21 * (v15 + v23 + v16) / 100;
      }
      v28 = (double)*(__int16 *)((char *)&pathfinder->field_2414[a1].field_2 + 9 * mapWidth * HIDWORD(a1))
          / (double)*(signed int *)&dword_51D5BC->_4[16];
      if ( dword_51D5BC->flags1 & 0x80 )
      {
        v28 = v28 * 0.5 + 0.5;
      }
      else
      {
        if ( v28 <= 5.0 )
        {
          if ( v28 <= 4.0 )
          {
            if ( v28 <= 3.0 )
            {
              if ( v28 <= 2.0 )
              {
                if ( v28 <= 1.5 )
                {
                  if ( v28 > 1.0 )
                    v28 = v28 * 1.2;
                }
                else
                {
                  v28 = v28 * 1.4;
                }
              }
              else
              {
                v28 = v28 * 1.7;
              }
            }
            else
            {
              v28 = v28 * 2.0;
            }
          }
          else
          {
            v28 = v28 * 2.5;
          }
        }
        else
        {
          v28 = v28 * 3.0;
        }
      }
      v23 = (signed __int64)((double)v23 / (v28 + 0.2));
      v16 = (signed __int64)((double)(2 * v16) / (v28 + 1.0));
      if ( v21 == 100 )
        v23 += v16;
      if ( dword_51D5BC->flags1 & 0x80 && v17 == 28 )
        v23 += 40;
      if ( debugLogLevel > 4 )
      {
        v13 = v17 & 0x7F;
        if ( v13 <= 0 || v13 >= 119 )
          *(_DWORD *)v11 = L" ";
        else
          *(_DWORD *)v11 = (&adventureMapLocations)[4 * v13];
        sprintf(&prefix, "FUN U :% 15s", *(_DWORD *)v11);
        logUpTo7Ints((int)&prefix, a1, SHIDWORD(a1), v23, v15, v16, 100 * v14, -999);
      }
      result = v23;
    }
    else
    {
      result = -100;
    }
  }
  else
  {
    result = -100;
  }
  return result;
}
