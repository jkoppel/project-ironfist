{
  advManager *this; // [sp+Ch] [bp-8h]@1
  int grantedArtifact; // [sp+10h] [bp-4h]@1

  this = (advManager *)ecx0;
  grantedArtifact = game::GetRandomArtifactId(gpGame, 14, 1);
  if ( grantedArtifact == -1 )
    advManager::GiveResource(this, hro, 6, 1000);
  else
    GiveArtifact(hro, (ARTIFACT)grantedArtifact, 1, -1);
  return grantedArtifact;
}