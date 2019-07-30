AdvMessageBox = require("scripts.modules.advmessagebox");

abandonedHutVisited = false;
bonfireVisited = false;
caveVisited = false;
tentVisited = false;
treeHouseVisited = false;
gateUnlocked = false;
gateDestroyed = false;
fountainVisited = false;
smallHouseVisited = false;
joustingRingVisited = false;
hero = null;
player = null;
gateX = 11;
gateY = 18;
bonfireX = 31;
bonfireY = 19;
events = {  zero  = {x=29, y= 8, func='AbandonedHutEvent'},
            one   = {x=26, y=19, func='TreeHouseEvent'   },
            two   = {x=31, y=19, func='BonfireEvent'     },
            three = {x=24, y=10, func='CaveEvent'        },
            four  = {x=32, y=31, func='TentEvent'        },
            five  = {x=21, y=22, func='SmallHouseEvent'  },
            six   = {x=30, y= 4, func='JoustingRingEvent'}};

mapVariables = {"abandonedHutVisited", "bonfireVisited", "caveVisited", "tentVisited", "treeHouseVisited", "gateUnlocked", "gateDestroyed", "fountainVisited", "smallHouseVisited", "joustingRingVisited", "hero", "player", "gateX", "gateY", "events"};


function TryGrantArtifact(hero, artifact) --We have not implemented a screen to grant artifacts.
    freeSlots = CountEmptyArtifactSlots(hero);
    if (freeSlots > 0) then
        if (not HasArtifact(hero, artifact)) then
            GrantArtifact(hero, artifact);
            AdvMessageBox.SingleImage("You have received an artifact!", 1, 7, artifact)
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
    player.daysLeftWithoutCastle = 60;
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
    MessageBox("Your goal now is to capture the warlock lord controlling this region and extract information about Archibald’s army and location. Once you capture this final town you will be able to pass through to Archibald’s Grand Castle, and finally defeat the tyrant.");
end

function OnLocationVisit(loc, x, y) --Should we have custom text for when a location's event has already happened?
    if (x == gateX and y == gateY and loc == LOCATION_BARRIER) then
        GateEvent();
    else
        for key, event in pairs(events) do
            if (event.x == x and event.y == y) then
                _G[event.func]();
                return true;
            end
        end
        return false;
    end
    return true; --This can be removed when all of the events are in the tables
end

function OnHeroMove(x, y)
    if (x >= 10 and x <= 13) then
        if (y >= 16 and y <= 18) then
            GateDestroyEvent();
        end
    end
    
    if (x >= 5 and x <= 6) then
        if (y == 18) then
            FountainEvent();
        end
    end
end

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
        MessageBox("As you approach the fire you find a battle-hardened paladin.");
        MessageBox("He offers to join your cause.");
        if (not TryGrantArmy(hero, CREATURE_PALADIN, 1)) then
            bonfireVisited = false;
        else
            MapFizzle(bonfireX, bonfireY, true); --We pass true because we want the sound to play.
        end
    end
end

function CaveEvent()
    if (not caveVisited) then
        caveVisited = true;
        MessageBox("Hidden in the cave is a witch that offers you either great riches or a powerful spell.");
        choice = QuestionBox("Will you accept the spell?");
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
        if (not TryGrantArmy(hero, CREATURE_RANGER, 10)) then
            tentVisited = false;
        end
    else
        MessageBox("The tent has already been visited.");
    end
end

function TreeHouseEvent()
    if (not treeHouseVisited) then
        treeHouseVisited = true;
        MessageBox("In the distance you notice a small tree house, getting closer an old druid comes down from the tree, he looks at you with his one good eye, while his other eye travels away randomly.");
        MessageBox("\"The one that will save us all from the tyrant Archibald.\"");
        MessageBox("\"For this you may take one of my precious beloved items:\"");
        choice = AdvancedMessageBox("Giant Flail of Dominion or Armored Gauntlets of Protection", 7, -1, -1, 7, ARTIFACT_GIANT_FLAIL_OF_DOMINION, 7, ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION, 1, 0);
        if (choice) then
            TryGrantArtifact(hero, ARTIFACT_GIANT_FLAIL_OF_DOMINION);
        else
            TryGrantArtifact(hero, ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION);
        end
    else
        MessageBox("The tree house has already been visited.");
    end
