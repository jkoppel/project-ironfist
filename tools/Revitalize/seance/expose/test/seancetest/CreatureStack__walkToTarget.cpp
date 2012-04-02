signed int __thiscall CreatureStack::walkToTarget(CreatureStack *this)
{
  return CreatureStack::walkTo(this, this->targetHex);
}
