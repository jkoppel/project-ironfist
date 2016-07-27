{
  int thisa; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+10h] [bp-10h]@5
  int v5; // [sp+14h] [bp-Ch]@5
  int v6; // [sp+14h] [bp-Ch]@18
  signed int i; // [sp+18h] [bp-8h]@5
  char *v8; // [sp+1Ch] [bp-4h]@2

  thisa = (int)this;
  if ( a2 != -1 )
  {
    sub_4507D0();
    sub_455030((void *)thisa, 0, 0, 1);
    sub_4507F0(thisa);
    *(_DWORD *)(thisa + 678) = 1;
    curPlayer->_1[0] = a2;
    v8 = (char *)&gameObject->heroes[curPlayer->_1[0]];
    *(_DWORD *)(thisa + 470) = gameObject->heroes[curPlayer->_1[0]].x - 7;
    *(_DWORD *)(thisa + 474) = *(_DWORD *)(v8 + 29) - 7;
    *(_DWORD *)(thisa + 666) = 7;
    *(_DWORD *)(thisa + 658) = *(_DWORD *)(thisa + 666);
    *(_DWORD *)(thisa + 670) = -1;
    *(_DWORD *)(thisa + 662) = *(_DWORD *)(thisa + 670);
    if ( v8[227] & 0x80 )
      *(_DWORD *)(thisa + 634) = 6;
    else
      *(_DWORD *)(thisa + 634) = (unsigned __int8)v8[23];
    *(_DWORD *)(thisa + 638) = (unsigned __int8)v8[44];
    *(_DWORD *)(thisa + 642) = sub_4C0550(*(_DWORD *)(thisa + 638));
    v4 = usedToCheckForBoatByCastle((AdvManager *)thisa, *(_DWORD *)(v8 + 25), *(_DWORD *)(v8 + 29));
    *(_BYTE *)(v4 + 8) |= 0x40u;
    sub_42CC90(*(_DWORD *)(v8 + 25), *(_DWORD *)(v8 + 29), *(_WORD *)(v8 + 45), *(_WORD *)(v8 + 47), 0, 4);
    v5 = 0;
    for ( i = 0; curPlayer->numHeroes > i; ++i )
    {
      if ( curPlayer->heroesOwned[i] == a2 )
        v5 = i;
    }
    if ( curPlayer->_1[1] <= v5 )
    {
      if ( curPlayer->_1[1] + 3 < v5 )
        curPlayer->_1[1] = v5 - 3;
    }
    else
    {
      curPlayer->_1[1] = v5;
    }
    AdvManager::heroSelectionGUIStuff((AdvManager *)thisa, 1, 1);
    sub_44D170((void *)thisa, 1, 1);
    if ( !a3 && (*(_DWORD *)(thisa + 50) == 1 || *(&byte_524758 + curPlayerIdx)) )
    {
      sub_4456D0(0, 0);
      sub_455240(thisa, *(_QWORD *)(v8 + 33));
      sub_454B50((void *)thisa, 0, 0, 1);
    }
    sub_44D440((void *)thisa, 1, 1, 1);
    *(_DWORD *)(thisa + 626) = 1;
    sub_44AA80(thisa, 1, 0);
    sub_447C20((AdvManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0, 1);
    sub_447A00((void *)thisa, 0, 0);
    sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
    v6 = (unsigned __int8)tileToTerrainType[*(_WORD *)v4];
    if ( *(_DWORD *)(thisa + 166) != v6 )
    {
      *(_DWORD *)(thisa + 166) = v6;
      SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(thisa + 166)]);
    }
    if ( !dword_4F3084 )
    {
      sub_4D1570();
      *(_DWORD *)(thisa + 486) = 0;
    }
  }
}
