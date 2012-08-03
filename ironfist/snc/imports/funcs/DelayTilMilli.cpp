{
  int v1; // [sp+Ch] [bp-4h]@1

  v1 = tick;
  while ( KBTickCount() < v1 )
  {
    Process1WindowsMessage();
    PollSound();
  }
}