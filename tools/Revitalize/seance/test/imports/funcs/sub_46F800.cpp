{
  MapTiles *v2; // ST0C_4@1
  int result; // eax@1

  v2 = this;
  *(_BYTE *)(this->field_4 - a2 + 8 * a2 + 2) &= 1u;
  *(_BYTE *)(this->field_4 - a2 + 8 * a2 + 3) = -1;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 2) &= 0xFEu;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 4) &= 0xFEu;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 4) &= 0xFDu;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 4) &= 0xFBu;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 5) &= 3u;
  *(_BYTE *)(this->field_4 - a2 + 8 * a2 + 6) = -1;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 5) &= 0xFEu;
  *(_BYTE *)(v2->field_4 - a2 + 8 * a2 + 5) &= 0xFDu;
  result = this->field_4;
  *(_WORD *)(result + 7 * a2) = 0;
  return result;
}
