void __thiscall sub_402950(SoundManager *this, int a2, signed int a3, int a4, int a5)
{
  int v5; // eax@20
  int v6; // [sp+0h] [bp-28h]@0
  SoundManager *thisa; // [sp+Ch] [bp-1Ch]@1
  unsigned __int32 startmsec; // [sp+10h] [bp-18h]@14

  thisa = this;
  if ( !soundDisabled && this->field_69E && *(_DWORD *)&musicVolume )
  {
    if ( a2 == -1 )
    {
      sub_4022B0(this);
    }
    else
    {
      if ( this->currentTrack != a2 || !dword_4ED0AC || a5 )
      {
        passOnMessages();
        serveSound();
        thisa->field_694 = a2;
        thisa->field_698 = a4;
        if ( *((_BYTE *)&byte_523020 + a2) )
          a3 = 1;
        sub_4035A0(thisa, 1, v6);
        sub_4022B0(thisa);
        if ( !a5 && a3 && *((_DWORD *)dword_4ED0B8 + a2) )
          startmsec = *((_DWORD *)dword_4ED0B8 + a2);
        else
          startmsec = *((_DWORD *)ptr + a2);
        thisa->redbookStatus = AIL_redbook_play(redbook, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
        if ( thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION )
        {
          sleep(100);
          thisa->redbookStatus = AIL_redbook_status(redbook);
          if ( thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION )
            thisa->redbookStatus = AIL_redbook_play(redbook, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
        }
        dword_4ED0AC = 1;
        passOnMessages();
        serveSound();
        if ( thisa->volRelated <= 0 )
        {
          if ( a4 != -1 )
            SoundManager::setCDMusicVolume(thisa, -1, 0);
        }
        else
        {
          thisa->volRelated = 10;
          dword_524BF8 = getTickCount() + 600;
          v5 = computeAILVolume(1, 101);
          SoundManager::setCDMusicVolume(thisa, v5, 1);
        }
        thisa->currentTrack = a2;
      }
    }
  }
}
