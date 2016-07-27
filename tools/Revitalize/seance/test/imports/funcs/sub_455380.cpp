{
  signed int result; // eax@1
  void *v2; // [sp+Ch] [bp-Ch]@1
  int y; // [sp+10h] [bp-8h]@2
  int x; // [sp+14h] [bp-4h]@2

  v2 = this;
  result = *(&byte_524758 + curPlayerIdx);
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    retrieveVirtualCursorCoordinates(&x, &y);
    *(_DWORD *)((char *)v2 + 486) = -1;
    result = sub_446FB0(v2, x, y);
  }
  return result;
}
