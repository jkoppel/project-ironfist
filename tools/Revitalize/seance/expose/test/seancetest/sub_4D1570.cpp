void __cdecl sub_4D1570()
{
  int *v0; // ebx@2
  int *v1; // edi@2
  InputEvent *v2; // esi@2
  int *v3; // ST04_4@2
  int *v4; // ST00_4@2
  int v5; // ecx@2

  if ( !inputManager->readingInputMutex )
  {
    inputManager->readingInputMutex = 1;
    v0 = &inputManager->inputInstances[inputManager->currentInfoField].yCoord;
    v1 = &inputManager->inputInstances[inputManager->currentInfoField].xCoordOrKeycode;
    v2 = &inputManager->inputInstances[inputManager->currentInfoField];
    v3 = &inputManager->inputInstances[inputManager->currentInfoField].yCoord;
    v4 = &inputManager->inputInstances[inputManager->currentInfoField].xCoordOrKeycode;
    v2->eventCode = 4;
    retrieveVirtualCursorCoordinates(v4, v3);
    v2->altXCoord = *v1;
    v2->altYCoord = *v0;
    v2->inputTypeBitmask = inputManager->forSettingBitmask;
    ++inputManager->currentInfoField;
    inputManager->currentInfoField = (((unsigned __int64)inputManager->currentInfoField >> 32) ^ abs(inputManager->currentInfoField) & 0x3F)
                                   - ((unsigned __int64)inputManager->currentInfoField >> 32);
    v5 = inputManager->currentInputEvt;
    if ( inputManager->currentInfoField == v5 )
    {
      inputManager->currentInputEvt = v5 + 1;
      inputManager->currentInputEvt = (((unsigned __int64)inputManager->currentInputEvt >> 32) ^ abs(inputManager->currentInputEvt) & 0x3F)
                                    - ((unsigned __int64)inputManager->currentInputEvt >> 32);
    }
    inputManager->readingInputMutex = 0;
  }
}
