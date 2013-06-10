#include "dialog.h"


void H2MessageBox(char* msg) {
	NormalDialog(msg, DIALOG_OKAY, -1,-1,-1,0,-1,0,-1,0);
}