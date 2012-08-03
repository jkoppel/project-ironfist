{
  int v3; // [sp+10h] [bp-1Ch]@7
  char v4; // [sp+1Ch] [bp-10h]@5
  char v5; // [sp+20h] [bp-Ch]@5
  void *this; // [sp+24h] [bp-8h]@1
  int v7; // [sp+28h] [bp-4h]@5

  this = &gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5)];
  advManager::DemobilizeCurrHero(gpAdvManager);
  if ( *((_BYTE *)this + 1) != giCurPlayer )
  {
    if ( town::HasGarrison((town *)this) )
    {
      if ( (signed int)*((_BYTE *)this + 1) >= 0 && gbHumanPlayer[*((_BYTE *)this + 1)] )
      {
        if ( *((_BYTE *)this + 23) == -1 )
          v3 = 0;
        else
          v3 = (int)&gpGame->heroes[*((_BYTE *)this + 23)];
        if ( !advManager::DoCombat(
                gpAdvManager,
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
          game::ClaimTown(gpGame, *(_BYTE *)this, giCurPlayer, 0);
          dword_5305C4 = *(_BYTE *)this;
        }
      }
      else
      {
        v7 = philAI::QuickCombat(
               a2 + 101,
               a2,
               (unsigned int)((char *)this + 8),
               1,
               *(_BYTE *)this,
               (float *)&v5,
               (float *)&v4);
      }
    }
    else
    {
      game::ClaimTown(gpGame, *(_BYTE *)this, giCurPlayer, 0);
    }
  }
  if ( *((_BYTE *)this + 1) == giCurPlayer && *(_QWORD *)(a2 + 25) == a3 )
  {
    *((_BYTE *)this + 23) = gpCurPlayer->curHeroIdx;
    *(_WORD *)(a2 + 45) = 163;
    *(_WORD *)(a2 + 47) = *(_BYTE *)this;
    philAI::HeroInteractionAtTown(a2, (signed int)this, 0, (int)&unk_5305C8);
  }
  advManager::MobilizeCurrHero(gpAdvManager, 0);
  town::GiveSpells((town *)this, 0);
}