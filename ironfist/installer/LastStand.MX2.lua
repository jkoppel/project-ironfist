
Trigger(MAP_START, "", "FixHeroName");
Trigger(NEW_DAY, "", "DayFunc");
Trigger(BATTLE_START, "", "OnBattleStart");
-- Trigger(HERO_MOVE, NULL, "OnHeroMove");
Trigger(HERO_MOVE, "35,25", "ShrineVisit");
Trigger(HERO_MOVE, "1,23", "ShrineVisit2");
Trigger(HERO_MOVE, "9,7", "ShrineVisit3");

Trigger(HERO_MOVE, "32,26", "DruidCircleVisit");
Trigger(HERO_MOVE, "5,34", "AlchemistVisit");
Trigger(HERO_MOVE, "18,18", "WitchVisit");

Trigger(HERO_MOVE, "7,25", "SwampEnter");
Trigger(HERO_MOVE, "31,24", "SwampEnter");
Trigger(HERO_MOVE, "32,24", "SwampEnter");
Trigger(HERO_MOVE, "34,24", "SwampEnter");
Trigger(HERO_MOVE, "35,24", "SwampEnter");
Trigger(HERO_MOVE, "2,12", "BadlandsEnter");
Trigger(HERO_MOVE, "3,12", "BadlandsEnter");
Trigger(HERO_MOVE, "4,12", "BadlandsEnter");
Trigger(BATTLE_ATTACK_MELEE, NULL, "OnBattleAttack");

shrineVisited = {false, false, false, false, false};
shrineVisited2 = {false, false, false, false, false};
shrineVisited3 = {false, false, false, false, false};
-- shrineVisited[1] = {false, false, false, false, false};
-- shrineVisited[2] = {false, false, false, false, false};

druidCircleVisited = "0";
alchemistLabVisited = "0";
witchVisited = "0";
swampEntered = "0";
badlandsEntered = "0";

mapVariables = {"druidCircleVisited", "alchemistLabVisited", "witchVisited", "swampEntered", "badlandsEntered" };
-- mapVariables = {"shrineVisited"};

function SwampEnter()
	if swampEntered == "0" then
		swampEntered = "1";
		MessageBox("Beware! The swamps are filled with hungry creatures roaming around. Watch your steps and stick to the road.");
	end
end;

function BadlandsEnter()
	if badlandsEntered == "0" then
		badlandsEntered = "1";
		MessageBox("Beware! The evil lord sees all and hears all; no one escapes his grasp not in life and certainly not in death!");
	end
end;

function DruidCircleVisit()
	if "0" == druidCircleVisited then
		druidCircleVisited = "1";
		h = GetCurrentHero();
		GrantArtifact(h, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY);
		MessageBox("You have stumbled upon a droid circle and the old druid there foretelling "
					.. "your arrival has granted you these Boots of Travel as a gift to aid you on your journey!")
	end
end;

function AlchemistVisit()
	if "0" == alchemistLabVisited then
		alchemistLabVisited = "1";
		h = GetCurrentHero();
		GrantArmy(h, CREATURE_RANGER, 10);
		MessageBox("You have reached a small alchemist lab. The owner of the lab is a rich nobleman who " ..
		             "has seen the merits of your efforts and offers to aid you by giving you some of his best archers.");
	end
end;

function WitchVisit()
	if "0" == witchVisited then
		witchVisited = "1";
		h = GetCurrentHero();
		
		MessageBox("You come across a wooden house in the middle of the swamp with a strange aura inside. " ..
		                "The witch who resides there offers to sell you a necklace, and says it will bring you fortune.");
						
		result = QuestionBox("Do you wish to buy the necklace (1000 Gold)?");
		
		if result then
		    gold = GetResource(GetPlayer(0), RESOURCE_GOLD);
			gold = gold - 1000;
			if gold < 0 then
			    MessageBox("The witch stomps her feet. \"Come back when you can afford it.\"");
				witchVisited = "0";
			else
				MessageBox("\"You have chosen well\" she says with a big-toothed grin, as she hands you a necklace from which a rabbit's foot dangles.");
				GrantArtifact(h, ARTIFACT_LUCKY_RABBITS_FOOT);
				SetResource(GetPlayer(0), RESOURCE_GOLD, gold);
			end
		else
			MessageBox("\"Foolish child to turn down a golden offer. I won't make it again.\"");
		end
	end
end;

