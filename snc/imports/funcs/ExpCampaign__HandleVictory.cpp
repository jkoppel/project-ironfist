{
  bool result; // eax@10
  int v2; // [sp+10h] [bp-Ch]@1
  int i; // [sp+14h] [bp-8h]@11
  __int16 v4; // [sp+18h] [bp-4h]@1

  v2 = this;
  v4 = 0;
  if ( *(_DWORD *)(this + 4) > -1 )
  {
    v4 = ExpCampaign::Days(this);
    *(_BYTE *)(*(_DWORD *)(v2 + 4) + v2 + 20) = 1;
  }
  memset((void *)(v2 + 12), 0, *(_DWORD *)(v2 + 8));
  switch ( *(_DWORD *)v2 )
  {
    case 0:
      ExpCampaign::HandleVictory1(v2);
      break;
    case 1:
      ExpCampaign::HandleVictory2(v2);
      break;
    case 2:
      ExpCampaign::HandleVictory3(v2);
      break;
    case 3:
      ExpCampaign::HandleVictory4(v2);
      break;
    default:
      break;
  }
  if ( ExpCampaign::IsCompleted(v2) )
  {
    result = 0;
  }
  else
  {
    *(_DWORD *)(v2 + 4) = -1;
    for ( i = 0; *(_DWORD *)(v2 + 8) > i; ++i )
    {
      if ( *(_BYTE *)(i + v2 + 12) )
      {
        *(_WORD *)(v2 + 2 * i + 28) = v4;
        if ( *(_DWORD *)(v2 + 4) == -1 )
          *(_DWORD *)(v2 + 4) = i;
      }
    }
    ExpCampaign::ShowInfo(v2, 0, 0);
    result = gpWindowManager->buttonPressedCode == 30722;
  }
  return result;
}