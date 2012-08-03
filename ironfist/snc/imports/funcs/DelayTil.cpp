{
  int *d; // [sp+Ch] [bp-4h]@1

  d = tick;
  while ( KBTickCount() < *d )
  {
    Process1WindowsMessage();
    PollSound();
  }
}