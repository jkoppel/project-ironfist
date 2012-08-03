{
  textEntryWidget *thisa; // ebp@1
  const char *v4; // esi@4
  unsigned int v5; // ebx@7
  void *result; // eax@10
  int v7; // ecx@14
  int v8; // ebx@18
  signed int v9; // [sp+10h] [bp-130h]@13
  char str; // [sp+14h] [bp-12Ch]@13
  char v11[299]; // [sp+15h] [bp-12Bh]@14

  thisa = this;
  if ( KBTickCount() > glTimers )
  {
    thisa->_2 = 1 - thisa->_2;
    glTimers = KBTickCount() + 360;
  }
  if ( a3 )
  {
    v4 = a2;
    strncpy((char *)thisa->ptrToFifthShortPlusFiveManyBytes, a2, a3);
  }
  else
  {
    v4 = a2;
  }
  if ( thisa->_2 )
  {
    v5 = a3;
    *((_BYTE *)thisa->ptrToFifthShortPlusFiveManyBytes + a3) = 31;
  }
  else
  {
    v5 = a3;
    *((_BYTE *)thisa->ptrToFifthShortPlusFiveManyBytes + a3) = 95;
  }
  if ( strlen(v4) <= v5 )
  {
    result = thisa->ptrToFifthShortPlusFiveManyBytes;
    *((_BYTE *)result + v5 + 1) = 0;
  }
  else
  {
    result = thisa->ptrToFifthShortPlusFiveManyBytes;
    strcpy((char *)result + v5 + 1, &v4[v5]);
  }
  if ( thisa->type == 3 )
  {
    do
    {
      v9 = 0;
      strcpy(&str, (const char *)thisa->ptrToFifthShortPlusFiveManyBytes + thisa->field_4B);
      if ( font::LineWidth((font *)thisa->font, &str) > thisa->field_3D )
      {
        v7 = thisa->font;
        v11[v5 - thisa->field_4B] = 0;
        if ( font::LineWidth((font *)v7, &str) > thisa->field_3D )
        {
          v9 = 1;
          ++thisa->field_4B;
        }
      }
      result = (void *)v9;
    }
    while ( v9 );
    if ( thisa->field_4B > 0 )
    {
      do
      {
        v8 = 0;
        strcpy(&str, (const char *)thisa->ptrToFifthShortPlusFiveManyBytes + thisa->field_4B - 1);
        result = (void *)font::LineWidth((font *)thisa->font, &str);
        if ( (signed int)result > thisa->field_3D )
          v8 = 0;
        else
          --thisa->field_4B;
        if ( !thisa->field_4B )
          v8 = 0;
      }
      while ( v8 );
    }
  }
  return result;
}