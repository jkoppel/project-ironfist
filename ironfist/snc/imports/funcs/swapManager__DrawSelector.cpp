{
  int v1; // [sp+Ch] [bp-3Ch]@10
  int v2; // [sp+10h] [bp-38h]@4
  int v3; // [sp+14h] [bp-34h]@3
  int offsetY; // [sp+28h] [bp-20h]@1
  int offsetX; // [sp+30h] [bp-18h]@1

  offsetX = 0;
  offsetY = 0;
  if ( *(_DWORD *)(this + 70) != -1 && *(_DWORD *)(this + 78) != -1 )
  {
    v3 = *(_DWORD *)(this + 70);
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v1 = *(_DWORD *)(this + 86);
        if ( v1 )
        {
          if ( v1 == 1 )
          {
            offsetX = 36 * (*(_DWORD *)(this + 78) % 7) + 367;
            offsetY = *(_DWORD *)(this + 78) <= 6 ? 347 : 127;
          }
        }
        else
        {
          offsetX = 45 * *(_DWORD *)(this + 78) + 381;
          offsetY = 267;
        }
      }
    }
    else
    {
      v2 = *(_DWORD *)(this + 86);
      if ( v2 )
      {
        if ( v2 == 1 )
        {
          offsetX = 36 * (*(_DWORD *)(this + 78) % 7) + 23;
          offsetY = *(_DWORD *)(this + 78) <= 6 ? 347 : 127;
        }
      }
      else
      {
        offsetX = 45 * *(_DWORD *)(this + 78) + 36;
        offsetY = 267;
      }
    }
    icon::FillToBuffer(*(icon **)(this + 58), offsetX, offsetY, (*(_DWORD *)(this + 86) < 1u) + 2, 10, 0, 0);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, offsetX, offsetY, 0x2Eu, 46);
  }
}