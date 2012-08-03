{
  playerData *result; // eax@1

  result = gpCurPlayer;
  LOBYTE(gpCurPlayer->field_45) = -1;
  return result;
}