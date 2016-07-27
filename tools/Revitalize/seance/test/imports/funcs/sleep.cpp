{
  int v1; // ST0C_4@1
  int v2; // eax@1

  v1 = x;
  v2 = getTickCount();
  sleepUntil(v2 + v1);
}
