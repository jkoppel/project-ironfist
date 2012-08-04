{
  gbDrawingPuzzle = 1;
  advManager::CompleteDraw(this, a2, a3, 0, 0);
  gbDrawingPuzzle = 0;
  return IconToBitmap(
           (icon *)this->field_CE[17],
           gpWindowManager->screenBuffer,
           32 * (a4 - a2) - 12,
           32 * (a5 - a3),
           0,
           1,
           0,
           0,
           0x1E0u,
           480,
           0);
}