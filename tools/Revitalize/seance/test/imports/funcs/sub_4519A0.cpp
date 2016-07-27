{
  int v1; // eax@2
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( curPlayer->_1[0] != -1 )
  {
    sub_450820(this, 0);
    sub_448110((AdvManager *)thisa, 0);
    sub_447A00((void *)thisa, 0, 0);
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
    v1 = GameInfo::open_spellbook(
           gameObject,
           &gameObject->heroes[curPlayer->_1[0]],
           SPELL_CATEGORY_ADVENTURE,
           (int)constantlyTrue,
           0);
    sub_4513B0(thisa, v1);
  }
}
