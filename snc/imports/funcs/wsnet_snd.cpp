{
  unsigned __int16 v4; // [sp+Ch] [bp-Ch]@1
  int v5; // [sp+10h] [bp-8h]@1

  v4 = a2;
  v5 = a1;
  wsProcessMessages();
  if ( v5 == 127 )
    wsSendMessage(0, 1, v4, a3);
  else
    wsSendMessage(*((_DWORD *)&giNetPosToDCOPos + v5), 1, v4, a3);
  return 0;
}