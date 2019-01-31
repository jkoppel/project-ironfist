niftysnippets = require("scripts.modules.niftysnippets_1")
AdvMessageBox = require("scripts.modules.AdvMessageBox")

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

battleColosseumDone = 0;
campfireComeback = 0;
campfire2Comeback = 0;
battleAlchemistDone = 0;
firstWitchVisitDone = 0;

mapVariables = {"shrineVisited", "shrineVisited2", "shrineVisited3",
                "descriptionShown", "oldWeek", "homeReachedShown", "swampEntered", "badlandsEntered", "druidCircleVisited", "alchemistLabVisited",
                "witchVisited", "windmillVisited", "hermitVisited", "woodHouseVisited", "woodHouse2Visited", "eyeVisited", "eye2Visited",
				"towerVisited", "castleVisited", "graveyardVisited", "wellVisited", "campfireVisited", "campfire2Visited", "campfire3Visited",
				"colosseumVisited",
				"battleColosseumDone", "campfireComeback", "campfire2Comeback", "battleAlchemistDone", "firstWitchVisitDone"};


function OnMapStart()
	ToggleAIArmySharing(0);
	if descriptionShown == 0 then
		MessageBox("The evil Necromancer Lord Varuun has been planning a take over of the entire region. He is now preparing his final strike against the kingdom with his Legion of Doom. He has raised an alarming number of undead of all kinds, from simple zombies and ghouls as the cannon fodder, to giant skeleton dragons!");
		MessageBox("You are the last line of defence in the region. As the Protector of the Realm, it is your duty to amass an army strong and united to stand against the forces of the evil Lord.");
		MessageBox("You had been adventuring in the wilderness when you first heard the news about the evil Lord. After riding back as fast you could, you have finally arrived back to your castle. Gather the aid of the local castles, with reason or charm if possible or force if necessary. Your campaign begins.");

		descriptionShown = 1;
	end
end

