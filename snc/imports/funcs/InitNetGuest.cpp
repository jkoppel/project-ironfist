{
  int v0; // eax@10
  char result; // al@22
  char v2; // [sp+10h] [bp-30h]@14
  char v3; // [sp+14h] [bp-2Ch]@10

  switch ( iInitNetGuestStatus )
  {
    case 0:
      if ( nb_init(5, 6) == 1 )
      {
        ShutDown("NETBIOS is not loaded.");
      }
      else
      {
        gbRemoteOn = 1;
        ++iInitNetGuestStatus;
      }
      goto LABEL_24;
    case 1:
      if ( nb_stat(6) & 2 )
        iInitNetGuestStatus += 3;
      else
        ++iInitNetGuestStatus;
      goto LABEL_24;
    case 2:
      v0 = Random(0, 99999);
      sprintf(&v3, "H2G%d", v0);
      if ( nb_sess(0, (int)&v3) )
        ++iNameRetryCount;
      else
        ++iInitNetGuestStatus;
      goto LABEL_24;
    case 3:
      v2 = nb_stat(6);
      if ( v2 & 2 )
      {
        ++iInitNetGuestStatus;
      }
      else if ( v2 & 0x80 )
      {
        ++iNameRetryCount;
        --iInitNetGuestStatus;
      }
      goto LABEL_24;
    case 4:
      if ( nb_sess(1, 0) )
      {
        sprintf(gText, "Network initialization failed");
        ShutDown(gText);
      }
      result = 1;
      break;
    default:
LABEL_24:
      result = 0;
      break;
  }
  return result;
}