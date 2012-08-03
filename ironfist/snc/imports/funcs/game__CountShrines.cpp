{
  int result; // eax@2
  mapCell *v3; // [sp+10h] [bp-18h]@7
  int row; // [sp+14h] [bp-14h]@3
  int col; // [sp+18h] [bp-10h]@5
  int v6; // [sp+20h] [bp-8h]@3
  town *v7; // [sp+24h] [bp-4h]@7

  if ( xIsExpansionMap )
  {
    v6 = 0;
    for ( row = 0; row < MAP_HEIGHT; ++row )
    {
      for ( col = 0; col < MAP_WIDTH; ++col )
      {
        v3 = &this->map.tiles[row * this->map.width] + col;
        v7 = 0;
        if ( v3->objType == 163 )
        {
          v7 = &gpGame->castles[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)];
        }
        else if ( v3->objType == 170
  && gpGame->heroes[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].occupiedObjType == 163 )
        {
          v7 = &gpGame->castles[gpGame->heroes[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].occupiedObjVal];
        }
        if ( v7 && v7->ownerIdx == a2 && v7->buildingsBuiltFlags & 4 )
        {
          if ( v7->factionID == FACTION_NECROMANCER )
            ++v6;
        }
      }
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}