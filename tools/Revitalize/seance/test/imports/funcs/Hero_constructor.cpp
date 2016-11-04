{
  Hero *v1; // ST0C_4@1

  v1 = this;
  ArmyInfo_constructor(&this->army);
  v1->field_2 = 0;
  v1->probablyOwnerIdx = 0;
  v1->x = 0;
  v1->y = 0;
  v1->factionID = 0;
  v1->heroID = 0;
  v1->name[0] = 0;
  heroWindow = 0;
  dword_523428 = -1;
  return v1;
}
