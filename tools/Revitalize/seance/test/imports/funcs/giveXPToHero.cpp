{
  int newLevel; // [sp+14h] [bp-10h]@1
  int oldLevel; // [sp+20h] [bp-4h]@1

  oldLevel = levelForXP(hero->experience);
  hero->oldLevel = oldLevel;
  hero->experience += xp;
  newLevel = levelForXP(hero->experience);
  if ( a3 )
    Hero::checkForLevelUp(hero);
  return newLevel - oldLevel;
}
