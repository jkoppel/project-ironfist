abandonedHutVisited = false;
bonfireVisited = false;
caveVisited = false;
tentVisited = false;
treeHouseVisited = false;
gateUnlocked = false;
hero = null;
player = null;

mapVariables = {"abandonedHutVisited", "bonfireVisited", "caveVisited", "tentVisited", "treeHouseVisited","gateUnlocked", "hero", "player"};


function TryGrantArtifact(hero, artifact) --We have not implemented a screen to grant artifacts.
    freeSlots = CountEmptyArtifactSlots(hero);
    if (freeSlots > 0) then
        if (not HasArtifact(hero, artifact)) then
            GrantArtifact(hero, artifact);
            return true;
        else
            MessageBox("The hero already has this artifact!");
        end
    else
        MessageBox("The hero can't carry anymore artifacts!");
    end
    return false;
end

function TryGrantArmy(hero, creature, amount)
    freeSlots = CountEmptyCreatureSlots(hero);
    if (freeSlots > 0) then
        GrantArmy(hero, creature, amount);
        return true;
    else
        MessageBox("The hero's army is full!");
        return false;
    end
end

function OnMapStart()
    player = GetPlayer(0);
    hero = GetHero(player, 0);
	GrantArmy(hero, CREATURE_CYBER_BEHEMOTH, 1);
	GrantArmy(hero, CREATURE_CYBER_INDIGO_PANTHER, 2);
	GrantArmy(hero, CREATURE_CYBER_SHADOW_ASSASSIN, 5);
	GrantArmy(hero, CREATURE_CYBER_PLASMA_BERSERKER, 5);
	GrantArmy(hero, CREATURE_CYBER_KOBOLD_SPEARMAN, 2);
    if (not HasArtifact(hero, ARTIFACT_MAGIC_BOOK)) then
        GrantArtifact(hero, ARTIFACT_MAGIC_BOOK);
    end
	MessageBox("Let me tell you a story!");
	MessageBox("The bravest warrior that has ever existed, controlling his augments and abilities, and leading his army of enhanced creatures to free the world from the mad tyrant Archibald the wicked!");
	MessageBox("This hero is unique - no one has ever seen such a marvel - part man, part machine, a true cybernetic hero.");
    MessageBox("Where this hero sees science and technology everyone else sees magic!");
    MessageBox("The chase after Archibald is tedious, the kingdom is littered with warlock towers sapping the life energy of the land.");
    MessageBox("Your goal now is to capture the warlock lord controlling this region and extract information about Archibald’s army, and location. Once you capture this final town you will be able to pass through to Archibald’s Grand Castle, and finally defeat the tyrant.");
    TeleportHero(hero, 10, 14);
	MessageBox(tostring(AQUA_BARRIER));
	SetBarrierTentVisited(player, AQUA_BARRIER);
	MessageBox("After!");
end; 

function OnLocationVisit(loc, x, y)
    if (loc == LOCATION_RANDOM_MONSTER or (LOCATION_RANDOM_MONSTER_WEAK <= loc and loc <= LOCATION_RANDOM_MONSTER_VERY_STRONG)) then
        MessageBox("This is a battle.");
        return false;
    elseif (loc == LOCATION_BARRIER) then
        Gate();
    elseif (loc == LOCATION_FOUNTAIN) then
        Fountain();
    elseif (x == 29 and y == 8) then
        AbandonedHut();
    elseif (x == 26 and y == 19) then
        TreeHouse();
    elseif (x == 31 and y == 19) then
        Bonfire();
    else
        MessageBox("This is some sort of location.");
        return false;
    end
    return true;
end

function OnHeroMove(x, y) --Should we have custom text for when a location's event has already happened?
    if (x == 6) then      --OnLocationVisit should be used, but I don't know where/what the events will be yet
        if (y == 11) then
            Cave();
        elseif (y == 12) then
            Tent();
        end
    end
        
end;

function AbandonedHutEvent()
    if (not abandonedHutVisited) then
        MessageBox("You find a small hut that seems to be abandoned.");
        MessageBox("Upon entering the hut you discover a pair of boots with odd markings.");
        freeSlots = CountEmptyArtifactSlots(hero);
        if (freeSlots > 0) then
            if (TryGrantArtifact(hero, ARTIFACT_NOMAD_BOOTS_OF_MOBILITY)) then
                abandonedHutVisited = true;
            end
        else
            MessageBox("The hero can't carry anymore artifacts!");
        end
    else
        MessageBox("The abandoned hut has already been visited.");
    end
end

function BonfireEvent()
    if (not bonfireVisited) then
        bonfireVisited = true;
        MessageBox("As you approach the fire you find a battle hardened paladin and his companion archers.");
        MessageBox("They offer to join your cause.");
        --Should this be a choice?
        --What if the hero's army is full? These are 2 (probably inseparable) stacks. Can we even check the hero army slots?
        --Should this be using the RecruitBox?
        if (not TryGrantArmy(hero, CREATURE_PALADIN, 1)) then
            bonfireVisited = false;
            return;
        end
        if (not TryGrantArmy(hero, CREATURE_ARCHER, 10)) then
            TakeTroop(hero, CREATURE_PALADIN, 1);
            bonfireVisited = false;
        end
    else
        MessageBox("The bonfire has already been visited.");
    end
