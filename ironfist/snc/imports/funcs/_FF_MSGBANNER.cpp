{
  int result; // eax@1

  result = __error_mode;
  if ( __error_mode == 1 || !__error_mode && __app_type == 1 )
  {
    _NMSG_WRITE(252);
    if ( _adbgmsg )
      _adbgmsg();
    result = _NMSG_WRITE(255);
  }
  return result;
}