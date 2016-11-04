{
  ManagerManager *v1; // ebx@1
  signed int v2; // ebp@1
  signed int v3; // esi@3
  AbstractManager *v4; // eax@3
  AbstractManager *curMan; // ecx@6
  int v6; // eax@9
  AbstractManager *v7; // eax@21
  InputEvent evt; // [sp+10h] [bp-38h]@3
  InputEvent a2; // [sp+2Ch] [bp-1Ch]@3

  v1 = this;
  v2 = 0;
  if ( this->firstManager )
  {
    InputManager::resetInfoFields(inputManager);
    do
    {
      passOnMessages();
      memcpy(&evt, InputManager::nextInputEvent(inputManager, &a2), sizeof(evt));
      v3 = 1;
      v4 = v1->firstManager;
      v1->currentManager = v1->firstManager;
      if ( !v4 )
        return;
      while ( v3 )
      {
        if ( v2 )
          return;
        curMan = v1->currentManager;
        if ( curMan->ready != 1
          || evt.eventCode == INPUT_MOUSEMOVE_EVENT_CODE && (AbstractManager *)HeroWindowManager::instance == curMan )
          goto LABEL_21;
        v6 = curMan->vtable->handleInput(curMan, &evt);
        if ( v6 == 1 )
        {
          v3 = 0;
          goto LABEL_21;
        }
        if ( v6 != 2 || !(BYTE1(evt.eventCode) & 0x40) )
          goto LABEL_21;
        if ( evt.xCoordOrKeycode == 1 )
          goto LABEL_20;
        if ( evt.xCoordOrKeycode == INPUT_KEYUP_EVENT_CODE )
        {
          ManagerManager__removeManager(v1, v1->currentManager);
          v1->currentManager = 0;
          goto LABEL_21;
        }
        if ( evt.xCoordOrKeycode == 4 )
        {
          v1->field_C = evt.payload;
LABEL_20:
          v2 = 1;
        }
LABEL_21:
        v7 = v1->currentManager;
        if ( v7 )
        {
          v1->currentManager = v7->next;
          if ( v1->currentManager )
            continue;
        }
        break;
      }
    }
    while ( !v2 );
  }
}
