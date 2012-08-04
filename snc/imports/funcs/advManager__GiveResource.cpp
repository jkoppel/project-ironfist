{
  int v4; // ecx@3

  if ( type >= 0 && type <= 6 )
  {
    v4 = 283 * hro->probablyOwnerIdx + 4 * type;
    *(int *)((char *)gpGame->players[0].resources + v4) += amt;
  }
  if ( type == 6 )
  {
    if ( gbHumanPlayer[hro->probablyOwnerIdx] )
      CheckEndGame(0, 0);
  }
}