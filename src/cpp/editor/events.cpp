#include <windows.h>
#include <string>

#include "base.h"

#include "adventure/map.h"
#include "combat/creatures.h"

#include "artifacts.h"
#include "editor.h"
#include "events.h"
#include "hero_edit.h"
#include "../../rc/editor/resource.h"
#include "town/buildings.h"
#include "town/town.h"

namespace {
  bool shouldFillInArtifacts = true;
}

extern void* hwndApp;
extern TownExtra gEditTownExtra;

extern long __stdcall AppWndProc_orig(void*, unsigned int, unsigned int, long);

void AddFlag(HWND hwnd, int id, int elt, int flag) {
	HWND control = GetDlgItem(hwnd, id);
	SetWindowLongPtr(control, elt, GetWindowLongPtr(control, elt) | flag);

}

int monLabels[] = { IDC_MON1
				  , IDC_MON2
				  , IDC_MON3
				  , IDC_MON4
				  , IDC_MON5
                  };

int monTypeFields[] = { IDC_MON1_TYPE
					  , IDC_MON2_TYPE
					  , IDC_MON3_TYPE
					  , IDC_MON4_TYPE
					  , IDC_MON5_TYPE
                      };

int monQtyFields[] = { IDC_MON1_QTY
					 , IDC_MON2_QTY
					 , IDC_MON3_QTY
					 , IDC_MON4_QTY
					 , IDC_MON5_QTY
					 };

int buildingIdToIdx[32];

static const std::wstring GetWC(const char *c) {
	const size_t cSize = strlen(c) + 1;
	std::wstring wc(cSize, L'#');
	size_t result = 0;
	mbstowcs_s(&result, &wc[0], cSize, c, cSize);

	return wc;
}

void InitBuildingMap() {
  for(int i = 0; i < ELEMENTS_IN(buildingIdToIdx); i++) {
	  buildingIdToIdx[i] = -1;
  }

  buildingIdToIdx[BUILDING_THIEVES_GUILD] = IDC_THIEVES_GUILD;
  buildingIdToIdx[BUILDING_TAVERN] = IDC_TAVERN;
  buildingIdToIdx[BUILDING_DOCK] = IDC_SHIPYARD;
  buildingIdToIdx[BUILDING_WELL] = IDC_WELL;
  buildingIdToIdx[BUILDING_STATUE] = IDC_STATUE;
  buildingIdToIdx[BUILDING_LEFT_TURRET] = IDC_LEFT_TURRET;
  buildingIdToIdx[BUILDING_RIGHT_TURRET] = IDC_RIGHT_TURRET;
  buildingIdToIdx[BUILDING_MARKET] = IDC_MARKETPLACE;
  buildingIdToIdx[BUILDING_SPECIAL_GROWTH] = IDC_SPECIAL_GROWTH_BUILDING;
  buildingIdToIdx[BUILDING_MOAT] = IDC_MOAT;
  buildingIdToIdx[BUILDING_SPECIAL] = IDC_SPECIAL_BUILDING;
  buildingIdToIdx[BUILDING_DWELLING_1] = IDC_DWELLING1;
  buildingIdToIdx[BUILDING_DWELLING_2] = IDC_DWELLING2;
  buildingIdToIdx[BUILDING_DWELLING_3] = IDC_DWELLING3;
  buildingIdToIdx[BUILDING_DWELLING_4] = IDC_DWELLING4;
  buildingIdToIdx[BUILDING_DWELLING_5] = IDC_DWELLING5;
  buildingIdToIdx[BUILDING_DWELLING_6] = IDC_DWELLING6;
  buildingIdToIdx[BUILDING_UPGRADE_1] = IDC_UPGRADE1;
  buildingIdToIdx[BUILDING_UPGRADE_2] = IDC_UPGRADE2;
  buildingIdToIdx[BUILDING_UPGRADE_3] = IDC_UPGRADE3;
  buildingIdToIdx[BUILDING_UPGRADE_4] = IDC_UPGRADE4;
  buildingIdToIdx[BUILDING_UPGRADE_5] = IDC_UPGRADE5;
}

