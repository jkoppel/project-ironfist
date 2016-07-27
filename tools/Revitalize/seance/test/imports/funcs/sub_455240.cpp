{
  char *v2; // eax@1

  LOBYTE(v2) = *(&byte_524758 + curPlayerIdx);
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    v2 = (char *)curPlayer->_1[0];
    if ( v2 != (char *)-1 )
    {
      v2 = (char *)&gameObject->heroes[curPlayer->_1[0]];
      if ( dword_5247C0 )
      {
        if ( !dword_524808 )
          LOBYTE(v2) = Pathfinder::doSomething2(
                         pathfinder,
                         gameObject->heroes[curPlayer->_1[0]].x,
                         gameObject->heroes[curPlayer->_1[0]].y,
                         *(_DWORD *)(this + 638),
                         59999,
                         *(_DWORD *)(this + 634) == 6,
                         0,
                         *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[20],
                         gameObject->heroes[curPlayer->_1[0]].secondarySkillLevel[0],
                         a2,
                         1,
                         1);
      }
      else
      {
        LOBYTE(v2) = Pathfinder::doSomething2(
                       pathfinder,
                       gameObject->heroes[curPlayer->_1[0]].x,
                       gameObject->heroes[curPlayer->_1[0]].y,
                       *(_DWORD *)(this + 638),
                       59999,
                       *(_DWORD *)(this + 634) == 6,
                       0,
                       *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[20],
                       gameObject->heroes[curPlayer->_1[0]].secondarySkillLevel[0],
                       a2,
                       0,
                       1);
      }
    }
  }
  return (char)v2;
}
