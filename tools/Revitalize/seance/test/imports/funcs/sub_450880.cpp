{
  int v2; // [sp+10h] [bp-8h]@3
  char *v3; // [sp+14h] [bp-4h]@3

  if ( curPlayer->_1[0] != -1 && thisa->field_2A6 )
  {
    thisa->field_2A6 = 0;
    v3 = (char *)&gameObject->heroes[curPlayer->_1[0]];
    sub_4BFAC0(thisa, 1);
    v2 = usedToCheckForBoatByCastle(thisa, *(_DWORD *)(v3 + 25), *(_DWORD *)(v3 + 29));
    *(_WORD *)(v3 + 45) = *(_BYTE *)(v2 + 9);
    *(_WORD *)(v3 + 47) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v2 + 4) >> 8) >> -5);
    v3[44] = LOBYTE(thisa->field_27E);
    if ( thisa->field_27A == 6 )
      *(_DWORD *)(v3 + 227) |= 0x80u;
    *(_BYTE *)(v2 + 9) = -86;
    *(_WORD *)(v2 + 4) = *(_WORD *)(v2 + 4) & 7 | 8 * (unsigned __int8)v3[2];
    *(_BYTE *)(v2 + 8) &= 0xBFu;
    thisa->field_272 = 0;
    sub_447C20(thisa, thisa->viewX, thisa->viewY, 0, 1);
    sub_447A00(thisa, 0, 0);
  }
}