void FillInTownEdit(HWND hwnd, TownExtra* twnExtra) {
	if(twnExtra->customGarrison) {
		SendDlgItemMessage(hwnd, IDC_TROOP_CUSTOM, BM_SETCHECK, BST_CHECKED, 0); 
	} else {
		SendDlgItemMessage(hwnd, IDC_TROOP_STANDARD, BM_SETCHECK, BST_CHECKED, 0);	
	}

	int msg = twnExtra->customGarrison ? SW_SHOW : SW_HIDE;
	
	ShowWindow(GetDlgItem(hwnd, IDC_MON_TYPE_LABEL), msg);
	ShowWindow(GetDlgItem(hwnd, IDC_MON_QTY_LABEL), msg);
	for(int i = 0; i < ELEMENTS_IN(monLabels); i++)
		ShowWindow(GetDlgItem(hwnd, monLabels[i]), msg);
	for(int i = 0; i < ELEMENTS_IN(monTypeFields); i++)
		ShowWindow(GetDlgItem(hwnd, monTypeFields[i]), msg);
	for(int i = 0; i < ELEMENTS_IN(monQtyFields); i++)
		ShowWindow(GetDlgItem(hwnd, monQtyFields[i]), msg);

	for(int i = 0; i < ELEMENTS_IN(monQtyFields); i++) {
		AddFlag(hwnd, monQtyFields[i], GWL_STYLE, ES_NUMBER);
	}

	armyGroup* army = &twnExtra->garrison;

	for(int i = 0; i < ELEMENTS_IN(army->creatureTypes); i++) {
		int idx = SendDlgItemMessage(hwnd, monTypeFields[i], CB_FINDSTRING, -1, (LPARAM)GetWC(GetCreatureName(army->creatureTypes[i])).c_str());
		if(idx == CB_ERR) {
			SendDlgItemMessage(hwnd, monTypeFields[i], CB_SETCURSEL, 0, 0);
		} else {
			SendDlgItemMessage(hwnd, monTypeFields[i], CB_SETCURSEL, idx, 0);
		}
	}

	for(int i = 0; i < ELEMENTS_IN(army->quantities); i++) {
		SetDlgItemInt(hwnd, monQtyFields[i], army->quantities[i], FALSE);
	}

	SendDlgItemMessage(hwnd, IDC_CAPTAIN, BM_SETCHECK, twnExtra->hasCaptain ? BST_CHECKED : BST_UNCHECKED, 0);

	if(twnExtra->customName) {
		SendDlgItemMessage(hwnd, IDC_NAME_CUSTOM, BM_SETCHECK, BST_CHECKED, 0);
		SendDlgItemMessage(hwnd, IDC_NAME, WM_SETTEXT, 0, (LPARAM)GetWC(twnExtra->name).c_str());
		ShowWindow(GetDlgItem(hwnd, IDC_NAME), SW_SHOW);
	} else {
		SendDlgItemMessage(hwnd, IDC_NAME_STANDARD, BM_SETCHECK, BST_CHECKED, 0);
		ShowWindow(GetDlgItem(hwnd, IDC_NAME), SW_HIDE);
	}

	if(twnExtra->isCastle) {
		ShowWindow(GetDlgItem(hwnd, IDC_ALLOW_CASTLE), SW_HIDE);
	} else {
		SendDlgItemMessage(hwnd, IDC_ALLOW_CASTLE, BM_SETCHECK, twnExtra->disallowCastle ? BST_UNCHECKED : BST_CHECKED, 0);
	}

	if(twnExtra->customBuildings) {
		SendDlgItemMessage(hwnd, IDC_BUILDING_CUSTOM, BM_SETCHECK, BST_CHECKED, 0);
	} else {
		SendDlgItemMessage(hwnd, IDC_BUILDING_STANDARD, BM_SETCHECK, BST_CHECKED, 0);
	}

	InitBuildingMap();

	msg = twnExtra->customBuildings ? SW_SHOW : SW_HIDE;

	for(int i = 0; i < ELEMENTS_IN(buildingIdToIdx); i++) {
		int idx = buildingIdToIdx[i];
		if(idx != -1) {
			ShowWindow(GetDlgItem(hwnd, idx), msg);
		}
	}

	ShowWindow(GetDlgItem(hwnd, IDC_MAGE_GUILD), msg);
	ShowWindow(GetDlgItem(hwnd, IDC_MAGE_GUILD_LABEL), msg);


	for(int i = 0; i < ELEMENTS_IN(buildingIdToIdx); i++) {
		int idx = buildingIdToIdx[i];
		if(idx != -1) {
			SendDlgItemMessage(hwnd, idx, BM_SETCHECK, (twnExtra->buildingsBuilt & (1<<i)) ? BST_CHECKED : BST_UNCHECKED, 0);
		}
	}

	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_SETCURSEL, twnExtra->mageGuildLevel, 0);
	
	int faction = gEditTownExtra.faction;
	if(faction != FACTION_RANDOM && faction != FACTION_MULTIPLE) {
	  int mask = gTownEligibleBuildMask[faction];
	  for(int i = 0; i < ELEMENTS_IN(buildingIdToIdx); i++) {
		  int idx = buildingIdToIdx[i];
		  if(idx != -1) {
			  if(!(mask & (1<<i)) && !(faction == FACTION_NECROMANCER && i == BUILDING_TAVERN)) {
				  ShowWindow(GetDlgItem(hwnd, idx), SW_HIDE);
			  }
		  }
	  }
	}
}

