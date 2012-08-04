{
  int result; // eax@6
  signed int i; // [sp+14h] [bp-10h]@8
  int v8; // [sp+18h] [bp-Ch]@7
  signed int v9; // [sp+1Ch] [bp-8h]@1

  *(_DWORD *)a4 = 0;
  *(_DWORD *)a5 = 0;
  *(_DWORD *)a6 = -1;
  v9 = 999999;
  if ( a3 )
    *(_DWORD *)a4 = a2;
  else
    *(_DWORD *)a4 = philAI::MaxBuyableCreatures(a1);
  if ( *(_DWORD *)a4 > a2 )
    *(_DWORD *)a4 = a2;
  result = a4;
  if ( *(_DWORD *)a4 )
  {
    v8 = *(_DWORD *)a4 * gMonsterDatabase[a1].fight_value;
    if ( !armyGroup::CanJoin(&gpCurAIHero->army, a1) )
    {
      for ( i = 0; i < 5; ++i )
      {
        if ( gpCurAIHero->army.creatureTypes[i] == a1 )
        {
          *(_DWORD *)a6 = -1;
          i = 5;
        }
        else if ( gMonsterDatabase[i].fight_value * gpCurAIHero->army.quantities[i] < v9 )
        {
          v9 = gMonsterDatabase[i].fight_value * gpCurAIHero->army.quantities[i];
          *(_DWORD *)a6 = i;
        }
      }
    }
    if ( *(_DWORD *)a6 != -1 )
      v8 -= v9;
    *(_DWORD *)a5 = (signed __int64)((double)v8 * *(float *)&gpGame->players[gpCurAIHero->probablyOwnerIdx]._4[100]);
    if ( !a3 )
    {
      getCreatureCosts(a1, &costTemp);
      *(_DWORD *)a5 -= *(_DWORD *)a4 * (unsigned __int64)philAI::RVConversion((int)&costTemp);
    }
    result = a5;
    if ( *(_DWORD *)a5 < 0 )
    {
      *(_DWORD *)a5 = 0;
      result = a4;
      *(_DWORD *)a4 = 0;
    }
  }
  return result;
}