{
  return gameObject->day
       + *(_WORD *)(this + 2 * *(_DWORD *)(this + 4) + 28)
       - (gameObject->week
        - 1)
       + 8 * (gameObject->week - 1)
       + 28 * (gameObject->month - 1);
}
