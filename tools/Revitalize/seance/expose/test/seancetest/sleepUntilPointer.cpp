void __fastcall sleepUntilPointer(int *tick)
{
  int *d; // [sp+Ch] [bp-4h]@1

  d = tick;
  while ( getTickCount() < *d )
  {
    passOnMessages();
    yieldToGlobalUpdater();
  }
}
