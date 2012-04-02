bool __fastcall virtualCoordsWithinCombatScreen(signed int x, signed int y)
{
  return x >= 0 && x < 640 && y >= 0 && y < 443;
}
