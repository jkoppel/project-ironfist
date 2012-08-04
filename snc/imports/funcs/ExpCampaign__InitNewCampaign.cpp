{
  int v2; // ST0C_4@1

  v2 = this;
  *(_DWORD *)this = a2;
  *(_DWORD *)(this + 4) = -1;
  *(_DWORD *)(this + 8) = dword_512A30[a2];
  ExpCampaign::ResetMapChoices(this);
  ExpCampaign::ResetMapsPlayed(v2);
  ExpCampaign::ResetAwards(v2);
  return ExpCampaign::ResetBonusChoices(v2);
}