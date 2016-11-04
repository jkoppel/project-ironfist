{
  Sample *result; // eax@1
  void *v3; // [sp+Ch] [bp-4h]@1

  v3 = this;
  result = (Sample *)a2;
  if ( !*(_DWORD *)((char *)this + 4 * a2 + 738) )
  {
    sub_456000(this, 4);
    sprintf(globBuf, "loop%04d.82M", a2);
    result = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    *(_DWORD *)((char *)v3 + 4 * a2 + 738) = result;
  }
  return result;
}
