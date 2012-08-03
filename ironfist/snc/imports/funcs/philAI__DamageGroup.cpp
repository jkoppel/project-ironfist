{
  signed int result; // eax@2

  if ( a4 >= 0.99 )
  {
    if ( a2 )
      advManager::HeroLoses((int)gpAdvManager, a2);
    else
      armyGroup::DamageGroup((armyGroup *)a1, a4);
    result = 1;
  }
  else
  {
    armyGroup::DamageGroup((armyGroup *)a1, a4);
    result = 0;
  }
  return result;
}