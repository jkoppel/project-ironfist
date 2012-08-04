{
  soundManager *thisa; // ebx@1
  int v2; // esi@3

  thisa = this;
  LogStr("MS1");
  if ( !gbNoSound )
  {
    LODWORD(thisa->field_6AA) = 1;
    if ( !gbDontTryMIDI )
    {
      LogStr("MS2");
      memset(pMIDIWrap, 0, 0xF0u);
      memset(&hSequence, 0, 0xF0u);
      thisa->usingRedbookRelated = 1;
      LogStr("MS6b");
      v2 = AIL_midiOutOpen(&hMDI, 0, -1);
      LogInt((int)"MS6c", v2, -999, -999, -999, -999, -999, -999);
      if ( v2 )
        thisa->usingRedbookRelated = 0;
    }
  }
}