function OnHeroMove(x, y)
	if x == 7 and y == 25 or
		x == 8 and y == 25 or
		x == 31 and y == 24 or
		x == 32 and y == 24 or
		x == 34 and y == 24 or
		x == 35 and y == 24 then
		if GetCurrentHero().owner.color == 0 and swampEntered == 0 then
			swampEntered = 1;
			MessageBox("Beware! The swamps are filled with hungry creatures roaming around. Watch your steps and stick to the road.");
		end
	elseif x == 2 and y == 12 or
			x == 3 and y == 12 or
			x == 4 and y == 12 then
		if GetCurrentHero().owner.color == 0 and badlandsEntered == 0 then
			badlandsEntered = 1;
			MessageBox("Beware! The evil lord sees all and hears all. No one escapes his grasp - not in life and certainly not in death!");
		end
	elseif x == 29 and y == 13 or
			x == 16 and y == 11 then
		if GetCurrentHero().owner.color == 0 then
			MessageBox("An odd magical structure is carved into a stone wall in the mountain in front of you. When you come closer, strange carvings of a long gone language are revealed. As you near your hand, they start glowing and when you touch the symbols your entire body starts to shake. Then a portal opens and sucks you into a limbo, dropping you on the other side of the mountain.");
		end
	elseif x == 17 and y == 3 then
		if GetCurrentHero().owner.color == 0 then
			MessageBox("Lord Varuun is standing at the top of his tower, laughing. \"So you are the thorn in my backside - you will pay for your insolence!\". He laughs again, motioning his hands in the air. The air sparkles and turns into a heavy black mist rolling away from him. The mist passes like a titlewave through the entire castle, and as it clears out a huge horde of undead skeletons and zombies rises.");
			MessageBox("The lord laughs even harder when he raises his scepter and emits a shockwave. The ground trembles and a huge skeleton dragon breaks out, dropping several zombies and skeletons as he ascends angry and restless.");
		end
	elseif x == 35 and y == 25 then
		h = GetCurrentHero();
		p = GetSpellpoints(h);
		o = h.owner;
		kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
		maxPoints = kno * 10;
		if p >= maxPoints or shrineVisited[o] == true then
			if o == 0 then
				MessageBox("You already feel refreshed to use magic.");
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
	elseif x == 35 and y == 25 then
		h = GetCurrentHero();
		p = GetSpellpoints(h);
		o = h.owner;
		kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
		maxPoints = kno * 10;
		if p >= maxPoints or shrineVisited2[o] == true then
			if o == 0 then
				MessageBox("You already feel refreshed to use magic.");
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
	elseif x == 35 and y == 25 then
		h = GetCurrentHero();
		p = GetSpellpoints(h);
		o = h.owner;
		kno = GetPrimarySkill(h, PRIMARY_SKILL_KNOWLEDGE);
		maxPoints = kno * 10;
		if p >= maxPoints or shrineVisited3[o] == true then
			if o == 0 then
				MessageBox("You already feel refreshed to use magic.");
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
	elseif x == 32 and y == 26 or
	x == 33 and y == 26 then
		if GetCurrentHero().owner.color == 0 and druidCircleVisited == 0 then
			h = GetCurrentHero();
			if HasArtifact(h, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY) then
				MessageBox("You stumble upon a druid circle. The old druid there, foretelling your arrival, knows that you already have the Travelers's Boots of Mobility he wanted to give you. Instead, he gives you 3000 gold.");
				GiveResource(GetPlayer(0), RESOURCE_GOLD, 3000);
				druidCircleVisited = 1;
			else
				AdvMessageBox.SingleImage("You stumble upon a druid circle. The old druid there, foretelling your arrival, would like to grant you the Travelers's Boots of Mobility as a gift, to aid you on your journey.", DIALOG_OKAY, IMAGE_GROUP_ARTIFACTS, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY);
				if CountEmptyArtifactSlots(h) > 0 then
					GrantArtifact(h, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY);
					druidCircleVisited = 1;
				else
					MessageBox("Unfortunately, you have no free space in your inventory. The old druid says you can come back later to get the Travelers's Boots of Mobility.");
				end
			end
		end
	elseif x == 5 and y == 34 then
		if GetCurrentHero().owner.color == 0 and alchemistLabVisited == 0 then
			if battleAlchemistDone == 0 then
				MessageBox("You reach a small estate. The owner of the house, a rich nobleman, acknowledges the merits of your efforts by offering you aid and giving you some of his best archers.");
				battleAlchemistDone = 1
			end
			if battleAlchemistDone == 1 then
				GrantArmy(GetCurrentHero(), CREATURE_RANGER, 10);
				if HasTroop(GetCurrentHero(), CREATURE_RANGER, 10) == true then
					MessageBox("The Rangers join your ranks.");
					alchemistLabVisited = 1;
				else
					MessageBox("Milord, it seems your army is full. We will wait for your return here.");
				end
			end
		end
	elseif x == 31 and y == 35 then
		if GetCurrentHero().owner.color == 0 and windmillVisited == 0 then
			h = GetCurrentHero();
			if HasArtifact(h, ARTIFACT_MAGIC_BOOK) then
				windmillVisited = 1;
				GrantSpell(h, SPELL_HASTE);
				MessageBox("You reach a windmill near a small lake. The wizard there offers to teach you the spell \"Haste\".");
			else
				MessageBox("You reach a windmill near a small lake. The wizard there offers to teach you the spell \"Haste\". Unfortunately, you have no Magic Book to record the spell with. The wizard says you can come back later to learn the spell.");
			end
		end
	elseif x == 27 and y == 16 then
		if GetCurrentHero().owner.color == 0 and woodHouseVisited == 0 then
			h = GetCurrentHero();
			if HasArtifact(h, ARTIFACT_DRAGON_SWORD_OF_DOMINION) then

				MessageBox("Still in the swamps region, you stumble upon a large wooden house. It seems to have been recently abandoned, but wait! Something is glistening inside. You go in and discover a great sword and what seems to be a pile of gold for an amount of at least 3000 gold - as if they were placed there for you to find.");
				MessageBox("They are strongly trapped in the ground, and you don't want to waste your time to retrieve both of them, the undeads are waiting for you. So, you have to make a choice, the sword or the gold.");

				result = QuestionBox("Do you wish to free and keep the Dragon Sword of Dominion?");

				if result then
						if CountEmptyArtifactSlots(h) > 0 then
							GrantArtifact(h, ARTIFACT_DRAGON_SWORD_OF_DOMINION);
							MessageBox("You feel invincible, as soon you get the sword.");
							woodHouseVisited = 1;
						else
							MessageBox("Unfortunately, you have no free space in your inventory. You decide to come back later.");
							woodHouseVisited = 0;
						end
				else
					GiveResource(GetPlayer(0), RESOURCE_GOLD, 3000);
					MessageBox("You choose the gold and now you feel reassured to be able to recruit more troops for your quest.");
					woodHouseVisited = 1;
				end
			else
				AdvMessageBox.SingleImage("Still in the swamps region, you stumble upon a large wooden house. It seems to have been recently abandoned, but wait! Something is glistening inside. You go in and discover a great sword - as if it was placed there for you to find.", DIALOG_OKAY, IMAGE_GROUP_ARTIFACTS, ARTIFACT_DRAGON_SWORD_OF_DOMINION);
				if CountEmptyArtifactSlots(h) > 0 then
					GrantArtifact(h, ARTIFACT_DRAGON_SWORD_OF_DOMINION);
					woodHouseVisited = 1;
				else
					MessageBox("Unfortunately, you have no free space in your inventory. You decide to come back later to take the Dragon Sword of Dominion.");
				end
			end
		end
	elseif x == 24 and y == 7 then
		if GetCurrentHero().owner.color == 0 and woodHouse2Visited == 0 then
			h = GetCurrentHero();
			if HasArtifact(h, ARTIFACT_GOLDEN_BOW) then
				MessageBox("An abandoned wooden house is in the midst of the swamps. As you approach you spot something glistening inside. It's a magical bow - lying there as if it was waiting for you to discover. But, as you already have one, you decide to break it into pieces, and get 1000 gold from it.");
				GiveResource(GetPlayer(0), RESOURCE_GOLD, 1000);
				woodHouse2Visited = 1;
			else
				AdvMessageBox.SingleImage("An abandoned wooden house is the midst of the swamps. As you approach you spot something glistening inside. It's a magical bow - lying there as if it was waiting for you to discover.", DIALOG_OKAY, IMAGE_GROUP_ARTIFACTS, ARTIFACT_GOLDEN_BOW);
				if CountEmptyArtifactSlots(h) > 0 then
				    GrantArtifact(h, ARTIFACT_GOLDEN_BOW);
					woodHouse2Visited = 1;
				else
					MessageBox("Unfortunately, you have no free space in your inventory. You decide to come back later to take the Golden Bow.");
				end
			end
		end
	elseif x == 30 and y == 2 then
	if GetCurrentHero().owner.color == 0 and eyeVisited == 0 then
			MessageBox("The All Seeing Eye structure gazes upon you - as if an extension of the evil lord's sight. As soon as you approach a horde of zombies attacks you.");
			if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 12, 1) == 1 then
				eyeVisited = 1;
			end
		end
	elseif x == 0 and y == 10 then
	if GetCurrentHero().owner.color == 0 and eye2Visited == 0 then
			MessageBox("The All Seeing Eye structure glances at you. Once you get closer it summons zombies from the ground.");
			if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 12, 1) == 1 then
				eye2Visited = 1;
			end
		end
	elseif x == 1 and y == 25 then
	if GetCurrentHero().owner.color == 0 and towerVisited == 0 then
			MessageBox("You have stumbled upon a ruined tower. In it there are several zombies hungry for fresh meat!");
			if StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 9, 1) == 1 then
				towerVisited = 1;
			end
		end
	elseif x == 11 and y == 22 then
	if GetCurrentHero().owner.color == 0 and castleVisited == 0 then
			MessageBox("There's a great castle ahead, but it's filled with undead monsters. It seems that the Lord has been busy in your absence.");
			if StartBattle(GetCurrentHero(), CREATURE_SKELETON, 47, 1) == 1 then
				castleVisited = 1;
			end
		end
	elseif x == 21 and y == 16 then
		if GetCurrentHero().owner.color == 0 and graveyardVisited == 0 then
			MessageBox("At the graveyard there are many ghouls ready to venture out into the nearby settlements. Will you help them?");
			if StartBattle(GetCurrentHero(), CREATURE_GHOST, 23, 1) == 1 then
				graveyardVisited = 1;
			end
		end
	elseif x == 28 and y == 20 then
		if GetCurrentHero().owner.color == 0 and wellVisited == 0 then
			MessageBox("As you approach a small well in the middle of a swamp, a swarm of hungry ghouls climb out of the well, attacking you on sight!");
			if StartBattle(GetCurrentHero(), CREATURE_GHOST, 13, 1) == 1 then
				wellVisited = 1;
			end
		end
	elseif x == 27 and y == 29 then
		if GetCurrentHero().owner.color == 0 and colosseumVisited == 0 then
			if battleColosseumDone == 0 then
				MessageBox("You have a chance to enlist the mighty barbarian warriors to your cause, but first you must defeat them in battle, to show your worth, only then they will join you!");
			end
			if battleColosseumDone == 0 and StartBattle(GetCurrentHero(), CREATURE_OGRE, 5, 1) == 1 then
				battleColosseumDone = 1;
			end
			if GetCurrentHero().owner.color == 0 and battleColosseumDone == 1 then
				GrantArmy(GetCurrentHero(), CREATURE_OGRE, 10);
				if HasTroop(GetCurrentHero(), CREATURE_OGRE, 10) == true then
					MessageBox("The Ogres join your cause.");
					colosseumVisited = 1;
				else
					MessageBox("Milord, it seems your army is full, come back later to enlist the Ogres.");
				end
			end
		end
	elseif x == 17 and y == 31 then
		if homeReachedShown == 0 then
			MessageBox("You have reached your home castle finally after so many nights in the wild, but alas it seems that in your absence Lord Varuun has overrun the castle with his zombie troops. You must free the castle to start your campaign.");
			homeReachedShown = 1;
		end
	end
