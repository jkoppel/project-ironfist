{
  int v10; // eax@4
  int v11; // eax@9
  int v12; // eax@14
  int result; // eax@28
  int v14; // [sp+20h] [bp-B4h]@1
  int v15; // [sp+94h] [bp-40h]@1
  int v16; // [sp+98h] [bp-3Ch]@15
  int v17; // [sp+9Ch] [bp-38h]@3
  int v18; // [sp+A0h] [bp-34h]@1
  int v19; // [sp+A4h] [bp-30h]@4
  int v20; // [sp+A8h] [bp-2Ch]@3
  int v21; // [sp+ACh] [bp-28h]@1
  int v22; // [sp+B0h] [bp-24h]@1
  int v23; // [sp+B4h] [bp-20h]@1
  int v24; // [sp+B8h] [bp-1Ch]@8
  int v25; // [sp+BCh] [bp-18h]@1
  int v26; // [sp+C0h] [bp-14h]@1
  int v27; // [sp+C4h] [bp-10h]@1
  unsigned int v28; // [sp+C8h] [bp-Ch]@13
  unsigned int v29; // [sp+D0h] [bp-4h]@13
  int v30; // [sp+100h] [bp+2Ch]@0

  v14 = col;
  v21 = 0;
  v15 = 100;
  v26 = 100;
  v18 = advManager::GetCell(gpAdvManager, a2, col_4)->objType;
  v23 = v18 & 0x7F;
  v25 = 100;
  v22 = 100;
  v27 = 100;
  if ( abs(a2 - gpCurAIHero->x) > 1 || abs(col_4 - gpCurAIHero->y) > 1 )
  {
    v20 = philAI::StrategicValueOfPosition(v14, gpCurAIHero->x, gpCurAIHero->y, 0, 1, &v19, 0);
    v10 = philAI::StrategicValueOfPosition(v14, a2, col_4, 0, 1, &v15, v30);
    v17 = v10 - v20;
  }
  else
  {
    v20 = 0;
    v17 = 0;
  }
  if ( v23 == 43 && v17 < 0 )
    v17 = 0;
  v24 = 0;
  if ( a4 )
  {
    v11 = philAI::ValueOfEventAtPosition((void *)v14, __PAIR__(a6, a5), 1, (int)&v22);
    v24 += v11;
  }
  if ( a7 )
  {
    v21 = philAI::StrategicValueOfPosition(v14, a8, a9, 1, 1, &v26, 0);
    if ( v21 < 0 )
      v24 += v21;
  }
  if ( advManager::FindAdjacentMonster(gpAdvManager, __PAIR__(col_4, a2), (int)&v29, (int)&v28, -1, -1) )
  {
    v12 = (int)advManager::GetCell(gpAdvManager, a2, col_4);
    if ( StopOnTrigger(v12) )
    {
      v16 = philAI::ValueOfEventAtPosition((void *)v14, __PAIR__(v28, v29), 1, (int)&v27);
      if ( v16 < 0 )
        v24 += v16;
      if ( v22 == 100 )
        v22 = v27;
      else
        v22 = v27 * v22 / 100;
    }
  }
  if ( v18 & 0x80 || LOBYTE(gpCurPlayer->field_41) == a2 && HIBYTE(gpCurPlayer->field_41) == col_4 )
    v16 = philAI::ValueOfEventAtPosition((void *)v14, __PAIR__(col_4, a2), a10, (int)&v25);
  else
    v16 = 0;
  if ( v25 < 100 )
    v17 = v25 * v17 / 100;
  if ( v15 >= 30 )
  {
    if ( v15 < 100 )
    {
      v16 = v16 * v15 / 100;
      v17 = v15 * v17 / 100;
    }
    if ( v26 >= 30 )
    {
      if ( v26 < 100 )
      {
        v16 = v16 * v26 / 100;
        v17 = v26 * v17 / 100;
      }
      if ( v22 >= 100 )
      {
        result = v16;
      }
      else if ( v24 <= 0 )
      {
        result = v22 * (v16 + v17) / 100;
        v24 += result;
      }
      else
      {
        result = v22 * (v16 + v24 + v17) / 100;
        v24 = v22 * (v16 + v24 + v17) / 100;
      }
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