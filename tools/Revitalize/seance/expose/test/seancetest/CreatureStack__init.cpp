void __thiscall CreatureStack::init(CreatureStack *this, int creatureIdx, int quantity, int owner, int stackIdx, int startHex, int armyIdx)
{
  int othOccHex; // [sp+10h] [bp-8h]@10
  Hero *hero; // [sp+14h] [bp-4h]@1

  CreatureStack::initializeBookkeeping(this);
  this->creatureIdx = creatureIdx;
  this->field_6 = 1;
  memcpy(&this->creature, &creature_table[creatureIdx], sizeof(this->creature));
  this->field_D4 = 6;
  hero = combatManager->heroes[owner];
  if ( hero )
  {
    this->creature.attack += Hero::getPrimarySkill(hero, 0);
    this->creature.defense += Hero::getPrimarySkill(hero, PRIMARY_SKILL_DEFENSE);
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
  this->morale = ArmyInfo::computeMorale(
                   combatManager->armies[this->owningSide],
                   combatManager->heroes[this->owningSide],
                   combatManager->castles[this->owningSide],
                   combatManager->armies[1 - this->owningSide]->creatureTypes);
  if ( this->creatureIdx == CREATURE_EARTH_ELEMENTAL
    || this->creatureIdx == CREATURE_AIR_ELEMENTAL
    || this->creatureIdx == CREATURE_FIRE_ELEMENTAL
    || this->creatureIdx == CREATURE_WATER_ELEMENTAL
    || HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD )
    this->morale = 0;
  this->luck = computeLuck(combatManager->heroes[this->owningSide], this, combatManager->castles[this->owningSide]);
  this->occupiedHex = startHex;
  combatManager->combatGrid[this->occupiedHex].unitOwner = LOBYTE(this->owningSide);
  combatManager->combatGrid[this->occupiedHex].stackIdx = LOBYTE(this->stackIdx);
  if ( this->creature.creature_flags & TWO_HEXER )
  {
    othOccHex = this->occupiedHex + (this->owningSide < 1u ? 1 : -1);
    combatManager->combatGrid[othOccHex].unitOwner = LOBYTE(this->owningSide);
    combatManager->combatGrid[othOccHex].stackIdx = LOBYTE(this->stackIdx);
    combatManager->combatGrid[othOccHex].isOccupierNonPrimaryHex = this->occupiedHex <= othOccHex;
    combatManager->combatGrid[this->occupiedHex].isOccupierNonPrimaryHex = this->occupiedHex > othOccHex;
  }
  this->armyIdx = armyIdx;
}
