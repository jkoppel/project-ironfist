#include<Windows.h>
#include<io.h>
#include<fcntl.h>
#include<stdio.h>
#include<stddef.h>

#define ELEMENTS_IN(x) (sizeof(x)/sizeof((x)[0]))

#define MAX_ITEM_LEN 20

#pragma pack(push,1)
struct SMonFrameInfo
{
	char firstByteIgnored;
	__int16 offsetForBlind[2];
	char startMoveAnimInfoIgnored[16];
	char subStartMoveAnimInfoIgnored[16];
	char mainMoveAnimInfoIgnored[16];
	char subEndMoveAnimInfoIgnored[16];
	char endMoveAnimInfoIgnored[16];
	char fullMoveAnimInfoIgnored[16];
	char moveAnimInfoIgnored[16];
	char numberOfFidgets;
	float fidgetProbabilities[5];
	int fidgetInfoIgnored[5];
	int maxFidgetDelay;
	int stepTime;
	int shootingTime;
	int flightSpeed;
	__int16 projectileStartOffset[3][2];
	char numMissileDirs;
	float projDirAngle[12];
	int stackNumDispXShift[2];
	char animationLengths[34];
	char animationFrameToImgIdx[34][16];
};
#pragma pack(pop)

struct FieldInfo {
	char* name;
	char type; //'d' or 'f'
	int size;
	int len;
	int off;
};

