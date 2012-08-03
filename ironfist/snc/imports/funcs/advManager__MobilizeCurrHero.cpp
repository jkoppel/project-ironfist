{
  if ( gpCurPlayer->curHeroIdx != -1 )
  {
    if ( !this->field_2A6 )
      advManager::SetHeroContext(this, gpCurPlayer->curHeroIdx, a2);
  }
}