{
  SoundManager *v1; // [sp+Ch] [bp-4h]@1

  v1 = this;
  if ( !soundDisabled && this->field_69E )
  {
    this->redbookStatus = AIL_redbook_stop(redbook);
    if ( v1->redbookStatus != 3 )
    {
      sleep(100);
      v1->redbookStatus = AIL_redbook_status(redbook);
      if ( v1->redbookStatus != 3 )
        v1->redbookStatus = AIL_redbook_stop(redbook);
    }
    AIL_redbook_close(redbook);
    if ( v1->outputDeviceID != -1 )
      auxSetVolume(v1->outputDeviceID, pdwVolume);
    redbook = 0;
    if ( ptr )
      KBFree(ptr, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 26);
    ptr = 0;
    if ( dword_4ED0B4 )
      KBFree(dword_4ED0B4, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 30);
    dword_4ED0B4 = 0;
    if ( dword_4ED0B8 )
      KBFree(dword_4ED0B8, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 34);
    dword_4ED0B8 = 0;
  }
}
