int __thiscall Button::paint(Button *this)
{
  GUIWindow *window; // edx@1
  int result; // eax@2

  window = this->parentWindow;
  if ( this->flags & BUTTON_IS_ARMED )
    result = Icon::drawToScreen(
               this->icon,
               window->xOffset + HIWORD(this->flags),
               window->yOffset + this->offsetY,
               this->armedImageIdx,
               0);
  else
    result = Icon::drawToScreen(
               this->icon,
               window->xOffset + HIWORD(this->flags),
               window->yOffset + this->offsetY,
               this->normalImageIdx,
               0);
  return result;
}
