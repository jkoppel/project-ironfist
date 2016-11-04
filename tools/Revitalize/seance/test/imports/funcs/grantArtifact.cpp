{
  signed int result; // eax@6
  Hero *heroa; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  heroa = hero;
  for ( i = 0; i < 14 && hero->artifacts[i] != -1; ++i )
    ;
  if ( i == 14 )
  {
    result = -1;
  }
  else
  {
    hero->artifacts[i] = a2;
    hero->scrollSpell[i] = scrollSpell;
    Hero::alterPrimarySkillsForArtifact(hero, a2, 0);
    Hero::checkForFullBattleGarb(heroa, 0);
    if ( a3 )
      checkGameEnd(0, 0);
    result = i;
  }
  return result;
}
