{
  mapCell *tile; // [sp+10h] [bp-8h]@3
  hero *hro; // [sp+14h] [bp-4h]@3

  if ( gpCurPlayer->curHeroIdx != -1 && thisa->field_2A6 )
  {
    thisa->field_2A6 = 0;
    hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
    advManager::StopCursor(thisa, 1);
    tile = advManager::GetCell(thisa, hro->x, hro->y);
    hro->occupiedObjType = tile->objType;
    hro->occupiedObjVal = (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5);
    HIBYTE(hro->field_2B) = LOBYTE(thisa->field_27E);
    if ( thisa->field_27A == 6 )
      *(_DWORD *)&hro->flags1 |= 0x80u;
    tile->objType = 170;
    tile->flags = tile->flags & 7 | 8 * hro->couldBeHeroIdx;
    tile->field_8 &= 0xBFu;
    thisa->field_272 = 0;
    advManager::CompleteDraw(thisa, thisa->viewX, thisa->viewY, 0, 1);
    advManager::UpdateScreen(thisa, 0, 0);
  }
}