{
  return this->creatureIdx == CREATURE_EARTH_ELEMENTAL
      || this->creatureIdx == CREATURE_AIR_ELEMENTAL
      || this->creatureIdx == CREATURE_FIRE_ELEMENTAL
      || this->creatureIdx == CREATURE_WATER_ELEMENTAL
      || HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE;
}