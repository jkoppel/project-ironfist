int __cdecl sub_4AA9A0()
{
  int result; // eax@2
  signed int v1; // ST20_4@4
  int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = curPlayer->numCastles;
    if ( result <= i )
      break;
    if ( gameObject->castles[curPlayer->castlesOwned[i]].visitingHeroIdx != -1 )
    {
      v1 = (signed int)&gameObject->castles[curPlayer->castlesOwned[i]];
      sub_4B43E0((int)&gameObject->heroes[*(_BYTE *)(v1 + 23)], v1, 0, (int)&unk_5305C8);
    }
  }
  return result;
}
