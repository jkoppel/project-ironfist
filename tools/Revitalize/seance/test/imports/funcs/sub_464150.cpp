{
  signed int result; // eax@2

  sub_464350("Waiting for ring...", "RING");
  sub_4641B0("Initializing modem...", "ATA");
  if ( sub_464350("Establishing connection...", "CONNECT") )
    result = 1;
  else
    result = 0;
  return result;
}
