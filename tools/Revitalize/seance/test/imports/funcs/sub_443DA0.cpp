{
  AdvManager *thisa; // [sp+Ch] [bp-2Ch]@1
  signed int i; // [sp+10h] [bp-28h]@3
  int v4; // [sp+14h] [bp-24h]@3
  int v5; // [sp+18h] [bp-20h]@3
  int v6; // [sp+1Ch] [bp-1Ch]@3
  int v7; // [sp+20h] [bp-18h]@3
  int v8; // [sp+24h] [bp-14h]@3
  int v9; // [sp+28h] [bp-10h]@3
  int v10; // [sp+2Ch] [bp-Ch]@3
  int v11; // [sp+30h] [bp-8h]@3
  int v12; // [sp+34h] [bp-4h]@3

  thisa = this;
  if ( a2 >= 1 )
    a2 = 2;
  v4 = 0;
  v5 = 3;
  v6 = 5;
  v7 = 3;
  v8 = 4;
  v9 = 5;
  v10 = 6;
  v11 = 3;
  v12 = 3;
  for ( i = 0; i < 9; ++i )
  {
    sprintf(globBuf, "wsnd%1d%1d.82M", a2, *(&v4 + i));
    thisa->field_352[i] = (int)ResourceManager::getSampleByFilename(resourceManager, globBuf);
    *(_DWORD *)(thisa->field_352[i] + 40) = 64;
    *(_DWORD *)(thisa->field_352[i] + 28) = 2;
  }
}
