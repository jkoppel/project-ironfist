{
  int v1; // [sp+0h] [bp-24h]@0
  soundManager *thisa; // [sp+Ch] [bp-18h]@1
  int a2; // [sp+1Ch] [bp-8h]@28
  signed int a2a; // [sp+1Ch] [bp-8h]@35

  thisa = this;
  if ( !gbNoSound )
  {
    if ( *(_DWORD *)&useCDMusic )
      soundManager::CDPoll((int)this);
    if ( (thisa->_4[0] || thisa->volRelated) && *(_DWORD *)&Data )
    {
      if ( thisa->volRelated > 0 )
      {
        Process1WindowsMessage();
        if ( thisa->currentTrack < 8 || thisa->currentTrack > 15 )
          dword_524BF8 = KBTickCount();
        thisa->volRelated = (dword_524BF8 - KBTickCount()) / 60;
        if ( thisa->volRelated < 1 )
          thisa->volRelated = 0;
        if ( thisa->volRelated <= 10 && thisa->currentTrack != thisa->_5 )
        {
          if ( *(_DWORD *)&thisa->_0[18] && *((_BYTE *)&bSaveMusicPosition + thisa->currentTrack) )
          {
            if ( !*(_DWORD *)&useCDMusic )
            {
              ProcessAssert(*(_DWORD *)&thisa->_0[18], "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED2AC + 39);
              *(_DWORD *)&thisa->_4[4 * thisa->currentTrack + 23] = ftell(*(_DWORD *)&thisa->_0[18]);
            }
          }
          else
          {
            dword_524BF8 = KBTickCount();
          }
          *(_DWORD *)&thisa->_4[263] = 1;
          if ( *((_BYTE *)&bSaveMusicPosition + thisa->_5) )
            soundManager::PlayAmbientMusic(thisa, thisa->_5, *(_DWORD *)&thisa->_4[4 * thisa->_5 + 23], -1, v1);
          else
            soundManager::PlayAmbientMusic(thisa, thisa->_5, 0, -1, v1);
          thisa->volRelated = (dword_524BF8 - KBTickCount()) / 60;
          if ( thisa->volRelated < 1 )
            thisa->volRelated = 0;
          thisa->currentTrack = LOBYTE(thisa->_5);
        }
        if ( thisa->volRelated > 10 )
          a2 = ((thisa->volRelated - 10) << 6) / 6;
        else
          a2 = ((11 - thisa->volRelated) << 6) / 11;
        if ( a2 > 64 )
          a2 = 64;
        if ( a2 < 0 )
          a2 = 0;
        if ( *(_DWORD *)&useCDMusic )
        {
          a2a = 127 * a2 * (11 - *(_DWORD *)&Data) / 640;
          if ( a2a > 127 )
            a2a = 127;
          if ( a2a < 0 )
            a2a = 0;
          soundManager::CDSetVolume(thisa, a2a, 1);
        }
        else
        {
          soundManager::MIDISetVolume(thisa);
        }
      }
      thisa->_4[0] = 0;
    }
  }
}