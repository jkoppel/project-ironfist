{
  int v0; // eax@10
  char result; // al@25
  char v2; // [sp+10h] [bp-30h]@14
  char v3; // [sp+14h] [bp-2Ch]@10
  int v4; // [sp+3Ch] [bp-4h]@15

  switch ( byte_4EE120 )
  {
    case 0:
      if ( sub_472B20(5, 6) == 1 )
      {
        terminate("NETBIOS is not loaded.");
      }
      else
      {
        dword_4F7494 = 1;
        ++byte_4EE120;
      }
      goto LABEL_27;
    case 1:
      if ( sub_473600(6) & 2 )
        byte_4EE120 += 3;
      else
        ++byte_4EE120;
      goto LABEL_27;
    case 2:
      v0 = unseededNextRand(0, 99999);
      sprintf(&v3, "H2G%d", v0);
      if ( sub_473130(0, (int)&v3) )
        ++dword_4EE124;
      else
        ++byte_4EE120;
      goto LABEL_27;
    case 3:
      v2 = sub_473600(6);
      if ( v2 & 2 )
        v4 = 0;
      else
        v4 = 1;
      if ( v4 )
      {
        if ( v2 & 0x80 )
        {
          ++dword_4EE124;
          --byte_4EE120;
        }
      }
      else
      {
        ++byte_4EE120;
      }
      goto LABEL_27;
    case 4:
      if ( sub_473130(1, 0) )
      {
        sprintf(globBuf, "Network initialization failed");
        terminate(globBuf);
      }
      result = 1;
      break;
    default:
LABEL_27:
      result = 0;
      break;
  }
  return result;
}
