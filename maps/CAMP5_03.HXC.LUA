function OnCastleConquered(CastleId, PlayerId)
	if CastleId == 3 and PlayerId == 0 then
		GrantSpell(GetCurrentHero(), SPELL_SUMMON_BOAT);
	end
end