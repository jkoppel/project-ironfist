{
  signed int v2; // ST14_4@4
  signed int v3; // [sp+Ch] [bp-230h]@1
  int v4; // [sp+10h] [bp-22Ch]@1
  char v5[516]; // [sp+18h] [bp-224h]@3
  int v6; // [sp+21Ch] [bp-20h]@1

  v3 = a2;
  v4 = a1;
  v6 = 0;
  if ( a2 <= 256 )
  {
    v5[v6++] = 112;
    for ( v5[v6++] = 0; ; v5[v6++] = *(_BYTE *)v4++ )
    {
      v2 = v3--;
      if ( !v2 )
        break;
      if ( *(_BYTE *)v4 == 112 )
        v5[v6++] = 112;
    }
    v5[v6++] = 112;
    v5[v6++] = 1;
    while ( !sub_4644D0(v5, v6) )
      sub_42EF00();
  }
  else
  {
    debugLog("TOO LONG");
  }
}
