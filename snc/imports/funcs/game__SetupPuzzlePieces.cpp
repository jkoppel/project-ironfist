{
  int v3; // ST38_4@1
  int wildPuzzlePieces; // ST3C_4@1
  double fractionVisited; // st7@1
  float v6; // ST48_4@1
  float fractionWild; // ST44_4@1
  int result; // eax@6
  unsigned int l; // [sp+20h] [bp-20h]@9
  signed int k; // [sp+24h] [bp-1Ch]@13
  unsigned int i; // [sp+28h] [bp-18h]@0
  signed int numToReveal; // [sp+2Ch] [bp-14h]@1
  int numToReveala; // [sp+2Ch] [bp-14h]@3
  int j; // [sp+34h] [bp-Ch]@7

  v3 = GetNumObelisks(playerNo);
  wildPuzzlePieces = 48 - this->numObelisks;
  fractionVisited = (double)GetNumObelisks(playerNo) / (double)this->numObelisks;
  v6 = fractionVisited;
  fractionWild = (fractionVisited * v6 + v6) / 2.0;
  numToReveal = (signed __int64)((double)wildPuzzlePieces * fractionWild + (double)v3);
  if ( GetNumObelisks(playerNo) == this->numObelisks )
    numToReveal = 48;
  numToReveala = this->players[playerNo]._3[0] + numToReveal;
  if ( numToReveala > 48 )
    numToReveala = 48;
  if ( isAi )
  {
    result = numToReveala;
  }
  else
  {
    memset(&puzzlePiecesRemoved, 0, 6u);
    SRand(3 * this->players[playerNo]._4[0] + this->players[playerNo].color);
    for ( j = 0; j < numToReveala; ++j )
    {
      for ( l = 0; (signed int)l < 48 && BitTest((char *)&puzzlePiecesRemoved, l); l += SRandom(1, 5) )
        ;
      for ( k = 0; ; ++k )
      {
        if ( k < 100 )
        {
          i = SRandom(0, 47);
          if ( BitTest((char *)&puzzlePiecesRemoved, i) )
            continue;
        }
        break;
      }
      if ( k >= 100 )
      {
        for ( i = 0; (signed int)i < 48 && BitTest((char *)&puzzlePiecesRemoved, i); ++i )
          ;
      }
      if ( (signed int)i >= 48 )
        i = 0;
      if ( (signed int)l >= 48 )
        BitSet((char *)&puzzlePiecesRemoved, i);
      else
        BitSet((char *)&puzzlePiecesRemoved, l);
    }
    result = numToReveala;
  }
  return result;
}