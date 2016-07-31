{
  signed __int16 v3; // ax@10
  signed int v5; // [sp+118h] [bp-10h]@1
  unsigned int v6; // [sp+124h] [bp-4h]@5

  v5 = 1;
  if ( a2 == 127 && !dword_512598 && !dword_51259C )
    a2 = 1 - dword_523F14;
  v6 = sub_46DD20((const void *)a1, dword_523F14, a2, a3);
  switch ( byte_51257C )
  {
    case 1:
    case 2:
      if ( dword_512598 )
      {
        sub_404D50(a2, v6, &byte_527218);
      }
      else
      {
        if ( dword_51259C )
        {
          sub_45F7F0(a2, v6, &byte_527218);
        }
        else
        {
          v3 = sub_473040(a2, v6, &byte_527218);
          if ( v3 )
          {
            logUpTo7Ints((int)"Bad return on Send Data", a2, v3, v6, 0, 0, -999, -999);
            v5 = 0;
          }
        }
      }
      break;
    case 3:
    case 4:
      sub_464AB0((int)&byte_527218, v6);
      v5 = 1;
      break;
    default:
      return v5;
  }
  return v5;
}
