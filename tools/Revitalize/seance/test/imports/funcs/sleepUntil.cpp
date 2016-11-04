{
  int v1; // [sp+Ch] [bp-4h]@1

  v1 = tick;
  while ( getTickCount() < v1 )
  {
    passOnMessages();
    yieldToGlobalUpdater();
  }
}
