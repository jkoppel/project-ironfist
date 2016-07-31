{
  int v3; // ST24_4@23
  size_t v4; // eax@23
  void *v5; // [sp+Ch] [bp-50h]@1
  char v6; // [sp+10h] [bp-4Ch]@2
  TextWidget *thisa; // [sp+14h] [bp-48h]@23
  int v8; // [sp+1Ch] [bp-40h]@17
  int a4; // [sp+20h] [bp-3Ch]@14
  __int16 v10; // [sp+24h] [bp-38h]@14
  __int16 v11; // [sp+26h] [bp-36h]@14
  __int16 v12; // [sp+28h] [bp-34h]@14
  __int16 v13; // [sp+2Ah] [bp-32h]@14
  char *content; // [sp+2Ch] [bp-30h]@23
  int evt; // [sp+30h] [bp-2Ch]@8
  int v16; // [sp+34h] [bp-28h]@8
  int v17; // [sp+38h] [bp-24h]@8
  int v18; // [sp+48h] [bp-14h]@8
  int a2a; // [sp+4Ch] [bp-10h]@14
  __int16 v20; // [sp+50h] [bp-Ch]@14
  __int16 v21; // [sp+52h] [bp-Ah]@14
  __int16 v22; // [sp+54h] [bp-8h]@14
  __int16 v23; // [sp+56h] [bp-6h]@14
  int i; // [sp+58h] [bp-4h]@14

  v5 = this;
  dword_511E64 = a2;
  if ( a2 )
    v6 = curPlayer->numCastles;
  else
    v6 = curPlayer->numHeroes;
  dword_525224 = v6;
  if ( dword_511E68[dword_511E64] > v6 - 4 )
    dword_511E68[dword_511E64] = dword_525224 - 4;
  if ( dword_511E68[dword_511E64] < 0 )
    dword_511E68[dword_511E64] = 0;
  evt = 512;
  v16 = 4;
  v17 = 102;
  v18 = dword_511E64 + 6;
  GUIWindow::processMessage(dword_511E58, (Event *)&evt);
  v16 = 4;
  v17 = 100;
  if ( dword_511E64 )
    v18 = 0;
  else
    v18 = 1;
  GUIWindow::processMessage(dword_511E58, (Event *)&evt);
  v16 = 4;
  v17 = 101;
  if ( dword_511E64 == 1 )
    v18 = 3;
  else
    v18 = 2;
  GUIWindow::processMessage(dword_511E58, (Event *)&evt);
  a2a = 15204387;
  v20 = 377;
  v21 = 35;
  v22 = 177;
  v23 = 379;
  a4 = 9306306;
  v10 = 241;
  v11 = 140;
  v12 = 199;
  v13 = 239;
  for ( i = 0; i < 3; ++i )
  {
    if ( dword_525218[i] )
    {
      GUIWindow::removeComponent(dword_511E58, (AbstractGUIComponent *)dword_525218[i]);
      v8 = dword_525218[i];
      if ( v8 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
      dword_525218[i] = 0;
    }
  }
  for ( i = 0; i < 3; ++i )
  {
    v3 = word_5120D0 + 42;
    v4 = strlen((&off_4F6F90)[4 * (i + 3 * dword_511E64)]);
    content = (char *)KBAlloc(v4 + 1, "F:\\h2xsrc\\Source\\Overview.cpp", v3);
    strcpy(content, (&off_4F6F90)[4 * (i + 3 * dword_511E64)]);
    thisa = (TextWidget *)operator new(0x2Bu);
    if ( thisa )
      dword_525218[i] = (int)TextWidget_constructor(
                               thisa,
                               *(int *)((char *)&a2a + 6 * dword_511E64 + 2 * i),
                               3,
                               *(int *)((char *)&a4 + 6 * dword_511E64 + 2 * i),
                               12,
                               content,
                               "smalfont.fnt",
                               1,
                               i + 110,
                               512,
                               1);
    else
      dword_525218[i] = 0;
    GUIWindow::insertElement(dword_511E58, (AbstractGUIComponent *)dword_525218[i], -1);
  }
  sub_45FF60(v5, 0, 1, 0);
  if ( a3 )
    GUIWindow::repaintComponentsInRange(dword_511E58, a3, 100, 999);
}
