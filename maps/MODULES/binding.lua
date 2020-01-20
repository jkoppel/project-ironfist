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
		elseif key == "tempMoraleBonuses" then
			SetHeroTempMoraleBonuses(table, value)
		elseif key == "tempLuckBonuses" then
			SetHeroTempLuckBonuses(table, value)
		elseif key == "mobility" then
			SetHeroMobility(table, value)
		elseif key == "remainingMobility" then
			SetHeroRemainingMobility(table, value)
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
		elseif k == "tempMoraleBonuses" then
			return GetHeroTempMoraleBonuses(t)
		elseif k == "tempLuckBonuses" then
			return GetHeroTempLuckBonuses(t)
		elseif k == "mobility" then
			return GetHeroMobility(t)
		elseif k == "remainingMobility" then
			return GetHeroRemainingMobility(t)
		elseif k == "x" then
			return GetHeroX(t)
		elseif k == "y" then
			return GetHeroY(t)
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
		elseif k == "x" then
			return GetTownX(t)
		elseif k == "y" then
			return GetTownY(t)
		elseif k == "visitingHero" then
			return GetVisitingHero(t)
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
			SetStackQuantity(table, value)
		elseif key == "initialQuantity" then
			SetStackInitialQuantity(table, value)
		elseif key == "hex" then
			MessageBox("Changing stack hex is not implemented yet")
		elseif key == "morale" then
			SetStackMorale(table, value)
		elseif key == "luck" then
			SetStackLuck(table, value)
		elseif key == "attack" then
			SetStackAttack(table, value)
		elseif key == "defense" then
			SetStackDefense(table, value)
		elseif key == "speed" then
			SetStackSpeed(table, value)
		elseif key == "shots" then
			SetStackShots(table, value)
		elseif key == "hp" then
			SetStackHp(table, value)
		else
			MessageBox("This field is not supported")
		end
	end,
	__index = function (t, k)
		if k == "side" then
			return GetStackSide(t)
		elseif k == "type" then
			return GetStackType(t)
		elseif k == "creatureType" then
			return GetStackType(t)
		elseif k == "quantity" then
			return GetStackQuantity(t)
		elseif k == "initialQuantity" then
			return GetStackInitialQuantity(t)
		elseif k == "hex" then
			return GetStackHex(t)
		elseif k == "morale" then
			return GetStackMorale(t)
		elseif k == "luck" then
			return GetStackLuck(t)
		elseif k == "attack" then
			return GetStackAttack(t)
		elseif k == "defense" then
			return GetStackDefense(t)
		elseif k == "speed" then
			return GetStackSpeed(t)
		elseif k == "shots" then
			return GetStackShots(t)
		elseif k == "hp" then
			return GetStackHp(t)
		else
			MessageBox("This field is not supported")
		end
	end
}

campaignChoice_mt = {
	__newindex = function (table, key, value)
		MessageBox("Setting campaign choice is not supported")
	end,
	__index = function (t, k)
		if k == "type" then
			return GetCampaignChoiceType()
		elseif k == "field" then
			return GetCampaignChoiceField()
		elseif k == "amount" then
			return GetCampaignChoiceAmount(t)
		else
			MessageBox("This field is not supported")
		end
	end
}