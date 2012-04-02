void __fastcall sub_4AA5F0(int a1, int a2, int a3)
{
  int v3; // ebx@9
  int v4; // ebx@18
  int v5; // [sp+Ch] [bp-10h]@1
  int v6; // [sp+10h] [bp-Ch]@1
  int j; // [sp+14h] [bp-8h]@6
  int i; // [sp+18h] [bp-4h]@4
  signed int k; // [sp+18h] [bp-4h]@15

  v5 = a2;
  v6 = a1;
  if ( a2 != -1 && a3 != -1 )
  {
    for ( i = 0; i < mapWidth; ++i )
    {
      for ( j = 0; j < mapHeight; ++j )
      {
        if ( v6 )
        {
          v3 = abs(a3 - j);
          if ( abs(v5 - i) + v3 < 10 )
            *((_WORD *)dword_51D5A0 + i + mapWidth * j) = -32001;
        }
        else
        {
          *((_WORD *)dword_51D5A0 + i + mapWidth * j) = -32001;
          *((_WORD *)dword_51D5A4 + i + mapWidth * j) = -32001;
        }
      }
    }
    *((_WORD *)dword_51D5A4 + v5 + a3 * mapWidth) = -32001;
    for ( k = 0; k < 54; ++k )
    {
      if ( v6 )
      {
        v4 = abs(a3 - gameObject->heroes[k].x);
        if ( abs(v5 - gameObject->heroes[k].x) + v4 >= 10 )
          continue;
      }
      word_532C60[k] = -32001;
    }
  }
}
