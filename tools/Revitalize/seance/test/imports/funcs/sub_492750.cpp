{
  int arr[7]; // [sp+14h] [bp-3Ch]@10
  char v3; // [sp+30h] [bp-20h]@9
  __int16 v4; // [sp+34h] [bp-1Ch]@1
  int i; // [sp+38h] [bp-18h]@10
  int v6; // [sp+3Ch] [bp-14h]@1
  int a3; // [sp+40h] [bp-10h]@9
  int v8; // [sp+44h] [bp-Ch]@10
  signed int slot; // [sp+48h] [bp-8h]@9
  int creatureType; // [sp+4Ch] [bp-4h]@2

  v6 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v4 = (signed __int16)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  switch ( v6 )
  {
    case 0:
      creatureType = 59;
      break;
    case 1:
      creatureType = 62;
      break;
    case 2:
      creatureType = 63;
      break;
    case 3:
      creatureType = 64;
      break;
    case 4:
      creatureType = 65;
      break;
    default:
      break;
  }
  if ( v4 )
  {
    sub_4B36D0(creatureType, v4, 0, (int)&a3, (int)&v3, (int)&slot);
    if ( a3 > 0 )
    {
      addCreaturesToArmy((ArmyInfo *)(a2 + 101), creatureType, a3, slot);
      v4 -= a3;
      v8 = v6 | 8 * v4;
      *(_WORD *)(a1 + 4) = 8 * (v6 | (unsigned __int16)(8 * v4)) | *(_WORD *)(a1 + 4) & 7;
      getCreatureCosts(creatureType, arr);
      for ( i = 0; i < 7; ++i )
        curPlayer->resources[i] -= a3 * arr[i];
    }
  }
}
