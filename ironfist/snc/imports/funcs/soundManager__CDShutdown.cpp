{
  soundManager *v1; // [sp+Ch] [bp-4h]@1

  v1 = this;
  if ( !gbNoSound && this->field_69E )
  {
    this->redbookStatus = AIL_redbook_stop(aStatusCdPositi);
    if ( v1->redbookStatus != 3 )
    {
      DelayMilli(100);
      v1->redbookStatus = AIL_redbook_status(aStatusCdPositi);
      if ( v1->redbookStatus != 3 )
        v1->redbookStatus = AIL_redbook_stop(aStatusCdPositi);
    }
    AIL_redbook_close(aStatusCdPositi);
    if ( v1->outputDeviceID != -1 )
      auxSetVolume(v1->outputDeviceID, pdwVolume);
    aStatusCdPositi = 0;
    if ( ptr )
      BaseFree(ptr, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 26);
    ptr = 0;
    if ( dword_4ED0B4 )
      BaseFree(dword_4ED0B4, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 30);
    dword_4ED0B4 = 0;
    if ( dword_4ED0B8 )
      BaseFree(dword_4ED0B8, (int)"F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED1C0 + 34);
    dword_4ED0B8 = 0;
  }
}