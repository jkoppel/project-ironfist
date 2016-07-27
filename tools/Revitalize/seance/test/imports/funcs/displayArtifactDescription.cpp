{
  GUIWindow *result; // eax@2

  if ( a1 == ARTIFACT_SPELL_SCROLL )
  {
    sprintf(globBuf, artifact_descriptions[86], spell_names[a3]);
    result = display_message_window(globBuf, a2 < 1 ? 1 : 4, -1, 28, -1, 0, -1, 0, -1, 0);
  }
  else
  {
    result = display_message_window(artifact_descriptions[a1], a2 < 1 ? 1 : 4, -1, 28, -1, 0, -1, 0, -1, 0);
  }
  return result;
}
