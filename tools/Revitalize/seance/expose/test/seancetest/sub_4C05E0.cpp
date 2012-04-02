void __thiscall sub_4C05E0(int this, int a2)
{
  int thisa; // [sp+10h] [bp-14h]@1
  signed int v3; // [sp+14h] [bp-10h]@7
  int v4; // [sp+18h] [bp-Ch]@1
  signed int v5; // [sp+1Ch] [bp-8h]@1
  int v6; // [sp+20h] [bp-4h]@7
  int v7; // [sp+20h] [bp-4h]@19

  thisa = this;
  v5 = 1;
  v4 = a2 - *(_DWORD *)(this + 638);
  if ( a2 != *(_DWORD *)(this + 638) )
  {
    if ( v4 < 0 && v4 >= -4 || v4 > 0 && v4 > 4 )
      v5 = -1;
    *(_DWORD *)(this + 654) = 1;
    v6 = 2 * *(_DWORD *)(this + 638);
    v3 = dword_51E1A0[*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx))];
    if ( !*((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) )
      v3 *= 3;
    if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) == 1 )
      v3 = (signed __int64)((double)v3 * 1.5);
    do
    {
      *(_DWORD *)(thisa + 650) = 1;
      if ( *(_DWORD *)(thisa + 634) < 6 )
        *(_DWORD *)(thisa + 642) = word_4F1D58[v6];
      else
        *(_DWORD *)(thisa + 642) = word_4F1D78[v6];
      *(_DWORD *)(thisa + 646) = 0;
      animTimer = getTickCount() + v3;
      if ( *((_DWORD *)&computerWalkSpeed + *(&byte_524758 + curPlayerIdx)) != 4 )
      {
        if ( sub_451D70((AdvManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0) )
          sub_447A00((void *)thisa, 0, 0);
        if ( dword_524C14 )
          sleepUntilPointer(&animTimer);
      }
      v7 = v5 + v6;
      if ( v7 < 0 )
        v7 = 15;
      v6 = (((unsigned __int64)v7 >> 32) ^ abs(v7) & 0xF) - ((unsigned __int64)v7 >> 32);
    }
    while ( 2 * a2 != v6 );
    *(_DWORD *)(thisa + 638) = a2;
    sub_4BFAC0((AdvManager *)thisa, 1);
    if ( dword_524C14 )
      sleepUntilPointer(&animTimer);
    if ( sub_451D70((AdvManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0) )
      sub_447A00((void *)thisa, 0, 0);
  }
}
