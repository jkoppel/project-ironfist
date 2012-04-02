int __cdecl zero_out_stack_affected_list()
{
  int result; // eax@5
  signed int i; // [sp+10h] [bp-8h]@1
  spellpower_offset j; // [sp+14h] [bp-4h]@3

  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < MAX_STACKS; ++j )
    {
      result = 20 * i;
      stack_affected_by_aoe[i][j] = 0;
    }
  }
  return result;
}
