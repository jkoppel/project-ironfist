{
  signed int result; // eax@2
  unsigned __int8 Buffer; // [sp+10h] [bp-4h]@1

  if ( com_rcv(0, 1u, &Buffer) == 1 )
    result = Buffer;
  else
    result = -1;
  return result;
}