{
  combatManager *thisa; // [sp+18h] [bp-40h]@1
  H2RECT str; // [sp+1Ch] [bp-3Ch]@10
  icon *icn; // [sp+2Ch] [bp-2Ch]@2
  int l; // [sp+30h] [bp-28h]@17
  int i; // [sp+34h] [bp-24h]@2
  army *creat; // [sp+38h] [bp-20h]@19
  int a2; // [sp+3Ch] [bp-1Ch]@20
  int j; // [sp+40h] [bp-18h]@4
  int y; // [sp+44h] [bp-14h]@6
  int v10; // [sp+48h] [bp-10h]@15
  int x; // [sp+4Ch] [bp-Ch]@8
  int k; // [sp+50h] [bp-8h]@15
  int harmedAnyone; // [sp+54h] [bp-4h]@15

  thisa = this;
  if ( !gbNoShowCombat )
  {
    icn = resourceManager::GetIcon(gpResourceManager, "storm.icn");
    for ( i = 0; i < 6; ++i )
    {
      for ( j = 0; j < 10; ++j )
      {
        glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 75.0);
        combatManager::DrawFrame(thisa, 0, 0, 0, 0, 75, 1, 1);
        for ( y = 0; y < 10; ++y )
        {
          for ( x = 0; x < 12; ++x )
            icon::CombatClipDrawToBuffer(icn, 54 * x, 54 * y, (y + j + 3 * x) % 10, &str, 0, 0, 0, 0);
        }
        combatManager::UpdateCombatArea(thisa);
        DelayTil(&glTimers);
      }
    }
    resourceManager::Dispose(gpResourceManager, (resource *)icn);
  }
  combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
  harmedAnyone = 0;
  v10 = 25 * thisa->heroSpellpowers[thisa->currentActionSide];
  for ( k = 0; k < 2; ++k )
  {
    for ( l = 0; thisa->numCreatures[k] > l; ++l )
    {
      creat = &thisa->creatures[k][l];
      if ( army::SpellCastWorks(&thisa->creatures[k][l], SPELL_ELEMENTAL_STORM) )
      {
        a2 = v10;
        if ( creat->creatureIdx == CREATURE_AIR_ELEMENTAL )
          a2 *= 2;
        if ( creat->creatureIdx == CREATURE_IRON_GOLEM || creat->creatureIdx == CREATURE_STEEL_GOLEM )
          a2 = (signed __int64)((double)a2 * 0.5);
        if ( thisa->heroes[k] && hero::HasArtifact(thisa->heroes[k], ARTIFACT_BROACH_OF_SHIELDING) )
          a2 = (signed __int64)((double)a2 * 0.5);
        army::Damage(creat, a2, SPELL_ELEMENTAL_STORM);
        harmedAnyone = 1;
      }
    }
  }
  if ( harmedAnyone )
  {
    sprintf(gText, "The elemental storm does %d damage.", v10);
    combatManager::CombatMessage(thisa, gText, 1, 1, 0);
    army::PowEffect(creat, -1, 1, -1, -1);
  }
}