local locations = {}
AdvMessageBox = require "scripts.modules.AdvMessageBox"

function locations.CyborgUpgradeLocation()
	h = GetCurrentHero()
	goblins = tonumber(GetCreatureAmount(h, CREATURE_GOBLIN)) or 0
	-- someone else
	pikemen = tonumber(GetCreatureAmount(h, CREATURE_PIKEMAN)) or 0
	if (goblins + pikemen) == 0 then
		AdvMessageBox.DoubleImage("{Hill Fort}\n\nAn unusual alliance of Cyborgs to train (upgrade) Pikemen and Goblins.  Unfortunately, you have none with you.",
	  1, IMAGE_GROUP_UNIT, CREATURE_PIKEMAN, IMAGE_GROUP_UNIT, CREATURE_GOBLIN)
	else
		if goblins > 0 then 
			TakeTroop(h, CREATURE_GOBLIN, goblins)
			GrantArmy(h, CREATURE_CYBER_KOBOLD_SPEARMAN, goblins)
		end
		-- someone else
		if pikemen > 0 then
			TakeTroop(h, CREATURE_PIKEMAN, pikemen)
			GrantArmy(h, CREATURE_CYBER_PLASMA_LANCER, pikemen)
		end
		PlaySoundEffect('EXPERNCE')
		if goblins > 0 and pikemen > 0 then
			AdvMessageBox.DoubleImage("{Hill Fort}\n\nAll of your Pikemen and Goblins have been upgraded to Cyborg Plasma Lancers and Cyborg Kobold Spearmen", 1, IMAGE_GROUP_UNIT, CREATURE_CYBER_PLASMA_LANCER, IMAGE_GROUP_UNIT, CREATURE_CYBER_KOBOLD_SPEARMAN)
		elseif goblins > 0 then
			AdvMessageBox.SingleImage("{Hill Fort}\n\nAll of your Goblins have been upgraded to Cyborg Kobold Spearmen", 1, IMAGE_GROUP_UNIT, CREATURE_CYBER_KOBOLD_SPEARMAN)
		elseif pikemen > 0 then
			AdvMessageBox.SingleImage("{Hill Fort}\n\nAll of your Pikemen have been upgraded to Cyborg Plasma Lancers", 1, IMAGE_GROUP_UNIT, CREATURE_CYBER_PLASMA_LANCER)
		end
	end
	return true
end

return locations