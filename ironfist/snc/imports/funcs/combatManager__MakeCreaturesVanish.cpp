{
  army *v1; // ST3C_4@15
  combatManager *thisa; // [sp+Ch] [bp-20h]@1
  signed int i; // [sp+10h] [bp-1Ch]@1
  signed int k; // [sp+10h] [bp-1Ch]@9
  int height; // [sp+14h] [bp-18h]@9
  int y; // [sp+18h] [bp-14h]@9
  int x; // [sp+1Ch] [bp-10h]@9
  int j; // [sp+24h] [bp-8h]@3
  int l; // [sp+24h] [bp-8h]@11
  int width; // [sp+28h] [bp-4h]@9

  thisa = this;
  combatManager::ResetLimitCreature(this);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
    {
      if ( thisa->field_F577[i][j] )
        thisa->stuffHappenedToCreature[i][j] = 1;
    }
  }
  combatManager::DrawFrame(thisa, 0, 1, 0, 1, 75, 1, 1);
  x = giMinExtentX;
  y = giMinExtentY;
  width = giMaxExtentX - giMinExtentX + 1;
  height = giMaxExtentY - giMinExtentY + 1;
  for ( k = 0; k < 2; ++k )
  {
    for ( l = 0; gpCombatManager->numCreatures[k] > l; ++l )
    {
      if ( thisa->field_F577[k][l] )
      {
        thisa->combatGrid[thisa->creatures[k][l].occupiedHex].unitOwner = -1;
        thisa->combatGrid[thisa->creatures[k][l].occupiedHex].stackIdx = -1;
        if ( thisa->creatures[k][l].creature.creature_flags & TWO_HEXER )
        {
          thisa->combatGrid[thisa->creatures[k][l].occupiedHex
                          + ((unsigned int)(thisa->creatures[k][l].facingRight - 1) < 1 ? 1 : -1)].unitOwner = -1;
          v1 = &thisa->creatures[k][l];
          thisa->combatGrid[v1->occupiedHex + ((unsigned int)(v1->facingRight - 1) < 1 ? 1 : -1)].stackIdx = -1;
        }
      }
    }
  }
  heroWindowManager::SaveFizzleSource(gpWindowManager, x, y, width, height);
  combatManager::DrawFrame(gpCombatManager, 0, 0, 1, 0, 75, 1, 1);
  heroWindowManager::FizzleForward(
    gpWindowManager,
    x,
    y,
    width,
    height,
    (signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 150.0),
    0,
    0);
}