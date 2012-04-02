int __thiscall sub_4CF570(Icon *this, int x, int y, int idx, char a6, int mirror, int a7)
{
  int result; // eax@2
  int v8; // edi@5
  int v9; // ebx@5
  int v10; // ebp@5

  if ( mirror )
  {
    result = sub_4DDCC0((int)this, (int)HeroWindowManager::instance->screenBuffer, x, y, idx, a6, 0, 0, 0, 0, 0);
  }
  else
  {
    if ( !dword_4F7488
      || !a7
      || (v8 = x + this->headersAndImageData[idx].offsetX,
          *(_DWORD *)a7 = v8,
          v9 = this->headersAndImageData[idx].width + v8 - 1,
          *(_DWORD *)(a7 + 4) = v9,
          v10 = y + this->headersAndImageData[idx].offsetY,
          *(_DWORD *)(a7 + 8) = v10,
          result = this->headersAndImageData[idx].height + v10 - 1,
          *(_DWORD *)(a7 + 12) = result,
          dword_4F748C)
      && v8 <= combatScreenRedrawRectRight
      && combatScreenRedrawRectLeft <= v9
      && v10 <= combatScreenRedrawRectBot
      && combatScreenRedrawRectTop <= result )
      result = sub_4D82D0(this, HeroWindowManager::instance->screenBuffer, x, y, idx, a6, 0, 0, 0, 0, 0);
  }
  return result;
}
