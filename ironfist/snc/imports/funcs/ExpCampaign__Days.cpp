{
  return gpGame->day
       + *(_WORD *)(this + 2 * *(_DWORD *)(this + 4) + 28)
       - (gpGame->week
        - 1)
       + 8 * (gpGame->week - 1)
       + 28 * (gpGame->month - 1);
}