{
  signed int result; // eax@4
  CreatureStack *thisa; // [sp+Ch] [bp-10h]@1
  int a3; // [sp+10h] [bp-Ch]@15
  signed int v5; // [sp+14h] [bp-8h]@11
  int i; // [sp+18h] [bp-4h]@11

  thisa = this;
  if ( this->creature.creature_flags & FLYER )
  {
    if ( this->occupiedHex != targetHex )
      sub_401700(this, targetHex);
    CreatureStack::performMeleeAttack(thisa, 0);
    result = 0;
  }
  else
  {
    if ( this->creature.creature_flags & TWO_HEX_ATTACKER && this->occupiedHex == this->targetHex )
    {
      CreatureStack::performMeleeAttack(this, 0);
      result = 0;
    }
    else
    {
      if ( sub_405DB0(this, this->occupiedHex, targetHex, this->creature.speed, 1, 0) )
      {
        if ( pathfinder->field_8 == 1 )
        {
          thisa->targetNeighborIdx = LOBYTE(pathfinder->field_2418);
          CombatManager::handleMoatClosing(combatManager);
          CreatureStack::performMeleeAttack(thisa, 0);
        }
        else
        {
          v5 = 0;
          for ( i = pathfinder->field_8 - 1; i; --i )
          {
            ++v5;
            a3 = i == 1 || thisa->creature.speed <= v5;
            sub_47BF10(thisa, *((_BYTE *)&pathfinder->field_2418 + i), a3, pathfinder->field_8 - 1 != i);
            if ( thisa->creature.speed <= v5 && i != 1 )
              return 3;
          }
          CreatureStack::handleCreatureEvent(thisa, 0);
          thisa->targetNeighborIdx = LOBYTE(pathfinder->field_2418);
          CombatManager::handleMoatClosing(combatManager);
          CreatureStack::performMeleeAttack(thisa, 0);
        }
        result = 0;
      }
      else
      {
        result = 3;
      }
    }
  }
  return result;
}
