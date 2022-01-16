//---------------------------------------------------------------------------

#pragma hdrstop

#include "Functions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

float calculatePdv(float pdv, float sumWitouthPdv){
	return sumWitouthPdv * (pdv / 100);
}
