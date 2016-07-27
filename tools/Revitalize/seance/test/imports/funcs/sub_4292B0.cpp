{
  unsigned int result; // eax@2
  char v1; // [sp+10h] [bp-14h]@5
  char v2; // [sp+14h] [bp-10h]@5
  char v3; // [sp+18h] [bp-Ch]@1
  unsigned int j; // [sp+1Ch] [bp-8h]@3
  unsigned int i; // [sp+20h] [bp-4h]@1

  v3 = 127;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( mapWidth <= (signed int)i )
      break;
    for ( j = 0; (signed int)j < mapHeight; ++j )
    {
      if ( sub_456630(advManager, __PAIR__(j, i), (int)&v2, (int)&v1, -1, -1) )
        *(&tileExplored[i] + mapWidth * j) |= 0x80u;
      else
        *(&tileExplored[i] + mapWidth * j) &= v3;
    }
  }
  return result;
}
