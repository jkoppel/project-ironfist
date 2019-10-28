-- function OnArtifactGive(hero, id) -- new
	-- if id == ARTIFACT_GIANT_FLAIL_OF_DOMINION then
		-- hero.attack += 1; -- new
	-- end;
-- end;

-- function OnArtifactTake(hero, id) -- new
	-- if id == ARTIFACT_GIANT_FLAIL_OF_DOMINION then
		-- hero.attack -= 1; -- new
	-- end;
-- end;

function OnNewDay(month, week, day)
	currentPlayer = GetCurrentPlayer();
	for i = 0, 7, 1 do
		h = GetHero(currentPlayer, i);
		-- num = GetNumArtifacts(h, ARTIFACT_TAX_LIEN); -- new
		num = 1;
	end;
	if num >= 1 then
		MessageBox("Yo -250 gold for ya");
		GiveResource(currentPlayer, RESOURCE_GOLD, -250 * num);
	end;
end;

-- function OnCalcMobility(hero) -- new
	-- if HasArtifact(h, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY) then
		-- hero.mobility += 300; -- new
	-- end;
-- end;

-- function OnGetLuck(hero) -- new
	-- if HasArtifact(h, ARTIFACT_MASTHEAD) then
		-- return 1;
	-- end;
	-- return -1;
-- end;

-- function OnGetMorale(hero) -- new
	-- if HasArtifact(h, ARTIFACT_MASTHEAD) then
		-- return 1;
	-- end;
	-- return -1;
-- end;

-- function OnGetLuckInfo(hero) -- new
	-- if HasArtifact(h, ARTIFACT_MASTHEAD) then
		-- return "Masthead bonus at sea +1";
	-- end;
	-- return '';
-- end;

-- function OnGetMoraleInfo(hero) -- new
	-- if HasArtifact(h, ARTIFACT_MASTHEAD) then
		-- return "Masthead bonus at sea +1";
	-- end;
	-- return '';
-- end;