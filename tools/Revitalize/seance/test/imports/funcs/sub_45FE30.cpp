{
  if ( dword_511794 )
  {
    if ( dword_511794 == 1 )
    {
      sub_45F910();
      if ( dword_4ED2F0 )
        return 1;
    }
  }
  else
  {
    if ( getTickCount() < dword_511790 )
      return 0;
    sub_45F910();
    if ( dword_511780 )
    {
      ++dword_511794;
      return 0;
    }
    sub_45F5F0(0, 2, 0x22u, &unk_526CB8);
    dword_511790 = getTickCount() + 3000;
    ++dword_51178C;
    if ( dword_51178C > 15 )
    {
      sprintf(cp, "The Host is not responding.  Keep waiting?");
      display_message_window(cp, 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
        terminate(0);
      dword_51178C = 0;
    }
  }
  return 0;
}
