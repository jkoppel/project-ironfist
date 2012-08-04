{
  int v5; // eax@20
  int v6; // [sp+0h] [bp-28h]@0
  soundManager *thisa; // [sp+Ch] [bp-1Ch]@1
  unsigned __int32 startmsec; // [sp+10h] [bp-18h]@14

  thisa = this;
  if ( !gbNoSound && this->field_69E && *(_DWORD *)&Data )
  {
    if ( a2 == -1 )
    {
      soundManager::CDStop(this);
    }
    else if ( this->currentTrack != a2 || !CDPlaying || a5 )
    {
      Process1WindowsMessage();
      soundManager::ServiceSound();
      thisa->field_694 = a2;
      thisa->field_698 = a4;
      if ( *((_BYTE *)&bSaveMusicPosition + a2) )
        a3 = 1;
      soundManager::StopAllSamples(thisa, 1, v6);
      soundManager::CDStop(thisa);
      if ( !a5 && a3 && *((_DWORD *)dword_4ED0B8 + a2) )
        startmsec = *((_DWORD *)dword_4ED0B8 + a2);
      else
        startmsec = *((_DWORD *)ptr + a2);
      thisa->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
      if ( thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION )
      {
        DelayMilli(100);
        thisa->redbookStatus = AIL_redbook_status(aStatusCdPositi);
        if ( thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION )
          thisa->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
      }
      CDPlaying = 1;
      Process1WindowsMessage();
      soundManager::ServiceSound();
      if ( thisa->volRelated <= 0 )
      {
        if ( a4 != -1 )
          soundManager::CDSetVolume(thisa, -1, 0);
      }
      else
      {
        thisa->volRelated = 10;
        dword_524BF8 = KBTickCount() + 600;
        v5 = soundManager::ConvertVolume(1, 101);
        soundManager::CDSetVolume(thisa, v5, 1);
      }
      thisa->currentTrack = a2;
    }
  }
}