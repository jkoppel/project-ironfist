{
  signed int i; // [sp+14h] [bp-8h]@1
  int v6; // [sp+18h] [bp-4h]@1

  v6 = 0;
  for ( i = 0; *(_BYTE *)(this + 68) > i; ++i )
  {
    if ( a3 < 19 || gameObject->castles[*(_BYTE *)(i + this + 71)].factionID == a2 )
    {
      if ( a3 )
      {
        if ( (1 << a3) & gameObject->castles[*(_BYTE *)(i + this + 71)].buildingsBuiltFlags )
          ++v6;
      }
      else
      {
        if ( gameObject->castles[*(_BYTE *)(i + this + 71)].buildingsBuiltFlags & 1 )
        {
          if ( gameObject->castles[*(_BYTE *)(i + this + 71)].mageGuildLevel == a4 )
            ++v6;
        }
      }
    }
  }
  return v6;
}
