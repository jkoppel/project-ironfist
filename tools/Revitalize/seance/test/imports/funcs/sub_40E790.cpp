{
  char result; // al@11
  int v1; // eax@12
  char v2; // al@16
  char v3; // [sp+14h] [bp-2Ch]@12
  int v4; // [sp+3Ch] [bp-4h]@7

  switch ( byte_4EE11C )
  {
    case 0:
      if ( sub_472B20(5, 0) == 1 )
      {
        terminate("NETBIOS is not loaded.");
      }
      else
      {
        ++byte_4EE11C;
        dword_4F7494 = 1;
      }
      goto LABEL_20;
    case 1:
      if ( sub_473600(0) & 2 )
        v4 = 0;
      else
        v4 = 1;
      if ( v4 )
      {
        ++byte_4EE11C;
LABEL_20:
        result = 0;
      }
      else
      {
        result = 1;
      }
      return result;
    case 2:
      v1 = unseededNextRand(0, 99999);
      sprintf(&v3, "H2H%d", v1);
      if ( sub_473130(0, (int)&v3) )
        terminate("Network initialization failed");
      else
        ++byte_4EE11C;
      goto LABEL_20;
    case 3:
      v2 = sub_473600(0);
      v4 = (unsigned __int8)v2;
      if ( !(v2 & 2) )
        goto LABEL_20;
      return 1;
    default:
      goto LABEL_20;
  }
}
