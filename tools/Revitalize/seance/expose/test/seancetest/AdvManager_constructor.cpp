AdvManager *__thiscall AdvManager_constructor(AdvManager *this)
{
  AdvManager *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1
  signed int j; // [sp+10h] [bp-4h]@4
  signed int k; // [sp+10h] [bp-4h]@7
  signed int l; // [sp+10h] [bp-4h]@10
  signed int m; // [sp+10h] [bp-4h]@13

  thisa = this;
  AbstractManager_constructor((AbstractManager *)this);
  thisa->vtable = (ManagerVtable *)&AdvManager_vtable;
  thisa->groundTileset = 0;
  thisa->radarIcon = 0;
  thisa->viewX = 0;
  thisa->viewY = 0;
  thisa->field_1F6 = 0;
  thisa->field_1FA = 0;
  thisa->field_1FE = 0;
  thisa->field_202 = 0;
  thisa->field_206 = 0;
  thisa->field_36 = -1;
  thisa->field_272 = 0;
  thisa->field_376 = 0;
  thisa->field_276 = 1;
  thisa->field_BA = 0;
  for ( i = 0; i < 64; ++i )
    thisa->field_CE[i] = 0;
  for ( j = 0; j < 8; ++j )
    thisa->heroIcons[j] = 0;
  for ( k = 0; k < 6; ++k )
  {
    thisa->flagIcons1[k] = 0;
    thisa->flagIcons2[k] = 0;
  }
  for ( l = 0; l < 28; ++l )
    thisa->field_2E2[l] = 0;
  for ( m = 0; m < 9; ++m )
    thisa->field_352[m] = 0;
  thisa->radarIcon = 0;
  thisa->clopIcon = 0;
  thisa->boatShadowIcon = 0;
  thisa->shadowIcon = 0;
  thisa->groundTileset = 0;
  thisa->clofTileset = 0;
  thisa->stonTileset = 0;
  thisa->adventureScreen = 0;
  thisa->field_9E = 0;
  thisa->field_2A6 = 0;
  thisa->field_2AA = 0;
  dword_524C14 = 1;
  thisa->field_2B2 = -99;
  thisa->field_2B6 = -99;
  thisa->field_20A = 0;
  thisa->field_20E = 4;
  thisa->field_212 = 11;
  thisa->field_216 = 13;
  thisa->field_AE = (int *)sub_419850(gameObject);
  dword_524214 = 0;
  dword_524218 = 0;
  thisa->field_286 = 0;
  thisa->field_28A = 0;
  thisa->field_28E = 0;
  return thisa;
}
