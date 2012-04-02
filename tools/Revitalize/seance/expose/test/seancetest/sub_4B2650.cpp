int __stdcall sub_4B2650(int a1)
{
  signed int i; // [sp+14h] [bp-8h]@1
  signed int v3; // [sp+18h] [bp-4h]@1
  int v4; // [sp+18h] [bp-4h]@6

  v3 = 0;
  for ( i = 0; i <= 24; ++i )
  {
    if ( (1 << i) & *(_DWORD *)(a1 + 24) )
      v3 += sub_432720(*(_BYTE *)(a1 + 3), i, *(_BYTE *)(a1 + 28));
  }
  v4 = (unsigned __int64)(signed __int64)(flt_530730 * 1250.0 * 1.5 + (double)v3) + 750;
  if ( gameObject->_2[0] == 1
    && *(_BYTE *)(a1 + 4) == *(_WORD *)&gameObject->_2[1]
    && *(_WORD *)&gameObject->_3[1] == *(_BYTE *)(a1 + 5) )
    v4 += 50000;
  if ( gameObject->winConditionType == 1
    && gameObject->winConditionArgument == *(_BYTE *)(a1 + 4)
    && *(_WORD *)&gameObject->field_2D5 == *(_BYTE *)(a1 + 5) )
    v4 += 50000;
  return v4;
}
