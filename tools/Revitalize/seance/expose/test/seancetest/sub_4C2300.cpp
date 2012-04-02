int __thiscall sub_4C2300(int this, int a2, int a3)
{
  int v3; // ST1C_4@3
  int v4; // ST18_4@3
  int v5; // ST14_4@4
  int v6; // ST10_4@4
  int result; // eax@5
  int v8; // [sp+28h] [bp-8h]@1
  int v9; // [sp+2Ch] [bp-4h]@1
  int v10; // [sp+38h] [bp+8h]@1
  int v11; // [sp+3Ch] [bp+Ch]@1

  v9 = *(_DWORD *)(this + 470);
  v8 = *(_DWORD *)(this + 474);
  *(_DWORD *)(this + 470) += a2;
  *(_DWORD *)(this + 474) += a3;
  v10 = v9 - *(_DWORD *)(this + 470);
  v11 = v8 - *(_DWORD *)(this + 474);
  if ( v9 != *(_DWORD *)(this + 470) || v8 != *(_DWORD *)(this + 474) )
  {
    v3 = **(_DWORD **)(this + 174)
       + 12 * (v9 + *(_DWORD *)(this + 658))
       + 12 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) * (v8 + *(_DWORD *)(this + 666));
    *(_BYTE *)(v3 + 8) &= 0xBFu;
    *(_DWORD *)(this + 658) += v10;
    *(_DWORD *)(this + 666) += v11;
    v4 = **(_DWORD **)(this + 174)
       + 12 * (*(_DWORD *)(this + 474) + *(_DWORD *)(this + 666)) * *(_DWORD *)(*(_DWORD *)(this + 174) + 8)
       + 12 * (*(_DWORD *)(this + 470) + *(_DWORD *)(this + 658));
    *(_BYTE *)(v4 + 8) |= 0x40u;
    if ( *(_DWORD *)(this + 662) != -1 )
    {
      v5 = **(_DWORD **)(this + 174)
         + 12 * (v9 + *(_DWORD *)(this + 662))
         + 12 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) * (v8 + *(_DWORD *)(this + 670));
      *(_BYTE *)(v5 + 8) &= 0xBFu;
      *(_DWORD *)(this + 662) += v10;
      *(_DWORD *)(this + 670) += v11;
      v6 = **(_DWORD **)(this + 174)
         + 12 * (*(_DWORD *)(this + 474) + *(_DWORD *)(this + 670)) * *(_DWORD *)(*(_DWORD *)(this + 174) + 8)
         + 12 * (*(_DWORD *)(this + 470) + *(_DWORD *)(this + 662));
      *(_BYTE *)(v6 + 8) |= 0x40u;
    }
  }
  result = this;
  *(_DWORD *)(this + 686) = 1;
  return result;
}
