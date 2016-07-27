{
  sample_resource res; // [sp+10h] [bp-8h]@0

  res.file = ResourceManager::getSampleByFilename(resourceManager, file);
  if ( (_DWORD)res.file )
  {
    res.file->codeThing = 2;
    res.sample = SoundManager::playSample(soundManager, res.file);
  }
  return res;
}
