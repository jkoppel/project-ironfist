void __thiscall AdvManager::loadloopSample(AdvManager *this, int n)
{
  if ( !this->loopSamples[n] )
  {
    sub_456000(this, 4);
    sprintf(globBuf, "loop%04d.82M", n);
    this->loopSamples[n] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
  }
}
