{
  void *v5; // ST30_4@1

  v5 = this;
  dword_4F5460 = 1;
  sub_447C20((AdvManager *)this, a2, a3, 0, 0);
  dword_4F5460 = 0;
  return rasterize(
           *(Icon **)((char *)v5 + 274),
           HeroWindowManager::instance->screenBuffer,
           32 * (a4 - a2) - 12,
           32 * (a5 - a3),
           0,
           1,
           0,
           0,
           0x1E0u,
           480,
           0);
}
