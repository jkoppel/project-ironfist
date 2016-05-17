#include "adventure/adv.h"
#include "base.h"
#include "adventure/map.h"
#include "game/game.h"

#include "game/map_xml.hxx"
#include "scripting/scripting.h"
#include "spell/spells.h"
#include "gui/dialog.h"

#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<sys/stat.h>

using namespace std;

extern int giMonthType;
extern int giMonthTypeExtra;
extern int giWeekType;
extern int giWeekTypeExtra;
extern char cPlayerNames[6][21];

extern int giCurPlayer;
extern int iLastMsgNumHumanPlayers;
extern int bShowIt;

extern int giCurTurn;

extern playerData* gpCurPlayer;
extern unsigned char giCurPlayerBit;

extern signed char gbThisNetHumanPlayer[];
extern int giCurWatchPlayer;
extern unsigned char giCurWatchPlayerBit;

extern int gbRemoteOn;
extern int giThisGamePos;

extern void __fastcall FileError(char*);

extern void __fastcall GenerateStandardFileName(char*,char*);


void ReadHeroXML(ironfist_map::hero_t& hx, hero* hro) {
	hro->Clear();

	hro->army = armyGroup();

	int i = 0;
	for(ironfist_map::army_t::slot_const_iterator it = hx.army().slot().begin();
		it != hx.army().slot().end();
		it++,
		i++) {

		hro->army.Add(it->id().get(), it->quantity().get(), i);
	}


	memset(hro->artifacts, -1, sizeof(hro->artifacts));
	i = 0;
	for(ironfist_map::hero_t::artifact_const_iterator jt = hx.artifact().begin();
			jt != hx.artifact().end();
			jt++,
				i++) {

		hro->artifacts[i] = jt->id();
		hro->scrollSpell[i] = jt->spell();
	}

	int nSS = 0;
	for(ironfist_map::hero_t::secondarySkill_const_iterator it =
					hx.secondarySkill().begin();
		it != hx.secondarySkill().end();
		it++) {

		hro->secondarySkillLevel[it->id().get()] = it->level().get();
		hro->skillIndex[it->id().get()] = it->idx().get();

		if(it->level().get() > 0)
			nSS++;
	}

	hro->numSecSkillsKnown = nSS;

	hro->GetNumSpells(1);

	for(ironfist_map::hero_t::spell_const_iterator it = hx.spell().begin();
		it != hx.spell().end();
		it++) {

			hro->spellsLearned[*it] = 1;
	}
	hro->GetNumSpells(1);

	hro->experience = hx.experience();
	hro->factionID = hx.factionID();
	hro->field_21 = hx.field_21();
	hro->field_23 = hx.field_23();
	hro->field_25 = hx.field_25();
	hro->field_27 = hx.field_27();
	hro->field_29 = hx.field_29();
	hro->field_2B = hx.field_2B();
	hro->field_4 = hx.field_4();
	hro->field_43 = hx.field_43();
	hro->field_46 = hx.field_46();
	hro->field_5 = hx.field_5();
	hro->field_6 = hx.field_6();
	hro->field_7 = hx.field_7();
	hro->field_8 = hx.field_8();
	hro->field_9 = hx.field_9();
	hro->field_E8 = hx.field_E8();
	hro->flags = hx.flags();
	hro->fortsVisited = hx.fortsVisited();
	hro->gazeboesVisited = hx.gazeboesVisited();
	hro->heroID = hx.heroID();
	hro->idx = hx.idx();
	hro->isCaptain = hx.isCaptain();
	hro->mercenaryCampsVisited = hx.mercenaryCampsVisited();
	hro->mobility = hx.mobility();
	strncpy(hro->name, hx.name().c_str(), sizeof(hro->name));

	hro->occupiedObjType = hx.occupiedObjType();
	hro->occupiedObjVal = hx.occupiedObjVal();
	hro->oldLevel = hx.oldLevel();
	hro->ownerIdx = hx.ownerIdx();

	hro->primarySkills[PRIMARY_SKILL_ATTACK] = hx.attack();
	hro->primarySkills[PRIMARY_SKILL_DEFENSE] = hx.defense();
	hro->primarySkills[PRIMARY_SKILL_SPELLPOWER] = hx.spellpower();
	hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE] = hx.knowledge();

	hro->randomSeed = hx.randomSeed();
	hro->remainingMobility = hx.remainingMobility();

	hro->spellpoints = hx.spellpoints();
	hro->standingStonesVisited = hx.standingStonesVisited();
	hro->tempLuckBonuses = hx.tempLuckBonuses();
	hro->tempMoraleBonuses = hx.tempMoraleBonuses();
	hro->treesOfKnowledgeVisited = hx.treesOfKnowledgeVisited();
	hro->wisdomLastOffered = hx.wisdomLastOffered();
	hro->witchDoctorHutsVisited = hx.witchDoctorHutsVisited();
	hro->x = hx.x();
	hro->xanadusVisited = hx.xanadusVisited();
	hro->y = hx.y();
}

