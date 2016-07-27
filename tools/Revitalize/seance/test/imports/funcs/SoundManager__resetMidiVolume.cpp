{
  signed int v1; // eax@3
  int v2; // edx@3
  signed int v3; // esi@5
  signed int v4; // eax@5
  signed __int32 v5; // eax@8

  if ( !soundDisabled && this->usingRedbookRelated )
  {
    v1 = 127;
    v2 = this->volRelated;
    if ( v2 > 0 )
    {
      if ( v2 > 10 )
      {
        v3 = 6;
        v4 = 127 * (v2 - 10);
      }
      else
      {
        v3 = 11;
        v4 = 127 * (11 - v2);
      }
      v1 = v4 / v3;
    }
    v5 = computeAILVolume(v1, 101);
    AIL_set_XMIDI_master_volume(drvr, v5);
  }
}
