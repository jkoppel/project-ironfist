{
  int v1; // ST1C_4@14
  CombatManager *thisa; // [sp+Ch] [bp-58h]@1
  int v3; // [sp+14h] [bp-50h]@13
  signed int botSq; // [sp+18h] [bp-4Ch]@32
  char cobjAlreadyPlaced[32]; // [sp+1Ch] [bp-48h]@23
  int cantPlace; // [sp+3Ch] [bp-28h]@30
  int coverID; // [sp+40h] [bp-24h]@15
  int numCoveredHexes; // [sp+44h] [bp-20h]@13
  int i; // [sp+48h] [bp-1Ch]@2
  int row; // [sp+4Ch] [bp-18h]@29
  int hex; // [sp+50h] [bp-14h]@26
  int covObjsToPlace; // [sp+54h] [bp-10h]@13
  int v13; // [sp+58h] [bp-Ch]@13
  int terrainMask; // [sp+5Ch] [bp-8h]@13
  int cobjID; // [sp+60h] [bp-4h]@26

  thisa = this;
  this->combatFieldCoverID = 0;
  if ( this->isCastleBattle )
  {
    this->ballistaDestroyed = 0;
    for ( i = 0; i < 4; ++i )
    {
      this->wallStatus[i] = 0;
      if ( !this->castles[1]->factionID )
      {
        if ( BYTE1(this->castles[1]->buildingsBuiltFlags) & BUILDING_SPECIAL_DEFENSE_BUILT )
          this->wallStatus[i] = 3;
      }
      this->turretStatus[i] = 0;
    }
    if ( BYTE1(this->castles[1]->buildingsBuiltFlags) & BUILDING_RIGHT_TURRET_BUILT )
      this->turretStatus[0] = 1;
    if ( BYTE1(this->castles[1]->buildingsBuiltFlags) & BUILDING_LEFT_TURRET_BUILT )
      this->turretStatus[3] = 1;
    this->combatGrid[9].probablyIsBlocked = 1;
    this->combatGrid[22].probablyIsBlocked = 1;
    this->combatGrid[34].probablyIsBlocked = 1;
    this->combatGrid[47].probablyIsBlocked = 1;
    this->combatGrid[59].probablyIsBlocked = 1;
    this->combatGrid[73].probablyIsBlocked = 1;
    this->combatGrid[86].probablyIsBlocked = 1;
    this->combatGrid[100].probablyIsBlocked = 1;
    this->combatGrid[113].probablyIsBlocked = 1;
    this->combatGrid[92].probablyIsBlocked = 1;
  }
  else
  {
    covObjsToPlace = nextRandomInt(3, 7);
    v3 = 0;
    terrainMask = 1 << LOBYTE(thisa->terrainType);
    v13 = 0;
    numCoveredHexes = 0;
    if ( nextRandomInt(0, 99) < 40 )
    {
      while ( 1 )
      {
        v1 = v13++;
        if ( v1 >= 100 )
          break;
        coverID = nextRandomInt(0, 24);
        if ( combatCovers[coverID].terrains & (unsigned __int16)terrainMask )
        {
          thisa->combatFieldCoverID = coverID;
          for ( i = 0; i < 15; ++i )
          {
            if ( *(&byte_4F529A[17 * thisa->combatFieldCoverID] + i) != -1 )
            {
              thisa->combatGrid[*(&byte_4F529A[17 * thisa->combatFieldCoverID] + i)].probablyIsBlocked = 1;
              ++numCoveredHexes;
            }
          }
          break;
        }
      }
    }
    covObjsToPlace -= numCoveredHexes / 2;
    v13 = 0;
    memset(cobjAlreadyPlaced, 0, 0x20u);
    while ( covObjsToPlace > v3 && v13 < 500 )
    {
      ++v13;
      hex = nextRandomInt(0, 116);
      cobjID = nextRandomInt(0, 32);            // Confused. I believe range is inclusive, but this can here give OOB cobj
      if ( combatObjs[cobjID].terrains & terrainMask )
      {
        if ( !cobjAlreadyPlaced[cobjID] )
        {
          row = hex / 13;
          if ( (unsigned __int8)byte_4F3904[14 * cobjID] <= hex / 13 + 1 )
          {
            cantPlace = 0;
            for ( i = 0; (unsigned __int8)byte_4F3905[14 * cobjID] > i; ++i )
            {
              botSq = hex + *(&byte_4F3906[14 * cobjID] + i);
              if ( botSq % 13 <= 2 || botSq % 13 >= 10 )
                cantPlace = 1;
              if ( thisa->combatGrid[botSq].probablyIsBlocked )
                cantPlace = 1;
            }
            if ( !cantPlace )
            {
              v13 = 0;
              v3 += (unsigned __int8)byte_4F3905[14 * cobjID];
              cobjAlreadyPlaced[cobjID] = 1;
              for ( i = 0; (unsigned __int8)byte_4F3905[14 * cobjID] > i; ++i )
                thisa->combatGrid[hex + *(&byte_4F3906[14 * cobjID] + i)].probablyIsBlocked = 1;
              sprintf(globBuf, "cobj%04d.icn", cobjID);
              thisa->combatObjIcons[thisa->numCombatObjs] = ResourceManager::getIconByFilename(resourceManager, globBuf);
              thisa->combatGrid[hex].combatObjIdx = LOBYTE(thisa->numCombatObjs);
              ++thisa->numCombatObjs;
            }
          }
        }
      }
    }
  }
}
