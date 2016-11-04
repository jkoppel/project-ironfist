{
  int y; // [sp+10h] [bp-8h]@1
  int x; // [sp+14h] [bp-4h]@1

  retrieveVirtualCursorCoordinates(&x, &y);
  return x >= 0 && x < 640 && y >= 0 && y < 480 && (x < 16 || x > 623 || y < 16 || y > 464);
}
