{
  signed int result; // eax@1

  result = this;
  if ( *(_DWORD *)(this + 4) != -1 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 4) + this + 20) = 1;
    sprintf(globBuf, "%s_%d", off_51A870[*(_DWORD *)this], *(_DWORD *)(this + 4) + 1);
    result = GameInfo::saveGame(gameObject, globBuf, 1, 0);
  }
  return result;
}
