void __stdcall sub_4ABCA0(__int64 a1)
{
  sub_453A20(advManager, (int)dword_51D5BC, a1, 0, 0);
  if ( *(_DWORD *)&dword_51D5BC->_4[20] >= 225 )
    *(_DWORD *)&dword_51D5BC->_4[20] -= 225;
  else
    *(_DWORD *)&dword_51D5BC->_4[20] = 0;
  Hero::spendSpellPointsFor(dword_51D5BC, 56);
}
