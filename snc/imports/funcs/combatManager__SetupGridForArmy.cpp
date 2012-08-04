{
  int v2; // ST24_4@3
  int v3; // ST28_4@3
  combatManager *thisa; // [sp+Ch] [bp-14h]@1
  int v5; // [sp+10h] [bp-10h]@3
  signed int i; // [sp+14h] [bp-Ch]@3

  thisa = this;
  if ( !gbNoShowCombat && combatShadeLevel >= 1 )
  {
    v5 = army::GetAttackMask(stack, stack->occupiedHex, 2, -1);
    memset(thisa->field_49F, 0, 0x75u);
    v2 = stack->targetOwner;
    v3 = stack->targetStackIdx;
    stack->targetOwner = -1;
    stack->targetStackIdx = -1;
    searchArray::SeedCombatPosition(stack);
    stack->targetOwner = v2;
    stack->targetStackIdx = v3;
    for ( i = 0; i < 117; ++i )
    {
      if ( stack->occupiedHex == i )
      {
        thisa->field_49F[i] = 1;
      }
      else if ( thisa->combatGrid[i].field_41 )
      {
        if ( thisa->combatGrid[i].unitOwner == -1 )
        {
          thisa->field_49F[i] = 3;
        }
        else if ( thisa->combatGrid[i].unitOwner != stack->owningSide )
        {
          thisa->field_49F[i] = 1;
        }
      }
      else if ( thisa->combatGrid[i].unitOwner != -1
  && thisa->combatGrid[i].unitOwner != 1 - thisa->currentActionSide
  && (1 << thisa->combatGrid[i].stackIdx) & v5 )
      {
        thisa->field_49F[i] = 1;
      }
    }
  }
}