{
  int othOccHex; // [sp+10h] [bp-8h]@10
  hero *hro; // [sp+14h] [bp-4h]@1

  army::InitClean(this);
  this->creatureIdx = creatureIdx;
  this->field_6 = 1;
  memcpy(&this->creature, &gMonsterDatabase[creatureIdx], sizeof(this->creature));
  this->field_D4 = 6;
  hro = gpCombatManager->heroes[owner];
  if ( hro )
  {
    this->creature.attack += hero::Stats(hro, 0);
    this->creature.defense += hero::Stats(hro, PRIMARY_SKILL_DEFENSE);
  }
  this->facingRight = owner ^ 1;
  this->animationType = 7;
  this->animationFrame = 0;
  this->luckStatus = 0;
  this->targetOwner = -1;
  this->targetStackIdx = -1;
  this->targetNeighborIdx = -1;
  this->speed = this->creature.speed;
  this->quantity = quantity;
  this->initialQuantity = this->quantity;
  this->anAmountToLose = 0;
  this->mightBeIsAttacking = 0;
  this->damage = 0;
  this->otherBadLuckThing = 0;
  this->hasTakenLosses = 0;
  this->dead = this->hasTakenLosses;
  this->damageTakenDuringSomeTimePeriod = this->dead;
  this->owningSide = owner;
  this->stackIdx = stackIdx;
  this->morale = armyGroup::GetMorale(
                   gpCombatManager->armies[this->owningSide],
                   gpCombatManager->heroes[this->owningSide],
                   gpCombatManager->castles[this->owningSide],
                   gpCombatManager->armies[1 - this->owningSide]->creatureTypes);
  if ( this->creatureIdx == CREATURE_EARTH_ELEMENTAL
    || this->creatureIdx == CREATURE_AIR_ELEMENTAL
    || this->creatureIdx == CREATURE_FIRE_ELEMENTAL
    || this->creatureIdx == CREATURE_WATER_ELEMENTAL
    || HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD )
    this->morale = 0;
  this->luck = game::GetLuck(
                 gpCombatManager->heroes[this->owningSide],
                 this,
                 gpCombatManager->castles[this->owningSide]);
  this->occupiedHex = startHex;
  gpCombatManager->combatGrid[this->occupiedHex].unitOwner = LOBYTE(this->owningSide);
  gpCombatManager->combatGrid[this->occupiedHex].stackIdx = LOBYTE(this->stackIdx);
  if ( this->creature.creature_flags & TWO_HEXER )
  {
    othOccHex = this->occupiedHex + (this->owningSide < 1u ? 1 : -1);
    gpCombatManager->combatGrid[othOccHex].unitOwner = LOBYTE(this->owningSide);
    gpCombatManager->combatGrid[othOccHex].stackIdx = LOBYTE(this->stackIdx);
    gpCombatManager->combatGrid[othOccHex].isOccupierNonPrimaryHex = this->occupiedHex <= othOccHex;
    gpCombatManager->combatGrid[this->occupiedHex].isOccupierNonPrimaryHex = this->occupiedHex > othOccHex;
  }
  this->armyIdx = armyIdx;
}