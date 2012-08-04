{
  char *v2; // [sp+10h] [bp-14h]@2
  sample_resource res; // [sp+1Ch] [bp-8h]@1

  res = LoadPlaySample("rsbryfzl.82m");
  if ( a1->quantity == 1 )
    v2 = gArmyNames[a1->creatureIdx];
  else
    v2 = gArmyNamesPlural[a1->creatureIdx];
  sprintf(gText, "The %s %s the spell!", v2, &aResists[("resist" - "resists") & ((a1->quantity == 1) - 1)]);
  combatManager::CombatMessage(gpCombatManager, gText, 1, 1, 0);
  WaitEndSample(-1, res);
}