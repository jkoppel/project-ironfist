{
  char result; // al@8
  int v1; // eax@9
  char v2; // al@13
  char v3; // [sp+14h] [bp-2Ch]@9
  int v4; // [sp+3Ch] [bp-4h]@13

  switch ( iInitNetHostStatus )
  {
    case 0:
      if ( nb_init(5, 0) == 1 )
      {
        ShutDown("NETBIOS is not loaded.");
      }
      else
      {
        ++iInitNetHostStatus;
        gbRemoteOn = 1;
      }
      goto LABEL_17;
    case 1:
      if ( nb_stat(0) & 2 )
      {
        result = 1;
      }
      else
      {
        ++iInitNetHostStatus;
LABEL_17:
        result = 0;
      }
      return result;
    case 2:
      v1 = Random(0, 99999);
      sprintf(&v3, "H2H%d", v1);
      if ( nb_sess(0, (int)&v3) )
        ShutDown("Network initialization failed");
      else
        ++iInitNetHostStatus;
      goto LABEL_17;
    case 3:
      v2 = nb_stat(0);
      v4 = (unsigned __int8)v2;
      if ( !(v2 & 2) )
        goto LABEL_17;
      return 1;
    default:
      goto LABEL_17;
  }
}