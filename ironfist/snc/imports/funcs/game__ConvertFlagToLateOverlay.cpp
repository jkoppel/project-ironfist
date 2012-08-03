{
  game *result; // eax@3
  mapCell *v4; // [sp+10h] [bp-8h]@1
  int v5; // [sp+14h] [bp-4h]@4

  v4 = &this->map.tiles[a3 * this->map.width] + a2;
  if ( (((unsigned __int8)v4->field_6 >> 2) & 0x3F) == 14 )
    v4->field_6 |= 2u;
  result = (game *)v4;
  if ( v4->field_A )
  {
    result = this;
    v5 = this->map.field_4 + 7 * v4->field_A;
  }
  else
  {
    v5 = 0;
  }
  while ( v5 )
  {
    if ( ((*(_BYTE *)(v5 + 5) >> 2) & 0x3F) == 14 )
      *(_BYTE *)(v5 + 5) |= 2u;
    result = (game *)v5;
    if ( *(_WORD *)v5 )
    {
      result = this;
      v5 = this->map.field_4 + 7 * *(_WORD *)v5;
    }
    else
    {
      v5 = 0;
    }
  }
  return result;
}