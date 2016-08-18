Trigger(MAP_START, NULL, "OnMapStart");
Trigger(NEW_DAY, "", "DayFunc");
Trigger(BATTLE_START, "", "OnBattleStart");
Trigger(BATTLE_ATTACK_MELEE, NULL, "OnBattleAttack");
Trigger(MAP_VICTORY, "", "VictoryMessage");

Trigger(HERO_MOVE, "7,25", "SwampEnter");
Trigger(HERO_MOVE, "8,25", "SwampEnter");
Trigger(HERO_MOVE, "31,24", "SwampEnter");
Trigger(HERO_MOVE, "32,24", "SwampEnter");
Trigger(HERO_MOVE, "34,24", "SwampEnter");
Trigger(HERO_MOVE, "35,24", "SwampEnter");
Trigger(HERO_MOVE, "2,12", "BadlandsEnter");
Trigger(HERO_MOVE, "3,12", "BadlandsEnter");
Trigger(HERO_MOVE, "4,12", "BadlandsEnter");
Trigger(HERO_MOVE, "29,13", "PortalEnter");
Trigger(HERO_MOVE, "16,11", "PortalEnter");
Trigger(HERO_MOVE, "17,3", "NecropolisEnter");

Trigger(HERO_MOVE, "35,25", "ShrineVisit");
Trigger(HERO_MOVE, "1,23", "ShrineVisit2");
Trigger(HERO_MOVE, "9,7", "ShrineVisit3");

Trigger(HERO_MOVE, "32,26", "DruidCircleVisit");
Trigger(HERO_MOVE, "5,34", "AlchemistVisit");
Trigger(HERO_MOVE, "18,18", "WitchVisit");
Trigger(HERO_MOVE, "31,35", "WindmillVisit");
Trigger(HERO_MOVE, "5,17", "HermitVisit");
Trigger(HERO_MOVE, "27,16", "WoodHouseVisit");
Trigger(HERO_MOVE, "24,7", "WoodHouse2Visit");
Trigger(HERO_MOVE, "30,2", "EyeVisit");
Trigger(HERO_MOVE, "0,10", "Eye2Visit");
Trigger(HERO_MOVE, "1,25", "TowerVisit");
Trigger(HERO_MOVE, "11,22", "CastleVisit");
Trigger(HERO_MOVE, "21,16", "GraveyardVisit");
Trigger(HERO_MOVE, "28,20", "WellVisit");
Trigger(HERO_MOVE, "27,29", "ColosseumVisit");
Trigger(HERO_MOVE, "17,31", "HomeReached");

Trigger(VISIT_CAMPFIRE, "14,19", "CampfireVisit");
Trigger(VISIT_CAMPFIRE, "35,23", "Campfire2Visit");
Trigger(VISIT_CAMPFIRE, "32,18", "Campfire3Visit");

shrineVisited = {false, false, false, false, false};
shrineVisited2 = {false, false, false, false, false};
shrineVisited3 = {false, false, false, false, false};
-- shrineVisited[1] = {false, false, false, false, false};
-- shrineVisited[2] = {false, false, false, false, false};

descriptionShown = 0;
oldWeek = 0;
homeReachedShown = 0;
swampEntered = 0;
badlandsEntered = 0;
druidCircleVisited = 0;
alchemistLabVisited = 0;
witchVisited = 0;
windmillVisited = 0;
hermitVisited = 0;
woodHouseVisited = 0;
woodHouse2Visited = 0;
eyeVisited = 0;
eye2Visited = 0;
towerVisited = 0;
castleVisited = 0;
graveyardVisited = 0;
wellVisited = 0;
campfireVisited = 0;
campfire2Visited = 0;
campfire3Visited = 0;
colosseumVisited = 0;
mapVariables = {"shrineVisited", "shrineVisited2", "shrineVisited3",
                "descriptionShown", "oldWeek", "homeReachedShown", "swampEntered", "badlandsEntered", "druidCircleVisited", "alchemistLabVisited",
                "witchVisited", "windmillVisited", "hermitVisited", "woodHouseVisited", "woodHouse2Visited", "eyeVisited", "eye2Visited",
				"towerVisited", "castleVisited", "graveyardVisited", "wellVisited", "campfireVisited", "campfire2Visited", "campfire3Visited",
				"colosseumVisited"};

