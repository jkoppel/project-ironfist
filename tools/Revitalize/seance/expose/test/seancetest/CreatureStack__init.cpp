void __thiscall CreatureStack::init(CreatureStack *this, int creatureIdx, int quantity, int owner, int stackIdx, int startHex, int armyIdx)
{
  CreatureStack *thisa; // [sp+Ch] [bp-Ch]@1
  int othOccHex; // [sp+10h] [bp-8h]@10
  Hero *hero; // [sp+14h] [bp-4h]@1

  thisa = this;
  CreatureStack::initializeBookkeeping(this);
  thisa->creatureIdx = creatureIdx;
  thisa->field_6 = 1;
  memcpy(&thisa->creature, &creature_table[creatureIdx], sizeof(thisa->creature));
  thisa->field_D4 = 6;
  hero = combatManager->heroes[owner];
  if ( hero )
  {
    thisa->creature.attack += Hero::getPrimarySkill(hero, 0);
    thisa->creature.defense += Hero::getPrimarySkill(hero, PRIMARY_SKILL_DEFENSE);
  }
  thisa->facingRight = owner ^ 1;
  thisa->animationType = 7;
  thisa->animationFrame = 0;
  thisa->luckStatus = 0;
  thisa->targetOwner = -1;
  thisa->targetStackIdx = -1;
  thisa->targetNeighborIdx = -1;
  thisa->speed = thisa->creature.speed;
  thisa->quantity = quantity;
  thisa->initialQuantity = thisa->quantity;
  thisa->anAmountToLose = 0;
  thisa->mightBeIsAttacking = 0;
  thisa->damage = 0;
  thisa->otherBadLuckThing = 0;
  thisa->hasTakenLosses = 0;
  thisa->dead = thisa->hasTakenLosses;
  thisa->damageTakenDuringSomeTimePeriod = thisa->dead;
  thisa->owningSide = owner;
  thisa->stackIdx = stackIdx;
  thisa->morale = ArmyInfo::computeMorale(
                    combatManager->armies[thisa->owningSide],
                    combatManager->heroes[thisa->owningSide],
                    combatManager->castles[thisa->owningSide],
                    combatManager->armies[1 - thisa->owningSide]->creatureTypes);
  if ( thisa->creatureIdx == CREATURE_EARTH_ELEMENTAL
    || thisa->creatureIdx == CREATURE_AIR_ELEMENTAL
    || thisa->creatureIdx == CREATURE_FIRE_ELEMENTAL
    || thisa->creatureIdx == CREATURE_WATER_ELEMENTAL
    || HIBYTE(thisa->creature.creature_flags) & ATTR_UNDEAD )
    thisa->morale = 0;
  thisa->luck = computeLuck(combatManager->heroes[thisa->owningSide], thisa, combatManager->castles[thisa->owningSide]);
  thisa->occupiedHex = startHex;
  combatManager->combatGrid[thisa->occupiedHex].unitOwner = LOBYTE(thisa->owningSide);
  combatManager->combatGrid[thisa->occupiedHex].stackIdx = LOBYTE(thisa->stackIdx);
  if ( thisa->creature.creature_flags & TWO_HEXER )
  {
    othOccHex = thisa->occupiedHex + (thisa->owningSide < 1u ? 1 : -1);
    combatManager->combatGrid[othOccHex].unitOwner = LOBYTE(thisa->owningSide);
    combatManager->combatGrid[othOccHex].stackIdx = LOBYTE(thisa->stackIdx);
    combatManager->combatGrid[othOccHex].notPrimarySquareOfTwoHexer = thisa->occupiedHex <= othOccHex;
    combatManager->combatGrid[thisa->occupiedHex].notPrimarySquareOfTwoHexer = thisa->occupiedHex > othOccHex;
  }
  thisa->armyIdx = armyIdx;
}
