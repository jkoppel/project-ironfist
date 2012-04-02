void __thiscall sub_403C60(int this)
{
  if ( !soundDisabled )
  {
    *(_BYTE *)(this + 1405) = 1;
    sub_403E60((SoundManager *)this);
  }
}
