{
  searchArray *thisa; // esi@1
  void *v2; // ecx@1

  thisa = this;
  v2 = this->field_2414;
  if ( v2 )
    BaseFree(v2, (int)"F:\\h2xsrc\\Source\\FINDPATH.CPP", word_5124EC + 1);
  thisa->field_2414 = 0;
  thisa->field_2414 = (PathfindingInfo *)BaseAlloc(
                                           9 * MAP_HEIGHT * MAP_WIDTH,
                                           "F:\\h2xsrc\\Source\\FINDPATH.CPP",
                                           word_5124C8 + 2);
}