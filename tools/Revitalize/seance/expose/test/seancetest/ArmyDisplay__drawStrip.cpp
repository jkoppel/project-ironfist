int __thiscall ArmyDisplay::drawStrip(ArmyDisplay *this)
{
  return Icon::drawToScreen(this->stripIcon, this->x, this->y, 0, 0);
}
