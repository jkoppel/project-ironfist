{
  signed int v3; // [sp+10h] [bp-4h]@1

  v3 = 0;
  if ( a1 >= 1 )
  {
    if ( mapWidth - 1 <= a1 )
      v3 = 50;
  }
  else
  {
    v3 = 200;
  }
  if ( a2 >= 1 )
  {
    if ( mapHeight - 1 <= a2 )
      v3 |= 0x64u;
  }
  else
  {
    v3 |= 0x91u;
  }
  if ( v3 )
  {
    if ( !(v3 & 1) && !(unsigned __int8)(*(&tileExplored[a1] + mapWidth * (a2 - 1)) & byte_5306F0) )
      v3 |= 1u;
    if ( !(v3 & 2) && !(unsigned __int8)(*(&tileExplored[a2 * mapWidth + 1] + a1) & byte_5306F0) )
      v3 |= 2u;
    if ( !(v3 & 4) && !(unsigned __int8)(*(&tileExplored[a1] + mapWidth * (a2 + 1)) & byte_5306F0) )
      v3 |= 4u;
    if ( !(v3 & 8) && !(unsigned __int8)(*(&tileExplored[a2 * mapWidth - 1] + a1) & byte_5306F0) )
      v3 |= 8u;
    if ( !(v3 & 0x10) && !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 - 1) + 1] + a1) & byte_5306F0) )
      v3 |= 0x10u;
    if ( !(v3 & 0x20) && !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 + 1) + 1] + a1) & byte_5306F0) )
      v3 |= 0x20u;
    if ( !(v3 & 0x40) && !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 + 1) - 1] + a1) & byte_5306F0) )
      v3 |= 0x40u;
    if ( !(v3 & 0x80) && !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 - 1) - 1] + a1) & byte_5306F0) )
      v3 |= 0x80u;
  }
  else
  {
    if ( !(unsigned __int8)(*(&tileExplored[a1] + mapWidth * (a2 - 1)) & byte_5306F0) )
      v3 = 1;
    if ( !(unsigned __int8)(*(&tileExplored[a2 * mapWidth + 1] + a1) & byte_5306F0) )
      v3 |= 2u;
    if ( !(unsigned __int8)(*(&tileExplored[a1] + mapWidth * (a2 + 1)) & byte_5306F0) )
      v3 |= 4u;
    if ( !(unsigned __int8)(*(&tileExplored[a2 * mapWidth - 1] + a1) & byte_5306F0) )
      v3 |= 8u;
    if ( !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 - 1) + 1] + a1) & byte_5306F0) )
      v3 |= 0x10u;
    if ( !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 + 1) + 1] + a1) & byte_5306F0) )
      v3 |= 0x20u;
    if ( !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 + 1) - 1] + a1) & byte_5306F0) )
      v3 |= 0x40u;
    if ( !(unsigned __int8)(*(&tileExplored[mapWidth * (a2 - 1) - 1] + a1) & byte_5306F0) )
      v3 |= 0x80u;
  }
  return (unsigned __int8)byte_4F2B28[v3];
}
