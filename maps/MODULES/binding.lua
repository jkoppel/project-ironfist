hero_mt = {
	__newindex = function (table, key, value)
		if key == "name" then
			SetHeroName(table, value)
		elseif key == "owner" then
			MessageBox("Changing hero owner is not implemented yet")
		elseif key == "spellpoints" then
			SetSpellpoints(table, value)
		elseif key == "level" then
			MessageBox("Changing hero level is not implemented yet")
		end
	end,
	__index = function (t, k)
		if k == "name" then
			return GetHeroName(t)
		elseif k == "owner" then
			return GetHeroOwner(t)
		elseif k == "spellpoints" then
			return GetSpellpoints(t)
		elseif k == "level" then
			return GetHeroLevel(t)
		end
	end
}

town_mt = {
	__newindex = function (table, key, value)
		if key == "name" then
			SetTownName(table, value)
		elseif key == "owner" then
			SetTownOwner(table, value)
		elseif key == "faction" then
			SetTownFaction(table, value)
		end
	end,
	__index = function (t, k)
		if k == "name" then
			return GetTownName(t)
		elseif k == "owner" then
			return GetTownOwner(t)
		elseif k == "faction" then
			return GetTownFaction(t)
		end
	end
}

player_mt = {
	__newindex = function (table, key, value)
		
	end,
	__index = function (t, k)
		
	end
}
}