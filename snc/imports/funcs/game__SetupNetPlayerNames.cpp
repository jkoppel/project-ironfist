{
  int result; // eax@3
  int i; // [sp+10h] [bp-4h]@2

  if ( iLastMsgNumHumanPlayers > 1 )
  {
    for ( i = 0; ; ++i )
    {
      result = i;
      if ( iLastMsgNumHumanPlayers <= i )
        break;
      if ( iMPBaseType != 2 )
        strcpy(&cPlayerNames[21 * i], (char *)&gsNetPlayerInfo + 34 * i + 4);
    }
  }
  return result;
}