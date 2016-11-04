{
  Castle *result; // eax@15
  signed int v2; // [sp+10h] [bp-Ch]@1
  signed int i; // [sp+14h] [bp-8h]@1
  int j; // [sp+14h] [bp-8h]@6
  char *v5; // [sp+18h] [bp-4h]@1

  v5 = (char *)&gameObject->players[this->ownerIdx];
  v2 = -1;
  for ( i = 0; gameObject->players[this->ownerIdx].numCastles > i; ++i )
  {
    if ( v5[i + 71] == this->idx )
      v2 = i;
  }
  for ( j = v2; v5[68] - 1 > j; ++j )
    v5[j + 71] = v5[j + 72];
  v5[v5[68] + 70] = -1;
  if ( this->idx == v5[69] )
    v5[69] = -1;
  --v5[68];
  if ( v5[68] >= 5 )
  {
    if ( v5[70] + 5 > v5[68] )
      v5[70] = v5[68] - 5;
  }
  else
  {
    v5[70] = 0;
  }
  gameObject->_7[this->idx] = -1;
  result = this;
  this->ownerIdx = -1;
  return result;
}
