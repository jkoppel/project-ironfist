void *__thiscall sub_4D9820(TextEntry *this, const char *a2, unsigned __int16 a3)
{
  TextEntry *thisa; // ebp@1
  int v4; // eax@1
  const char *v5; // esi@4
  unsigned int v6; // ebx@7
  void *result; // eax@10
  int v8; // ecx@14
  int v9; // ebx@18
  signed int v10; // [sp+10h] [bp-130h]@13
  char str; // [sp+14h] [bp-12Ch]@13
  char v12[299]; // [sp+15h] [bp-12Bh]@14

  thisa = this;
  if ( getTickCount() > animationFrameSwitchTime )
  {
    thisa->_2 = 1 - thisa->_2;
    animationFrameSwitchTime = getTickCount() + 360;
  }
  if ( a3 )
  {
    v5 = a2;
    strncpy((char *)thisa->ptrToFifthShortPlusFiveManyBytes, a2, a3);
  }
  else
  {
    v5 = a2;
  }
  if ( thisa->_2 )
  {
    v6 = a3;
    *((_BYTE *)thisa->ptrToFifthShortPlusFiveManyBytes + a3) = 31;
  }
  else
  {
    v6 = a3;
    *((_BYTE *)thisa->ptrToFifthShortPlusFiveManyBytes + a3) = 95;
  }
  if ( strlen(v5) <= v6 )
  {
    result = thisa->ptrToFifthShortPlusFiveManyBytes;
    *((_BYTE *)result + v6 + 1) = 0;
  }
  else
  {
    strcpy((char *)(v4 + v6 + 1), &v5[v6]);
    result = thisa->ptrToFifthShortPlusFiveManyBytes;
  }
  if ( thisa->type == 3 )
  {
    do
    {
      v10 = 0;
      strcpy(&str, (const char *)thisa->ptrToFifthShortPlusFiveManyBytes + thisa->field_4B);
      if ( Font::getFlattenedStringWidth((Font *)thisa->font, &str) > thisa->field_3D )
      {
        v8 = thisa->font;
        v12[v6 - thisa->field_4B] = 0;
        if ( Font::getFlattenedStringWidth((Font *)v8, &str) > thisa->field_3D )
        {
          v10 = 1;
          ++thisa->field_4B;
        }
      }
      result = (void *)v10;
    }
    while ( v10 );
    if ( thisa->field_4B > 0 )
    {
      do
      {
        v9 = 0;
        strcpy(&str, (const char *)thisa->ptrToFifthShortPlusFiveManyBytes + thisa->field_4B - 1);
        result = (void *)Font::getFlattenedStringWidth((Font *)thisa->font, &str);
        if ( (signed int)result > thisa->field_3D )
          v9 = 0;
        else
          --thisa->field_4B;
        if ( !thisa->field_4B )
          v9 = 0;
      }
      while ( v9 );
    }
  }
  return result;
}
