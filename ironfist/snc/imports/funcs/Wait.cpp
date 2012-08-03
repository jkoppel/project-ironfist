{
  GUIModemResponse("Waiting for ring...", "RING");
  GUIModemCommand("Initializing modem...", "ATA");
  return GUIModemResponse("Establishing connection...", "CONNECT") != 0;
}