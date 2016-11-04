{
  void *v5; // [sp+Ch] [bp-Ch]@1
  int hex; // [sp+10h] [bp-8h]@8
  int hexa; // [sp+10h] [bp-8h]@12
  signed int v8; // [sp+14h] [bp-4h]@4

  v5 = this;
  while ( a4 )
  {
    if ( *(_DWORD *)(a2 + 118) == 59 )
      v8 = sub_46C870(v5, a3, a4);
    else
      v8 = sub_46C670(v5, a3, a4);
    if ( v8 == -1 )
      return 0;
    *(_DWORD *)(a2 + 82) = a3;
    *(_DWORD *)(a2 + 86) = v8;
    hex = *(_DWORD *)((char *)v5 + 24234 * a3 + 1154 * v8 + 13769);
    *(_DWORD *)(a2 + 98) = hex;
    if ( sub_405F00((CreatureStack *)a2, hex, 0) )
    {
      couldBeCreatureActionType = 2;
      notTargetForAISpell = hex;
      return 1;
    }
    if ( *((_BYTE *)v5 + 24234 * a3 + 1154 * v8 + 13855) & 1 )
    {
      hexa = *(_DWORD *)((char *)v5 + 24234 * a3 + 1154 * v8 + 13781) ? hex + 1 : hex - 1;
      *(_DWORD *)(a2 + 98) = hexa;
      if ( sub_405F00((CreatureStack *)a2, hexa, 0) )
      {
        couldBeCreatureActionType = 2;
        notTargetForAISpell = hexa;
        return 1;
      }
    }
    a4 &= ~(1 << v8);
  }
  return 0;
}
