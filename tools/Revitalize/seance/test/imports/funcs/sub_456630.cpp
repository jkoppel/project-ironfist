{
  void *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  dword_524CFC = a2 + 2;
  dword_524CE0 = HIDWORD(a2) + 2;
  if ( (signed int)a2 > 0 && SHIDWORD(a2) > 0 && mapWidth - 1 > (signed int)a2 && mapHeight - 1 > SHIDWORD(a2) )
  {
    for ( dword_524CF0 = a2 - 1; dword_524CFC > dword_524CF0; ++dword_524CF0 )
    {
      for ( dword_524D0C = HIDWORD(a2) - 1; dword_524D0C < dword_524CE0; ++dword_524D0C )
      {
        if ( *(_BYTE *)(**(_DWORD **)((char *)thisa + 174)
                      + 12 * dword_524D0C * *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 8)
                      + 12 * dword_524CF0
                      + 9) == 152 )
        {
          if ( SHIDWORD(a2) <= dword_524D0C )
          {
            if ( dword_524CF0 != a5 || dword_524D0C != a6 )
              goto LABEL_53;
          }
          else
          {
            if ( (*(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 3) == 255
               || ((*(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 2) >> 2) & 0x3F) == 47
               || *(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 8) & 0x80)
              && (dword_524CF0 != a5 || dword_524D0C != a6) )
              goto LABEL_53;
          }
        }
      }
    }
    return 0;
  }
  if ( mapWidth - 1 == (_DWORD)a2 )
    dword_524CFC = a2 + 1;
  if ( mapHeight - 1 == HIDWORD(a2) )
    dword_524CE0 = HIDWORD(a2) + 1;
  if ( (_DWORD)a2 )
    dword_524E7C = a2 - 1;
  else
    dword_524E7C = 0;
  if ( HIDWORD(a2) )
    dword_524EBC = HIDWORD(a2) - 1;
  else
    dword_524EBC = 0;
  dword_524CF0 = dword_524E7C;
LABEL_35:
  if ( dword_524CFC <= dword_524CF0 )
    return 0;
  for ( dword_524D0C = dword_524EBC; ; ++dword_524D0C )
  {
    if ( dword_524D0C >= dword_524CE0 )
    {
      ++dword_524CF0;
      goto LABEL_35;
    }
    if ( *(_BYTE *)(**(_DWORD **)((char *)thisa + 174)
                  + 12 * dword_524D0C * *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 8)
                  + 12 * dword_524CF0
                  + 9) != 152 )
      continue;
    if ( SHIDWORD(a2) > dword_524D0C )
      break;
    if ( dword_524CF0 != a5 || dword_524D0C != a6 )
      goto LABEL_53;
LABEL_50:
    ;
  }
  if ( *(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 3) != 255
    && ((*(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 2) >> 2) & 0x3F) != 47
    && !(*(_BYTE *)(usedToCheckForBoatByCastle((AdvManager *)thisa, a2, SHIDWORD(a2)) + 8) & 0x80)
    || dword_524CF0 == a5 && dword_524D0C == a6 )
    goto LABEL_50;
LABEL_53:
  *(_DWORD *)a3 = dword_524CF0;
  *(_DWORD *)a4 = dword_524D0C;
  return 1;
}