function OnMapStart()
	ToggleAIArmySharing(0);
	if descriptionShown == 0 then
		MessageBox("The evil Necromancer Lord Varuun has been planning a take over the entire region. He is now preparing his final strike against the kingdom with his Legion of Doom. He has raised an alarming number of undead of all kinds, from simple zombies and ghouls as the cannon fodder, to giant skeleton dragons!");
		MessageBox("You are the last line of defence in the region. As the Protector of the Realm, it is your duty to amass an army strong and united to stand against the forces of the evil Lord.");
		MessageBox("You had been adventuring in the wilderness when you first heard the news about the evil Lord. After riding back as fast you could, you have finally arrived back to your castle. Gather the aid of the local castles, with reason or charm if possible or force if necessary. Your campaign begins.");
		descriptionShown = 1;
	end
end;

function HomeReached()
	if homeReachedShown == 0 then
		MessageBox("You have reached your home castle finally after so many nights in the wild, but alas it seems that in your absence Lord Varuun has overrun the castle with his zombie troops. You must free the castle to start your campaign.");
		homeReachedShown = 1;
	end
end;

function VictoryMessage()
	MessageBox("Congratulations!");
	MessageBox("Lord Varuun looks at you in despise, shouting \"you may have won this battle, but you will never win the war - we will meet again!\". He raises his hands and a cloud of smoke appears around him. When it clears out, he is no longer there.");
	MessageBox("You climb up the tower, searching every corner, but the evil lord is nowhere to be found. The lord and his armies are defeated! The sky clears and your army roars in honor of the great victory. Everyone is finally relieved as the great evil necromancer lord is no more!");
	MessageBox("You and your allies return home and celebrate your victory with a marvelous feast. The entire kingdom celebrates the miraculous victory.");
	MessageBox("You are granted the Hero’s Star, the highest honor and decoration any protector can receive!");
	MessageBox("Your only concern is knowing that one day you will have to face the necromancer again...");
end;

function DayFunc()
	day = GetDay();
	week = GetWeek();
	
	if day == 0 and week == 0 then
		oldWeek = 0;
	end
	
	if oldWeek ~= week then
		WeekFunc();
	end
	oldWeek = week;
	
	-- Allow mystery hero to live forever without a castle
	SetDaysAfterTownLost(GetPlayer(2), 7);
end;

function WeekFunc()
	mon = GetMonth();
	week = GetWeek();
-- Give army to the enemy
	if mon == 1 then
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
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_SKELETON, (mon * 4 + week) * 50);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_VAMPIRE, (mon * 4 + week) * 2);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_LICH, (mon * 4 + week) * 2);
		GrantArmy(GetHero(GetPlayer(1), 0), CREATURE_BONE_DRAGON, 1);
	end
	
	for i = 0, 5 do
		shrineVisited[i] = false;
		shrineVisited2[i] = false;
		shrineVisited3[i] = false;
	end
end;

function PortalEnter()
	if GetHeroOwner(GetCurrentHero()) == 0 then
		MessageBox("An odd magical structure is carved into a stone wall in the mountain in front of you. When you come closer, strange carvings of a long gone language are revealed. As you near your hand, they start glowing and when you touch the symbols your entire body starts to shake. Then a portal opens and sucks you into a limbo, dropping you on the other side of the mountain.");
	end
end;

function NecropolisEnter()
	if GetHeroOwner(GetCurrentHero()) == 0 then
		MessageBox("Lord Varuun is standing at the top of his tower, laughing. \"So you are the thorn in my backside - you will pay for your insolence!\". He laughs again, motioning his hands in the air. The air sparkles and turns into a heavy black mist rolling away from him. The mist passes like a titlewave through the entire castle, and as it clears out a huge horde of undead skeletons and zombies rises.");
		MessageBox("The lord laughs even harder when he raises his scepter and emits a shockwave. The ground trembles and a huge skeleton dragon breaks out, dropping several zombies and skeletons as he ascends angry and restless.");
	end
end;

function SwampEnter()
	if GetHeroOwner(GetCurrentHero()) == 0 and swampEntered == 0 then
		swampEntered = 1;
		MessageBox("Beware! The swamps are filled with hungry creatures roaming around. Watch your steps and stick to the road.");
	end
end;

function BadlandsEnter()
	if GetHeroOwner(GetCurrentHero()) == 0 and badlandsEntered == 0 then
		badlandsEntered = 1;
		MessageBox("Beware! The evil lord sees all and hears all. No one escapes his grasp - not in life and certainly not in death!");
	end
end;

function EyeVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and eyeVisited == 0 then
		MessageBox("The All Seeing Eye structure gazes upon you - as if an extension of the evil lord's sight. As soon as you approach a horde of zombies attacks you.");
		if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 12, 1) == 1 then
			eyeVisited = 1;
		end
	end