end

function CaveEvent()
    if (not caveVisited) then
        caveVisited = true;
        MessageBox("Hidden in the cave is a witch that offers you either great riches or a powerful spell.");
        choice = QuestionBox("YES: Mass Invisibility\nNO: 1000 gold & 10 gems");
        if (choice) then 
            GrantSpell(hero, SPELL_TELEPORT);
        else
            GiveResource(player, RESOURCE_GOLD, 1000);
            GiveResource(player, RESOURCE_GEMS, 10);
        end
    else
        MessageBox("The cave has already been visited.");
    end
end

function TentEvent()
    if (not tentVisited) then
        tentVisited = true;
        MessageBox("A few rangers show their skill in a competition.");
        MessageBox("Upon your arrival, you join the crowd and watch the show which ends with one archer splitting an arrow in mid air and hitting the bullseye of the target.");
        MessageBox("After the show, the archers notice you, and offer to join you telling you it will be their honor to serve you with their skills.");
        --What if the army slots are full?
        if (not TryGrantArmy(hero, CREATURE_RANGER, 10)) then
            tentVisited = false;
        end
    else
        MessageBox("The tent has already been visited.");
    end
end

function TreeHouse()
    if (not treeHouseVisited) then
        treeHouseVisited = true;
        MessageBox("In the distance you notice a small tree house, getting closer an old druid comes down from the tree, he looks at you with his one good eye, while his other eye travels away randomly.");
        MessageBox("The one that will save us all from the tyrant Archibald.");
        MessageBox("For this you may take one of my precious beloved items:");
        choice = QuestionBox("YES: Giant Flail of Dominion\nNO: Armored Gauntlets of Protection");
        if (choice) then --Had to use placeholder artifacts.
            GrantArtifact(hero, ARTIFACT_GIANT_FLAIL_OF_DOMINION);
        else
            GrantArtifact(hero, ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION);
        end
    else
        MessageBox("The tree house has already been visited.");
    end
end

function Gate()
    if (gateUnlocked) then
        MapEraseSquare(x, y);
    else
        MessageBox("A mighty gate stands before you.");
        MessageBox("You try to open it, you use strength, then use the combined might of your army, but even your mighty behemoth is unable to open it.");
        MessageBox("Finally when the sun lowers you see a shimmer on the gate - it is magically sealed.");
        MessageBox("One of your companions reveals his hunch that whatever is locking the gate must be in that warlock tower that we passed nearby.");
    end
    return true;
end

function Fountain()
    MessageBox("At a distance, you see a grass island in the middle of all the horrible hellish ground - a beautiful fountain with a few butterflies surrounding the water.");
    MessageBox("As you get closer to these butterflies, you see that they are not butterflies at all - they are fairies. One of them gets closer to you, and whispers in a magical voice that sounds like a melody in your ear.");
    MessageBox("It is so wonderful to meet you, truly a pleasure to see our savior in the flesh, as you see even our magic is waning and we’ll not be able to hold on much longer.");
    result = QuestionBox("We can teach you a great spell that will help you on your journey: Mass Haste or Meteor Shower.\nYES: Mass Haste\nNO: Meteor Shower");
    if (result) then
        GrantSpell(hero, SPELL_MASS_HASTE);
    else
        GrantSpell(hero, SPELL_METEOR_SHOWER);
    end
end

function OnCastleConquered(castleId, playerId)
    MessageBox("A castle was conquered.");
    firstCastle = 0;
    firstPlayer = 0;
	if (castleId == firstCastle and playerId == firstPlayer) then
		MessageBox("Upon defeating the warlock, and securing his tower, you hear a great noise in the distance.");
        MessageBox("Once you look out the window you notice that the grand gate, that was once unbreakable, is now open.");
		gateUnlocked = true;
	end;

end;

function OnMapVictory()
    MessageBox("The warlock lord curses you from his high tower - he waves his wand in the air, and shimmering smoke falls as if it's heavier than the air.");
    MessageBox("It now encompasses the entire castle. You see a flash, moments later you hear a bang, and a shock wave sweeps the entire area - you are unable to avoid it...");
    MessageBox("Oh wait, wait, this is way too fast, let me start from the beginning:");
    MessageBox("Sometime after Archibald was captured by Roland, and was placed in his statue prison, a large guild of warlocks calling themselves the Unwavering Darkness, decided that Archibald is the mightiest wizard that the kingdom has ever known, and thus ventured to free him.");
    MessageBox("Together they conquered the land, and in the process, Archibald never forgave his brother for looming a plan to remove him from the world. ");
end;
