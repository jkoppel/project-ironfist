function OnMapStart()
	GrantArmy(GetHero(GetPlayer(0), 0), CREATURE_CYBER_BEHEMOTH, 23);
	GrantArmy(GetHero(GetPlayer(0), 0), CREATURE_CYBER_INDIGO_PANTHER, 20);
	GrantArmy(GetHero(GetPlayer(0), 0), CREATURE_CYBER_SHADOW_ASSASSIN, 20);
	MessageBox("Let me tell you a story!");
	MessageBox("The bravest warrior that has ever existed, controlling his augments and abilities, and leading his army of enhanced creatures to free the world from the mad tyrant Archibald the wicked!");
	MessageBox("This hero is unique - no one has ever seen such a marvel - part man, part machine, a true cybernetic hero.");
    MessageBox("Where this hero sees science and technology everyone else sees magic!");
    MessageBox("The chase after Archibald is tedious, the kingdom is littered with warlock towers sapping the life energy of the land.");
    MessageBox("Your goal now is to capture the warlock lord controlling this region and extract information about Archibald’s army, and location. Once you capture this final town you will be able to pass through to Archibald’s Grand Castle, and finally defeat the tyrant.");
    TeleportHero(GetHero(GetPlayer(0), 0), 10, 14);
	MessageBox(tostring(AQUA_BARRIER));
	SetBarrierTentVisited(GetPlayer(0), AQUA_BARRIER);
	MessageBox("After!");
end; 

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
