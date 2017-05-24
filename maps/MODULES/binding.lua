hero_mt = {
	__newindex = function (table, key, value)
		if key == "name" then
			MessageBox("name set")
			SetHeroName(table, value)
		elseif key == "owner" then
			MessageBox("Changing hero owner is not implemented yet")
			SetHeroOwner(table, value)
		elseif key == "spellpoints" then
			MessageBox("spellpoints set")
			SetSpellpoints(table, value)
		elseif key == "level" then
			MessageBox("Changing hero level is not implemented yet")
		end
	end,
	__index = function (t, k)
		if k == "name" then
			MessageBox("name return")
			return GetHeroName(t)
		elseif k == "owner" then
			MessageBox("owner return")
			return GetHeroOwner(t)
		elseif k == "spellpoints" then
			MessageBox("spellpoints return")
			return GetSpellpoints(t)
		elseif k == "level" then
			MessageBox("level return")
			return GetHeroLevel(t)
		end
	end
}