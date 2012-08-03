{
  heroWindowManager *result; // eax@7

  switch ( *(_DWORD *)this )
  {
    case 0:
      ExpCampaign::ReplaySmacker1((int)this);
      break;
    case 1:
      ExpCampaign::ReplaySmacker2((int)this);
      break;
    case 2:
      ExpCampaign::ReplaySmacker3((int)this);
      break;
    case 3:
      ExpCampaign::ReplaySmacker4((int)this);
      break;
    default:
      break;
  }
  result = gpWindowManager;
  gpWindowManager->field_56 = 1;
  return result;
}