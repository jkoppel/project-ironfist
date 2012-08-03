{
  bool result; // eax@2

  if ( gbNoSound )
  {
    result = 0;
  }
  else if ( this->field_69E )
  {
    result = AIL_redbook_status(aStatusCdPositi) == REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION;
  }
  else
  {
    result = 0;
  }
  return result;
}