{
  signed int result; // eax@3
  char v3; // [sp+10h] [bp-20h]@1
  int a2; // [sp+20h] [bp-10h]@1
  int res[2]; // [sp+24h] [bp-Ch]@1
  int v6; // [sp+2Ch] [bp-4h]@1

  *(_QWORD *)res = NULL_SAMPLE2;
  a2 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v6 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  sprintf(
    gText,
    "A magical %s barrier stands tall before you, blocking your way.  Runes on the arch read, \"Speak the key and you may pass.\"",
    xBarrierColor[a2]);
  GetDataEntry(gText, (int)&v3, 14, 0, 0, 1);
  if ( StrEqNoCase((int *)&v3, (int *)xPasswordStrings[v6]) && gpCurPlayer->_4[1] & (1 << a2) )
  {
    playTrackForLocationVisit(*(_BYTE *)(a1 + 9) & 0x7F, a2, (_QWORD *)res);
    NormalDialog(
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
    NormalDialog("You speak, and nothing happens.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    result = 0;
  }
  return result;
}