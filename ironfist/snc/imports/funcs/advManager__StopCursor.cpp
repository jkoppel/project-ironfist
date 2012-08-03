{
  mapCell *v2; // ST14_4@4

  if ( a2 )
  {
    bMoveSoundMade = 1;
    this->field_282 = advManager::GetCursorBaseFrame(this->field_27E);
    this->field_286 = 0;
    EveryOther = 0;
    hOldWalkSample = 0;
    hNewWalkSample = 0;
  }
  this->field_28A = 0;
  if ( *(_DWORD *)&this->field_292[4] != -1 )
  {
    v2 = &this->map->tiles[this->viewX + *(_DWORD *)&this->field_292[4]]
       + this->map->width * (this->viewY + *(_DWORD *)&this->field_292[12]);
    v2->field_8 &= 0xBFu;
    *(_DWORD *)&this->field_292[12] = -1;
    *(_DWORD *)&this->field_292[4] = *(_DWORD *)&this->field_292[12];
  }
  this->field_28E = 0;
}