function OnBattleAttack()
	st = __targetStack;
	
	if not (BattleHasHero(0) and BattleHasHero(1)) then
		return;
	end
	
	if GetStackSide(st) == 1 and GetStackType(st) == CREATURE_EARTH_ELEMENTAL then
	
		up_occupied = false;
		down_occupied = false;
		
		uphex = GetStackHex(st) - 13;
		-- MessageBox(tostring(uphex));
		if uphex < 0 then
			up_occupied = true;
		end
		downhex = GetStackHex(st) + 13;
		if downhex > 115 then
			down_occupied = true;
		end

		numStacks = BattleNumStacksForSide(0);
		for i = 0, numStacks do
			summonHex = GetStackHex(BattleGetStack(0,i));
			if summonHex == uphex then
				up_occupied = true;
			end
			if summonHex == downhex then
				down_occupied = true;
			end
		end
		
		numStacks = BattleNumStacksForSide(1);
		for i = 1, numStacks-1 do
			summonHex = GetStackHex(BattleGetStack(1,i));
			if summonHex == uphex then
				up_occupied = true;
			end
			if summonHex == downhex then
				down_occupied = true;
			end
		end

		if IsHexEmpty(uphex) == false then
			up_occupied = true;
		end
		if IsHexEmpty(downhex) == false then
			down_occupied = true;
		end
		if up_occupied == false then
			BattleSummonCreature(1, uphex, CREATURE_EARTH_ELEMENTAL, 1);
			BattleMessage("Earth elemental splits itself");
		end
		if down_occupied == false then
			BattleSummonCreature(1, downhex, CREATURE_EARTH_ELEMENTAL, 1);
			BattleMessage("Earth elemental splits itself");
		end
	end
end;

function OnBattleStart()
	-- if BattleHasHero(0) then
		-- MessageBox("For the king!");
	-- else
	if BattleHasHero(0) and BattleHasHero(1) and GetHeroName(BattleGetHero(1)) == "Mystery Hero" then
		MessageBox("Now we finally meet!");
	end
end;

function ShrineVisit()
end;

function ShrineVisit2()
	h = GetCurrentHero();
	p = GetSpellpoints(h);
	o = GetHeroOwner(h);
	kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
	maxPoints = kno * 10;
	if p >= maxPoints or shrineVisited2[o] == true then
		if o == 0 then
			MessageBox("You already feel refreshed to use magic");
		end
	else
		p = p + 20;
		if p > maxPoints then
			p = maxPoints;
		end
		SetSpellpoints(h, p);
		if o == 0 then
			MessageBox("You feel very refreshed. Your mana is restored.");
		end
	end
	shrineVisited2[o] = true;
end;

function ShrineVisit3()
	h = GetCurrentHero();
	p = GetSpellpoints(h);
	o = GetHeroOwner(h);
	kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
	maxPoints = kno * 10;
	if p >= maxPoints or shrineVisited3[o] == true then
		if o == 0 then
			MessageBox("You already feel refreshed to use magic");
		end
	else
		p = p + 30;
		if p > maxPoints then
			p = maxPoints;
		end
		SetSpellpoints(h, p);
		if o == 0 then
			MessageBox("You feel very refreshed. Your mana is restored.");
		end
	end
	shrineVisited3[o] = true;
end;

function OnHeroMove()
	--MessageBox("I move!");
	--MessageBox(tostring(GetCurrentHero()));
end;

-- Quick hack for release -- having problem changing names of heroes in editor
function FixHeroName()
	SetHeroName(GetHero(GetPlayer(1), 0), "Lord Varuun");
end;

function DayFunc()
	if day == 0 and week == 0 then
		oldWeek = 0;
	end
	
	week = GetWeek();
	if oldWeek ~= week then
		WeekFunc();
	end
	oldWeek = week;
	
	-- Allow mystery hero to live forever without a castle
	SetDaysAfterTownLost(GetPlayer(2), 7);
end;

function WeekFunc()
	month = GetMonth();
-- Give army to the enemy
	if month == 1 then
		if week == 1 then
			GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_SKELETON, 50);
		elseif week == 2 then
			GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_VAMPIRE, 15);
		elseif week == 3 then
			GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_LICH, 10);
		elseif week == 4 then
			GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_BONE_DRAGON, 2);
		end
	else
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_SKELETON, (month * 4 + week) * 50);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_VAMPIRE, (month * 4 + week) * 2);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_LICH, (month * 4 + week) * 2);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_BONE_DRAGON, 1);
	end
	
	for i = 0, 5 do
		shrineVisited[i] = false;
		shrineVisited2[i] = false;
		shrineVisited3[i] = false;
	end
end;