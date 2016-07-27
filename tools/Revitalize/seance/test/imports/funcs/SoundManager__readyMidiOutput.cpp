{
  SoundManager *thisa; // ebx@1
  int v2; // esi@3

  thisa = this;
  debugLog("MS1");
  if ( !soundDisabled )
  {
    LODWORD(thisa->field_6AA) = 1;
    if ( !dword_4F1C94 )
    {
      debugLog("MS2");
      memset(sequences, 0, 0xF0u);
      memset(&hsequences, 0, 0xF0u);
      thisa->usingRedbookRelated = 1;
      debugLog("MS6b");
      v2 = AIL_midiOutOpen(&drvr, 0, -1);
      logUpTo7Ints((int)"MS6c", v2, -999, -999, -999, -999, -999, -999);
      if ( v2 )
        thisa->usingRedbookRelated = 0;
    }
  }
}
