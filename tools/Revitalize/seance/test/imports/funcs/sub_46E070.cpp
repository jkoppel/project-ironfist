{
  signed int result; // eax@4
  void *v4; // [sp+10h] [bp-10h]@1
  signed int v5; // [sp+1Ch] [bp-4h]@1

  v4 = a2;
  v5 = 1;
  switch ( byte_51257C )
  {
    case 1:
    case 2:
      if ( dword_512598 )
      {
        if ( sub_404DB0(byte_526DC8) )
        {
          v5 = sub_46DDB0(v4);
          goto LABEL_18;
        }
        result = 0;
      }
      else
      {
        if ( dword_51259C )
        {
          if ( sub_45F860(byte_526DC8) )
          {
            v5 = sub_46DDB0(v4);
            goto LABEL_18;
          }
          result = 0;
        }
        else
        {
          if ( sub_472F80(0x10Au, byte_526DC8) )
          {
            v5 = sub_46DDB0(v4);
            goto LABEL_18;
          }
          result = 0;
        }
      }
      break;
    case 3:
    case 4:
      if ( sub_464980() )
      {
        v5 = sub_46DDB0(v4);
        goto LABEL_18;
      }
      result = 0;
      break;
    default:
LABEL_18:
      result = v5;
      break;
  }
  return result;
}
