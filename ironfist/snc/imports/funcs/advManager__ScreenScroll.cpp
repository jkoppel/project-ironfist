{
  signed int v4; // [sp+14h] [bp-8h]@1
  signed int v5; // [sp+18h] [bp-4h]@1

  v4 = this->viewX;
  v5 = this->viewY;
  iLastScrollTime = KBTickCount();
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
    mouseManager::SetPointer(gpMouseManager, a2 + 32);
  if ( v4 < -7 )
    v4 = -7;
  if ( MAP_WIDTH - 8 < v4 )
    v4 = MAP_WIDTH - 8;
  if ( v5 < -7 )
    v5 = -7;
  if ( MAP_HEIGHT - 8 < v5 )
    v5 = MAP_HEIGHT - 8;
  if ( this->viewX != v4 || this->viewY != v5 )
  {
    advManager::DemobilizeCurrHero(this);
    this->viewX = v4;
    this->viewY = v5;
    advManager::UpdateRadar((int)this, 1, 0);
    advManager::CompleteDraw(this, 0);
    advManager::UpdateScreen(this, 0, 0);
  }
}