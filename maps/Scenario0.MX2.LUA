abandonedHutVisited = false;
bonfireVisited = false;
caveVisited = false;
tentVisited = false;
treeHouseVisited = false;
hero = null;
player = null;

mapVariables = {"abandonedHutVisited", "bonfireVisited", "caveVisited", "tentVisited", "treeHouseVisited", "hero", "player"};


function OnMapStart()
    player = GetPlayer(0);
    hero = GetHero(player, 0);
	GrantArmy(hero, CREATURE_CYBER_BEHEMOTH, 23);
	GrantArmy(hero, CREATURE_CYBER_INDIGO_PANTHER, 20);
	GrantArmy(hero, CREATURE_CYBER_SHADOW_ASSASSIN, 20);
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

function OnHeroMove(x, y) --Should we have custom text for when a location's event has already happened?
    if (x == 6) then    
        if (y == 9) then
            AbandonedHut();
        elseif (y == 10) then
            Bonfire();
        elseif (y == 11) then
            Cave();
        elseif (y == 12) then
            Tent();
        elseif (y == 13) then
            TreeHouse();
        end
    end
        
end;

function AbandonedHut()
    if (not abandonedHutVisited) then
        abandonedHutVisited = true;
        MessageBox("You find a small hut that seems to be abandoned.");
        MessageBox("Upon entering the hut you discover a staff with great power.");
        --Should SetSecondarySkill be used instead of an artifact?
        freeSlots = CountEmptyArtifactSlots(hero);
        if (freeSlots > 0) then
            --We do not have a staff with +2 pathfinding. A placeholder is being used.
            artifact = ARTIFACT_STAFF_OF_WIZARDRY;
            if (not HasArtifact(hero, artifact)) then
                --We have not implemented a screen to grant artifacts.
                GrantArtifact(hero, artifact);
            else
                abandonedHutVisited = false;
                MessageBox("The hero already has this artifact!");
            end
        else
            abandonedHutVisited = false;
            MessageBox("The hero can't carry anymore artifacts!");
        end
    else
        MessageBox("The abandoned hut has already been visited.");
    end
end

function Bonfire()
    if (not bonfireVisited) then
        bonfireVisited = true;
        MessageBox("As you approach the fire you find a battle hardened paladin and his companion archers.");
        MessageBox("They offer to join your cause.");
        --Should this be a choice?
        --What if the hero's army is full? These are 2 (probably inseparable) stacks. Can we even check the hero army slots?
        --Should this be using the RecruitBox?
        GrantArmy(hero, CREATURE_PALADIN, 1);
        GrantArmy(hero, CREATURE_ARCHER, 10);
    else
        MessageBox("The bonfire has already been visited.");
    end
end

function Cave()
    if (not caveVisited) then
        caveVisited = true;
        MessageBox("Hidden in the cave is a witch that offers you either great riches or a powerful spell.");
        choice = QuestionBox("What do you choose?\n\nYES: Mass Invisibility\nNO: 1000 gold & 1000 gems");
        if (choice) then 
            if (HasArtifact(hero, ARTIFACT_MAGIC_BOOK)) then --Does the hero have a spellbook???
                GrantSpell(hero, SPELL_MASS_BLESS); --Placeholder spell. Mass Invisibility does not exist.
            else
                GrantSpellScroll(hero, SPELL_MASS_BLESS);
            end
        else
            GiveResource(player, RESOURCE_GOLD, 1000);
            GiveResource(player, RESOURCE_GEMS, 1000);
        end
    else
        MessageBox("The cave has already been visited.");
    end
end

function Tent()
    if (not tentVisited) then
        tentVisited = true;
        MessageBox("A few rangers show their skill in a competition.");
        MessageBox("Upon your arrival, you join the crowd and watch the show which ends with one archer splitting an arrow in mid air and hitting the bullseye of the target.");
        MessageBox("After the show, the archers notice you, and offer to join you telling you it will be their honor to serve you with their skills.");
        --What if the army slots are full?
        GrantArmy(hero, CREATURE_RANGER, 10);
    else
        MessageBox("The tent has already been visited.");
    end
end

function TreeHouse()
    if (not treeHouseVisited) then
        treeHouseVisited = true;
        MessageBox("Tree House");
    end
end

function OnCastleConquered(castleId, playerId)

	if castleId==0
	then
		
		
	end;

end;

function OnMapVictory()
    MessageBox("The warlock lord curses you from his high tower - he waves his wand in the air, and shimmering smoke falls as if it's heavier than the air.");
    MessageBox("It now encompasses the entire castle. You see a flash, moments later you hear a bang, and a shock wave sweeps the entire area - you are unable to avoid it...");
    MessageBox("Oh wait, wait, this is way too fast, let me start from the beginning:");
    MessageBox("Sometime after Archibald was captured by Roland, and was placed in his statue prison, a large guild of warlocks calling themselves the Unwavering Darkness, decided that Archibald is the mightiest wizard that the kingdom has ever known, and thus ventured to free him.");
    MessageBox("Together they conquered the land, and in the process, Archibald never forgave his brother for looming a plan to remove him from the world. ");
end;
