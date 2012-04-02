void __thiscall sub_4C3D60(CombatManager *this)
{
  if ( !combatGraphicsOff )
  {
    if ( this->checkedInsub4c3d60 )
    {
      fullScreenRelated = 0;
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 640u, 443);
      fullScreenRelated = 1;
    }
  }
}