void InitializeTownEdit(HWND hwnd) {
	EnableWindow(hwnd, TRUE);

	for(int i = 0; i < ELEMENTS_IN(monTypeFields); i++) {
		SendDlgItemMessage(hwnd, monTypeFields[i], CB_ADDSTRING, 0, (LPARAM)L"-empty-");
		for(int j = 0; j < GetNumCreatures(); j++) {
			snprintf(gText, gTextSize, "%s", GetCreatureName(j));
			if(strlen(gText) == 0) {
                SendDlgItemMessage(hwnd, monTypeFields[i], CB_ADDSTRING, 0, (LPARAM)L"###UNKNOWN CREATURE###");
				continue; //ghetto way of checking for if creature is real (not random)
			}

			gText[0] -= 32; // This is seriously "the C++ way" to capitalize...

			int idx = SendDlgItemMessage(hwnd, monTypeFields[i], CB_ADDSTRING, 0, (LPARAM)GetWC(gText).c_str());
			SendDlgItemMessage(hwnd, monTypeFields[i], CB_SETITEMDATA, idx, j);
		}
	}

	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"-None-");
	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"Level 1");
	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"Level 2");
	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"Level 3");
	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"Level 4");
	SendDlgItemMessage(hwnd, IDC_MAGE_GUILD, CB_ADDSTRING, 0, (LPARAM)L"Level 5");

	int faction = gEditTownExtra.faction;
	SendDlgItemMessage(hwnd, IDC_SPECIAL_GROWTH_BUILDING, WM_SETTEXT, 0, (LPARAM)GetWC(GetFirstLevelGrowerName(faction)).c_str());
	SendDlgItemMessage(hwnd, IDC_SPECIAL_BUILDING, WM_SETTEXT, 0, (LPARAM)GetWC(GetSpecialBuildingName(faction)).c_str());

	if(faction == FACTION_NECROMANCER) {
		SendDlgItemMessage(hwnd, IDC_TAVERN, WM_SETTEXT, 0, (LPARAM)L"Shrine");
	}
}

