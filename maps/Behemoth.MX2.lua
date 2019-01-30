SetDaysAfterTownLost(GetPlayer(0), 30);
function OnMapStart()
  GrantArmy(GetHero(GetPlayer(0), 0), CREATURE_CYBER_BEHEMOTH, 1);
end;