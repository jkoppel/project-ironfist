{
  char *v1; // ST20_4@1
  char *result; // eax@1

  v1 = &gpGame->players[a1]._4[8];
  *(float *)v1 = (double)Random(0, 100) / 500.0 + 0.23;
  *((float *)v1 + 2) = (double)Random(0, 100) / 500.0 + 0.23;
  *((float *)v1 + 2) = (1.0 + 3.0) / 4.0 * *((float *)v1 + 2);
  *((float *)v1 + 2) = (5.0 - 1.0) / 4.0 * *((float *)v1 + 2);
  *(float *)v1 = (1.0 + 3.0) / 4.0 * *(float *)v1;
  *((float *)v1 + 2) = ((3.0 - (double)gpGame->numPlayers) * 0.15 + 1.0) * *((float *)v1 + 2);
  *(float *)v1 = ((3.0 - (double)gpGame->numPlayers) * 0.07000000000000001 + 1.0) * *(float *)v1;
  result = v1;
  *((float *)v1 + 1) = 1.0 - *((float *)v1 + 2) - *(float *)v1;
  return result;
}