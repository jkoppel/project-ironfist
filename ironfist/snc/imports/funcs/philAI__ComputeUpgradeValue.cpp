{
  signed int result; // eax@2
  signed int v3; // [sp+18h] [bp-8h]@3
  int v4; // [sp+1Ch] [bp-4h]@1

  v4 = hero::CreatureTypeCount(gpCurAIHero, a1);
  if ( v4 )
  {
    v3 = (signed __int64)((double)(v4 * (gMonsterDatabase[a2].fight_value - gMonsterDatabase[a1].fight_value))
                        * *(float *)&gpCurPlayer->_4[100]);
    if ( hero::CreatureTypeCount(gpCurAIHero, a2) )
      v3 = (signed __int64)((double)v3 * 1.2);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}