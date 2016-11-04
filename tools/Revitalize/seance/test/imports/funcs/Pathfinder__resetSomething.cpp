{
  Pathfinder *thisa; // esi@1
  void *v2; // ecx@1

  thisa = this;
  v2 = this->field_2414;
  if ( v2 )
    KBFree(v2, (int)"F:\\h2xsrc\\Source\\FINDPATH.CPP", word_5124EC + 1);
  thisa->field_2414 = 0;
  thisa->field_2414 = (PathfindingInfo *)KBAlloc(
                                           9 * mapHeight * mapWidth,
                                           "F:\\h2xsrc\\Source\\FINDPATH.CPP",
                                           word_5124C8 + 2);
}
