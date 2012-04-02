void __fastcall CreatureForm::doSomethingElse(CreatureForm *form, CREATURES creature)
{
  int speedDiff; // [sp+28h] [bp-4h]@1

  speedDiff = 0;
  if ( creature == CREATURE_RANGER
    || creature == CREATURE_VETERAN_PIKEMAN
    || creature == CREATURE_MASTER_SWORDSMAN
    || creature == CREATURE_CHAMPION
    || creature == CREATURE_CRUSADER
    || creature == CREATURE_ORC_CHIEF
    || creature == CREATURE_OGRE_LORD
    || creature == CREATURE_WAR_TROLL
    || creature == CREATURE_BATTLE_DWARF
    || creature == CREATURE_GRAND_ELF
    || creature == CREATURE_GREATER_DRUID
    || creature == CREATURE_MINOTAUR_KING
    || creature == CREATURE_STEEL_GOLEM
    || creature == CREATURE_ARCHMAGE
    || creature == CREATURE_MUTANT_ZOMBIE
    || creature == CREATURE_ROYAL_MUMMY
    || creature == CREATURE_VAMPIRE_LORD
    || creature == CREATURE_POWER_LICH )
    speedDiff = creature_table[creature].speed - creature_table[creature - 1].speed;
  if ( creature == CREATURE_EARTH_ELEMENTAL
    || creature == CREATURE_AIR_ELEMENTAL
    || creature == CREATURE_WATER_ELEMENTAL )
    speedDiff = creature_table[creature].speed - creature_table[64].speed;
  if ( speedDiff )
  {
    if ( creature == CREATURE_RANGER )
      form->field_A6 = (signed __int64)((double)form->field_A6 * 0.78);
    else
      form->field_A6 = (signed __int64)((1.0 - (double)speedDiff * 0.08) * (double)form->field_A6);
    form->field_A2 = (signed __int64)((1.0 - (double)speedDiff * 0.12) * (double)form->field_A2);
  }
}
