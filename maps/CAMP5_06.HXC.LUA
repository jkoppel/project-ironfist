mymodule = require "scripts.modules.niftysnippets_1"

bridges = {["1"] = false, ["2"] = false, ["3"] = false}; 
locksGet = {["1"] = false, ["2"] = false};

mapVariables = {"bridges", "locksGet"};

math.randomseed(os.time())

function OnHeroMove(x, y)
	if GetHeroOwner(GetCurrentHero()).color ~= 0 then
		if x == 57 and y == 28 then
			if bridges["2"] == false then
				TeleportHero(GetCurrentHero(), 57, 32);
			end
		end
		return;
	end
	
	if locksGet["1"] == false or locksGet["2"] == false then
		if locksGet["1"] == false then
			if x == 12 and y == 15 then
				locksGet["1"] = true;
				MessageBox("1st lock GET!");
			end
		end
		
		if locksGet["2"] == false then
			if x == 96 and y == 18 then
				locksGet["2"] = true;
				MessageBox("2nd lock GET!");
			end
		end
		
		if locksGet["1"] == true and locksGet["2"] == true then
			if bridges["2"] == false then
				CreateSecondBridge();
				bridges["2"] = true;
				MessageBox("built second bridgo");
			end
		end
	end
end;

function OnCastleConquered(CastleId, PlayerId)
	if PlayerId ~= 0 then
		return;
	end
	
	if bridges["1"] == false then
		if GetTownOwner(GetTown(GetTownIdFromPos(50,81))) == 0 and
		   GetTownOwner(GetTown(GetTownIdFromPos(64,81))) == 0 then		
				CreateFirstBridge();
				bridges["1"] = true;
				MessageBox("built first bridgo");
		end
	end
	
	if bridges["3"] == false then
		if GetTownOwner(GetTown(GetTownIdFromPos(51,17))) == 0 and
		   GetTownOwner(GetTown(GetTownIdFromPos(54,23))) == 0 and
		   GetTownOwner(GetTown(GetTownIdFromPos(65,17))) == 0 and
		   GetTownOwner(GetTown(GetTownIdFromPos(62,23))) == 0 then			
				CreateThirdBridge();
				bridges["3"] = true;
				MessageBox("built third bridgo");
		end
	end	
end;

function CreateFirstBridge()
	MapSetTileTerrain(54, 72, 7);
	MapSetTileTerrain(55, 72, 331, MAP_CELL_FLIP_HORIZONTALLY);
	MapSetTileTerrain(56, 72, 330);
	MapSetTileTerrain(57, 72, 8, MAP_CELL_FLIP_HORIZONTALLY);
	 
	MapSetTileTerrain(54, 73, 10);
	MapSetTileTerrain(55, 73, 329, MAP_CELL_FLIP_HORIZONTALLY);
	MapSetTileTerrain(56, 73, 332);
	MapSetTileTerrain(57, 73, 9, MAP_CELL_FLIP_HORIZONTALLY);
	
	MapSetTileTerrain(54, 74, 8);
	MapSetTileTerrain(55, 74, 332, MAP_CELL_FLIP_HORIZONTALLY);
	MapSetTileTerrain(56, 74, 329);
	MapSetTileTerrain(57, 74, 9, MAP_CELL_FLIP_HORIZONTALLY);
	
	MapSetTileTerrain(54, 75, 7, MAP_CELL_FLIP_VERTICALLY);
	MapSetTileTerrain(55, 75, 330, MAP_CELL_FLIP_HORIZONTALLY);
	MapSetTileTerrain(56, 75, 331);
	MapSetTileTerrain(57, 75, 6, MAP_CELL_FLIP_HORIZONTALLY + MAP_CELL_FLIP_VERTICALLY);
end;

function CreateSecondBridge()
	for i = 55, 59 do
	    for j = 29, 32 do
			offset = 246 + math.random(0,15);
			MapSetTileTerrain(i, j, offset);
		end
	end
end;

function CreateThirdBridge()
	for i = 55, 59 do
	    for j = 10, 13 do
			offset = 246 + math.random(0,15);
			MapSetTileTerrain(i, j, offset);
		end
	end
end;