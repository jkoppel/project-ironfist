{
  signed int v1; // ST20_4@21
  signed int v3; // [sp+28h] [bp-24h]@18
  int v4; // [sp+2Ch] [bp-20h]@20
  signed int i; // [sp+38h] [bp-14h]@2
  signed int j; // [sp+38h] [bp-14h]@18
  signed int v7; // [sp+40h] [bp-Ch]@1
  int v8; // [sp+44h] [bp-8h]@1

  v8 = 0;
  v7 = 0;
  switch ( ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F )
  {
    case 0:
      for ( i = 0; i < 14; ++i )
      {
        if ( IsCursedItem((ARTIFACT)gpCurAIHero->artifacts[i]) )
          ++v8;
      }
      if ( gpCurPlayer->resources[6] > 1500 )
        v7 = 500 * v8;
      break;
    case 1:
      if ( !(gpCurAIHero->flags3 & 0x40) )
        v7 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 1000.0);
      break;
    case 5:
      if ( !(gpCurAIHero->flags3 & 0x10) && giCurAIHeroLuck < 3 )
        v7 = (signed __int64)(*(float *)&gpCurAIHero->field_E7[1] * 200.0);
      break;
    case 6:
      if ( !(gpCurAIHero->flags3 & 0x20) )
      {
        v3 = 0;
        for ( j = 0; j < 5; ++j )
        {
          v4 = gpCurAIHero->army.creatureTypes[j];
          if ( v4 != -1 )
          {
            v1 = gpCurAIHero->army.quantities[j];
            v3 += (v1 - (unsigned __int64)(signed __int64)((double)v1 * 0.7)) * gMonsterDatabase[v4].hp;
          }
        }
        v7 = (signed __int64)((double)v3 * *(float *)&gpCurAIHero->field_E7[1]);
      }
      break;
    case 4:
      v7 = philAI::ComputeUpgradeValue(7, 8);
      if ( !(gpCurAIHero->flags3 & 0x80) )
        v7 = (signed __int64)((double)(200 * (8 - gpGame->day)) * *(float *)&gpCurAIHero->field_E7[1] + (double)v7);
      break;
    case 2:
    case 3:
      return v7;
  }
  return v7;
}