end;

function Eye2Visit()
	if GetHeroOwner(GetCurrentHero()) == 0 and eye2Visited == 0 then
		MessageBox("The All Seeing Eye structure glances at you. Once you get closer it summons zombies from the ground.");
		if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 12, 1) == 1 then
			eye2Visited = 1;
		end
	end
end;

function TowerVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and towerVisited == 0 then
		MessageBox("You have stumbled upon a ruined tower. In it there are several zombies hungry for fresh meat!");
		if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 9, 1) == 1 then
			towerVisited = 1;
		end
	end
end;

function CastleVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and castleVisited == 0 then
		MessageBox("There’s a great castle ahead, but it's filled with undead monsters. It seems that the Lord has been busy in your absence.");
		if StartBattle(GetCurrentHero(), CREATURE_SKELETON, 47, 1) == 1 then
			castleVisited = 1;
		end
	end
end;

function GraveyardVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and graveyardVisited == 0 then
		MessageBox("At the graveyard there are many ghouls ready to venture out into the nearby settlements. Will you help them?");
		if StartBattle(GetCurrentHero(), CREATURE_GHOST, 23, 1) == 1 then
			graveyardVisited = 1;
		end
	end
end;

function WellVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and wellVisited == 0 then
		MessageBox("As you approach a small well in the middle of a swamp, a swarm of hungry ghouls climb out of the well, attacking you on sight!");
		if StartBattle(GetCurrentHero(), CREATURE_GHOST, 13, 1) == 1 then
			wellVisited = 1;
		end
	end
end;

function WindmillVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and windmillVisited == 0 then
		windmillVisited = 1;
		h = GetCurrentHero();
		GrantSpell(h, SPELL_HASTE);
		MessageBox("You reach a windmill near a small lake. The wizard there offers to teach you the spell \"Haste\".");
	end
end;

function HermitVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and hermitVisited == 0 then
		hermitVisited = 1;
		h = GetCurrentHero();
		GrantArtifact(h, ARTIFACT_FIRE_CLOAK);
		MessageBox("You approach a lone house amongst the old swamp trees. An old hermit greets you and invites you in for dinner and rest. After a long philosophical discussion, he offers you a gift for your Journey into the fiery badlands.");
	end
end;

function ColosseumVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and colosseumVisited == 0 then
		MessageBox("You have a chance to enlist the mighty barbarian warriors to your cause, but first you must defeat them in battle, to show your worth. Only then they will join you!");
		if StartBattle(GetCurrentHero(), CREATURE_OGRE, 5, 1) == 1 then
			GrantArmy(GetCurrentHero(), CREATURE_OGRE, 10);
			colosseumVisited = 1;
		end
	end
end;

function CampfireVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and campfireVisited == 0 then
		campfireVisited = 1;
		h = GetCurrentHero();
		GrantArmy(h, CREATURE_SWORDSMAN, 10);
		MessageBox("A few adventurers gather around a campfire in the swamps area. Impressed with you and your party, they offer to join your cause.");
	end
end;

function Campfire2Visit()
	if GetHeroOwner(GetCurrentHero()) == 0 and campfire2Visited == 0 then
		campfire2Visited = 1;
		h = GetCurrentHero();
		GrantArmy(h, CREATURE_SWORDSMAN, 10);
		GrantArmy(h, CREATURE_CAVALRY, 10);
		MessageBox("You spot a campsite nearby. Shadowy figures gather around a big bonfire. When you approach, you see that these are a few soldiers and rangers preparing their dinner while singing songs. Silence drops as you approach, but when they recognize that you’re not one of the dead, they happily invite you to join.");
		MessageBox("After a long wonderful night they offer to join your campaign against the evil lord.");
	end
end;

function Campfire3Visit()
	if GetHeroOwner(GetCurrentHero()) == 0 and campfire3Visited == 0 then
		campfire3Visited = 1;
		h = GetCurrentHero();
		MessageBox("You come across a campsite in the middle of the swamp. Getting closer you manage to notice several corpses in sleeping bags and tents. Seems they found their demise during their sleep.");
		MessageBox("Once getting closer the corpses raise up and attack you!");
		StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 13, 1);
	end
end;

function WoodHouseVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and woodHouseVisited == 0 then
		woodHouseVisited = 1;
		h = GetCurrentHero();
		GrantArtifact(h, ARTIFACT_DRAGON_SWORD_OF_DOMINION);
		MessageBox("Still in the swamps region, you stumble upon a large wooden house. It seems to have been recently abandoned, but wait! Something is glistening inside. You go in and discover a great sword - as if it was placed there for you to find.");
	end
