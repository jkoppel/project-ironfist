{
  GameInfo *result; // eax@2
  GameInfo *thisa; // [sp+Ch] [bp-28h]@1
  int v3; // [sp+10h] [bp-24h]@14
  int img2Arg; // [sp+14h] [bp-20h]@12
  int img2Type; // [sp+18h] [bp-1Ch]@12
  int img1Type; // [sp+1Ch] [bp-18h]@12
  int img1Arg; // [sp+20h] [bp-14h]@12
  signed int j; // [sp+24h] [bp-10h]@12
  signed int i; // [sp+28h] [bp-Ch]@1
  int v10; // [sp+2Ch] [bp-8h]@1
  int v11; // [sp+30h] [bp-4h]@3

  thisa = this;
  v10 = this->day + 7 * (this->week - 1) + 28 * (this->month - 1);
  for ( i = 0; ; ++i )
  {
    result = thisa;
    if ( *(_WORD *)&thisa->_10[408] <= i )
      break;
    v11 = *((_DWORD *)dword_524784 + *(_WORD *)&thisa->_10[2 * i + 410]);
    if ( (dword_524810[curPlayerIdx] && *(_BYTE *)(v11 + 42) || !dword_524810[curPlayerIdx] && *(_BYTE *)(v11 + 31))
      && *(_BYTE *)(thisa->players[(char)curPlayerIdx].color + v11 + 43)
      && (*(_WORD *)(v11 + 33) == v10
       || *(_WORD *)(v11 + 35) && *(_WORD *)(v11 + 33) < v10 && !((v10 - *(_WORD *)(v11 + 33)) % *(_WORD *)(v11 + 35))) )
    {
      img1Type = -1;
      img1Arg = 0;
      img2Type = -1;
      img2Arg = 0;
      for ( j = 0; j < 7; ++j )
      {
        v3 = *(_DWORD *)(v11 + 4 * j + 1);
        if ( gameObject->players[curPlayerIdx].resources[j] < -v3 )
          v3 = -gameObject->players[curPlayerIdx].resources[j];
        gameObject->players[curPlayerIdx].resources[j] += *(_DWORD *)(v11 + 4 * j + 1);
        if ( gameObject->players[curPlayerIdx].resources[j] < 0 )
          gameObject->players[curPlayerIdx].resources[j] = 0;
        if ( v3 )
        {
          if ( img1Type != -1 )
          {
            img2Type = img1Type;
            img2Arg = img1Arg;
          }
          img1Type = j;
          img1Arg = v3;
        }
      }
      if ( img1Type >= 0 && img1Type <= 6 && img1Arg < 0 )
        img1Arg -= 100000;
      if ( img2Type >= 0 && img2Type <= 6 && img2Arg < 0 )
        img2Arg -= 100000;
      if ( *(&byte_524758 + curPlayerIdx) )
        display_message_window((char *)(v11 + 49), 1, -1, -1, img1Type, img1Arg, img2Type, img2Arg, -1, 0);
    }
  }
  return result;
}
