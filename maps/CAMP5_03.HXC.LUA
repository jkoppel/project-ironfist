function OnCastleConquered(CastleId, PlayerId)
	if CastleId == 3 and PlayerId == 0 then
		GrantSpell(GetCurrentHero(), SPELL_SUMMON_BOAT);
		SetTownFaction(GetTown(3), FACTION_CYBORG)
	end
end