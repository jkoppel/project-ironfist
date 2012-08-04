{
  soundManager *thisa; // [sp+Ch] [bp-14h]@1
  int dwVolume; // [sp+18h] [bp-8h]@9
  signed int weight; // [sp+28h] [bp+8h]@3
  signed int weighta; // [sp+28h] [bp+8h]@7

  thisa = this;
  if ( !gbNoSound && this->field_69E )
  {
    weight = 127;
    if ( this->volRelated > 0 )
    {
      if ( this->volRelated > 10 )
        weight = 127 * (this->volRelated - 10) / 6;
      else
        weight = 127 * (11 - this->volRelated) / 11;
    }
    weighta = soundManager::ConvertVolume(weight, 101);
    if ( thisa->outputDeviceID != -1 )
    {
      if ( weighta )
        dwVolume = ((12 - (11 - weighta / 12)) << 12) | ((12 - (11 - weighta / 12)) << 28);
      else
        dwVolume = 0;
      auxSetVolume(thisa->outputDeviceID, dwVolume);
    }
  }
}