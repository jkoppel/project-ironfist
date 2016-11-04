{
  int result; // eax@2
  __int16 v4; // ax@7
  int v5; // ST1C_4@7
  int thisa; // [sp+Ch] [bp-14h]@1
  int v7; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@3

  thisa = this;
  if ( *(_WORD *)(*(_DWORD *)this + 12 * a3 * *(_DWORD *)(this + 8) + 12 * a2 + 10) )
  {
    v7 = *(_WORD *)(*(_DWORD *)this + 12 * a3 * *(_DWORD *)(this + 8) + 12 * a2 + 10);
    for ( i = *(_DWORD *)(this + 4) + 7 * *(_WORD *)(*(_DWORD *)this + 12 * a3 * *(_DWORD *)(this + 8) + 12 * a2 + 10);
          ;
          i = *(_DWORD *)(this + 4) + 7 * *(_WORD *)i )
    {
      if ( *(_BYTE *)(i + 3) == 255 )
        return i;
      if ( !*(_WORD *)i )
        break;
      v7 = *(_WORD *)i;
    }
    v4 = sub_46F8D0((MapTiles *)this);
    v5 = *(_DWORD *)(thisa + 4) - v7 + 8 * v7;
    *(_WORD *)v5 = v4;
    result = *(_DWORD *)(thisa + 4) + 7 * *(_WORD *)v5;
  }
  else
  {
    *(_WORD *)(*(_DWORD *)this + 12 * a3 * *(_DWORD *)(this + 8) + 12 * a2 + 10) = sub_46F8D0((MapTiles *)this);
    result = *(_DWORD *)(thisa + 4) + 7 * *(_WORD *)(*(_DWORD *)thisa + 12 * a3 * *(_DWORD *)(thisa + 8) + 12 * a2 + 10);
  }
  return result;
}
