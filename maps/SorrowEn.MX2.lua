function OnMapStart()
	p = GetPlayer(0);
	h = GetHero(p, 0);
	GrantSpell(h, SPELL_METEOR_SHOWER);
	SetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE, 10);
	SetSpellpoints(h, 100);
	SetSecondarySkill(h, SECONDARY_SKILL_LEADERSHIP, 1);
	SetSecondarySkill(h, SECONDARY_SKILL_WISDOM, 3);
	
	p2 = GetPlayer(1);
	h2 = GetHero(p2, 0);
	GrantArmy(h2, CREATURE_BONE_DRAGON, 10);
end;

function OnTownOpen(t)
	if t.name == "Sorrow's End" then
		if HasVisitingHero(t) then
			h = GetVisitingHero(t);
			if HasArtifact(h, ARTIFACT_MAGES_RING_OF_POWER) then
				TakeArtifact(h, ARTIFACT_MAGES_RING_OF_POWER);
				MessageBox("The Mage's Ring fits easily in the keyhole of the sealed library door. Inside lie shelves packed with tomes.");
				SetGuildSpell(t, 4, 0, SPELL_DIMENSION_DOOR);
				SetGuildSpell(t, 4, 1, SPELL_SUMMON_WATER_ELEMENTAL);
				SetGuildSpell(t, 4, 2, SPELL_SUMMON_EARTH_ELEMENTAL);
				SetGuildSpell(t, 4, 3, SPELL_RESURRECT_TRUE);
				BuildInCurrentTown(BUILDING_MAGE_GUILD); 
				BuildInCurrentTown(BUILDING_MAGE_GUILD);
				BuildInCurrentTown(BUILDING_MAGE_GUILD);
				BuildInCurrentTown(BUILDING_MAGE_GUILD);
				BuildInCurrentTown(BUILDING_MAGE_GUILD);
				SetNumGuildSpells(t, 0, 4); 
				SetNumGuildSpells(t, 1, 4);
				SetNumGuildSpells(t, 2, 4);
				SetNumGuildSpells(t, 3, 4); 
				SetNumGuildSpells(t, 4, 4);
			end;
		end;
	end;
end;
