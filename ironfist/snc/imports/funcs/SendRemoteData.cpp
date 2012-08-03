{
  signed __int16 v3; // ax@10
  signed int v5; // [sp+118h] [bp-10h]@1
  unsigned int v6; // [sp+124h] [bp-4h]@5

  v5 = 1;
  if ( a2 == 127 && !bUseDirectPlay && !bUseWinsock )
    a2 = 1 - giThisNetPos;
  v6 = EncodePacket((const void *)a1, giThisNetPos, a2, a3);
  switch ( GameMode )
  {
    case 1:
    case 2:
      if ( bUseDirectPlay )
      {
        dpnet_snd(a2, v6, &PacketSend);
      }
      else if ( bUseWinsock )
      {
        wsnet_snd(a2, v6, &PacketSend);
      }
      else
      {
        v3 = nb_snd(a2, v6, &PacketSend);
        if ( v3 )
        {
          LogInt((int)"Bad return on Send Data", a2, v3, v6, 0, 0, -999, -999);
          v5 = 0;
        }
      }
      break;
    case 3:
    case 4:
      WriteModemPacket((int)&PacketSend, v6);
      v5 = 1;
      break;
    default:
      return v5;
  }
  return v5;
}