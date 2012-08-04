{
  heroWindow *window; // edx@1
  int result; // eax@2

  window = this->parentWindow;
  if ( this->flags & BUTTON_IS_ARMED )
    result = icon::DrawToBuffer(
               this->icon,
               window->xOffset + HIWORD(this->flags),
               window->yOffset + this->offsetY,
               this->armedImageIdx,
               0);
  else
    result = icon::DrawToBuffer(
               this->icon,
               window->xOffset + HIWORD(this->flags),
               window->yOffset + this->offsetY,
               this->normalImageIdx,
               0);
  return result;
}