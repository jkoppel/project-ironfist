function OnMapStart()
	SetDaysAfterTownLost(GetPlayer(0), 128)
    ForceComputerPlayerChase(GetHero(GetPlayer(1), 0), GetHero(GetPlayer(0), 0), true)
end

function OnCastleConquered(CastleId, PlayerId)
	if CastleId == 0 and PlayerId == 0 then
		SetTownFaction(GetTown(0), FACTION_CYBORG)
	end
end