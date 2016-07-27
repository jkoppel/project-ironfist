{
  int result; // eax@4
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  if ( *(_DWORD *)(this + 66) == 3
    || *(_DWORD *)(this + 1050) >= 0 && *(_DWORD *)(this + 1042) > *(_DWORD *)(this + 1050) )
  {
    if ( *(_DWORD *)(this + 1050) == -1 )
    {
      sprintf(globBuf, "%s%s", this + 691, this + 686);
    }
    else
    {
      if ( *(_DWORD *)(this + 66) != 2 && *(_DWORD *)(this + 66) != 4 && *(_DWORD *)(this + 66) != 1 )
        sprintf(globBuf, "%s%s", *(_DWORD *)(this + 670) + 351 * *(_DWORD *)(this + 1050), this + 686);
      else
        sprintf(
          globBuf,
          "%s%s",
          *(_DWORD *)(this + 670) + 351 * *(_DWORD *)(this + 1050),
          *(_DWORD *)(this + 674) + 5 * *(_DWORD *)(this + 1050));
    }
    strcpy((char *)(v2 + 691), globBuf);
    result = v2 + 691;
  }
  else
  {
    result = (int)off_4EE0E0;
  }
  return result;
}
