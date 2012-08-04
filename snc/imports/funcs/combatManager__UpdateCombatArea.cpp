{
  if ( !gbNoShowCombat )
  {
    if ( this->checkedInsub4c3d60 )
    {
      gbEnlargeScreenBlit = 0;
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 640u, 443);
      gbEnlargeScreenBlit = 1;
    }
  }
}