BOOL CALLBACK EditTownProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	int update = 0;
	int extraIdx = gpExaminedCell->extraInfo;

	int monIdx = 0;
	int isCustom = 0;
	int buildingIdx = 0;
	int checkState = 0;

	switch(Message)
    {
        case WM_INITDIALOG:
			InitializeTownEdit(hwnd);
			update = 1;
		break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
					memcpy(gpEditManager->mapExtra[extraIdx], &gEditTownExtra, sizeof(TownExtra));
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;

				case IDC_TROOP_STANDARD: isCustom = 0; goto HANDLE_CUSTOM_GARRISON;
				case IDC_TROOP_CUSTOM:   isCustom = 1; goto HANDLE_CUSTOM_GARRISON;
HANDLE_CUSTOM_GARRISON:
					switch(HIWORD(wParam)) {
						case BN_CLICKED:
							gEditTownExtra.customGarrison = isCustom;
							update = 1;
						break;
					}
				break;
				
				case IDC_BUILDING_STANDARD: isCustom = 0; goto HANDLE_CUSTOM_BUILDINGS;
				case IDC_BUILDING_CUSTOM:   isCustom = 1; goto HANDLE_CUSTOM_BUILDINGS;
HANDLE_CUSTOM_BUILDINGS:
					switch(HIWORD(wParam)) {
						case BN_CLICKED:
							gEditTownExtra.customBuildings = isCustom;
							update = 1;
						break;
					}
				break;
				
				case IDC_NAME_STANDARD: isCustom = 0; goto HANDLE_CUSTOM_NAME;
				case IDC_NAME_CUSTOM:   isCustom = 1; goto HANDLE_CUSTOM_NAME;
HANDLE_CUSTOM_NAME:
					switch(HIWORD(wParam)) {
						case BN_CLICKED:
							gEditTownExtra.customName = isCustom;
							update = 1;
						break;
					}
				break;

				case IDC_MON1_TYPE: monIdx = 0; goto HANDLE_MONSTER;
				case IDC_MON2_TYPE: monIdx = 1; goto HANDLE_MONSTER;
				case IDC_MON3_TYPE: monIdx = 2; goto HANDLE_MONSTER;
				case IDC_MON4_TYPE: monIdx = 3; goto HANDLE_MONSTER;
				case IDC_MON5_TYPE: monIdx = 4; goto HANDLE_MONSTER;
HANDLE_MONSTER:
					switch(HIWORD(wParam)) {
						case CBN_SELCHANGE:
							int sel = SendMessage(GetDlgItem(hwnd, LOWORD(wParam)), CB_GETCURSEL, 0, 0);
							int creature = SendDlgItemMessage(hwnd, LOWORD(wParam), CB_GETITEMDATA, sel, 0);
							gEditTownExtra.garrison.creatureTypes[monIdx] = creature;
							update = 1;
						break;
					}
				break;

				case IDC_MON1_QTY: monIdx = 0; goto HANDLE_MON_QTY;
				case IDC_MON2_QTY: monIdx = 1; goto HANDLE_MON_QTY;
				case IDC_MON3_QTY: monIdx = 2; goto HANDLE_MON_QTY;
				case IDC_MON4_QTY: monIdx = 3; goto HANDLE_MON_QTY;
				case IDC_MON5_QTY: monIdx = 4; goto HANDLE_MON_QTY;
HANDLE_MON_QTY:
					switch(HIWORD(wParam)) {
						case EN_CHANGE:
							int succ = FALSE;
							int qty = GetDlgItemInt(hwnd, LOWORD(wParam), &succ, FALSE);
							if(succ) {
								gEditTownExtra.garrison.quantities[monIdx] = qty;
							}
						break;
					}
				break;

				case IDC_NAME:
					switch(HIWORD(wParam)) {
						case EN_CHANGE:
							GetWindowTextA(GetDlgItem(hwnd, IDC_NAME), (LPSTR)&gEditTownExtra.name, ELEMENTS_IN(gEditTownExtra.name));
							break;
					}
				break;

				case IDC_CAPTAIN:
					switch(HIWORD(wParam)) {
						case BN_CLICKED:
							checkState = SendMessage(GetDlgItem(hwnd, IDC_CAPTAIN), BM_GETCHECK, 0, 0);
							gEditTownExtra.hasCaptain = checkState == BST_CHECKED ? 1 : 0;
						break;
					}
				break;

				case IDC_ALLOW_CASTLE:
					switch(HIWORD(wParam)) {
						case BN_CLICKED:
							checkState = SendMessage(GetDlgItem(hwnd, IDC_ALLOW_CASTLE), BM_GETCHECK, 0, 0);
							gEditTownExtra.disallowCastle = checkState == BST_CHECKED ? 0 : 1;
						break;
					}
				break;

				case IDC_THIEVES_GUILD:
				case IDC_TAVERN:
				case IDC_SHIPYARD:
				case IDC_WELL:
				case IDC_STATUE:
				case IDC_LEFT_TURRET:
				case IDC_RIGHT_TURRET:
				case IDC_MARKETPLACE:
				case IDC_SPECIAL_GROWTH_BUILDING:
				case IDC_MOAT:
				case IDC_SPECIAL_BUILDING:
				case IDC_DWELLING1:
				case IDC_DWELLING2:
				case IDC_DWELLING3:
				case IDC_DWELLING4:
				case IDC_DWELLING5:
				case IDC_DWELLING6:
				case IDC_UPGRADE1:
				case IDC_UPGRADE2:
				case IDC_UPGRADE3:
				case IDC_UPGRADE4:
				case IDC_UPGRADE5:

					for(int i = 0; i < ELEMENTS_IN(buildingIdToIdx); i++) {
						if(buildingIdToIdx[i] == LOWORD(wParam)) {
							buildingIdx = i;
							break;
						}
					}
					
					checkState = SendMessage(GetDlgItem(hwnd, LOWORD(wParam)), BM_GETCHECK, 0, 0);
					
					if(checkState == BST_CHECKED) {
						gEditTownExtra.buildingsBuilt |= 1 << buildingIdx;
					} else {
						gEditTownExtra.buildingsBuilt &= ~(1 << buildingIdx);
					}

				break;
				
				case IDC_MAGE_GUILD:
					switch(HIWORD(wParam)) {
						case CBN_SELCHANGE:
							int sel = SendMessage(GetDlgItem(hwnd, LOWORD(wParam)), CB_GETCURSEL, 0, 0);
							gEditTownExtra.mageGuildLevel = sel;
							
							if(sel > 0) {
								gEditTownExtra.buildingsBuilt |= 1 << BUILDING_MAGE_GUILD;
							} else {
								gEditTownExtra.buildingsBuilt &= ~(1 << BUILDING_MAGE_GUILD);
							}
						break;
					}
				break;
            }
        break;
        default:
            return FALSE;
    }
	if(update)
	  FillInTownEdit(hwnd, &gEditTownExtra);
    return TRUE;
}

