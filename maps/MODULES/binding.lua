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
		else
			MessageBox("This field is not supported")
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
		else
			MessageBox("This field is not supported")
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
		else
			MessageBox("This field is not supported")
		end
	end,
	__index = function (t, k)
		if k == "name" then
			return GetTownName(t)
		elseif k == "owner" then
			return GetTownOwner(t)
		elseif k == "faction" then
			return GetTownFaction(t)
		else
			MessageBox("This field is not supported")
		end
	end
}

player_mt = {

	__newindex = function (table, key, value)
		if key == "daysLeftWithoutCastle" then
			SetDaysAfterTownLost(table, value);
		else
			MessageBox("This field is not supported");
		end
	end,
	__index = function (t, k)
		if k == "color" then
			return GetPlayerColor(t);
		elseif k == "numHeroes" then
			return GetNumHeroes(t);
		elseif k == "daysLeftWithoutCastle" then
			return GetDaysAfterTownLost(t);
		else
			MessageBox("This field is not supported");
		end
	end
}

battleStack_mt = {
	__newindex = function (table, key, value)
		if key == "side" then
			MessageBox("Changing stack side is not implemented yet")
		elseif key == "type" then
			MessageBox("Changing stack type is not implemented yet")
		elseif key == "quantity" then
			MessageBox("Changing stack quantity is not implemented yet")
		elseif key == "hex" then
			MessageBox("Changing stack hex is not implemented yet")
		else
			MessageBox("This field is not supported")
		end
	end,
	__index = function (t, k)
		if k == "side" then
			return GetStackSide(t)
		elseif k == "type" then
			return GetStackType(t)
		elseif k == "quantity" then
			return GetStackQuantity(t)
		elseif k == "hex" then
			return GetStackHex(t)
		else
			MessageBox("This field is not supported")
		end
	end
}