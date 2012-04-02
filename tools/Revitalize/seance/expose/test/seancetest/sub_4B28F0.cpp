double __stdcall sub_4B28F0(int a1)
{
  double result; // st7@4
  int v2; // eax@7
  signed int v3; // [sp+24h] [bp-Ch]@1
  char *v4; // [sp+2Ch] [bp-4h]@1

  v4 = &gameObject->players[a1]._4[8];
  v3 = dword_4F2050[gameObject->_10[26]];
  if ( gameObject->winConditionType == 3 )
    v3 *= 2;
  if ( gameObject->_10[26] == -1 )
  {
    result = 0.0;
  }
  else
  {
    *(_DWORD *)&gameObject->players[a1]._4[88] = 48 * (v3 / 110) / gameObject->field_B52;
    if ( curPlayer->personality == 2 )
      *((_DWORD *)v4 + 20) = (signed __int64)((double)*((signed int *)v4 + 20) * 1.4);
    v2 = sub_419500(gameObject, curPlayerIdx, 1);
    *((_DWORD *)v4 + 20) = (signed __int64)((1.5 - (double)abs(48 - v2) / 48.0) * (double)*((signed int *)v4 + 20));
    *((_DWORD *)v4 + 20) = (signed __int64)((*((float *)v4 + 5) + 0.66) * (double)*((signed int *)v4 + 20));
    result = (double)*((signed int *)v4 + 20);
  }
  return result;
}
