{
  int thisa; // [sp+Ch] [bp-14h]@1
  int thisb; // [sp+10h] [bp-10h]@1
  Hero *v5; // [sp+14h] [bp-Ch]@5
  Castle *castle; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  castle = &gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)];
  thisb = (int)&gameObject->heroes[curPlayer->_1[0]];
  sub_450880((AdvManager *)this);
  if ( castle->ownerIdx == curPlayerIdx )
  {
    castle->visitingHeroIdx = curPlayer->_1[0];
    Castle::visit(castle, 0);
  }
  else
  {
    if ( Castle::hasGarrison(castle) )
    {
      if ( castle->visitingHeroIdx == -1 )
        v5 = 0;
      else
        v5 = &gameObject->heroes[castle->visitingHeroIdx];
      if ( !sub_4938B0(
              (void *)thisa,
              a3,
              thisb,
              (const void *)(thisb + 101),
              (int)castle,
              (int)v5,
              &castle->garrison,
              a3,
              SBYTE4(a3),
              -1,
              1) )
        sub_420F30(gameObject, castle->idx, curPlayerIdx, 0);
    }
    else
    {
      sub_420F30(gameObject, castle->idx, curPlayerIdx, 0);
      if ( dword_4EF268 )
        return;
      sub_44AA80(thisa, 1, 0);
      AdvManager::heroSelectionGUIStuff((AdvManager *)thisa, 1, 1);
      sub_44D170((void *)thisa, 1, 1);
      castle->visitingHeroIdx = curPlayer->_1[0];
      Castle::visit(castle, 0);
    }
  }
  Castle::grantHeroSpellsFromMageGuild(castle, 0);
  Hero::checkForLevelUp((Hero *)thisb);
}
