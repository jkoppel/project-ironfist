{
  InputManager *thisa; // ebx@1
  int v3; // eax@2
  signed __int64 v4; // qax@3
  InputEvent *result; // eax@7
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
    v4 = v3 + 1;
    thisa->currentInputEvt = v4;
    LODWORD(v4) = (HIDWORD(v4) ^ ((BYTE4(v4) ^ (unsigned __int8)v4) - BYTE4(v4)) & 0x3F) - HIDWORD(v4);// signed v4 &= 63
    HIDWORD(v4) = evt.eventCode;
    thisa->currentInputEvt = v4;
    if ( HIDWORD(v4) == INPUT_KEYDOWN_EVENT_CODE && !thisa->normalizingKeycodeRelated )
      InputManager::stuffInvolvingNormalizingKeycode(thisa, &evt);
  }
  result = a2;
  memcpy(a2, &evt, 0x1Cu);
  return result;
}