end;

function WoodHouse2Visit()
	if GetHeroOwner(GetCurrentHero()) == 0 and woodHouse2Visited == 0 then
		woodHouse2Visited = 1;
		h = GetCurrentHero();
		GrantArtifact(h, ARTIFACT_GOLDEN_BOW);
		MessageBox("An abandoned wooden house in the midst of the swamps. As you approach you spot something glistening inside. It's a magical bow - lying there as if it was waiting for you to discover.");
	end
end;

function DruidCircleVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and druidCircleVisited == 0 then
		druidCircleVisited = 1;
		h = GetCurrentHero();
		GrantArtifact(h, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY);
		MessageBox("You stumble upon a droid circle. The old druid there, foretelling your arrival, grants you this as a gift, to aid you on your journey.");
	end
end;

function AlchemistVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and alchemistLabVisited == 0 then
		alchemistLabVisited = 1;
		h = GetCurrentHero();
		GrantArmy(h, CREATURE_RANGER, 10);
		MessageBox("You reach a small estate. The owner of the house, a rich nobleman, acknowledges the merits of your efforts by offering you aid and giving you some of his best archers");
	end
end;

function WitchVisit()
	if GetHeroOwner(GetCurrentHero()) == 0 and witchVisited == 0 then
		witchVisited = 1;
		h = GetCurrentHero();
		
		MessageBox("You come across a wooden house in the middle of the swamp with a strange aura inside. " ..
		                "The witch who resides there offers to sell you a necklace, and says it will bring you fortune.");
						
		result = QuestionBox("Do you wish to buy the necklace (1000 Gold)?");
		
		if result then
		    gold = GetResource(GetPlayer(0), RESOURCE_GOLD);
			gold = gold - 1000;
			if gold < 0 then
			    MessageBox("The witch stomps her feet. \"Come back when you can afford it.\"");
				witchVisited = 0;
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
	if BattleHasHero(0) and BattleHasHero(1) and GetHeroName(BattleGetHero(1)) == "Mystery Hero" then
		MessageBox("Now we finally meet!");
	end
	if BattleHasHero(0) and BattleHasHero(1) and GetHeroName(BattleGetHero(1)) == "Lord Varuun" then
		lord = GetHero(GetPlayer(1), 0);
		phero = GetCurrentHero();
		SetPrimarySkill(lord, PRIMARY_SKILL_ATTACK, GetPrimarySkill(phero, PRIMARY_SKILL_ATTACK));
		SetPrimarySkill(lord, PRIMARY_SKILL_DEFENSE, GetPrimarySkill(phero, PRIMARY_SKILL_DEFENSE));
		SetPrimarySkill(lord, PRIMARY_SKILL_SPELLPOWER, GetPrimarySkill(phero, PRIMARY_SKILL_SPELLPOWER));
		SetPrimarySkill(lord, PRIMARY_SKILL_KNOWLEDGE, GetPrimarySkill(phero, PRIMARY_SKILL_KNOWLEDGE));
		
		SetSecondarySkill(lord, SECONDARY_SKILL_ARCHERY, GetSecondarySkill(phero, SECONDARY_SKILL_ARCHERY));
		SetSecondarySkill(lord, SECONDARY_SKILL_LEADERSHIP, GetSecondarySkill(phero, SECONDARY_SKILL_LEADERSHIP));
		SetSecondarySkill(lord, SECONDARY_SKILL_WISDOM, GetSecondarySkill(phero, SECONDARY_SKILL_WISDOM));
		SetSecondarySkill(lord, SECONDARY_SKILL_LUCK, GetSecondarySkill(phero, SECONDARY_SKILL_LUCK));
		SetSpellpoints(lord, GetSpellpoints(phero));
	end
end;

function ShrineVisit()
	h = GetCurrentHero();
	p = GetSpellpoints(h);
	o = GetHeroOwner(h);
	kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
	maxPoints = kno * 10;
	if p >= maxPoints or shrineVisited[o] == true then
		if o == 0 then
			MessageBox("You already feel refreshed to use magic");
		end
	else
		p = p + 10;
		if p > maxPoints then
			p = maxPoints;
		end
		SetSpellpoints(h, p);
		if o == 0 then
			MessageBox("You feel very refreshed. Your mana is restored.");
		end
	end
	shrineVisited[o] = true;
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