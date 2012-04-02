void __thiscall sub_402B80(int ecx0)
{
  int this; // [sp+Ch] [bp-4h]@1

  this = ecx0;
  if ( !soundDisabled
    && *(_DWORD *)(ecx0 + 1694)
    && *(_DWORD *)&musicVolume
    && dword_4ED0AC
    && (signed int)*(_BYTE *)(ecx0 + 1404) >= 0
    && byte_524060[*(_BYTE *)(ecx0 + 1404)]
    && getTickCount() >= *(_DWORD *)(ecx0 + 1710) + 3000 )
  {
    *(_DWORD *)(this + 1710) = getTickCount();
    if ( !sub_4023E0((SoundManager *)this) )
      sub_402950((SoundManager *)this, *(_DWORD *)(this + 1684), 0, -1, 1);
  }
}
