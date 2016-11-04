{
  InputManager *thisa; // ebx@1
  int v3; // eax@2
  INPUT_EVENT_CODE v4; // edx@3
  void *result; // eax@7
  InputEvent evt; // [sp+Ch] [bp-1Ch]@3

  thisa = this;
  yieldToGlobalUpdater();
  if ( inputManager->ready != 1 || (v3 = thisa->currentInputEvt, thisa->currentInfoField == v3) )
  {
    evt.eventCode = 0;
    evt.yCoord = 0;
    evt.xCoordOrKeycode = 0;
    evt.inputTypeBitmask = 0;
  }
  else
  {
    memcpy(&evt, &thisa->inputInstances[v3], sizeof(evt));
    v4 = (signed int)evt.eventCode;
    thisa->currentInputEvt = (((unsigned __int64)v3 >> 32) ^ abs(v3) & 0x3F) - ((unsigned __int64)v3 >> 32);
    if ( v4 == 1 && !thisa->normalizingKeycodeRelated )
      InputManager::stuffInvolvingNormalizingKeycode(thisa, &evt);
  }
  result = a2;
  memcpy(a2, &evt, 0x1Cu);
  return result;
}
