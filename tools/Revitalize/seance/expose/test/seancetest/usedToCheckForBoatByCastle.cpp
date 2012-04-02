int __thiscall usedToCheckForBoatByCastle(AdvManager *this, int col, int row)
{
  int result; // eax@4

  if ( (signed __int64)__PAIR__(row, col) >= 0 && mapWidth > col && mapHeight > row )
    result = *this->field_AE + 12 * row * this->field_AE[2] + 12 * col;
  else
    result = *this->field_AE;
  return result;
}
