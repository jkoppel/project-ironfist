void __thiscall sub_4AADD0(void *this)
{
  void *v1; // [sp+10h] [bp-20h]@1
  int v2; // [sp+14h] [bp-1Ch]@33
  int v3; // [sp+18h] [bp-18h]@33
  int v4; // [sp+1Ch] [bp-14h]@36
  int v5; // [sp+20h] [bp-10h]@38
  Castle *v6; // [sp+24h] [bp-Ch]@5
  int v7; // [sp+28h] [bp-8h]@1
  int v8; // [sp+2Ch] [bp-4h]@1

  v1 = this;
  v7 = 0;
  v8 = 0;
  GameInfo::fixSeveralInvariants(gameObject);
  if ( curPlayer->resources[6] >= 200 && (curPlayer->resources[6] >= 2500 || curPlayer->numHeroes) )
  {
    logUpTo7Ints((int)"CheckBuy Start", curPlayer->resources[6], -999, -999, -999, -999, -999, -999);
    v6 = 0;
    if ( byte_532CD8[curPlayerIdx] < 0 )
    {
      if ( byte_5306C8[curPlayerIdx] >= 0 )
        v6 = &gameObject->castles[byte_5306C8[curPlayerIdx]];
    }
    else
    {
      v6 = &gameObject->castles[byte_532CD8[curPlayerIdx]];
    }
    if ( byte_532CD8[curPlayerIdx] < 0 )
    {
      if ( byte_5306C8[curPlayerIdx] >= 0 )
        v6 = &gameObject->castles[byte_5306C8[curPlayerIdx]];
    }
    else
    {
      v6 = &gameObject->castles[byte_532CD8[curPlayerIdx]];
    }
    if ( v6 && v6->ownerIdx != curPlayerIdx )
    {
      byte_532CD8[curPlayerIdx] = -1;
      byte_5306C8[curPlayerIdx] = byte_532CD8[curPlayerIdx];
      v6 = 0;
    }
    if ( byte_532CD8[curPlayerIdx] >= 0 )
    {
      if ( sub_432680((int)v6, 3) && sub_4323C0((unsigned int *)v6, 3) )
      {
        sub_4B5390((signed int)v6, 3);
        byte_532CD8[curPlayerIdx] = -1;
      }
      else
      {
        curPlayer->resources[6] -= 2000;
        curPlayer->resources[0] -= 20;
      }
    }
    if ( byte_5306C8[curPlayerIdx] >= 0 )
    {
      if ( v6->buildingsBuiltFlags & 8 && curPlayer->resources[6] >= 1000 && curPlayer->resources[0] >= 10 )
      {
        if ( sub_42C880(gameObject) < 48
          && !*(_BYTE *)(usedToCheckForBoatByCastle(advManager, LOBYTE(v6->field_6), HIBYTE(v6->field_6)) + 9)
          && sub_419870(gameObject, LOBYTE(v6->field_6), HIBYTE(v6->field_6), 0) != -1 )
        {
          curPlayer->resources[6] -= 1000;
          curPlayer->resources[0] -= 10;
        }
        byte_5306C8[curPlayerIdx] = -1;
      }
      else
      {
        curPlayer->resources[6] -= 1000;
        curPlayer->resources[0] -= 10;
      }
    }
    sub_4AAA50();
    sub_4AA9A0();
    while ( !v7 )
    {
      sub_4ADEA0(v1, curPlayerIdx, (int)&v2);
      if ( v3 >= 0 && sub_4B5A60((int)&v2) )
      {
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            sub_4B5470(v2, v4);
          }
          else
          {
            if ( v3 == 2 )
              sub_4B57A0(v2, v4, v5);
          }
        }
        else
        {
          sub_4B5390(v2, v4);
        }
        v8 = 1;
      }
      else
      {
        v7 = 1;
      }
    }
    if ( byte_532CD8[curPlayerIdx] >= 0 )
    {
      curPlayer->resources[6] += 2000;
      curPlayer->resources[0] += 20;
    }
    if ( byte_5306C8[curPlayerIdx] >= 0 )
    {
      curPlayer->resources[6] += 1000;
      curPlayer->resources[0] += 10;
    }
    sub_4AA9A0();
    logUpTo7Ints((int)"CheckBuy End  ", curPlayer->resources[6], -999, -999, -999, -999, -999, -999);
  }
}
