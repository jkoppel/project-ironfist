{
  signed int result; // eax@4
  void *v4; // [sp+10h] [bp-10h]@1
  signed int v5; // [sp+1Ch] [bp-4h]@1

  v4 = a2;
  v5 = 1;
  switch ( GameMode )
  {
    case 1:
    case 2:
      if ( bUseDirectPlay )
      {
        if ( dpnet_rcv(packet) )
        {
          v5 = DecodePacket(v4);
          goto LABEL_18;
        }
        result = 0;
      }
      else if ( bUseWinsock )
      {
        if ( wsnet_rcv(packet) )
        {
          v5 = DecodePacket(v4);
          goto LABEL_18;
        }
        result = 0;
      }
      else
      {
        if ( nb_rcv(0x10Au, packet) )
        {
          v5 = DecodePacket(v4);
          goto LABEL_18;
        }
        result = 0;
      }
      break;
    case 3:
    case 4:
      if ( ReadPacket() )
      {
        v5 = DecodePacket(v4);
        goto LABEL_18;
      }
      result = 0;
      break;
    default:
LABEL_18:
      result = v5;
      break;
  }
  return result;
}