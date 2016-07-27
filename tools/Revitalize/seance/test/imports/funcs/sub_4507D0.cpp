{
  Player *result; // eax@1

  result = curPlayer;
  LOBYTE(curPlayer->field_45) = -1;
  return result;
}