end

function OnLocationVisit(type, x, y)
	if x == 14 and y == 19 and type == LOCATION_CAMPFIRE then
		if GetCurrentHero().owner.color == 0 and campfireVisited == 0 then
		  campfireVisited = 1;
		  MessageBox("A few adventurers gather around a campfire in the swamps area. Impressed with you and your party, they offer to join your cause.");
		  if CountEmptyCreatureSlots(GetCurrentHero()) > 0 or HasTroop(GetCurrentHero(), CREATURE_SWORDSMAN, 1) then
			 GrantArmy(GetCurrentHero(), CREATURE_SWORDSMAN, 10);
		  else
			 MessageBox("Milord, it seems your army is full. We will wait for your return here.");
		  end
		end
		
		return true;
	elseif x == 35 and y == 23 and type == LOCATION_CAMPFIRE then
	    h = GetCurrentHero();
		if h.owner.color == 0 and campfire2Visited == 0 then
			MessageBox("Through the mist, you spot a campsite nearby. Shadowy figures gather around a big bonfire. When you approach, you see that these are a few soldiers and rangers preparing their dinner while singing songs. Silence drops as you approach, but when they recognize that you are not one of the dead, they happily invite you to join.");
			MessageBox("After a long wonderful night they offer to join your campaign against the evil lord.");
					if CountEmptyCreatureSlots(h) >= 2 or (HasTroop(h, CREATURE_SWORDSMAN, 1) and HasTroop(h, CREATURE_CAVALRY, 1)) then
					   GrantArmy(h, CREATURE_SWORDSMAN, 10);
					   GrantArmy(h, CREATURE_CAVALRY, 10);
					   campfire2Visited = 1;
			else
					   MessageBox ("My Lord, it seems there is not enough space in your army for both our troops, we will wait for your return here.");
			end
		end
		
		return false; -- TODO: Cancel normal event, but make disappear
	elseif x == 32 and y == 18 and type == LOCATION_CAMPFIRE then
		if GetCurrentHero().owner.color == 0 and campfire3Visited == 0 then
			campfire3Visited = 1;
			h = GetCurrentHero();
			MessageBox("You come across a campsite in the middle of the swamp. Getting closer you manage to notice several corpses in sleeping bags and tents. Seems they found their demise during their sleep.");
			MessageBox("Once getting closer the corpses raise up and attack you!");
			StartBattle(GetCurrentHero(), CREATURE_ZOMBIE, 13, 1);
		end
		
		return false; -- TODO: Cancel normal event, but make disappear
	elseif x == 18 and y == 18 and type == LOCATION_WITCH_HUT then
		if GetCurrentHero().owner.color == 0 and witchVisited == 0 then
			if firstWitchVisitDone == 0 then
				MessageBox("You come across a wooden house in the middle of the swamp with a strange aura inside.");
				firstWitchVisitDone = 1;
			end
			if HasArtifact(GetCurrentHero(), ARTIFACT_LUCKY_RABBITS_FOOT) then
				MessageBox("The witch who resides there, sees that you already have the necklace she wanted to sell you, and says you are really fortunate, smiling, she gives you 1000 gold.");
				GiveResource(GetPlayer(0), RESOURCE_GOLD, 1000);
				witchVisited = 1;
			else
				MessageBox("The witch who resides there offers to sell you a necklace, and says it will bring you fortune.");

				result = QuestionBox("Do you wish to buy the necklace (1000 Gold)?");

				if result then
					gold = GetResource(GetPlayer(0), RESOURCE_GOLD);
					gold = gold - 1000;
					if gold < 0 then
						MessageBox("The witch stomps her feet. \"Come back when you can afford it.\"");
						witchVisited = 0;
					else
						AdvMessageBox.SingleImage("\"You have chosen well\" she says with a big-toothed grin, as she hands you a necklace from which a rabbit's foot dangles.", DIALOG_OKAY, IMAGE_GROUP_ARTIFACTS, ARTIFACT_LUCKY_RABBITS_FOOT);
						GrantArtifact(GetCurrentHero(), ARTIFACT_LUCKY_RABBITS_FOOT);
						SetResource(GetPlayer(0), RESOURCE_GOLD, gold);
					end
					if HasArtifact(GetCurrentHero(), ARTIFACT_LUCKY_RABBITS_FOOT) then
						witchVisited = 1;
					else
						MessageBox("\"Your inventory seems full. My, my.\" she says with a smirk as she pockets your gold.");
						witchVisited = 1;
					end
				else
					MessageBox("\"Foolish child to turn down a golden offer. I won't make it again.\"");
					witchVisited = 1;
				end
			end
		end
		
		return true;
	elseif x == 5 and y == 17 and type ==LOCATION_WITCH_HUT then
		if GetCurrentHero().owner.color == 0 and hermitVisited == 0 then
			h = GetCurrentHero();
			if HasArtifact(h, ARTIFACT_FIRE_CLOAK) then
				MessageBox("You approach a lone house amongst the old swamp trees. An old hermit greets you and invites you in for dinner and rest. After a long philosophical discussion, he wanted to offer you a gift for your Journey into the fiery badlands. But he sees that you already have the Fire Cloack he wanted to give you, instead, he gives you 1000 gold.");
				GiveResource(GetPlayer(0), RESOURCE_GOLD, 1000);
				hermitVisited = 1;
			else
				GrantArtifact(h, ARTIFACT_FIRE_CLOAK);
				AdvMessageBox.SingleImage("You approach a lone house amongst the old swamp trees. An old hermit greets you and invites you in for dinner and rest. After a long philosophical discussion, he offers you a gift for your Journey into the fiery badlands.", DIALOG_OKAY, IMAGE_GROUP_ARTIFACTS, ARTIFACT_FIRE_CLOAK);
				if HasArtifact(h, ARTIFACT_FIRE_CLOAK) then
					hermitVisited = 1;
				else
					MessageBox("Unfortunately, you have no free space in your inventory. The old hermit says you can come back later to get the Fire Cloack.");
					hermitVisited = 0;
				end
			end
		end
		
		return true
	end
	
	return false;
