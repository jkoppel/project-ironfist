{
  signed int i; // [sp+10h] [bp-8h]@3

  if ( !soundDisabled && *(_DWORD *)(this + 58) )
  {
    AIL_end_sample((HSAMPLE)a2);
    for ( i = 0; i < 10; ++i )
      sleep(5);
  }
}
