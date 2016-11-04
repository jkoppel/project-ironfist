{
  if ( (*hexIdx + 2) % 13 )
    ++*hexIdx;
  else
    *hexIdx += 3;
}
