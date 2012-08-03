{
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( bUseDirectPlay )
      {
        dpnet_term();
      }
      else if ( bUseWinsock )
      {
        wsnet_term();
      }
      else
      {
        nb_term();
      }
    }
  }
  else
  {
    com_term(0);
  }
}