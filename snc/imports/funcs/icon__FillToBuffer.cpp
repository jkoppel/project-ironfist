{
  int result; // eax@2
  int v8; // edi@5
  int v9; // ebx@5
  int v10; // ebp@5

  if ( mirror )
  {
    result = FlipMonoIconToBitmap((int)this, (int)gpWindowManager->screenBuffer, x, y, idx, a6, 0, 0, 0, 0, 0);
  }
  else if ( !gbLimitToExtent
  || !a7
  || (v8 = x + this->headersAndImageData[idx].offsetX,
      *(_DWORD *)a7 = v8,
      v9 = this->headersAndImageData[idx].width + v8 - 1,
      *(_DWORD *)(a7 + 4) = v9,
      v10 = y + this->headersAndImageData[idx].offsetY,
      *(_DWORD *)(a7 + 8) = v10,
      result = this->headersAndImageData[idx].height + v10 - 1,
      *(_DWORD *)(a7 + 12) = result,
      gbCurrArmyDrawn)
  && v8 <= giMaxExtentX
  && giMinExtentX <= v9
  && v10 <= giMaxExtentY
  && giMinExtentY <= result )
  {
    result = MonoIconToBitmap(this, gpWindowManager->screenBuffer, x, y, idx, a6, 0, 0, 0, 0, 0);
  }
  return result;
}