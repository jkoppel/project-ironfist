extern "C" {
	void __stdcall ResourceManager__dumpImageToScreen( const char * filename, Bitmap * screenBuf, int  isICN);
	AbstractResource * __stdcall ResourceManager__findLoadedFile( int  fileID);
	void __stdcall ResourceManager__freeAllResources();
	Bitmap * __stdcall ResourceManager__getBitmapByFilename( const char * filename);
	int __stdcall ResourceManager__getFileSize( int  fileID);
	Font * __stdcall ResourceManager__getFontByFilename( const char * filename);
	Icon * __stdcall ResourceManager__getIconByFileID( int  fileID);
	Icon * __stdcall ResourceManager__getIconByFilename( const char * filename);
	Palette * __stdcall ResourceManager__getPal( const char * file);
	Sample * __stdcall ResourceManager__getSampleByFilename( const char * filename);
	Palette * __stdcall ResourceManager__getPal( const char * file);
	Sample * __stdcall ResourceManager__getSampleByFilename( const char * filename);
	Sequence * __stdcall ResourceManager__getSequenceByFilename( const char * filename);
	Tileset * __stdcall ResourceManager__getTilesetByFilename( const char * filename);
	int __stdcall ResourceManager__handleInput( InputEvent * a1);
	signed int __stdcall ResourceManager__initialize( int  idx);
	__int32 __stdcall ResourceManager__pointToFile( int  id);
	__int32 __stdcall ResourceManager__popFileAndOffsetOffStack();
	void __stdcall ResourceManager__prependFileLinkedListNode( AbstractResource * res);
	int __stdcall ResourceManager__pushCurrentFileAndOffsetOntoStack();
	void __stdcall ResourceManager__readFromCurrentFile( void * buf, unsigned int  nbytes);
	int __stdcall ResourceManager__readInt();
	void __stdcall ResourceManager__readNexDOSFilename( void * buf);
	__int16 __stdcall ResourceManager__readShort();
	void __stdcall ResourceManager__reduceReferenceCountToResource( AbstractResource * res);
	void __stdcall ResourceManager__removeFileFromList( AbstractResource * fil);
	void __stdcall SoundManager__initializeRedbook();
	int FileRequester_constructor(int  this, int  a2, int  a3, int  a4, const char * a5, const char * a6, const char * a7);
	signed int CombatManager::findHexWithCorpse(CombatManager * this, int  startHex, int * resultHex, Spell  spell);
	void Bitmap::copyFrom(Bitmap * to, Bitmap * from, __int16  x, __int16  y);
	signed int ArmyInfo::hasUndead(ArmyInfo * this);
	signed int ArmyInfo::hasNonUndead(ArmyInfo * this);
	Button * Button_constructor(Button * this);
	void sub_402950(SoundManager * this, int  a2, signed int  a3, int  a4, int  a5);
	void CreatureStack::fireShot(CreatureStack * this);
	signed int CreatureStack::walkTo(CreatureStack * ecx0, int  hex);
	signed int CombatManager::summonElemental(CombatManager * this, CREATURES  creatureId, int  strength);
	void GameInfo::initializeCastles(GameInfo * this);
	int FileRequester::terminate(int  this);
	AdvManager * AdvManager_constructor(AdvManager * this);
	int Font::charWidth(Font * this, char  chr);
	HeroWindowManager * CombatManager::drawLuckAnimation(CombatManager * this, int  side, int  stackIdx);
	void CombatManager::castEarthquake(CombatManager * this);
	signed int CreatureStack::walkToTarget(CreatureStack * this);
	void GUIWindow::repaint(GUIWindow * this, int  updateScreen);
	void CombatManager::setCombatArmyInfoLevel(CombatManager * this, int  level);
	void Bitmap::blitToScreenSizedBmp(Bitmap * this, Bitmap * buf, int  xTarg, int  yTarg, int  xFrom, int  yFrom, unsigned int  width, int  height);
	signed int sub_4012C0(CreatureStack * this, int  hex, int  flag);
	void CombatManager::castMiscEffectSpellOnHex(CombatManager * this, int  hexIdx);
	void BackgroundGUI::paint(BackgroundGUI * this);
	void CreatureStack::doHydraAttack(CreatureStack * this, int  a2);
	void CreatureStack::removePositiveEffects(CreatureStack * this);
	int Font::getFlattenedStringWidth(Font * this, const char * str);
	int CombatManager::getAliveStackBitmask(CombatManager * this, int  side);
	int Bankbox::cleanUp(Bankbox * this);
	int AbstractGUIComponent::setParent(AbstractGUIComponent * this, __int16  idx, GUIWindow * parent);
	void SoundManager::closeRedbook(SoundManager * this);
	void ArmyDisplay::cleanUp(ArmyDisplay * this);
	void GameInfo::fixSeveralInvariants(GameInfo * this);
	bool CreatureStack::canMoveToNeighbor(CreatureStack * this, int  hexIdx, signed int  neighborIdx);
	void CombatHexTile::drawNonTopmostCorpses(CombatHexTile * this);
	void HeroWindowManager::cleanUp(HeroWindowManager * this);
	ArmyInfo * ArmyInfo_constructor(ArmyInfo * this);
	int CreatureStack::getRightBound(CreatureStack * this);
	void CombatManager::showGenericCastMessage(CombatManager * this, int  a2, Spell  spell, CreatureStack * stack);
	void GUIIcon::readSelf(GUIIcon * this);
	int CreatureStack::getFreeNeighborBitmask(CreatureStack * this, int  hex, int  focusLevel, int  a5);
	void Castle::retrieveBallistaStats(Castle * this, int * numArchers, int * attack);
	void Bitmap::outputToScreen(Bitmap * bmp, int  x, int  y, unsigned int  width, int  height, int  screenX, signed int  screenY);
	AbstractGUIComponent * AbstractGUIComponent_constructor(AbstractGUIComponent * this, __int16  a2, __int16  a3, __int16  a4, __int16  a5, __int16  fieldID, __int16  a7);
	int Font::drawLine(Font * ecx0, char * a2, int  a3, int  a4, int  a5, int  a7, int  a8, unsigned int  regionWidth, int  regionHeight);
	BackgroundGUI * BackgroundGUI_noArgConstructor(BackgroundGUI * this);
	void CombatManager::clearHitByHydraAttack(CombatManager * this);
	signed int ArmyInfo::hasCreatureOfType(ArmyInfo * this, int  creatureType);
	void GUIWindow::removeComponentByID(GUIWindow * this, int  id);
	signed int sub_4016D0(int  this);
	void CombatManager::initializeArmyAndHeroData(CombatManager * this);
	void CreatureStack::handleCreatureEvent(CreatureStack * this, CREATURE_EVENT_CODE  code);
	void Bitmap::getContentsFromScreen(Bitmap * to, __int16  xOff, __int16  yOff);
	GUIWindow * GUIWindow::emptyBuffer(GUIWindow * this);
	int ArmyInfo::getNumStacks(ArmyInfo * this);
	void CreatureStack::performMeleeAttack(CreatureStack * ecx0, int  isRetaliationOrSecondAttack);
	char CombatManager::initializeHexNeighbors(CombatManager * this);
	void CombatManager::animateDrawbridgeClosing(CombatManager * this);
	void CombatManager::addCasualtyInfoToWindow(CombatManager * ecx0, GUIWindow * window);
	int CombatManager::initialize(CombatManager * this, int  a2);
	int CreatureStack::getLeftBound(CreatureStack * this);
	void CombatManager::resetStuffHapenedToCreature(CombatManager * this);
	SoundManager * sub_402DB0(int  a1);
	int CombatManager::getHeuristicForSummon(CombatManager * this, int  hex, Spell  spell);
	void CreatureStack::cure(CreatureStack * this, int  spellpower);
	int GameInfo::randomArtifact(GameInfo * this, char  allowedLevels, int  allowNegatives);
	BackgroundGUI * BackgroundGUI_constructor(BackgroundGUI * this, __int16  x, __int16  y, __int16  width, __int16  height, __int16  fieldID, __int16  a7, __int16  color, const char * filename);
	signed int BackgroundGUI::handleEvent(BackgroundGUI * this, InputEvent * evt);
	int GameInfo::getNumberOfThievesGuilds(GameInfo * this, int  playerIdx);
	signed int CreatureStack::othCreatureIsAdjacent(CreatureStack * this, int  side, int  idx);
	signed int AdvManager__handleInput(AdvManager * this, InputEvent * evt);
	void CreatureStack::removeEffect(CreatureStack * this, STACK_MODIFYING_EFFECT  effect);
	void CreatureStack::initializeBookkeeping(CreatureStack * this);
	int CreatureStack::takeDamage(CreatureStack * this, signed int  baseDam, Spell  spell);
	int CreatureStack::getStandingTopY(CreatureStack * this);
	CombatManager * CombatManager::informLostBattle(CombatManager * this);
	signed int CombatManager::handleInput(CombatManager * this, InputEvent * evt);
	bool CreatureStack::canPlaceCreature(CreatureStack * this, int  hex, int  mayShiftTwoHexers, int * rearHex);
	void AdvManager::visitLocation(AdvManager * ecx0, MapTile * loc, __int64  a4);
	void GameInfo::randomlyFillGarrisonSlot(GameInfo * this, int  castleIdx);
	signed int CombatManager::checkCombatOver(CombatManager * this, InputEvent * evt);
	bool Castle::adjacentToWater(Castle * this);
	BuildingDisplay * BuildingDisplay_constructor(BuildingDisplay * this, int  faction, int  buildingCode, char * filename);
	void GUIWindow::removeComponent(GUIWindow * this, AbstractGUIComponent * comp);
	void CreatureStack::dealDamage(CreatureStack * this, CreatureStack * targ, int * damageDone, int * creaturesKilled, int  isRanged, int  a6);
	int DropList_constructor(int  this);
	SoundManager * sub_402D50(int  a1);
	void * AdvManager__cleanUp(void * this);
	void CombatManager::showCastMessage(CombatManager * this, int  spell, int  hex);
	CombatManager * CombatManager_constructor(CombatManager * this);
	HDIGDRIVER initializeWaveOutput(DWORD  samplesPerSec, __int16  bitsPerSample, WORD  nChannels, __int16  a4);
	signed int GameInfo::saveGame(GameInfo * this, const char * a2, int  a3, char  a4);
	void AbstractGUIComponent_destructor(void * this);
	void Bankbox::refreshCaptions(Bankbox * this, int  updateScreen);
	void AdvManager::involvesSettingPointBars(AdvManager * this, int  a2, int  a3, int  a4);
	CombatHexTile * CombatHexTile_constructor(CombatHexTile * this);
	Castle * Castle_constructor(Castle * this);
	int GUIWindow::grabBitmapFromScreen(GUIWindow * this);
	Bitmap * Bitmap::cleanUp(Bitmap * this, char  a2);
	BackgroundGUI * BackgroundGUI::cleanUp(BackgroundGUI * this, char  a2);
	void BuildingDisplay_cleanUp(BuildingDisplay * this);
	int GameInfo::exploreAllWater(GameInfo * this, char  playerIdx);
	void CombatHexTile::drawTopmostCorpse(CombatHexTile * this);
	void CombatManager::initializeCreatureStacks(CombatManager * this);
	bool CreatureStack::rollSpellSucceeds(CreatureStack * this, Spell  spell);
	void CreatureForm::doSomethingElse(CreatureForm * form, CREATURES  creature);
	Bitmap * Bitmap_noArgsConstructor(Bitmap * this);
	GUIWindow * GUIWindow::cleanUp(GUIWindow * this);
	CreatureStack * CombatManager::castResurrectionSpell(CombatManager * this, Spell  spell, int  hex, int  spellpower);
	signed int ArmyInfo::addCreatures(ArmyInfo * this, int  creatureType, __int16  quantity, signed int  stackIdx);
	signed int ArmyInfo::computeMoraleBonusForAlignments(ArmyInfo * this, int  a2);
	signed int GameInfo::computePlayerIncome(GameInfo * this, int  playerIdx);
	void Font::drawString(Font * this, const char * str, int  x, int  y, signed int  regionWidth, int  regionHeight, int  a7, int  alignType);
	signed int ArmyInfo::hasRoomForCreatureType(ArmyInfo * this, int  creatureType);
	void Button::cleanUp(Button * this, char  a2);
	signed int Castle::hasGarrison(Castle * this);
	void sub_4022B0(SoundManager * this);
	signed int CombatManager::castCombatSpell(CombatManager * this, int  a2);
	void CombatHexTile::drawCombatObj(CombatHexTile * this);
	void GUIWindow::repaintAndUpdateScreen(GUIWindow * this);
	void Font_destructor(Font * this);
	void CombatManager::displayCombatMessage(CombatManager * this, char * message, int  a3, int  a4, int  a5);
	ResourceManager * ResourceManager_constructor(ResourceManager * this);
	signed int GUIWindow::placeInIdx(GUIWindow * this, int  idx, int  redraw);
	int CombatManager::processAction(CombatManager * this, InputEvent * a2);
	GUIIcon * GUIIcon_constructor(GUIIcon * this, __int16  x, __int16  y, __int16  width, __int16  height, const char * filename, __int16  imgIdx, char  mirror, __int16  fieldID, __int16  a10, __int16  a11);
	int GameInfo::ownedNecromancyShrines(GameInfo * this, int  a2);
	void CombatManager::handleGoodMorale(CombatManager * this, int  side, int  stackIdx);
	void Bitmap::blitToScreenBufAt(Bitmap * from, __int16  x, __int16  y);
	signed int CombatManager::doCombatRound(CombatManager * this, int  a2);
	bool CreatureStack::isElementalOrMirrorImage(CreatureStack * this);
	void GUIIcon::paint(GUIIcon * this);
	void CombatManager::handleMoatClosing(CombatManager * a1);
	void CombatManager::drawBattlefield(CombatManager * this, int  redrawAll, int  a3, int  a4, int  a5, signed int  a6, int  a7, int  waitUntilItIsTime);
	void CreatureStack::doEffectAnimation(CreatureStack * this, int  animationIdx, signed int  a3, int  a4);
	void CreatureStack::draw(CreatureStack * this, int  centX, int  standingBotY, int  a4);
	int FileRequester::initialize(void * this, int  a2);
	int CreatureStack::getCenterX(CreatureStack * this);
	void BackgroundGUI__readSelf(BackgroundGUI * this);
	signed __int16 Button::handleEvent(Button * this, InputEvent * e);
	void CombatManager::handleCatapult(CombatManager * ecx0, int  side);
	int GameInfo::getRandomHeroFromHeroPool(GameInfo * this, int  playerIdx, signed int  faction, int  getPowerfulHero);
	signed int CreatureStack::neighboringHexOccupied(CreatureStack * this, int  knownHex, signed int  neighborIdx, int  focusLevel, int  a5, int * neighbor);
	void CombatManager::castElementalStorm(CombatManager * this);
	int CreatureStack::getCenterY(CreatureStack * this);
	void CreatureStack::rollAndHandleLuck(CreatureStack * this);
	CreatureStack * CreatureStack::cleanUp(CreatureStack * this);
	void CombatManager::animateDrawbridgeOpening(CombatManager * this);
	void CombatManager::animateCreatureColorChange(CombatManager * this, CreatureStack * a2, int  flagAdditions);
	void Bitmap::blitTo(Bitmap * this, Bitmap * target, int  targX, int  targY, int  offX, int  offY, int  width, int  height);
	int Font::cleanUp(int  this, char  a2);
	signed int CombatManager::handleBadMorale(CombatManager * this, int  side, int  stackIdx);
	void AdvManager::heroSelectionGUIStuff(AdvManager * this, int  a2, int  a3);
	void Castle::visit(Castle * this, int  a2);
	signed int GameInfo::endTurn(void * this);
	signed int CombatManager::shouldHalveRangedAttack(CombatManager * this, int  side, signed int  occupiedHex, signed int  targHex);
	int CreatureStack_constructor(CreatureStack * this);
	void ArmyInfo::swapStack(ArmyInfo * this, int  idx, ArmyInfo * oth, int  othIdx);
	void CombatManager::couldBeResetCombatMessage(CombatManager * this);
	void ArmyInfo::randomlyKillCreatures(ArmyInfo * this, float  chance);
	void GUIWindow::move(GUIWindow * this, int  deltaX, int  deltaY);
	void CreatureStack::loadRelatedFiles(CreatureStack * this);
	void CombatManager::toplevelCombatAIFunction(CombatManager * this);
	void GUIWindow::repaintComponentsInRange(GUIWindow * this, int  updateScreen, signed int  lowID, signed int  highID);
	void CreatureStack::die(CreatureStack * this, int  a2);
	signed int CombatManager::spellWillAffectSomeone(CombatManager * this, Spell  spellID);
	void CombatManager::handleGarrisonAndCatapult(CombatManager * this);
	int Castle::castleBuilt(Castle * this);
	ArmyDisplay * ArmyDisplay::constructor(ArmyDisplay * this, int  x, int  y, int  a4, int  portraitFileID, int  portraitIconIdx, ArmyInfo * army, __int16  fieldIDStart, int  redraw, int  a10);
	void CombatManager::createSummonedStack(CombatManager * this, int  side, CREATURES  creatureID, int  num, int  hex, int  attrs, int  a7);
	CombatManager * CombatManager::cleanUp(CombatManager * this);
	void CreatureStack::doAttackAndDamageTakenAnimations(CreatureStack * this, int  animIdx, int  a3, int  a4, int  a5);
	int CreatureStack::getNextEffectAnimationBottomY(CreatureStack * this);
	int GUIWindow::processMessage(GUIWindow * this, Event * evt);
	bool CombatManager::spellWillAffectUnitIn(CombatManager * this, Spell  spell, int  hexIdx);
	int CombatManager::findClosestCreature(CombatManager * this, CreatureStack * creat, int  forChainLightning);
	Bitmap * Bitmap_constructorFromFile(Bitmap * this, int  fileID);
	signed int CreatureStack::receiveEffect(CreatureStack * this, STACK_MODIFYING_EFFECT  effectType, signed int  strength);
	Bankbox * Bankbox_constructor(Bankbox * this, __int16  x, __int16  y, Player * player);
	void CreatureStack::decrementEffectDurations(CreatureStack * this);
	int Font::numLinesNeededToDisplay(Font * this, const char * msg, int  maxWidth);
	void HeroWindowManager::addWindow(HeroWindowManager * this, GUIWindow * window, int  idx, int  redraw);
	signed __int64 CombatManager::getHeuristicForRessurect(CombatManager * this, int * val, int  hexIdx, Spell  spell);
	signed int GUIIcon::handleEvent(GUIIcon * this, InputEvent * evt);
	int CreatureStack::canMoveToNeighborBitmask(CreatureStack * this, int  targHex);
	void AdvManager::drawAdventureMap(AdvManager * this, __int64  a2, int  a3, int  a4, char  a5, int  a6);
	bool CombatManager::anySpaceInFrontOfHero(CombatManager * this);
	Bitmap * Bitmap_constructor(Bitmap * this, __int16  a2, __int16  width, __int16  height);
	signed int CombatManager::getCorpseStackIdx(CombatManager * this, int  side, Spell  spell, int  hexIdx);
	double CreatureStack::getSpellSuccessChance(CreatureStack * this, Spell  spell);
	void CombatManager::castMedusaPetrify(CombatManager * this, CreatureStack * stack);
	signed int CreatureStack::getHexNeighbor(CreatureStack * this, int  knownHex, signed int  hexIdx);
	__int16 Button::readSelf(Button * this);
	void CreatureStack::doResistSpell(CreatureStack * a1, int  a2);
	void AbstractResource_destructor(void * this);
	void ResourceManager_destructor(ResourceManager * this);
	signed int AbstractGUIComponent::handleEvent(AbstractGUIComponent * this, Event * evt);
	void Bitmap::drawToScreenBuffer(Bitmap * from, __int16  x, __int16  y);
	signed int Castle::buildBuilding(Castle * this, signed int  buildingCode);
	HeroWindowManager * CombatManager::drawBolt(void * this, int  clearAfterwards, signed int  startX, signed int  startY, signed int  endX, signed int  endY, int  forkControl1, int  forkControl2, int  startWidth, int  endWidth, int  colorController, int  minRandomDiverge, int  maxRandomDiverge, int  divergeFreq, int  a15, int  a13, signed int  a17, int  a18);
	void Bitmap::copyFromAllowOOB(Bitmap * this, Bitmap * fromBMP, __int16  x, __int16  y);
	GUIIcon * GUIIcon::cleanUp(GUIIcon * this, char  a2);
	void Castle::grantHeroSpellsFromMageGuild(Castle * this, Hero * captain);
	int computeAILVolume(int  weight, int  ifForMusicThen101);
	signed int CombatManager::pickBestSpell(CombatManager * this, int  i, int  a3);
	void CombatManager::animateMagicOrGarrisonArrow(int  xFrom, int  yFrom, int  xTarg, int  yTarg, float * anglesOfImgIdxs, Icon * icon);
	signed int CombatManager::findCreature(CombatManager * this, int  startHex, int  side, int * resultHex);
	void CombatManager::castMirrorImage(CombatManager * this, int  hex);
	void sub_402B80(int  ecx0);
	signed int sub_401700(CreatureStack * this, signed int  hexIdx);
	void CombatManager::freeCreatureStackObjects(CombatManager * this);
	signed int FileRequester::handleInput(int  this, int  a2);
	void CombatManager::handleCreatureChanges(CombatManager * this, signed int  side);
	AbstractResource * AbstractResource_constructor(AbstractResource * this, RESOURCE_TYPE  type, int  fileID, __int16  referenceCount, AbstractResource * next);
	void CombatManager::castElementalAOE(CombatManager * this, int  hexIdx, Spell  spell);
	int HeroWindowManager::deleteSomeBMP(HeroWindowManager * this);
	int CombatManager::winBattle(CombatManager * this, signed int  side);
	int CombatManager::getExperiencePointsForDefeatingHero(CombatManager * this, int  side);
	int CombatManager::resetCombatGrid(CombatManager * this);
	bool sub_4023E0(SoundManager * this);
	Font * Font_constructor(Font * ecx0, int  fileID);
	void BuildingDisplay::paint(BuildingDisplay * this, int  advanceAnimations);
	void CombatManager::castMassSpell(CombatManager * this, Spell  spell, signed int  spellpower);
	GUIWindow * GUIWindow_constructorFromFile(GUIWindow * ecx0, int  xOff, int  yOff, const char * filename);
	int Button::paint(Button * this);
	signed int CombatManager::sphereOfNegationInEffect(CombatManager * this);
	void ArmyDisplay::paint(ArmyDisplay * this, int  updateScreen);
	signed int CombatManager::findBestDistanceHPTradeoffStack(CombatManager * this, CreatureStack * stack, int  side, int  stackBmask);
	void GUIWindow::insertElement(GUIWindow * this, AbstractGUIComponent * guiObj, int  index);
	void CombatManager::loadManyCombatImages(CombatManager * this);
	int AdvManager::initialize(AdvManager * this, int  idx);
	signed int ArmyInfo::computeMorale(ArmyInfo * this, Hero * hero, Castle * castle, char * enemyCreaturesList);
	void CombatManager::initializeBattlefield(CombatManager * this);
	int CombatManager::getHexIdxForMouseCoords(CombatManager * this, signed int  x, signed int  y);
	void CombatManager::effectCombatSpell(CombatManager * this, Spell  proto_spell, int  hexIdx, int  isCreatureAbility, int  a5);
	signed int CombatManager::defeatedOpponent(CombatManager * this, int  side);
	void CombatManager::getHeuristicForSpell(CombatManager * this, Spell  spell, int * value, int * target);
	CombatManager * CombatManager::doHolySpellGraphics(CombatManager * this, char  a2, char  a3, char  a4);
	int GameInfo::open_spellbook(GameInfo * this, Hero * hero, SPELL_CATEGORY  type, int  callback, char  a5);
	GUIWindow * GUIWindow_constructor(GUIWindow * this, int  x, int  y, int  width, int  height, int  flags);
	int CombatManager::getHeuristicForDamageSpell(CombatManager * this, int * val, Spell  spell, int  hexIdx);
	void CreatureStack::init(CreatureStack * this, int  creatureIdx, int  quantity, int  owner, int  stackIdx, int  startHex, int  armyIdx);
	void CombatManager::doDeathSpellGraphics(CombatManager * this, int  strength);
	int ArmyDisplay::drawStrip(ArmyDisplay * this);
	void CombatManager::handleTurrets(CombatManager * this, int  towerIdx);
	void Bitmap::colorSubstituteRectangle(Bitmap * bmp, int  x, int  y, int  width, int  height, int  substitutionIdx);
	void CreatureForm::doSomething(CreatureForm * form, int  a2, int  a3);
	char * CombatManager::prepareTerrainImageryAndGetBackgroundFilename(CombatManager * this);
	void CombatManager::releaseStaticObjectIcons(CombatManager * this);
	void CombatManager::getHeuristicForDispelOrCureCast(CombatManager * this, int * val, int  side, int  hex, int  isCure);
	void ArmyInfo::deleteStack(ArmyInfo * this, int  idx);
	void CombatManager::castChainLightning(CombatManager * this, int  targetHex, int  power);
	int CombatManager::getHeuristicForEffect(CombatManager * this, CreatureStack * stack, STACK_MODIFYING_EFFECT  eff);
	AbstractManager * AbstractManager_constructor(AbstractManager * this);
	void CombatManager::drawBackground(CombatManager * this);
	int GameInfo::showStackInfo(GameInfo * this, int  xOff, int  a3, CREATURES  creat, signed int  a5, int  a6, int  a7, unsigned int  a8, int  a9, Hero * a10, int  a11, ArmyInfo * a12, int  a13);
	GUIIcon * GUIIcon_noArgConstructor(GUIIcon * this);
}
void ResourceManager::dumpImageToScreen( const char * filename, Bitmap * screenBuf, int  isICN) {
	__asm {
		push isICN
		push screenBuf
		push filename
		mov ecx, this
		call ResourceManager__dumpImageToScreen
	}
}
AbstractResource * ResourceManager::findLoadedFile( int  fileID) {
	__asm {
		push fileID
		mov ecx, this
		call ResourceManager__findLoadedFile
	}
}
void ResourceManager::freeAllResources() {
	__asm {
		mov ecx, this
		call ResourceManager__freeAllResources
	}
}
Bitmap * ResourceManager::getBitmapByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, this
		call ResourceManager__getBitmapByFilename
	}
}
int ResourceManager::getFileSize( int  fileID) {
	__asm {
		push fileID
		mov ecx, this
		call ResourceManager__getFileSize
	}
}
Font * ResourceManager::getFontByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, ecx0
		call ResourceManager__getFontByFilename
	}
}
Icon * ResourceManager::getIconByFileID( int  fileID) {
	__asm {
		push fileID
		mov ecx, ecx0
		call ResourceManager__getIconByFileID
	}
}
Icon * ResourceManager::getIconByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, this
		call ResourceManager__getIconByFilename
	}
}
Palette * ResourceManager::getPal( const char * file) {
	__asm {
		push file
		mov ecx, thisa
		call ResourceManager__getPal
	}
}
Sample * ResourceManager::getSampleByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, ecx0
		call ResourceManager__getSampleByFilename
	}
}
Palette * ResourceManager::getPal( const char * file) {
	__asm {
		push file
		mov ecx, thisa
		call ResourceManager__getPal
	}
}
Sample * ResourceManager::getSampleByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, ecx0
		call ResourceManager__getSampleByFilename
	}
}
Sequence * ResourceManager::getSequenceByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, ecx0
		call ResourceManager__getSequenceByFilename
	}
}
Tileset * ResourceManager::getTilesetByFilename( const char * filename) {
	__asm {
		push filename
		mov ecx, this
		call ResourceManager__getTilesetByFilename
	}
}
int ResourceManager::handleInput( InputEvent * a1) {
	__asm {
		push a1
		mov ecx, this
		call ResourceManager__handleInput
	}
}
signed int ResourceManager::initialize( int  idx) {
	__asm {
		push idx
		mov ecx, ecx0
		call ResourceManager__initialize
	}
}
__int32 ResourceManager::pointToFile( int  id) {
	__asm {
		push id
		mov ecx, this
		call ResourceManager__pointToFile
	}
}
__int32 ResourceManager::popFileAndOffsetOffStack() {
	__asm {
		mov ecx, this
		call ResourceManager__popFileAndOffsetOffStack
	}
}
void ResourceManager::prependFileLinkedListNode( AbstractResource * res) {
	__asm {
		push res
		mov ecx, this
		call ResourceManager__prependFileLinkedListNode
	}
}
int ResourceManager::pushCurrentFileAndOffsetOntoStack() {
	__asm {
		mov ecx, this
		call ResourceManager__pushCurrentFileAndOffsetOntoStack
	}
}
void ResourceManager::readFromCurrentFile( void * buf, unsigned int  nbytes) {
	__asm {
		push nbytes
		push buf
		mov ecx, this
		call ResourceManager__readFromCurrentFile
	}
}
int ResourceManager::readInt() {
	__asm {
		mov ecx, this
		call ResourceManager__readInt
	}
}
void ResourceManager::readNexDOSFilename( void * buf) {
	__asm {
		push buf
		mov ecx, this
		call ResourceManager__readNexDOSFilename
	}
}
__int16 ResourceManager::readShort() {
	__asm {
		mov ecx, this
		call ResourceManager__readShort
	}
}
void ResourceManager::reduceReferenceCountToResource( AbstractResource * res) {
	__asm {
		push res
		mov ecx, this
		call ResourceManager__reduceReferenceCountToResource
	}
}
void ResourceManager::removeFileFromList( AbstractResource * fil) {
	__asm {
		push fil
		mov ecx, this
		call ResourceManager__removeFileFromList
	}
}
void SoundManager::initializeRedbook() {
	__asm {
		mov ecx, this
		call SoundManager__initializeRedbook
	}
}
