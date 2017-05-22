hero_mt = {
	__newindex = function (table, key, value)
		if key == "name" then
			MessageBox("name set")
			SetHeroName(table, value)
		elseif key == "owner" then
			MessageBox("owner set")
			SetHeroOwner(table, value)
		end
	end,
	__index = function (t, k)
		if k == "name" then
			MessageBox("name return")
			return GetHeroName(t)
		elseif k == "owner" then
			MessageBox("owner return")
			return GetHeroOwner(t)
		end
	end
}