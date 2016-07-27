{
  int v1; // eax@1

  v1 = 3;
  if ( !(this->field_16 & 8) )
    v1 = this->field_28;
  Font::drawString(
    this->font,
    this->content,
    this->parentWindow->xOffset + this->offsetX,
    this->parentWindow->yOffset + this->offsetY,
    this->width,
    this->height,
    v1,
    this->field_2A);
}