FieldInfo frmInfo[] = {
	{"first-byte", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, firstByteIgnored)},
	{"blind-offset", 'd', sizeof(__int16), 2, offsetof(SMonFrameInfo, offsetForBlind)},
	{"start-move-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, startMoveAnimInfoIgnored)},
	{"sub-start-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, subStartMoveAnimInfoIgnored)},
	{"move-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, mainMoveAnimInfoIgnored)},
	{"sub-end-move-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, subEndMoveAnimInfoIgnored)},
	{"end-move-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, endMoveAnimInfoIgnored)},
	{"full-move-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, fullMoveAnimInfoIgnored)},
	{"walk-anim-info", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, moveAnimInfoIgnored)},
	{"num-fidgets", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, numberOfFidgets)},
	{"fidget-probabilities", 'f', sizeof(float), 5, offsetof(SMonFrameInfo, fidgetProbabilities)},
	{"fidget-info", 'd', sizeof(int), 5, offsetof(SMonFrameInfo, fidgetInfoIgnored)},
	{"max-fidget-delay", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, maxFidgetDelay)},
	{"step-time", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, stepTime)},
	{"shooting-time", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, shootingTime)},
	{"flight-speed", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, flightSpeed)},
	{"shoot-up-projectile-offset", 'd', sizeof(__int16), 2, offsetof(SMonFrameInfo, projectileStartOffset[0])},
	{"shoot-forward-projectile-offset", 'd', sizeof(__int16), 2, offsetof(SMonFrameInfo, projectileStartOffset[1])},
	{"shoot-down-projectile-offset", 'd', sizeof(__int16), 2, offsetof(SMonFrameInfo, projectileStartOffset[2])},
	{"num-missile-directions", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, numMissileDirs)},
	{"projectile-dir-angle", 'f', sizeof(float), 12, offsetof(SMonFrameInfo, projDirAngle)},
	{"stack-number-display-facing-right-xoff", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, stackNumDispXShift[0])},
	{"stack-number-display-facing-left-xoff", 'd', sizeof(int), 1, offsetof(SMonFrameInfo, stackNumDispXShift[1])},

	{"start-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[0])},
	{"sub-start-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[1])},
	{"main-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[2])},
	{"sub-end-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[3])},
	{"end-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[4])},
	{"full-move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[5])},
	{"move-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[6])},
	{"standing-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[7])},
	{"fidget-1-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[8])},
	{"fidget-2-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[9])},
	{"fidget-3-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[10])},
	{"fidget-4-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[11])},
	{"fidget-5-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[12])},
	{"dying-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[13])},
	{"wince-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[14])},
	{"wince-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[15])},
	{"melee-attack-up-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[16])},
	{"melee-attack-up-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[17])},
	{"melee-attack-up-2hex-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[18])},
	{"melee-attack-up-2hex-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[19])},
	{"melee-attack-forward-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[20])},
	{"melee-attack-forward-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[21])},
	{"melee-attack-forward-2hex-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[22])},
	{"melee-attack-forward-2hex-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[23])},
	{"melee-attack-down-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[24])},
	{"melee-attack-down-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[25])},
	{"melee-attack-down-2hex-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[26])},
	{"melee-attack-down-2hex-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[27])},
	{"ranged-attack-up-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[28])},
	{"ranged-attack-up-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[29])},
	{"ranged-attack-forward-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[30])},
	{"ranged-attack-forward-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[31])},
	{"ranged-attack-down-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[32])},
	{"ranged-attack-down-return-animation-length", 'd', sizeof(char), 1, offsetof(SMonFrameInfo, animationLengths[33])},

	{"start-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[0])},
	{"sub-start-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[1])},
	{"main-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[2])},
	{"sub-end-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[3])},
	{"end-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[4])},
	{"full-move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[5])},
	{"move-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[6])},
	{"standing-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[7])},
	{"fidget-1-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[8])},
	{"fidget-2-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[9])},
	{"fidget-3-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[10])},
	{"fidget-4-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[11])},
	{"fidget-5-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[12])},
	{"dying-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[13])},
	{"wince-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[14])},
	{"wince-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[15])},
	{"melee-attack-up-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[16])},
	{"melee-attack-up-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[17])},
	{"melee-attack-up-2hex-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[18])},
	{"melee-attack-up-2hex-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[19])},
	{"melee-attack-forward-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[20])},
	{"melee-attack-forward-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[21])},
	{"melee-attack-forward-2hex-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[22])},
	{"melee-attack-forward-2hex-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[23])},
	{"melee-attack-down-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[24])},
	{"melee-attack-down-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[25])},
	{"melee-attack-down-2hex-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[26])},
	{"melee-attack-down-2hex-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[27])},
	{"ranged-attack-up-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[28])},
	{"ranged-attack-up-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[29])},
	{"ranged-attack-forward-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[30])},
	{"ranged-attack-forward-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[31])},
	{"ranged-attack-down-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[32])},
	{"ranged-attack-down-return-animation", 'd', sizeof(char), 16, offsetof(SMonFrameInfo, animationFrameToImgIdx[33])},
};

int make_ini(SMonFrameInfo* frm, char* filnam) {
	for(int i = 0; i < ELEMENTS_IN(frmInfo); i++) {
		FieldInfo* fieldInfo = &frmInfo[i];

		char *sep = "";
		char* buf = (char*)calloc(1+fieldInfo->len*(MAX_ITEM_LEN+1), sizeof(char));
		for(int j = 0; j < fieldInfo->len; j++) {
			strcat(buf, sep);
			sep = ",";

			char ibuf[MAX_ITEM_LEN];
			ibuf[0] = '\0';

			void* v = (char*)frm+fieldInfo->off+j*fieldInfo->size;
			switch(fieldInfo->type) {
			case 'd':
				{
					switch(fieldInfo->size) {
					case sizeof(char):
						{
							char c = *(char*)v;
							sprintf(ibuf, "%d", (int)c);
							strcat(buf, ibuf);
							break;
						}	
					case sizeof(__int16):
						{
							__int16 c = *(__int16*)v;
							sprintf(ibuf, "%d", (int)c);
							strcat(buf, ibuf);
							break;
						}
					case sizeof(int):
						{
							int c = *(int*)v;
							sprintf(ibuf, "%d", c);
							strcat(buf, ibuf);
							break;
						}
					default:
						MessageBox(NULL, "Invalid field info size", NULL, MB_OK|MB_ICONERROR);
						return 1;
					}
				}
				break;
			case 'f':
				{
					if(fieldInfo->size == sizeof(float)) {
						float f = *(float*)v;
						sprintf(ibuf, "%f", f);
						strcat(buf, ibuf);
					} else {
						MessageBox(NULL, "Invalid field info size", NULL, MB_OK|MB_ICONERROR);
						return 1;
					}
				}
				break;
			default:
				MessageBox(NULL, "Invalid field info type", NULL, MB_OK|MB_ICONERROR);
				return 1;
			}
		}
		WritePrivateProfileString("FRM", fieldInfo->name, buf, filnam);
		free(buf);
	}

	return 0;
}

int read_ini(SMonFrameInfo *frm, char* filnam) {
	for(int i = 0; i < ELEMENTS_IN(frmInfo); i++) {
		FieldInfo* fieldInfo = &frmInfo[i];
		int buflen = 1+fieldInfo->len*(MAX_ITEM_LEN+1);
		char* buf = (char*)calloc(buflen, sizeof(char));
		GetPrivateProfileString("FRM", fieldInfo->name, "0", buf, buflen, filnam);

		char* tok = strtok(buf, ",");
		for(int j = 0; j < fieldInfo->len && tok!=NULL; j++, tok=strtok(NULL,",")) {
			void* v = (char*)frm+fieldInfo->off+j*fieldInfo->size;
			switch(fieldInfo->type) {
			case 'd':
				{
					int n;
					sscanf(tok, "%d", &n);
					switch(fieldInfo->size) {
					case sizeof(char):
						*(char*)v = (char)n;
						break;
					case sizeof(__int16):
						*(__int16*)v = (__int16)n;
						break;
					case sizeof(int):
						*(int*)v = (int)n;
						break;
					default:
						MessageBox(NULL, "Invalid field info size", NULL, MB_OK|MB_ICONERROR);
						return 1;
					}
				}
				break;
			case 'f':
				{
					float f;
					sscanf(tok, "%f", &f); 
					if(fieldInfo->size == sizeof(float)) {
						*(float*)v = f;
					} else {
						MessageBox(NULL, "Invalid field info size", NULL, MB_OK|MB_ICONERROR);
						return 1;
					}
				}
				break;
			default:
				MessageBox(NULL, "Invalid field info type", NULL, MB_OK|MB_ICONERROR);
				return 1;
			}
		}
	}
	return 0;
}

//#define UNPACK

#ifdef UNPACK

char* usageInfo =
	"Converts HoMM II FRM.BIN (monster frame info) files into human-readable .ini files.\n"
	"\n"
	"Usage: Create a desktop shortcut and drag the desired FRM.BIN file onto the shortcut.";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if(__argc <= 1) {
		MessageBox(NULL, usageInfo, "H2FRMUnpack", MB_OK);
		return 0;
	}

	int fd = _open(__argv[1], _O_BINARY);

	SMonFrameInfo frm;
	_read(fd, &frm, sizeof(SMonFrameInfo));
	_close(fd);

	char* iniFilnam = (char*)calloc(1+strlen(".ini")+strlen(__argv[1]), sizeof(char));
	strcat(iniFilnam, __argv[1]);
	strcat(iniFilnam, ".ini");

	if(make_ini(&frm, iniFilnam) == 0)
		MessageBox(NULL, "Operation succeeded", "Info", MB_OK);
	else
		MessageBox(NULL, "Operation failed", "Info", MB_OK);

	free(iniFilnam);


	return 0;
}

#else

char* usageInfo =
	"Converts human-readable .ini files into  HoMM II FRM.BIN (monster frame info) files.\n"
	"\n"
	"Usage: Create a desktop shortcut and drag the desired .ini file onto the shortcut.";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if(__argc <= 1) {
		MessageBox(NULL, usageInfo, "H2FRMPack", MB_OK);
		return 0;
	}

	SMonFrameInfo* frm = (SMonFrameInfo*)calloc(1, sizeof(SMonFrameInfo));
	if(read_ini(frm, __argv[1]) != 0) {
		MessageBox(NULL, "Failed to read .ini file", NULL, MB_OK|MB_ICONERROR);
		return 0;
	}

	char* ini = strstr(__argv[1], ".ini");

	if(ini == NULL) {
		MessageBox(NULL, "Input file does not have \".ini\" extension.", "Info", MB_OK);
		return 0;
	}

	ini[0] = '\0';

	//int fd = _open(__argv[1], _O_BINARY|_O_CREAT|_O_WRONLY|_O_TRUNC);

	FILE *fout = fopen(__argv[1], "wb");

	if(fwrite(frm, sizeof(SMonFrameInfo), 1, fout))
		MessageBox(NULL, "Operation succeeded", "Info", MB_OK);
	else
		MessageBox(NULL, "Operation failed", NULL, MB_OK|MB_ICONERROR);

	fclose(fout);

	free(frm);

	return 0;
}

#endif