ironfist_map::hero_t WriteHeroXML(hero* hro) {

	ironfist_map::army_t arm;

	for(int i = 0; i < ELEMENTS_IN(hro->army.creatureTypes); i++) {
		ironfist_map::slot_t sl;
		sl.id(hro->army.creatureTypes[i]);
		sl.quantity(hro->army.quantities[i]);
		
		arm.slot().push_back(sl);
	}

	ironfist_map::hero_t hx(
		hro->spellpoints,
		hro->idx,
		hro->ownerIdx,
		hro->field_4,
		hro->field_5,
		hro->field_6,
		hro->field_7,
		hro->field_8,
		hro->field_9,
		hro->name,
		hro->factionID,
		hro->heroID,
		hro->x,
		hro->y,
		hro->field_21,
		hro->field_23,
		hro->field_25,
		hro->field_27,
		hro->field_29,
		hro->field_2B,
		hro->occupiedObjType,
		hro->occupiedObjVal,
		hro->mobility,
		hro->remainingMobility,
		hro->experience,
		hro->oldLevel,
		hro->primarySkills[PRIMARY_SKILL_ATTACK],
		hro->primarySkills[PRIMARY_SKILL_DEFENSE],
		hro->primarySkills[PRIMARY_SKILL_SPELLPOWER],
		hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE],
		hro->field_43,
		hro->tempMoraleBonuses,
		hro->tempLuckBonuses,
		hro->field_46,
		hro->gazeboesVisited,
		hro->fortsVisited,
		hro->witchDoctorHutsVisited,
		hro->mercenaryCampsVisited,
		hro->standingStonesVisited,
		hro->treesOfKnowledgeVisited,
		hro->xanadusVisited,
		hro->randomSeed,
		hro->wisdomLastOffered,
		arm,
		hro->flags,
		hro->isCaptain,
		hro->field_E8);

	for(int i = 0; i < ELEMENTS_IN(hro->secondarySkillLevel); i++) {
		ironfist_map::secondarySkill sk;
		sk.id(i);
		sk.level(hro->secondarySkillLevel[i]);
		sk.idx(hro->skillIndex[i]);
		hx.secondarySkill().push_back(sk);
	}

	for(int i = 0; i < NUM_SPELLS; i++) {
		if(hro->spellsLearned[i])
			hx.spell().push_back(i);
	}

	for(int i = 0; i < ELEMENTS_IN(hro->artifacts); i++) {
		hx.artifact().push_back(ironfist_map::hero_t::artifact_type(hro->artifacts[i]));
	}

	return hx;
}

void SaveMapVariables(ironfist_map::map_t& m) {
	int key = -1;
	const char* mapVariableId;
	bool isTable;
	bool mapVariablesLeft = GetNextMapVariable(key, mapVariableId, isTable);
	while (mapVariablesLeft) {
		ironfist_map::mapVariable_t mapVar(mapVariableId);
		if (isTable) {
			std::map<const char*, const char*> mapVariableValue = GetMapVariableValueTable(mapVariableId);
			for (std::map<const char*, const char*>::const_iterator it = mapVariableValue.begin(); it != mapVariableValue.end(); ++it) {
				ironfist_map::array ar;
				ar.key(it->first);
				ar.value(it->second);
				mapVar.array().push_back(ar);
			}
			m.mapVariable().push_back(mapVar);
		}
		else {
			const char* mapVariableValue = GetMapVariableValue(mapVariableId);
			if (mapVariableValue == NULL) {
				ErrorSavingMapVariable(mapVariableId);
			}
			else {
				mapVar.value(mapVariableValue);
				m.mapVariable().push_back(mapVar);
			}
		}
		mapVariablesLeft = GetNextMapVariable(key, mapVariableId, isTable);
	}
}

