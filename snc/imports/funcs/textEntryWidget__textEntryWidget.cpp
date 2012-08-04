{
  int v16; // ebx@1
  icon *v17; // eax@1
  __int16 v18; // cx@1
  __int16 v19; // dx@1
  __int16 v20; // cx@1
  __int16 v21; // cx@2
  __int16 v22; // ax@2
  __int16 v23; // cx@2

  v16 = this;
  textWidget::textWidget((textWidget *)this, a2, a3, a4, a5, (char *)a7, a8, a9, a12, a13, 1);
  *(_WORD *)(v16 + 51) = a6;
  *(_WORD *)(v16 + 49) = 0;
  *(_DWORD *)v16 = &textEntryWidget::_vftable_;
  v17 = resourceManager::GetIcon(gpResourceManager, filename);
  v18 = *(_WORD *)(v16 + 24);
  *(_DWORD *)(v16 + 43) = v17;
  *(_WORD *)(v16 + 75) = 0;
  *(_WORD *)(v16 + 20) = 16384;
  v19 = *(_WORD *)(v16 + 26);
  *(_WORD *)(v16 + 47) = a11;
  *(_WORD *)(v16 + 69) = 1;
  *(_WORD *)(v16 + 71) = 0;
  *(_WORD *)(v16 + 40) = 1;
  LOWORD(v17) = *(_WORD *)(v16 + 28);
  *(_WORD *)(v16 + 53) = v18;
  v20 = *(_WORD *)(v16 + 30);
  *(_WORD *)(v16 + 55) = v19;
  *(_WORD *)(v16 + 57) = (_WORD)v17;
  *(_WORD *)(v16 + 51) = a6;
  *(_WORD *)(v16 + 59) = v20;
  *(_DWORD *)(v16 + 32) = BaseAlloc(a6 + 5, "F:\\h2xsrc\\Base\\Textntry.cpp", 62);
  strcpy(*(char **)(v16 + 32), (const char *)a7);
  if ( a14 == 4 )
  {
    *(_WORD *)(v16 + 71) = 1;
    v21 = a16 + *(_WORD *)(v16 + 26);
    *(_WORD *)(v16 + 65) = a15 + *(_WORD *)(v16 + 24);
    v22 = *(_WORD *)(v16 + 28) - 2 * a15;
    *(_WORD *)(v16 + 67) = v21;
    v23 = *(_WORD *)(v16 + 30);
    *(_WORD *)(v16 + 61) = v22;
    *(_WORD *)(v16 + 63) = v23;
  }
  return v16;
}