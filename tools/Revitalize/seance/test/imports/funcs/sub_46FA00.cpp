{
  int result; // eax@2
  __int16 v4; // ax@7
  int v5; // ST1C_4@7
  MapTiles *this; // [sp+Ch] [bp-14h]@1
  int v7; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@3

  this = ecx0;
  if ( *(&ecx0->tiles[col].field_A + 6 * row * ecx0->width) )
  {
    v7 = *(&ecx0->tiles[col].field_A + 6 * row * ecx0->width);
    for ( i = ecx0->field_4 + 7 * *(&ecx0->tiles[col].field_A + 6 * row * ecx0->width);
          ;
          i = ecx0->field_4 + 7 * *(_WORD *)i )
    {
      if ( *(_BYTE *)(i + 6) == 255 )
        return i;
      if ( !*(_WORD *)i )
        break;
      v7 = *(_WORD *)i;
    }
    v4 = sub_46F8D0(ecx0);
    v5 = this->field_4 - v7 + 8 * v7;
    *(_WORD *)v5 = v4;
    result = this->field_4 + 7 * *(_WORD *)v5;
  }
  else
  {
    *(&ecx0->tiles[col].field_A + 6 * row * ecx0->width) = sub_46F8D0(ecx0);
    result = this->field_4 + 7 * *(&this->tiles[col].field_A + 6 * row * this->width);
  }
  return result;
}
