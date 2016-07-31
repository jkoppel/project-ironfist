{
  int v2; // ST18_4@1

  v2 = this;
  _write(a2, (const void *)(this + 8), 4u);
  _write(a2, (const void *)(v2 + 12), 4u);
  _write(a2, *(const void **)v2, 12 * *(_DWORD *)(v2 + 12) * *(_DWORD *)(v2 + 8));
  _write(a2, (const void *)(v2 + 16), 4u);
  return _write(a2, *(const void **)(v2 + 4), 7 * *(_DWORD *)(v2 + 16));
}
