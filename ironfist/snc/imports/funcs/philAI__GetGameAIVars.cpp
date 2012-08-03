{
  int result; // eax@2
  int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = gpGame->numPlayers;
    if ( result <= i )
      break;
    philAI::GetGameAttentionValue(i);
  }
  return result;
}