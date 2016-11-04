{
  char *v6; // eax@1
  int v7; // esi@1
  int i; // edi@1
  PathfindingInfo *v9; // ebx@4
  int v10; // edx@7
  int v11; // edx@8

  v6 = (char *)&this->field_2418;
  this->field_8 = 0;
  v7 = a4;
  for ( i = a5; a2 != v7 || a3 != i; i += byte_4F1DC1[4 * v11] )
  {
    v9 = &this->field_2414[v7 + i * mapWidth];
    if ( v9->field_0 != v7 && v9->field_1 != i )
      return 0;
    if ( v9->field_2 <= a6 )
    {
      ++v6;
      *(v6 - 1) = (unsigned __int8)v9->field_4 >> 4;
      v10 = this->field_8 + 1;
      this->field_8 = v10;
      if ( v10 >= 256 )
      {
        this->field_8 = 0;
        return this->field_8;
      }
    }
    v11 = (((unsigned __int8)v9->field_4 >> 4) + 4) & 7;
    v7 += byte_4F1DC0[4 * v11];
  }
  return this->field_8;
}
