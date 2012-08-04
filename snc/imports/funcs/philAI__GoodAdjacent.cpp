{
  signed int result; // eax@2
  void *v3; // [sp+Ch] [bp-30h]@1
  signed int v4; // [sp+18h] [bp-24h]@1
  int v5; // [sp+1Ch] [bp-20h]@16
  int v6; // [sp+20h] [bp-1Ch]@1
  int v7; // [sp+24h] [bp-18h]@1
  int row; // [sp+28h] [bp-14h]@6
  int col; // [sp+2Ch] [bp-10h]@6
  int v10; // [sp+30h] [bp-Ch]@16
  int v11; // [sp+34h] [bp-8h]@1
  int i; // [sp+38h] [bp-4h]@3

  v3 = this;
  v11 = -1;
  v7 = fReduceFactor;
  v6 = fBerserkFactor;
  fReduceFactor = 1065353216;
  fBerserkFactor = 1065353216;
  v4 = 100;
  if ( (advManager::GetCell(gpAdvManager, gpCurAIHero->x, gpCurAIHero->y)->objType & 0x7F) == 36 )
  {
    result = 0;
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      if ( advManager::ValidMoveWithEvent((int)gpAdvManager, (int)gpCurAIHero, i) )
      {
        col = gpCurAIHero->x + normalDirTable[4 * i];
        row = gpCurAIHero->y + byte_4F1DC1[4 * i];
        if ( advManager::GetCell(
               gpAdvManager,
               gpCurAIHero->x + normalDirTable[4 * i],
               gpCurAIHero->y + byte_4F1DC1[4 * i])->objType & 0x80 )
        {
          if ( !(*(&mapExtra[col] + row * MAP_WIDTH) & 0x80)
            && (advManager::GetCell(gpAdvManager, col, row)->objType & 0x7F) != 36
            && (advManager::GetCell(gpAdvManager, col, row)->objType & 0x7F) != 39
            && (advManager::GetCell(gpAdvManager, col, row)->objType != 163
             || gpGame->castles[(unsigned __int8)((unsigned __int8)(advManager::GetCell(gpAdvManager, col, row)->flags >> 8) >> -5)].ownerIdx != giCurPlayer
             || *(_WORD *)&gpCurAIHero->_2[3] != giCurTurn) )
          {
            if ( advManager::GetCell(gpAdvManager, col, row)->objType != 170
              || gpGame->heroes[(unsigned __int8)((unsigned __int8)(advManager::GetCell(gpAdvManager, col, row)->flags >> 8) >> -5)].probablyOwnerIdx != giCurPlayer
              || *(_WORD *)&gpCurAIHero->_2[0] != giCurTurn )
            {
              v5 = philAI::ValueOfEventAtPosition(v3, __PAIR__(row, col), 2, (int)&v10);
              if ( v10 > 80 )
              {
                if ( v4 < v5 )
                {
                  v4 = v5;
                  v11 = i;
                }
              }
            }
          }
        }
      }
    }
    fReduceFactor = v7;
    fBerserkFactor = v6;
    if ( v11 == -1 )
    {
      result = 0;
    }
    else
    {
      *(_DWORD *)a1 = v11;
      result = 1;
    }
  }
  return result;
}