{
  char *v2; // [sp+10h] [bp-14h]@2
  sample_resource res; // [sp+1Ch] [bp-8h]@1

  res = playSample("rsbryfzl.82m");
  if ( a1->quantity == 1 )
    v2 = creatureSingularNames[a1->creatureIdx];
  else
    v2 = creaturePluralNames[a1->creatureIdx];
  sprintf(globBuf, "The %s %s the spell!", v2, &aResists[("resist" - "resists") & ((a1->quantity == 1) - 1)]);
  CombatManager::displayCombatMessage(combatManager, globBuf, 1, 1, 0);
  waitForSampleToFinish(-1, res);
}
