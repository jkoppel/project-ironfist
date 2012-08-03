{
  int alignment; // eax@5
  signed int result; // eax@10
  armyGroup *thisa; // [sp+Ch] [bp-1Ch]@1
  char numOfEachAlignment[8]; // [sp+10h] [bp-18h]@1
  int lastCreatureID; // [sp+18h] [bp-10h]@1
  int i; // [sp+1Ch] [bp-Ch]@1
  int numCreatureIDsSeen; // [sp+20h] [bp-8h]@1
  int numAlignments; // [sp+24h] [bp-4h]@11

  thisa = this;
  numCreatureIDsSeen = 0;
  memset(numOfEachAlignment, 0, 7u);
  lastCreatureID = -1;
  for ( i = 0; i < 5; ++i )
  {
    if ( thisa->creatureTypes[i] != -1 )
    {
      if ( a2 == -1 )
      {
        alignment = gMonsterDatabase[thisa->creatureTypes[i]].faction;
        ++numOfEachAlignment[alignment];
      }
      if ( thisa->creatureTypes[i] != lastCreatureID )
      {
        ++numCreatureIDsSeen;
        lastCreatureID = thisa->creatureTypes[i];
      }
    }
  }
  if ( numCreatureIDsSeen > 1 )
  {
    numAlignments = 0;
    for ( i = 0; i < 7; ++i )
    {
      if ( numOfEachAlignment[i] )
        ++numAlignments;
    }
    switch ( numAlignments )
    {
      case 1:
        result = 1;
        break;
      case 3:
        result = -1;
        break;
      case 4:
        result = -2;
        break;
      default:
        if ( numAlignments < 5 )
          result = 0;
        else
          result = -3;
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}