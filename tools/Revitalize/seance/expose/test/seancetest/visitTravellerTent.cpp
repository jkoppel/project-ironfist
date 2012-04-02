char __stdcall visitTravellerTent(MapTile *tile, Hero *hero)
{
  int v2; // ST30_4@1
  char result; // al@1
  int res[2]; // [sp+14h] [bp-Ch]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  *(_QWORD *)res = stru_5230F8;
  v2 = ((unsigned __int8)(tile->flags >> 8) >> -5) & 7;
  v5 = (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5);
  v5 >>= 3;
  playTrackForLocationVisit(tile->objType & 0x7F, v2, (_QWORD *)res);
  sprintf(
    globBuf,
    "You enter the tent and see an old woman gazing into a magic gem.  She looks up and says, \"In my travels, I have learned much in the way of arcane magic.  A great oracle taught me his skill.  I have the answer you seek.  The %s keyword is '%s'.\"",
    gateColors[v2],
    gatePasswords[v5]);
  display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
  result = (1 << v2) | curPlayer->_4[1];
  curPlayer->_4[1] = result;
  return result;
}
