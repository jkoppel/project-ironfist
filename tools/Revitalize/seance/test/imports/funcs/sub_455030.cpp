{
  char *v4; // eax@9
  void *thisa; // [sp+Ch] [bp-8h]@1

  thisa = this;
  if ( *(&byte_524758 + curPlayerIdx) || debugLogLevel && dword_51D598 )
  {
    if ( a4 )
      HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 2, 16392);
    if ( a3 && curPlayer->_1[0] != -1 )
    {
      v4 = (char *)gameObject + 250 * curPlayer->_1[0];
      *(_DWORD *)(v4 + 10213) = -1;
      *(_DWORD *)(v4 + 10217) = -1;
    }
    if ( *(_DWORD *)((char *)thisa + 162) )
    {
      *(_DWORD *)((char *)thisa + 162) = 0;
      if ( a2 )
      {
        sub_448110((AdvManager *)thisa, 0);
        sub_447A00(thisa, 0, 0);
      }
    }
  }
}
