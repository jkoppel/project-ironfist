{
  sample_resource res; // [sp+10h] [bp-8h]@0

  res.file = resourceManager::GetSample(gpResourceManager, file);
  if ( (_DWORD)res.file )
  {
    res.file->codeThing = 2;
    res.sample = soundManager::MemorySample(gpSoundManager, res.file);
  }
  return res;
}