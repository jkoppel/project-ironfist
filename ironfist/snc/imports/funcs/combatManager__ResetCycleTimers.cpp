{
  signed int i; // [sp+10h] [bp-10h]@1
  int v3; // [sp+14h] [bp-Ch]@1
  army *v4; // [sp+18h] [bp-8h]@5
  int j; // [sp+1Ch] [bp-4h]@3

  v3 = KBTickCount();
  this->field_33BD[0] = KBTickCount();
  this->field_33BD[1] = KBTickCount();
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
    {
      v4 = &gpCombatManager->creatures[i][j];
      gpCombatManager->creatures[i][j].baseFidgetTime = v3;
      if ( *(_DWORD *)&v4->gap_129[158] > 51 )
        v4->baseFidgetTime -= Random(50, *(_DWORD *)&v4->gap_129[158]);
    }
  }
}