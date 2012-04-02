void __thiscall Castle::visit(Castle *this, int a2)
{
  Castle *thisa; // [sp+Ch] [bp-8h]@1

  thisa = this;
  dword_51256C = 1;
  if ( dword_4F74AC + 1300 <= 2900 )
  {
    if ( dword_4F74AC + 1300 > 800 )
      dword_4F7490 = 1;
  }
  else
  {
    dword_4F7490 = 2;
  }
  townManager->castle = this;
  if ( !a2 )
    sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  ManagerManager::switchToManager(managerManager, (AbstractManager *)townManager);
  if ( thisa->visitingHeroIdx != -1 )
    sub_450C10(advManager, thisa->visitingHeroIdx, 0);
  dword_4F7490 = 0;
  dword_51256C = 0;
}
