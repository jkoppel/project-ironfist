{
  combatManager *this; // [sp+3Ch] [bp-C4h]@1
  int randNeighbor; // [sp+50h] [bp-B0h]@68
  char missTiles[11]; // [sp+54h] [bp-ACh]@68
  int neighb; // [sp+60h] [bp-A0h]@70
  int v6; // [sp+64h] [bp-9Ch]@60
  int v7; // [sp+68h] [bp-98h]@52
  int hexIdx; // [sp+6Ch] [bp-94h]@5
  icon *boulderICN; // [sp+70h] [bp-90h]@43
  unsigned int missed; // [sp+74h] [bp-8Ch]@5
  int v11; // [sp+78h] [bp-88h]@83
  H2RECT rect; // [sp+7Ch] [bp-84h]@103
  int v13; // [sp+8Ch] [bp-74h]@83
  int i; // [sp+90h] [bp-70h]@72
  int j; // [sp+94h] [bp-6Ch]@68
  icon *cloudICN; // [sp+98h] [bp-68h]@116
  int garrisonIsTarget; // [sp+9Ch] [bp-64h]@5
  int numTurrets; // [sp+A0h] [bp-60h]@5
  int targetTurret; // [sp+A4h] [bp-5Ch]@5
  sample_resource v20; // [sp+A8h] [bp-58h]@43
  int catDamage; // [sp+B0h] [bp-50h]@5
  int targY; // [sp+B4h] [bp-4Ch]@43
  float v23; // [sp+B8h] [bp-48h]@83
  float boulderY; // [sp+BCh] [bp-44h]@83
  int targetWall; // [sp+C0h] [bp-40h]@5
  int targX; // [sp+C4h] [bp-3Ch]@43
  float v27; // [sp+C8h] [bp-38h]@83
  float boulderX; // [sp+CCh] [bp-34h]@83
  int numWalls; // [sp+D0h] [bp-30h]@5
  sample_resource res; // [sp+D4h] [bp-2Ch]@43
  float v31; // [sp+DCh] [bp-24h]@83
  int gateIsTargetl; // [sp+E0h] [bp-20h]@5
  float v33; // [sp+E4h] [bp-1Ch]@83
  int v34; // [sp+E8h] [bp-18h]@83
  int rndNum; // [sp+ECh] [bp-14h]@5
  resource *catapultSound; // [sp+F0h] [bp-10h]@43
  int imageIdx; // [sp+F8h] [bp-8h]@83
  int v38; // [sp+FCh] [bp-4h]@83

  this = ecx0;
  if ( ecx0->isCastleBattle )
  {
    LogStr("CA1");
    if ( *(_DWORD *)&this->_15[100] != -1 || *(_DWORD *)&this->_15[104] != -1 )
    {
      *(_DWORD *)&this->_15[104] = -1;
      *(_DWORD *)&this->_15[100] = *(_DWORD *)&this->_15[104];
      combatManager::DrawSmallView(this, 0, 1);
      combatManager::DrawSmallView(this, 1, 1);
    }
    rndNum = SRandom(0, 20);
    numWalls = 0;
    numTurrets = 0;
    targetWall = -1;
    targetTurret = -1;
    gateIsTargetl = -1;
    garrisonIsTarget = -1;
    hexIdx = -1;
    missed = 0;
    catDamage = 1;
    if ( this->wallStatus[0] != 2 && this->wallStatus[0] != 6 )
      ++numWalls;
    if ( this->wallStatus[1] != 2 && this->wallStatus[1] != 6 )
      ++numWalls;
    if ( this->wallStatus[2] != 2 && this->wallStatus[2] != 6 )
      ++numWalls;
    if ( this->wallStatus[3] != 2 && this->wallStatus[3] != 6 )
      ++numWalls;
    if ( this->turretStatus[0] == 1 )
      ++numTurrets;
    if ( this->turretStatus[3] == 1 )
      ++numTurrets;
    if ( numWalls )
    {
      rndNum = rndNum % numWalls + 1;
      targetWall = -1;
      while ( rndNum )
      {
        ++targetWall;
        if ( this->wallStatus[targetWall] != 2 )
        {
          if ( this->wallStatus[targetWall] != 6 )
            --rndNum;
        }
      }
    }
    else if ( numTurrets )
    {
      rndNum %= numTurrets;
      if ( rndNum != 1 && this->turretStatus[0] != 2 )
        targetTurret = 0;
      else
        targetTurret = 3;
    }
    else if ( this->drawBridgePosition == MOAT_DESTROYED )
    {
      if ( !this->ballistaDestroyed )
        garrisonIsTarget = 0;
    }
    else
    {
      gateIsTargetl = 1;
    }
    if ( targetTurret != -1 || targetWall != -1 || gateIsTargetl != -1 || garrisonIsTarget != -1 )
    {
      sprintf(gText, "catsnd%02d.82M", 2);
      catapultSound = (resource *)resourceManager::GetSample(gpResourceManager, gText);
      res = NULL_SAMPLE2;
      boulderICN = resourceManager::GetIcon(gpResourceManager, "boulder.icn");
      sprintf(gText, "catsnd%02d.82M", 0);
      v20 = LoadPlaySample(gText);
      targX = -1;
      targY = -1;
      if ( targetWall != -1 )
      {
        targX = wallPos[targetWall].x;
        targY = wallPos[targetWall].y;
        hexIdx = byte_4F4C30[11][targetWall + 121];
      }
      if ( targetTurret != -1 )
      {
        targX = towerPos[targetTurret].x;
        targY = towerPos[targetTurret].y;
        hexIdx = byte_4F4C30[11][targetTurret + 125];
      }
      if ( gateIsTargetl != -1 )
      {
        targX = (unsigned __int16)doorPos.x;
        targY = (unsigned __int16)doorPos.y;
        hexIdx = 59;
      }
      if ( garrisonIsTarget != -1 )
      {
        targX = 600;
        targY = 160;
        hexIdx = 77;
      }
      if ( this->heroes[0]->secondarySkillLevel[10] )
      {
        if ( this->heroes[0]->secondarySkillLevel[10] > 2 )
        {
          if ( this->heroes[0]->secondarySkillLevel[10] == 3 )
            catDamage = 2;
        }
        else
        {
          v6 = SRandom(0, 100);
          if ( !gbHumanPlayer[this->heroes[0]->probablyOwnerIdx] )
            v6 -= 5;
          if ( v6 < 50 )
            catDamage = 2;
        }
      }
      else
      {
        v7 = SRandom(0, 100);
        if ( !gbHumanPlayer[this->heroes[0]->probablyOwnerIdx] )
          v7 -= 5;
        if ( v7 >= 25 )
        {
          if ( v7 > 75 )
          {
            missed = 1;
            catDamage = 0;
          }
        }
        else
        {
          catDamage = 2;
        }
      }
      if ( missed )                             // The catapult will hit a tile adjacent to its target
      {
        missTiles[0] = 32;
        missTiles[1] = 46;
        missTiles[2] = 10;
        missTiles[3] = 23;
        missTiles[4] = 35;
        missTiles[5] = 48;
        missTiles[6] = 60;
        missTiles[7] = 74;
        missTiles[8] = 87;
        missTiles[9] = 101;
        missTiles[10] = 114;
        randNeighbor = SRandom(0, 5);
        for ( j = 0; j < 6; ++j )
        {
          neighb = GetAdjacentCellIndexNoArmy(hexIdx, (j + randNeighbor) % 6);
          if ( neighb != -1 && this->combatGrid[neighb].unitOwner == -1 )
          {
            for ( i = 0; i < 11; ++i )
            {
              if ( (unsigned __int8)missTiles[i] == neighb )
              {
                targX = this->combatGrid[neighb].centerX;
                targY = this->combatGrid[neighb].occupyingCreatureBottomY - 17;
                goto LABEL_79;
              }
            }
          }
        }
        missed = 0;
        catDamage = 1;
LABEL_79:
        ++j;
      }
      giMinExtentX = 0;
      giMaxExtentX = 160;
      giMinExtentY = 263;
      giMaxExtentY = 413;
      for ( this->probablyCatapultImgIdx[side] = 0;
            this->probablyCatapultImgIdx[side] < 5;
            ++this->probablyCatapultImgIdx[side] )
        combatManager::DrawFrame(this, 1, 0, 1, 0, 75, 1, 1);
      v13 = 84;
      v11 = 304;
      imageIdx = 0;
      boulderX = (double)84;
      boulderY = (double)304;
      v33 = (double)((targX + 84) / 2);
      v31 = (double)targY - (double)(targX - 84) * 0.3 - (double)targY * 0.35;
      v27 = (v33 - (double)84) / 12.5;
      v23 = (v31 - (double)304) / 78.0;
      v38 = -1;
      v34 = -1;
      for ( j = 0; j < 25; ++j )
      {
        if ( j == 12 )
          v23 = (v31 - (double)targY) / 78.0;
        if ( j )
        {
          giMinExtentX = v38 - 15;
          giMaxExtentX = (signed __int64)(boulderX + 15.0);
          giMinExtentY = (signed __int64)(boulderY - 15.0);
          giMaxExtentY = (signed __int64)(boulderY + 15.0);
          if ( (double)v34 >= boulderY )
            giMaxExtentY = v34 + 15;
          else
            giMinExtentY = v34 - 15;
          if ( j <= 6 )
          {
            giMinExtentX = 0;
            giMaxExtentY = 413;
          }
          if ( giMinExtentX < 0 )
            giMinExtentX = 0;
          if ( giMinExtentY < 0 )
            giMinExtentY = 0;
          if ( giMaxExtentX > 639 )
            giMaxExtentX = 639;
          if ( giMaxExtentY > 442 )
            giMaxExtentY = 442;
          if ( giMaxExtentY < 1 )
            giMaxExtentY = 1;
        }
        combatManager::DrawFrame(this, 0, 0, 1, 0, 63, 1, 1);
        icon::CombatClipDrawToBuffer(
          boulderICN,
          (signed __int64)boulderX,
          (signed __int64)boulderY,
          imageIdx,
          &rect,
          0,
          0,
          0,
          0);
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          giMinExtentX,
          giMinExtentY,
          giMaxExtentX - giMinExtentX + 1,
          giMaxExtentY - giMinExtentY + 1);
        v38 = (signed __int64)boulderX;
        v34 = (signed __int64)boulderY;
        boulderX = boulderX + v27;
        boulderY = (double)(12 - j) * v23 + boulderY;
        ++imageIdx;
        imageIdx = (((unsigned __int64)imageIdx >> 32) ^ abs(imageIdx) & 7) - ((unsigned __int64)imageIdx >> 32);
        if ( j < 4 )
          ++this->probablyCatapultImgIdx[side];
      }
      sprintf(gText, "catsnd%02d.82M", 2);
      res = LoadPlaySample(gText);
      this->zeroedInHandleCatapult1 = 0;
      this->zeroedInHandleCatapult2 = 0;
      giMinExtentX = targX - 75;
      giMaxExtentX = targX + 75;
      giMinExtentY = targY - 50;
      giMaxExtentY = targY + 150;
      if ( gateIsTargetl != -1 )
        giMinExtentX -= 75;
      if ( giMinExtentX < 0 )
        giMinExtentX = 0;
      if ( giMaxExtentX > 639 )
        giMaxExtentX = 639;
      if ( giMinExtentY < 0 )
        giMinExtentY = 0;
      if ( giMaxExtentY > 442 )
        giMaxExtentY = 442;
      cloudICN = resourceManager::GetIcon(
                   gpResourceManager,
                   &aSmalclod_icn[("lichclod.icn" - "smalclod.icn") & ((missed != 0) - 1)]);
      for ( j = 0; j < 12; ++j )
      {
        if ( j < 10 || gateIsTargetl == -1 && !missed )
        {
          animTimer = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 75.0);
          combatManager::DrawFrame(this, 0, 0, 1, 0, 0, 1, 0);
          if ( gateIsTargetl != -1 && j >= 2 && !missed )
            IconToBitmap(
              cloudICN,
              gpWindowManager->screenBuffer,
              targX - 45,
              targY + 70,
              j - 2,
              1,
              0,
              0,
              0x280u,
              443,
              0);
          if ( j < 10 )
            IconToBitmap(
              cloudICN,
              gpWindowManager->screenBuffer,
              targX,
              targY + (missed < 1 ? 0x19 : 0),
              j,
              1,
              0,
              0,
              0x280u,
              443,
              0);
          heroWindowManager::UpdateScreenRegion(
            gpWindowManager,
            giMinExtentX,
            giMinExtentY,
            giMaxExtentX - giMinExtentX + 1,
            giMaxExtentY - giMinExtentY + 1);
          DelayTil(&animTimer);
          if ( (j == 6 && gateIsTargetl == -1 || j == 7 && gateIsTargetl != -1) && !missed )
          {
            if ( targetWall == -1 )
            {
              if ( targetTurret == -1 )
              {
                if ( gateIsTargetl == -1 )
                {
                  if ( garrisonIsTarget != -1 )
                    this->ballistaDestroyed = 1;
                }
                else
                {
                  this->drawBridgePosition = MOAT_DESTROYED;
                }
              }
              else
              {
                this->turretStatus[targetTurret] = 2;
              }
            }
            else
            {
              if ( this->wallStatus[targetWall] < 3 || this->wallStatus[targetWall] > 5 )
              {
                if ( catDamage <= 1 )
                  ++this->wallStatus[targetWall];
                else
                  this->wallStatus[targetWall] = 2;
              }
              else
              {
                this->wallStatus[targetWall] += catDamage;
                if ( this->wallStatus[targetWall] > 5 )
                  this->wallStatus[targetWall] = 6;
              }
              if ( this->wallStatus[targetWall] == 2 || this->wallStatus[targetWall] == 6 )
                this->combatGrid[byte_4F4C30[11][targetWall + 121]].isBlocked = 0;
            }
          }
        }
      }
      resourceManager::Dispose(gpResourceManager, (resource *)cloudICN);
      this->probablyCatapultImgIdx[side] = 0;
      combatManager::DrawFrame(this, 1, 0, 0, 0, 75, 1, 1);
      resourceManager::Dispose(gpResourceManager, (resource *)boulderICN);
      WaitEndSample(-1, res);
      WaitEndSample(-1, v20);
      if ( catapultSound )
        resourceManager::Dispose(gpResourceManager, catapultSound);
      LogStr("CA2");
    }
  }
}