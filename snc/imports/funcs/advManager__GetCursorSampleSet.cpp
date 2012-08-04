{
  advManager *thisa; // [sp+Ch] [bp-2Ch]@1
  signed int i; // [sp+10h] [bp-28h]@3
  int v4[9]; // [sp+14h] [bp-24h]@3

  thisa = this;
  if ( speed >= 1 )
    speed = 2;
  v4[0] = 0;
  v4[1] = 3;
  v4[2] = 5;
  v4[3] = 3;
  v4[4] = 4;
  v4[5] = 5;
  v4[6] = 6;
  v4[7] = 3;
  v4[8] = 3;
  for ( i = 0; i < 9; ++i )
  {
    sprintf(gText, "wsnd%1d%1d.82M", speed, v4[i]);
    thisa->walkSamples[i] = resourceManager::GetSample(gpResourceManager, gText);
    thisa->walkSamples[i]->field_28 = 64;
    thisa->walkSamples[i]->codeThing = 2;
  }
}