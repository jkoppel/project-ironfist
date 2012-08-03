{
  int v3; // [sp+10h] [bp-8h]@1
  int v4; // [sp+14h] [bp-4h]@1

  v4 = normalDirTable[4 * a2];
  v3 = byte_4F1DC1[4 * a2];
  return (*(&gbThisNetHumanPlayer + giCurPlayer) || !*(_DWORD *)&blackoutComputer)
      && (MapExtraPosAndAdjacentsSet(*(_DWORD *)(a1 + 25), *(_DWORD *)(a1 + 29), giCurWatchPlayerBit)
       || MapExtraPosAndAdjacentsSet(v4 + *(_DWORD *)(a1 + 25), v3 + *(_DWORD *)(a1 + 29), giCurWatchPlayerBit));
}