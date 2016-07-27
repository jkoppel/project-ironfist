{
  bool result; // eax@2

  if ( soundDisabled )
  {
    result = 0;
  }
  else
  {
    if ( *(_DWORD *)&useCDMusic )
    {
      if ( this->field_69E )
        result = sub_4023E0(this);
      else
        result = 0;
    }
    else
    {
      if ( this->usingRedbookRelated )
        result = sub_4CBB80(this);
      else
        result = 0;
    }
  }
  return result;
}
