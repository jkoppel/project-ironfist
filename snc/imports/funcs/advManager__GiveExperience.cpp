{
  int newLevel; // [sp+14h] [bp-10h]@1
  int oldLevel; // [sp+20h] [bp-4h]@1

  oldLevel = hero::GetLevel(hro->experience);
  hro->oldLevel = oldLevel;
  hro->experience += xp;
  newLevel = hero::GetLevel(hro->experience);
  if ( a3 )
    hero::CheckLevel(hro);
  return newLevel - oldLevel;
}