bool __fastcall sub_4AA210(signed int a1)
{
  bool result; // eax@2
  signed int tracknum; // [sp+Ch] [bp-Ch]@1
  unsigned __int32 startmsec; // [sp+10h] [bp-8h]@6
  unsigned __int32 endmsec; // [sp+14h] [bp-4h]@6

  tracknum = a1;
  if ( dword_51D4A8 )
  {
    if ( a1 >= 1 && a1 <= 43 )
    {
      AIL_redbook_track_info(dword_51D4A8, a1, &startmsec, &endmsec);
      result = *(_DWORD *)&aOrigdata_bin_1[8 * tracknum + 8] == startmsec
            && *(_DWORD *)&aOrigdata_bin_1[8 * tracknum + 12] == endmsec;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
