{
  if ( !this->loopSamples[n] )
  {
    advManager::TrimLoopingSounds(this, 4);
    sprintf(gText, "loop%04d.82M", n);
    this->loopSamples[n] = resourceManager::GetSample(gpResourceManager, gText);
  }
}