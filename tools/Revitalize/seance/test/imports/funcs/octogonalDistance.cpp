{
  signed int xDist; // esi@1
  signed int yDist; // eax@1
  int result; // eax@2

  xDist = abs(x1 - x2);
  yDist = abs(y1 - y2);
  if ( xDist < yDist )
    result = yDist + xDist / 2;
  else
    result = xDist + yDist / 2;
  return result;
}
