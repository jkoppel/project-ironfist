signed int __stdcall sub_4B6790(int a1, int a2)
{
  signed int result; // eax@2
  signed int v3; // [sp+18h] [bp-8h]@3
  int v4; // [sp+1Ch] [bp-4h]@1

  v4 = Hero::numStacksOfCreatureType(dword_51D5BC, a1);
  if ( v4 )
  {
    v3 = (signed __int64)((double)(v4 * (creature_table[a2].fight_value - creature_table[a1].fight_value))
                        * *(float *)&curPlayer->_4[100]);
    if ( Hero::numStacksOfCreatureType(dword_51D5BC, a2) )
      v3 = (signed __int64)((double)v3 * 1.2);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
