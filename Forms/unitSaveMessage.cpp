//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "unitMain.h"
#include "unitSaveMessage.h"

#include "utils.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformSaveMessage *formSaveMessage;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformSaveMessage::TformSaveMessage(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TformSaveMessage::FormShow(TObject *Sender)
{
	labelFolder->Caption = formMain->getReceiptFileName();
	buttonOkay->Top = labelFolder->Top + labelFolder->Height + DEFAULT_MARGIN;
}

void __fastcall TformSaveMessage::buttonOkayClick(TObject *Sender)
{
	formSaveMessage->Close();
}
//******************************************************************************



