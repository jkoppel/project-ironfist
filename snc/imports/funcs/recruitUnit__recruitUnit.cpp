{
  recruitUnit *thisa; // [sp+Ch] [bp-24h]@1
  int i; // [sp+10h] [bp-20h]@1
  int arr[6]; // [sp+14h] [bp-1Ch]@1
  int v8; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  baseManager::baseManager((baseManager *)this);
  thisa->vtable = &recruitUnit::_vftable_;
  thisa->field_4E = a4;
  thisa->field_36 = 35;
  thisa->army = (armyGroup *)(a2 + 8);
  thisa->creatureType = gDwellingType[*(_BYTE *)(a2 + 3)][a3];
  thisa->available = a2 + 2 * a3 + 30;
  getCreatureCosts(thisa->creatureType, arr);
  thisa->field_42 = v8;
  for ( i = 0; i < 6 && !arr[i]; ++i )
    ;
  if ( i >= 6 )
  {
    thisa->field_46 = -1;
    thisa->field_4A = 0;
  }
  else
  {
    thisa->field_46 = i;
    thisa->field_4A = arr[thisa->field_46];
  }
  return thisa;
}