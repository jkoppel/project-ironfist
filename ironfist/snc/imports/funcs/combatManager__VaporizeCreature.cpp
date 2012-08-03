{
  combatManager *thisa; // ST2C_4@1
  signed int i; // [sp+18h] [bp-24h]@1
  signed int v5; // [sp+1Ch] [bp-20h]@4
  int j; // [sp+20h] [bp-1Ch]@11
  int v7; // [sp+24h] [bp-18h]@1
  army *v8; // [sp+28h] [bp-14h]@1
  signed int v9; // [sp+2Ch] [bp-10h]@4
  int v10; // [sp+34h] [bp-8h]@1
  int v11; // [sp+38h] [bp-4h]@1

  thisa = this;
  v8 = &this->creatures[a2][a3];
  combatManager::ResetLimitCreature(this);
  ++thisa->stuffHappenedToCreature[a2][a3];
  combatManager::DrawFrame(gpCombatManager, 1, 1, 1, 0, 75, 1, 1);
  gyModify = BaseAlloc(0x1E0u, "F:\\h2xsrc\\Source\\SPELLS.CPP", word_51A404 + 9);
  memset(gyModify, 0, 480u);
  v8->field_125 = gyModify;
  LODWORD(v8->field_4E) = 0;
  v11 = 5 * (giMinExtentY / 5);
  v10 = 5 * (giMaxExtentY / 5);
  v7 = (5 * (giMaxExtentY / 5) - v11) / 5 + 1;
  for ( i = 0; i < 3; ++i )
  {
    if ( i )
    {
      if ( i == 1 )
      {
        v9 = 1;
        v5 = 3;
      }
      else
      {
        v9 = 3;
        v5 = 2;
      }
    }
    else
    {
      v9 = 0;
      v5 = 1;
    }
    if ( i == 2 )
      v7 = (v7 - 1) / 2 + 1;
    for ( j = 0; v7 > j; ++j )
    {
      *((_BYTE *)gyModify + 5 * j + v9 + v11) = 127;
      *((char *)gyModify + v10 - v5 + -5 * j) = 127;
      gbLimitToExtent = 1;
      combatManager::DrawFrame(gpCombatManager, 1, 0, 1, 0, 30, 1, 1);
    }
  }
  DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 500.0));
  v8->field_125 = 0;
  LODWORD(v8->field_4E) = 1;
  BaseFree(gyModify, (int)"F:\\h2xsrc\\Source\\SPELLS.CPP", word_51A404 + 56);
  gyModify = 0;
  combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
}