//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "projectGlobals.h"

#include "unitShowMessageCustom.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformShowMessageCustom *formShowMessageCustom;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformShowMessageCustom::TformShowMessageCustom(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TformShowMessageCustom::buttonOkayClick(TObject *Sender)
{
	formShowMessageCustom->Close();
}

void __fastcall TformShowMessageCustom::FormShow(TObject *Sender)
{
	buttonOkay->Top = 3*DEFAULT_MARGIN/2 + labelCustomMessage->Height;
	Height = DEFAULT_MARGIN + buttonOkay->Top + buttonOkay->Height;
}
//******************************************************************************

