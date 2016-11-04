{
  signed int result; // eax@3
  char v3; // [sp+10h] [bp-20h]@1
  int a2; // [sp+20h] [bp-10h]@1
  int res[2]; // [sp+24h] [bp-Ch]@1
  int v6; // [sp+2Ch] [bp-4h]@1

  *(_QWORD *)res = stru_5230F8;
  a2 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v6 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  sprintf(
    globBuf,
    "A magical %s barrier stands tall before you, blocking your way.  Runes on the arch read, \"Speak the key and you may pass.\"",
    gateColors[a2]);
  sub_4CAEF0(globBuf, (int)&v3, 14, 0, 0, 1);
  if ( sub_48C5F0((int *)&v3, (int *)gatePasswords[v6]) && curPlayer->_4[1] & (1 << a2) )
  {
    playTrackForLocationVisit(*(_BYTE *)(a1 + 9) & 0x7F, a2, (_QWORD *)res);
    display_message_window(
      "As you speak the magic word, the glowing barrier dissolves into nothingness.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    result = 1;
  }
  else
  {
    display_message_window("You speak, and nothing happens.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    result = 0;
  }
  return result;
}
