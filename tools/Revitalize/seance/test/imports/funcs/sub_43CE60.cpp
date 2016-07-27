{
  CombatManager *result; // eax@15
  CombatManager *thisa; // [sp+Ch] [bp-14h]@1
  CreatureStack *stack; // [sp+10h] [bp-10h]@5
  signed int i; // [sp+14h] [bp-Ch]@1
  signed int j; // [sp+18h] [bp-8h]@3

  thisa = this;
  this->field_33A2 = 0;
  thisa->field_33A1 = thisa->field_33A2;
  this->field_33A3[1] = 0;
  thisa->field_33A3[0] = thisa->field_33A3[1];
  this->field_339D[1] = 0;
  thisa->field_339D[0] = thisa->field_339D[1];
  this->field_339F[1] = 0;
  thisa->field_339F[0] = thisa->field_339F[1];
  thisa->timesCatapultMustFire[0] = *(_DWORD *)&thisa->_11[0];
  thisa->timesCatapultMustFire[1] = *(_DWORD *)&thisa->_11[4];
  this->timesGarrisonMustFire[0] = 1;
  this->timesGarrisonMustFire[1] = 1;
  this->field_3543 = 0;
  thisa->field_353F = thisa->field_3543;
  memset(combatManager->field_F577, 0, 0x28u);
  combatManager->field_F59F = 0;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < 20; ++j )
    {
      stack = &thisa->creatures[i][j];
      if ( thisa->creatures[i][j].quantity > 0 )
      {
        *(_DWORD *)&thisa->creatures[i][j].creature.creature_flags &= 0xFF1Fu;
        if ( thisa->creatures[i][j].creatureIdx == CREATURE_TROLL
          || thisa->creatures[i][j].creatureIdx == CREATURE_WAR_TROLL )
          thisa->creatures[i][j].damage = 0;
        CreatureStack::decrementEffectDurations(stack);
        if ( !thisa->creatures[i][j].lifespan )
          CreatureStack::die(stack, 1);
      }
    }
  }
  if ( combatManager->field_F59F )
    sub_4796F0(combatManager);
  result = thisa;
  thisa->field_F2AB = 15;
  return result;
}
