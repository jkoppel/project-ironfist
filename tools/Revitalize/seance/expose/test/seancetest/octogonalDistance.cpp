// This is an odd but simple metric, best described by the source code. Its unit circle is an octogon.
int __stdcall octogonalDistance(int x1, int y1, int x2, int y2)
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
