{
  int result; // eax@1
  void *v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  result = *(&byte_524758 + curPlayerIdx);
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    result = curPlayer->_1[0];
    if ( result != -1 )
    {
      result = sub_419790(gameObject, curPlayer->_1[0]);
      if ( !result )
      {
        sub_454B50(v2, 1, 0, 0);
        AdvManager::heroSelectionGUIStuff((AdvManager *)v2, 1, 1);
        result = sub_4551D0();
      }
    }
  }
  return result;
}
