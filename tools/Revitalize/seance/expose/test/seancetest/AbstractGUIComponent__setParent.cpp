int __thiscall AbstractGUIComponent::setParent(AbstractGUIComponent *this, __int16 idx, GUIWindow *parent)
{
  this->componentIndex = idx;
  this->parentWindow = parent;
  return 0;
}
