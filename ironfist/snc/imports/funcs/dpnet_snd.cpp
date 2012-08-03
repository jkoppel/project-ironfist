{
  unsigned __int16 v4; // [sp+Ch] [bp-Ch]@1
  int v5; // [sp+10h] [bp-8h]@1
  int v6; // [sp+14h] [bp-4h]@2

  v4 = a2;
  v5 = a1;
  dpProcessMessages();
  if ( v5 == 127 )
    v6 = 0;
  else
    v6 = *((_DWORD *)&giNetPosToDCOPos + v5);
  dpSendMessage(v6, 1, v4, a3);
  return 0;
}