{
  void *thisa; // [sp+Ch] [bp-8h]@1
  int castleIdx; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( castleIdx = 0; castleIdx < 72; ++castleIdx )
  {
    GameInfo::randomlyFillGarrisonSlot((GameInfo *)thisa, castleIdx);
    if ( *((_BYTE *)thisa + 100 * castleIdx + 2923) & 0x40 )
    {
      if ( unseededNextRand(0, 100) < 80 )
        GameInfo::randomlyFillGarrisonSlot((GameInfo *)thisa, castleIdx);
    }
    else
    {
      if ( unseededNextRand(0, 100) < 40 )
        GameInfo::randomlyFillGarrisonSlot((GameInfo *)thisa, castleIdx);
    }
  }
}