end

function GateDestroyEvent() --Need to set up play sound for destroy?
    if (gateUnlocked and not gateDestroyed) then
        gateDestroyed = true;
        MessageBox("Crash! The gate to the south, once impenetrable, crumbles before your eyes.");
        MapFizzle(gateX, gateY, true); --We pass true because we want the sound to play.
    end
end

function GateEvent()
    if ((not gateUnlocked) and (not gateDestroyed)) then
        MessageBox("A mighty gate stands before you.");
        MessageBox("You try to open it, you use strength, then use the combined might of your army, but even your mighty behemoth is unable to open it.");
        MessageBox("Finally when the sun lowers you see a shimmer on the gate - it is magically sealed.");
        MessageBox("One of your companions reveals his hunch that whatever is locking the gate must be in that warlock tower that we passed nearby.");
    end
end

function FountainEvent()
    if (not fountainVisited) then
        fountainVisited = true;
        MessageBox("At a distance, you see a grass island in the middle of all the horrible hellish ground - a beautiful fountain with a few butterflies surrounding the water.");
        MessageBox("As you get closer to these butterflies, you see that they are not butterflies at all - they are fairies. One of them gets closer to you, and whispers in a magical voice that sounds like a melody in your ear.");
        MessageBox("\"It is so wonderful to meet you, truly a pleasure to see our savior in the flesh, as you see even our magic is waning and we’ll not be able to hold on much longer.\"");
        result = AdvancedMessageBox("We can teach you a great spell that will help you on your journey: Mass Haste or Meteor Shower.", 7, -1, -1, 8, SPELL_MASS_HASTE, 8, SPELL_METEOR_SHOWER, 1, 0);
        if (result) then
            GrantSpell(hero, SPELL_MASS_HASTE);
        else
            GrantSpell(hero, SPELL_METEOR_SHOWER);
        end
    end
end

function SmallHouseEvent()
    if (not smallHouseVisited) then
        smallHouseVisited = true;
        MessageBox("You get closer and notice a farmer and his wife sitting down and eating their meal.");
        MessageBox("They offer you to join them, but you decline as you have pressing matters. They insist and you agree.");
        MessageBox("After the meal they tell you: \"It's so great to meet and feed our hero. You may take our precious heirloom to aid you on your journey:\"");
        if (not TryGrantArtifact(hero, ARTIFACT_GOLDEN_HORSESHOE)) then
            smallHouseVisited = false;
        end
    else
        MessageBox("The small house has already been visited.");
    end
end

function JoustingRingEvent()
    if (not joustingRingVisited) then
        joustingRingVisited = true;
        MessageBox("As you get closer a group of jousting knights battles each other.");
        MessageBox("You enjoy the show, and once you are about to leave, they approach you offering to join your cause.");
        if (not TryGrantArmy(hero, CREATURE_CAVALRY, 10)) then
            joustingRingVisited = false;
            return;
        end
    else
        MessageBox("The jousting ring has already been visited.");
    end
end

function OnCastleConquered(castleId, playerId)
    --MessageBox("A castle was conquered.");
    firstCastle = 0;
    firstPlayer = 0;
    if (castleId == firstCastle and playerId == firstPlayer) then
        MessageBox("With the first Warlock defeated, your troops scurry to secure the castle.");
        MessageBox("At the top of the tower, there is a lever, labeled \"Darkstone Pass\".");
        MessageBox("You pull it, and hear a roar from the south.");
        gateUnlocked = true;
    end
end

function OnMapVictory()
    MessageBox("The warlock lord curses you from his high tower - he waves his wand in the air, and shimmering smoke falls as if it's heavier than the air.");
    MessageBox("It now encompasses the entire castle. You see a flash, moments later you hear a bang, and a shock wave sweeps the entire area - you are unable to avoid it...");
    MessageBox("Oh wait, wait, this is way too fast, let me start from the beginning:");
    MessageBox("Sometime after Archibald was captured by Roland, and was placed in his statue prison, a large guild of warlocks calling themselves the Unwavering Darkness, decided that Archibald is the mightiest wizard that the kingdom has ever known, and thus ventured to free him.");
    MessageBox("Together they conquered the land, and in the process, Archibald never forgave his brother for looming a plan to remove him from the world. ");
end
