function OnMapStart()
	SetDaysAfterTownLost(GetPlayer(0), 128)
	SetDaysAfterTownLost(GetPlayer(1), 128)
	GiveResource(GetPlayer(1), RESOURCE_GEMS, 10)
    ForceComputerPlayerChase(GetHero(GetPlayer(1), 0), GetHero(GetPlayer(0), 0), true)
end

function OnCastleConquered(CastleId, PlayerId)
	if CastleId == 0 and PlayerId == 0 then
		SetTownFaction(GetTown(0), FACTION_CYBORG)
	end
end

function OnNewDay(month, week, day)
	if month == 1 and week == 2 and day == 1 then
		TeleportHero(GetHero(GetPlayer(1), 0), 8, 11);
	end
end