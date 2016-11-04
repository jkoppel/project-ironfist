{
  Pathfinder *thisa; // edi@1
  int hi; // ebx@2
  int low; // ecx@2
  PathfindingInfo *v8; // ebp@4
  int mid; // eax@7
  PathfindingInfo *goalPInfo; // esi@7
  int v11; // ecx@13
  int v12; // eax@13
  char v13; // cl@15
  char v14; // al@15

  thisa = this;
  if ( checkHexGridIdxBounds(sourceHex) )
  {
    hi = thisa->field_0;
    low = 0;
    if ( speed <= 0 || speed >= a4 )
    {
      v8 = &thisa->field_2414[sourceHex];
      if ( !(v8->field_4 & 1) || v8->field_2 > a4 )
      {
        if ( thisa->field_0 < 0x400u )
        {
          while ( 1 )
          {
            mid = (low + hi) / 2;
            goalPInfo = &thisa->mainDataStructure[mid];
            if ( hi <= low )
              break;
            if ( thisa->mainDataStructure[mid].field_2 <= a4 )
              hi = (low + hi) / 2;
            else
              low = mid + 1;
          }
          if ( (unsigned int)mid < thisa->field_0 )
            memcpy_0(
              (void *)(thisa->field_0 - mid),
              (int)&thisa->mainDataStructure[mid + 1],
              &thisa->mainDataStructure[mid + 1],
              &thisa->mainDataStructure[mid],
              9 * (thisa->field_0 - mid));
          v11 = thisa->field_4;
          v12 = thisa->field_0 + 1;
          thisa->field_0 = v12;
          if ( v11 < (unsigned int)v12 )
            thisa->field_4 = v12;
          v13 = 16 * neighborIdx;
          goalPInfo->field_0 = sourceHex;
          goalPInfo->field_1 = 0;
          goalPInfo->field_4 = v13 ^ (v13 ^ goalPInfo->field_4) & 0xF;
          goalPInfo->field_2 = a4;
          v14 = v8->field_4 | 1;
          v8->field_4 = v14;
          v8->field_4 = v13 ^ (v14 ^ v13) & 0xF;
          v8->field_2 = a4;
        }
      }
    }
  }
}
