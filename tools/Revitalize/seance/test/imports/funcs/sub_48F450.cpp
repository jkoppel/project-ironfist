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
              Hero::alterPrimarySkillsForArtifact((Hero *)a2, (ARTIFACT)*(_BYTE *)(j + a1 + 213), 0);
              *(_BYTE *)(i + a2 + 213) = *(_BYTE *)(j + a1 + 213);
              *(_BYTE *)(i + a2 + 236) = *(_BYTE *)(j + a1 + 236);
            }
            else
            {
              if ( *(&byte_524758 + *(_BYTE *)(a1 + 3)) || *(&byte_524758 + *(_BYTE *)(a2 + 3)) )
              {
                sprintf(
                  globBuf,
                  "As you reach for the %s, it mysteriously disappears.",
                  artifactNames[*(_BYTE *)(j + a1 + 213)]);
                display_message_window(globBuf, 1, -1, -1, 7, *(_BYTE *)(j + a1 + 213), -1, 0, -1, 0);
              }
            }
            Hero::alterPrimarySkillsForArtifact((Hero *)a1, (ARTIFACT)*(_BYTE *)(j + a1 + 213), 1);
            *(_BYTE *)(j + a1 + 213) = -1;
            *(_BYTE *)(j + a1 + 236) = -1;
            break;
          }
        }
      }
    }
    Hero::checkForFullBattleGarb((Hero *)a2, 0);
  }
}
