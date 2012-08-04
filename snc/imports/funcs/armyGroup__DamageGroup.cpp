{
  armyGroup *thisa; // [sp+Ch] [bp-18h]@1
  int numKilled; // [sp+10h] [bp-14h]@4
  signed int j; // [sp+18h] [bp-Ch]@4
  signed int i; // [sp+1Ch] [bp-8h]@1
  signed int mustSpareACreature; // [sp+20h] [bp-4h]@1

  thisa = this;
  mustSpareACreature = 1;
  for ( i = 0; i < 5; ++i )
  {
    if ( thisa->creatureTypes[i] == -1 )
    {
      thisa->quantities[i] = 0;
    }
    else
    {
      numKilled = 0;
      for ( j = 0; thisa->quantities[i] > j; ++j )
      {
        if ( SRandom(0, 100) < (signed int)(signed __int64)(chance * 100.0) )
          ++numKilled;
      }
      if ( mustSpareACreature && thisa->quantities[i] == numKilled && chance < 0.999 )
        LOWORD(numKilled) = numKilled - 1;
      thisa->quantities[i] -= numKilled;
      if ( thisa->quantities[i] <= 0 || chance >= 1.0 )
      {
        thisa->quantities[i] = 0;
        thisa->creatureTypes[i] = -1;
      }
      mustSpareACreature = 0;
    }
  }
}