{
  bool result; // eax@10
  int v2; // [sp+10h] [bp-Ch]@1
  int i; // [sp+14h] [bp-8h]@11
  __int16 v4; // [sp+18h] [bp-4h]@1

  v2 = this;
  v4 = 0;
  if ( *(_DWORD *)(this + 4) > -1 )
  {
    v4 = sub_472850(this);
    *(_BYTE *)(*(_DWORD *)(v2 + 4) + v2 + 20) = 1;
  }
  memset((void *)(v2 + 12), 0, *(_DWORD *)(v2 + 8));
  switch ( *(_DWORD *)v2 )
  {
    case 0:
      sub_471BE0(v2);
      break;
    case 1:
      sub_471D50(v2);
      break;
    case 2:
      sub_471EA0(v2);
      break;
    case 3:
      sub_471F70(v2);
      break;
    default:
      break;
  }
  if ( sub_4723E0(v2) )
  {
    result = 0;
  }
  else
  {
    *(_DWORD *)(v2 + 4) = -1;
    for ( i = 0; *(_DWORD *)(v2 + 8) > i; ++i )
    {
      if ( *(_BYTE *)(i + v2 + 12) )
      {
        *(_WORD *)(v2 + 2 * i + 28) = v4;
        if ( *(_DWORD *)(v2 + 4) == -1 )
          *(_DWORD *)(v2 + 4) = i;
      }
    }
    sub_470DF0(v2, 0, 0);
    result = HeroWindowManager::instance->buttonPressedCode == 30722;
  }
  return result;
}