end

function OnMapVictory()
	MessageBox("Congratulations!");
	MessageBox("Lord Varuun glares despisingly upon you, shouting \"you may have won this battle, but you will never win the war - we will meet again!\". He raises his hands and a cloud of smoke appears around him. When it clears out, he is no longer there.");
	MessageBox("You climb up the tower, searching every corner, but the evil lord is nowhere to be found. The lord and his armies are defeated! The sky clears and your army roars in honor of the great victory. Everyone is finally relieved as the great evil necromancer lord is no more!");
	MessageBox("You and your allies return home and celebrate your victory with a marvelous feast. The entire kingdom celebrates the miraculous victory.");
	MessageBox("You are granted the Hero's Star, the highest honor and decoration any protector can receive!");
	MessageBox("Your only concern is knowing that one day you will have to face the necromancer again...");
end;

function OnNewDay(month, week, day)
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

up_occupied = true
down_occupied = true
uphex = -1
downhex = -1

function OnBattleMeleeAttackComplete(attackerStack, targetStack)
	if up_occupied == false then
		BattleSummonCreature(1, uphex, CREATURE_EARTH_ELEMENTAL, 1);
		BattleMessage("Earth elemental splits itself.");
	end
	if down_occupied == false then
		BattleSummonCreature(1, downhex, CREATURE_EARTH_ELEMENTAL, 1);
		BattleMessage("Earth elemental splits itself.");
	end
	
	up_occupied = true
	down_occupied = true
