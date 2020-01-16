mymodule = require "scripts.modules.niftysnippets_1"

excSites = {
{4, 6},
{63, 5},
{104, 42},
{13, 58},
{7, 95},
{70, 102},
{103, 96}
}

sitesTaken = {
["1"] = false,
["2"] = false,
["3"] = false,
["4"] = false,
["5"] = false,
["6"] = false,
["7"] = false,
}

specialSite = -1

mapVariables = {"sitesTaken", "specialSite"}

math.randomseed(os.time())

function OnNewDay(month, week, day)
	if month == 2 and week == 2 and day == 5 then
		availableSites = {}
		i = 1
		for index, value in pairs(sitesTaken) do
			if value == false then
				availableSites[i] = tonumber(index)
				i = i + 1
			end
		end
		specialSite = math.random(1, #availableSites)
		SpecialSiteMessage(specialSite)
	end
end

function OnLocationVisit(type, x, y)
	if type == LOCATION_DESERT_TENT then
		site = GetExcavationSiteID(x, y)
		if site == -1 then
			return false
		end
		if sitesTaken[tostring(site)] == true then
			MessageBox("You've already excavated this")
			return true
		end
		
		if StartBattle(GetCurrentHero(), CREATURE_VAMPIRE, 30, 0) == 0 then
			MessageBox("Graz successful excavation")
			sitesTaken[tostring(site)] = true
			
			if IsEverythingExcavated() or specialSite == site then
				MessageBox("Finally you get Iron Fist")
				GrantArtifact(GetCurrentHero(), ARTIFACT_IRON_FIST);				
			end
		end
		return true
	end
end

function GetExcavationSiteID(x, y)
	for index = 1, #excSites do
		if excSites[index][1] == x and excSites[index][2] == y then
			return index
		end
	end
	return -1
end

function IsEverythingExcavated()
	for index, value in pairs(sitesTaken) do
		if value == false then
			return false
		end
	end
	return true
end

function SpecialSiteMessage(site)
	direction = 'somewhere'
	if site == 1 then direction = 'northwest'
	elseif site == 2 then direction = 'north'
	elseif site == 3 then direction = 'east'
	elseif site == 4 then direction = 'west'
	elseif site == 5 then direction = 'southwest'
	elseif site == 6 then direction = 'south'
	elseif site == 7 then direction = 'southeast'
	end
	MessageBox("John Carver feels the force from the " .. direction)
end