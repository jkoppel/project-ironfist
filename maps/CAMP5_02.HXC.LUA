locations = require "scripts.modules.locations_1"
peasantsVisited = false
goblinsLeft = 10
mapVariables = {"peasantsVisited", "goblinsLeft"};

function OnMapStart()
	SetDaysAfterTownLost(GetPlayer(0), 128)
	SetDaysAfterTownLost(GetPlayer(1), 128)
	GiveResource(GetPlayer(1), RESOURCE_GEMS, 10)
	ForceComputerPlayerChase(GetHero(GetPlayer(1), 0), GetHero(GetPlayer(0), 0), true)
	MessageBox("Beset by memories of the future, Lt. John Carver awoke to find himself in a strange new land. Although disoriented, he managed to make out a distant chatter before his cochlear implant shortened out. None of his other implants seemed to fare much better, a likely consequence of whatever magic was used to hurl him through time.")
	MessageBox("He allowed the rumblings to lead him to a small village. Wary of how frightening he might look with his cybernetic implants, he resisted rushing forward long enough to notice the approach of a robed figure. The warlock demanded to know if the villagers had seen any strangers with metallic body parts. When it became clear they knew nothing, he unleashed great balls of fire and lightning that spared none a painful death.");
	MessageBox("Getting home would not be as easy as John hoped with a madman like that hunting him, but with any luck, there would be more than a few warlock-hating locals about, and perhaps his comrades were also flung through time and were out there somewhere, waiting to be found. This wouldn't be easy, but then nothing in John Carver's life ever was.");
	SetInclinedToJoin(23, 2, true)
	SetInclinedToJoin(22, 21, true)
	SetInclinedToJoin(20, 51, true)
	SetInclinedToJoin(46, 71, true)
	SetInclinedToJoin(61, 4, true)
end

function OnCastleConquered(CastleId, PlayerId)
	if CastleId == 0 and PlayerId == 0 then
		SetTownFaction(GetTown(0), FACTION_CYBORG)
	end
end

function OnLocationVisit(type, x, y)
	if x == 29 and y == 32 then
		return locations.CyborgUpgradeLocation()
	elseif x == 18 and y == 31 then
		if goblinsLeft > 0 then
			MessageBox("You can buy goblins here")
			h = GetCurrentHero()
			oldGoblins = tonumber(GetCreatureAmount(h, CREATURE_GOBLIN)) or 0
			RecruitBox(GetCurrentHero(), CREATURE_GOBLIN, goblinsLeft)
			newGoblins = tonumber(GetCreatureAmount(h, CREATURE_GOBLIN)) or 0
			goblinsLeft = goblinsLeft - (newGoblins - oldGoblins)
		else
			MessageBox("The hut is empty")
		end
		return true
	elseif x == 12 and y == 10 then
		if peasantsVisited == false then 
			MessageBox("A group of bereaved Peasants who watched the warlock slaughter their neighbors wish to join you. Do you accept?")
			GrantArmy(GetCurrentHero(), CREATURE_PEASANT, 30)
		end
		peasantsVisited = true
		return true
	elseif x == 18 and y == 12 then
		MessageBox("Cloverdale - Population 168")
		return true
	elseif x == 24 and y == 19 then
		MessageBox("Cloverdale - West\nMeridith's Trading Post - North\nGrimsby Castle - South")
		return true
	elseif x == 15 and y == 26 then
		MessageBox("Cloverdale - North\nMeridith's Trading Post - North\nGrimsby Castle - South")
		return true
	elseif x == 26 and y == 32 then
		MessageBox("Danger! - East\nCloverdale - West\nGrimsby Castle - South")
		return true
	elseif x == 22 and y == 43 then
		MessageBox("Scenic Route - West\nSpeedster's Route - South")
		return true
	elseif x == 24 and y == 60 then
		MessageBox("Cloverdale - West\nGrimsby Castle - East")
		return true
	elseif x == 31 and y == 61 then
		MessageBox("Tennent's Observation Tower")
		return true
	elseif x == 46 and y == 58 then
		MessageBox("Grimsby Castle - East\nCloverdale - West\nRiches Aplenty - North (Strangely, this appears to be freshly carved.)")
		return true
	elseif x == 60 and y == 55 then
		MessageBox("Grimsby Castle - North\nSarton's Stables - South\nOlec's Trading Post - Across the River")
		return true
	elseif x == 65 and y == 37 then
		MessageBox("Grimsby Castle - North\nSarton's Stables - South")
		return true
	elseif x == 59 and y == 48 then
		MessageBox("Lundy's Sawmill - West")
		return true
	end
end

function OnMonsterInteract(x, y)
	if GetCurrentHero().owner.color ~= 0 then
		return true
	end
	if x == 22 and y == 21 then
		MessageBox("It's good to see you, sir. We feared you were dead. We haven't seen any of the others, but a nasty looking bunch passed by recently talking about hunting cybernetic men. They were headed south. What are your orders?")
	elseif x == 23 and y == 2 then
		MessageBox("Steady your axes men, it's just the lieutenant! Sorry sir, we've all been on edge since waking up in this strange place by ourselves, but if you're here, maybe the others made it too.")
	elseif x == 20 and y == 51 then
		MessageBox("Sir, are we glad to see you! We've had a rough time since being thrown through that time portal. We lost some good men just trying to get this far, but we suspected that the others also made it through after spotting two flares in the night sky. One came from the southeast, the other from the northeast.")
	elseif x == 46 and y == 71 then
		MessageBox("You sure took your sweet time. We set off a flare ages ago, and one went off north of here shortly after. Was that you?")
	elseif x == 61 and y == 4
	then
		MessageBox("I knew you'd come. Let's do this.")
	end
end

function OnBattleStart()
	if BattleHasHero(0) and BattleHasHero(1) and BattleGetHero(1).name == "Scouting" then
		MessageBox("John Carver... and friends. That was unexpected. Still, if I were you, I'd surrender now  . Even if I fail to defeat you in combat, I will have slowed you down enough to ensure my master finishes you off, so it's in your best interest to simply surrender now. His army far surpasses this small scouting party of mine, but if you're insistent on making this difficult, so be it.")
	end
end