end

function OnBattleMeleeAttack(attackerStack, targetStack, isRetaliation)
	st = targetStack;

	if not (BattleHasHero(0) and BattleHasHero(1)) then
		return;
	end
	
	if st.side == 1 and st.type == CREATURE_EARTH_ELEMENTAL and isRetaliation == false then
		up_occupied = false;
		down_occupied = false;

		uphex = GetStackHex(st) - 13;
		-- MessageBox(tostring(uphex));
		if uphex < 0 then
			up_occupied = true;
		end
		downhex = st.hex + 13;
		if downhex > 115 then
			down_occupied = true;
		end

		numStacks = BattleNumStacksForSide(0);
		for i = 0, numStacks do
			summonHex = BattleGetStack(0,i).hex;
			if summonHex == uphex then
				up_occupied = true;
			end
			if summonHex == downhex then
				down_occupied = true;
			end
		end

		numStacks = BattleNumStacksForSide(1);
		for i = 1, numStacks-1 do
			summonHex = BattleGetStack(1,i).hex;
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
	end
end;

function OnBattleStart()
	if BattleHasHero(0) and BattleHasHero(1) and BattleGetHero(1).name == "Mystery Hero" then
		MessageBox("Now we finally meet!");
	end
	if BattleHasHero(0) and BattleHasHero(1) and BattleGetHero(1).name == "Lord Varuun" then
		lord = GetHero(GetPlayer(1), 0);
		phero = GetCurrentHero();
		niftysnippets.CloneHeroSkills(phero, lord);
	end
end;

