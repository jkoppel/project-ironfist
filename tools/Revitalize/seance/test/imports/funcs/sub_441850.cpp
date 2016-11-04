{
  CombatManager *thisa; // ST0C_4@1
  signed int i; // [sp+10h] [bp-10h]@1
  int v3; // [sp+14h] [bp-Ch]@1
  CreatureStack *v4; // [sp+18h] [bp-8h]@5
  int j; // [sp+1Ch] [bp-4h]@3

  thisa = this;
  v3 = getTickCount();
  thisa->field_33BD[0] = getTickCount();
  thisa->field_33BD[1] = getTickCount();
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; combatManager->numCreatures[i] > j; ++j )
    {
      v4 = &combatManager->creatures[i][j];
      combatManager->creatures[i][j].timeToFidget = v3;
      if ( v4->form.fidgetTimeRelated > 51 )
        v4->timeToFidget -= unseededNextRand(50, v4->form.fidgetTimeRelated);
    }
  }
}
