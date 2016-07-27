{
  int v3; // ecx@3

  if ( type >= 0 && type <= 6 )
  {
    v3 = 283 * hero->probablyOwnerIdx + 4 * type;
    *(int *)((char *)gameObject->players[0].resources + v3) += amt;
  }
  if ( type == RESOURCE_GOLD )
  {
    if ( dword_524810[hero->probablyOwnerIdx] )
      checkGameEnd(0, 0);
  }
}
