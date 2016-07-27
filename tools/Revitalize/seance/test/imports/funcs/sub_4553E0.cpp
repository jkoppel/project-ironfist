{
  int thisa; // [sp+10h] [bp-Ch]@1
  signed int v4; // [sp+14h] [bp-8h]@1
  signed int v5; // [sp+18h] [bp-4h]@1

  thisa = this;
  v4 = *(_DWORD *)(this + 470);
  v5 = *(_DWORD *)(this + 474);
  dword_50EA8C = getTickCount();
  switch ( a2 )
  {
    case 0:
      --v5;
      break;
    case 1:
      ++v4;
      --v5;
      break;
    case 2:
      ++v4;
      break;
    case 3:
      ++v4;
      ++v5;
      break;
    case 4:
      ++v5;
      break;
    case 5:
      --v4;
      ++v5;
      break;
    case 6:
      --v4;
      break;
    case 7:
      --v4;
      --v5;
      break;
    default:
      break;
  }
  if ( a3 )
    MouseManager::setSpriteIdx(mouseManager, a2 + 32);
  if ( v4 < -7 )
    v4 = -7;
  if ( mapWidth - 8 < v4 )
    v4 = mapWidth - 8;
  if ( v5 < -7 )
    v5 = -7;
  if ( mapHeight - 8 < v5 )
    v5 = mapHeight - 8;
  if ( *(_DWORD *)(thisa + 470) != v4 || *(_DWORD *)(thisa + 474) != v5 )
  {
    sub_450880((AdvManager *)thisa);
    *(_DWORD *)(thisa + 470) = v4;
    *(_DWORD *)(thisa + 474) = v5;
    sub_44AA80(thisa, 1, 0);
    sub_448110((AdvManager *)thisa, 0);
    sub_447A00((void *)thisa, 0, 0);
  }
}
