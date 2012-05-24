{
  bool result; // eax@2

  if ( soundDisabled )
  {
    result = 0;
  }
  else
  {
    if ( this->field_69E )
      result = AIL_redbook_status(redbook) == REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION;
    else
      result = 0;
  }
  return result;
}
