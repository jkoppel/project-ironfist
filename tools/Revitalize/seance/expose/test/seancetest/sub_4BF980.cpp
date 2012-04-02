int __thiscall sub_4BF980(int this, signed int a2)
{
  int v2; // ST24_4@4
  int v3; // ST20_4@4
  int v4; // ST14_4@4
  int result; // eax@4
  int v6; // [sp+Ch] [bp-18h]@1

  v6 = this;
  *(_DWORD *)(this + 638) = a2;
  *(_DWORD *)(this + 642) = sub_4C0550(a2) + 1;
  if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) <= 0 )
    *(_DWORD *)(v6 + 650) = 2;
  else
    *(_DWORD *)(v6 + 650) = 1;
  v2 = byte_4F1DC0[4 * a2];
  v3 = byte_4F1DC1[4 * a2];
  *(_DWORD *)(v6 + 662) = *(_DWORD *)(v6 + 658);
  *(_DWORD *)(v6 + 670) = *(_DWORD *)(v6 + 666);
  *(_DWORD *)(v6 + 658) += v2;
  *(_DWORD *)(v6 + 666) += v3;
  v4 = **(_DWORD **)(v6 + 174)
     + 12 * (*(_DWORD *)(v6 + 474) + *(_DWORD *)(v6 + 666)) * *(_DWORD *)(*(_DWORD *)(v6 + 174) + 8)
     + 12 * (*(_DWORD *)(v6 + 470) + *(_DWORD *)(v6 + 658));
  result = **(_DWORD **)(v6 + 174)
         + 12 * (*(_DWORD *)(v6 + 474) + *(_DWORD *)(v6 + 666)) * *(_DWORD *)(*(_DWORD *)(v6 + 174) + 8)
         + 12 * (*(_DWORD *)(v6 + 470) + *(_DWORD *)(v6 + 658));
  *(_BYTE *)(v4 + 8) |= 0x40u;
  return result;
}
