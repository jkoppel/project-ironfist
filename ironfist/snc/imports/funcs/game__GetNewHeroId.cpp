{
  game *thisa; // [sp+Ch] [bp-18h]@1
  signed int tries; // [sp+14h] [bp-10h]@1
  int heroIdx; // [sp+20h] [bp-4h]@1

  thisa = this;
  heroIdx = -1;
  tries = 0;
  while ( tries < 2000 )
  {
    ++tries;
    heroIdx = Random(0, 53);
    if ( thisa->relatedToHeroForHireStatus[heroIdx] == -1 || thisa->relatedToHeroForHireStatus[heroIdx] == 64 )
    {
      if ( (thisa->relatedToHeroForHireStatus[heroIdx] != 64 || tries >= 1500)
        && (faction < 0 || faction > 5 || tries >= 100 || thisa->heroes[heroIdx].factionID == faction)
        && (!getPowerfulHero
         || tries >= 40
         || thisa->heroes[heroIdx].experience >= 1000
         || thisa->heroes[heroIdx].artifacts[0] != -1 && thisa->heroes[heroIdx].artifacts[0] != ARTIFACT_MAGIC_BOOK
         || thisa->heroes[heroIdx].artifacts[1] != -1 && thisa->heroes[heroIdx].artifacts[1] != ARTIFACT_MAGIC_BOOK) )
      {
        if ( !gbInCampaign || tries >= 500 || thisa->heroes[heroIdx].heroID < 54 || thisa->heroes[heroIdx].heroID > 59 )
          break;
      }
    }
  }
  return heroIdx;
}