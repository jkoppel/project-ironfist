{
  signed int j; // [sp+10h] [bp-8h]@7
  signed int i; // [sp+14h] [bp-4h]@4

  if ( a1 && a2 )
  {
    for ( i = 0; i < 14; ++i )
    {
      if ( *(_BYTE *)(i + a2 + 213) == -1 )
      {
        for ( j = 0; j < 14; ++j )
        {
          if ( *(_BYTE *)(j + a1 + 213) != -1 && *(_BYTE *)(j + a1 + 213) != 81 )
          {
            if ( (signed int)*(_BYTE *)(j + a1 + 213) > 7 )
            {
              GiveTakeArtifactStat((hero *)a2, (ARTIFACT)*(_BYTE *)(j + a1 + 213), 0);
              *(_BYTE *)(i + a2 + 213) = *(_BYTE *)(j + a1 + 213);
              *(_BYTE *)(i + a2 + 236) = *(_BYTE *)(j + a1 + 236);
            }
            else if ( *(&gbThisNetHumanPlayer + *(_BYTE *)(a1 + 3)) || *(&gbThisNetHumanPlayer + *(_BYTE *)(a2 + 3)) )
            {
              sprintf(
                gText,
                "As you reach for the %s, it mysteriously disappears.",
                gArtifactNames[*(_BYTE *)(j + a1 + 213)]);
              NormalDialog(gText, 1, -1, -1, 7, *(_BYTE *)(j + a1 + 213), -1, 0, -1, 0);
            }
            GiveTakeArtifactStat((hero *)a1, (ARTIFACT)*(_BYTE *)(j + a1 + 213), 1);
            *(_BYTE *)(j + a1 + 213) = -1;
            *(_BYTE *)(j + a1 + 236) = -1;
            break;
          }
        }
      }
    }
    hero::CheckAnduranPieces((hero *)a2, 0);
  }
}