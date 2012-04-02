void __thiscall renderScreenFromBitmapWithWinG(Bitmap *this)
{
  renderBitmapToScreenWithWinG(this, 0, 0, this->width, this->height, 0, 0);
}
