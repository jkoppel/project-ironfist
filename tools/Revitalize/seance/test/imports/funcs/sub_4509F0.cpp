{
  AdvManager *result; // eax@12
  int v4; // [sp+10h] [bp-Ch]@1
  int v5; // [sp+10h] [bp-Ch]@10
  signed int i; // [sp+14h] [bp-8h]@1
  char *v7; // [sp+18h] [bp-4h]@1

  sub_4507F0((int)this);
  LOBYTE(curPlayer->field_45) = a2;
  v7 = (char *)&gameObject->castles[LOBYTE(curPlayer->field_45)];
  this->viewX = gameObject->castles[LOBYTE(curPlayer->field_45)].field_4 - 7;
  this->viewY = (unsigned __int8)v7[5] - 7;
  v4 = 0;
  for ( i = 0; curPlayer->numCastles > i; ++i )
  {
    if ( curPlayer->castlesOwned[i] == a2 )
      v4 = i;
  }
  if ( SHIBYTE(curPlayer->field_45) <= v4 )
  {
    if ( HIBYTE(curPlayer->field_45) + 3 < v4 )
      HIBYTE(curPlayer->field_45) = v4 - 3;
  }
  else
  {
    HIBYTE(curPlayer->field_45) = v4;
  }
  AdvManager::heroSelectionGUIStuff(this, 1, 1);
  sub_44D170(this, 1, 1);
  sub_455030(this, 0, 0, 1);
  sub_44D440(this, 1, 1, 1);
  sub_44AA80((int)this, 1, 0);
  sub_447C20(this, this->viewX, this->viewY, 0, 1);
  sub_447A00(this, 0, 0);
  sub_452F60(this, this->viewX + 7, this->viewY + 7, 1);
  v5 = (unsigned __int8)tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(
                                                      this,
                                                      (unsigned __int8)v7[4],
                                                      (unsigned __int8)v7[5])];
  if ( this->field_A6 != v5 )
  {
    this->field_A6 = v5;
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[this->field_A6]);
  }
  sub_4D1570();
  result = this;
  *(_DWORD *)&this->_2[8] = 0;
  return result;
}