extern void* hInstApp;

extern int __stdcall AppAbout(void *,unsigned int,unsigned int,long);

void eventsManager::EditTown(int x, int y) {
	gpExaminedCell = &gpMap.tiles[y*gpMap.width + x];
	int extraIdx = gpExaminedCell->extraInfo;
	memcpy(&gEditTownExtra, gpEditManager->mapExtra[extraIdx], sizeof(TownExtra));
	DialogBoxParamA((HINSTANCE)hInstApp, "EDIT_TOWN",  (HWND)hwndApp, (DLGPROC)EditTownProc, 0);;
}

int eventsManager::EditHero(int x, int y, int isJailed) {
  EditHero_RequestUserDefinedElements();
  return EditHero_orig(x, y, isJailed);
}

int eventsManager::EditEvent(int mapExtraIdx) {
  EditEvent_RequestUserDefinedElements();
  return EditEvent_orig(mapExtraIdx);
}

void __stdcall FillInEventEdit(EventExtra *extra) {
  const int ARTIFACT_SLOT = 301;

  if (shouldFillInArtifacts) {
    for (int i = MAX_EXPANSION_ARTIFACT + 1; i < NUM_SUPPORTED_ARTIFACTS; ++i) {
      if (!IsArtifactValid(i)) {
        continue;
      }
      GUIDroplistAdd(gpCellEditDialog, ARTIFACT_SLOT, GetArtifactName(i));
    }

    shouldFillInArtifacts = false;
  }

  FillInEventEdit_orig(extra);
}

void EditEvent_RequestUserDefinedElements() {
  shouldFillInArtifacts = true;
}

extern long __fastcall AppCommand_orig(void *hMenu, unsigned int a1, unsigned int a2, long a3);

long __fastcall AppCommand(void *hMenu, unsigned int a1, unsigned int a2, long a3) {
  switch(a2) {
    case 40010: //MENUITEM "1280 x 960 (Native x2)"
      ResizeWindow(-1, -1, 1280, 960);
      return 0;
    case 40011: //MENUITEM "1920 x 1440 (Native x3)"
      ResizeWindow(-1, -1, 1920, 1440);
      return 0;
    default:
      return AppCommand_orig(hMenu, a1, a2, a3);
  }
}

extern void __fastcall UpdateDfltMenu_orig(void *hMenu);

extern void __fastcall UpdateDfltMenu(void *hMenu) {
  UpdateDfltMenu_orig(hMenu);
  EnableMenuItem((HMENU)hMenu, 40010, MF_ENABLED);
  EnableMenuItem((HMENU)hMenu, 40011, MF_ENABLED);
}

extern int __fastcall oldmain_orig();

int __fastcall oldmain() {
  // Disallow resizing game window using mouse
  SetWindowLong((HWND)hwndApp, GWL_STYLE, GetWindowLong((HWND)hwndApp, GWL_STYLE) &~ WS_SIZEBOX);
  return oldmain_orig();
}