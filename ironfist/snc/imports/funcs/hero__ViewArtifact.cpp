{
  heroWindow *result; // eax@2

  if ( a1 == ARTIFACT_SPELL_SCROLL )
  {
    sprintf(gText, gArtifactDesc[86], gSpellNames[a3]);
    result = NormalDialog(gText, a2 < 1 ? 1 : 4, -1, 28, -1, 0, -1, 0, -1, 0);
  }
  else
  {
    result = NormalDialog(gArtifactDesc[a1], a2 < 1 ? 1 : 4, -1, 28, -1, 0, -1, 0, -1, 0);
  }
  return result;
}