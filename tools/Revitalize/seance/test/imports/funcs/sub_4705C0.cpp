{
  int v2; // ST0C_4@1

  v2 = this;
  *(_DWORD *)this = a2;
  *(_DWORD *)(this + 4) = -1;
  *(_DWORD *)(this + 8) = dword_512A30[a2];
  sub_470440(this);
  sub_470470(v2);
  sub_4704A0(v2);
  return sub_4704D0(v2);
}
