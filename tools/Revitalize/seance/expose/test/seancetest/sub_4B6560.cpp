void __stdcall sub_4B6560(int a1, int a2, __int64 a3)
{
  int v3; // [sp+10h] [bp-1Ch]@7
  char v4; // [sp+1Ch] [bp-10h]@5
  char v5; // [sp+20h] [bp-Ch]@5
  void *this; // [sp+24h] [bp-8h]@1
  int v7; // [sp+28h] [bp-4h]@5

  this = &gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5)];
  sub_450880(advManager);
  if ( *((_BYTE *)this + 1) != curPlayerIdx )
  {
    if ( Castle::hasGarrison((Castle *)this) )
    {
      if ( (signed int)*((_BYTE *)this + 1) >= 0 && dword_524810[*((_BYTE *)this + 1)] )
      {
        if ( *((_BYTE *)this + 23) == -1 )
          v3 = 0;
        else
          v3 = (int)&gameObject->heroes[*((_BYTE *)this + 23)];
        if ( !sub_4938B0(
                advManager,
                a3,
                a2,
                (const void *)(a2 + 101),
                (int)this,
                v3,
                (char *)this + 8,
                a3,
                SBYTE4(a3),
                -1,
                1) )
        {
          sub_420F30(gameObject, *(_BYTE *)this, curPlayerIdx, 0);
          dword_5305C4 = *(_BYTE *)this;
        }
      }
      else
      {
        v7 = sub_4B38C0(a2 + 101, a2, (unsigned int)((char *)this + 8), 1, *(_BYTE *)this, (float *)&v5, (float *)&v4);
      }
    }
    else
    {
      sub_420F30(gameObject, *(_BYTE *)this, curPlayerIdx, 0);
    }
  }
  if ( *((_BYTE *)this + 1) == curPlayerIdx && *(_QWORD *)(a2 + 25) == a3 )
  {
    *((_BYTE *)this + 23) = curPlayer->_1[0];
    *(_WORD *)(a2 + 45) = 163;
    *(_WORD *)(a2 + 47) = *(_BYTE *)this;
    sub_4B43E0(a2, (signed int)this, 0, (int)&unk_5305C8);
  }
  sub_450820((int)advManager, 0);
  Castle::grantHeroSpellsFromMageGuild((Castle *)this, 0);
}
