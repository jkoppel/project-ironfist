{
  int *v0; // ebx@2
  int *v1; // edi@2
  tag_message *v2; // esi@2
  int *v3; // ST04_4@2
  int *v4; // ST00_4@2
  int v5; // ecx@2

  if ( !gpInputManager->readingInputMutex )
  {
    gpInputManager->readingInputMutex = 1;
    v0 = &gpInputManager->inputInstances[gpInputManager->currentInfoField].yCoord;
    v1 = &gpInputManager->inputInstances[gpInputManager->currentInfoField].xCoordOrKeycode;
    v2 = &gpInputManager->inputInstances[gpInputManager->currentInfoField];
    v3 = &gpInputManager->inputInstances[gpInputManager->currentInfoField].yCoord;
    v4 = &gpInputManager->inputInstances[gpInputManager->currentInfoField].xCoordOrKeycode;
    v2->eventCode = 4;
    mouseManager::MouseCoords(v4, v3);
    v2->altXCoord = *v1;
    v2->altYCoord = *v0;
    v2->inputTypeBitmask = gpInputManager->forSettingBitmask;
    ++gpInputManager->currentInfoField;
    gpInputManager->currentInfoField = (((unsigned __int64)gpInputManager->currentInfoField >> 32) ^ abs(gpInputManager->currentInfoField) & 0x3F)
                                     - ((unsigned __int64)gpInputManager->currentInfoField >> 32);
    v5 = gpInputManager->currentInputEvt;
    if ( gpInputManager->currentInfoField == v5 )
    {
      gpInputManager->currentInputEvt = v5 + 1;
      gpInputManager->currentInputEvt = (((unsigned __int64)gpInputManager->currentInputEvt >> 32) ^ abs(gpInputManager->currentInputEvt) & 0x3F)
                                      - ((unsigned __int64)gpInputManager->currentInputEvt >> 32);
    }
    gpInputManager->readingInputMutex = 0;
  }
}