{
  int v5; // [sp+Ch] [bp-84h]@1
  char v6; // [sp+14h] [bp-7Ch]@18
  int v7; // [sp+78h] [bp-18h]@10
  int i; // [sp+7Ch] [bp-14h]@1
  bool v9; // [sp+80h] [bp-10h]@8
  int v10; // [sp+84h] [bp-Ch]@10
  int v11; // [sp+88h] [bp-8h]@1
  int v12; // [sp+8Ch] [bp-4h]@15

  v5 = this;
  v11 = -1;
  for ( i = 0; *(_BYTE *)(this + 707) > i; ++i )
  {
    if ( *(_BYTE *)(i + this + 1119) == dword_524730 )
      v11 = i;
  }
  v9 = v11 >= a3 && v11 <= a4;
  v7 = a4 - a3 + 1;
  v10 = a4 - a3 + 1 - ((unsigned int)v9 >= 1);
  if ( v9 )
  {
    if ( v10 )
    {
      if ( v10 <= 1 )
        sprintf(a2, "You and your ally ");
      else
        sprintf(a2, "You and your allies ");
      v12 = 0;
      for ( i = a3; i <= a4; ++i )
      {
        if ( v11 != i )
        {
          ++v12;
          sprintf(&v6, (&off_4F62F8)[4 * *(_BYTE *)(i + v5 + 1101)]);
          v6 -= 32;
          strcat(a2, &v6);
          if ( v10 - 1 <= v12 )
          {
            if ( v10 > v12 )
              strcat(a2, " and ");
          }
          else
          {
            strcat(a2, ", ");
          }
        }
      }
    }
    else
    {
      sprintf(a2, "You");
    }
  }
  else
  {
    if ( v7 <= 1 )
      strcpy(a2, "the enemy - ");
    else
      strcpy(a2, "the enemy alliance of ");
    v12 = 0;
    for ( i = a3; i <= a4; ++i )
    {
      ++v12;
      sprintf(&v6, (&off_4F62F8)[4 * *(_BYTE *)(i + v5 + 1101)]);
      v6 -= 32;
      strcat(a2, &v6);
      if ( v10 - 1 <= v12 )
      {
        if ( v10 > v12 )
          strcat(a2, " and ");
      }
      else
      {
        strcat(a2, ", ");
      }
    }
  }
  return v9;
}
