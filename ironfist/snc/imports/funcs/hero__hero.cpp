{
  hero *v1; // ST0C_4@1

  v1 = this;
  armyGroup::armyGroup(&this->army);
  v1->couldBeHeroIdx = 0;
  v1->probablyOwnerIdx = 0;
  v1->x = 0;
  v1->y = 0;
  v1->factionID = 0;
  v1->heroID = 0;
  v1->name[0] = 0;
  heroWin = 0;
  giHeroScreenSrcIndex = -1;
  return v1;
}