void game::LoadGame(char* filnam, int newGame, int a3) {
	if(newGame) {
		this->SetupOrigData();

		for(int i = 0; i < MAX_HEROES; i++) {
			//SetupOrigData clears out spellsLearned. Of course, we've changed
			//spellsLearned from an array to a pointer, so that actually NULLs it out
			this->heroes[i].ResetSpellsLearned();
		}
	} else {
		try {
			int fd;
			
			char v8[100];
			int v14 = 0;
			gbGameOver = 0;
			this->field_660E = 1;
			sprintf(v8, "%s%s", ".\\GAMES\\", filnam);

			/*
			 * Check if original save format
			 */
			fd = _open(v8, O_BINARY);
			char first_byte;
			_read(fd, &first_byte, sizeof(first_byte));
			_close(fd);

			if(first_byte != '<') {
				this->LoadGame_orig(filnam, newGame, a3);
				return;
			}

			auto_ptr<ironfist_map::map_t> mp = ironfist_map::map(string(v8));

			int i = 0;
			for (ironfist_map::map_t::hero_const_iterator it = mp->hero().begin();
			it != mp->hero().end();
				it++, i++) {
				ironfist_map::hero_t hx = *it;
				ReadHeroXML(hx, &this->heroes[i]);
			}

			int tmp_fd = _open("tmp", O_BINARY | O_CREAT | O_WRONLY);
			_write(tmp_fd, mp->raw().data(), mp->raw().size());
			_close(tmp_fd);

			char expansion;
			char curPlayer;
			char hasPlayer[6];

			int width,height;

			fd = open("tmp", O_BINARY | O_RDONLY);
			if ( fd == -1 )
				FileError(v8);
			ClearMapExtra();
			expansion = 1;

			_read(fd, &width, 4u);
			_read(fd, &height, 4u);
			this->SetMapSize(width, height);
			_read(fd, &this->mapHeader, sizeof(SMapHeader));
			_read(fd, &this->field_44D, 0x41u);
			_read(fd, this, 2u);
			_read(fd, &giMonthType, 1);
			_read(fd, &giMonthTypeExtra, 1u);
			_read(fd, &giWeekType, 1u);
			_read(fd, &giWeekTypeExtra, 1u);
			_read(fd, cPlayerNames, sizeof(cPlayerNames));

			gpAdvManager->PurgeMapChangeQueue();
			_read(fd, &giMapChangeCtr, 4u);

			sprintf(gpGame->lastSaveFile, filnam);
			_read(fd, &this->numPlayers, sizeof(this->numPlayers));
			_read(fd, &curPlayer, sizeof(curPlayer));
			giCurPlayer = curPlayer;
			_read(fd, &this->couldBeNumDefeatedPlayers, 1u);
			_read(fd, this->playerDead, 6u);

			_read(fd, hasPlayer, sizeof(hasPlayer));
			for(int i = 0; i < 6; ++i) {
				if(hasPlayer[i] && v14 < iLastMsgNumHumanPlayers) {
					++v14;
					gbHumanPlayer[i] = 1;
				} else {
					gbHumanPlayer[i] = 0;
				}
			}
			for(int i = 0; i < 6; ++i) {
				if(gbHumanPlayer[i])
					gbThisNetHumanPlayer[i] = !gbRemoteOn || i == giThisGamePos;
				else
					gbThisNetHumanPlayer[i] = 0;
			}

			_read(fd, &this->day, 2u);
			_read(fd, &this->week, 2u);
			_read(fd, &this->month, 2u);
			giCurTurn = this->day + 7 * (this->week - 1) + 28 * (this->month - 1);
			for(int i = 0; i < 6; ++i)
				this->players[i].Read(fd);
			_read(fd, &this->numObelisks, 1u);
			_read(fd, this->relatedToHeroForHireStatus, 0x36u);
			_read(fd, this->castles, 7200u);
			_read(fd, this->field_2773, 0x48u);
			_read(fd, this->field_27BB, 9u);
			_read(fd, this->mines, 0x3F0u);
			_read(fd, this->field_60A6, 144u);

			_read(fd, this->artifactGeneratedRandomly, 0x67u);
			_read(fd, this->boats, 0x180u);
			_read(fd, this->boatBuilt, 0x30u);
			_read(fd, this->obeliskVisitedMasks, 0x30u);
			_read(fd, &this->field_6395, 1u);
			_read(fd, &this->field_6396, 1u);
			_read(fd, &this->field_6397, 1u);
			_read(fd, this->currentRumor, 301u);
			_read(fd, this->field_637D, 0x18u);
			_read(fd, &this->numRumors, 4u);
			_read(fd, this->rumorIndices, 2 * this->numRumors);
			_read(fd, &this->numEvents, 4u);
			_read(fd, this->eventIndices, 2 * this->numEvents);
			_read(fd, &this->field_657B, 4u);
			_read(fd, this->_D, 2 * this->field_657B);
			_read(fd, &iMaxMapExtra, 4u);
			ppMapExtra = (void**)ALLOC(4 * iMaxMapExtra);
			pwSizeOfMapExtra = (short*)ALLOC(2 * iMaxMapExtra);
			memset(ppMapExtra, 0, 4 * iMaxMapExtra);
			memset(pwSizeOfMapExtra, 0, 2 * iMaxMapExtra);
			for(int i = 1; i < iMaxMapExtra; ++i ) {
				_read(fd, &pwSizeOfMapExtra[i], 2u);
				ppMapExtra[i] = ALLOC(pwSizeOfMapExtra[i]);
				_read(fd, ppMapExtra[i], pwSizeOfMapExtra[i]);
			}
			_read(fd, mapRevealed, MAP_HEIGHT * MAP_WIDTH);
			this->map.Read(fd, 0);
			_close(fd);
            gpAdvManager->heroMobilized = 0;
			gpCurPlayer = &gpGame->players[giCurPlayer];
			giCurPlayerBit = 1 << giCurPlayer;
			for(giCurWatchPlayer = giCurPlayer;
				!gbThisNetHumanPlayer[giCurWatchPlayer];
				giCurWatchPlayer = (giCurWatchPlayer + 1) % this->numPlayers )
				;
			giCurWatchPlayerBit = 1 << giCurWatchPlayer;
			bShowIt = gbThisNetHumanPlayer[giCurPlayer];
			this->SetupAdjacentMons();
			gpAdvManager->CheckSetEvilInterface(0, -1);

            gpGame->ResetIronfistGameState();

			if (mp->script().present()) {
				ScriptingInitFromString(mp->script().get().c_str());
			}

			for (ironfist_map::map_t::mapVariable_const_iterator it = mp->mapVariable().begin();
				it != mp->mapVariable().end();
				it++) {
				if (it->value().present()) {
					SetMapVariable(it->id().c_str(), it->value().get().c_str());
				}
				else {
					std::map<const char*, const char*> array;
					for (ironfist_map::mapVariable_t::array_const_iterator it2 = it->array().begin(); 
						it2 != it->array().end(); it2++) {
						array[it2->key().get().c_str()] = it2->value().get().c_str();
					}
					SetMapVariableTable(it->id().c_str(), array);
				}
			}
		} catch(xml_schema::exception& e) {
			cerr << e << endl;
			exit(0);
		}
	}
}

