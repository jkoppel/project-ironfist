int __cdecl sub_4AD070()
{
  int result; // eax@2
  int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = gameObject->numPlayers;
    if ( result <= i )
      break;
    sub_4B11A0(i);
  }
  return result;
}
