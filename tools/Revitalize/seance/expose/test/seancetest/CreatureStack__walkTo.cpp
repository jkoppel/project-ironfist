signed int __thiscall CreatureStack::walkTo(CreatureStack *ecx0, int hex)
{
  signed int result; // eax@33
  CreatureStack *this; // [sp+Ch] [bp-18h]@1
  signed int onEnemySideOfMoat; // [sp+10h] [bp-14h]@9
  signed int moatIdx; // [sp+14h] [bp-10h]@3
  signed int isOnMoat; // [sp+18h] [bp-Ch]@3
  signed int v7; // [sp+1Ch] [bp-8h]@34
  signed int i; // [sp+20h] [bp-4h]@3
  signed int hexIdxa; // [sp+20h] [bp-4h]@17
  int hexIdxb; // [sp+20h] [bp-4h]@34

  this = ecx0;
  ecx0->targetStackIdx = -1;
  ecx0->targetOwner = ecx0->targetStackIdx;
  if ( combatManager->hasMoat && ecx0->creature.creature_flags & TWO_HEXER )
  {
    isOnMoat = 0;
    moatIdx = 0;
    for ( i = 0; i < 9; ++i )
    {
      if ( moatHexes[i] == hex )
      {
        isOnMoat = 1;
        moatIdx = i;
      }
    }
    if ( isOnMoat )
    {
      onEnemySideOfMoat = 0;
      if ( moatIdx == 4 && combatManager->drawBridgePosition != 4 )
        onEnemySideOfMoat = 1;
      if ( moatIdx > 0 && *((_BYTE *)&dword_4F5474 + moatIdx + 3) == ecx0->occupiedHex
        || moatIdx < 8 && moatHexes[moatIdx + 1] == ecx0->occupiedHex )
        onEnemySideOfMoat = 1;
      for ( hexIdxa = 0; hexIdxa < 6; ++hexIdxa )
      {
        if ( moatHexes[moatIdx] == CreatureStack::getHexNeighbor(this, this->occupiedHex, hexIdxa) )
          onEnemySideOfMoat = 1;
      }
      if ( !this->owningSide && moatHexes[this->occupiedHex / 13] < this->occupiedHex )
        onEnemySideOfMoat = 1;
      if ( this->owningSide == 1 && moatHexes[this->occupiedHex / 13] > this->occupiedHex )
        onEnemySideOfMoat = 1;
      if ( !onEnemySideOfMoat )
      {
        if ( this->facingRight == 1 )
          --hex;
        else
          ++hex;
      }
    }
  }
  if ( sub_405DB0(this, this->occupiedHex, hex, this->creature.speed, 1, 0) )
  {
    v7 = 0;
    for ( hexIdxb = pathfinder->field_8 - 1; hexIdxb >= 0; --hexIdxb )
    {
      sub_47BF10(this, *((_BYTE *)&pathfinder->field_2418 + hexIdxb), 0, pathfinder->field_8 - 1 != hexIdxb);
      ++v7;
      if ( this->creature.speed <= v7 )
        hexIdxb = -1;
    }
    CreatureStack::handleCreatureEvent(this, 0);
    this->animationType = 7;
    this->animationFrame = 0;
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    CombatManager::handleMoatClosing(combatManager);
    result = 0;
  }
  else
  {
    result = 3;
  }
  return result;
}