int game::SaveGame(char *saveFile, int autosave, signed char baseGame) {
	void* extraMemory = ALLOC(50000);
	memset(extraMemory, 0, 50000u);
	baseGame = 0;
	gpAdvManager->DemobilizeCurrHero();
	char path[100];
	char v9[100];
	if(autosave) {
		if(!xIsExpansionMap || baseGame) {
			sprintf(path, "%s.GM1", saveFile);
		} else {
			sprintf(path, "%s.GX1", saveFile);
		}
	} else {
		sprintf(path, saveFile);
	}
	sprintf(v9, "%s%s", ".\\GAMES\\", &path);
	if(strnicmp(path, "AUTOSAVE", 8) && strnicmp(path, "PLYREXIT", 8))
		strcpy(gpGame->lastSaveFile, saveFile);

	int fd = open("tmp", O_WRONLY | O_TRUNC | O_CREAT | O_BINARY, S_IWRITE);
	if ( fd == -1 )
		FileError(v9);

	_write(fd, &this->map.width, 4);
	_write(fd, &this->map.height, 4);
	_write(fd, &this->mapHeader, 420);
	_write(fd, &this->field_44D, 65);
	_write(fd, this, 2);
	_write(fd, &giMonthType, 1);
	_write(fd, &giMonthTypeExtra, 1);
	_write(fd, &giWeekType, 1);
	_write(fd, &giWeekTypeExtra, 1);
	_write(fd, cPlayerNames, 126);

	char buf[100];

	gpAdvManager->PurgeMapChangeQueue();
	_write(fd, &giMapChangeCtr, 4);
	GenerateStandardFileName(this->lastSaveFile, buf);
	_write(fd, &this->numPlayers, 1);
	int v14 = giCurPlayer;
	_write(fd, &v14, 1);
	_write(fd, &this->couldBeNumDefeatedPlayers, 1);
	_write(fd, this->playerDead, 6);
	char playerAlive[6];
	for (int i = 0; i < 6; ++i)
	{
		playerAlive[i] = gbHumanPlayer[i];
		if(this->playerDead[i])
			playerAlive[i] = 0;
	}
	_write(fd, playerAlive, 6);
	_write(fd, &this->day, 2);
	_write(fd, &this->week, 2);
	_write(fd, &this->month, 2);
	for(int i = 0; i < 6; ++i )
		this->players[i].Write(fd);
	_write(fd, &this->numObelisks, 1);
	_write(fd, this->relatedToHeroForHireStatus, 54);
	_write(fd, this->castles, 7200);
	_write(fd, this->field_2773, 72);
	_write(fd, this->field_27BB, 9);
	_write(fd, this->mines, 1008);
	_write(fd, this->field_60A6, 144);
	_write(fd, this->artifactGeneratedRandomly, 103);
	_write(fd, this->boats, 384);
	_write(fd, this->boatBuilt, 48);
	_write(fd, this->obeliskVisitedMasks, 48);
	_write(fd, &this->field_6395, 1);
	_write(fd, &this->field_6396, 1);
	_write(fd, &this->field_6397, 1);
	_write(fd, this->currentRumor, 301);
	_write(fd, this->field_637D, 24);
	_write(fd, &this->numRumors, 4);
	_write(fd, this->rumorIndices, 2 * this->numRumors);
	_write(fd, &this->numEvents, 4);
	_write(fd, this->eventIndices, 2 * this->numEvents);
	_write(fd, &this->field_657B, 4);
	_write(fd, this->_D, 2 * this->field_657B);
	_write(fd, &iMaxMapExtra, 4);
	for(int i = 1; i < iMaxMapExtra; ++i) {
		_write(fd, &pwSizeOfMapExtra[i], 2);
		if(ppMapExtra[i])
			_write(fd, ppMapExtra[i], pwSizeOfMapExtra[i]);
		else
			_write(fd, extraMemory, pwSizeOfMapExtra[i]);
	}
	_write(fd, mapRevealed, MAP_HEIGHT * MAP_WIDTH);
	this->map.Write(fd);
	_close(fd);
	FREE(extraMemory);


	unsigned char dat[1000000];
	fd = _open("tmp", O_BINARY);
	lseek(fd, 0, SEEK_END);
	int sz = tell(fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, dat, sz);
	close(fd);

	const xml_schema::base64_binary datbin(dat, sz);

	ofstream os(v9);

	ironfist_map::map_t m(datbin);

	for(int i = 0; i < ELEMENTS_IN(this->heroes); i++) {
		m.hero().push_back(WriteHeroXML(&this->heroes[i]));
	}

	if (GetScriptContents() != NULL) {
		m.script(GetScriptContents());
		SaveMapVariables(m);
	}

	xml_schema::namespace_infomap infomap;
	infomap[""].name = "ironfist_map";
	infomap[""].schema = "map_xml.xsd";

	ironfist_map::map(os, m, infomap);

	return 1;
}