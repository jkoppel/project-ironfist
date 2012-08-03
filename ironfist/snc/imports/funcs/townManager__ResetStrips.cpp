{
  int result; // eax@5
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  if ( *(_DWORD *)(this + 222) )
    *(_DWORD *)(*(_DWORD *)(this + 222) + 40) = -1;
  if ( *(_DWORD *)(this + 230) )
    *(_DWORD *)(*(_DWORD *)(this + 230) + 40) = -1;
  strip::Draw(*(_DWORD *)(this + 210));
  strip::Draw(*(_DWORD *)(v2 + 206));
  *(_DWORD *)(v2 + 230) = 0;
  *(_DWORD *)(v2 + 222) = *(_DWORD *)(v2 + 230);
  *(_DWORD *)(v2 + 234) = -1;
  result = *(_DWORD *)(v2 + 234);
  *(_DWORD *)(v2 + 226) = result;
  return result;
}