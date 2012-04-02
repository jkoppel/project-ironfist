int __thiscall sub_4D0F50(InputManager *this, int a2)
{
  int result; // eax@1

  this->normalizingKeycodeRelated = a2;
  result = 0;
  this->currentInfoField = 0;
  this->currentInputEvt = 0;
  return result;
}
