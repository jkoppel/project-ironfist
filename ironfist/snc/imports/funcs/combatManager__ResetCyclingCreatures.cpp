{
  char *v1; // eax@17
  combatManager *thisa; // [sp+Ch] [bp-18h]@1
  signed int i; // [sp+10h] [bp-14h]@1
  signed int k; // [sp+10h] [bp-14h]@12
  int j; // [sp+18h] [bp-Ch]@3
  int l; // [sp+18h] [bp-Ch]@14
  int v7; // [sp+1Ch] [bp-8h]@1

  thisa = this;
  v7 = 0;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
    {
      if ( !(gpCombatManager->creatures[i][j].creature.creature_flags & DEAD)
        && gpCombatManager->creatures[i][j].animationType >= 8 )
      {
        if ( gpCombatManager->creatures[i][j].animationType <= 12 )
        {
          ++v7;
          ++gpCombatManager->stuffHappenedToCreature[i][j];
        }
      }
    }
  }
  if ( v7 )
  {
    combatManager::DrawFrame(gpCombatManager, 0, 1, 1, 1, 75, 1, 1);
    for ( k = 0; k < 2; ++k )
    {
      for ( l = 0; gpCombatManager->numCreatures[k] > l; ++l )
      {
        if ( !(gpCombatManager->creatures[k][l].creature.creature_flags & DEAD) )
        {
          v1 = (char *)gpCombatManager + 24234 * k + 1154 * l;
          *(_DWORD *)(v1 + 13773) = 7;
          *(_DWORD *)(v1 + 13777) = 0;
          *(_DWORD *)(v1 + 13885) = KBTickCount();
        }
      }
    }
    thisa->field_33BD[0] = KBTickCount();
    thisa->field_33BD[1] = KBTickCount();
    combatManager::DrawFrame(gpCombatManager, 1, 1, 0, 0, 75, 1, 1);
  }
}