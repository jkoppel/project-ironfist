void __thiscall CreatureStack::initializeBookkeeping(CreatureStack *this)
{
  CreatureStack *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( i = 0; i < 7; ++i )
    this->combatSounds[i] = 0;
  this->lifespan = -1;
  this->numActiveEffects = 0;
  memset(this->effectStrengths, 0, 0xFu);
  thisa->baseFidgetTime = getTickCount();
  thisa->field_11D = 1;
  thisa->creatureIcon = 0;
  thisa->probablyIsNeedDrawSpellEffect = 0;
  thisa->spellEnemyCreatureAbilityIsCasting = -1;
  thisa->mirroredIdx = -1;
  thisa->mirrorIdx = -1;
  thisa->armyIdx = -1;
  thisa->previousQuantity = -1;
}
