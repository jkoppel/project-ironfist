{
  char buf[516]; // [sp+14h] [bp-210h]@3
  int v9; // [sp+218h] [bp-Ch]@1

  v9 = 0;
  if ( eventID < 0 || eventID >= 95 )
  {
    if ( eventID == -1 )
      sprintf(buf, msg);
    else
      sprintf(buf, "Event ID %d", eventID);
  }
  else
  {
    sprintf(buf, adventureMapLocationMessages[eventID]);
  }
  display_message_window(buf, a2, -1, -1, a4, a5, resource2Type, resource2Amt, a8, 0);
}
