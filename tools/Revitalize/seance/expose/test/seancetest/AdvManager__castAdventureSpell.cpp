void __thiscall AdvManager::castAdventureSpell(AdvManager *this)
{
  int v1; // eax@2
  int v2; // edx@2

  if ( curPlayer->_1[0] != -1 )
  {
    sub_450820(this, 0);
    sub_448110(this, 0);
    sub_447A00(this, 0, 0);
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
    v1 = GameInfo::open_spellbook(
           gameObject,
           &gameObject->heroes[curPlayer->_1[0]],
           SPELL_CATEGORY_ADVENTURE,
           (int)constantlyTrue,
           0);
    AdvManager::effectAdventureSpell(this, v2, v1);
  }
}
